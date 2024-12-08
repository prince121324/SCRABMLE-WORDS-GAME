#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Function to shuffle a word
void shuffleWord(char *word, char *shuffled) {
    int len = strlen(word);
    int used[len];
    for (int i = 0; i < len; i++) {
        used[i] = 0; // Initialize the used array
    }

    int index = 0;
    while (index < len) {
        int randomIndex = rand() % len;
        if (!used[randomIndex]) {
            shuffled[index++] = word[randomIndex];
            used[randomIndex] = 1;
        }
    }
    shuffled[len] = '\0';
}

int main() {
    // List of possible words to be guessed
    char *words[] = {"programming", "computer", "language", "developer", "challenge"};
    int numWords = sizeof(words) / sizeof(words[0]); // Number of words in the list
    char shuffled[20], guess[20];
    int attempts = 3; // Number of attempts
    srand(time(0)); // Seed for random number generation

    // Select a random word from the list
    char *word = words[rand() % numWords];

    shuffleWord(word, shuffled);
    printf("Word Scramble Game!\n");
    printf("Unscramble the word: %s\n", shuffled);

    // Allow user to try 3 times
    while (attempts > 0) {
        printf("You have %d attempt(s) left. Enter your guess: ", attempts);
        scanf("%s", guess);

        if (strcmp(word, guess) == 0) {
            printf("Correct! You guessed the word.\n");
            break; // Exit the loop if the guess is correct
        } else {
            attempts--; // Decrease the number of attempts
            if (attempts == 0) {
                printf("Sorry, you've run out of attempts. The correct word was: %s\n", word);
            } else {
                printf("Incorrect! Try again.\n");
            }
        }
    }

    return 0;
}
