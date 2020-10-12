#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    system(std::string("cd ~/Desktop/ && mkdir PlazaPCO").c_str());
    system(std::string("cd ~/Desktop/PlazaPCO && mkdir background ").c_str());

    if(QLocale::Turkey){
        QFile lfile(QString::fromStdString(Path) + "/Desktop/ScreenRecorder/");
        if (!lfile.open(QIODevice::ReadOnly | QIODevice::Text)){
            qDebug() << "1";
            return;
        }
    } else {

    }

    ui->TimeLabel->setVisible(false);
    ui->RecLabel->setVisible(false);

    connect(timer, &QTimer::timeout, this, QOverload<>::of(&MainWindow::timeFunc));
    connect(camTimer, &QTimer::timeout, this, QOverload<>::of(&MainWindow::GetPicFormCam));
    connect(recTimer, &QTimer::timeout, this, QOverload<>::of(&MainWindow::recAnim));
    camTimer->start();

    QFile lfile(QString::fromStdString(Path) + "/Desktop/ScreenRecorder/Logo/logo.txt");
    if (!lfile.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "1";
        return;
    }

    QTextStream lin(&lfile);
    while (!lin.atEnd()) {
        logo = lin.readLine();
        qDebug() << logo;
    }

    QString url = QString::fromStdString(Path) + "/Desktop/ScreenRecorder/Logo/" + logo;
    qDebug() << url;
    QPixmap img(url);
    img.scaled(ui->LogoLabel->width(), ui->LogoLabel->height());
    ui->LogoLabel->setPixmap(img);
    ui->LogoLabel->setScaledContents(true);

    QFile rfile(QString::fromStdString(Path) + "/Desktop/ScreenRecorder/Line_Under_Logo/Line_Under_Logo.txt");
    if (!rfile.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "2";
        return;
    }


    QTextStream rin(&rfile);
    while (!rin.atEnd()) {
        redtext = rin.readLine();
        qDebug() << redtext;
    }

    ui->label_2->setText("<html><head/><body><p align='center'>" + redtext + "</p></body></html>");

    cap.open(0);

    if(cap.isOpened()){
        qDebug() << "Camera don't load";
    } else {
        qDebug() << "Camera loaded";
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timeFunc() {
    QString out = QString("%1:%2").arg( timeElapsed.elapsed() / 60000        , 2, 10, QChar('0'))
                                  .arg((timeElapsed.elapsed() % 60000) / 1000, 2, 10, QChar('0'));
    ui->TimeLabel->setText("Time: " + out);
}

void MainWindow::GetPicFormCam(){

    cap >> frame;

    if(!frame.empty()){
        cvtColor(frame, frame, cv::COLOR_BGR2RGB);

        qt_image = QImage((const unsigned char*) (frame.data), frame.cols, frame.rows, QImage::Format_RGB888);

        qt_image.scaled(ui->CamLabel->width(), ui->CamLabel->height());

        ui->CamLabel->setPixmap(QPixmap::fromImage(qt_image));
        ui->CamLabel->setScaledContents(true);
    }

}

void MainWindow::recAnim(){
    if(state == 0){
        QString url = QString::fromStdString(Path) + "/Desktop/ScreenRecorder/Images/recording1.png";
        qDebug() << url;
        QPixmap img(url);
        img.scaled(ui->LogoLabel->width(), ui->LogoLabel->height());
        ui->RecLabel->setPixmap(img);
        ui->RecLabel->setScaledContents(true);
        ++state;
    } else if(state == 1) {
        QString url = QString::fromStdString(Path) + "/Desktop/ScreenRecorder/Images/recording2.png";
        qDebug() << url;
        QPixmap img(url);
        img.scaled(ui->LogoLabel->width(), ui->LogoLabel->height());
        ui->RecLabel->setPixmap(img);
        ui->RecLabel->setScaledContents(true);
        ++state;
    } else {
        QString url = QString::fromStdString(Path) + "/Desktop/ScreenRecorder/Images/recording3.png";
        qDebug() << url;
        QPixmap img(url);
        img.scaled(ui->LogoLabel->width(), ui->LogoLabel->height());
        ui->RecLabel->setPixmap(img);
        ui->RecLabel->setScaledContents(true);
        state = 0;
    }

}


void MainWindow::Recording(){

    qDebug() << "Nagrywam!";

    qRec.setProcessChannelMode(QProcess::MergedChannels);
    qRec.setProgram( QString::fromStdString(Path) + "/Desktop/ScreenRecorder/ffmpeg");
    qRec.setArguments({"-loop", "1", "-i", QString::fromStdString(Path) + "/Desktop/ScreenRecorder/background/background.jpg", "-framerate", "30", "-f", "avfoundation", "-i", "1", "-framerate", "30", "-f", "avfoundation", "-i", "0", "-f", "avfoundation", "-i", ":0", "-filter_complex", "[1:v]scale=960:600[a]; \
                       [2:v]scale=240:150[b]; \
                       [0:v][a]overlay=32:60:shortest=1[c]; \
                       [c][b]overlay=main_w-overlay_w-10:(main_h/2)-75[video]", "-map", "[video]", QString::fromStdString(Path) + "/Desktop/ScreenRecorder/Output/" + date + ".mkv"});
    qRec.start();
    qRec.waitForFinished(1);

    qDebug() << "Koniec: " << qRec.readAllStandardOutput();

}

void MainWindow::Converting(){

    qDebug() << "Konwertuję!";

    qCon.setProcessChannelMode(QProcess::MergedChannels);
    qCon.setProgram( QString::fromStdString(Path) + "/Desktop/ScreenRecorder/ffmpeg");
    qCon.setArguments({"-loglevel", "panic", "-i", QString::fromStdString(Path) + "/Desktop/ScreenRecorder/Output/" + date + ".mkv", "-codec", "copy", QString::fromStdString(Path) + "/Desktop/ScreenRecorder/Output/" + date + ".mp4"});
    qCon.start();
    qCon.waitForFinished();

    qDebug() << "Koniec: " << qCon.readAllStandardOutput();

}

void MainWindow::on_pushButton_clicked()
{
    if(!recording){

        QString DateString = QDate::currentDate().toString("MM-dd-yy");
        QString TimeString = QTime::currentTime().toString("hh:mm:ss");

        date = DateString + "-" + TimeString;

        qDebug() << date;

        qCon.terminate();
        ui->pushButton->setStyleSheet("* { background-color: rgb(168, 11, 0) }");
        timer->start(1000);
        recTimer->start(500);
        recording = true;
        ui->RecLabel->setVisible(true);
        ui->TimeLabel->setVisible(true);
        timeElapsed.start();
        Recording();
    } else {
        timer->stop();
        recTimer->stop();
        qRec.terminate();
        ui->pushButton->setStyleSheet("* { background-color: rgb(255,255,255) }");
        recording = false;
        ui->RecLabel->setVisible(false);
        ui->TimeLabel->setVisible(false);
        Converting();
    }

}

void MainWindow::on_toolButton_clicked()
{
    std::string x = "open " + Path + "/Desktop/ScreenRecorder/Output/";
    system(x.c_str());
}
