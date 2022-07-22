#pragma once
#include <string>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <limits>
#include <algorithm>

using namespace std;

static inline string validarCh(string msg){
	string dato;
	char c;
	int i=0;
	cout<<msg<<endl;
	while((c=getch()) !=13){
		if(c>='a' && c<='z' || c==' ' || c>='A' && c<='Z'){
			printf("%c",c);
			dato+=(char)c;
		}
	}
	cout<<endl;
	return dato;
}

static inline string validarTodo(string msg){
	string dato;
	char c;
	int i=0;
	cout<<msg<<endl;
	while((c=getch()) !=13){
		if( c==' ' || c>='A' && c<='Z' || c>='0' && c<='9'){
			printf("%c",c);
			dato+=(char)c;
		}
	}
	cout<<endl;
	return dato;
}

static inline int validarNum(string msg){
    string dato;
    int i=0,valor;
    char c;
    cout<<msg<<endl;
    while((c=getch())!=13){
        if(c>='0' && c<='9'){
            printf("%c",c);
            dato+=(char)c;
        }
    }
    valor=stoi(dato);
    cout<<endl;
    return valor;
}

static inline char* validarC(char*msg){
	char* dato=new char[10];
	char c;
	int i=0;
	printf("%s",msg);
	while((c=getch()) !=13){
		if(c>='a' && c<='z' || c==' ' || c>='A' && c<='Z' || c>='0' && c<='9'){
			printf("%c",c);
			dato[i++]=c;
		}
	}
	dato[i]='\0';
	cout<<endl;
	return dato;
}

static inline char* validarCLV(char*msg){
	char* dato=new char[10];
	char c;
	int i=0;
	printf("%s",msg);
	while((c=getch()) !=13){
		if(c>='a' && c<='z' || c==' ' || c>='A' && c<='Z' || c>='0' && c<='9'){
			printf("*");
			dato[i++]=c;
		}
	}
	dato[i]='\0';
	cout<<endl;
	return dato;
}