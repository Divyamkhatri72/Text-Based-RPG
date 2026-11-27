#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include "assets/environment/environment.h"
#include <QWidget>

namespace Ui {
class GameWidget;
}

class GameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GameWidget(QWidget *parent = nullptr);
    GameWidget(QWidget *parent=nullptr,Environment *e=nullptr);
    void ResetBoard();
    ~GameWidget();
protected:
    void keyPressEvent(QKeyEvent *event) override;
private:
    Ui::GameWidget *ui;
    Environment *_env;
};

#endif // GAMEWIDGET_H
