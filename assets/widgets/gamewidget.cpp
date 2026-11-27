#include "gamewidget.h"
#include "qevent.h"
#include "qlabel.h"
#include "ui_gamewidget.h"

GameWidget::GameWidget(QWidget *parent, shared_ptr<Environment> e, shared_ptr<Player> p)
    : QWidget(parent)
    , ui(new Ui::GameWidget)
{
    _env=e;

    _env->PlacePlayer(p);

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
        _command->setText("");
        ResetBoard();
    }
}

void GameWidget::ResetBoard()
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            _boardGrid->addWidget(new QLabel("help"),i,j,1,1,Qt::AlignLeft);
        }
    }
}

GameWidget::~GameWidget()
{
    delete ui;
    delete _boardGrid;
    delete _command;
}
