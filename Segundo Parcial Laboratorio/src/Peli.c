/*
 * Peli.c
 *
 *  Created on: Nov 24, 2021
 *      Author: Seether
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Peli.h"

eMovie* peli_new()
{
	eMovie* nuevaPeli;

	nuevaPeli = (eMovie*) malloc(sizeof(eMovie));

	if(nuevaPeli != NULL)
	{
		nuevaPeli->id_peli = 0;
		strcpy(nuevaPeli->titulo, "NN");
		strcpy(nuevaPeli->genero, "NN");
		nuevaPeli->duracion = 0;
	}

	return nuevaPeli;
}

eMovie* peli_newParametrosStr(char* id_peliStr,char* tituloStr,char* generoStr, char* duracionStr)
{
	eMovie* nuevaPeliStr = peli_new();

	if(nuevaPeliStr != NULL)
	{
		if(!(peli_setId(nuevaPeliStr, atoi(id_peliStr))
			&& peli_setTitulo(nuevaPeliStr, tituloStr)
			&& peli_setGenero(nuevaPeliStr, generoStr)
			&& peli_setDuracion(nuevaPeliStr, atoi(duracionStr))))
		{
			printf("Hubo un error.\n");
			free(nuevaPeliStr);
			nuevaPeliStr = NULL;
		}
	}
	return nuevaPeliStr;
}

//--------------SETTERS------------//

int peli_setId(eMovie* this,int id_peli)
{
	int ret = 0;

	if(this != NULL)
	{
		this->id_peli = id_peli;
		ret = 1;
	}

	return ret;
}

int peli_setTitulo(eMovie* this,char* titulo)
{
	int ret = 0;

	if(this != NULL)
	{
		strcpy(this->titulo, titulo);
		ret = 1;
	}

	return ret;
}

int peli_setGenero(eMovie* this,char* genero)
{
	int ret = 0;

	if(this != NULL)
	{
		strcpy(this->genero, genero);
		ret = 1;
	}

	return ret;
}

int peli_setDuracion(eMovie* this,int duracion)
{
	int ret = 0;

	if(this != NULL)
	{
		this->duracion = duracion;
		ret = 1;
	}

	return ret;
}

//----------GETTERS----------//

int peli_getId(eMovie* this,int* id_peli)
{
	int ret = 0;

	if(this != NULL)
	{
		*id_peli = this->id_peli;
		ret = 1;
	}

	return ret;
}

int peli_getTitulo(eMovie* this,char* titulo)
{
	int ret = 0;

	if(this != NULL)
	{
		strcpy(titulo, this->titulo);
		ret = 1;
	}

	return ret;
}

int peli_getGenero(eMovie* this,char* genero)
{
	int ret = 0;

	if(this != NULL)
	{
		strcpy(genero, this->genero);
		ret = 1;
	}

	return ret;
}

int peli_getDuracion(eMovie* this,int* duracion)
{
	int ret = 0;

	if(this != NULL)
	{
		*duracion = this->duracion;
		ret = 1;
	}

	return ret;
}

//-------------ASIGNAR TIEMPOS-----------//

void* peli_asignarTiempo(void* peli)
{
	int min = 100;
	int max = 240;
	eMovie* auxPeli = NULL;

	if(peli != NULL)
	{
		auxPeli = (eMovie*) peli;

		auxPeli->duracion = rand() % (max - min + 1) + min;
	}

	return auxPeli;
}

//------------FILTROS-------------//

int peli_filtroComedy(void* peli)
{
	int ret = 0;

	if(!strcmp(((eMovie*) peli)->genero, "Comedy"))
	{
		ret = 1;
	}

	return ret;
}

int peli_filtroAdventure(void* peli)
{
	int ret = 0;

	if(!strcmp(((eMovie*) peli)->genero, "Adventure"))
	{
		ret = 1;
	}

	return ret;
}

int peli_filtroDrama(void* peli)
{
	int ret = 0;

	if(!strcmp(((eMovie*) peli)->genero, "Drama"))
	{
		ret = 1;
	}

	return ret;
}

int peli_filtroRomance(void* peli)
{
	int ret = 0;

	if(!strcmp(((eMovie*) peli)->genero, "Romance"))
	{
		ret = 1;
	}

	return ret;
}

int peli_filtroDocumentary(void* peli)
{
	int ret = 0;

	if(!strcmp(((eMovie*) peli)->genero, "Documentary"))
	{
		ret = 1;
	}

	return ret;
}

int peli_filtroHorror(void* peli)
{
	int ret = 0;

	if(!strcmp(((eMovie*) peli)->genero, "Horror"))
	{
		ret = 1;
	}

	return ret;
}

int peli_filtroAnimation(void* peli)
{
	int ret = 0;

	if(!strcmp(((eMovie*) peli)->genero, "Animation"))
	{
		ret = 1;
	}

	return ret;
}

int peli_filtroAction(void* peli)
{
	int ret = 0;

	if(!strcmp(((eMovie*) peli)->genero, "Action"))
	{
		ret = 1;
	}

	return ret;
}

int peli_filtroMusical(void* peli)
{
	int ret = 0;

	if(!strcmp(((eMovie*) peli)->genero, "Musical"))
	{
		ret = 1;
	}

	return ret;
}

int peli_filtroThriller(void* peli)
{
	int ret = 0;

	if(!strcmp(((eMovie*) peli)->genero, "Thriller"))
	{
		ret = 1;
	}

	return ret;
}

int peli_filtroWestern(void* peli)
{
	int ret = 0;

	if(!strcmp(((eMovie*) peli)->genero, "Western"))
	{
		ret = 1;
	}

	return ret;
}

//-------------ORDENAMIENTO-------------//

int peli_ordenarPorGenero(void* peliUno, void* peliDos)
{
	int ret = -2;
	eMovie* auxPeliUno = NULL;
	eMovie* auxPeliDos = NULL;

	if(peliUno != NULL && peliDos != NULL)
	{
		auxPeliUno = (eMovie*) peliUno;
		auxPeliDos = (eMovie*) peliDos;

		if(strcmp(auxPeliUno->genero, auxPeliDos->genero) > 0)
		{
			ret = -1;
		}
		else if(strcmp(auxPeliUno->genero, auxPeliDos->genero) < 0)
		{
			ret = 1;
		}
		else if(strcmp(auxPeliUno->genero, auxPeliDos->genero) == 0)
		{
			if(auxPeliUno->duracion > auxPeliDos->duracion)
			{
				ret = 0;
			}
		}
	}

	return ret;
}
