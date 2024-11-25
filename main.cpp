#include <cstdlib>
#include <cstring>
#include "FileReader.h"

using namespace std;

//THIS IS AN EXAMPLE FILE - YOU CAN DELETE EVERYTHING HERE

int main() {
    linklist TvShow;

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

        char * age = new char[strlen(token) + 1];
        strcpy(age,token);

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
        TvShow.addShow(showName,characterName,age,specialAbility);
        // For demonstration purposes, let's just print them
        // std::cout << "Show: " << showName << ", Character: " << characterName
        //           << ", Age: " << age << ", Ability: " << specialAbility << std::endl;

        
        // Don't forget to free the allocated memory
        delete[] showName;
        delete[] characterName;
        delete[] age;
        delete[] specialAbility;
        delete[] line;
    }

    //user interface
    char* input = new char[100];
    while (true) {
            char* showName = new char[100];
            char* characterName = new char[100];
            char * age = new char[100];
            char* specialAbility  =new char[100];
        // Display the menu
        cout << "\n"
            << "\033[1;32m=====================================================\n"  // Bold blue for header
            << "                     MAIN MENU                      \n"
            << "=====================================================\033[0m\n"  // Reset to default color
            << "   \033[33m<1>\033[0m \033[93mDisplay All TV Shows and Characters           \033[0m\n"  // Pink number, blue text
            << "   \033[33m<2>\033[0m \033[93mAdd a New Character                           \033[0m\n"
            << "   \033[33m<3>\033[0m \033[93mDelete a Character                            \033[0m\n"
            << "   \033[33m<4>\033[0m \033[93mSearch for a Character                        \033[0m\n"
            << "   \033[33m<5>\033[0m \033[93mSort Characters in a TV Show                  \033[0m\n"
            << "   \033[33m<6>\033[0m \033[93mUpdate Character Info                         \033[0m\n"
            << "   \033[33m<7>\033[0m \033[93mExit                                          \033[0m\n"
            << "\033[1;32m=====================================================\033[0m\n";  // Bold blue footer
        cout << "Please enter your choice by number <\033[33m1-7\033[0m>:\n> ";

        cin.getline(input, 100); // Get input from user
    
    if (strcmp(input, "7") == 0) {
            cout << "\nTerminate the program safely\n";
            break;
        } else if (strcmp(input, "1") == 0) {
        cout << "\n\033[93m[INFO] This program manages TV shows and their characters.\033[0m\n";
            TvShow.printShows();
        } else if (strcmp(input, "2") == 0) {
            cout << "\n\033[93m[INFO] You selected to add a character. Processing...\033[0m\n";

            cout << "Enter the name of the TV show: ";
            cin.getline(showName, 100);
            cout << "Enter the character's name: ";
            cin.getline(characterName, 100);
            cout << "Enter the character's age: ";
            cin.getline(age, 100);
            cout << "Enter the character's special ability: ";
            cin.getline(specialAbility, 100);

            TvShow.addShow(showName,characterName,age,specialAbility);
            //delete[] showName;
            //delete[] characterName;
            //delete[] age;
            //delete[] specialAbility;

        }else if (strcmp(input, "3") == 0) {
            cout << "\n\033[93m[INFO] You selected to delete a character. Processing...\033[0m\n";
            cout << "Enter the character's name for Deletion: ";
            cin.getline(characterName, 100);
            TvShow.deleteChar(characterName);
            //delete[] characterName;

        } else if (strcmp(input, "4") == 0) {
            cout << "\n\033[93m[INFO] You selected to search for a character. Processing...\033[0m\n";
            cout << "Enter the character's name you want to search: ";
            cin.getline(characterName, 100);
            TvShow.SearchChar(characterName);
            //delete[] characterName;

        } else if (strcmp(input, "5") == 0) {
            cout << "\n\033[93m[INFO] You selected to Sort character info. Processing...\033[0m\n";
            // Add update logic here
        } else if (strcmp(input, "6") == 0) {
            cout << "\n\033[93m[INFO] You selected to update character (NOTE :: name cannot be changed!)\033[0m\n";
            cout << "Enter the character's name you want to Update: ";
            cin.getline(characterName, 100);
            cout << "Enter the new age (or type 'NONE' to keep the current age): ";
            cin.getline(age,100);
            cout << "Enter the new specialAbility (or type 'NONE' to keep the current specialAbility):" ;
            cin.getline(specialAbility,100);

            TvShow.updateChar(characterName,age,specialAbility);
            //delete[] characterName;
            //delete[] age;
            //delete[] specialAbility;

        } else {
            cout << "\n\033[31m[ERROR] Invalid input. Please try again.\033[0m\n";
        }
    }
    // delete[] showName;
    // delete[] characterName;
    // delete[] age;
    // delete[] specialAbility;

    delete[] input;
    return 0;
}
