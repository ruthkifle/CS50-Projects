#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for input
    long numbers;
    do
    {
        numbers = get_long("Number: ");
    }
    while (numbers < 0);

    int len = 0;
    long tempcard = numbers;

    // Check for card length and starting digit
    do
    {
        len++;
        tempcard /= 10;
    }
    while (tempcard > 0);

    if (len != 13 && len != 15 && len != 16)
    {
        printf("INVALID\n");
        return 0;
    }
    // Calculate checksum
    int sum1 = 0, sum2 = 0, total = 0;
    long set1, set2, num1, num2;
    tempcard = numbers;
    do
    {
        set1 = tempcard % 10;
        sum1 += set1;
        tempcard /= 10;

        set2 = tempcard % 10;
        set2 *= 2;
        num1 = set2 / 10;
        num2 = set2 % 10;
        sum2 = sum2 + num1 + num2;

        tempcard /= 10;
    }
    while (tempcard > 0);
    total = sum1 + sum2;

    // Print AMEX(15), MASTERCARD(16), VISA(13, 16), or INVALID.
    if (total % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    else
    {
        long first = numbers;
        do
        {
            first /= 10;
        }
        while (first >= 100);

        if ((len == 13 || len == 16) && (first / 10 == 4))
        {
            printf("VISA\n");
        }
        else if (len == 15 && (first == 34 || first == 37))
        {
            printf("AMEX\n");
        }
        else if (len == 16 && (first > 50 && first < 56))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
            return 0;
        }
    }
}
