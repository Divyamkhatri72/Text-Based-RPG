#ifndef BOARDSETUP_H
#define BOARDSETUP_H

#include "assets/widgets/gamewidget.h"
#include "qlabel.h"
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
    BoardSetup(QWidget *parent = nullptr,GameWidget *g=nullptr, shared_ptr<Environment> e=nullptr);
    ~BoardSetup();

protected:
    void Next();
     void closeEvent(QCloseEvent *event);

private:
    Ui::BoardSetup *ui;
    QLineEdit *_xInput;
    QLineEdit *_yInput;
    QPushButton *_nextBttn;
    QLabel *_l;
    GameWidget * _g;
    shared_ptr<Environment> _env;
};

#endif // BOARDSETUP_H
