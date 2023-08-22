#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct File {
    char name[50];
};


struct File directory[100];
int fileCount = 0;


void createFile(char name[]) {
    if (fileCount >= 100) {
        printf("Directory is full. Cannot create more files.\n");
        return;
    }

    strcpy(directory[fileCount].name, name);
    fileCount++;
    printf("File '%s' created successfully.\n", name);
}


void deleteFile(char name[]) {
    int found = 0;

    for (int i = 0; i < fileCount; i++) {
        if (strcmp(directory[i].name, name) == 0) {
            found = 1;

            
            for (int j = i; j < fileCount - 1; j++) {
                strcpy(directory[j].name, directory[j + 1].name);
            }

            fileCount--;
            printf("File '%s' deleted successfully.\n", name);
            break;
        }
    }

    if (!found) {
        printf("File '%s' not found in the directory.\n", name);
    }
}


void listFiles() {
    if (fileCount == 0) {
        printf("Directory is empty.\n");
        return;
    }

    printf("Files in the directory:\n");
    for (int i = 0; i < fileCount; i++) {
        printf("%s\n", directory[i].name);
    }
}

int main() {
    int choice;
    char name[50];

    while (1) {
        printf("\nSingle-Level Directory Operations:\n");
        printf("1. Create File\n");
        printf("2. Delete File\n");
        printf("3. List Files\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the file to create: ");
                scanf("%s", name);
                createFile(name);
                break;
            case 2:
                printf("Enter the name of the file to delete: ");
                scanf("%s", name);
                deleteFile(name);
                break;
            case 3:
                listFiles();
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

