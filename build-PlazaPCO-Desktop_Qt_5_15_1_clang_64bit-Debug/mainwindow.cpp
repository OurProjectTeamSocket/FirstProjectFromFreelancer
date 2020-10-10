#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    system(std::string("cd ~/Desktop/ && mkdir PlazaPCO").c_str());

    ui->TimeLabel->setVisible(false);
    ui->RecordingLabel->setVisible(false);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&MainWindow::timeFunc));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timeFunc() {
    timeElapsed = timeElapsed.addSecs(1);
    ui->TimeLabel->setText("Time: " + timeElapsed.toString("hh:mm:ss"));
    qDebug() << timeElapsed.toString("hh:mm:ss");
}

void MainWindow::Recording(){

    qDebug() << "Nagrywam!";

    Qrec.setProcessChannelMode(QProcess::MergedChannels);
    Qrec.setProgram( QString::fromStdString(Path) + "/Desktop/PlazaPCO/ffmpeg");
    Qrec.setArguments({"-loop", "1", "-i", "/Users/nintyswinty/Downloads/1280x720-rich-electric-blue-solid-color-background.jpg", "-f", "avfoundation", "-i", "1", "-f", "avfoundation", "-i", "0", "-filter_complex", "[1:v]scale=960:600[a]; \
                       [2:v]scale=240:150[b]; \
                       [0:v][a]overlay=32:88:shortest=1[c]; \
                       [c][b]overlay=main_w-overlay_w-10:(main_h/2)-(overlay_h/2)[video]" , "-map", "[video]", QString::fromStdString(Path) + "/Desktop/PlazaPCO/" + date + ".mkv"});
    Qrec.start();
    Qrec.waitForFinished();

    qDebug() << "Koniec: " << Qrec.readAllStandardOutput();

}

void MainWindow::Converting(){

    qDebug() << "Konwertuję!";

    Qcon.setProcessChannelMode(QProcess::MergedChannels);
    Qcon.setProgram( QString::fromStdString(Path) + "/Desktop/PlazaPCO/ffmpeg");
    Qcon.setArguments({"-loglevel", "panic", "-i", QString::fromStdString(Path) + "/Desktop/PlazaPCO/" + date + ".mkv", "-codec", "copy", QString::fromStdString(Path) + "/Desktop/PlazaPCO/" + date + ".mp4"});
    Qcon.start();
    Qcon.waitForFinished();

    qDebug() << "Koniec: " << Qcon.readAllStandardOutput();

}

void MainWindow::on_pushButton_clicked()
{
    if(!recording){

        QString DateString = QDate::currentDate().toString("MM-dd-yy");
        QString TimeString = QTime::currentTime().toString("hh:mm:ss");

        date = DateString + "-" + TimeString;

        qDebug() << date;

        Qcon.terminate();
        ui->pushButton->setStyleSheet("* { background-color: rgb(168, 11, 0) }");
        timer->start(1000);
        recording = true;
        ui->RecordingLabel->setVisible(true);
        ui->TimeLabel->setVisible(true);
        Recording();
    } else {
        timer->stop();
        Qrec.terminate();
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
;}
