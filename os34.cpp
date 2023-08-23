#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 100

struct Record {
    int id;
    char data[256]; 
};
struct File {
    struct Record records[MAX_RECORDS];
    int currentRecord; 
};
void initFile(struct File* file) {
    file->currentRecord = 0;
}
void addRecord(struct File* file, int id, const char* data) {
    if (file->currentRecord < MAX_RECORDS) {
        file->records[file->currentRecord].id = id;
        (file->records[file->currentRecord].data, data);
        file->currentRecord++;
    } else {
        printf("File is full. Cannot add more records.\n");
    }
}
void readRecords(struct File* file) {
    if (file->currentRecord == 0) {
        printf("File is empty. No records to read.\n");
        return;
    }

    printf("Records in the file:\n");
    for (int i = 0; i < file->currentRecord; i++) {
        printf("Record ID: %d\n", file->records[i].id);
        printf("Data: %s\n", file->records[i].data);
        printf("----------------------------\n");
    }
}
int main() {
    struct File myFile;
    initFile(&myFile);
    addRecord(&myFile, 1, "Data for Record 1");
    addRecord(&myFile, 2, "Data for Record 2");
    addRecord(&myFile, 3, "Data for Record 3");
    readRecords(&myFile);
    return 0;
}

