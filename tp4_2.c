#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tarea
{
    int tareaID;
    char *descripcion;
    int duracion;
}typedef Tarea;

int main(){

    char *buff;
    int tareas;
    Tarea **cantidadTareas;
    printf("Indique la cantidad de tareas a realizar: ");
    scanf("%d", &tareas);

    cantidadTareas = (Tarea*)malloc(sizeof(Tarea) * tareas);

    for (int i = 0; i < tareas; i++)
    {
        cantidadTareas[i]->tareaID = i + 1;
        printf("Indique la tarea que realizo: ");
        gets(buff);
        cantidadTareas[i]->descripcion = (Tarea*)malloc(sizeof(Tarea*)*(sizeof(buff)+1));
        strcpy(cantidadTareas[i]->descripcion, buff);
        printf("Indique el tiempo que demoro en realizar la tarea: ");
        scanf("%d", cantidadTareas[i]->duracion);
    }

    for (int j = 0; j < tareas; j++)
    {
        printf("Tarea: ");
        puts(cantidadTareas[j]->descripcion);
        printf("Tiempo utilizado: %d", cantidadTareas[j]->duracion);
    }
        
    for (int k = 0; k < tareas; k++)
    {
        free(buff[k]);
        free(cantidadTareas[k]);
    }
    
    return 0;
}