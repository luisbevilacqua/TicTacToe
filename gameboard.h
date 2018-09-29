#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QWidget>

namespace Ui {
class GameBoard;
}

class GameBoard : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameBoard(QWidget *parent = nullptr);
    ~GameBoard();

private:
    Ui::GameBoard *ui;
};

#endif // GAMEBOARD_H
