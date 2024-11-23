#ifndef FILEREADER_H
#define FILEREADER_H

#include <fstream>
#include <cstring>


class Character{
public:
    char * name;
    char * specialAbility;
    int age;
    Character * next;

    // Constructor
    // Character(const char* name, const char* specialAbility, int age)
    //     : age(age), next(nullptr) {
    //     this->name = strdup(name);
    //     this->specialAbility = strdup(specialAbility);
    // }

    // // Destructor
    // ~Character() {
    //     delete[] name;
    //     delete[] specialAbility;
    // }
};

class TVShow{
public:
    char* showName;
    Character * Next_Character; // Head of the linked list of characters
    TVShow* next_show;          // Pointer to the next TVShow in the list

    // Constructor
    // TVShow(const char* showName) : characters(nullptr), next(nullptr) {
    //     this->showName = strdup(showName);
    // }

    // Destructor
    // ~TVShow() {
    //     delete[] showName;

    //     // Clean up the linked list of characters
    //     Character* current = characters;
    //     while (current) {
    //         Character* toDelete = current;
    //         current = current->next;
    //         delete toDelete;
    //     }
    // }

    // Method to add a character to the TV show
    // void addCharacter(const char* name, const char* specialAbility, int age) {
    //     Character* newCharacter = new Character(name, specialAbility, age);
    //     if (!characters) {
    //         characters = newCharacter;
    //     } else {
    //         Character* temp = characters;
    //         while (temp->next) {
    //             temp = temp->next;
    //         }
    //         temp->next = newCharacter;
    //     }
    // }

    // Display characters ( maybe we dont need it )
    // void displayCharacters() const {
    //     Character* current = characters;
    //     std::cout << "TV Show: " << showName << "\nCharacters:\n";
    //     while (current) {
    //         std::cout << " - " << current->name << " (Age: " << current->age
    //                   << ", Special Ability: " << current->specialAbility << ")\n";
    //         current = current->next;
    //     }
    // }
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
