#ifndef CHARACTERSELECT_H
#define CHARACTERSELECT_H

#include "assets/entity/character.h"
#include "assets/widgets/boardsetup.h"
#include "qlabel.h"
#include "qpushbutton.h"
#include <QWidget>
#include <QComboBox>

namespace Ui {
class CharacterSelect;
}

class CharacterSelect : public QWidget
{
    Q_OBJECT

public:
    explicit CharacterSelect(QWidget *parent = nullptr);
    CharacterSelect(QWidget *parent = nullptr,BoardSetup *b=nullptr, shared_ptr<Player> p=nullptr);
    ~CharacterSelect();

protected:
    void Start();
    void closeEvent(QCloseEvent *event);

private:
    Ui::CharacterSelect *ui;
    BoardSetup * _b;

    QLabel *_instruction;
    QComboBox *_raceSelect;
    QLineEdit *_name;
    QPushButton *_nextBttn;
    shared_ptr<Player> _p;

};

#endif // CHARACTERSELECT_H
