#include<stdio.h>
#include<stdlib.h>
#include <math.h>

int main()
{
/*DECLARAÇÕES NECESSÁRIAS*/
int a, b, i, j, k = 0, l, m, n,q=0 ,r=0, max_cinza;
float d, MSE;
FILE *Im = NULL;
char arq[60], p[2];

/*INDICAÇÃO DA IMAGEM QUE SERÁ LIDA*/
    while(Im == NULL)
    {
        printf("\nEscreva o nome de um arquivo valido\n");
        scanf("%s", &arq);
        Im = fopen(arq,"r");
    }

/*LEITURA DO CABEÇALHO DA IMAGEM*/
    fscanf(Im,"%s %d %d %d",&p,&m,&n,&max_cinza);

/*DECLARAÇÕES DAS MATRIZES NECESSÁRIAS*/
    int T[m][n], R[4][4];
    float M[4096][16], Dic [32][16];

/*LEITURA DE ARQUIVO E ARMAZENAMENTO VALORES DE PIXELS EM MATRIZ*/
    for (i=0; i<m; i++)
        for(j=0; j<n; j++)
            fscanf(Im,"%d",&T[i][j]);
    fclose(Im);
Im = NULL;

/*INDICAÇÃO DO DICIONÁRIO QUE SERÁ LIDO*/
    while(Im == NULL)
    {
        printf("\nEscreva o nome do arquivo dicionario (.dic)\n"); //airplane_boat_gull_goldhill_32.dic
        scanf("%s", &arq);
        Im = fopen(arq,"r");
    }

/*LEITURA DOS VALORES DO DICIONÁRIO*/
    for (i = 0; i < 32; i++)
        for (j = 0; j < 16; j++)
            fscanf(Im, "%f", &Dic[i][j]);
fclose(Im);
Im = NULL;

/* DIVIDIR MATRIZ T[256][256] E TRANSEFRIR PARA MATRIZ M[4096][16]*/
    for (a = 0; a < m/4; a++)
        for (b = 0; b < n/4; b++)
        {
            for (i = 4*a; i < (4*a)+4; i++)
            {
                l=0;
                for(j = 4*b; j < (4*b)+4; j++)
                {
                    R[k][l] = T [i][j];
                    l++;
                }
                k++;
            }

            for (k = 0; k < 4; k++)
                for (l = 0; l < 4; l++)
                {
                    M[q][r] = R[k][l];
                    r++;
                    if (r == 16)
                    {
                        r=0;
                        q++;
                    }
                }
                k=0;
        }

/*ATRIBUIÇÃO DOS VALORES DO DICIONÁRIO NA IMAGEM*/
    for (k = 0; k < 4096; k++)
    {
        int r;
        b = 40000;
        for (i = 0; i < 32; i++)
        {
            d = 0;
            for(j = 0; j < 16; j++)
            {
                d = d + pow((M [k][j] - Dic[i][j]),2);
                MSE = d/16;

                if (MSE < b)
                {
                    r = i;
                    b = MSE;
                }
            }
        }
        for (j = 0; j < 16; j++)
            M [k][j] = Dic [r][j];

    }
/*ARREDONDA OS VALORES DA MATRIZ PARA UM NÚMERO INTEIRO*/

    for(i = 0; i < 4096; i++)
        for (j = 0; j < 16;j++)
            M[i][j] = round (M[i][j]);


/*INDICAÇÃO DO ARQUIVO FINAL (.dat)*/
    while(Im == NULL)
    {
        printf("\nEscreva o nome do arquivo de destino\n(NOME_DO_ARQUIVO.dat)\n");
        scanf("%s", &arq);
        Im = fopen(arq,"w");
    }

/* ESCREVE A MATRIZ NO ARQUIVO*/
    for(i = 0; i < 4096; i++)
        for (j = 0; j < 16;j++)
            fprintf(Im, "%.0f ", M[i][j]);

fclose(Im);
system("pause");
return 0;
}
