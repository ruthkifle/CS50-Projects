#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int compute_score(string word);
int main(void)
{

    // ask for user two input
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    // mark the winner
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
}
// compure their score
int compute_score(string word)
{
    int sum = 0;
    for (int i = 0; i <= strlen(word); i++)
    {
        if (isupper(word[i]))
        {
            sum = sum + points[word[i] - 65];
        }
        if (islower(word[i]))
        {
            sum = sum + points[word[i] - 97];
        }
    }
    return sum;
}
