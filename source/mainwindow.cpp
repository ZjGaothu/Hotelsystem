#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"customerlist.h"
#include"hotelmanagerlist.h"

extern customerlist L1;
extern hotelmanagerlist L2;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
