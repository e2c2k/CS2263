#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#define MAX_NAME_LENGTH 50

// directory node
typedef struct Directory {
    char *name;
    struct Directory* children;  // linked lists of child directories
    struct File* files;          // linked lists of files
    struct Directory* nextDir;      // next directory under same parent
    struct Directory* parentDir;    // Parent directory null for groot 
} Directory;

//file node
typedef struct File {
    char *name;
    int size;                   // file size
    struct File* nextFile;          // next file under than same parentDir
    struct Directory* parentDir;   // parent directory
} File;

// outlines
void addDirectory(Directory* parent,char* name);
void addFile(Directory* parent,char* name, int size);
Directory* findDirectory(Directory* root,char* name);
void listDirectory(Directory* dir, int depth);
void searchTree(Directory* dir,char* target);
void freeDirectory(Directory* dir);
Directory* createGroot();

#endif 