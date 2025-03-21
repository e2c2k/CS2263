#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FileSystem.h"
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
        file = file->nextFile; // exits once last file in list is reached same concept as adding directory
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

}
void freeDirectory(Directory* dir){
//i give up - -
//          ---
//         /   \'  
}