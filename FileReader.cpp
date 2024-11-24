#include "FileReader.h"
//character class
Character::~Character() {
    delete[] name;
    delete[] SPA;
}
void Character::setCharacter(const char* charName, int charAge, const char* spa) {
    name = new char[strlen(charName) + 1];
    strcpy(name, charName);

    SPA = new char[strlen(spa) + 1];
    strcpy(SPA, spa);

    age = charAge;
}

//linkedlist
linklist::~linklist() {
    TvShow* current = head;
    while (current) {
        TvShow* toDelete = current;
        current = current->getNext();
        delete toDelete;
    }
}

void linklist::addShow(const char* showName, const char* charName, int charAge, const char* spa) {
    TvShow* temp = head;

    while (temp) {
        if (strcmp(temp->getName(), showName) == 0) {
            temp->addCharacter(charName, charAge, spa);
            return;
        }
        temp = temp->getNext();
    }

    TvShow* newShow = new TvShow();
    newShow->setName(showName);
    newShow->addCharacter(charName, charAge, spa);
    newShow->setNext(nullptr);

    if (!head) {
        head = newShow;
    } else {
        temp = head;
        while (temp->getNext()) {
            temp = temp->getNext();
        }
        temp->setNext(newShow);
    }
}

//show class
TvShow::~TvShow() {
    delete[] name;

    // Delete cast linked list
    Character* current = cast;
    while (current) {
        Character* toDelete = current;
        current = current->getNext();
        delete toDelete;
    }
}

void TvShow::setName(const char* showName) {
    name = new char[strlen(showName) + 1];
    strcpy(name, showName);
}

void TvShow::addCharacter(const char* charName, int charAge, const char* spa) {
    Character* newCharacter = new Character();
    newCharacter->setCharacter(charName, charAge, spa);
    newCharacter->setNext(nullptr);

    if (!cast) {
        cast = newCharacter;
    } else {
        Character* temp = cast;
        while (temp->getNext()) {
            temp = temp->getNext();
        }
        temp->setNext(newCharacter);
    }
}

//filereader class
FileReader::FileReader(const char* filename) {
    file.open(filename);
}

FileReader::~FileReader() {
    if (file.is_open()) {
        file.close();
    }
}

bool FileReader::isOpen() {
    return file.is_open();
}

char* FileReader::getNextLine() {
    if (!file.is_open()) {
        return NULL;
    }

    std::string line;
    if (std::getline(file, line)) {
        // Convert std::string to char*
        char* cstr = new char[line.length() + 1];
        std::strcpy(cstr, line.c_str());
        return cstr;
    } else {
        return NULL;
    }
}
