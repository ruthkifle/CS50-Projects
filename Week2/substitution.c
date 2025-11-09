#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // validate key
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (isalpha(argv[1][i]) == 0)
        {
            printf("Key must only contain alphabetic characters/n");
            return 1;
        }
        for (int j = i + 1; j < n; j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                printf("Key must not contain repeated characters\n");
                return 1;
            }
        }
    }
    // get the key

    string key = argv[1];
    // get plaintext
    string plain = get_string("Plaintext: ");
    // print ciphertext
    printf("ciphertext: ");

    // encipher
    for (int i = 0, m = strlen(plain); i < m; i++)
    {
        if (isalpha(plain[i]))
        {
            if (isupper(plain[i]))
            {
                printf("%c", toupper(key[plain[i] - 65]));
            }
            else
            {
                printf("%c", tolower(key[plain[i] - 97]));
            }
        }
        else
        {
            printf("%c", plain[i]);
        }
    }
    printf("\n");
}
