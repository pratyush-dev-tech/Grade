#include <stdio.h>
#include <string.h>

struct book {
    int id;
    char name[50];
    char author[50];
    int issued;
};

struct book b[100];
int count = 0;


void addBook() {
    printf("\nEnter Book ID: ");
    scanf("%d", &b[count].id);

    printf("Enter Book Name: ");
    scanf(" %[^\n]", b[count].name);

    printf("Enter Author Name: ");
    scanf(" %[^\n]", b[count].author);

    b[count].issued = 0;

    count++;
    printf("✅ Book Added Successfully!\n");
}


void showBooks() {
    if (count == 0) {
        printf("\nNo books available.\n");
        return;
    }

    printf("\n--- Book List ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d\n", b[i].id);
        printf("Name: %s\n", b[i].name);
        printf("Author: %s\n", b[i].author);

        if (b[i].issued == 1)
            printf("Status: Issued\n");
        else
            printf("Status: Available\n");

        printf("-------------------\n");
    }
}



void issueBook() {
    int id, found = 0;

    printf("\nEnter Book ID to issue: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (b[i].id == id) {
            found = 1;
            if (b[i].issued == 0) {
                b[i].issued = 1;
                printf("✅ Book Issued Successfully!\n");
            } else {
                printf("❌ Book already issued!\n");
            }
            break;
        }
    }

    if (!found) {
        printf("❌ Book not found!\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n==== Library Management ====\n");
        printf("1. Add Book\n");
        printf("2. Show Books\n");
        printf("3. Issue Book\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: showBooks(); break;
            case 3: issueBook(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}