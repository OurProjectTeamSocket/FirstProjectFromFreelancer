#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

void MainWindow::Recording(){

    std::string command = "ffmpeg -framerate 30 -f avfoundation -i '0:0' test.mkv";

    system(command.c_str());
}

void MainWindow::Convertiong(){

    std::string command = "ffmpeg -i test.mkv -codec copy test.mp4";

    system(command.c_str());
}
