#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct compu {
    int velocidad; // Velocidad de procesamiento en GHz (valor entre 1 y 3)
    int anio; // Año de fabricación (valor entre 2015 y 2024)
    int cantidad_nucleos; // Cantidad de núcleos (valor entre 1 y 8)
    char *tipo_cpu; // Tipo de procesador (apuntador a cadena de caracteres)
};
typedef struct compu compu;

void listarPCs(compu pcs[], int cantidad);
void mostrarMasVieja(struct compu pcs[], int cantidad);
void mostrarMasVeloz(struct compu pcs[], int cantidad);

int main(){
    srand(time(NULL));
    int i,cantidad=5;
    compu computadora[4];
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    
    for (i=0;i<5;i++){
        computadora[i].velocidad=1+rand()%3;
        computadora[i].anio=2015+rand()%(2024-2015+1);
        computadora[i].cantidad_nucleos=1+rand()%8;
        computadora[i].tipo_cpu=&tipos[rand()%6][10];
    }

    listarPCs(computadora,cantidad);
    mostrarMasVieja(computadora,cantidad);
    mostrarMasVeloz(computadora,cantidad);

    getchar();
    return 0;
}

void listarPCs(compu pcs[], int cantidad){
    int i;
    cantidad=5;
    for (i=0;i<cantidad;i++){
        printf("Computadora %d:",i+1);
        printf("\nVelocidad de procesamiento: %d GHz",pcs[i].velocidad);
        printf("\nAnio de fabricacion: %d",pcs[i].anio);
        printf("\nCantidad de nucleos: %d",pcs[i].cantidad_nucleos);
        printf("\nTipo de procesador:");
        puts(pcs[i].tipo_cpu);
        printf("\n");
    }    
}

void mostrarMasVieja(struct compu pcs[], int cantidad){
    int i,pc,vieja=3000;
    cantidad=5;
    for (i=0;i<cantidad;i++){
        if (pcs[i].anio<vieja){
            vieja=pcs[i].anio;
            pc=i;
        }
    }
    printf("Computadora mas vieja:");
    printf("\nVelocidad de procesamiento: %d GHz",pcs[pc].velocidad);
    printf("\nAnio de fabricacion: %d",pcs[pc].anio);
    printf("\nCantidad de nucleos: %d",pcs[pc].cantidad_nucleos);
    printf("\nTipo de procesador:");
    puts(pcs[pc].tipo_cpu);
    printf("\n");
}

void mostrarMasVeloz(struct compu pcs[], int cantidad){
    int i,pc,veloz=0;
    cantidad=5;
    for (i=0;i<cantidad;i++){
        if (pcs[i].velocidad>veloz){
            veloz=pcs[i].velocidad;
            pc=i;
        }
    }
    printf("Computadora mas rapida:");
    printf("\nVelocidad de procesamiento: %d GHz",pcs[pc].velocidad);
    printf("\nAnio de fabricacion: %d",pcs[pc].anio);
    printf("\nCantidad de nucleos: %d",pcs[pc].cantidad_nucleos);
    printf("\nTipo de procesador:");
    puts(pcs[pc].tipo_cpu);
    printf("\n");
}
