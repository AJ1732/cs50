#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    // Executes the prompt at least once, and returns a height value between 1 and 8 inclusive.
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    for (int i = 0; i < height; i++)
    {
        int space;

        // Print the spaces starting from height - 1.
        for (space = height - 1; space > i; space--)
        {
            printf(" ");
        }

        // Print the hash col, as it less than or equal to the available space.
        for (int col = 0; col <= space; col++)
        {
            printf("#");
        }
        // Goes to the next row (line), for the next loop
        printf("\n");
    }
}
