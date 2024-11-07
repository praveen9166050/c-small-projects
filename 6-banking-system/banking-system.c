#include <stdio.h>
#include <string.h>

void create_account();
void deposit_money();
void withdraw_money();
void check_balance();

const char *ACCOUNT_FILE = "acount.dat";

typedef struct {
    char name[50];
    int acc_no;
    float balance;
} Account;

int main(int argc, char const *argv[])
{
    while (1) {
        printf("\n***Bank Management System***");
        printf("\n1. Create Account");
        printf("\n2. Deposit Money");
        printf("\n3. Withdraw Money");
        printf("\n4. Check Balance");
        printf("\n5. Exit");

        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_account();
                break;
            case 2:
                deposit_money();
                break;
            case 3:
                withdraw_money();
                break;
            case 4:
                check_balance();
                break;
            case 5:
                printf("\nExiting the bank, thanks for your visit.\n");
                return 0;
                break;
            default:
                printf("Invalid choice!");
                break;
        }
    }
    return 0;
}

void create_account() {
    Account acc;
    FILE *file = fopen(ACCOUNT_FILE, "ab+");
    if (file == NULL) {
        printf("\nUnable to open file!!");
        return;
    }

    char c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);

    printf("\nEnter your name: ");
    fgets(acc.name, sizeof(acc.name), stdin);
    int index = strcspn(acc.name, "\n");
    acc.name[index] = '\0';
    printf("Enter your account number: ");
    scanf("%d", &acc.acc_no);
    acc.balance = 0;

    fwrite(&acc, sizeof(acc), 1, file);
    fclose(file);
    printf("\nAccount created successfully!!!");
}

void deposit_money() {
    FILE *file = fopen(ACCOUNT_FILE, "rb+");
    if (file == NULL) {
        printf("\nUnable to open file!!");
        return;
    }

    Account acc_to_read;
    int acc_no;
    float money;
    printf("Enter your account number: ");
    scanf("%d", &acc_no);
    printf("Enter the amount to deposit: ");
    scanf("%f", &money);

    while (fread(&acc_to_read, sizeof(acc_to_read), 1, file)) {
        if (acc_to_read.acc_no == acc_no) {
            acc_to_read.balance += money;
            fseek(file, -sizeof(acc_to_read), SEEK_CUR);
            fwrite(&acc_to_read, sizeof(acc_to_read), 1, file);
            fclose(file);
            printf("Successfully deposited %.2f. New balance is %.2f.", money, acc_to_read.balance);
            return;
        }
    }

    fclose(file);
    printf("Money could not be deposited as the account number %d was not found.", acc_no);
}

void withdraw_money() {
    FILE *file = fopen(ACCOUNT_FILE, "rb+");
    if (file == NULL) {
        printf("\nUnable to open file!!");
        return;
    }

    Account acc_to_read;
    int acc_no;
    float money;
    printf("Enter your account number: ");
    scanf("%d", &acc_no);
    printf("Enter the amount to withdraw: ");
    scanf("%f", &money);

    while (fread(&acc_to_read, sizeof(acc_to_read), 1, file)) {
        if (acc_to_read.acc_no == acc_no) {
            if (acc_to_read.balance >= money) {
                acc_to_read.balance -= money;
                fseek(file, -sizeof(acc_to_read), SEEK_CUR);
                fwrite(&acc_to_read, sizeof(acc_to_read), 1, file);
                printf("Successfully withdrawn %.2f. New balance is %.2f.", money, acc_to_read.balance);
            } else {
                printf("Insufficient balance!!!");
            }
            fclose(file);
            return;
        }
    }

    fclose(file);
    printf("Money could not be withdrawn as the account number %d was not found.", acc_no);
}

void check_balance() {
    FILE *file = fopen(ACCOUNT_FILE, "rb");
    if (file == NULL) {
        printf("\nUnable to open file!!");
        return;
    }
    Account acc_read;
    int acc_no;
    printf("Enter your account number: ");
    scanf("%d", &acc_no);

    while (fread(&acc_read, sizeof(acc_read), 1, file)) {
        if (acc_read.acc_no == acc_no) {
            printf("\nYour account balanace is Rs %.2f", acc_read.balance);
            fclose(file);
            return;
        }
    }
    fclose(file);
    printf("\nAccount number %d, not found.", acc_no);
}