#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ALPHABET_SIZE 150
#define MAX_LENGTH 300

char alphabet[ALPHABET_SIZE];

void createAlphabet(void)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        alphabet[i] = 'A' + i;
    }
}

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

int randome(int lambda_n)
{
    srand((unsigned int)time(NULL));
    while (1)
    {
        int num = (rand() % (lambda_n - 5 + 1)) + 5;
        if (isPrime(num) == 1)
        {
            return num;
            break;
        }
    }
    return -1;
}

long private_key(long e, int lambda_n)
{
    for (long i = 1; i < lambda_n; i++)
    {
        if ((i * e) % lambda_n == 1)
        {
            return i;
        }
    }
    return -1;
}

long pomod(long a, long b, long m)
{
    long x = 1, y = a;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x * y) % m;
        }
        y = (y * y) % m;
        b /= 2;
    }
    return x % m;
}

char* rsaEncrypt(char* message, long e, long n)
{
    createAlphabet();
    long index;
    long i;
    long len = strlen(message);
    char* cipher = (char*)malloc(len * sizeof(char));
    for (i = 0; i < len; i++)
    {
        index = pomod(message[i], e, n);
        cipher[i] = alphabet[index];
    }
    return cipher;
}

char* decrypt(char* cipher, long d, long n)
{
    createAlphabet();
    long index;
    long i;
    long len = strlen(cipher);
    char* message = (char*)malloc(len * sizeof(char));
    for (i = 0; i < len; i++)
    {
        index = 0;
        while (alphabet[index] != cipher[i])
        {
            index++;
        }
        message[i] = pomod(index, d, n);
    }
    return message;
}

// Decryption of a message
char* rsaDecrypt(char* cipher, long d, long n)
{
    createAlphabet();
    long index;
    long i;
    long len = strlen(cipher);
    char* message = (char*)malloc((len + 1) * sizeof(char)); // Include space for null terminator
    for (i = 0; i < len; i++)
    {
        if (cipher[i] == ' ')
        {
            message[i] = ' '; // Preserve space character
        }
        else
        {
            index = 0;
            while (alphabet[index] != cipher[i])
            {
                index++;
            }
            message[i] = pomod(index, d, n);
        }
    }
    message[len] = '\0'; //null terminator
    return message;
}

// Encryption of a sentence
char* RSAencrypt(char* sentence, long e, long n)
{
    createAlphabet();
    long index;
    long i;
    long len = strlen(sentence);
    char* encry = (char*)malloc((len + 1) * sizeof(char)); // Include space for null terminator
    for (i = 0; i < len; i++)
    {
        if (sentence[i] == ' ')
        {
            encry[i] = ' '; // Preserve space character
        }
        else
        {
            index = pomod(sentence[i], e, n);
            encry[i] = alphabet[index];
        }
    }
    encry[len] = '\0'; // Add null terminator to the cipher string
    return encry;
}

// Decryption of a previous sentence
char* RSAdecrypt(char* encry, long d, long n)
{
    createAlphabet();
    long index;
    long i;
    long len = strlen(encry);
    char* sentence = (char*)malloc((len + 1) * sizeof(char)); // Include space for null terminator
    for (i = 0; i < len; i++)
    {
        if (encry[i] == ' ')
        {
            sentence[i] = ' '; // Preserve space character
        }
        else
        {
            index = 0;
            while (alphabet[index] != encry[i])
            {
                index++;
            }
            sentence[i] = pomod(index, d, n);
        }
    }
    sentence[len] = '\0'; // Add null terminator to the message string
    return sentence;
}

// Decryption of a sentence
char* RSAdecryptSentence(char* encrySentence, long d, long n)
{
    createAlphabet();
    long index;
    long i;
    long len = strlen(encrySentence);
    char* sentence = (char*)malloc((len + 1) * sizeof(char)); // Include space for null terminator
    for (i = 0; i < len; i++)
    {
        if (encrySentence[i] == ' ')
        {
            sentence[i] = ' '; // Preserve space character
        }
        else
        {
            index = 0;
            while (alphabet[index] != encrySentence[i])
            {
                index++;
            }
            sentence[i] = pomod(index, d, n);
        }
    }
    sentence[len] = '\0'; // Add null terminator to the message string
    return sentence;
}

//Encryption of a sentence
char* RSAencryptFile(char* sentence, long e, long n)
{
    createAlphabet();
    long index;
    long i;
    long len = strlen(sentence);
    char* encry = (char*)malloc((len + 1) * sizeof(char)); // Include space for null terminator
    for (i = 0; i < len; i++)
    {
        if (sentence[i] == ' ')
        {
            encry[i] = ' '; // Preserve space character
        }
        else
        {
            index = pomod(sentence[i], e, n);
            encry[i] = alphabet[index];
        }
    }
    encry[len] = '\0'; // Add null terminator to the cipher string
    return encry;
}

