//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Variaveis inteiraas
int nContinuar;
int nChute;
int nNivel;
int nNumeroSecreto;
int nPontos;
int nTentativas;

//Variaveis booleanas

int main()
{   
    LABEL_1:

    //Cabecalho
    printf("********************************\n");
    printf("Bem vindo ao jogo de adivinhacao\n");
    printf("********************************\n");

    //Reseta pontos
    nPontos = 1000;

    //Atribui numero secreto
    srand(time(0));
    int nNumeroSecreto = (rand() % 100);

    LABEL_2:

    //Atribui nivel
    printf("Escolha um nivel: \n");
    printf("1- Facil    = 20 tentativas \n");
    printf("2- Moderado = 10 tentativas \n");
    printf("3- Dificil  =  5 tentativas \n");
    scanf("%d", &nNivel);

    switch (nNivel)
    {
    case 1:
        nTentativas = 20;
        break;

    case 2:
        nTentativas = 10;
        break;

    case 3:
        nTentativas = 5;
        break;
    
    default:
        printf("Valor invalido, escolha novamente");
        goto LABEL_2;
        break;
    }

    
	
    for (int i = 1; i <= nTentativas; i++)
    {
        printf("Tentativa %d de %d \n",i, nTentativas);

        //Verifica o chute
        printf("Qual eh seu chute?: \n");
        scanf("%d", &nChute);

        //Verifica chute
        if (nChute == nNumeroSecreto) //acertou
        {
            printf("PARABENS...Voce acertou o/ \n\n");
            goto LABEL_3;
        }

        else if (nChute > nNumeroSecreto)            
        {
        printf("Quase...seu chute foi maior \n\n");
        }

        else if (nChute < nNumeroSecreto)
        {
            printf("Por pouco, seu chute foi menor \n\n");
        }

        nPontos = nPontos - abs(nChute - nNumeroSecreto);
        
    }

    //Perdeu
    printf("Que pena my friend... voce nao acertou :'( \n");

    LABEL_3:

    //Fim de jogo
    printf("O numero secreto era: %d \n",nNumeroSecreto);
    printf("Sua pontuacao foi de: %d \n",nPontos);
    printf("Deseja jogar de novo? \n");
    printf("0- NAO \n");
    printf("1- SIM \n");
    scanf("%d", &nContinuar);
    if (nContinuar)
    {
        goto LABEL_1;
    }
    
}