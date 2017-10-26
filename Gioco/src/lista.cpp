/*
 * lista.cpp
 *
 *  Created on: 18 ott 2017
 *      Author: turri
 */
#include "lista.hpp"

template <class T>
Lista<T> * insertCoda(T value, Lista<T> * head){
		Lista<T> * tmp;
		if(head == NULL){
			head=new Lista<T>;
			head->value = value;
			head->next = NULL;
		}else{
			tmp=head;
			while(tmp->next != NULL){
				tmp = tmp->next;
			}
			tmp->next=new Lista<T>;
			tmp->next->value = value;
			tmp->next->next = NULL;

		}
		return head;
}

template <class T>
T getElemetI(int i, Lista<T> * head){
	Lista<T> * tmp;
	int count=0;
	if(head != NULL){
		tmp = head;
		while(tmp->next != NULL && count < i){
			tmp = tmp->next;
			count++;
		}
		if(count == i){
			return tmp->value;
		}else{
			cout<<"Non ci sono abbastanza elementi (get)";

		}
	}else{
		cout<<"La lista è vuota";
	}
}

template <class T>
void setElemetI(int i, Lista<T> * head, T value){
	Lista<T> * tmp;
	int count=0;
	if(head != NULL){
		tmp = head;
		while(tmp->next != NULL && count < i){
			tmp = tmp->next;
			count++;
		}
		if(count == i){
			tmp->value = value;
		}else{
			cout<<"Non ci sono abbastanza elementi (set)";

		}
	}else{
		cout<<"La lista è vuota";
	}
}
template <class T>
void cancellaLista(Lista<T> * head){
	Lista<T> * tmp;
	while(head != NULL){
		tmp = head;
		head = head->next;
		delete(tmp);
	}
}

template <class T>
Lista<T> *  deleteI(int i, Lista<T> * head){
	Lista<T> * tmp;
	Lista<T> * prov;
	int count=0;
	if(head != NULL){
		if(head->next !=NULL){
			tmp = head;
			while(tmp->next->next != NULL && count < i-1){
				tmp = tmp->next;
				count++;
			}
			if(count == i-1 || count == 0){
				if(i == 0){
					head = tmp->next;
					delete(tmp) ;
				}else{
					prov = tmp->next;
					tmp->next = tmp->next->next;
					delete(prov);
				}
			}
		}else{
			if(count == i){
				delete (head) ;
				head = NULL;
			}
		}
	}
	return head;
}

