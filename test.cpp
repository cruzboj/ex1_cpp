#include <iostream>
#include <cstring> // For strdup (need strcpy)

class Character {
    char* name;   // Character name
    char* SPA;    // Special Power Ability (SPA)
    int age;      // Character age
    Character* next; // Pointer to the next character

public:
    Character() : name(nullptr), SPA(nullptr), age(-1), next(nullptr) {}

    void setCharacter(const char* charName, int charAge, const char* spa) {
        name = new char[strlen(charName)+1];
        name = strcpy(name,charName);  
        
        SPA = new char[strlen(spa)+1];
        SPA = strcpy(SPA,spa);        
        
        age = charAge;
    }

    ~Character() {
        free(name);
        free(SPA);
    }

    void setNext(Character* nextChar) { next = nextChar; }
    Character* getNext() const { return next; }

    void printCharacter() const {
        std::cout << "Character: " << name << ", Age: " << age
                  << ", Special Ability: " << SPA << std::endl;
    }
};

class TvShow {
    char* name;       // Show name
    TvShow* next;     // Pointer to the next show
    Character* cast;  // Pointer to the head of the character list

public:
    TvShow() : name(nullptr), next(nullptr), cast(nullptr) {}

    ~TvShow();

    void setName(const char* showName) {
        name = new char[strlen(showName)+1];
        name = strcpy(name,showName); // Allocate and copy show name
    }

    const char* getName() const {
        return name;
    }

    void addCharacter(const char* charName, int charAge, const char* spa);

    void printShow() const;

    TvShow* getNext() const { return next; }
    void setNext(TvShow* nextShow) { next = nextShow; }
};

// Destructor for TvShow
TvShow::~TvShow() {
    free(name);
    Character* temp = cast;
    while (temp) {
        Character* toDelete = temp;
        temp = temp->getNext();
        delete toDelete;
    }
}

void TvShow::addCharacter(const char* charName, int charAge, const char* spa) {
    Character* newCharacter = new Character();
    newCharacter->setCharacter(charName, charAge, spa);
    newCharacter->setNext(nullptr);

    if (!cast) { // If no cast exists, set the new character as the head
        cast = newCharacter;
    } else { // Otherwise, append the new character to the cast
        Character* temp = cast;
        while (temp->getNext()) {
            temp = temp->getNext();
        }
        temp->setNext(newCharacter);
    }
}

void TvShow::printShow() const {
    if (name) {
        std::cout << "Show Name: " << name << std::endl;
    }
    if (cast) {
        std::cout << "Cast:" << std::endl;
        Character* temp = cast;
        while (temp) {
            temp->printCharacter();
            temp = temp->getNext();
        }
    } else {
        std::cout << "No cast available." << std::endl;
    }
}

class TvShowList {
    TvShow* head; // Pointer to the head of the show list

public:
    TvShowList() : head(nullptr) {}
    ~TvShowList();

    void addShow(const char* showName, const char* charName, int charAge, const char* spa);
    void printShows() const;
};

// Destructor for TvShowList
TvShowList::~TvShowList() {
    while (head) {
        TvShow* toDelete = head;
        head = head->getNext();
        delete toDelete;
    }
}

void TvShowList::addShow(const char* showName, const char* charName, int charAge, const char* spa) {
    TvShow* temp = head;

    // Check if the show already exists
    while (temp) {
        if (strcmp(temp->getName(), showName) == 0) {
            temp->addCharacter(charName, charAge, spa); // Add character to existing show
            return;
        }
        temp = temp->getNext();
    }

    // If the show doesn't exist, create a new one
    TvShow* newShow = new TvShow();
    newShow->setName(showName);
    newShow->addCharacter(charName, charAge, spa);
    newShow->setNext(nullptr);

    if (!head) { // If the list is empty
        head = newShow;
    } else { // Otherwise, append the new show to the list
        temp = head;
        while (temp->getNext()) {
            temp = temp->getNext();
        }
        temp->setNext(newShow);
    }
}

void TvShowList::printShows() const {
    TvShow* temp = head;
    while (temp) {
        temp->printShow();
        temp = temp->getNext();
    }
}

int main() {
    TvShowList showList;

    // Add multiple shows with character details
    showList.addShow("Pokemon", "Ash Ketchum", 12, "Pokemon Trainer");
    showList.addShow("Samurai Jack", "Jack", 30, "Samurai Master");
    showList.addShow("Pokemon", "Misty William", 13, "Water Trainer");

    // Print all shows
    showList.printShows();

    return 0;
}
