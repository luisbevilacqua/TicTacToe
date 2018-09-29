#ifndef GAMECELLWIDGET_H
#define GAMECELLWIDGET_H

#include <QPushButton>
#include <QWidget>

class GameCellWidget : public QPushButton
{
    Q_OBJECT
public:
    explicit GameCellWidget(QWidget *parent = nullptr);
    bool isEmpty();
    void setPlayerToken(char token);
    char playerToken = EMPTY_CELL_TOKEN;

signals:

public slots:
    void clear();

private:
    static const char EMPTY_CELL_TOKEN = ' ';
};

#endif // GAMECELLWIDGET_H
