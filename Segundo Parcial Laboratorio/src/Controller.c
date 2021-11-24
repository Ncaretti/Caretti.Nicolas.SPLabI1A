/*
 * Controller.c
 *
 *  Created on: Nov 24, 2021
 *      Author: Seether
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Peli.h"
#include "Parser.h"
#include "validaciones.h"

int controller_loadFromText(char* path , LinkedList* this)
{
	int ret = 0;

	FILE* pFile = fopen (path,"r");

	if(path != NULL && this != NULL)
	{
		if(pFile != NULL)
		{
			if(parser_pelis(pFile, this))
			{
				ret = 1;
			}
		}
		fclose(pFile);
	}

    return ret;
}

int controller_elegirArchivo(LinkedList* this)
{
	int ret = 0;
	char archivo[20];

	if(getString(archivo, 20, 3, "Ingrese el nombre del archivo: ", "Error, ingrese un nombre valido.\n"))
	{
		ll_clear(this);
	}

	if(controller_loadFromText(archivo, this))
	{
		printf("El archivo se ha cargado con exito.\n");
		ret = 1;
	}
	else
	{
		printf("Error, el archivo no existe o hubo un error en la carga.\n");
	}

	return ret;
}

int controller_ListMovie(LinkedList* this)
{
    int id_peli;
    char titulo[40];
    char genero [40];
    int duracion;
    int contPelis = 0;
    int ret = 0;
    int tam;
    int i;
    eMovie* pMovie;

    if(ll_isEmpty(this) == 0)
    {

    	tam = ll_len(this);

        printf("  ID    TITULO                         GENERO         DURACION\n");

        for(i=0; i<tam; i++)
        {
        	pMovie = (eMovie*) ll_get(this, i);

            if((peli_getId(pMovie, &id_peli) &&
                peli_getTitulo(pMovie, titulo) &&
                peli_getGenero(pMovie, genero) &&
                peli_getDuracion(pMovie, &duracion)))
            {
                printf("%4d    %-30s %-15s     %-8d\n", pMovie->id_peli, pMovie->titulo, pMovie->genero, pMovie->duracion);
                contPelis++;
            }
        }
        if(contPelis == tam)
        {
        	ret = 1;
        }
    }
    return ret;
}

int controller_saveAsText(char* path , LinkedList* this)
{
    int ret = 0;
    int tam;
    int i;
    int id_peli;
    char titulo[40];
    char genero[40];
    int duracion;
    FILE* pFile;
    eMovie* auxPeli = NULL;

    if(this != NULL && path != NULL)
    {
        pFile = fopen(path, "w");
        tam = ll_len(this);

        if(pFile != NULL)
        {
            fprintf(pFile, "id_peli,titulo,genero,duracion\n");
            for(i=0; i<tam; i++)
            {
            	auxPeli = (eMovie*) ll_get(this, i);

                peli_getId(auxPeli, &id_peli);
                peli_getTitulo(auxPeli, titulo);
                peli_getGenero(auxPeli, genero);
                peli_getDuracion(auxPeli, &duracion);

                fprintf(pFile, "%d,%s,%s,%d\n", id_peli, titulo, genero, duracion);
            }
        }
        fclose(pFile);
        ret = 1;
    }
    return ret;
}

int controller_filtrarPorGenero(LinkedList* this)
{
	int ret = 0;
	int opcion;
	LinkedList* auxGenero = ll_newLinkedList();

	printf("LISTA GENEROS:\n"
		   "1-Adventure\n"
		   "2-Drama\n"
		   "3-Comedy\n"
		   "4-Romance\n"
	       "5-Documentary\n"
		   "6-Horror\n"
		   "7-Animation\n"
		   "8-Action\n"
		   "9-Musical\n"
		   "10-Thriller\n"
		   "11-Western\n");
	printf("Ingrese la ID del genero: ");
	validarEntero(&opcion, 1, 12);

	switch(opcion)
	{
		case 1:
			auxGenero = ll_filter(this, peli_filtroAdventure);
		break;

		case 2:
			auxGenero = ll_filter(this, peli_filtroDrama);
		break;

		case 3:
			auxGenero = ll_filter(this, peli_filtroComedy);
		break;

		case 4:
			auxGenero = ll_filter(this, peli_filtroRomance);
		break;

		case 5:
			auxGenero = ll_filter(this, peli_filtroDocumentary);
		break;

		case 6:
			auxGenero = ll_filter(this, peli_filtroHorror);
		break;

		case 7:
			auxGenero = ll_filter(this, peli_filtroAnimation);
		break;

		case 8:
			auxGenero = ll_filter(this, peli_filtroAction);
		break;

		case 9:
			auxGenero = ll_filter(this, peli_filtroMusical);
		break;

		case 10:
			auxGenero = ll_filter(this, peli_filtroThriller);
		break;

		case 11:
			auxGenero = ll_filter(this, peli_filtroWestern);
		break;
	}

	if(controller_saveAsText("genero.csv", auxGenero))
	{
		ret = 1;
	}

	return ret;
}

int controller_ordenPorGenero(LinkedList* this)
{
	int ret = 0;

	if(this != NULL)
	{
		if(ll_sort(this, peli_ordenarPorGenero, 0) == 0)
		{
			controller_ListMovie(this);
		}
	}
	return ret;
}

int controller_listaPorGenero(LinkedList* this)
{
	int ret = 0;

	if(controller_saveAsText("ordenado.csv", this))
	{
		ret = 1;
	}

	return ret;
}
