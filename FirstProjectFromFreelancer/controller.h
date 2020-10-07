#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDesktopWidget>
#include <QAudioRecorder>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void Recording();

    void Converting();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    bool recording = false;
    QAudioRecorder *audioRecorder;

};
#endif // MAINWINDOW_H
