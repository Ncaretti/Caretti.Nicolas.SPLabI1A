/*
 * Controller.h
 *
 *  Created on: Nov 24, 2021
 *      Author: Seether
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controller_loadFromText(char* path , LinkedList* this);
int controller_elegirArchivo(LinkedList* this);
int controller_ListMovie(LinkedList* this);
int controller_saveAsText(char* path , LinkedList* this);
int controller_filtrarPorGenero(LinkedList* this);
int controller_ordenPorGenero(LinkedList* this);
int controller_listaPorGenero(LinkedList* this);

#endif /* CONTROLLER_H_ */
