#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int choice;
    double first, second;

    while (1) {
        printf("\n-------------------Welcome to the simple calculator-------------------\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Modulus\n");
        printf("6. Power\n");
        printf("7. Exit\n");
        printf("Please enter a choice: ");
        scanf("%d", &choice);

        if (choice == 7) {
            break;
        } else if (choice < 1 || choice > 7) {
            printf("Please enter a valid choice.\n");
            continue;
        }

        printf("Enter the first number: ");
        scanf("%lf", &first);
        printf("Enter the second number: ");
        scanf("%lf", &second);

        switch (choice) {
            case 1:
                printf("%.2lf + %.2lf = %.2lf\n", first, second, first + second);
                break;
            case 2:
                printf("%.2lf - %.2lf = %.2lf\n", first, second, first - second);
                break;
            case 3:
                printf("%.2lf x %.2lf = %.2lf\n", first, second, first * second);
                break;
            case 4:
                if (second == 0) {
                    fprintf(stderr, "Can't divide by zero\n");
                } else {
                    printf("%.2lf / %.2lf = %.2lf\n", first, second, first / second);
                }
                break;
            case 5:
            if (second == 0) {
                    fprintf(stderr, "Can't divide by zero\n");
                } else {
                    printf("%.2lf modulo %.2lf = %.2lf\n", first, second, (int)first % (int)second);
                }
                break;
            case 6:
                printf("%.2lf to the power %.2lf = %.2lf\n", first, second, pow(first, second));
                break;
            default:
                printf("Please enter a valid choice.\n");
                break;
        }
    }

    printf("\nThanks for using the simple calculator");

    return 0;
}
