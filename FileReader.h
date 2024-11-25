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
    char* age;      // Character age
    Character* next; // Pointer to the next character

    Character() : name(nullptr), SPA(nullptr), age(nullptr), next(nullptr) {}
    ~Character();

    void setCharacter(const char* charName, char * charAge, const char* spa);
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
    void addCharacter(const char* charName, char * charAge, const char* spa);
    
    TvShow* getNext() const { return next; }
    void setNext(TvShow* nextShow) { next = nextShow; }

};

class linklist {
private:
    TvShow * head;

public:
    linklist() : head(nullptr) {}
    ~linklist();
    //take from file + Input details of a new character and add them to the appropriate TV show.
    void addShow(const char* showName, const char* charName, char * charAge, const char* spa);
    
    //Show all TV shows in your catalog along with their respective characters.
    void printShows() const;
    //Remove a character by name from a TV show.
    void deleteChar(char * deletedCharacter);
    //Find and display a character by name across all TV shows.
    void SearchChar(char * findCharacter) const;
    //Rearrange and update the character list of a specific TV show based on a chosen sorting criterion.
    void Sort(const char* showName,char* input);
    //Modify the details of an existing character.
    void updateChar(const char * updateCharacter,char * UpdateAge,char * UpdateSPA);
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
