#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->restartButton, SIGNAL(clicked()), ui->gameBoard, SLOT(restartGame()));
    connect(ui->restartButton, SIGNAL(clicked()), ui->winnerLabel, SLOT(clear()));
    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->gameBoard, SIGNAL(gameFinished(QString)), ui->winnerLabel, SLOT(setText(QString)));
    connect(ui->gameBoard, SIGNAL(turnPassed(QString)), ui->turnIndicatorLabel, SLOT(setText(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
