/*
 *	Predmet : Formální jazyky a překladače
 *	Projekt : Implementace překladače imperativního jazyka IFJ19
 *	Súbor	: symstack.h
 *				-hlavickovy subor stacku vytvoreneho na pracu so symbolmi v PSA
 *	Tím		: číslo 10 / varianta II
 *	Autori	: Dominik Boboš (xbobos00)
 *			  Peter Hudeček (xhudec34)
 *			  Timotej Kováčik (xkovac49)
 *			  Dávid Oravec (xorave05)
 *
 */

#ifndef _SYMSTACK_H
#define _SYMSTACK_H


#include <stdbool.h>
#include "expr.h" //TODO
#include "symtable.h"

typedef struct s_item
{
    prec_table_sym symbol; //este nieje
	DataType data_type;
	struct s_item *next;
} s_item;

typedef struct
{
	s_item *top;

} sstack;
//Init zasobnika
void symbol_init(sstack* stack);

//Pushne symbol na vrchol stacku
bool symbol_push(sstack* stack, prec_table_sym symbol, DataType type);

//Uvolni prvok z vrchola zasobnika
bool symbol_pop(sstack* stack);

//Uvolni "times" znakov z vvrchola zasobnika
void symbol_pop_times(sstack* stack, int times);

//Vrati prvy najdeny terminal na vrchole stacku
s_item* symbol_top_term(sstack * stack);

//Vrati hodnotu vrcholu zasobnika
s_item* symbol_top(sstack* stack);

//Uvolni zasobnik
void symbol_free(sstack* stack);

#endif //_SYMSTACK_H