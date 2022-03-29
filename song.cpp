#include "song.h"


using namespace std;

Song::Song() {

    }
Song::Song(std::string a, std::string n, string i,string m) {
    name = n;
    author = a;
    interpreter = i;
    mp3 = m;
    }

void Song::copyAll(Song& s) {
    this->name = s.name;
    this->author = s.author;
    this->interpreter = s.interpreter;
    this->mp3 = s.mp3;
    }


Song::Song(Song& s) {
    copyAll(s);

    }

Song Song::operator=(Song& s) {
    copyAll(s);

    return *this;
    }


string Song::getName() {
    return name;
    }

string Song::getAuthor() {
    return author;
    }

string Song::getInterpreter() {
    return interpreter;
    }

string Song::getMP3()
    {
        return mp3;
    }


void Song::setName(const std::string n) {
    name = n;
    }

void Song::setAuthor(const std::string a) {
    author = a;
    }

void Song::setInterpreter(const string i) {
    interpreter = i;
    }

void Song::setMp3(const std::string m) {
    mp3=m;
    }

int Song::compareByName(Song& s,Song& e) {
    return s.name.compare(e.name);

    }

int Song::compareByInterpreter(Song& s, Song& e) {
    return s.interpreter.compare(e.interpreter);
    }


string Song::toString() {
    string txt,temp;

    temp=name;
    temp.resize(20,' ');
    txt+=temp;

    temp= "| " + author;
    temp.resize(20,' ');
    txt+=temp;

    temp= "| " + interpreter;
    temp.resize(20,' ');
    txt+=temp;

    temp= "| " + mp3 + ".mp3";
    temp.resize(20,' ');
    txt+=temp;


    return txt;
    }
bool Song::operator == (Song& s) {
    return name.compare(s.name) == 0;

    }

bool Song::operator!=(Song& s) {
    return !(*this == s);
    }

bool Song::operator>(Song& s) {
    return name.compare(s.name) > 0;
    }

bool Song::operator>=(Song& s) {
    return *this > s and *this == s;
    }

bool Song::operator<(Song&  s) {
    return !(*this >= s);
    }

bool Song::operator<=(Song& s) {
    return *this < s and *this == s;
    }



