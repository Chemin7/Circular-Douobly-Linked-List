#include "userinterface.h"
#include <iostream>
#include <string>

using namespace std;

void UserInterface::insertElem()
{
     string name,author,interpreter,mp3;
    Song s;
    Node<Song>* pos;
    int opc,rep;

    do {
        cin.ignore( );
        cout<<"Ingresa el nombre de la cancion: ";
        getline(cin,name);
        cout<<"Ingresa el nombre de el autor: ";
        getline(cin,author);
        cout<<"Ingresa el nombre de el interprete: ";
        getline(cin,interpreter);
        cout<<"Ingresa el nombre del archivo MP3: ";
        getline(cin,mp3);

        s.setName(name);
        s.setAuthor(author);
        s.setInterpreter(interpreter);
        s.setMp3(mp3);

        cout<<"En que posicion lo quieres insertar?\n"
            <<"1) Al inicio\n"
            <<"2) Al final\n"
            <<"3) Despues de una cancion en la lista\n"
            <<"Selecciona una opcion: ";
        cin>>opc;

        switch(opc) {
            case 1:
                pos=nullptr;
                myList.insertElem(pos,s);
                break;
            case 2:
                pos=myList.getLastPos();
                myList.insertElem(pos,s);
                break;
            case 3:
                pos = selectElem();
                if(pos==nullptr) {
                    cout<<"Elemento no encontrado o lista vacia"<<endl;
                    system("pause");
                    return;
                    }
                else {
                    myList.insertElem(pos,s);
                    }
                break;
            }

        cout<<"Elemento insertado exitosamente..."<<endl;


        cout<<"Si quieres ingresar otro elemento presiona 1: ";
        cin>>rep;

        cout<<endl;

        }while(rep==1);

    system("pause");
}

void UserInterface::removeElem()
{
 Node<Song>* pos(nullptr);
    cout<<"----------Eliminar cancion---------"<<endl;
    pos = selectElem();

    if(pos !=nullptr){
    cout<<"El elemento: "<<endl;
    cout<<myList.retrieve(pos).toString();
     cout<<"Eliminado exitosamente..."<<endl;
    myList.deleteElem(pos);
    }else{
        cout<<"El elemento no se encuentra en la lista"<<endl;
    }



    system("pause");
}

void UserInterface::getElem()
{
     Node<Song>* pos(nullptr);
    cout<<"---------Obtener elemento-----------"<<endl;
    pos = selectElem();
    cout<<myList.retrieve(pos).toString()<<endl;
    system("pause");
}

void UserInterface::deleteAllElems()
{
    cout<<"---------Eliminar todos los elementos---------"<<endl;
    myList.deleteAll();
    //cout<<"Elementos eliminados"<<end;
    cout<<"Elementos eliminados"<<endl;
    system("pause");
}

void UserInterface::findElem()
{
    Node<Song>* pos(nullptr);
    cout<<"-------------Encontrar elemento-------------"<<endl;
    pos = selectElem();

    if(pos!=nullptr) {
        cout<<"El elemento se encuentra en la posicon "<<pos<<"  de la lista."<<endl;
        cout<<endl;
        }
    else {
        cout<<"El elemento no se encuentra en  la lista"<<endl;
        }

    system("pause");
}

Node<Song>* UserInterface::selectElem()
{
    int opc;
    string atribute;
    Node<Song>* pos(nullptr);

    cout<<"Selecciona uno de los atributos de la cancion\n"
        <<"1) Por nombre\n"
        <<"2) Por autor\n"
        <<"3) Por interprete\n"
        <<"4) Por nombre de archivo mp3\n"
        <<"Elige una opcion: ";
    cin>>opc;
    switch(opc) {
        case 1:
            cin.ignore();
            cout<<"Ingresa el nombre de la cancion: ";
            getline(cin,atribute);
            pos = myList.findElemByAtribute(atribute,1);
            break;
        case 2:
            cin.ignore();
            cout<<"Ingresa el autor de la cancion: ";
            getline(cin,atribute);
            pos = myList.findElemByAtribute(atribute,2);
            break;
        case 3:
            cin.ignore();
            cout<<"Ingresa el nombre del interprete de la cancion: ";
             getline(cin,atribute);
            pos = myList.findElemByAtribute(atribute,3);
            break;
        case 4:
            cin.ignore();
            cout<<"Ingresa el nombre del archivo de la cancion: ";
            getline(cin,atribute);
            pos = myList.findElemByAtribute(atribute,4);
            break;
        }

    return pos;
}

UserInterface::UserInterface()
{

}

UserInterface::UserInterface(List<Song>&)
{

}

void UserInterface::mainMenu()
{
    int opc;
    do {
        system("cls");
        cout<<myList.toString();
        cout<<"----------MENU---------\n"
            <<"1) Ingresar un elemento\n"
            <<"2) Remover elemento\n"
            <<"3) Obtener elemento\n"
            <<"4) Encontrar elemento\n"
            <<"5) Borrar todos los elementos\n"
            <<"6) Salir\n"
            <<"Seleciona una opcion: ";
        cin >>opc;

        switch(opc) {
            case 1:
                insertElem();
                break;
            case 2:
                removeElem();
                break;
            case 3:
                getElem();
                break;
            case 4:
                findElem();
                break;
            case 5:
                deleteAllElems();
                break;
            case 6:
                break;
            default:
                cout<<"Opcion invalida"<<endl;
            }

        }
    while(opc!=6);
}
