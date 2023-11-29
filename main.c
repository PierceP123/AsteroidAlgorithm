/* 
Pierce Purcell
R00221276
Assignment 1
C Programming 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

// defines const value max_guesses to 6 guesses (can be changed to more guesses)
#define MAX_GUESSES  6

int main() {
    
    char play_again;
    do {
        
        char word_list[DICT_SIZE][WORD_SIZE+1];
        load_word_list(word_list);
        
        // random number generator with time set to now
        srand(time(NULL)); 
        int word_index = rand() % DICT_SIZE;
        char word[WORD_SIZE+1];
        
        int i;
        for (i = 0; i < WORD_SIZE && word_list[word_index][i] != '\0'; i++) {
            word[i] = word_list[word_index][i];
            }
         
        // add null terminator at the end  
        word[i] = '\0';
        // make sure word is null-terminated
        word[WORD_SIZE] = '\0';
        
        
        printf("***** Word Guessing Simulator! *****\n");
        printf("\n");
        printf("Please guess the word (length %d): ", WORD_SIZE);
        
        // declares array guess_word with the size of WORD_SIZE +1
        char guess_word[WORD_SIZE+1]; 
            for (int i = 0; i < WORD_SIZE; i++) {
            guess_word[i] = '_'; 
        }
            // sets last word to null terminator
            guess_word[WORD_SIZE] = '\0'; 

            char full_guess_word[WORD_SIZE+1];
            fgets(full_guess_word, WORD_SIZE+1, stdin); 
        
        // initilise guesses to 0
        int guesses = 0;
        
        // loop to get characters from the user
        while (guesses < MAX_GUESSES) {
            printf("Current word: %s\n", guess_word);
            printf("\nYou have %d guesses left.\n", MAX_GUESSES - guesses);
            printf("\nGuess a character in the word: ");
            char guess_char;
            scanf(" %c", &guess_char);

        // loop to iterate through each character of word of a fixed size
        int correct_letters = 0;
        for (int i = 0; i < WORD_SIZE; i++) {
            if (guess_char == word[i]) {
                guess_word[i] = guess_char;
                correct_letters++;
            }
        }
        
        // checks if correct letters is still at 0
        if (correct_letters == 0) {
            printf("\nIncorrect, '%c' is not in the word.\n", guess_char);
        } else {
            printf("\nGood guess! '%c' appears %d time(s) in the word.\n", guess_char, correct_letters);
        }
    
        // loop that prints out correctly guessed letters
        printf("\nCorrectly guessed letters: ");
        for (int i = 0; i < WORD_SIZE; i++) {
            if (guess_word[i] != '_') {
                printf("%c ", guess_word[i]);
            }
        }
            printf("\n");
            guesses++;
        }
        
        // prints out the word that was being guessed
        printf("\n***** The word was %s! *****\n", word);
        
        // promting the user if they would like to play again reading input with scanf
        printf("\nDo you want to play again? (y/n) ");
        scanf(" %c", &play_again);
        }
    
    // part of the do while loop which asks the user if they would like to play again if 'y' will begin the loop again
    while(play_again == 'y' || play_again == 'Y');
        printf("\nThank you for playing Word Guess Simulator!");

    return 0;
}



