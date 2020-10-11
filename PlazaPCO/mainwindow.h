#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDesktopServices>
#include <QMainWindow>
#include <QDateTime>
#include <QProcess>
#include <QtDebug>
#include <QTimer>
#include <QTime>
#include <QFile>
#include <QUrl>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void timeFunc();

    void Converting();

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

     QTime timeElapsed;

     QTime photosTime;

};

#endif // MAINWINDOW_H
