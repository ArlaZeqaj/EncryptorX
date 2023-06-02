#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    system("COLOR 02");
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
        else
        {
            printf("\n\t~Invalid input. Please enter a number between 1 and 7.\n");
        }
    }

    return 0;
}

