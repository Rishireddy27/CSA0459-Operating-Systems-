#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBDIRECTORIES 50
#define MAX_FILES_PER_DIRECTORY 50
#define MAX_FILENAME_LENGTH 50


struct File {
    char name[MAX_FILENAME_LENGTH];
};


struct Directory {
    char name[MAX_FILENAME_LENGTH];
    struct File files[MAX_FILES_PER_DIRECTORY];
    int fileCount;
};


struct Directory directories[MAX_SUBDIRECTORIES];
int directoryCount = 0;


void createDirectory(char name[]) {
    if (directoryCount >= MAX_SUBDIRECTORIES) {
        printf("Cannot create more directories. Maximum limit reached.\n");
        return;
    }

    strcpy(directories[directoryCount].name, name);
    directories[directoryCount].fileCount = 0;
    directoryCount++;
    printf("Directory '%s' created successfully.\n", name);
}


void createFile(char dirName[], char fileName[]) {
    for (int i = 0; i < directoryCount; i++) {
        if (strcmp(directories[i].name, dirName) == 0) {
            struct Directory *dir = &directories[i];
            if (dir->fileCount >= MAX_FILES_PER_DIRECTORY) {
                printf("Cannot create more files in directory '%s'. Maximum limit reached.\n", dirName);
                return;
            }

            strcpy(dir->files[dir->fileCount].name, fileName);
            dir->fileCount++;
            printf("File '%s' created in directory '%s'.\n", fileName, dirName);
            return;
        }
    }

    printf("Directory '%s' not found.\n", dirName);
}


void listFilesInDirectory(char dirName[]) {
    for (int i = 0; i < directoryCount; i++) {
        if (strcmp(directories[i].name, dirName) == 0) {
            struct Directory *dir = &directories[i];
            printf("Files in directory '%s':\n", dirName);
            for (int j = 0; j < dir->fileCount; j++) {
                printf("- %s\n", dir->files[j].name);
            }
            return;
        }
    }

    printf("Directory '%s' not found.\n", dirName);
}

int main() {
    int choice;
    char dirName[MAX_FILENAME_LENGTH];
    char fileName[MAX_FILENAME_LENGTH];

    while (1) {
        printf("\nTwo-Level Directory Operations:\n");
        printf("1. Create Directory\n");
        printf("2. Create File in Directory\n");
        printf("3. List Files in Directory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the directory to create: ");
                scanf("%s", dirName);
                createDirectory(dirName);
                break;
            case 2:
                printf("Enter the name of the directory: ");
                scanf("%s", dirName);
                printf("Enter the name of the file to create: ");
                scanf("%s", fileName);
                createFile(dirName, fileName);
                break;
            case 3:
                printf("Enter the name of the directory to list files: ");
                scanf("%s", dirName);
                listFilesInDirectory(dirName);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

