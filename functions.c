#include <stdio.h>
#include <string.h>
#include <stdlib.h>  


struct User {
    char userId[20];
    char name[20];
    char email[20];
    char phoneNumber[20];
    char gender[20];
    int day, month, year;
    char username[20];
    char password[20];
    double balance;
    char status[20];
};


void addUser(struct User users[], int *numUsers) {
    if (*numUsers >= 20) {
        printf("Error: Cannot add more users, the system is full.\n");
        return;
    }

    struct User newUser;
    printf("*** Add New User ***\n");

    
    while (1) {
        printf("Enter User ID: ");
        fgets(newUser.userId, sizeof(newUser.userId), stdin);
        newUser.userId[strcspn(newUser.userId, "\n")] = '\0';  

        if (strlen(newUser.userId) < 10) {
            printf("Error: ID cannot be less than 10 characters.\n");
        } else {
            break;
        }
    }

  
    printf("Enter Name: ");
    fgets(newUser.name, sizeof(newUser.name), stdin);
    newUser.name[strcspn(newUser.name, "\n")] = '\0';

    printf("Enter Email: ");
    fgets(newUser.email, sizeof(newUser.email), stdin);
    newUser.email[strcspn(newUser.email, "\n")] = '\0';

    printf("Enter Phone Number: ");
    fgets(newUser.phoneNumber, sizeof(newUser.phoneNumber), stdin);
    newUser.phoneNumber[strcspn(newUser.phoneNumber, "\n")] = '\0';

    
    while (1) {
        printf("Enter Gender (0 for Male, 1 for Female): ");
        fgets(newUser.gender, sizeof(newUser.gender), stdin);
        newUser.gender[strcspn(newUser.gender, "\n")] = '\0';  

        if (strcmp(newUser.gender, "0") == 0 || strcmp(newUser.gender, "1") == 0) {
            break;  
        } else {
            printf("Error: Invalid gender input. Please enter 0 for Male or 1 for Female.\n");
        }
    }

   
    printf("Enter Day of Birth: ");
    scanf("%d", &newUser.day);
    printf("Enter Month of Birth: ");
    scanf("%d", &newUser.month);
    printf("Enter Year of Birth: ");
    scanf("%d", &newUser.year);
    getchar();  

 
    printf("Enter Username: ");
    fgets(newUser.username, sizeof(newUser.username), stdin);
    newUser.username[strcspn(newUser.username, "\n")] = '\0';  

    
    strcpy(newUser.password, newUser.phoneNumber);

    
    printf("Enter Account Balance: ");
    scanf("%lf", &newUser.balance);
    getchar();  

    
    strcpy(newUser.status, "Open");

    
    users[*numUsers] = newUser;
    (*numUsers)++;

    printf("User added successfully!\n");

    
    char choice;
    printf("Go back (b)? or Exit (0)? ");
    scanf(" %c", &choice);
    getchar(); 

    if (choice == 'b' || choice == 'B') {
        return;  
    } else if (choice == '0') {
        exit(0); 
    }
}


void showAllUsers(struct User users[], int numUsers) {
    if (numUsers == 0) {
        printf("No users found.\n");
        return;
    }

    printf("\n%-15s %-20s %-30s %-15s %-10s\n", "ID", "Name", "Email", "Phone", "Status");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < numUsers; i++) {
        printf("%-15s %-20s %-30s %-15s %-10s\n", 
               users[i].userId, 
               users[i].name, 
               users[i].email, 
               users[i].phoneNumber, 
               users[i].status);
    }
    printf("\n");
}


void showUserDetails(struct User users[], int numUsers, char* userName) {
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, userName) == 0) {
            printf("\n%-15s %-20s %-30s %-15s %-10s %-20s %-15s %-15s %-10s\n", 
                   "ID", "Name", "Email", "Phone", "Status", "Gender", "Date of Birth", "Username", "Balance");
            printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n");

            printf("%-15s %-20s %-30s %-15s %-10s %-20s %02d-%02d-%d %-15s %.2f\n", 
                   users[i].userId, 
                   users[i].name, 
                   users[i].email, 
                   users[i].phoneNumber, 
                   users[i].status, 
                   users[i].gender, 
                   users[i].day, 
                   users[i].month, 
                   users[i].year, 
                   users[i].username, 
                   users[i].balance);
            return;
        }
    }
    printf("Error: User not found.\n");
}


void viewMyProfile(struct User users[], int numUsers, char userId[]) {
    printf("\n%-15s %-25s %-15s %-30s %-10s\n", "User ID", "Name", "Phone", "Email", "Status");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].userId, userId) == 0) {
            printf("%-15s %-25s %-15s %-30s %-10s\n", 
                   users[i].userId, 
                   users[i].name, 
                   users[i].phoneNumber, 
                   users[i].email, 
                   users[i].status);
            return;
        }
    }
    printf("User not found!\n");
}


void viewMyBalance(struct User users[], int numUsers, char userId[]) {
    printf("\n%-15s %-15s\n", "User ID", "Balance");
    printf("-----------------------------\n");

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].userId, userId) == 0) {
            printf("%-15s %-15.2f\n", users[i].userId, users[i].balance);
            return;
        }
    }
    printf("User not found!\n");
}

