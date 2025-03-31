#ifndef ALIEN_PET_H
#define ALIEN_PET_H

#include <stdio.h>
#include <stdlib.h>

// Maximum number of alien pets allowed in the system
#define MAX_PETS 50

// Structure defining an Alien Pet
typedef struct AlienPet {
    int *pets;
    int *count;
	// TODO
	char *name; // dynamically allocated name of the pet	
	// TODO	
	char *species;	     // dynamically allocated species name
	// TODO			 
	char *planet;  // dynamically allocated planet name
	// TODO
	int *age;            // age of the pet in alien years
} AlienPet;

// Function prototypes
int addAlienPet(AlienPet* pets[], int *count, const char* name, const char* species, int age, const char* planet);
void displayAlienPet(const AlienPet* pet);
void displayAllAlienPets(AlienPet* pets[], int count);
void freeAlienPet(AlienPet* pet);
void freeAllAlienPets(AlienPet* pets[], int *count);

#endif
