/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_2;
    QToolButton *toolButton;
    QLabel *TimeLabel;
    QLabel *LogoLabel;
    QLabel *CamLabel;
    QLabel *RecLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(370, 600);
        MainWindow->setMinimumSize(QSize(370, 600));
        MainWindow->setMaximumSize(QSize(370, 600));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8("font-family: Arial;\n"
"font-size: 10px !important; \n"
"background: rgb(255, 255, 255);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 351, 31));
        label->setStyleSheet(QString::fromUtf8("font-size: 16px;\n"
"color : black;"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 280, 111, 31));
        pushButton->setStyleSheet(QString::fromUtf8("font-size: 15px;"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 560, 371, 61));
        label_2->setStyleSheet(QString::fromUtf8("color: red;\n"
"font-size: 12px;\n"
"text-align: center;"));
        toolButton = new QToolButton(centralwidget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(250, 280, 111, 31));
        toolButton->setStyleSheet(QString::fromUtf8(""));
        TimeLabel = new QLabel(centralwidget);
        TimeLabel->setObjectName(QString::fromUtf8("TimeLabel"));
        TimeLabel->setGeometry(QRect(10, 280, 111, 21));
        TimeLabel->setStyleSheet(QString::fromUtf8("font-size: 14px;\n"
"color: rgb(142, 190, 223);"));
        LogoLabel = new QLabel(centralwidget);
        LogoLabel->setObjectName(QString::fromUtf8("LogoLabel"));
        LogoLabel->setGeometry(QRect(60, 400, 250, 170));
        CamLabel = new QLabel(centralwidget);
        CamLabel->setObjectName(QString::fromUtf8("CamLabel"));
        CamLabel->setGeometry(QRect(10, 70, 350, 200));
        CamLabel->setStyleSheet(QString::fromUtf8("background: white;\n"
"border: 1px solid black;"));
        RecLabel = new QLabel(centralwidget);
        RecLabel->setObjectName(QString::fromUtf8("RecLabel"));
        RecLabel->setGeometry(QRect(85, 330, 200, 50));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Plaza PCO Sunum Kayit", nullptr));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Camera Preview</p></body></html>", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Record", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Text Line 123</p></body></html>", nullptr));
        toolButton->setText(QApplication::translate("MainWindow", "Open Video\n"
" Folder", nullptr));
        TimeLabel->setText(QApplication::translate("MainWindow", "Time: ", nullptr));
        LogoLabel->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        CamLabel->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        RecLabel->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
