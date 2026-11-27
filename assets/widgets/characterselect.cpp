#include "characterselect.h"
#include "qevent.h"
#include "ui_characterselect.h"

CharacterSelect::CharacterSelect(QWidget *parent,GameWidget *g, Player *p)
    : QWidget(parent)
    , ui(new Ui::CharacterSelect)
{
    _p=p;
    _g=g;

    _raceSelect=new QComboBox(this);

    _raceSelect->addItem(" Human");
    _raceSelect->addItem("Elf");
    _raceSelect->addItem("Dwarf");
    _raceSelect->addItem("Hobbit");
    _raceSelect->addItem("Orc");

    _nextBttn=new QPushButton(this);
    connect(_nextBttn,&QPushButton::pressed,this,&CharacterSelect::Start);
    _nextBttn->move(10,160);

    _name=new QLineEdit(this);

    ui->setupUi(this);
}

void CharacterSelect::Start()
{
    qDebug()<<"Clicking works";



    _g->show();
    this->close();

}

void CharacterSelect::closeEvent(QCloseEvent *event)
{
event->accept();
}

CharacterSelect::~CharacterSelect()
{
    delete ui;
}
