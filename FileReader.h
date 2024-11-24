#ifndef FILEREADER_H
#define FILEREADER_H

#include <fstream>
#include <cstring>
#include <iostream>

//g++ main.cpp FileReader.cpp -o ...
class Character {
public:
    char* name;   // Character name
    char* SPA;    // Special Power Ability (SPA)
    int age;      // Character age
    Character* next; // Pointer to the next character

    Character() : name(nullptr), SPA(nullptr), age(-1), next(nullptr) {}
    ~Character();

    void setCharacter(const char* charName, int charAge, const char* spa);
    void setNext(Character* nextChar) { next = nextChar; }
    Character* getNext() const { return next; }

};

class TvShow {
public:
    char* name;       // Show name
    Character* cast;  // Pointer to the head of the character list
    TvShow* next;     // Pointer to the next show (for a linked list of shows)

    TvShow() : name(nullptr), cast(nullptr), next(nullptr) {}
    ~TvShow();

    void setName(const char* showName);
    const char* getName() const { return name; }
    void addCharacter(const char* charName, int charAge, const char* spa);
    
    TvShow* getNext() const { return next; }
    void setNext(TvShow* nextShow) { next = nextShow; }

};

class linklist {
private:
    TvShow * head;

public:
    linklist() : head(nullptr) {}
    ~linklist();

    void addShow(const char* showName, const char* charName, int charAge, const char* spa);
    void printShows() const;
};


class FileReader {
public:
    FileReader(const char* filename);
    ~FileReader();
    bool isOpen();
    char* getNextLine();

private:
    std::ifstream file;
};

#endif
