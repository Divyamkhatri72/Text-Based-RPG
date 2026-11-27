#include "boardsetup.h"
#include "gamewidget.h"
#include "ui_boardsetup.h"
#include <QIntValidator>
#include <QDebug>

BoardSetup::BoardSetup(QWidget *parent, GameWidget *g)
    : QWidget(parent)
    , ui(new Ui::BoardSetup)
{
    game=g;

    xInput = new QLineEdit(this);
    xInput->move(10,90);
    xInput->setValidator(new QIntValidator(0,1000,this));


    yInput = new QLineEdit(this);
    yInput->setValidator(new QIntValidator(0,1000,this));
    yInput->move(10,120);

    startButton=new QPushButton(this);
    connect(startButton,&QPushButton::pressed,this,&BoardSetup::StartGame);
    startButton->move(10,160);
    startButton->setText("Generate Board");

    ui->setupUi(this);
}

void BoardSetup::StartGame(){
    qDebug()<<"Clicking works";

    game->show();
}

BoardSetup::~BoardSetup()
{
    delete ui;
}
