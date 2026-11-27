#include "boardsetup.h"
#include "qevent.h"
#include "ui_boardsetup.h"
#include <QIntValidator>
#include <QDebug>

BoardSetup::BoardSetup(QWidget *parent, GameWidget *g, shared_ptr<Environment> e)
    : QWidget(parent)
    , ui(new Ui::BoardSetup)
{
    _env=e;
    _g=g;

    _xInput = new QLineEdit(this);
    _xInput->move(10,90);
    _xInput->setValidator(new QIntValidator(0,1000,this));


    _yInput = new QLineEdit(this);
    _yInput->setValidator(new QIntValidator(0,1000,this));
    _yInput->move(10,120);

    _nextBttn=new QPushButton(this);
    connect(_nextBttn,&QPushButton::pressed,this,&BoardSetup::Next);
    _nextBttn->move(12,160);
    _nextBttn->setText("Next");

    ui->setupUi(this);
}

void BoardSetup::Next(){

    int x=_xInput->text().toInt();
    int y=_yInput->text().toInt();
    if(_xInput->text().toInt()>0 && _yInput->text().toInt()>0)
    {
        _env->setGridSize(x,y);
        _g->show();
        this->close();
   }
}

void BoardSetup::closeEvent(QCloseEvent *event)
{
    event->accept();
}

BoardSetup::~BoardSetup()
{
    delete ui;
    delete _xInput;
    delete _yInput;
    delete _nextBttn;
}
