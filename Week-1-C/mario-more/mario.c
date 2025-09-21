#include <cs50.h>
#include <stdio.h>

void print_chars(int condition, char ch);

int main(void)
{
    int height;

    // Executes the prompt at least, and returns a height value between 1 and 8 inclusive.
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    for (int i = 0; i < height; i++)
    {
        int space;

        // Print the before spaces starting from height - 1.
        for (space = height - 1; space > i; space--)
        {
            printf(" ");
        }

        print_chars(space, '#');

        // Print the Gaps inbetween the right angled pyramids
        int gaps = 1;
        print_chars(gaps, ' ');

        print_chars(i, '#');

        printf("\n");
    }
}

// Reusable function to print chars
void print_chars(int condition, char ch)
{
    for (int i = 0; i <= condition; i++)
    {
        printf("%c", ch);
    }
}
