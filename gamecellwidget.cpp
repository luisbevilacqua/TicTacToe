#include "gamecellwidget.h"

GameCellWidget::GameCellWidget(QWidget *parent) : QPushButton(parent)
{
}

void GameCellWidget::setPlayerToken(char token) {
    playerToken = token;
    setText(QString(token));
    setDisabled(true);
}

bool GameCellWidget::isEmpty() {
    return playerToken == EMPTY_CELL_TOKEN;
}

void GameCellWidget::clear() {
    playerToken = EMPTY_CELL_TOKEN;
    setText(QString(EMPTY_CELL_TOKEN));
    setDisabled(false);
}
