#include "gameboardwidget.h"

GameBoardWidget::GameBoardWidget(QWidget *parent) : QWidget(parent)
{
    QGridLayout *layout = new QGridLayout();

    for(int i = 0; i < NUMBER_OF_COLUMNS; i++) {
        for(int j = 0; j < NUMBER_OF_ROWS; j++) {
            GameCellWidget *gameCell = new GameCellWidget();

            gameMatrix[i][j] = gameCell;
            connect(gameCell, SIGNAL(clicked()), this, SLOT(performMove()));

            layout->addWidget(gameCell, i, j);
        }
    }

    setLayout(layout);
    show();
}

void GameBoardWidget::performMove() {
    GameCellWidget* clickedCell = qobject_cast<GameCellWidget*>(sender());

    clickedCell->setPlayerToken(currentPlayerToken());

    checkForWinners();

    if(winnerPlayerToken != ' ') {

    }
    else if(draw) {

    }
    else {
        currentPlayerIndex = nextPlayerIndex();
    }
}

void GameBoardWidget::checkForWinners() {
  if(checkRows() || checkColumns() || checkDiagonals() || gameBoardFull()) {
      finishGame();
      emit gameFinished();
  }
}

void GameBoardWidget::finishGame() {
    for(int i=0; i < NUMBER_OF_COLUMNS; i++){
        for(int j=0; j < NUMBER_OF_ROWS; j ++){
            gameMatrix[i][j]->setDisabled(true);
        }
    }
}

void GameBoardWidget::restartGame() {
    for(int i=0; i < NUMBER_OF_COLUMNS; i++){
        for(int j=0; j < NUMBER_OF_ROWS; j ++){
            gameMatrix[i][j]->clear();
        }
    }
    currentPlayerIndex = 0;
    winnerPlayerToken = ' ';
    draw = false;
}

bool GameBoardWidget::checkRows() {
    for(int i = 0; i < NUMBER_OF_ROWS; i++){
        GameCellWidget* row[NUMBER_OF_COLUMNS];

        for(int j = 0; j < NUMBER_OF_COLUMNS; j++){
          row[j] = gameMatrix[i][j];
        }

        if(areAllEqual(row, NUMBER_OF_COLUMNS)){
          winnerPlayerToken = row[0]->playerToken;
          return true;
        }
     }
    return false;
}

bool GameBoardWidget::checkColumns() {
    for(int i = 0; i < NUMBER_OF_COLUMNS; i++){
        GameCellWidget* column[NUMBER_OF_ROWS];

        for(int j = 0; j < NUMBER_OF_ROWS; j++){
          column[j] = gameMatrix[j][i];
        }

        if(areAllEqual(column, NUMBER_OF_COLUMNS)){
          winnerPlayerToken = column[0]->playerToken;
          return true;
        }
     }
    return false;
}

bool GameBoardWidget::checkDiagonals() {
    int diagonalSize = std::min(int(NUMBER_OF_COLUMNS), int(NUMBER_OF_ROWS));

    GameCellWidget* firstDiagonal[diagonalSize];
    GameCellWidget* secondDiagonal[diagonalSize];

    for(int i = 0; i < diagonalSize; i++){
         firstDiagonal[i] = gameMatrix[i][i];
         secondDiagonal[i] = gameMatrix[diagonalSize - i - 1][i];
    }

    if(areAllEqual(firstDiagonal, diagonalSize)){
      winnerPlayerToken = firstDiagonal[0]->playerToken;
      return true;
    }
    else if(areAllEqual(secondDiagonal, diagonalSize)){
      winnerPlayerToken = secondDiagonal[0]->playerToken;
      return true;
    }

    return false;
}


bool GameBoardWidget::gameBoardFull() {
    for(int i=0; i < NUMBER_OF_COLUMNS; i++){
        for(int j=0; j < NUMBER_OF_ROWS; j ++){
            if(gameMatrix[i][j]->isEmpty()){
                return false;
            }
        }
    }
    return true;
}

bool GameBoardWidget::areAllEqual(GameCellWidget *array[], int size){
    int position = 0;

    while(++position < size &&
          array[0]->playerToken == array[position]->playerToken &&
          !array[0]->isEmpty()
         );

    return position == size;
}

char GameBoardWidget::currentPlayerToken() {
    return PLAYER_TOKENS[currentPlayerIndex];
}

int GameBoardWidget::nextPlayerIndex() {
    int nextPlayerIndex = currentPlayerIndex + 1;

    if(nextPlayerIndex >= NUMBER_OF_PLAYERS) {
       nextPlayerIndex = 0;
    }

    return nextPlayerIndex;
}
