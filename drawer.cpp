#include "drawer.h"
#include "tempo.h"
#include <iostream>
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QTime>
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <QPixmap>
#include <QWidget>
#include <QPaintEvent>
#include <QDateTime>

drawer::drawer(QWidget *parent) : QWidget(parent){

}

void drawer::paintEvent(QPaintEvent *e){

    int time[9];


    srand(20);

    struct timeval start_time, stop;

    QPainter painter(this);
    QBrush brush;
    QPen pen;

    //configurações do retangulo branco
    brush.setColor(QColor(255,255,255));
    brush.setStyle(Qt::SolidPattern);

    pen.setColor(QColor(0,0,156));
    pen.setWidth(2);

    //Informações da tela
    painter.setBrush(brush);
    //Informações da caneta
    painter.setPen(pen);
    //O que deve desenhar (é preciso na ui promover o Qwidget com a classe drawer
    painter.drawRect(0,0,width(), height());

    QPixmap bolaazul("/home/gildson/Imagens/images.jpeg");
    QPixmap bolavermelha("/home/gildson/Imagens/vermelha.jpeg");
    QPixmap bolaamarela("/home/gildson/Imagens/amarelo.jpeg");
    QPixmap bolaverde("/home/gildson/Imagens/verde.jpeg");

    for(int i=0; i<=9; i++){
        update();
        //int bola = 1 + rand()%4;
        int bola = 0;
        int x = 1+rand()%width()/2;
        int y = 1+rand()%height()/2;
        if(bola == 1 && start == true){
            painter.drawRect(0,0,width(), height());
            painter.drawPixmap(x, y, bolavermelha);

        } else if (bola == 2 && start == true) {
            painter.drawRect(0,0,width(), height());
            painter.drawPixmap(x, y, bolaazul);

        }else if (bola == 3 && start == true) {
            painter.drawRect(0,0,width(), height());
            painter.drawPixmap(x, y, bolaamarela);

        }else if(bola == 4 && start == true){
            painter.drawRect(0,0,width(), height());
            painter.drawPixmap(x, y, bolaverde);
        }
    }
}

int drawer::getTempo(){
    int tempo = 0;
    return tempo;
}

int drawer::getScore(){
    int score = 0;
    return score;
}
