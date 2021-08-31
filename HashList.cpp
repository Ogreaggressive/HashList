// HashList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

#include <io.h>
#include <fcntl.h>

#include "Hash.h"
#include "Cliente.h"


void leerDeArchivo(Hash<Cliente>& clientes)
{
	ifstream archi;
	int numerosArchivo;
	int cont = 0;
	string palabrasArchivo;

	//usar animales para 3000+ 
	//usar animalesCorto para 100
	// 
	//archi.open("cien_años_de_soledad.txt");
	archi.open("prueba.txt");

	if (!archi)
		cout << "No se puede abrir";
	else
		while (!archi.eof() && archi >> palabrasArchivo)
		{
			clientes.insertarEnHash(Cliente::getTot,new Cliente(cont,palabrasArchivo));
			cont = cont+1;
		}
	archi.close();
}

/*
int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
    Hash<Cliente> clientes(278261);

   /*Cliente* c1 = new Cliente(1, "Azul");
    Cliente* c2 = new Cliente(2, "Verde");

    clientes.insertarEnHash(Cliente::getTot,c1);
    clientes.insertarEnHash(Cliente::getTot, c2);
    clientes.insertarEnHash(Cliente::getTot, c1);*/
	//leerDeArchivo(clientes);
    //clientes.mostrar(Cliente::mostrar);

	//cout << "años" << endl;


    return 0;
}*/

int wmain(int argc, wchar_t* argv[])
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	std::wcout << L"Testing unicode -- English -- ???????? -- Español." << std::endl;
}