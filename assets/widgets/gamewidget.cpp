#include "gamewidget.h"
#include "qevent.h"
#include "ui_gamewidget.h"

GameWidget::GameWidget(QWidget *parent,Environment *e)
    : QWidget(parent)
    , ui(new Ui::GameWidget)
{
    _env=e;
    ui->setupUi(this);
}



void GameWidget::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "A key was pressed in the line edit: " << event->text();
}

GameWidget::~GameWidget()
{
    delete ui;
}
