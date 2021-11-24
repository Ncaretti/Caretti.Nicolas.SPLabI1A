/*
 * Parser.c
 *
 *  Created on: Nov 23, 2021
 *      Author: Seether
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Parser.h"
#include "Peli.h"

int parser_pelis(FILE* pFile, LinkedList* this)
{
    int ret = 0;
    char id_peli[128];
    char titulo[128];
    char genero[128];
    char duracion[128];
    eMovie* pPeli;

    if(pFile != NULL && this != NULL)
    {
        fscanf(pFile,"%s\n",titulo);
         while(!feof(pFile))
        {
           if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n] \n",id_peli,titulo,genero,duracion) == 4)
           {
        	   pPeli = peli_newParametrosStr(id_peli,titulo,genero,duracion);
               ll_add(this,pPeli);
           }
           else
           {
        	   printf("Error\n");
               break;
           }
        }
        ret = 1;
    }

    return ret;
}
