#include "gamewidget.h"
#include "assets/environment/environment.h"
#include "qevent.h"
#include "ui_gamewidget.h"

GameWidget::GameWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameWidget)
{
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
