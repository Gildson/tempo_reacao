#include <iostream>
#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

using namespace std;

//Estrutura criada para guarda informações do programa
typedef struct
{
  string nome;
  int score;
}usuario;


int main()
{
		
    usuario unico;
    cout << "Digite seu nome" << endl;
    cin >> unico.nome;
    
    struct timeval time_reacao_inicio, time_reacao_final;
    int time_reacao[9];

    unsigned semente = time(0);
    srand(semente);
    
    char comando;

    //São necessárias 10 tentativas, utilizaremos w(119) para cima/a(97) para esquerda/d(100) para direita/s(115) para baixo 
    for(int i = 0; i <= 9; i++)
    {
        int bola = 1 + rand()%4;
        sleep(rand()%3);
        cout << bola << endl; 
        gettimeofday(&time_reacao_inicio, NULL);
        cin >> comando;
        gettimeofday(&time_reacao_final, NULL);
		  if(bola == 1 && comando == 'w'){
            unico.score = unico.score+1;
            time_reacao[i] = (int) (1000 * (time_reacao_final.tv_sec - time_reacao_inicio.tv_sec) + (time_reacao_final.tv_usec - time_reacao_inicio.tv_usec) / 1000);
        } else if (bola == 2 && comando == 'a'){
        		unico.score = unico.score+1;
            time_reacao[i] = (int) (1000 * (time_reacao_final.tv_sec - time_reacao_inicio.tv_sec) + (time_reacao_final.tv_usec - time_reacao_inicio.tv_usec) / 1000);
        } else if(bola == 3 && comando == 'd'){
				unico.score = unico.score+1;
            time_reacao[i] = (int) (1000 * (time_reacao_final.tv_sec - time_reacao_inicio.tv_sec) + (time_reacao_final.tv_usec - time_reacao_inicio.tv_usec) / 1000);
        } else if(bola == 4 && comando == 's'){
				unico.score = unico.score+1;
            time_reacao[i] = (int) (1000 * (time_reacao_final.tv_sec - time_reacao_inicio.tv_sec) + (time_reacao_final.tv_usec - time_reacao_inicio.tv_usec) / 1000);
        } else {
            time_reacao[i] = (int) (1000 * (time_reacao_final.tv_sec - time_reacao_inicio.tv_sec) + (time_reacao_final.tv_usec - time_reacao_inicio.tv_usec) / 1000);
        }
     }

    int tempo_medio=0;
     for(int j=0; j <= 9; j++)
     {
     		 tempo_medio += time_reacao[j];
     }
     cout << unico.nome << " Teve um score de " << unico.score << " com tempo médio de resposta de " << tempo_medio/10 << endl;
     return 0;
}
