#include<iostream>
#include "Arbol.h"
#include "Validacion.h"
//#define level 0
using namespace std;
  
// Driver function
int menu();
int main(int argc, char** argv)
{
	Validacion v;
	class Node *temp = NULL;
	int opc, dim, level=0;
	char val[20], str[20];
	do{
		system("cls");
		opc=menu();
		switch(opc)
		{
			case 1:{
				char* mensaje = (char*) "\nIngrese un valor: ";
				strcpy(val,v.ingresarDatoC(mensaje));
				insert_node(&temp, val);	
				cout<<endl;
				break;
			}
			case 2:{
				char* mensaje = (char*) "\nIngrese el valor que desea buscar: ";
				strcpy(val,v.ingresarDatoC(mensaje));
        		searchTST(temp, val) ? cout << "Found\n"
                                      : cout << "Not Found\n";
                break;
			}
			case 3:{
				char* mensaje = (char*) "\nIngrese el valor que desea buscar: ";
				strcpy(val,v.ingresarDatoC(mensaje));
				level = 0;
				delete_node(temp,val, level, 5);
				level = 0;		            
				break;
			}
			case 4:{
				cout<<"\nPalabras dentro del arbol"<<endl;
				level = 0;
				display(temp, str, level);
				level = 0;
				//cout<<str<<endl;
				//traverseTST(temp);			            
				break;
			}
			case 0:{
				cout<<"\nAdios, Gracias por usar el programa :D "<<endl;
				break;
			}
			default:{
				cout<<"\nError. Opcion incorrecta"<<endl;
				break;
			}
		}
		system("pause");
	}while(opc!=0);
	
    /*class Node *temp = NULL;
 
    insert_node(&temp, "CAT");
    insert_node(&temp, "BUGS");
    insert_node(&temp, "CATS");
    insert_node(&temp, "UP");
 
    int level = 0;
    char str[20];

    cout << "1.Content of the TST before deletion:\n";
    display(temp, str, level);
 

    delete_node(temp,"CAT", level, 5);
 

    cout << "\n2.Content of the TST after deletion:\n";
    display(temp, str, level);*/
    return 0;
}

int menu()
		{
			int opc;
			char val[10];
			Validacion v;
			cout<<"\n****************************MENU****************************\n"<<endl
				<<"1. Ingresar un elemento a la tabla"<<endl
				<<"2. Buscar un elemento en la tabla"<<endl
				<<"3. Eliminar un elemento en la tabla"<<endl
				<<"4. Imprimir tabla"<<endl
				<<"0. Salir"<<endl;
			char* mensaje = (char*) "\nEscoja una opcion: ";
			strcpy(val,v.ingresarDato(mensaje));
        	opc=atoi(val);
			return opc;
		}