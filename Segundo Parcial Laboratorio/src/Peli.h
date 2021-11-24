/*
 * Peli.h
 *
 *  Created on: Nov 24, 2021
 *      Author: Seether
 */

#ifndef PELI_H_
#define PELI_H_

typedef struct
{
	int id_peli;
	char titulo[40];
	char genero[40];
	int duracion;
}eMovie;

eMovie* peli_new();
eMovie* peli_newParametrosStr(char* id_peliStr,char* tituloStr,char* generoStr, char* duracionStr);

int peli_setId(eMovie* this,int id_peli);
int peli_setTitulo(eMovie* this,char* titulo);
int peli_setGenero(eMovie* this,char* genero);
int peli_setDuracion(eMovie* this,int duracion);

int peli_getId(eMovie* this,int* id_peli);
int peli_getTitulo(eMovie* this,char* titulo);
int peli_getGenero(eMovie* this,char* genero);
int peli_getDuracion(eMovie* this,int* duracion);

void* peli_asignarTiempo(void* peli);

int peli_filtroComedy(void* peli);
int peli_filtroAdventure(void* peli);
int peli_filtroDrama(void* peli);
int peli_filtroRomance(void* peli);
int peli_filtroDocumentary(void* peli);
int peli_filtroHorror(void* peli);
int peli_filtroAnimation(void* peli);
int peli_filtroAction(void* peli);
int peli_filtroMusical(void* peli);
int peli_filtroThriller(void* peli);
int peli_filtroWestern(void* peli);

int peli_ordenarPorGenero(void* peliUno, void* peliDos);


#endif /* PELI_H_ */
