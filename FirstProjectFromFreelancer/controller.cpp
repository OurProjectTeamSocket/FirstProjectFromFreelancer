#include "controller.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) // 60% Done
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDesktopWidget *widget = QApplication::desktop();

    for(int x = 0; x < widget->screenCount(); x++){
        ui->comboBoxScreen->addItem(QString::number(x));
    }

    QAudioRecorder *Recorder = new QAudioRecorder(this);

    /*for(int x = 0; x < Recorder->audioInputs(); x++){ // Dodawnie urządzień dźwiękowych do wyboru w kolejności
        ui->comboBoxScreen->addItem(QString(QAudioDeviceInfo::availableDevices(QAudio::AudioOutput)));
    }*/

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked() // 80% Done
{
    if(!recording){
        recording = true;
        ui->pushButton->setStyleSheet("* { background-color: rgb(168, 11, 0) }");
        // Trzeba dodać by nagrane filmy nosiły date jako tytuł - QAudioDeviceInfo::deviceName()
    } else {
        recording = false;
        ui->pushButton->setStyleSheet("* { background-color: rgb(75,75,75) }");
    }
}

void MainWindow::Recording(){ // Not Done

    std::string command = "ffmpeg \ \n -f v4l2 -framerate 25 -video_size 960x600 -i /dev/video0 \ \n -f x11grab -framerate 100 -video_size 240x150 -i :0.0 \ \n -filter_complex \ \n output";

    system(command.c_str()); // usunąłem [0:v]pad=iw:900:0:(oh-ih)/2[left];[left][1:v]hstack b∂zie trzeba dodać jako zmienną
}

void MainWindow::Converting(){ // Done

    std::string command = "ffmpeg -i out.mkv -codec copy out.mp4";

    system(command.c_str());
}
