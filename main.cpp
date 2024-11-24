#include <iostream>
#include <cstdlib>
#include <cstring>
#include "FileReader.h"

//THIS IS AN EXAMPLE FILE - YOU CAN DELETE EVERYTHING HERE

int main() {
    FileReader reader("characters.txt");
    if (!reader.isOpen()) {
        std::cout << "Failed to open characters.txt" << std::endl;
        return 1;
    }

    char* line;
    while ((line = reader.getNextLine()) != NULL) {
        // Parse the line
        // Expected format: ShowName,CharacterName,Age,SpecialAbility
        char* token = strtok(line, ",");
        if (token == NULL) {
            delete[] line;
            continue;
        }

        // Allocate and copy showName
        char* showName = new char[strlen(token) + 1];
        strcpy(showName, token);

        token = strtok(NULL, ",");
        if (token == NULL) {
            delete[] line;
            delete[] showName;
            continue;
        }

        // Allocate and copy characterName
        char* characterName = new char[strlen(token) + 1];
        strcpy(characterName, token);

        token = strtok(NULL, ",");
        if (token == NULL) {
            delete[] line;
            delete[] showName;
            delete[] characterName;
            continue;
        }

        int age = atoi(token);

        token = strtok(NULL, ",");
        if (token == NULL) {
            delete[] line;
            delete[] showName;
            delete[] characterName;
            continue;
        }

        // Allocate and copy specialAbility
        char* specialAbility = new char[strlen(token) + 1];
        strcpy(specialAbility, token);

        // Now you have showName, characterName, age, specialAbility
        // TODO: Add the character to the appropriate TVShow linked list
        // Remember to delete showName, characterName, and specialAbility when done

        // For demonstration purposes, let's just print them
        std::cout << "Show: " << showName << ", Character: " << characterName
                  << ", Age: " << age << ", Ability: " << specialAbility << std::endl;
        
        // Don't forget to free the allocated memory
        delete[] showName;
        delete[] characterName;
        delete[] specialAbility;
        delete[] line;
    }

    return 0;
}
