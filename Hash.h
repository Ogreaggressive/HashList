#pragma once

#include "Lista8.h"
#include "ListaVaciaException.h"

template<class T>
class Hash
{
private:
	Lista8<T>* hash;
	int tam;
public:
	Hash(int tam);
	~Hash();
	void insertarEnHash(int(*funcGetNumero)(T*), T* dato);
	//void insertarEnHash(T* dato);
	void mostrar(void (*mostrarT)(T*));
	void eliminarEnHash(T* dato);
	//void buscarEnHash(T* dato);
	int funcionHash(int num);
};

template<typename T>
Hash<T>::Hash(int tam) 
{
	this->tam = tam;
	hash = new Lista8<T> [tam];
}

template<typename T>
Hash<T>::~Hash()
{

}

template<typename T>
void Hash<T>::insertarEnHash(int(*funcGetNumero)(T*),T* dato)
{
	int num;
	num=funcionHash((*funcGetNumero)(dato));
	//Aqui debes cambiar el indice 0 por el valor de getHashValue()
	hash[num].insertarContando(dato);
	//hash[0]->showList();
}

/*
template<typename T>
void Hash<T>::insertarEnHash(T*dato)
{
	int pos;
	pos = funcionHash();
	hash[pos].insertarContando(dato);
}*/


template<typename T>
void Hash<T>::eliminarEnHash(T* dato)
{

}

template<typename T>
int Hash<T>::funcionHash(int num)
{
	int t;
	t = num%tam;
	return t; 
}

template<typename T>
void Hash<T>::mostrar(void (*mostrarT)(T*))
{
	for (int i = 0; i < tam; i++)
	{
		Tripla<T>* aux = hash[i].getPrimer();
		while (aux != NULL)
		{
			(*mostrarT)(aux->getDato());
			aux = aux->getSiguiente();
		}
	}
}