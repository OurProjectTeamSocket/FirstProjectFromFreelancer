#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <QDesktopServices>
#include <QMainWindow>
#include <QDateTime>
#include <QProcess>
#include <QtDebug>
#include <QTimer>
#include <QTime>
#include <QFile>
#include <QUrl>
#include <QLocale>
#include <QTextCodec>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void timeFunc();

    void Converting();

    void GetPicFormCam();

    void recAnim();

public slots:
    void Recording();

private slots:
    void on_pushButton_clicked();

    void on_toolButton_clicked();

private:
    Ui::MainWindow *ui;

    bool recording = false;

    QString date;

    QProcess qRec;
    QProcess qCon;
    QProcess qCam;

    int elapsed = 0;

    std::string Path = getenv("HOME");

     QTimer *timer = new QTimer(this);
     QTimer *camTimer = new QTimer(this);
     QTimer *recTimer = new QTimer(this);

     QTime timeElapsed;

     QTime photosTime;

     QString logo;

     QString redtext;

     QString Image = QString::fromStdString(Path) + "/Desktop/ScreenRecorder/Images/";

     cv::VideoCapture cap;

     cv::Mat frame;
     QImage qt_image;

     int state = 0;

     bool reading;

     QString word[16];

};

#endif // MAINWINDOW_H
