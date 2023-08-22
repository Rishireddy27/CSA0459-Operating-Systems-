#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_EMPLOYEES 100


struct Employee {
    int id;
    char name[50];
    float salary;
};


void addEmployee(FILE *file) {
    struct Employee emp;
    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);
    printf("Enter Employee Name: ");
    scanf("%s", emp.name);
    printf("Enter Employee Salary: ");
    scanf("%f", &emp.salary);

    fseek(file, (emp.id - 1) * sizeof(struct Employee), SEEK_SET);
    fwrite(&emp, sizeof(struct Employee), 1, file);

    printf("Employee added successfully.\n");
}


void getEmployee(FILE *file) {
    struct Employee emp;
    int id;
    printf("Enter Employee ID to retrieve: ");
    scanf("%d", &id);

    fseek(file, (id - 1) * sizeof(struct Employee), SEEK_SET);
    fread(&emp, sizeof(struct Employee), 1, file);

    if (emp.id != 0) {
        printf("Employee ID: %d\n", emp.id);
        printf("Employee Name: %s\n", emp.name);
        printf("Employee Salary: %.2f\n", emp.salary);
    } else {
        printf("Employee with ID %d not found.\n", id);
    }
}


void updateEmployee(FILE *file) {
    struct Employee emp;
    int id;
    printf("Enter Employee ID to update: ");
    scanf("%d", &id);

    fseek(file, (id - 1) * sizeof(struct Employee), SEEK_SET);
    fread(&emp, sizeof(struct Employee), 1, file);

    if (emp.id != 0) {
        printf("Enter updated Employee Name: ");
        scanf("%s", emp.name);
        printf("Enter updated Employee Salary: ");
        scanf("%f", &emp.salary);

        fseek(file, (id - 1) * sizeof(struct Employee), SEEK_SET);
        fwrite(&emp, sizeof(struct Employee), 1, file);

        printf("Employee updated successfully.\n");
    } else {
        printf("Employee with ID %d not found.\n", id);
    }
}


void deleteEmployee(FILE *file) {
    struct Employee emp;
    int id;
    printf("Enter Employee ID to delete: ");
    scanf("%d", &id);

    fseek(file, (id - 1) * sizeof(struct Employee), SEEK_SET);
    fread(&emp, sizeof(struct Employee), 1, file);

    if (emp.id != 0) {
        emp.id = 0; 
        fseek(file, (id - 1) * sizeof(struct Employee), SEEK_SET);
        fwrite(&emp, sizeof(struct Employee), 1, file);

        printf("Employee deleted successfully.\n");
    } else {
        printf("Employee with ID %d not found.\n", id);
    }
}

int main() {
    FILE *file;
    file = fopen("employee.dat", "r+");

    if (file == NULL) {
        printf("File not found. Creating a new file.\n");
        file = fopen("employee.dat", "w+");
    }

    if (file == NULL) {
        printf("Error creating/opening the file.\n");
        return 1;
    }

    int choice;
    while (1) {
        printf("\nEmployee Record System\n");
        printf("1. Add Employee\n");
        printf("2. Get Employee\n");
        printf("3. Update Employee\n");
        printf("4. Delete Employee\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(file);
                break;
            case 2:
                getEmployee(file);
                break;
            case 3:
                updateEmployee(file);
                break;
            case 4:
                deleteEmployee(file);
                break;
            case 5:
                fclose(file);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

