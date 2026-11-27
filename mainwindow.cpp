#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    lineEdit = new QLineEdit(this);
    setCentralWidget(lineEdit);
    lineEdit->installEventFilter(this);
    ui->setupUi(this);
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == lineEdit && event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        qDebug() << "A key was pressed in the line edit: " << keyEvent->text();

        return false;
    }

    // Pass the event on to the base class
    return QMainWindow::eventFilter(obj, event);
}

MainWindow::~MainWindow()
{
    delete ui;
}
