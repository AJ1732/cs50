#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);
char rotate(char c, int key);

int main(int argc, string argv[])
{
    // 1. Check number of command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // 2. Check that argv[1] contains only digits
    if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // 3. Convert argv[1] to an integer (the key)
    int key = atoi(argv[1]);

    // 4. Prompt user for plaintext
    string plaintext = get_string("plaintext: ");

    // 5. Print the "ciphertext: " label
    printf("ciphertext: ");

    // 6. For each character in the plaintext, rotate and print
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char rotated_char = rotate(plaintext[i], key);
        printf("%c", rotated_char);
    }

    // Print a newline after printing the ciphertext
    printf("\n");

    // 7. Return 0 to indicate success
    return 0;
}

bool only_digits(string s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

// Rotates character c by key positions if it is alphabetical,
// preserving case. Non-alphabetical characters are returned unchanged.

char rotate(char c, int key)
{
    // Only rotate alphabetical characters
    if (isalpha(c))
    {
        // Handle uppercase letters
        if (isupper(c))
        {
            // Convert 'A' to 0, rotate, then convert back
            return (char) (((c - 'A') + key) % 26 + 'A');
        }
        // Handle lowercase letters
        else
        {
            // Convert 'a' to 0, rotate, then convert back
            return (char) (((c - 'a') + key) % 26 + 'a');
        }
    }
    else
    {
        // Non-alphabetical characters remain unchanged
        return c;
    }
}
