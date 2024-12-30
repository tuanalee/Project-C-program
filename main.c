
#include <stdio.h>
#include <string.h>
#include "functions.h"

void adminMenu(struct User users[], int *numUsers) {
    int choice;
    while (1) {
        printf("\n*** Admin Menu ***\n");
        printf("[1] Add a new User\n");
        printf("[2] Show All Users.\n");
        printf("[3] Show Details an user.\n");
        printf("[4] Lock (Unlock) an user.\n");
        printf("[5] User Guideline.\n");
        printf("[6] About Us.\n");
        printf("[0] Exit Admin Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                addUser(users, numUsers);
                break;
            case 2:
                showAllUsers(users, *numUsers);
                break;
            case 3:
                {
                    char username[30];
                    printf("Enter username to search: ");
                    fgets(username, sizeof(username), stdin);
                    username[strcspn(username, "\n")] = '\0';  
                    showUserDetails(users, *numUsers, username);
                }
                break;
            case 4:
               
                break;
            case 5:
                
                break;
            case 6:
                
                break;
            case 0:
                return;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

void userMenu(struct User users[], int numUsers) {
    int choice;
    char userId[20];
    
    printf("Enter User ID: ");
    fgets(userId, sizeof(userId), stdin);
    userId[strcspn(userId, "\n")] = '\0';  

    while (1) {
        printf("\n*** User Menu ***\n");
        printf("[1] View My Profile\n");
        printf("[2] View My Balance\n");
        printf("[0] Exit User Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                viewMyProfile(users, numUsers, userId);
                break;
            case 2:
                viewMyBalance(users, numUsers, userId);
                break;
            case 0:
                return;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

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

