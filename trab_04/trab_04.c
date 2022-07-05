#include <stdio.h>
#include <string.h>

char frase[1000][5000];
char textoConcatenado[50000];
char textoConcLimpo[20000];
int qtdFrases = 0;
int tamanhoDoTexto = 0;

void verificaCaracter(int posicaoInicial, int posicaoFinal){
    int qtdPorLetra[posicaoFinal - posicaoInicial];
    
    for (int i = 0; i <= (posicaoFinal - posicaoInicial); i++) {
        qtdPorLetra[i] = 0;
    }
    
    for (int i = 0; i < tamanhoDoTexto; i++) {
        for (char letra = posicaoInicial; letra <= posicaoFinal; letra++) {
            if(textoConcLimpo[i] == letra){
                qtdPorLetra[letra - posicaoInicial] += 1;
            }
        }
    }
    
    for (char letra = posicaoInicial, i = 0; letra <= posicaoFinal; letra++, i++) {
        printf("%c: ", letra);
        int qtd = qtdPorLetra[i];
        for (int j = 1; j <= qtd; j++) {
            printf("*");
        }
        float prob = (float)qtd/tamanhoDoTexto;
        printf(" (%d - %.2f)", qtd, prob);
        printf("\n");
    }
}

void limpaTexto(){
    int posicaoNovoArray = 0;
    for (int i = 0; i < strlen(textoConcatenado); i++) {
        // 48 a 57 => numeros  | 65 a 90 => letras maiusculas | 97 a 122 => letras minusculas
        if((textoConcatenado[i] >= 48 && textoConcatenado[i] <= 57) ||
        (textoConcatenado[i] >= 65 && textoConcatenado[i] <= 90) ||
        (textoConcatenado[i] >= 97 && textoConcatenado[i] <= 122)){
            textoConcLimpo[posicaoNovoArray] = textoConcatenado[i];
            posicaoNovoArray++;
        }
    }
    tamanhoDoTexto = strlen(textoConcLimpo);
}

void leEConcatenaTexto(){
    do{
        fgets(frase[qtdFrases], 1000, stdin);
        if(frase[qtdFrases][0] != '\n' && strcmp(frase[qtdFrases], "FIM")){
            if(frase[qtdFrases][0] == 'F' && frase[qtdFrases][1] == 'I' && frase[qtdFrases][2] == 'M'){
                break;
            }
            strcat(textoConcatenado, frase[qtdFrases]);
            qtdFrases++;
        }
    }while(frase[qtdFrases][0] != 'F' && frase[qtdFrases][1] != 'I' && frase[qtdFrases][2] != 'M');
}

int main()
{
    leEConcatenaTexto();
    
    limpaTexto();
    
    //printf("textoConcatenadoLimpo: %s| tamanho do texto: %d", textoConcLimpo, tamanhoDoTexto);
    
    //verificaMaiusculos() - 65 até 90 na tabela ASCII ;
    printf("Caracteres Maiusculos:\n");
    verificaCaracter(65, 90);
    
    //verificaMinusculos() - 97 até 122 na tabela ASCII ;
    printf("\nCaracteres Minusculos:\n");
    verificaCaracter(97, 122);
    
    //verificaNumeros() - 48 a 57;
    printf("\nDigitos:\n");
    verificaCaracter(48, 57);
    
    return 0;
}
