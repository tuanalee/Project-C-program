
#include <stdio.h>
#include <string.h>
#include "functions.h"

int main() {
    struct User users[20];
    int numUsers = 0;  
    int choice;

    while (1) {
        printf("\n*** Bank Management System ***\n");
        printf("[1] Admin\n");
        printf("[2] User\n");
        printf("[0] Exit the Program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                adminMenu(users, &numUsers);
                break;
            case 2:
                userMenu(users, numUsers);
                break;
            case 0:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

