#ifndef SONG_H_INCLUDED
#define SONG_H_INCLUDED

#include <iostream>
#include <string>

class Song {
    private:
         std::string name;
         std::string author ;
         std::string interpreter ;
         std::string mp3;

        void copyAll(Song&);

    public:
        Song();
        Song(std::string,std::string,std::string,std::string);

        Song(Song&);
        Song operator = (Song&);

         std::string getName();
         std::string getAuthor();
         std::string getInterpreter();
         std::string getMP3();

        void setName(const std::string);
        void setAuthor(const std::string );
        void setInterpreter(const std::string );
        void setMp3(const std::string);


        std::string toString();

        bool operator == (Song&);
        bool operator != (Song&);
        bool operator > (Song&);
        bool operator >= (Song&);
        bool operator < (Song&);
        bool operator <= (Song&);

        static int compareByName(Song&,Song&);
        static int compareByInterpreter(Song&,Song&);




    };

#endif // SONG_H_INCLUDED
