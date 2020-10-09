#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    system(std::string("cd ~/Desktop/ && mkdir PlazaPCO").c_str());

    ui->pushButton_2->setVisible(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Recording(){

    qDebug() << "Nagrywam!";

    Qrec.setProcessChannelMode(QProcess::MergedChannels);
    Qrec.setProgram("/Users/nintyswinty/Desktop/Dev/Qt/build-PlazaPCO-Desktop_Qt_5_15_1_clang_64bit-Debug/ffmpeg");
    Qrec.setArguments({"-framerate", "30", "-loglevel", "panic", "-f", "avfoundation", "-i", "1", "-f", "avfoundation", "-framerate", "30", "-i", "0", "-c:v", "libx264", "-crf", "0", "-preset", "ultrafast", QString::fromStdString(Path) + "/Desktop/PlazaPCO/" + date + ".mkv"});
    Qrec.start();
    Qrec.waitForFinished();

    qDebug() << "Koniec: " << Qrec.readAllStandardOutput();

}

void MainWindow::Converting(){

    qDebug() << "Konwertuję!";

    Qcon.setProcessChannelMode(QProcess::MergedChannels);
    Qcon.setProgram("/Users/nintyswinty/Desktop/Dev/Qt/build-PlazaPCO-Desktop_Qt_5_15_1_clang_64bit-Debug/ffmpeg");
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
        recording = true;
        Recording();
    } else {
        Qrec.terminate();
        ui->pushButton->setStyleSheet("* { background-color: rgb(75,75,75) }");
        recording = false;
        Converting();
    }

}
