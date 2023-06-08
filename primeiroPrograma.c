#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Variaveis
    int nTentativas;
    int nAcertou;
    int nNumSecreto;
    int nNivel;
    int nChute;

    // Atribui numero secreto
    srand(time(0));
    nNumSecreto = rand() % 100;

    // IHM_1 - Boas vindas
    printf("******************************** \n");
    printf("Bem vindo ao Jogo de adivinhação \n");
    printf("******************************** \n");

    // IHM_2 - Seleciona nivel
    printf("Selecione a dificuldade: \n");
    printf("1 - Fácil \n");
    printf("2 - Médio \n");
    printf("3 - Difícil \n");

    // Atribui o nide de dificuldade
    scanf("%d", &nNivel);
    switch (nNivel)
    {
    case 1:
        nTentativas = 10;
        break;

    case 2:
        nTentativas = 5;
        break;

    case 3:
        nTentativas = 3;
        break;

    default:
        printf("Escolha inválida \n");
        break;
    }

    for (int i = 1; i <= nTentativas; i++)
    {
        // IHM_7 - Tentativas
        printf("\n");
        printf("********************************** \n");
        printf("Tentativa %d de %d \n", i, nTentativas);

        // IHM_3 - Requisita chute
        printf("Qual é seu chute? \n");

        // Atribui chute
        scanf("%d", &nChute);

        // Verifica chute
        nAcertou = (nChute == nNumSecreto);

        // IHM_4 - Chute errado maior
        if ((nAcertou == 0) && (nChute > nNumSecreto))
        {
            printf("Seu chute foi maior \n");
        }

        // IHM_5 - Chute errado menor
        if ((nAcertou == 0) && (nChute < nNumSecreto))
        {
            printf("Seu chute foi menor \n");
        }

        // IHM_6 - Chute certo
        if (nAcertou == 1)
        {
            printf("\n");
            printf("\nParabens você GANHOU \\O/ \n");
            break;
        }
    
    }

    if (nAcertou == 0)
        {
            printf("\n");
            printf("Que pena, você perdeu :/ \n");
            printf("O número secreto era: %d \n",nNumSecreto);
        }

    printf("---> FIM DE JOGO <---\n");
}