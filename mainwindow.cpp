#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);

    connect(ui->pushButtonreset,
            SIGNAL(clicked(bool)),
            this,
            SLOT(reset()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::reset()
{
    ui->label_6->setText("Vamos de novo!");
    ui->label_5->clear();
    ui->textBrowser_tempo->setText(" ");
    ui->textBrowser_score->setText(" ");
    cont=0;
    tempo_medio = 0;
    score = 0;
}

void MainWindow::mostrarBolas(){

    cont++;

    QPixmap azul("/home/gildson/Imagens/azul.jpeg");
    QPixmap vermelha("/home/gildson/Imagens/vermelha.jpeg");
    QPixmap amarela("/home/gildson/Imagens/amarelo.jpeg");
    QPixmap verde("/home/gildson/Imagens/verde.jpeg");

    unsigned semente = time(0);
    srand(semente);

    bola=1+rand()%4;

    int x = rand()%565;
    int y = rand()%443;
    ui->label_5->setGeometry(rand()%565,rand()%443,100,100);

    tempo_real1 = time( (time_t *) 0);

    if(bola == 1){
        sleep(10);
        ui->label_5->clear();
        ui->label_5->setPixmap(vermelha.scaled(100,100,Qt::KeepAspectRatio));
        gettimeofday(&time_inicio, 0);

    } else if(bola == 2){
        sleep(10);
        ui->label_5->clear();
        ui->label_5->setPixmap(azul.scaled(100,100,Qt::KeepAspectRatio));
        gettimeofday(&time_inicio, 0);
    }else if(bola == 3){
        sleep(10);
        ui->label_5->clear();
        ui->label_5->setPixmap(amarela.scaled(100,100,Qt::KeepAspectRatio));
        gettimeofday(&time_inicio, 0);
    }else{
        sleep(10);
        ui->label_5->clear();
        ui->label_5->setPixmap(verde.scaled(100,100,Qt::KeepAspectRatio));
        gettimeofday(&time_inicio, 0);
    }
}

void MainWindow::on_pushButtoniniciar_clicked(){
    bool _start = true;
    cont=0;
    tempo_medio = 0;
    score = 0;
    mostrarBolas();
    ui->label_6->clear();
}

void MainWindow::sleep(int t){
    QTime dieTime= QTime::currentTime().addMSecs(t);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void MainWindow::keyPressEvent(QKeyEvent *event){

    tempo_real2 = time( (time_t *) 0);

    if(_start && cont <=11 && tempo_real2-tempo_real1 <= 10){
        if(event->key() == Qt::Key_W && bola == 1){
            score++;
            gettimeofday(&time_final, 0);
            tempo_medio = tempo_medio + (int) (1000 * (time_final.tv_sec - time_inicio.tv_sec) + (time_final.tv_usec - time_inicio.tv_usec) / 1000);
            mostrarBolas();
        }else if(event->key() == Qt::Key_A && bola == 2){
            score++;
            gettimeofday(&time_final, 0);
            tempo_medio = tempo_medio +  (int) (1000 * (time_final.tv_sec - time_inicio.tv_sec) + (time_final.tv_usec - time_inicio.tv_usec) / 1000);
            mostrarBolas();
        }else if(event->key() == Qt::Key_D && bola == 3){
            score++;
            gettimeofday(&time_final, 0);
            tempo_medio = tempo_medio +  (int) (1000 * (time_final.tv_sec - time_inicio.tv_sec) + (time_final.tv_usec - time_inicio.tv_usec) / 1000);
            mostrarBolas();
        }else if(event->key() == Qt::Key_S && bola == 4){
            score++;
            gettimeofday(&time_final, 0);
            tempo_medio = tempo_medio +  (int) (1000 * (time_final.tv_sec - time_inicio.tv_sec) + (time_final.tv_usec - time_inicio.tv_usec) / 1000);
            mostrarBolas();
        } else {
            mostrarBolas();
        }
    }else {
        mostrarBolas();
    }
        mostrarResultados();
        qDebug()<<tempo_real2-tempo_real1;
}

void MainWindow::mostrarResultados(){
    if(cont == 11){
        QMessageBox::about(this, "Resultados", "Tempo médio: " + QString::number(tempo_medio/10, QLocale::English, 2) + "ms \nScore: " + QString::number(score));
    ui->textBrowser_tempo->setText(QString::number(tempo_medio/10, QLocale::English, 2));
    ui->textBrowser_score->setText(QString::number(score));
    }
}
