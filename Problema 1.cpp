//Nombre del archivo: Práctica 5. Clases de Almacenamiento c.
//Autor: Cesar Alejandro Velazquez Mercado
//Fecha de creación: 29 de septiembre de 2023
//Descripción: Este archivo me dice el numero de loteria y si gané
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generarNumeroLoteria();
static int numeroGanador=0;

int main()
{
    srand(time(NULL));
    int boleto;
    boleto=generarNumeroLoteria();
    printf("tu boleto: %d\n\n", boleto);
    if (numeroGanador == 0) 
    {
        numeroGanador = generarNumeroLoteria();
    }
    printf("boleto ganador: %d\n\n", numeroGanador);
    if(boleto==numeroGanador)
    {
        printf("¡Felicidades, ganaste la lotería!\n");
    }
    else
    {
        printf("Lo siento, no ganaste esta vez.\n");
    }
}

int generarNumeroLoteria()
{
    return(rand()%100 +1);
}
