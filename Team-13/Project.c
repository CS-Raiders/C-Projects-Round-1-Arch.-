#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define MAX 1000
void Menu()
{
    printf("===================================================\n");
    printf(">>>\tWelcome to Number System Converter!\t<<<\n");
    printf("===================================================\n\n");
    printf("Select Conversion Type:\n");
    printf("=> 1. Binary Conversion\n=> 2. Decimal Conversion\n=> 3. Octal Conversion\n=> 4. Hexa Conversion\n=> 5. Exit\n");
}
int TryAgain(char *flag)
{
    char temp;
    do
    {
        printf("Do You Wish to Try Again? [Y/N]: ");
        scanf(" %c", flag); // using pointer to pass by reference
        temp = *flag;
        if (temp != 'N' && temp != 'n' && temp != 'Y' && temp != 'y')
            printf("Invalid Choice, Try Again!\n");
    } while (temp != 'N' && temp != 'n' && temp != 'Y' && temp != 'y');
    return 0; // showing success or failure
}
int isBinaryInput(const char *input)
{
    // checking the input char by char to avoid any errors
    while (*input)
    {
        if (!isdigit(*input) || (*input != '0' && *input != '1'))
        {
            return 0;
        }
        input++;
    }
    return 1; // Valid binary input
}
int IsBinary(int binary)
{
    while (binary > 0)
    {
        int digit = binary % 10;
        if (digit != 0 && digit != 1)
            return 0;
        binary /= 10;
    }
    return 1;
}
int binary_to_decimal(int binary)
{
    long long decimal = 0, weight = 1, rem;
    while (binary)
    {
        rem = binary % 10;
        decimal += rem * weight;
        binary = binary / 10;
        weight = weight * 2;
    }
    printf("====================================\n>>>\tConversion Results\t<<<\n====================================\n\n");
    printf("Decimal Number: %lld\n", decimal);
    return decimal;
}
int binary_to_octal(int binary)
{
    int octal = 0, weight = 1, rem;
    while (binary != 0)
    {
        rem = binary % 10;
        octal += rem * weight;
        binary = binary / 10;
        weight = weight * 2;
    }
    printf("octal Number: %o\n", octal);
    return octal;
}
int binary_to_hexadecimal(int binary)
{
    int hexa = 0, weight = 1, rem;
    while (binary != 0)
    {
        rem = binary % 10;
        hexa += rem * weight;
        binary = binary / 10;
        weight = weight * 2;
    }
    printf("hexa Number: %lX\n", hexa);
    return hexa;
}
int dec_to_bin(int num)
{
    int SizeInBits;
    unsigned int shifted;
    printf("====================================\n>>>\tConversion Results\t<<<\n====================================\n\n");
    printf("Binary Number : ", num);
    SizeInBits = 8 * sizeof(num);
    shifted = 1 << SizeInBits - 1; //(-1) to avoid become 0
    for (int i = 0; i < SizeInBits; i++)
    {
        (num & shifted) ? printf("1") : printf("0");
        shifted >>= 1;
    }
    printf("\n");
}
int dec_to_oct(int m)
{
    // octal//
    printf("Octal Number : %o\n", m);
}
int dec_to_hexa(int m)
{
    printf("Hexa-Decimal Number : %X\n", m);
}
int isOctalInput(const char *input)
{
    // checking the input char by char to avoid any errors
    while (*input)
    {
        if (!isdigit(*input) || (*input < '0' || *input > '7'))
        {
            return 0;
        }
        input++;
    }
    return 1; // Valid octal input
}
void octal_to_binary(int octal)
{
    int binary[MAX];
    int i = 0;

    while (octal != 0)
    {
        binary[i] = octal % 2;
        octal /= 2;
        i++;
    }
    printf("====================================\n>>>\tConversion Results\t<<<\n====================================\n\n");
    printf("Binary Number: ");
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", binary[j]);
    }
    printf("\n");
}
void octal_to_decimal(int octal)
{
    int decimal[MAX];
    int i = 0;

    while (octal != 0)
    {
        decimal[i] = octal % 10;
        octal /= 10;
        i++;
    }

    printf("Decimal Number: %d", octal);
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", decimal[j]);
    }
    printf("\n");
}
void octal_to_hexa(int Number)
{
    int i = 1, j, temp;
    char hexa_Number[MAX];

    while (Number != 0)
    {
        temp = Number % 16;

        if (temp < 10)
            temp = temp + 48;
        else
            temp = temp + 55;
        hexa_Number[i++] = temp;
        Number = Number / 16;
    }
    printf("Hexa-Decimal Number: ");
    for (j = i - 1; j > 0; j--)
        printf("%c", hexa_Number[j]);
    printf("\n");
}
int IsHexa(char *hex)
{
    char *endptr;
    strtol(hex, &endptr, 16);

    // Check if the entire string was consumed and the result is not zero
    return (*endptr == '\0' && hex[0] != '\0');
}
void hex_to_decimal(char hexa[])
{
    long int decimal = strtol(hexa, NULL, 16);
    /* strtol -> convert initial part of string to long int */
    printf("====================================\n>>>\tConversion Results\t<<<\n====================================\n\n");
    printf(" Decimal Number= %ld\n", decimal);
}
void hex_to_binary(char hexa[])
{
    printf(" Binary Number = ");
    unsigned long int decimal = strtoul(hexa, NULL, 16);
    /* strtoul -> convert initial part of string to long int */
    for (int i = sizeof(decimal) * 8 - 1; i >= 0; i--)
    {

        printf("%ld", (decimal >> i) & 1);
        if (i % 8 == 0)
            printf(" ");
    }
    printf("\n");
}
void hex_to_octal(char hexa[])
{
    long int decimal = strtol(hexa, NULL, 16);
    int rem;
    long int octal = 0;
    int i = 0;
    while (decimal)
    {
        rem = decimal % 8;
        octal += rem * pow(10, i);
        decimal /= 8;
        i++;
    }
    printf(" Octal Number = %ld\n", octal);
}
void ScreenCleaner()
{
    system("cls");
}
void Members_Menu()
{
    printf("=================================\n");
    printf(">>>\t\t\b\bTeam 13\t\t\b\b<<<\n");
    printf("=================================\n\n");
    printf("=> \033[1;4mAhmed Tamer\033[0m Worked on Menu, Try Again, Linking Functions and Input Validation");
    printf("\n=> \033[1;4mAhmed Abdelgawad\033[0m Worked Binary Conversion");
    printf("\n=> \033[1;4mEbrahim Ahmed\033[0m Worked on Decimal Conversion");
    printf("\n=> \033[1;4mMoez Alaa\033[0m Worked on Hexa-Decimal Conversion");
    printf("\n=> \033[1;4mAbdulrahman Hassan\033[0m Worked on Octal Conversion");
    printf("\n=> \033[1;4mMohamed Gamal\033[0m Worked on Screen Cleaner");
    printf("\n==================================================");
}
void Switch(int choice, long long n, char flag, char h[MAX])
{
    do
    {
        ScreenCleaner();
        Menu();
        if (scanf("%d", &choice) != 0)
        {
            switch (choice)
            {
            case 1:
                do
                {
                    ScreenCleaner();
                    printf("Enter the Binary Number: ");
                    char input[32];
                    scanf("%s", input);
                    if (!isBinaryInput(input))
                    {
                        printf("Invalid Choice, Try Again!\n");
                        TryAgain(&flag);
                        continue;
                    }
                    sscanf(input, "%lld", &n); // taking input from the string
                    if (IsBinary(n))
                    {
                        binary_to_decimal(n);
                        binary_to_octal(n);
                        binary_to_hexadecimal(n);
                        TryAgain(&flag);
                    }
                    else
                    {
                        printf("Invalid Choice, Try Again!\n");
                        TryAgain(&flag);
                    }
                } while (flag != 'N' && flag != 'n');
                break;
            case 2:
                do
                {
                    ScreenCleaner();
                    printf("Enter the Decimal Number: ");
                    if (scanf("%lld", &n) == 0)
                    {
                        printf("Invalid Choice, Try Again!\n");
                        while (getchar() != '\n') // avoiding an infinite loop
                            ;
                        TryAgain(&flag);
                        continue;
                    }
                    dec_to_bin(n);
                    dec_to_oct(n);
                    dec_to_hexa(n);
                    TryAgain(&flag);

                } while (flag != 'N' && flag != 'n');
                break;
            case 3:
                do
                {
                    ScreenCleaner();
                    printf("Enter the Octal Number: ");
                    char input[32];
                    scanf("%s", input);
                    if (!isOctalInput(input))
                    {
                        printf("Invalid Choice, Try Again!\n");
                        TryAgain(&flag);
                        continue;
                    }
                    sscanf(input, "%o", &n); // taking input from string as in binary case
                    octal_to_binary(n);
                    octal_to_decimal(n);
                    octal_to_hexa(n);
                    TryAgain(&flag);
                } while (flag != 'N' && flag != 'n');
                break;
            case 4:
                do
                {
                    ScreenCleaner();
                    printf("Enter the Hexa-Decimal Number: ");
                    scanf("%s", h);
                    if (IsHexa(h))
                    {
                        hex_to_decimal(h);
                        hex_to_binary(h);
                        hex_to_octal(h);
                        TryAgain(&flag);
                    }
                    else
                    {
                        printf("Invalid Choice, Try Again!\n");
                        TryAgain(&flag);
                    }
                } while (flag != 'N' && flag != 'n');
                break;
            case 5:
                break;
            default:
                printf("Invalid Choice, Try Again!\n");
                TryAgain(&flag);
                break;
            }
        }
        else
        {
            printf("Invalid Choice, Try Again!\n");
            while (getchar() != '\n') // avoiding an infinite loop
                ;
            TryAgain(&flag);
            if (flag == 'N' || flag == 'n')
                choice = 5;
        }
    } while (choice != 5);
    ScreenCleaner();
    Members_Menu(); // exit screen
}
int main()
{
    int choice;
    long long n;
    char flag, h[MAX];
    Switch(choice, n, flag, h);
}