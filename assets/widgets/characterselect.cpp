#include "characterselect.h"
#include "qevent.h"
#include "ui_characterselect.h"

CharacterSelect::CharacterSelect(QWidget *parent,BoardSetup *b, shared_ptr<Player> p)
    : QWidget(parent)
    , ui(new Ui::CharacterSelect)
{
    _p=p;
    _b=b;

    _instruction=new QLabel(this);
    _instruction->setText("What is your name?");
    _instruction->move(10,60);

    _name=new QLineEdit(this);
    _name->move(10,60);

    _raceSelect=new QComboBox(this);
    _raceSelect->addItem(" Human");
    _raceSelect->addItem("Elf");
    _raceSelect->addItem("Dwarf");
    _raceSelect->addItem("Hobbit");
    _raceSelect->addItem("Orc");
    _raceSelect->move(10,100);

    _nextBttn=new QPushButton(this);
    connect(_nextBttn,&QPushButton::pressed,this,&CharacterSelect::Start);
    _nextBttn->move(10,120);

    this->setFixedSize(120,160);
    ui->setupUi(this);
}

void CharacterSelect::Start()
{
    _p->SetDetails(static_cast<Race>(_raceSelect->currentIndex()),_name->text().toStdString());
    _b->show();
    this->close();
}

void CharacterSelect::closeEvent(QCloseEvent *event)
{ event->accept(); }

CharacterSelect::~CharacterSelect()
{
    delete ui;
    delete _b;
    delete _raceSelect;
    delete _name;
    delete _nextBttn;
    delete _instruction;
}
