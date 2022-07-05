#include <stdio.h>
#include <stdlib.h>

int** grafo;
int** cripto;
int tamGrafo = 0;
int caminho[10];
int valorCaminho = 0;
int posicaoJ = 0;
int posicaoI = 0;
int pontoFinal = 0;
int pontoInicial = 0;
int menorPosicao = 0;
int posicaoAtual = 0;
int distancia = 0;


int main(){

    int retornaMenorPosicao(), alocaMemoria(), leMatriz(), criptoMatriz(), liberaMemoriaAlocada();
    
    scanf("%d", &tamGrafo);
    
    alocaMemoria();
    
    leMatriz();
    
    criptoMatriz();
    
    scanf("%d\n%d", &pontoInicial, &pontoFinal);
    
    if (grafo[pontoInicial][pontoInicial] == 0){
        posicaoJ = pontoInicial;
        posicaoI = pontoInicial;
        
        do{
            if(posicaoJ  == pontoFinal|| posicaoI == pontoFinal){
                break;
            }
            retornaMenorPosicao();
        } while (retornaMenorPosicao());
        
        printf("Distancia total entre %d e %d: %d\n", pontoInicial, pontoFinal, distancia);
        printf("Caminho: ");
        for (int i = 0; i < valorCaminho; i++) {
            printf("%d->", caminho[i]);
        }
        printf("%d\n", pontoFinal);
        
    }
    
    liberaMemoriaAlocada();
    return 0;
}

int alocaMemoria(){
    // alocacao dinâmica de memória
    grafo = malloc(sizeof(int*) * tamGrafo);
    cripto = malloc(sizeof(int*) * tamGrafo);
    
    for(int i = 0; i < tamGrafo; i++) {
        grafo[i] = malloc(sizeof(int) * (tamGrafo+1));
        cripto[i] = malloc(sizeof(int) * (tamGrafo+1));
    }
    return 0;
}

int leMatriz(){
    // lendo matriz | i sendo a linha, j sendo a coluna
    for (int i = 0; i < tamGrafo; i++) {
        for (int j = 0; j < tamGrafo; j++) {
            scanf("%d", &grafo[i][j]);
        }
    }
    return 0;
}

int criptoMatriz(){
    for (int i = 0; i < tamGrafo; i++) {
        for (int j = 0; j < tamGrafo; j++) {
            cripto[i][j] = 0;
        }
    }
    return 0;
}

int retornaMenorPosicao(){
    int contador = 0, i = posicaoI; // recebe i
    int posicaoJRef = posicaoJ;
    
    if(i == pontoFinal){
        return 0;
    }
    
    for (int j = 0; j < tamGrafo; j++) {
        if((grafo[i][j] != 0) && (j != posicaoJRef) && (cripto[i][j] == 0) && (cripto[i][j] == 0)) { // começa com 
            if((contador == 1) && (grafo[i][j] < menorPosicao)){
                if((grafo[i][j] < menorPosicao) || (grafo[j][i] < menorPosicao)){
                    menorPosicao = grafo[i][j];
                    posicaoI = j;
                    cripto[i][j] = 1;
                    cripto[j][i] = 1;
                }
            } else if ((contador == 0 )) {
                menorPosicao = grafo[i][j];
                posicaoI = j;
                contador = 1;
                cripto[i][j] = 1;
                cripto[j][i] = 1;
            } 
        }

    }
    caminho[valorCaminho] = i;
    posicaoAtual = menorPosicao;
    distancia += posicaoAtual;
    valorCaminho++; //array de caminhos;
    return 1;
}

int liberaMemoriaAlocada(){
    // liberando memoria
    for (int i = 0; i < tamGrafo; i++) {
        free(grafo[i]);
        free(cripto[i]);
    }
    free(grafo);
    free(cripto);
    return 0;
}
