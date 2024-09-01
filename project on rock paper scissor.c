#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char get_computer_choice() {
    int random_choice = rand() % 3; // Generates a random number between 0 and 2

    switch (random_choice) {
        case 0: return 'R'; // Rock
        case 1: return 'P'; // Paper
        case 2: return 'S'; // Scissors
    }
    return 'R'; // Default to Rock
}

void determine_winner(char player_choice, char computer_choice) {
    if (player_choice == computer_choice) {
        printf("It's a tie! Both chose %c\n", player_choice);
    } else if ((player_choice == 'R' && computer_choice == 'S') ||
               (player_choice == 'P' && computer_choice == 'R') ||
               (player_choice == 'S' && computer_choice == 'P')) {
        printf("You win! %c beats %c\n", player_choice, computer_choice);
    } else {
        printf("You lose! %c beats %c\n", computer_choice, player_choice);
    }
}

int main() {
    char player_choice, computer_choice;
    
    srand(time(0));

    printf("Enter your choice (R for Rock, P for Paper, S for Scissors): ");
    scanf(" %c", &player_choice);

    computer_choice = get_computer_choice();

    printf("You chose: %c\n", player_choice);
    printf("Computer chose: %c\n", computer_choice);

    determine_winner(player_choice, computer_choice);

    return 0;
}
