#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGuiApplication>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

    QPixmap azul("/home/gildson/Imagens/images.jpeg");
    QPixmap vermelha("/home/gildson/Imagens/vermelha.jpeg");
    QPixmap amarela("/home/gildson/Imagens/amarelo.jpeg");
    QPixmap verde("/home/gildson/Imagens/verde.jpeg");

void MainWindow::on_pushButton_clicked()
{
    ui->label_4->setPixmap(vermelha.scaled(100,100,Qt::KeepAspectRatio));
}
