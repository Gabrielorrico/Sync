#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>



typedef struct station{
    int esperandoOnBoard; //passageiros autorizados porem não chamaram a on_Board;
    int assentosVeiculo; //assentos totais
    int assentosLivres; //assentos livres 
    int confirmados; //passageiros que ja charam on_board
    int esperando; //passageiros esperando um proximo carro
    int carroNaEstacao; //bool para saber se tem carro na estação ou não
    pthread_mutex_t mutex;
    pthread_cond_t esperarConfirmados;
    pthread_cond_t esperarAutorizacao;
    
}station;

void station_init(station *station){
    station->esperandoOnBoard = 0; 
    station->assentosVeiculo = 0; 
    station->assentosLivres = 0; 
    station->confirmados = 0; 
    station->esperando = 0; 
    station->carroNaEstacao = 0;
    pthread_mutex_init(&station->mutex, NULL);
    pthread_cond_init(&station->esperarConfirmados, NULL);
    pthread_cond_init(&station->esperarAutorizacao, NULL);
}

void station_load_car(struct station *station, int count){
    station->assentosVeiculo = count;
    station->assentosLivres = count;
}

int main() {
    
    return 0;
}