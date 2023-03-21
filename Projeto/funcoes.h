#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED
#include<stdio.h>
#include<string.h>
int i, j;

void mostra_matriz_pal(char matriz[5][9], int acertadas[5], int chances[5])
{
    for (i = 0; i < 5; i++)
    {
        printf("%i |", i+1);
        for (j = 0; j < 9; j++)
        {
            if (j >= strlen(matriz[i]))
            {
                printf("* |");

            }
            else if (acertadas[i])
            {
                printf("%c |", matriz[i][j]);

            }
            else
            {
                printf("  |");

            }
        }
        printf("\n");

    }
    printf("\n1 - Principal instrumento do rock? (%i tentativa(s) restante(s))\n", chances[0]);
    printf("2 - Segundo album de estudio do Black Sabbath? (%i tentativa(s) restante(s))\n", chances[1]);
    printf("3 - Genero musical cujo precursor sao bandas como Deep Purple, Led Zeppelin e Black Sabbath? (%i tentativa(s) restante(s))\n", chances[2]);
    printf("4 - Uma das musicas que Eric Clapton escreveu para Pattie Boyd? (%i tentativa(s) restante(s))\n", chances[3]);
    printf("5 - Bandas como Nirvana, Pearl Jam e Alice in Chains pertencem a qual movimento? (%i tentativa(s) restante(s))\n", chances[4]);
}

void verificar_pal(char pal[9], char matriz[5][9], int erros[5], int acertadas[5], int num, char matriz_aux[5][9])
{
    printf("\nResposta:");
    fflush(stdin);
    gets(pal);
    if (strcmp(pal, matriz[num-1]))
    {
        erros[num-1]--;
        printf("\nVoce errou!\n");

    }
    else
    {
        printf("\nVoce acertou!\n");
        acertadas[num-1] = 1;
        for (i = 0; i < strlen(pal); i++)
        {
            matriz_aux[num-1][i] = pal[i];
        }
    }
}

void verificar_letra(char letra[2], char digitadas[27], char matriz[5][9], int *erros, char matriz_aux[5][9])
{
    int acertou = 0;
    printf("\nLetra:");
    fflush(stdin);
    gets(letra);
    for (i = 0; i < strlen(digitadas); i++)
    {
        if (letra[0] == digitadas[i])
        {
            printf("\nLetra ja digitada!\n");
            return;
        }
    }
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 9; j++)
        {
            if (letra[0] == matriz[i][j])
            {
                acertou = 1;
                matriz_aux[i][j] = letra[0];
            }
        }
    }

    if (acertou)
    {
        strcat(digitadas, letra);
        printf("\nVoce acertou!\n");
        return;
    }
    printf("\nVoce errou!\n");
    *erros = *erros - 1;
    strcat(digitadas, letra);

    return;
}

void mostra_matriz_letra(char matriz[5][9], char matriz_aux[5][9], int erros)
{
    for (i = 0; i < 5; i++)
    {
        printf("%i |", i+1);
        for (j = 0; j < 9; j++)
        {
            if (j >= strlen(matriz[i]))
            {
                printf("* |");

            }
            else
            {
                if (matriz[i][j] == matriz_aux[i][j])
                {
                    printf("%c |", matriz[i][j]);
                }
                else
                {
                    printf("  |");
                }
            }

        }
        printf("\n");

    }


    printf("\n1 - Principal instrumento do rock?\n");
    printf("2 - Segundo album de estudio do Black Sabbath?\n");
    printf("3 - Genero musical cujo precursor sao bandas como Deep Purple, Led Zeppelin e Black Sabbath?\n");
    printf("4 - Uma das musicas que Eric Clapton escreveu para Pattie Boyd?\n");
    printf("5 - Bandas como Nirvana, Pearl Jam e Alice in Chains pertencem a qual movimento?");
    printf("\nNumero de chances: %i\n", erros);
}

void mostrar_ganhou(char matriz[5][9])
{
    printf("\nParabens! Voce ganhou o jogo!\n");
    for (i = 0; i < 5; i++)
    {
        printf("%i |", i+1);
        for (j = 0; j < 9; j++)
        {
            if (j >= strlen(matriz[i]))
            {
                printf("* |");

            }
            else
            {
                printf("%c |", matriz[i][j]);
            }
        }
        printf("\n");

    }

}


#endif // FUNCOES_H_INCLUDED
