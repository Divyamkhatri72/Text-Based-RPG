#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream> // TO REMOVE LATER

using namespace std;//SAME HERE

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == lineEdit && event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);

        if(keyEvent->text()=="Return")
        {
            std::cout<<"IT detects it"<<std::endl;
            lineEdit->text()="IT detects it";
        }


        qDebug() << "A key was pressed in the line edit: " << keyEvent->text();
        // Return true to stop propagation, false to continue it
        return false;
    }

    // Pass the event on to the base class
    return QMainWindow::eventFilter(obj, event);
}

MainWindow::~MainWindow()
{
    delete ui;
}
