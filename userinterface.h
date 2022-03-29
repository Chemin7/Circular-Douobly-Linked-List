#ifndef USERINTERFACE_H_INCLUDED
#define USERINTERFACE_H_INCLUDED
#include "list.h"
#include "song.h"
class UserInterface{

private:
        List<Song> myList;

        void insertElem();
        void removeElem();
        void getElem();
        void deleteAllElems();
        void findElem();
        Node<Song>* selectElem();

    public:
        UserInterface();
        UserInterface(List<Song>&);

        void mainMenu();

};

#endif // USERINTERFACE_H_INCLUDED
