#include<iostream>
#include "Arbol.h"
#include "Validacion.h"
#include "Menu.h"
#include "utils.h"
#include "marquesina.h"

using namespace std;

int main(int argc, char** argv){
	const char* us,*us1,*cl,*cl1;
	Menu menu;
	Validacion v;
	class Node *temp = NULL;
	int opc, dim, level=0;
	char val[20], str[20];
	
	us1={"a"};
	cl1={"a"};
	cout<<endl<<endl<<endl<<"				Ingreso al sistema"<<endl<<endl<<endl;
	us= validarC("Usuario: ");
	cl= validarCLV("Clave: ");
	if(strcmp(us,us1)==0 && strcmp(cl,cl1)==0){
		system("cls");
		do{
			system("cls");
			opc=menu.menu();
			switch(opc){
				case 0:{
					strcpy(val,v.ingresarDatoC("\nIngrese una palabra: "));
					insert_node(&temp, val);
					break;
				}
				case 1:{
					strcpy(val,v.ingresarDatoC("\nIngrese el valor que desea buscar: "));
    	    		searchTST(temp, val) ? cout << "\nPalabra encontrada\n" : cout << "\nPalabra no encontrada\n";
    	            break;
				}
				case 2:{
					strcpy(val,v.ingresarDatoC("\nIngrese el valor que desea eliminar: "));
					delete_node(temp,val, level, 5);		            
					break;
				}
				case 3:{
					cout<<"\nPalabras dentro del arbol"<<endl;
					display(temp, str, level);            
					break;
				}
				case 4:{
					cout<<"\nAdios, Gracias por usar el programa :D "<<endl;
					break;
				}
				default:{
					cout<<"\nError. Opcion incorrecta"<<endl;
					break;
				}
			}
			system("pause");
		}while(opc!=4);
	} else{
		cout<<"Ingreso de datos incorrecto"<<endl;
	}
    return 0;
}