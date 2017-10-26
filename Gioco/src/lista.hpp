/*
 * lista.hpp
 *
 *  Created on: 21 ott 2017
 *      Author: turri
 */

#ifndef LISTA_HPP_
#define LISTA_HPP_


#include <iostream>
using namespace std;

template <class T>
struct Lista{
		T value;
		Lista<T> * next;
};

template <class T> Lista<T> * insertCoda(T value, Lista<T> * head);
template <class T> T getElemetI(int i, Lista<T> * head);
template <class T> void cancellaLista(Lista<T> * head);
template <class T> void setElemetI(int i, Lista<T> * head, T value);
template <class T> Lista<T> *  deleteI(int i, Lista<T> * head);


#endif /* LISTA_HPP_ */
