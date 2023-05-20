#test.pro
#-------------------------------------------------
#
# Project created by QtCreator 2023 - 03 - 25T08:41 : 20
#
#-------------------------------------------------

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4) : QT += widgets

TARGET = test181
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated(the exact warnings
    # depend on your compiler).Please consult the documentation of the
    # deprecated API in order to know how to port your code away from it.
    DEFINES += QT_DEPRECATED_WARNINGS

    # You can also make your code fail to compile if you use deprecated APIs.
    # In order to do so, uncomment the following line.
    # You can also select to disable deprecated APIs only up to a certain version of Qt.
    #DEFINES += QT_DISABLE_DEPRECATED_BEFORE = 0x060000    # disables all the APIs deprecated before Qt 6.0.0

    CONFIG += c++11

    SOURCES += \
    main.cpp \
    mainwindow.cpp

    HEADERS += \
    mainwindow.h

    FORMS += \
    mainwindow.ui

    # Default rules for deployment.
    qnx: target.path = / tmp / $${ TARGET } / bin
    else: unix:!android : target.path = / opt / $${ TARGET } / bin
    !isEmpty(target.path) : INSTALLS += target


    #mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

    namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow* ui;
    void mousePressEvent(QMouseEvent* event);
    void paintEvent(QPaintEvent* event);
    bool isMouseInRect(int x, int y, QRect rect);
    QLabel* xMouseLabel;
    QLabel* flagLabel;
    QRect redButtonRect;
    const int LeftRedButton = 100;
    const int TopRedButton = 150;
    const int WidthRedButton = 300;
    const int HeightRedButton = 150;
    bool flagRedButtonClick = false;
};

#endif // MAINWINDOW_H


#main.cpp
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}


#mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMouseEvent>
#include <QString>
#include <QPainter>

MainWindow::MainWindow(QWidget * parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << "Test QDebug.";
    QFont labelFont("Times", 14, QFont::Bold);

    setWindowTitle("Mouse v18.1");
    setFixedSize(900, 700);

    redButtonRect.setRect(LeftRedButton, TopRedButton, WidthRedButton, HeightRedButton);

    xMouseLabel = new QLabel("Mouse X: ", this);
    xMouseLabel->setGeometry(0, 0, 200, 50);
    xMouseLabel->setFont(labelFont);

    flagLabel = new QLabel("Flag: ", this);
    flagLabel->setGeometry(0, 100, 200, 50);
    flagLabel->setFont(labelFont);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent * event) {
    int xMouse = event->x();
    int yMouse = event->y();
    QString strXMouse;
    qDebug() << "Mouse X: " << event->x();
    qDebug() << "Mouse Y: " << event->y();
    xMouseLabel->setText("Mouse X: "
        + QString("%1").arg(xMouse, 3, 10, QChar('0'))
        + "\n"
        + "Mouse Y: "
        + QString("%1").arg(yMouse, 3, 10, QChar('0')));
    qDebug() << "" << isMouseInRect(xMouse, yMouse, redButtonRect);
    if (isMouseInRect(xMouse, yMouse, redButtonRect)) {
        flagRedButtonClick = true;
    }
    else {
        flagRedButtonClick = false;
    }
    flagLabel->setText("Flag: " + QString("%1").arg(flagRedButtonClick, 1, 10, QChar(' ')));
}


void MainWindow::paintEvent(QPaintEvent * event) {
    QPainter painter(this);
    QPen redPen4(Qt::red, 4, Qt::SolidLine);
    painter.setPen(redPen4);
    painter.drawRect(LeftRedButton, TopRedButton, WidthRedButton, HeightRedButton);
}

bool MainWindow::isMouseInRect(int x, int y, QRect rect) {
    return x > rect.x()
        and y > rect.y()
        and x < (rect.x() + rect.width())
        and y < (rect.y() + rect.height());
}

#mainwindow.ui
< ? xml version = "1.0" encoding = "UTF-8" ? >
<ui version = "4.0">
<class>MainWindow< / class>
<widget class = "QMainWindow" name = "MainWindow">
<property name = "geometry">
<rect>
< x>0 < / x >
< y>0 < / y >
< width>400 < / width >
< height>300 < / height >
< / rect>
< / property>
<property name = "windowTitle">
<string>MainWindow< / string>
< / property>
<widget class = "QWidget" name = "centralWidget" / >
< / widget>
<layoutdefault spacing = "6" margin = "11" / >
<resources / >
<connections / >
< / ui>
