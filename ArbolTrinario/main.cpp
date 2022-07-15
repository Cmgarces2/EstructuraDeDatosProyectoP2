#include <iostream>
#include "Nodo.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int menu();

int main(int argc, char** argv) {
	
	Validacion v;
	int opc, dim;
	char val[10];
	do{
		system("cls");
		opc=menu();
		switch(opc)
		{
			case 1:{
				char* mensaje = (char*) "\nIngrese un valor: ";
				strcpy(val,v.ingresarDato(mensaje));
        		dim=atoi(val);
				objt.ingreso(dim);	
				cout<<endl;
				break;
			}
			case 2:{
				char* mensaje = (char*) "\nIngrese el valor que desea buscar: ";
				strcpy(val,v.ingresarDato(mensaje));
        		dim=atoi(val);
        		cout<<endl;
				if (objt.busqueda(dim)==1){
					cout << "El valor ha sido encontrado" << endl;
					objt.impresion();
				}
				else {
					cout << "Valor no encontrado" << endl;
				};			            
				break;
			}
			case 3:{
				char* mensaje = (char*) "\nIngrese el valor que desea eliminar: ";
				strcpy(val,v.ingresarDato(mensaje));
        		dim=atoi(val);
        		cout<<endl;
				if (objt.eliminar(dim)) {
					cout << "Despues de la eliminacion" << endl;
				}
				else {
					cout << "Valor no encontrado" << endl;
				};			            
				break;
			}
			case 4:{
				objt.impresion();			            
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
	
	/*Node* root = NULL;
    char cat[] = "cat";
    char cats[] = "cats";
    char up[] = "up";
    char bug[] = "bug";
    char bu[] = "bu";
    insert(&root, cat);
    insert(&root, cats);
    insert(&root, up);
    insert(&root, bug);
 
    cout << "Following is traversal of ternary search "
            "tree\n";
    traverseTST(root);
 
    cout << "\nFollowing are search results for cats, bu "
            "and cat respectively\n";
    searchTST(root, cats) ? cout << "Found\n"
                          : cout << "Not Found\n";
    searchTST(root, bu) ? cout << "Found\n"
                        : cout << "Not Found\n";
    searchTST(root, cat) ? cout << "Found\n"
                         : cout << "Not Found\n";*/
 
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