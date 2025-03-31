#include "alien_pet.h"
#include <string.h>

// Adds a new Alien Pet into the system
int addAlienPet(AlienPet* pets[], int *count, const char* name, const char* species, int age, const char* planet) {
    // Check if the pet array is full
    // TODO
    printf("0");
        if( *count >= MAX_PETS){ 
            printf("too many pets");
            return 0;
        }
    // Allocate memory for the new AlienPet
    // TODO
    AlienPet *newPet;
    newPet = malloc(sizeof(*newPet)+1);
    if (!newPet) {
        printf("Memory allocation failed for AlienPet.\n");
        return 0;
    }
    
    // Allocate and copy the pet's name
    // TODO
    
    name = malloc(sizeof(name)+1);
    strcpy(newPet->name, name);
    
    // Allocate and copy the pet's species
    // TODO
    species = malloc(sizeof(species)+1);
    strcpy(newPet->species, species);
    
    // Allocate and copy the pet's home planet
	// TODO
	planet = malloc(sizeof(planet)+1);
    strcpy(newPet->planet, planet);

    // Set the pet's age
    // TODO
     *newPet->age = age;
    // Add pet to array and increment count
    // TODO

     count++;
	 pets[*count] = newPet;
    return 1; // success
}

// Displays details of a single Alien Pet
void displayAlienPet(const AlienPet* pet) {
    if (!pet) {
    printf("no pets");
    return;
	// TODO
    
    }
	// TODO
	int i;
	printf("name: ");
    for( i = 0; i < sizeof(pet-> name); i++){
        printf("%c",pet -> name);
    }
    printf("\nspecies: ");
	for(i = 0; i < sizeof(pet -> species); i++){
	    printf("%c", pet -> species);
	}
	printf("\nplanet: ");
	for(i = 0; i < sizeof(pet -> planet); i++){
	    printf("%c", pet -> planet);
	}
	printf("\nage: ");
	for(i = 0; i < sizeof(pet -> age); i++){
	    printf("%d", pet -> age);
	}
	printf("\n");
}

// Displays details of all Alien Pets in the system
void displayAllAlienPets(AlienPet* pets[], int count) {
    if (count == 0) {
        printf("no pets added");
       // TODO
	   
	   }

    printf("\n--- List of Alien Pets (%d pets) ---\n", count);
    // TODO
	for(int i = 0; i < count; i++){
	displayAlienPet(pets[i]);
	}
	
	
}

// Frees memory allocated for a single Alien Pet
void freeAlienPet(AlienPet* pet) {
    if (!pet) return;

	// TODO
    free(pet);


}

// Frees memory allocated for all Alien Pets
void freeAllAlienPets(AlienPet* pets[], int *count) {
	// TODO
    int j =0;
    for(int * i = 0; i < count; i++){
        freeAlienPet(pets[j]);
        j++;
    }

    *count = 0; // reset count to 0
}
