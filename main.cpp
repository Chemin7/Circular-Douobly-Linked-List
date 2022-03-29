#include <iostream>
#include <string>
#include "list.h"
#include "validate.h"

using namespace std;

void menu() {
    int opc,e,i,pos;
    string str_opc,str_e,str_i;
    List<int> myList;

    do {
        system("cls");
        if(myList.isEmpty())
            cout<<"Lista vacia..."<<endl;
        else
            cout<<myList;
        cout<<"1) Insertar al Principio\n"
            <<"2) Insertar al Final\n"
            <<"3) Buscar por Posición\n"
            <<"4) Modificar\n"
            <<"5) Remover\n"
            <<"6) Salir\n";
        do {
            cout<<"Seleccione una opcion: ";
            cin>>str_opc;
            }
        while( !isInt(str_opc) );

        opc=stoi(str_opc);

        switch(opc) {
            case 1:
                do{
                cout<<"Ingresa un numero: ";
                cin>>str_e;
                }while( !isInt(str_e) );
                e=stoi(str_e);

                myList.insertElem(nullptr,e);
                break;
            case 2:
                do{
                cout<<"Ingresa un numero: ";
                cin>>str_e;
                }while( !isInt(str_e) );
                e=stoi(str_e);

                myList.insertElem(myList.getLastPos(),e);
                break;
            case 3:
                do{
                cout<<"Ingresa el indice del numero a buscar: ";
                cin>>str_i;
                }while( !isInt(str_i) );
                i=stoi(str_i);

                if(myList.findElemByIndex(i) != nullptr) {
                    e=myList.retrieveElemByIndex(i);
                    cout<<"El elemnto de indice "<<i<<" es: "<<e<<endl;
                    }
                else
                    cout<<"El indice ingresado no el valido"<<endl;

                system("pause");
                break;
            case 4:
               do{
                cout<<"Ingresa el indice del numero a modificar: ";
                cin>>str_i;
                }while( !isInt(str_i) );
                i=stoi(str_i);
                if(myList.findElemByIndex(i) != nullptr) {
                    cout<<"Ingresa el numero a cambiar: ";
                    cin>>e;
                    myList.modifyElem(i,e);
                    }
                else
                    cout<<"El indice ingresado no el valido"<<endl;
                system("pause");


                break;
            case 5:
                do{
                cout<<"Ingresa el indice del numero a remover: ";
                cin>>str_i;
                }while( !isInt(str_i) );
                i=stoi(str_i);
                if(myList.findElemByIndex(i) != nullptr) {
                    myList.deleteElem(myList.findElemByIndex(i));
                    cout<<"Elemento eliminado..."<<endl;
                    }
                else
                    cout<<"El indice ingresado no el valido"<<endl;
                system("pause");
                break;
            case 6:

                break;
            }
        }
    while(opc!=6);
    }

int main() {
    menu();
    return 0;
    }
