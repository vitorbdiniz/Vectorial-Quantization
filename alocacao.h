#ifndef	_ALOCACAO_H
#define	_ALOCACAO_H	1

#include <malloc.h>
#include <stdlib.h>

double *aloca_vetor_double(int N);
int *aloca_vetor_int(int N);
double **aloca_matrizd(int N, int K);
void desaloca_matrizd(double **pt, int N);
int **aloca_matriz_int(int N, int K);
void desaloca_matriz_int(int **pt, int N);


int *aloca_vetor_int(int N){
/*******************************************************************
* Função que  retorna um ponteiro inteiro de dimensão N.           *
*******************************************************************/
int *x,i;

x = (int *)malloc(N*sizeof(int));  
if(!x){
  printf("\nFalha na alocação de memória\n");
  exit(1);
}

for(i=0;i<N;i++)
  x[i] = 0;

return (x);
}

double *aloca_vetor_double(int N){
/*******************************************************************
* Função que  retorna um ponteiro double de dimensão N.           *
*******************************************************************/
double *x;
int i;

x = (double *)malloc(N*sizeof(double));  
if(!x){
  printf("\nFalha na alocação de memória\n");
  exit(1);
}

for(i=0;i<N;i++)
  x[i] = 0.0;

return (x);
}

double **aloca_matrizd(int N, int K){
/*******************************************************************
* Função que  retorna um ponteiro double de dimensão N x K         *
*******************************************************************/
int i,j;
double **x;

x = (double **)malloc(N*sizeof(double*));  
if(!x){
  printf("\nFalha na alocação de memória\n");
  exit(1);
}

for(i=0;i<N;i++){
   x[i] =(double *)malloc(K * sizeof(double));
   if(!x[i]) {
     printf("\nFalha na alocação de memória\n");
     exit(1);
   }
}

for(i=0;i<N;i++)
  for(j=0;j<K;j++)
	 x[i][j] = 0.0;

return (x);
}

int **aloca_matriz_int(int N, int K){
/*******************************************************************
* Função que  retorna um ponteiro int de dimensão N x K            *
*******************************************************************/
int i,j;
int **x;

x = (int **)malloc(N*sizeof(int*));  
if(!x){
  printf("\nFalha na alocação de memória\n");
  exit(1);
}

for(i=0;i<N;i++){
   x[i] =(int *)malloc(K * sizeof(int));
   if(!x[i]) {
     printf("\nFalha na alocação de memória\n");
     exit(1);
   }
}

for(i=0;i<N;i++)
  for(j=0;j<K;j++)
	 x[i][j] = 0.0;

return (x);
}


void desaloca_matrizd(double **pt, int N){
/******************************************************************
* Desaloca o ponteiro da matriz double (dim N x K).               *
******************************************************************/

int i;

for(i=0;i<N;i++)
  free(pt[i]);
free(pt);

return;
}

void desaloca_matriz_int(int **pt, int N){
/******************************************************************
* Desaloca o ponteiro da matriz int (dim N x K).                  *
******************************************************************/

int i;

for(i=0;i<N;i++)
  free(pt[i]);
free(pt);

return;
}


#endif	/* alocacao.h  */
