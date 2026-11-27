#ifndef CHARACTERSELECT_H
#define CHARACTERSELECT_H

#include "assets/widgets/gamewidget.h"
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
    CharacterSelect(QWidget *parent = nullptr,GameWidget *g=nullptr);
    ~CharacterSelect();

protected:
    void Start();
    void closeEvent(QCloseEvent *event);

private:
    Ui::CharacterSelect *ui;
    GameWidget * _g;

    QComboBox *_raceSelect;

    QPushButton *_nextBttn;
};

#endif // CHARACTERSELECT_H
