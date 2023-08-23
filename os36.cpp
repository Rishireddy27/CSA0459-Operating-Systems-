#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BLOCKS 100 
#define MAX_FILES 10  
struct Block {
    int blockNumber;
    struct Block* nextBlock;
};

struct File {
    char name[50];
    struct Block* firstBlock;
    struct Block* lastBlock;
};

struct FileSystem {
    struct File files[MAX_FILES];
    int fileCount;
    struct Block blocks[MAX_BLOCKS];
    int blockCount;
};
void initFileSystem(struct FileSystem* fs) {
    fs->fileCount = 0;
    fs->blockCount = 0;
}
void createFile(struct FileSystem* fs, const char* name) {
    if (fs->fileCount < MAX_FILES) {
        struct File* newFile = &fs->files[fs->fileCount];
        strcpy(newFile->name, name);
        newFile->firstBlock = NULL;
        newFile->lastBlock = NULL;
        fs->fileCount++;
        printf("File '%s' created successfully.\n", name);
    } else {
        printf("File system is full. Cannot create more files.\n");
    }
}
void addBlock(struct FileSystem* fs, const char* name, int blockNumber) {
    struct File* file = NULL;
    for (int i = 0; i < fs->fileCount; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            file = &fs->files[i];
            break;
        }
    }

    if (file != NULL) {
        struct Block* newBlock = &fs->blocks[fs->blockCount];
        newBlock->blockNumber = blockNumber;
        newBlock->nextBlock = NULL;

        if (file->lastBlock == NULL) {
            file->firstBlock = newBlock;
            file->lastBlock = newBlock;
        } else {
            file->lastBlock->nextBlock = newBlock;
            file->lastBlock = newBlock;
        }

        fs->blockCount++;
        printf("Block %d added to file '%s'.\n", blockNumber, name);
    } else {
        printf("File not found.\n");
    }
}
void displayFileStructure(struct FileSystem* fs, const char* name) {
    struct File* file = NULL;
    for (int i = 0; i < fs->fileCount; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            file = &fs->files[i];
            break;
        }
    }

    if (file != NULL) {
        printf("Structure of file '%s':\n", name);
        struct Block* currentBlock = file->firstBlock;
        while (currentBlock != NULL) {
            printf("Block %d -> ", currentBlock->blockNumber);
            currentBlock = currentBlock->nextBlock;
        }
        printf("End\n");
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
    displayFileStructure(&myFileSystem, "file1");
    displayFileStructure(&myFileSystem, "file2");

    return 0;
}

