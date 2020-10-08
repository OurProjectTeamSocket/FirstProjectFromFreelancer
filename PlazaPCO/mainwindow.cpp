#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    system(std::string("cd ~/Desktop/ && mkdir PlazaPCO").c_str());
    system(std::string("brew install ffmpeg").c_str());
    system(std::string("brew update ffmpeg").c_str());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Recording(){

    qDebug() << "Nagrywam!";

    rec.start("/Users/nintyswinty/Desktop/Dev/Qt/build-PlazaPCO-Desktop_Qt_5_15_1_clang_64bit-Debug/ffmpeg -framerate 30 -f avfoundation  -i '1' -f avfoundation -framerate 30  -i '0' -c:v libx264 -crf 0 -preset ultrafast -filter_complex 'overlay=main_w-overlay_w-10:main_h-overlay_h-10' ~/Desktop/PlazaPCO/" + date + ".mkv");

    qDebug() << "Koniec - nagrywam";

}

void MainWindow::Converting(){

    qDebug() << "Konwertuję!";

    std::string command = "ffmpeg -i ~/Desktop/PlazaPCO/"  + date + ".mkv -codec copy ~/Desktop/PlazaPCO/" + date + ".mp4";

    con.setProgram("/Users/nintyswinty/Desktop/Dev/Qt/build-PlazaPCO-Desktop_Qt_5_15_1_clang_64bit-Debug/ffmpeg");
    con.setArguments({command.c_str()});

    qDebug() << "Koniec - konvertuję";

}

void MainWindow::on_pushButton_clicked()
{
    std::string command = "killall ffmpeg";

    QString DateString = QDate::currentDate().toString("MM-dd-yy");
    QString TimeString = QTime::currentTime().toString("hh:mm:ss");

    date = DateString.toStdString() + "-" + TimeString.toStdString();

    if(!recording){
        ui->pushButton->setStyleSheet("* { background-color: rgb(168, 11, 0) }");
        recording = true;
        Recording();
    } else {
        ui->pushButton->setStyleSheet("* { background-color: rgb(75,75,75) }");
        recording = false;

        Converting();
    }
}
