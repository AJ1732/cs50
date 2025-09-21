#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int changeOwed;
    do
    {
        changeOwed = get_int("Change owed: ");
    }
    while (changeOwed <= 0);

    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;

    // Initialize change coin variables to zero
    int quarters = 0, dimes = 0, nickels = 0, pennies = 0;

    while (changeOwed >= quarter)
    {
        quarters++;
        changeOwed -= quarter;
    }

    while (changeOwed >= dime)
    {
        dimes++;
        changeOwed -= dime;
    }

    while (changeOwed >= nickel)
    {
        nickels++;
        changeOwed -= nickel;
    }

    while (changeOwed >= penny)
    {
        pennies++;
        changeOwed -= penny;
    }

    printf("Quarter: %i\n", quarters);
    printf("Dime: %i\n", dimes);
    printf("Nickel: %i\n", nickels);
    printf("Penny: %i\n", pennies);
    printf("Changed owed: %i\n", changeOwed);
    printf("Coins: %i\n", quarters + dimes + nickels + pennies);
}
