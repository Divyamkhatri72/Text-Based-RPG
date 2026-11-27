#ifndef BOARDSETUP_H
#define BOARDSETUP_H

#include "assets/widgets/characterselect.h"
#include "qlineedit.h"
#include <QWidget>
#include <QPushButton>

namespace Ui {
class BoardSetup;
}

class BoardSetup : public QWidget
{
    Q_OBJECT

public:
    explicit BoardSetup(QWidget *parent = nullptr);
    BoardSetup(QWidget *parent = nullptr,CharacterSelect *c=nullptr, Environment *e=nullptr);
    ~BoardSetup();

protected:
    void Next();
     void closeEvent(QCloseEvent *event);

private:
    Ui::BoardSetup *ui;
    QLineEdit *_xInput;
    QLineEdit *_yInput;
    QPushButton *_nextBttn;
    CharacterSelect *_ch;
    Environment *_env;
};

#endif // BOARDSETUP_H
