#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

int main(){
    srand(time(NULL));
    int i;
    double vt[N]; //vt tiene la direccion de vt[0] entonces es un puntero

    for(i = 0;i<N; i++){
      *(vt + i)=1+rand()%100;
      printf("%f ", *(vt + i));
    }


    getchar();
    return 0;
}