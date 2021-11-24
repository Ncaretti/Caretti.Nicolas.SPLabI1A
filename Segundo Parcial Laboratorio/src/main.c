/*
 ============================================================================
 Name        : Segundo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkedList.h"
#include "Peli.h"
#include "Parser.h"
#include "Controller.h"

int main(void)
{

	setbuf(stdout, NULL);
	srand(time(NULL));
    int opcion = 0;
    int flagArchivo = 0;
    int flagDuracion = 0;
    int flagGenero = 0;
    int flagOrderGenero = 0;

    LinkedList* this = ll_newLinkedList();

    do{
        printf("Menu:\n"
       		 "1. Cargar archivo\n"
       		 "2. Imprimir lista\n"
       		 "3. Asignar tiempos\n"
       		 "4. Filtrar por genero\n"
       		 "5. Mostrar duraciones\n"
       		 "6. Guardar peliculas\n"
       		 "7. Salir\n");
        scanf("%d", &opcion);

        switch(opcion)
        {
        	case 1:
        		if(controller_elegirArchivo(this))
        		{
        			flagArchivo = 1;
        			flagDuracion = 0;
        		}
        		system("pause");
        	break;

        	case 2:
        		if(flagArchivo)
        		{
        			controller_ListMovie(this);
        		}
        		else
        		{
        			printf("Error, primero debe cargar un archivo.\n");
        		}
        		system("pause");
        	break;

        	case 3:
        		if(flagArchivo)
        		{
        			if(ll_map(this, peli_asignarTiempo))
        			{
        				printf("Se han asignado los tiempos con exito.\n");
        				flagDuracion = 1;
        			}
        			else
        			{
        				printf("Hubo un error al asignar los tiempos.\n");
        			}
        		}
        		else
        		{
        			printf("Error, primero debe cargar un archivo.\n");
        		}
        		system("pause");
        	break;

        	case 4:
        		if(flagArchivo)
        		{
        			if(flagDuracion || flagGenero)
        			{
						if(controller_filtrarPorGenero(this))
						{
							flagGenero = 1;
							printf("Archivo genero.csv generado con exito.\n"
									"Se recomienda volver a cargar el archivo movies.csv o genero.csv para evitar errores.\n");
						}
						else
						{
							printf("Hubo un error al generar el archivo.\n");
						}
        			}
        			else
        			{
        				printf("Error, primero debe cargar los tiempos.\n");
        			}
        		}
        		else
        		{
        			printf("Error, primero debe cargar un archivo.\n");
        		}
				system("pause");
        	break;

        	case 5:
        		if(flagArchivo)
        		{
        			if(flagDuracion)
        			{
        				controller_ordenPorGenero(this);
        				flagOrderGenero = 1;
        			}
        			else
        			{
        				printf("Error, primero debe cargar los tiempos.\n");
        			}
        		}
        		else
        		{
        			printf("Error, primero debe cargar un archivo.\n");
        		}
				system("pause");
        	break;

        	case 6:
        		if(flagArchivo)
        		{
        			if(flagOrderGenero)
        			{
        				if(controller_listaPorGenero(this))
        				{
        					printf("Archivo ordenado.csv generado con exito.\n"
        						   "Se recomienda volver a cargar el archivo movies.csv o ordenado.csv para evitar errores.\n");
        				}
        				else
        				{
        					printf("Hubo un error al generar el archivo.\n");
        				}
        			}
        			else
        			{
        				printf("Error, no puede generar el archivo sin antes haber generado la lista del punto 5.\n");
        			}
        		}
        		else
        		{
        			printf("Error, primero debe cargar un archivo.\n");
        		}
				system("pause");
			break;

        	case 7:
        		printf("Ha salido con exito, gracias por usar la aplicacion.\n");
        		system("pause");
        	break;

        	default:
        		printf("Error, ingrese una opcion valida.\n");
        		system("pause");
        	break;
        }
    }while(opcion != 7);
}
