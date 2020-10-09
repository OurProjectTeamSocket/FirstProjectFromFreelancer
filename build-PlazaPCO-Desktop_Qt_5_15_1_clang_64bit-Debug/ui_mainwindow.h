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
    QPushButton *pushButton_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(300, 600);
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        masno = new QFrame(centralwidget);
        masno->setObjectName(QString::fromUtf8("masno"));
        masno->setGeometry(QRect(30, 70, 240, 150));
        masno->setStyleSheet(QString::fromUtf8("background: gray;"));
        masno->setFrameShape(QFrame::StyledPanel);
        masno->setFrameShadow(QFrame::Raised);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 30, 131, 16));
        label->setStyleSheet(QString::fromUtf8("font-size: 15px;\n"
"color : black;"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(90, 230, 111, 31));
        pushButton->setStyleSheet(QString::fromUtf8("font-size: 15px;"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(100, 550, 181, 61));
        label_2->setStyleSheet(QString::fromUtf8("color: red;\n"
"font-size: 12px;"));
        toolButton = new QToolButton(centralwidget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(220, 230, 71, 31));
        toolButton->setStyleSheet(QString::fromUtf8(""));
        frame = new QWidget(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 380, 261, 181));
        frame->setCursor(QCursor(Qt::ArrowCursor));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setEnabled(true);
        pushButton_2->setGeometry(QRect(90, 230, 111, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("font-size: 15px;"));
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
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Record", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
