#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "funcoes.h"

//Variaveis
char sChute;
char sChutesCerto[20];
char sChutesErrado[26];
char sPalavraSecreta[20];

int bAcertou;
int bChuteOK;
int bEnforcou;

int nNumLinhas;
int nTentativa;
int nTentativasNivel;

//Registradores
char cReg1;

int nReg1;

void rResetaVariaveis()
{
    //Reseta variaveis
    bAcertou    = 0;
    bEnforcou   = 0;
    nTentativa  = 1;
    sChutesErrado[26] = "";
}

void rAtribuiPalavra()
{
    //Abre o arquivo
    FILE* f;

    f = fopen("c:\\Users\\ptiag\\Documents\\Alura\\C_1\\palavras.txt" , "r");


    //Verifica quantas linhas tem o arquivo
    fscanf(f, "%d", &nNumLinhas);


    //Atribui palavra
    srand(time(0));
    int nReg1 = rand() % nNumLinhas;

    for (int i = 0; i <= nReg1 ; i++)
    {
        fscanf(f , "%s", sPalavraSecreta);
    }
    
    //Fecha arquivo
    fclose(f);

    //Atribui sChutesCerto
    for (int i = 0; i < strlen(sPalavraSecreta); i++)
    {
        sChutesCerto[i] = '-';
    }
}

void rAtribuiDificuldade()
{
    LABEL_1:

    //Atribui dificuldade
    printf("Qual a dificuldade?: \n");
    printf("1- Facil \n");
    printf("2- Moderado \n");
    printf("3- Dificil \n");
    scanf("%d", &nReg1);

    switch (nReg1)
    {
    case 1:
        nTentativasNivel = 20;
        break;
    
    case 2:
        nTentativasNivel = 10;
        break;
    
    case 3:
        nTentativasNivel =  5;
        break;
    
    default:
        printf("Selecionar um valor valido \n");
        goto LABEL_1;
    }
    printf("\n\n");
}

int main(void)
{
    
    rResetaVariaveis();

    rAtribuiPalavra();

    rAtribuiDificuldade();

    do
    {
        printf("Tentativa %d de %d \n",nTentativa, nTentativasNivel);
        printf("Palavra secreta: %s \n", sChutesCerto);
        printf("Chutes errado:   %s \n\n", sChutesErrado);

        //Le chute do usuario
        bChuteOK = 0;
        printf("Chute uma letra: \n");
        scanf(" %c",&sChute);

        //Verifica o chute
        for (int i = 0; i < strlen(sPalavraSecreta); i++)
        {
            if (sChute == sPalavraSecreta[i]) //acertou o chute
            {
                sChutesCerto[i] = sChute;
                bChuteOK = 1;
            }
            
            
        }
        printf("\n");
        
        if (!bChuteOK)//errou o chute
        {                
            sChutesErrado[nTentativa - 1] = sChute;
            nTentativa ++;
        }

        //Verifica fim do jogo
        if (nTentativa > nTentativasNivel)
        {
            bEnforcou = 1;
            bAcertou  = 0;
            printf("Voce perdeu");
        }
        else if (strcmp(sChutesCerto,sPalavraSecreta) == 0)
        {
            bEnforcou = 0;
            bAcertou  = 1;

            printf("Voce ganhou");
        }

    } while (!bAcertou && !bEnforcou);
   
}