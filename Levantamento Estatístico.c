#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#define PI 3.1415926535897932
int main ()
{
        setlocale(LC_ALL, "Portuguese");
/*DECLARAÇÕES NECESSÁRIAS*/
int a = 0, b = 0,i, j,k,l, m,n,t,v,w,z, max;
FILE *Im = NULL;
char arq[60], p[3];

/*INDICAÇÃO DA IMAGEM QUE SERÁ LIDA*/
    while(Im == NULL)
    {
        printf("Escreva o nome do arquivo da imagem (.pgm)\n");
        scanf("%s", &arq);
        Im = fopen(arq,"r");
    }

/*LEITURA DO CABEÇALHO DA IMAGEM*/
    fscanf(Im,"%s %d %d %d",&p,&m,&n,&max);

/*DECLARAÇÃO DAS MATRIZES*/
    double X[m][n], ABSA[64], A[64], Y[1024][64], S[64],DP[64],c, C;
    int M[m][n];

/*MATRIZ ARMAZENA OS VALORES DO ARQUIVO*/
    for (i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            fscanf(Im,"%d",&M[i][j]);
fclose(Im);
Im = NULL;
    for (a = 0; a < m; a++)
        for (b = 0; b < n; b++)
            X[a][b] = 0;

/*DCT*/
    for (k = 0; k < m/8; k++)
        for (l = 0; l < n/8; l++)
            for (a = k*8; a < k*8+8; a++)
                for (b = l*8; b < l*8+8; b++)
                {
                    z = a%8;
                    w = b%8;
                        if (z == 0) { C = 1.0/sqrt(2); }
                            else { C = 1;}
                        if (w == 0){ c = 1.0/sqrt(2); }
                            else{c = 1;}

                    for (i = k*8; i < k*8+8; i++)
                        for (j = l*8; j < l*8+8; j++)
                        {
                            t = i%8;
                            v = j%8;
                            X[a][b] = X[a][b] + (C*c*0.25*(cos((2*t+1)*z*PI/(16.0))* cos((2*v+1)*w*PI/(16.0))* M[i][j]));
                        }
                }

/*LEITURA EM ZIG-ZAG*/
i = 0;
for (a = 0; a < 32; a++)
    for (b = 0; b < 32; b++)
    {
        Y [i][0] = X[a*8][b*8];
        Y [i][1] = X[a*8][b*8+1];
        Y [i][2] = X[a*8+1][b*8];
        Y [i][3] = X[a*8+2][b*8];
        Y [i][4] = X[a*8+1][b*8+1];
        Y [i][5] = X[a*8][b*8+2];
        Y [i][6] = X[a*8][b*8+3];
        Y [i][7] = X[a*8+1][b*8+2];
        Y [i][8] = X[a*8+2][b*8+1];
        Y [i][9] = X[a*8+3][b*8];
        Y [i][10] = X[a*8+4][b*8];
        Y [i][11] = X[a*8+3][b*8+1];
        Y [i][12] = X[a*8+2][b*8+2];
        Y [i][13] = X[a*8+1][b*8+3];
        Y [i][14] = X[a*8][b*8+4];
        Y [i][15] = X[a*8][b*8+5];
        Y [i][16] = X[a*8+1][b*8+4];
        Y [i][17] = X[a*8+2][b*8+3];
        Y [i][18] = X[a*8+3][b*8+2];
        Y [i][19] = X[a*8+4][b*8+1];
        Y [i][20] = X[a*8+5][b*8];
        Y [i][21] = X[a*8+6][b*8];
        Y [i][22] = X[a*8+5][b*8+1];
        Y [i][23] = X[a*8+4][b*8+2];
        Y [i][24] = X[a*8+3][b*8+3];
        Y [i][25] = X[a*8+2][b*8+4];
        Y [i][26] = X[a*8+1][b*8+5];
        Y [i][27] = X[a*8][b*8+6];
        Y [i][28] = X[a*8][b*8+7];
        Y [i][29] = X[a*8+1][b*8+6];
        Y [i][30] = X[a*8+2][b*8+5];
        Y [i][31] = X[a*8+3][b*8+4];
        Y [i][32] = X[a*8+4][b*8+3];
        Y [i][33] = X[a*8+5][b*8+2];
        Y [i][34] = X[a*8+6][b*8+1];
        Y [i][35] = X[a*8+7][b*8];
        Y [i][36] = X[a*8+7][b*8+1];
        Y [i][37] = X[a*8+6][b*8+2];
        Y [i][38] = X[a*8+5][b*8+3];
        Y [i][39] = X[a*8+4][b*8+4];
        Y [i][40] = X[a*8+3][b*8+5];
        Y [i][41] = X[a*8+2][b*8+6];
        Y [i][42] = X[a*8+1][b*8+7];
        Y [i][43] = X[a*8+2][b*8+7];
        Y [i][44] = X[a*8+3][b*8+6];
        Y [i][45] = X[a*8+4][b*8+5];
        Y [i][46] = X[a*8+5][b*8+4];
        Y [i][47] = X[a*8+6][b*8+3];
        Y [i][48] = X[a*8+7][b*8+2];
        Y [i][49] = X[a*8+7][b*8+3];
        Y [i][50] = X[a*8+6][b*8+4];
        Y [i][51] = X[a*8+5][b*8+5];
        Y [i][52] = X[a*8+4][b*8+6];
        Y [i][53] = X[a*8+3][b*8+7];
        Y [i][54] = X[a*8+4][b*8+7];
        Y [i][55] = X[a*8+5][b*8+6];
        Y [i][56] = X[a*8+6][b*8+5];
        Y [i][57] = X[a*8+7][b*8+4];
        Y [i][58] = X[a*8+7][b*8+5];
        Y [i][59] = X[a*8+6][b*8+6];
        Y [i][60] = X[a*8+5][b*8+7];
        Y [i][61] = X[a*8+6][b*8+7];
        Y [i][62] = X[a*8+7][b*8+6];
        Y [i][63] = X[a*8+7][b*8+7];

        i++;
    }

/*CÁLCULO DA MÉDIA*/
    for(j = 0; j < 64 ; j++)
            A[j] = 0;
    for(j = 0; j < 64 ; j++)
        for(i = 0; i < (m*n/64) ; i++)
            A[j] = A[j] + (Y[i][j]/(m*n/64));

/*CÁLCULO DA MÉDIA ABSOLUTA*/
    for(j = 0; j < 64 ; j++)
            ABSA[j] = 0;
    for(j = 0; j < 64 ; j++)
        for(i = 0; i < (m*n/64) ; i++)
        {
            if (Y[i][j] < 0)
                Y[i][j] = -1*Y[i][j];
            ABSA[j] = ABSA[j] + (Y[i][j]/(m*n/64));
        }

/*CÁLCULO DA VARIÂNCIA*/
    for(j = 0; j < 64 ; j++)
            S[j] = 0;
    for(j = 0; j < 64 ; j++)
        for(i = 0; i < (m*n/64) ; i++)
            S[j] = S[j] + (pow((Y[i][j]-A[j]),2)/(m*n/64));

/*CÁLCULO DO DESVIO PADRÃO*/
    for(j = 0; j < 64; j++)
        DP[j] = sqrt(S[j]);

/*INDICAÇÃO DO ARQUIVO QUE SERÁ SALVO*/
    while(Im == NULL)
    {
        printf("\nEscreva o nome do arquivo\n");
        scanf("%s", &arq);
        Im = fopen(arq,"w");
    }

    fprintf(Im,"MÉDIA\n");
        for(j = 0 ;j < 64; j++)
            fprintf(Im,"%.2f\n", A[j]);

    fprintf(Im,"\n\nMÉDIA ABSOLUTA\n");
        for(j = 0; j < 64; j++)
            fprintf(Im,"%.2f\n", ABSA[j]);

    fprintf(Im,"\n\nVARIÂNCIA\n");
        for(j = 0 ;j < 64; j++)
            fprintf(Im,"%.2f\n", S[j]);

    fprintf(Im,"\n\nDESVIO PADRÃO\n");
        for(j = 0 ;j < 64; j++)
            fprintf(Im,"%.2f\n", DP[j]);
fclose(Im);
system("pause");
return 0;
}
