#include <stdio.h>

int main() {
    int math, science, total;
    char name[50];
    char choice;

    do {
        printf("\nEnter Student Name: ");
        scanf("%s", name);

        printf("Enter Math (1 for yes, 0 for no): ");
        scanf("%d", &math);

        printf("Enter Science (1 for yes, 0 for no): ");
        scanf("%d", &science);

        if (math == 1 && science == 1) {
            total = 45;
        }
        else if (math == 1) {
            total = 30;
        }
        else if (science == 1) {
            total = 20;
        }
        else {
            total = 0;
        }

        printf("\nStudent: %s\n", name);
        printf("Total Marks = %d\n", total);

        
        if (total >= 40)
            printf("Grade: A\n");
        else if (total >= 25)
            printf("Grade: B\n");
        else if (total > 0)
            printf("Grade: C\n");
        else
            printf("Grade: Fail\n");

        printf("\nDo you want to enter another student? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    return 0;
}