#ifndef BOARDSETUP_H
#define BOARDSETUP_H

#include "gamewidget.h"
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
    BoardSetup(QWidget *parent = nullptr,GameWidget *g=nullptr);
    ~BoardSetup();
protected:
    void StartGame();

private:
    Ui::BoardSetup *ui;
    QLineEdit *xInput;
    QLineEdit *yInput;
    QPushButton *startButton;
    GameWidget *game;
};

#endif // BOARDSETUP_H
