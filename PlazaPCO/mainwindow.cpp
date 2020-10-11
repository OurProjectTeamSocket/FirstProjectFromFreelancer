#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    system(std::string("cd ~/Desktop/ && mkdir PlazaPCO").c_str());
    system(std::string("cd ~/Desktop/PlazaPCO && mkdir background ").c_str());

    ui->TimeLabel->setVisible(false);
    ui->RecordingLabel->setVisible(false);

    connect(timer, &QTimer::timeout, this, QOverload<>::of(&MainWindow::timeFunc));

    qCam.setProcessChannelMode(QProcess::MergedChannels);
    qCam.setProgram( QString::fromStdString(Path) + "/Desktop/PlazaPCO/ffmpeg");
    qCam.setArguments({"-f", "avfoundation", "-framerate", "1", "-pixel_format", "yuyv422", "-i", "0", QString::fromStdString(Path) + "/Desktop/PlazaPCO/cam.png"});
    qCam.start();
    qCam.waitForFinished();

    QFile lfile(QString::fromStdString(Path) + "/Desktop/ScreenRecorder/Logo/logo.txt");
    if (!lfile.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream lin(&lfile);
    while (!lin.atEnd()) {
        logo = lin.readLine();

    }

    QFile rfile(QString::fromStdString(Path) + "/Desktop/ScreenRecorder/Logo/logo.txt");
    if (!rfile.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream rin(&rfile);
    while (!rin.atEnd()) {
        redtext = rin.readLine();

    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timeFunc() {
    ui->pushButton->setStyleSheet("* { background-color: rgb(255,255,255) }");
}

void MainWindow::Recording(){

    qDebug() << "Nagrywam!";

    qRec.setProcessChannelMode(QProcess::MergedChannels);
    qRec.setProgram( QString::fromStdString(Path) + "/Desktop/PlazaPCO/ffmpeg");
    qRec.setArguments({"-loop", "1", "-i", QString::fromStdString(Path) + "/Desktop/PlazaPCO/background.jpg", "-framerate", "30", "-f", "avfoundation", "-i", "1", "-framerate", "30", "-f", "avfoundation", "-i", "0", "-filter_complex", "[1:v]scale=960:600[a]; \
                       [2:v]scale=240:150[b]; \
                       [0:v][a]overlay=32:60:shortest=1[c]; \
                       [c][b]overlay=main_w-overlay_w-10:(main_h/2)-75[video]", "-map", "[video]", QString::fromStdString(Path) + "/Desktop/PlazaPCO/" + date + ".mkv"});
    qRec.start();
    qRec.waitForFinished();

    qDebug() << "Koniec: " << qRec.readAllStandardOutput();

}

void MainWindow::Converting(){

    qDebug() << "Konwertuję!";

    qCon.setProcessChannelMode(QProcess::MergedChannels);
    qCon.setProgram( QString::fromStdString(Path) + "/Desktop/PlazaPCO/ffmpeg");
    qCon.setArguments({"-loglevel", "panic", "-i", QString::fromStdString(Path) + "/Desktop/PlazaPCO/" + date + ".mkv", "-codec", "copy", QString::fromStdString(Path) + "/Desktop/PlazaPCO/" + date + ".mp4"});
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
        recording = true;
        ui->RecordingLabel->setVisible(true);
        ui->TimeLabel->setVisible(true);
        Recording();
    } else {
        timer->stop();
        qRec.terminate();
        ui->pushButton->setStyleSheet("* { background-color: rgb(255,255,255) }");
        recording = false;
        ui->RecordingLabel->setVisible(false);
        ui->TimeLabel->setVisible(false);
        Converting();
        timeElapsed.restart();
    }

}

void MainWindow::on_toolButton_clicked()
{
    std::string x = "open " + Path + "/Desktop/PlazaPCO/";
    system(x.c_str());
}
