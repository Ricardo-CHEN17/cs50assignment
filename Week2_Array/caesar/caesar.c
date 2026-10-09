#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit((unsigned char) argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]) % 26;
    string plaintext = get_string("plaintext:  ");
    printf("ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++)
    {
        char c = plaintext[i];

        if (isupper((unsigned char) c))
        {
            printf("%c", 'A' + (c - 'A' + key) % 26);
        }
        else if (islower((unsigned char) c))
        {
            printf("%c", 'a' + (c - 'a' + key) % 26);
        }
        else
        {
            printf("%c", c);
        }
    }

    printf("\n");

    return 0;
}
