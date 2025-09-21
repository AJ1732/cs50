#include <cs50.h>
#include <stdio.h>

int count_digits(long n);
int first_digit(long n);
int first_two_digits(long n);
bool has_n_digits(long n, int count);
bool checksum(long n);
string card_type(long n);

int main(void)
{
    long card_number = get_long("Card number: ");

    if (checksum(card_number))
    {
        printf("%s\n", card_type(card_number));
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}

int count_digits(long n)
{
    int count = 0;

    while (n != 0)
    {
        n /= 10;
        count++;
    }

    return count;
}

int first_digit(long n)
{
    while (n >= 10)
    {
        n /= 10;
    }

    return (int) n;
}

int first_two_digits(long n)
{
    while (n >= 100)
    {
        n /= 10;
    }

    return (int) n;
}

bool has_n_digits(long n, int count)
{
    return count_digits(n) == count;
}

bool checksum(long n)
{
    int sum = 0;
    int position = 0;

    while (n > 0)
    {
        int digit = n % 10;

        if (position % 2 == 1)
        {
            int product = digit * 2;

            if (product > 9)
            {
                sum += (product % 10) + (product / 10);
            }
            else
            {
                sum += product;
            }
        }

        else
        {
            sum += digit;
        }

        n /= 10;
        position++;
    }

    return (sum % 10 == 0);
}

string card_type(long n)
{
    int fd = first_digit(n);
    int ftd = first_two_digits(n);

    if (fd == 4 && (has_n_digits(n, 13) || has_n_digits(n, 16)))
    {
        return "VISA";
    }

    if ((ftd == 34 || ftd == 37) && (has_n_digits(n, 15)))
    {
        return "AMEX";
    }

    if ((ftd >= 51 && ftd <= 55) && (has_n_digits(n, 16)))
    {
        return "MASTERCARD";
    }

    return "INVALID";
}
