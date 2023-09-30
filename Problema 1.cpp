//Nombre del archivo: Práctica 5. Clases de Almacenamiento c.
//Autor: Cesar Alejandro Velazquez Mercado
//Fecha de creación: 29 de septiembre de 2023
//Descripción: Este archivo me dice el numero de loteria y si gané
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int generarNumeroLoteria();
static int numeroGanador=0;
void iniciarCarrera();
int generarVelocidadAleatoria();

typedef struct {
    char nombre[10];
    int velocidad;
    float tiempo;
} Coche;

int main()
{
    int op;
    printf("Qué quieres hacer? 1)jugar a la loteria 2)Carrera de carros: ");
    scanf("%d",&op);
    switch (op)
    {
    case 1:
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
        break;
    case 2:
    {
        iniciarCarrera();
    }
        break;
    }
    return 0;
}

int generarNumeroLoteria()
{
    return(rand()%100 +1);
}

int generarVelocidadAleatoria()
{
    return rand() % 101 + 100;
}

void iniciarCarrera()
{
    Coche coches[3];
    srand(time(NULL));

    strcpy(coches[0].nombre, "Coche1");
    strcpy(coches[1].nombre, "Coche2");
    strcpy(coches[2].nombre, "Coche3");

    

    for (int i = 0; i < 3; i++) 
    {
        coches[i].velocidad = generarVelocidadAleatoria();
    }

    double distancia = 1000.0; 
    for (int i = 0; i < 3; i++) 
    {
        coches[i].tiempo = distancia / (coches[i].velocidad / 3.6); 
    }
    
    printf("Resultados de la carrera:\n");
    for (int i = 0; i < 3; i++) 
    {
        printf("%s - Velocidad: %d km/h - Tiempo: %.2lf segundos\n", coches[i].nombre, coches[i].velocidad, coches[i].tiempo);
    }

    int ganador = 0;
    for (int i = 1; i < 3; i++) 
    {
        if (coches[i].tiempo < coches[ganador].tiempo) 
        {
            ganador = i;
        }
    }

    printf("\nEl coche ganador es: %s\n", coches[ganador].nombre);
}

