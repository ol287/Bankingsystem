#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pass {
    char username[50];
    char fname[20];
    char lname[20];
    char address[50];
    char typeaccount[20];
    int date, month, year;
};

struct money {
    char usernameto[50];
    long int money1;
};

void accountcreated(void);
void login(void);
void display(char*);
void checkbalance(char*);
void transfermoney(void);
void logout(void);

int main() {
    int choice;

    printf("BANK ACCOUNT SYSTEM\n");
    printf("1. CREATE A BANK ACCOUNT\n");
    printf("2. ALREADY A USER? SIGN IN\n");
    printf("3. EXIT\n");
    printf("ENTER YOUR CHOICE: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        accountcreated();
        break;
    case 2:
        login();
        break;
    case 3:
        exit(0);
        break;
    }
    return 0;
}

void accountcreated(void) {
    struct pass u1;
    char password[50];
    FILE *fp;

    printf("CREATE ACCOUNT\n");
    printf("Enter first name: ");
    scanf("%s", u1.fname);
    printf("Enter last name: ");
    scanf("%s", u1.lname);
    printf("Enter username: ");
    scanf("%s", u1.username);
    printf("Enter password: ");
    scanf("%s", password);  // Basic input, not secure for real use
    printf("Enter address: ");
    scanf("%s", u1.address);
    printf("Enter account type: ");
    scanf("%s", u1.typeaccount);
    printf("Enter birth date (DD MM YYYY): ");
    scanf("%d %d %d", &u1.date, &u1.month, &u1.year);

    fp = fopen("username.txt", "ab");
    if (fp != NULL) {
        fwrite(&u1, sizeof(struct pass), 1, fp);
        fclose(fp);
    } else {
        printf("Failed to open the file!\n");
    }

    printf("Account created successfully. Press enter to login\n");
    while (getchar() != '\n'); // Flush the newline
    getchar(); // Wait for enter
    login();
}

void login(void) {
    char username[50];
    char password[50];
    struct pass u1;
    FILE *fp;
    int found = 0;

    printf("LOGIN\n");
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password); // Basic input, not secure for real use

    fp = fopen("username.txt", "rb");
    if (fp != NULL) {
        while (fread(&u1, sizeof(struct pass), 1, fp)) {
            if (strcmp(u1.username, username) == 0) {
                found = 1;
                break;
            }
        }
        fclose(fp);
    }

    if (found) {
        printf("Login successful.\n");
        display(username);
    } else {
        printf("Username or password is incorrect.\n");
    }
}

void display(char* username) {
    struct pass u1;
    FILE *fp;
    int found = 0;

    fp = fopen("username.txt", "rb");
    if (fp != NULL) {
        while (fread(&u1, sizeof(struct pass), 1, fp)) {
            if (strcmp(u1.username, username) == 0) {
                found = 1;
                break;
            }
        }
        fclose(fp);
    }

    if (found) {
        printf("Account Details:\n");
        printf("Name: %s %s\n", u1.fname, u1.lname);
        printf("Address: %s\n", u1.address);
        printf("Account Type: %s\n", u1.typeaccount);
        printf("Date of Birth: %d-%d-%d\n", u1.date, u1.month, u1.year);
    } else {
        printf("No account found with the username %s.\n", username);
    }

    int choice;
    printf("1. Check Balance\n");
    printf("2. Transfer Money\n");
    printf("3. Logout\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
        checkbalance(username);
        break;
    case 2:
        transfermoney();
        break;
    case 3:
        logout();
        break;
    }
}

void checkbalance(char* username) {
    printf("Balance function is not implemented.\n");
    display(username);
}

void transfermoney(void) {
    printf("Transfer money function is not implemented.\n");
}

void logout(void) {
    printf("Logging out...\n");
    exit(0);
}
