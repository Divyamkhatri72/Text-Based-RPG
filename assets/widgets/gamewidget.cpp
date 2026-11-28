#include "gamewidget.h"
#include "qevent.h"
#include "qlabel.h"
#include "ui_gamewidget.h"

GameWidget::GameWidget(QWidget *parent, shared_ptr<Environment> e, shared_ptr<Player> p)
    : QWidget(parent)
    , ui(new Ui::GameWidget)
{
    _env=e;
    _env->PlacePlayer(p);

    _boardGrid=new QGridLayout(this);
    ResetBoard();

    _command=new QLineEdit(this);
    _command->move(10,90);

    ui->setupUi(this);
}

void GameWidget::keyPressEvent(QKeyEvent *event)
{
    if( event->text()=='\r')
    {
        _env->ReceiveCommand(_command->text().at(0));
        _command->setText("");
        ResetBoard();
    }
}


void GameWidget::DrawTileFor(int envX, int envY,int x, int y)
{
    shared_ptr<Entity> toDraw=_env->getTileEntity(envX,envY);

    if(toDraw!=nullptr)
        _boardGrid->addWidget(new QLabel(static_cast<QString>(typeid(toDraw).name())),x,y,1,1,Qt::AlignLeft); //Placeholder Code. Ellaborate on this later
    /*
     * SET ON GRID (TILENODE POINTER)
     * Get tilenode based on coordinates
     *if node points to empty, set as Empty
     *
     * If node is enemy, set as enemy
     *
     * if node is item, set as item
     *
     * if the node does not exist, don;t display anything
     */

}
void GameWidget::DrawNeighborsOf(int envX, int envY, int gridInitX, int gridInitCol)
{

    DrawTileFor(envX,envY,gridInitX,gridInitCol);

    if(_env->getTileEntity(envX,envY)!=nullptr)
    {
        DrawTileFor(envX-1,envY,gridInitX-1,gridInitCol);
        DrawTileFor(envX-2,envY,gridInitX-2,gridInitCol);
        DrawTileFor(envX+1,envY,gridInitX+1,gridInitCol);
        DrawTileFor(envX+1,envY,gridInitX+2,gridInitCol);
    }

    /*SET NEIGHBORS (Index x, int Y)
     * Get tilenode based on index
     *
     *
     * SET ON GRID (tilenode)
     *
     * if there is a node to the left of tilenode,
     *      SET ON GRID (prev tile)
     * if there is a node to the right of tilenode,
     *      SET ON GRID (next tile)
     *
     */



}


void GameWidget::ResetBoard()
{
    /* clear grid
     * make a 3 X 3 grid
     *
     * Get player TIleNode
     * Set player at center
     * SET NEIGHBORS (player node x, player node y)
     *
     * If there is a list of tiles above the player
     *      SET NEIGHBORS (player node x, player node y+1)
     * If there is a list of tiles below the player
     *      SET NEIGHBORS (player node x, player node y-1)
     */

    DrawNeighborsOf(0,0,0,2);
    DrawNeighborsOf(1,0,1,2);
    DrawNeighborsOf(2,0,2,2);
    DrawNeighborsOf(3,0,3,2);
    DrawNeighborsOf(4,0,4,2);

}

GameWidget::~GameWidget()
{
    delete ui;
    delete _boardGrid;
    delete _command;
}
