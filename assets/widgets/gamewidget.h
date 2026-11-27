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
    GameWidget(QWidget *parent=nullptr,Environment *e=nullptr);
    ~GameWidget();
protected:
    void keyPressEvent(QKeyEvent *event) override;
    void ResetBoard();
private:
    Ui::GameWidget *ui;
    Environment *_env;
    QGridLayout *_boardGrid;
    QLineEdit *_command;
};

#endif // GAMEWIDGET_H
