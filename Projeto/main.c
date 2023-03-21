#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "funcoes.h"

char matriz[5][9] = { "guitarra", "paranoid", "metal", "layla", "grunge" }, palavra[9], letra[2];
int i, j, x, opc, num;

int main()
{
    do
    {
        char matriz_aux[5][9] = {"", "", "", "", ""},  digitadas[27];
        int ganhou, perdeu = 0, chances_pal[5] = {2, 2, 2, 2, 2}, acertadas[5] = {0, 0, 0, 0, 0}, chances_letra = 7;
        printf("=========WORD PLAY: ROCK=========\nObs: apenas letras minusculas\nVoce deseja jogar como?\n(1) Tentar Palavra inteira\n(2) Tentar letra a letra\n(3) Sair\n");
        scanf("%i", &opc);
        switch (opc)
        {
        case 1:
            do
            {
                for (i = 0; i < 5; i++)
                {

                    if (chances_pal[i] == 0)
                    {
                        perdeu = 1;
                        break;
                    }
                }

                for (i = 0; i < 5; i++)
                {
                    if (strcmp(matriz[i], matriz_aux[i]) != 0)
                    {
                        ganhou = 0;
                        break;
                    }
                    ganhou = 1;
                }


                if (perdeu)
                {
                    printf("\n---------->FIM DE JOGO<-------------\n\n");
                    break;
                }

                if (ganhou)
                {
                    mostrar_ganhou(matriz);
                    break;
                }
                mostra_matriz_pal(matriz, acertadas, chances_pal);
                do
                {
                    printf("\nInforme a palavra a ser adivinhada (Numero 1 ao 5):");
                    scanf("%i", &num);
                    if (acertadas[num-1])
                    {
                        printf("\nVoce ja acertou essa!\n");
                    }
                    else
                    {
                        break;
                    }
                }
                while(1);
                switch (num)
                {
                case 1:
                    verificar_pal(palavra, matriz, chances_pal, acertadas, num, matriz_aux);
                    break;
                case 2:
                    verificar_pal(palavra, matriz, chances_pal, acertadas, num, matriz_aux);
                    break;
                case 3:
                    verificar_pal(palavra, matriz, chances_pal, acertadas, num, matriz_aux);
                    break;
                case 4:
                    verificar_pal(palavra, matriz, chances_pal, acertadas, num, matriz_aux);
                    break;
                case 5:
                    verificar_pal(palavra, matriz, chances_pal, acertadas, num, matriz_aux);
                    break;
                default:
                    printf("\nOpcao invalida!\n");
                }
            }
            while(1);
            break;
        case 2:
            do
            {
                if (chances_letra == 0)
                {
                    printf("\n---------->FIM DE JOGO<------------\n\n");
                    break;
                }
                for (i = 0; i < 5; i++)
                {
                    if (strcmp(matriz_aux[i], matriz[i]) != 0)
                    {
                        ganhou = 0;
                        break;
                    }
                    ganhou = 1;
                }
                if (ganhou)
                {
                    mostrar_ganhou(matriz);
                    break;
                }
                mostra_matriz_letra(matriz, matriz_aux, chances_letra);
                verificar_letra(letra, digitadas, matriz, &chances_letra, matriz_aux);
            }
            while(1);
            break;
        case 3:
            return 0;
        default:
            printf("\nOpcao invalida!\n");

        }
    }
    while(1);








}
