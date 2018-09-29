#ifndef GAMEBOARDWIDGET_H
#define GAMEBOARDWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <gamecellwidget.h>

class GameBoardWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameBoardWidget(QWidget *parent = nullptr);
    bool checkForWinners();

signals:
    void gameFinished();
    void gameFinished(char winnerToken);
    void gameFinished(QString formatedWinner);

public slots:
    void performMove();
    void finishGame();
    void restartGame();

private:
    static const int NUMBER_OF_COLUMNS = 3;
    static const int NUMBER_OF_ROWS = 3;
    static const int NUMBER_OF_PLAYERS = 2;
    const char PLAYER_TOKENS[NUMBER_OF_PLAYERS] = {'X', 'O'};

    GameCellWidget* gameMatrix[NUMBER_OF_COLUMNS][NUMBER_OF_ROWS];

    int currentPlayerIndex = 0;
    char winnerPlayerToken = ' ';
    bool draw = false;

    char currentPlayerToken();
    int nextPlayerIndex();

    bool areAllEqual(GameCellWidget *array[], int size);
    bool checkRows();
    bool checkColumns();
    bool checkDiagonals();
    bool gameBoardFull();

    QString formatedWinnerText();
};

#endif // GAMEBOARDWIDGET_H
