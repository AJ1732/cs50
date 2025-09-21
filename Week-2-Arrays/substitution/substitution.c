#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool validate_key(string key);

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];
    if (!validate_key(key))
    {
        printf("Key must be 26 letters, containing each letter exactly once.\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i];

        if (isalpha(c))
        {

            if (isupper(c))
            {

                int index = c - 'A';

                printf("%c", toupper(key[index]));
            }
            else
            {
                int index = c - 'a';
                printf("%c", tolower(key[index]));
            }
        }
        else
        {
            printf("%c", c);
        }
    }

    printf("\n");
    return 0;
}

bool validate_key(string key)
{
    if (strlen(key) != 26)
    {
        return false;
    }

    int freq[26] = {0};

    for (int i = 0; i < 26; i++)
    {
        char c = key[i];

        if (!isalpha(c))
        {
            return false;
        }

        c = toupper(c);

        int index = c - 'A';

        if (freq[index] > 0)
        {
            return false;
        }
        freq[index]++;
    }

    return true;
}
