#include <iostream>
#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//Estrutura criada para guarda informações do programa
struct usuario
{
    string nome;
    int score = 0;
};

//int printbola(){}

int main()
{

    usuario unico;
    cout << "Digite seu nome" << endl;
    cin >> unico.nome;

    struct timeval time_reacao_inicio, time_reacao_final;
    int time_reacao[9];

    srand( time (NULL) );

    int comando;

    //São necessárias 10 tentativas, utilizaremos w(119) para cima/a(97) para esquerda/d(100) para direita/s(115) para baixo
    for(int i = 0; i <= 9; i++)
    {
        //(aqui está o problema)
        int bola = 1+rand()%4;

        //Assim que a bola aparece o tempo começa a ser contado
        printf("%d bola", bola);
        gettimeofday(&time_reacao_inicio, NULL);
        comando = getchar();
        gettimeofday(&time_reacao_final, NULL);
        //Após aperta a tecla o tempo para e é feito os calculos de quantos milissegundos a pessoa preciso
        //do momento de ver a bola até aperta a tecla.
        time_reacao[i] = (int) (1000 * (time_reacao_final.tv_sec - time_reacao_inicio.tv_sec) + (time_reacao_final.tv_usec - time_reacao_inicio.tv_usec) / 1000);

        if(bola == 1 && comando == 'w'){
            unico.score = unico.score+1;
        } else if (bola == 2 && comando == 'a'){
                unico.score = unico.score+1;
        } else if(bola == 3 && comando == 'd'){
                unico.score = unico.score+1;
        } else if(bola == 4 && comando == 's'){
                unico.score = unico.score+1;
        } else {
                unico.score = unico.score;
        }
     }

     cout << "O usuário " << unico.nome << endl;
     for(int j=0; j <= 9; j++)
     {
         printf("Gastou %d milissegundos na %d tentativa\n", time_reacao[j], j+1);
     }
     cout << "Acertou " << unico.score;

     return 0;
}
