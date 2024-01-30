#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

void main_menu();
void decimal_conversion(char num[]);
void hexa_conversion(char num[]);
void octal_conversion(char num[]);
void binary_conversion(char num[]);
void exitScreen();

void decimal_to_binary(int decimal_num);
void decimal_to_octal(int decimal_num);
void decimal_to_hexa(int decimal_num);

void try_again();
void conversion_result();

void BinaryConversion();
void DecimalConversion();
void HexaConversion();
void OctalConversion();

int main()
{

    int choice;

    system("COLOR 0B");
    main_menu();

    // Check if the input is a valid integer
    if (scanf("%d", &choice) != 1)
    {
        // Input is not a valid integer (user entered a letter)
        system("cls");
        printf("========================================================\n");
        printf("=== Invalid input. Please enter a number from 1 to 5 ===\n");
        printf("========================================================\n");

        // Clear the input buffer
        while (getchar() != '\n');

        main(); // Recursive call to main function
    }
    else
    {
        // Input is a valid integer
        switch (choice)
        {
        case 1:
            BinaryConversion();
            break;

        case 2:
            DecimalConversion();
            break;

        case 3:
            HexaConversion();
            break;

        case 4:
            OctalConversion();
            break;

        case 5:
            exitScreen();
            exit(0);
            break;

        default:
            system("cls");
            printf("========================================\n");
            printf("Please enter a valid number from 1 to 5.\n");
            printf("========================================\n");
            main();
            break;
        }
    }
    return 0;
}

// Display the main menu
void main_menu()
{
    puts("------------------------------------------");
    puts(">>> Welcome to Number System converter <<<");
    puts("------------------------------------------");
    puts("                                          ");
    puts(">> Select Conversion Type:");
    puts("1. Binary Conversion ");
    puts("2. Decimal Conversion ");
    puts("3. Octal Conversion ");
    puts("4. Hexadecimal Conversion ");
    puts("5. Exit the program ");

    printf("\nEnter the Number & hit ENTER: ");
}

// Prints a header for the conversion results section.
void conversion_result()
{
    printf("---------------------------\n");
    printf(" >>> conversion results <<<\n");
    printf("---------------------------\n");
}

// Displays an exit screen with information about the creators of the program.
void exitScreen()
{
    system("cls"); // is a command used to clear the console screen.
    puts("*****************************************************************************************");
    puts(">>>                               Creator: TIGERS                                     <<<");
    puts("*****************************************************************************************");
    puts("> Leader   \"Youssef Badr\"   , Worked on : Project structure & Octal conversion function");
    puts("> Member 1 \"Omar El Bshary\" , Worked on : Welcome & Exit function & Test the project");
    puts("> Member 2 \"Ayman El Feky\"  , Worked on : Main function");
    puts("> Member 3 \"Youssef sherif\" , Worked on : decimal conversion function");
    puts("> Member 4 \"Youssef Gaber\"  , Worked on : Binary conversion function");
    puts("> Member 5 \"Omar Khattab\"   , Worked on : Hexadecimal conversion function");
    puts("> Member 6 \"Omar Salah\"     , Worked on : Try again function\n");
    puts("                                  ***GOOD LUCK***                                        ");
}

// Convert decimal to binary, octal, and hexadecimal
void decimal_to_binary(int decimal_num)
{
    int decimal_to_binary = decimal_num;
    int binary_num[32];
    int i = 0, j;

    while (decimal_to_binary > 0)
    {
        binary_num[i] = decimal_to_binary % 2;
        decimal_to_binary = decimal_to_binary / 2;
        i++;
    }
    printf("Binary Number: ");

    for (j = i - 1; j >= 0; j--)
    {
        printf("%d", binary_num[j]);
    }

    if (decimal_num == 0){
        printf("%d\n", 0);
    }
}
void decimal_to_octal(int decimal_num)
{
    int decimal_to_octal = decimal_num;
    int octal_num[100];
    int i = 0, j;

    while (decimal_to_octal > 0)
    {
        octal_num[i] = decimal_to_octal % 8;
        decimal_to_octal = decimal_to_octal / 8;
        i++;
    }
    printf("\nOctal Number: ");

    for (j = i - 1; j >= 0; j--)
    {
        printf("%d", octal_num[j]);
    }

    if (decimal_num == 0){
        printf("%d\n", 0);
    }
}
void decimal_to_hexa(int decimal_num)
{
    char hexa_num[100];
    int temp, j, decimal_to_hexa = decimal_num;
    int i = 0;

    while (decimal_to_hexa > 0)
    {
        temp = decimal_to_hexa % 16;

        if (temp < 10){
            hexa_num[i] = temp + 48;
        }
        else{
            hexa_num[i] = temp + 55;
        }
        decimal_to_hexa = decimal_to_hexa / 16;
        i++;
    }
    printf("\nHexadecimal Number: ");

    for (j = i - 1; j >= 0; j--)
    {
        printf("%c", hexa_num[j]);
    }

    if (decimal_num == 0){
        printf("%d\n", 0);
    }
}
void decimal_conversion(char decimal_number[])
{

    int decimal_num = 0, power = 0, decimal_digit;
    for(int counter = strlen(decimal_number) - 1 ; counter >= 0 ; counter--)
    {
        if(isdigit(decimal_number[counter]))
        {
            decimal_digit = decimal_number[counter] - 48;
        }
        else
        {
            system("cls");
            printf("\nPlease Enter The CORRECT decimal number!!!\n");
            DecimalConversion();
            break;
        }
        decimal_num = decimal_num + decimal_digit * pow(10,power++);
    }

    conversion_result();

    decimal_to_binary(decimal_num);
    decimal_to_octal(decimal_num);
    decimal_to_hexa(decimal_num);
}

