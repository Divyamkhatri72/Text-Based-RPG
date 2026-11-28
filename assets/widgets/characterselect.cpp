#include "characterselect.h"
#include "qevent.h"
#include "ui_characterselect.h"

CharacterSelect::CharacterSelect(QWidget *parent,BoardSetup *b, shared_ptr<Player> p)
    : QWidget(parent)
    , ui(new Ui::CharacterSelect)
{

    _p=p;
    _b=b;

    _l1=new QLabel(this);
    _l1->setText("What is your name?");
    _l1->move(10,10);

    _name=new QLineEdit(this);
    _name->move(10,30);

    _l2=new QLabel(this);
    _l2->setText("...and of what blood is your flesh?");
    _l2->setAlignment(Qt::AlignCenter);
    _l2->setMaximumWidth(250);
    _l2->setWordWrap(true);
    _l2->move(10,60);

    _raceSelect=new QComboBox(this);
    _raceSelect->addItem(" Human");
    _raceSelect->addItem("Elf");
    _raceSelect->addItem("Dwarf");
    _raceSelect->addItem("Hobbit");
    _raceSelect->addItem("Orc");
    _raceSelect->move(10,100);

    _nextBttn=new QPushButton(this);
    connect(_nextBttn,&QPushButton::pressed,this,&CharacterSelect::Start);
    _nextBttn->setText("Proceed");
    _nextBttn->move(10,150);

    this->setFixedSize(150,210);

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
    delete _l1;
    delete _l2;
}
