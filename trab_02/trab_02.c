#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// compara filamento1 com filamento2
char Compare(char compared1[], char compared2[]){
    
    // variaveis para comparação
    int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2= 0, d1 = 0, d2 = 0, e1 = 0, e2 = 0, f1 = 0, f2 = 0;
    
    // contador de caracteres
    for (int i = 0; i < 13; i++) {
        switch(compared1[i]){
            case 'A' :
                a1++;
                break;
            case 'B' :
                b1++;
                break;
            case 'C' :
                c1++;
                break;
            case 'D' :
                d1++;
                break;
            case 'E' :
                e1++;
                break;
            case 'F' :
                f1++;
                break;
        }
        
        switch(compared2[i]){
            case 'A' :
                a2++;
                break;
            case 'B' :
                b2++;
                break;
            case 'C' :
                c2++;
                break;
            case 'D' :
                d2++;
                break;
            case 'E' :
                e2++;
                break;
            case 'F' :
                f2++;
                break;
        }
        
    }
    
    // retorno da função
    if(a1 == a2 && b1 == b2 && c1 == c2 && d1 == d2 && e1 == e2 && f1 == f2 ){
        return 1;
    } 
    else {
        return 0;
    }
}

// função principal
int main()
{   
    // variaveis
    char filamento[2][13] = {"XXXXXXXXXXXX", "YYYYYYYYYYYY"};
    int nCasos;

    // entrada => quantidade de repetições
    scanf("%d", &nCasos);
    while(nCasos > 0){
        // entrada =>  filamentos
        scanf("%s", filamento[0]);
        scanf("%s", filamento[1]);

        // valida char
        bool res = Compare(filamento[0], filamento[1]);

        if(res){
            // saída
            printf("Caracteristicas Iguais\n");
        } 
        else {
            // saída
            printf("Caracteristicas Diferentes\n");
        }
        nCasos--;
    }
     
        
    return 0;
}
