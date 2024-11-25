#include "FileReader.h"
//character class
Character::~Character() {
    delete[] name;
    delete[] SPA;
}
void Character::setCharacter(const char* charName, char * charAge, const char* spa) {
    name = new char[strlen(charName) + 1];
    strcpy(name, charName);

    SPA = new char[strlen(spa) + 1];
    strcpy(SPA, spa);

    age = new char[strlen(charAge) + 1]; 
    strcpy(age,charAge);
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

void linklist::addShow(const char* showName, const char* charName, char * charAge, const char* spa) {
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

void linklist::printShows() const {
    TvShow* tempShow = head;
    while (tempShow) {
        std::cout << "Show: " << tempShow->name << std::endl;

        Character* tempCharacter = tempShow->cast;
        while (tempCharacter) {
            std::cout << "  Character: " << tempCharacter->name
                      << ", Age: " << tempCharacter->age
                      << ", Special Ability: " << tempCharacter->SPA << std::endl;
            tempCharacter = tempCharacter->next;
        }

        tempShow = tempShow->next;
    }
}

void linklist::deleteChar(char * deletedCharacter){
    TvShow* tempShow = head;

    while (tempShow){
        Character* prevCharacter = nullptr;
        Character* tempCharacter = tempShow->cast;

        while (tempCharacter){
            if(strcmp(deletedCharacter,tempCharacter->name) == 0){
                if (prevCharacter == nullptr) {
                    tempShow->cast = tempCharacter->next;
                } else {
                    prevCharacter->next = tempCharacter->next;
                }
                    delete[] tempCharacter->name;
                    delete[] tempCharacter->age;
                    delete[] tempCharacter->SPA;
                    std::cout << "\033[31mcharacter " << deletedCharacter << " has been deleted\033[0m" << std::endl;
                    return;
            }
            prevCharacter = tempCharacter;
            tempCharacter = tempCharacter->next;
        }
        tempShow = tempShow->next;
    }
    std::cout << "\033[31mcharacter was not found\033[0m" << std::endl;
    return;
}

void linklist::SearchChar(char * findCharacter) const{
        TvShow* tempShow = head;

    while (tempShow){
        Character* tempCharacter = tempShow->cast;

        while (tempCharacter){
            if(strcmp(findCharacter,tempCharacter->name) == 0){
                    std::cout   << "\nShow: " << tempShow->name << std::endl;
                    std::cout   << "  Character: " << tempCharacter->name
                                << ", Age: " << tempCharacter->age
                                << ", Special Ability: " << tempCharacter->SPA << std::endl;
                    return;
            }
            tempCharacter = tempCharacter->next;
        }
        tempShow = tempShow->next;
    }
    std::cout << "\033[31mcharacter was not found\033[0m" << std::endl;
    return;
}

void linklist::updateChar(const char * updateCharacter,char * UpdateAge,char * UpdateSPA){
    TvShow* tempShow = head;

    while (tempShow){
        Character* tempCharacter = tempShow->cast;

        while (tempCharacter){
            if(strcmp(updateCharacter,tempCharacter->name) == 0){
                    if(strcmp("NONE",UpdateAge)==0)
                    {
                        strcpy(tempCharacter->SPA,UpdateSPA);
                        std::cout << "\033[33mcharacter character specialAbility has been Updated\033[0m" << std::endl;
                        return;
                    }
                    else if(strcmp("NONE",UpdateAge)==0){
                        strcpy(tempCharacter->age,UpdateAge);
                        std::cout << "\033[33mcharacter Age has been Updated\033[0m" << std::endl;
                        return;
                    }
                    else{
                        strcpy(tempCharacter->SPA,UpdateSPA);
                        strcpy(tempCharacter->age,UpdateAge);
                        std::cout << "\033[33mcharacter age and specialAbility has been Updated\033[0m" << std::endl;
                        return;
                    }
            }
            tempCharacter = tempCharacter->next;
        }
        tempShow = tempShow->next;
    }
    std::cout << "\033[31mcharacter was not found\033[0m" << std::endl;
    return;
}

void linklist::Sort(const char* showName,char* input) {
    TvShow* tempShow = head;
    while (tempShow) {

        if (strcmp(showName, tempShow->name) == 0) {
            if (strcmp(input, "1") == 0) {
                // Sorting by character name alphabetically
                bool swapped;
                do {
                    swapped = false;
                    Character* current = tempShow->cast;
                    while (current && current->next) {
                        Character* nextCharacter = current->next;

                        if (strcmp(current->name, nextCharacter->name) > 0) {
                            std::swap(current->name, nextCharacter->name);
                            std::swap(current->age, nextCharacter->age);
                            std::swap(current->SPA, nextCharacter->SPA);

                            swapped = true;
                        }

                        current = current->next;
                    }
                } while (swapped);
                std::cout << "Sorting by character name alphabetically complete!" << std::endl;

                Character* tempCharacter = tempShow->cast;
                while (tempCharacter) {
                    std::cout << "  Character: " << tempCharacter->name
                              << ", Age: " << tempCharacter->age
                              << ", Special Ability: " << tempCharacter->SPA << std::endl;
                    tempCharacter = tempCharacter->getNext();
                }
            
            }else if(strcmp(input, "2") == 0){
                //sorting by character ages
                bool swapped;
                do {
                    swapped = false;
                    Character* current = tempShow->cast;
                    while (current && current->next) {
                        Character* nextCharacter = current->next;

                        if (strcmp(current->age, nextCharacter->age) > 0) {
                            std::swap(current->name, nextCharacter->name);
                            std::swap(current->age, nextCharacter->age);
                            std::swap(current->SPA, nextCharacter->SPA);

                            swapped = true;
                        }

                        current = current->next;
                    }
                } while (swapped);
                std::cout << "Sorting by character name alphabetically complete!" << std::endl;

                Character* tempCharacter = tempShow->cast;
                while (tempCharacter) {
                    std::cout << "  Character: " << tempCharacter->name
                              << ", Age: " << tempCharacter->age
                              << ", Special Ability: " << tempCharacter->SPA << std::endl;
                    tempCharacter = tempCharacter->getNext();
                }

            }else if(strcmp(input, "3") == 0 || strcmp(input,"4")==0){
                // Reverse
                Character* prev = nullptr;
                Character* current = tempShow->cast;
                Character* next = nullptr;

                while (current) {
                    next = current->getNext();
                    current->setNext(prev);    
                    prev = current;            
                    current = next;
                }

                tempShow->cast = prev;
                std::cout << "Reversed the character list!" << std::endl;
            
                Character* tempCharacter = tempShow->cast;
                while (tempCharacter) {
                    std::cout << "  Character: " << tempCharacter->name
                              << ", Age: " << tempCharacter->age
                              << ", Special Ability: " << tempCharacter->SPA << std::endl;
                    tempCharacter = tempCharacter->getNext();
                }

            }else
                std::cout << "\033[31myou didnt choose numbers in range of 1-4\033[0m" << std::endl;
            break;
        }
        tempShow = tempShow->next;
    }
    if (!tempShow) {
        std::cout << "\033[31mTV Show was not found\033[0m" << std::endl;
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

void TvShow::addCharacter(const char* charName, char * charAge, const char* spa) {
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
