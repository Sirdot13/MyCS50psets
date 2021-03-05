#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    string key = argv[1];
    int validate = 0;
    int count[26] = {0};
    // Validating key

    if (argc!=2) //Usage
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (strlen(key) != 26) //Length
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for (int i = 0, len = strlen(key); i < len; i++) //Character check
    {
        if (!isalpha(key[i]))
        {
        printf ("Key must only contain alphabetic characters\n");
        return 1;
        }
    }
    for (int i = 0, len = strlen(key) - 1; i < len; i++)
    {
    for (int j = i + 1; j < strlen(key); j++)
    {
     if (key[i] == key[j])
     {
         printf("Key must not contain duplicate characters.\n");
         return 1;
     }
    }
    }
    string plain = get_string("plaintext: "); // Get plaintext

    string diff = argv[1]; //Variable declaration

    for (int i = 'A'; i <= 'Z'; i++) //Creating the cipher difference

            diff[i - 'A'] = toupper(diff[i - 'A']) - i;

    printf("ciphertext: ");

    for (int i = 0, len = strlen(plain); i < len; i++) //Printing out the plaintext enciphered
    {
        if (isalpha(plain[i]))

        plain [i] = plain[i] + diff[plain[i] - (isupper(plain[i]) ? 'A' : 'a')];

        printf("%c", plain[i]);
    }

    printf("\n");
    return 0;
}
