#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct compu {
    int velocidad; // Velocidad de procesamiento en GHz (valor entre 1 y 3)
    int anio; // Año de fabricación (valor entre 2015 y 2024)
    int cantidad_nucleos; // Cantidad de núcleos (valor entre 1 y 8)
    char *tipo_cpu; // Tipo de procesador (apuntador a cadena de caracteres)
};
typedef struct compu compu;

int main(){
    srand(time(NULL));
    int i;
    compu computadora[4];
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    
    for (i=0;i<5;i++){
        computadora[i].velocidad=1+rand()%3;
        computadora[i].anio=2015+rand()%(2024-2015+1);
        computadora[i].cantidad_nucleos=1+rand()%8;
        computadora[i].tipo_cpu=&tipos[rand()%6];
    }

    getchar();
    return 0;
}