#include "gamewidget.h"
#include "qevent.h"
#include "ui_gamewidget.h"

GameWidget::GameWidget(QWidget *parent,Environment *e)
    : QWidget(parent)
    , ui(new Ui::GameWidget)
{
    _env=e;

    _boardGrid=new QGridLayout(this);
    ResetBoard();

    _command=new QLineEdit(this);
    _command->move(10,90);

    ui->setupUi(this);
}



void GameWidget::keyPressEvent(QKeyEvent *event)
{
    if( event->text()=='\r')
    {
        _env->ReceiveCommand(_command->text().at(0).toLatin1());
         qDebug()<<"Clicking works"<<_command->text().at(0);

        _command->setText("");


        //refresh menu or sth here


    }
}

void GameWidget::ResetBoard()
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            _boardGrid->addWidget(new QFrame(),i,j,1,1,Qt::AlignJustify);
        }
    }
}

GameWidget::~GameWidget()
{
    delete ui;
}
