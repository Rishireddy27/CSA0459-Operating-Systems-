#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BLOCKS 100 
#define MAX_FILES 10   

struct File {
    char name[50];
    int indexBlock[MAX_BLOCKS];
    int size;
};

struct FileSystem {
    struct File files[MAX_FILES];
    int fileCount;
};
void initFileSystem(struct FileSystem* fs) {
    fs->fileCount = 0;
}
void createFile(struct FileSystem* fs, const char* name) {
    if (fs->fileCount < MAX_FILES) {
        struct File* newFile = &fs->files[fs->fileCount];
        strcpy(newFile->name, name);
        newFile->size = 0;
        memset(newFile->indexBlock, -1, sizeof(newFile->indexBlock));
        fs->fileCount++;
        printf("File '%s' created successfully.\n", name);
    } else {
        printf("File system is full. Cannot create more files.\n");
    }
}
void addBlock(struct FileSystem* fs, const char* name, int block) {
    struct File* file = NULL;
    for (int i = 0; i < fs->fileCount; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            file = &fs->files[i];
            break;
        }
    }

    if (file != NULL && file->size < MAX_BLOCKS) {
        file->indexBlock[file->size] = block;
        file->size++;
        printf("Block %d added to file '%s'.\n", block, name);
    } else {
        printf("File not found or file is full. Cannot add more blocks.\n");
    }
}
void displayIndexBlock(struct FileSystem* fs, const char* name) {
    struct File* file = NULL;
    for (int i = 0; i < fs->fileCount; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            file = &fs->files[i];
            break;
        }
    }

    if (file != NULL) {
        printf("Index block for file '%s': ", name);
        for (int i = 0; i < file->size; i++) {
            printf("%d ", file->indexBlock[i]);
        }
        printf("\n");
    } else {
        printf("File not found.\n");
    }
}

int main() {
    struct FileSystem myFileSystem;
    initFileSystem(&myFileSystem);
    createFile(&myFileSystem, "file1");
    createFile(&myFileSystem, "file2");
    addBlock(&myFileSystem, "file1", 0);
    addBlock(&myFileSystem, "file1", 1);
    addBlock(&myFileSystem, "file2", 2);
    displayIndexBlock(&myFileSystem, "file1");
    displayIndexBlock(&myFileSystem, "file2");

    return 0;
}

