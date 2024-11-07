#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_USERS 10
#define CREDENTIAL_LENGTH 30

typedef struct {
    char username[CREDENTIAL_LENGTH];
    char password[CREDENTIAL_LENGTH];
} User;

User users[MAX_USERS];
int user_count = 0;

void register_user();
int login_user();
void fix_fgets_input(char *);
void input_credentials(char *, char *);

int main(int argc, char const *argv[])
{
    while (1) {
        printf("\nWelcome to User Management");
        printf("\n1. Register");
        printf("\n2. Login");
        printf("\n3. Exit");

        int option;
        printf("\nSelect an option: ");
        scanf("%d", &option);
        getchar(); // consume extra enter

        switch (option) {
            case 1:
                register_user();
                break;
            case 2:
                int user_index = login_user();
                if (user_index >= 0) {
                    printf("\nLogin successful. Welcome, %s!\n", users[user_index].username);
                } else {
                    printf("\nLogin failed!!! Incorrect username or password\n");
                }
                break;
            case 3:
                printf("\nExiting Program.\n");
                return 0;
                break;
            default:
                printf("\nInvalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}


void register_user() {
    if (user_count == MAX_USERS) {
        printf("\nMaximum registration limit reached\n");
        return;
    }

    int new_index = user_count;
    printf("\nRegister a new user\n");
    input_credentials(users[new_index].username, users[new_index].password);
    user_count++;
    printf("\nRegistration Successful\n");
}

int login_user() {
    char username[CREDENTIAL_LENGTH];
    char password[CREDENTIAL_LENGTH];
    input_credentials(username, password);

    for (int i = 0; i < user_count; i++) {
        if (
            strcmp(users[i].username, username) == 0 &&
            strcmp(users[i].password, password) == 0
        ) {
            return i;
        }
    }
    return -1;
}

void fix_fgets_input(char *string) {
    int index = strcspn(string, "\n");
    string[index] = '\0';
}

void input_credentials(char *username, char *password) {
    printf("Enter username: ");
    fgets(username, CREDENTIAL_LENGTH, stdin);
    fix_fgets_input(username);
    printf("Enter password: ");
    fgets(password, CREDENTIAL_LENGTH, stdin);
    fix_fgets_input(password);
}