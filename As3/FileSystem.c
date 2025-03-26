#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FileSystem.h"
//
/**
@Author Brayden Lavigne 
@author Mike Drost
	*/
// yes i named it Groot on purpose
Directory* createGroot(){
    Directory* newDir = malloc(sizeof(Directory));
    if (!newDir) {
        printf("Memory allocation failed\n");
        return 0;
        }
	newDir->name = malloc(5*sizeof(char));
    strcpy(newDir->name,"root");

    newDir->children = NULL;
    newDir->files = NULL;
    newDir->nextDir = NULL; 
    newDir->parentDir = NULL; //root is orphan :(
    return newDir; //why did i forget this smh
}

void addDirectory(Directory* parent, char* name) {
    Directory* newDir = malloc(sizeof(Directory));
    if (!newDir) {
        printf("Memory allocation failed\n");
        return;
    }
    
	newDir->name = malloc(sizeof(char)* strlen(name)+1);
    strcpy(newDir->name, name);

    newDir->children = NULL;
    newDir->files = NULL;
    newDir->nextDir = NULL;
    newDir->parentDir = parent;

    Directory* child = parent->children;
    while (child) {
        if (strcmp(child->name, name) == 0) {
            printf("Directory already exists\n");
            return;
        }
        child = child->nextDir; //finding the last child returns null when we reach the end
    }

    newDir->nextDir = parent->children;
    parent->children = newDir;
}

void addFile(Directory* parentDir,char* name, int size){
    File* newFile = (File*)malloc(sizeof(File));
    if (!newFile) {
        printf("Memory allocation failed\n");
        return;
    }
    newFile->name = malloc(sizeof(char)* strlen(name)+1);
    strcpy(newFile->name, name);
    newFile->size = size;
    newFile->nextFile = NULL;
    newFile->parentDir = parentDir;

    File* file = parentDir->files;
    while (file) {
        if (strcmp(file->name, name) == 0) {
            printf("File already exists\n");
            return;
        }
        file = file->nextFile; // exit once last file in list is reached same concept as adding directory
    }
    newFile->nextFile = parentDir->files;
    parentDir->files = newFile;
}
Directory* findDirectory(Directory* root,char* name){
    if (strcmp(root->name, name) == 0) return root;

    Directory* child = root->children;
    while (child) {
        Directory* result = findDirectory(child, name); //recursively searched the children and theyre children and theyre children and theyre children and theyre children etc
        if (result) return result;
        child = child->nextDir;
    }
    return NULL; //self explanitory, the child is missing and you should probably call police 
}
// depth is used for proper indentation
void listDirectory(Directory* dir, int depth){
    if (!dir) return;

    for (int i = 0; i < depth; i++) printf("  ");
    printf("Directory:  %s\n", dir->name);

    File* file = dir->files;
    while (file) {
        for (int i = 0; i < depth + 1; i++) printf("  "); //makes like tree :0
        printf("File: %s bytes: %d\n", file->name, file->size);
        file = file->nextFile;
    }
    // this part down here recursively prints children until theyre all printed , 'redacted'
    Directory* child = dir->children;
    while (child) {
        listDirectory(child, depth + 1); //my brain hurts 
        child = child->nextDir;
    }
}
void searchTree(Directory* dir,char* target){
	if (!dir){ // initial check to see if the root is rooting
		printf("Target: %s Not found.\n", target);
		return;
	}
	printf("%s/", dir->name);
	if(strcmp(dir->name, target) == 0){ // looking for a directory scowering.
		printf("\nFound directory:  %s \n", dir->name);
		return;
	}
	File* file = dir->files; // make a file structure for the directory to search files in directory WOWOWOWOW
	while(file != NULL){ // check all files in directory. Had to add the second check to fix infinite loop
		if (strcmp(file->name, target) == 0){ // compare
			printf("\nFound file: %s\n", file->name);
			return;
		}
		file = file->nextFile; // moving to next file in directory
	}
	Directory* currentSub = dir->children; // moves to next directory
	searchTree(currentSub, target); // recursively check groot to see if he's hiding a file
	return;
}
void freeDirectory(Directory* dir) {
    if (dir == NULL) {
        printf("not a directory\n");
        return;
    }

    File* currentFile = dir->files;
    while (currentFile != NULL) {
        File* nextFile = currentFile->nextFile;
        free(currentFile->name); //frees all the files in the directory that are linked together 
        free(currentFile); 
        currentFile = nextFile;
    }

    Directory* currentSub = dir->children;
    while (currentSub != NULL) {
        Directory* nextChild = currentSub->nextDir; 
        freeDirectory(currentSub); // should recursivly free all sub directories
        currentSub = nextChild;
    }

    // frees the actual directory at the end of recursive before unwind :) groot is last 
    free(dir->name);
    free(dir);
}
