#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

//  assign points to each letter of the alphabet, alphabetically
int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Function to calculate the score of a word
int compute_score(char word[])
{
    int score = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        char c = toupper(word[i]);

        // Check if the character is a letter
        if (c >= 'A' && c <= 'Z')
        {
            // Calculate the score by finding the position in the points array
            score += points[c - 'A'];
        }
    }
    return score;
}

int main(void)
{
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    return 0;
}