//Getting text from file
char* readFile() {
    FILE* file = fopen("message.txt", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        exit(1);
    }

    char* text = (char*)malloc(sizeof(char) * MAX_LENGTH);
    if (fgets(text, MAX_LENGTH, file) == NULL) {
        printf("Failed to read from the file.\n");
        exit(1);
    }

    fclose(file);
    return text;
}

//Writing encrypted text to a new file
void storeSentenceInFile(const char* text) {
    FILE* file = fopen("secret.txt", "w");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }
    fprintf(file, "%s", text);
    fclose(file);
}

int main(void)
{
    system("COLOR 02");
    int p = 7, q = 19, lambda_n, P, Q, lambda_N;
    long n, e, d, N;
    char* message;
    char* mgs;
    char* text;
    char* cipher;
    char* sentence;
    char* file_text;
    char* encryptSentence;
    char* encrySentence;
    char choice[10];
    char choice1[10];
    createAlphabet();
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
        else if (number == 2)
        {
            n = p * q;
            lambda_n = totient(p, q);
            e = randome(lambda_n);
            d = private_key(e, lambda_n);
            printf("\n\tThe value of public key is %ld and modulus is %ld\n", d, n);
            message = (char*)malloc(sizeof(char) * 100);
            printf("\n\t~Enter the message: ");
            scanf("%s", message);
            cipher = rsaEncrypt(message, e, n);
            printf("\n\t~The encrypted message is: %s\n", cipher);
            printf("\n\t~~~DO YOU WISH TO DECRYPT THE MESSAGE (yes/no): "); 
            scanf("%s", choice);

            if (!strcmp(choice, "yes"))
            {
                message = decrypt(cipher, d, n);
                printf("\n\t~The original message was: %s\n", message);
            }
            else
            {
                printf("T-T\n");
            }

            free(message);
            free(cipher);
        }
        else if (number == 3)
        {
            printf("\n\t~Enter d (public key): ");
            scanf("%ld", &d);
            printf("\n\t~Enter n (modulus): ");
            scanf("%ld", &n);
            printf("\n\t~Enter the message: ");
            mgs = (char*)malloc(sizeof(char) * 100);
            scanf("%s", mgs);
            text = rsaDecrypt(mgs, d, n);
            printf("\n\t~The original message was: %s\n", text);
            free(text);
            free(mgs);
        }
        else if (number == 4)
        {
            n = p * q;
            lambda_n = totient(p, q);
            e = randome(lambda_n);
            d = private_key(e, lambda_n);
            printf("\n\tThe value of public key is %ld and modulus is %ld\n", d, n);
            sentence = (char*)malloc(sizeof(char) * 100);
            printf("\n\t~Enter the sentence: ");
            scanf(" %[^\n]s", sentence); // Read the entire line including spaces
            encryptSentence = RSAencrypt(sentence, e, n);
            printf("\n\t~The encrypted sentence is: %s\n", encryptSentence);
            printf("\n\t~~~DO YOU WISH TO DECRYPT THE SENTENCE (yes/no): ");
            scanf("%s", choice);

            if (!strcmp(choice, "yes"))
            {
                char* decryptedMessage = RSAdecrypt(encryptSentence, d, n);
                printf("\n\t~The original sentence was: %s\n", decryptedMessage);
                free(decryptedMessage);
            }
            else
            {
                printf("T-T\n");
            }

            free(sentence);
            free(encryptSentence);
        }
        else if (number == 5)
        {
            printf("\n\t~Enter d (public key): ");
            scanf("%ld", &d);
            printf("\n\t~Enter n (modulus): ");
            scanf("%ld", &n);
            printf("\n\t~Enter the sentence: ");
            encrySentence = (char*)malloc(sizeof(char) * 100);
            scanf(" %[^\n]s", encrySentence);
            char* decryptedSentence = RSAdecryptSentence(encrySentence, d, n);
            printf("\n\t~The original sentence was: %s\n", decryptedSentence);
            free(decryptedSentence);
            free(encrySentence);
        }
        else if (number == 6)
        {
            n = p * q;
            lambda_n = totient(p, q);
            e = randome(lambda_n);
            d = private_key(e, lambda_n);
            file_text = readFile();
            encryptSentence = RSAencryptFile(file_text, e, n);
            printf("\n\t~The file was encrypted successfully!\n");
            printf("\n\t~The encrypted text is: %s\n", encryptSentence);
            storeSentenceInFile(encryptSentence);
            printf("\n\t~~~DO YOU WISH TO DECRYPT THE TEXT (yes/no): ");
            scanf("%s", choice1);
            if (!strcmp(choice1, "yes"))
            {
                char* decryptedText = RSAdecrypt(encryptSentence, d, n);
                printf("\n\t~The original text was: %s\n", decryptedText);
                free(decryptedText);
            }
            else
            {
                printf("T-T\n");
            }
            free(file_text);
            free(encryptSentence);
        }
        else
        {
            printf("\n\t~Invalid input. Please enter a number between 1 and 7.\n");
        }
    }

    return 0;
}

