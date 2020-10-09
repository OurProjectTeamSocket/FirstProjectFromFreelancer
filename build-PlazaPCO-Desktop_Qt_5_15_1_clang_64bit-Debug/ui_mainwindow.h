/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
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
    QFrame *masno;
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_2;
    QToolButton *toolButton;
    QWidget *frame;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(371, 600);
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        MainWindow->setStyleSheet(QString::fromUtf8("font-family: Arial;\n"
"background: rgb(255, 255, 255);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        masno = new QFrame(centralwidget);
        masno->setObjectName(QString::fromUtf8("masno"));
        masno->setGeometry(QRect(10, 70, 351, 201));
        masno->setStyleSheet(QString::fromUtf8("background: white;\n"
"border: 1px solid black;"));
        masno->setFrameShape(QFrame::StyledPanel);
        masno->setFrameShadow(QFrame::Raised);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 30, 141, 31));
        label->setStyleSheet(QString::fromUtf8("font-size: 16px;\n"
"color : black;"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 280, 111, 31));
        pushButton->setStyleSheet(QString::fromUtf8("font-size: 15px;"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(140, 560, 181, 61));
        label_2->setStyleSheet(QString::fromUtf8("color: red;\n"
"font-size: 12px;"));
        toolButton = new QToolButton(centralwidget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(290, 280, 71, 31));
        toolButton->setStyleSheet(QString::fromUtf8(""));
        frame = new QWidget(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(40, 410, 261, 171));
        frame->setCursor(QCursor(Qt::ArrowCursor));
        frame->setStyleSheet(QString::fromUtf8("background-image: url(:/images/plaza_seffaf2.png);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 280, 61, 21));
        label_3->setStyleSheet(QString::fromUtf8("font-size: 14px;\n"
"color: rgb(142, 190, 223);"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(120, 320, 141, 51));
        label_4->setStyleSheet(QString::fromUtf8("font-size: 25px;\n"
"color: red;"));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Plaza PCO Sunum Kayit", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Camera Preview", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Record", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Text Line 123", nullptr));
        toolButton->setText(QCoreApplication::translate("MainWindow", "Open Video\n"
" Folder", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Time: ", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Recording..", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
