#include "alien_pet.h"

#define addAlienPet(pets, count, name, species, age, planet); 
#define reeAllAlienPets(pets, count);
#define displayAllAlienPets(pets, count);
int main() {
    AlienPet* pets[MAX_PETS];  // array to store pet pointers
    int count = 0;             // current pet count
    int choice;
    char name[100], species[100], planet[100];
    int age;

    printf("Welcome to Alien Pet Management!\n");

    while (1) {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Add Alien Pet\n");
        printf("2. Display All Pets\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add pet
                // TODO
				printf("enter a name: ");
				char buffer[100];
				scanf("%s", name);
				printf("\n");
				printf("enter a species: ");
				scanf("%s", species);
				printf("\n");
				printf("enter a planet: ");
				scanf("%s", planet);
				printf("\n");
				printf("enter an age: ");
				scanf("%d", &age);

				count++;
				addAlienPet(pets, count, name, species, age, planet); 
                break;

            case 2: // Display pets
                // TODO
                displayAllAlienPets(pets, count);
                break;

            case 3: // Exit
                // TODO
				//freeAllAlienPets(pets, &count);
                return 0;

            default:
                // TODO
                break;
        }
    }

    return 0; // This line is not reached due to return above
}