void binary_conversion(char binary_num[])
{
    int binary_number = 0, power = 0, digit;

    for(int counter = strlen(binary_num) - 1 ; counter >= 0 ; counter--)
    {
        if(binary_num[counter] == '0' || binary_num[counter] == '1')
        {
            digit = binary_num[counter] - 48;
        }
        else
        {
            system("cls");
            printf("\nPlease Enter The CORRECT Binary number!!!\n");
            BinaryConversion();
            break;
        }
        binary_number = binary_number + digit * pow(10,power++);
    }

    conversion_result();

    int decimal_num = 0 , temp , i = 0;
    long long binary_to_decimal = binary_number ;

    while(binary_to_decimal>0)
    {
        temp = binary_to_decimal % 10 ;
        decimal_num = decimal_num + temp * pow(2, i++);
        binary_to_decimal /= 10;
    }
    printf("Decimal Number: %d\n",decimal_num);

    decimal_to_octal(decimal_num);
    decimal_to_hexa(decimal_num);
}

void octal_conversion(char octal_num[])
{

    int octal_number = 0, power = 0, digit;

    for(int counter = strlen(octal_num) - 1 ; counter >= 0 ; counter--)
    {
        if(isdigit(octal_num[counter]))
        {
            digit = octal_num[counter] - 48;
        }
        else
        {
            system("cls");
            printf("\nPlease Enter The CORRECT Octal number!!!\n");
            OctalConversion();
            break;
        }

        octal_number = octal_number + digit * pow(10,power++);
    }

    conversion_result();


    int octal_to_decimal = octal_number ,temp,decimal_num=0,i=0;
    while(octal_to_decimal > 0)
    {
        temp = octal_to_decimal % 10 ;
        decimal_num = decimal_num + temp * pow(8,i++);
        octal_to_decimal /= 10;
    }
    printf("decimal number: %d\n",decimal_num);

    decimal_to_binary(decimal_num);
    decimal_to_hexa(decimal_num);
}

void hexa_conversion(char hexa[])
{

    int decimal_num = 0, digit, power=0, i;
    for( i = strlen(hexa) - 1 ; i >= 0 ; i--)
    {
        if(isdigit(hexa[i]))
        {
            digit = hexa[i] - 48;
        }
        else if(hexa[i]>='A' && hexa[i]<='F' )
        {
            digit = hexa[i] - 55;
        }
        else if(hexa[i]>='a' && hexa[i]<='f')
        {
            digit = hexa[i] - 87;
        }
        else
        {
            system("cls");
            printf("\nPlease Enter The CORRECT Hexadecimal number!!!\n");
            HexaConversion();
            break;
        }
        decimal_num = decimal_num + digit * pow(16,power++) ;
    }

    conversion_result();

    printf("Decimal Number: %d\n",decimal_num);

    decimal_to_binary(decimal_num);
    decimal_to_octal(decimal_num);
}

void BinaryConversion()
{
    char binary_num[100];

    printf("Enter the Binary: ");
    scanf("%s",&binary_num);
    binary_conversion(binary_num);
    printf("\n");
    try_again();
}
void DecimalConversion()
{
        char decimal_num[100];

        printf("Enter the Decimal: ");
        scanf("%s",&decimal_num);

        decimal_conversion(decimal_num);
        printf("\n");
        try_again();
}
void HexaConversion()
{
    char hexa_num[100];

    printf("Enter the Hexadecimal: ");
    scanf("%s",&hexa_num);

    hexa_conversion(hexa_num);
    printf("\n");
    try_again();
}
void OctalConversion()
{
        char octal_num[100];

        printf("Enter the Octal: ");
        scanf("%s",&octal_num);

        octal_conversion(octal_num);
        printf("\n");
        try_again();
}

// Allows the user to choose whether to try another conversion or exit the program.
void try_again()
{
    char c,ch;
    while(1)
    {
        printf("Do you want to try again [Y/N]: ");
        c = getch();
        printf("\n");

        if(c == 'Y' || c == 'y')
        {
            printf("Do you want to save the last result [Y/N]: ");
            ch = getch();
            printf("\n");

            if(ch == 'Y' || ch == 'y'){
                main();
                break;
            }
            else if(ch == 'N' || ch == 'n'){
                system("cls");
                main();
                break;
            }
            else
            {
                puts("Please Enter The CORRECT charater !");
                puts("Do you want to save the last result [Y/N]: ");
                ch = getch();

                if(ch == 'Y' || ch == 'y'){
                   main();
                   break;
                }
                else if(ch == 'N' || ch == 'n'){
                   system("cls");
                   main();
                   break;
                }
                else{
                    puts("Please Enter The CORRECT charater !");
                }
            }

        }

        else if(c == 'N' || c == 'n'){
            exitScreen();
            exit(0);
        }

        else{
            puts("Please Enter The CORRECT char !!!");
            continue;
        }
    }
}
