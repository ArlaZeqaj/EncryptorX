#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int isPrime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int totient(int p, int q)
{
    return (p - 1) * (q - 1);
}

int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    return gcd(b % a, a);
}

int public_key(int lambda_n)
{
    for (int i = 2; i < lambda_n; i++)
    {
        if (gcd(i, lambda_n) == 1)
        {
            return i;
        }
    }
    return -1;
}

int main(void)
{
    system("COLOR 02");
    int p = 7, q = 19, lambda_n, P, Q, lambda_N;
    long n, e, d, N;
    printf("\n\
         _______  _        _______  _______           _______ _________ _______  _______             \n\
        (  ____ \\( (    /|(  ____ \\(  ____ )|\\     /|(  ____ )\\__   __/(  ___  )(  ____ )  |\\     /| \n\
        | (    \\/|  \\  ( || (    \\/| (    )|( \\   / )| (    )|   ) (   | (   ) || (    )|  ( \\   / ) \n\
        | (__    |   \\ | || |      | (____)| \\ (_) / | (____)|   | |   | |   | || (____)|   \\ (_) /  \n\
        |  __)   | (\\ \\) || |      |     __)  \\   /  |  _____)   | |   | |   | ||     __)    ) _ (   \n\
        | (      | | \\   || |      | (\\ (      ) (   | (         | |   | |   | || (\\ (      / ( ) \\ \n\
        | (____/\\| )  \\  || (____/\\| ) \\ \\__   | |   | )         | |   | (___) || ) \\ \\__  ( /   \\ ) \n\
        (_______/|/    )_)(_______/|/   \\__/   \\_/   |/          )_(   (_______)|/   \\__/  |/     \\| \n\
           ");
        printf("\n                           \t\t         MAIN MENU\n\
                                         ~~~~~~~~~~~~~~~~~~~~~~~~~\n\
                                          1-Generate a public key \n\
                                          2-Encrypt a message     \n\
                                          3-Decrypt a message     \n\
                                          4-Encrypt a sentence    \n\
                                          5-Decrypt a sentence    \n\
                                          6-Encrypt a text file   \n\
                                          (7-TESTING)             \n\
                                         ~~~~~~~~~~~~~~~~~~~~~~~~~");

    while (1)
    {
        printf("\n\n\t~CHOOSE BETWEEN 1-7 (0 to stop): ");
        char input[10];
        scanf("%s", input);

        // Convert the input string to an integer using sscanf
        int number;
        if (sscanf(input, "%d", &number) != 1)
        {
            printf("\n\t~Invalid input. Please enter a number between 1 and 7.\n");
            continue; // Restart the loop
        }

        if (number == 0)
        {
            printf("\n\tExiting program...\n");
            break;
        }
        else if (number == 1)
        {
            while (1)
            {
                printf("\n\t~Enter the value of p (prime number): ");
                scanf("%d", &P);
                printf("\n\t~Enter the value of q (prime number): ");
                scanf("%d", &Q);
                N = P * Q;
                lambda_N = totient(P, Q);

                if (!isPrime(P) && !isPrime(Q))
                {
                    printf("\n\t~~~THE VALUE OF p AND q SHOULD BE PRIME\n");
                }
                else if (!isPrime(P))
                {
                    printf("\n\t~~~THE VALUE OF p SHOULD BE PRIME\n");
                }
                else if (!isPrime(Q))
                {
                    printf("\n\t~~~THE VALUE OF q SHOULD BE PRIME\n");
                }
                else
                {
                    int key = public_key(lambda_N);
                    printf("\n\t~~~THE PUBLIC KEY IS (d, n): %d, %ld\n", key, N);
                    break;
                }
            }
        }
        else
        {
            printf("\n\t~Invalid input. Please enter a number between 1 and 7.\n");
        }
    }

    return 0;
}

