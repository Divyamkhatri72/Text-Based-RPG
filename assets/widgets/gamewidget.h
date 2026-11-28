#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include "assets/environment/environment.h"
#include "qlineedit.h"
#include <QWidget>
#include <QGridLayout>

namespace Ui {
class GameWidget;
}

class GameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GameWidget(QWidget *parent = nullptr);
    GameWidget(QWidget *parent=nullptr,shared_ptr<Environment> e=nullptr,shared_ptr<Player> p=nullptr);
    ~GameWidget();
protected:
    void keyPressEvent(QKeyEvent *event) override;
    void ResetBoard();

private:
    Ui::GameWidget *ui;
    QGridLayout *_boardGrid;
    QLineEdit *_command;
    shared_ptr<Environment> _env;
    shared_ptr<Player> _p;


    void DrawTileFor(int envX, int envY,int gridX, int gridY);
    void DrawNeighborsOf(int envX, int envY,int gridInitX, int gridInitY);
};

#endif // GAMEWIDGET_H
