#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FileSystem.c"
int main() {
    Directory* root = createGroot();
    int choice, size;
    char name[MAX_NAME_LENGTH], parentName[MAX_NAME_LENGTH];
    Directory* parent;
    printf("\n+++++++File System Hierarchy Manager+++++++\n");

    while (1) {
        printf("\n1. Create a New Directory\n");
        printf("2. Create a New File\n");
        printf("3. List Contents\n");
        printf("4. Search for an Item\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // add directory
                printf("Enter parent directory name: ");
                scanf("%s", parentName);
                parent = findDirectory(root, parentName);
                if (!parent) {
                    printf("\n++++++++++++Parent directory not found+++++++++++\n");
                    break;
                }
                printf("Enter new directory name: ");
                scanf("%s", name);
                addDirectory(parent, name);
                break;

            case 2: // add File
                printf("Enter parent directory name: ");
                scanf("%s", parentName);
                parent = findDirectory(root, parentName);
                if (!parent) {
                    printf("\n++++++++++++Parent directory not found+++++++++++\n");
                    break;
                }
                printf("Enter file name: ");
                scanf("%s", name);
                printf("Enter file size: ");
                scanf("%d", &size);
                addFile(parent, name, size);
                break;

            case 3: // ls
                listDirectory(root, 0);
                break;

            case 4: // Search
                printf("Enter name to search: ");
                scanf("%s", name);
                printf("Search results: \n");
                searchTree(root, name);
                break;

            case 5: // exit
                printf("You Can't Leave");
                freeDirectory(root);
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
