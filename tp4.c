#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct Tarea
{
    int tareaID;
    char *descripcion;
    int duracion;
}Tarea;

void cargarTareas(Tarea **tareas, int num);
void mostrarTareas(Tarea ** tareas, int num);
int realizadas(Tarea **tareasRealizadas, Tarea **tareas, int numeroTareas);
void listaTareasRealizadas(Tarea **tereasRealizada, int num);
void listaTareasPendientes(Tarea **tareas, int num);
void buscarPorPalabra(Tarea **tareas, int num, char * clave);

int main(){
    srand(time(NULL));
    int numeroTareas;
    char * clave = (char*)malloc(sizeof(char)*10);
    Tarea **cantidadTarea;
    Tarea **tareasRealizadas;

    printf("Indique la cantidad de tareas a realizar: ");
    scanf("%d", &numeroTareas);

    cantidadTarea = (Tarea**)malloc(sizeof(Tarea*) * numeroTareas);
    tareasRealizadas = (Tarea**)malloc(sizeof(Tarea*) * numeroTareas);

    cargarTareas(cantidadTarea, numeroTareas);

    //---------- Busqueda por palabra ------------
    printf("Indique la palabra clave para buscar una tarea: ");
    gets(clave);
    buscarPorPalabra(cantidadTarea, numeroTareas, clave);
    free(clave);
    //---------- fin busqueda por palabra ------------

    for (int i = 0; i < numeroTareas; i++)
    {
        tareasRealizadas[i] = NULL;
    }

    // mostrarTareas(cantidadTarea, numeroTareas);
    int cantidadRealizadas = realizadas(tareasRealizadas, cantidadTarea, numeroTareas);
    listaTareasRealizadas(tareasRealizadas, cantidadRealizadas);
    listaTareasPendientes(cantidadTarea, numeroTareas);

    return 0;
}

void cargarTareas(Tarea **tareas, int num)
{
    char *buff = (char*)malloc(sizeof(char)*100);

    for (int i = 0; i < num; i++)
    {   
        tareas[i] = (Tarea*)malloc(sizeof(Tarea));

        tareas[i]->tareaID = i+1;

        printf("Escriba una breve descripcion de la %d tarea: ",i+1);
        fflush(stdin);
        gets(buff);
        tareas[i]->descripcion = (char *)malloc(strlen(buff) + 1);
        strcpy(tareas[i]->descripcion, buff);

        tareas[i]->duracion = 10 + rand() % 90;
    }

    free(buff);
}

void mostrarTareas(Tarea ** tareas, int num)
{	
    printf("========== Tarea numero %d ==========\n");
    printf("ID = %d\n", tareas[num]->tareaID);
    printf("Descripcion: ");
    puts(tareas[num]->descripcion);
    fflush(stdin);
    printf("Duracion: %d \n\n", tareas[num]->duracion);
}

int realizadas(Tarea **tareasRealizadas, Tarea **tareas, int numeroTareas)
{
    int realizada = 0, valor = 0;
    for (int i = 0; i < numeroTareas; i++)
    {
        fflush(stdin);
        mostrarTareas(tareas, i);
        printf("Realizo esta tarea%c 1-SI / 0-NO \n", 63);
        scanf("%d", &realizada); 

        if (realizada == 1)
        {
            tareasRealizadas[valor] = (Tarea*)malloc(sizeof(Tarea));
            tareasRealizadas[valor] = tareas[i];
            tareas[i] = NULL;
            valor++;
        } 
    }    
    return valor;
}

void listaTareasRealizadas(Tarea **tareasRealizada, int num)
{
    printf("\n---------------------------------------\n");
    printf("---------- TAREAS REALIZADAS ----------\n");
    printf("---------------------------------------\n\n");

    for (int i = 0; i < num; i++)
    {
        printf("========== Tarea numero %d ==========\n", i+1);
        printf("ID = %d\n", tareasRealizada[i]->tareaID);
        printf("Descripcion: ");
        puts(tareasRealizada[i]->descripcion);
        fflush(stdin);
        printf("Duracion: %d \n\n", tareasRealizada[i]->duracion);
    }
    
}

void listaTareasPendientes(Tarea **tareas, int num)
{
    printf("\n\n---------------------------------------\n");
    printf("---------- TAREAS PENDIENTES ----------\n");
    printf("---------------------------------------\n\n");
    for (int i = 0; i < num; i++)
    {   
        if (tareas[i] != NULL)
        {
            mostrarTareas(tareas, i);
        }
    } 
}

void buscarPorPalabra(Tarea **tareas, int num, char * clave)
{
    
    printf("---------- TAREAS BUSCADA POR PALABRA ----------\n");
    for (int i = 0; i < num; i++)
    {   
        int valor = strcmp(tareas[i]->descripcion, clave);
        if (valor);
        {
            mostrarTareas(tareas, i);
        }
    } 
}