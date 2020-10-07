#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->pushButton->setStyleSheet("* { }");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Recording(){

    std::string command = "ffmpeg -framerate 30 -f avfoundation -i '0:0' test.mkv";

    system(command.c_str());
}

void MainWindow::Convertiong(){

    std::string command = "ffmpeg -i test.mkv -codec copy test.mp4";

    system(command.c_str());
}

void MainWindow::on_pushButton_clicked()
{
    if(!recording){
        recording = true;
        Recording();
    } else {
        recording = false;
        
    }
}
