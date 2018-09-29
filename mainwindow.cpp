#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->restartButton, SIGNAL(clicked()), ui->gameBoard, SLOT(restartGame()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
