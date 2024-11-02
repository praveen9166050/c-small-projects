#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    int random, guess;
    int num_of_guesses = 0;

    srand(time(NULL));
    random = rand() % 100 + 1;
    do {
        printf("Enter a number between 1 and 100: ");
        scanf("%d", &guess);
        num_of_guesses++;
        if (guess < random) {
            printf("Your guess is smaller than the random number\n");
        } else if (guess > random) {
            printf("Your guess is greater than the random number\n");
        } else {
            printf("Congratulations, you have perfectly guessed the number!!!");
            printf("\nYou took %d number of attempts.", num_of_guesses);
        }
    } while (guess != random);
    
    printf("\nThanks for playing the game");

    return 0;
}
