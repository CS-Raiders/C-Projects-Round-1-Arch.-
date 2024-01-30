#include <stdio.h>  //for input and output
#include <stdlib.h> // for exit(0) function
#include <math.h>  //for power function
#include<string.h> // for strlen() function

void menu();//welcome screen and display menu

void textColor();//text color(blue)

int tryagain();//try Again function

void clear_screen_and_buffer(); // clears the output screen and input buffers

int credits();//exit screen with credits

int check_Has_One_Or_Zero(int num);//handling 0's and 1's errors

void Source_Code();//the main code


//binary cinversions functions
void binary_to_decimal();
void binary_to_hexadecimal();
void convert_BINARY_to_OCTAL();

//decimal conversions functions
void decimal_to_octal();
void decimal_to_hexadecimal();
void decimal_to_binary();

//hexa conversions function
void hexToOct();
void hexTodeci(char hex[]);
void HexatoBinary();

//octal conversions function
void octaltodecimal();
void octaltobinary();
void octal_hexa();

int main()
{
    //it will execute the Source_Code function one time then will execute the tryagain functin
    //menu();
    do
    {

        Source_Code();

    }
    while (tryagain());
    return 0;
}

void clear_screen_and_buffer()
{
    system("cls");//clear screen
    int  c;
    while ((c=getchar())!='\n' && c !=EOF) {} //clear buffer


}
void hexToOct()
{
    char hex[20];
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    // Convert hexadecimal to decimal
    long decimal = strtol(hex, NULL, 16);

    // Convert decimal to octal
    char octal[50];
    int i = 0;
    while (decimal != 0)
    {
        octal[i] = (decimal % 8) + '0';
        decimal /= 8;
        i++;
    }

    // Display the octal number in reverse order
    printf("-----------------------\n>>> Conversion result >>>\n-----------------------\n ");
    printf("the equivilant octal is: ");
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%c", octal[j]);
    }

    printf("\n");
}

//==============================//
void decimal_to_octal()
{
    int dec, octal = 0, k = 1, rem;
    printf("Enter Decimal Number : ");
    scanf("%d", &dec);
    while (dec != 0)
    {
        rem = dec % 8;
        octal = octal + k * rem;
        dec = dec / 8;
        k = k * 10;
    }
    printf("-----------------------\n>>> Conversion result >>>\n-----------------------\n ");
    printf("the equivalent Octal is :  %d", octal);
}

//==============================//
void hexTodeci(char hex[])
{
    printf("Enter hexadecimal number: ");
    scanf("%s", &hex);

    long decimal;
    decimal = strtol(hex, NULL, 16);

    if (decimal == 0 && hex[0] != '0')
    {
        printf("invalid value \a \n");
    }
    else
    {
        printf("decimal value is : %ld\n", decimal);
    }
}

//==============================//
void HexatoBinary()
{

    char hex_string[10];
    printf("Enter the Hexadecimal: ");
    scanf("%s", hex_string);
    printf("-----------------------\n>>> Conversion result >>>\n-----------------------\n ");
    printf("the eqyuivalent Binary Number is : ");
    for( int i=0; hex_string[i] != '\0'; ++i)
    {
        char hex_digit = hex_string[i] ;

        switch(hex_digit)
        {
        case '0':
            printf("0000");
            break;
        case '1':
            printf("0001");
            break;
        case '2':
            printf("0010");
            break;
        case '3':
            printf("0011");
            break;
        case '4':
            printf("0100");
            break;
        case '5':
            printf("0101");
            break;
        case '6':
            printf("0110");
            break;
        case '7':
            printf("0111");
            break;
        case '8':
            printf("1000");
            break;
        case '9':
            printf("1001");
            break;
        case 'A':
            printf("1010");
            break;
        case 'B':
            printf("1011");
            break;
        case 'C':
            printf("1100");
            break;
        case 'D':
            printf("1101");
            break;
        case 'E':
            printf("1110");
            break;
        case 'F':
            printf("1111");
            break;
        default:
            printf("\nInvalid number \a\n");
        }

    }
}
//==============================//
void decimal_to_hexadecimal()
{
    int decimal_number, hexa_decimal = 0, weight2 = 1;
    printf("please enter decimalnumber to convert:");
    scanf("%d", &decimal_number);

    // Convert decimal to hexadecimal
    while (decimal_number != 0)
    {
        int remainder2 = decimal_number % 16;
        hexa_decimal = hexa_decimal + (remainder2 * weight2);
        decimal_number = decimal_number / 16;
        weight2 = weight2 * 10;
    }
    printf("-----------------------\n>>> Conversion result >>>\n-----------------------\n ");
    printf("The equivalent Hexadecimal is: %X\n", hexa_decimal);
}

//==============================//
void decimal_to_binary()
{
    long decimal;
    int binary = 0, weight = 1;
    printf("Please enter the decimal number to convert: ");
    scanf("%ld", &decimal);
    while (decimal != 0)
    {
        int rem = decimal % 2;
        binary = binary + rem * weight;
        decimal = decimal / 2;
        weight = weight * 10; //due to converting froma base 10[binary]to 2[decimal]
    }
    printf("-----------------------\n>>> Conversion result >>>\n-----------------------\n ");
    printf("the equivalent decimal is :%d", binary);
}

//==============================//
void binary_to_decimal()
{
    int binary, weight = 1;
    long decimal_number = 0;
    printf("Please enter the binary number to convert: ");
    scanf("%d", &binary);


    if (check_Has_One_Or_Zero(binary) > 0)
    {
        while (binary != 0)
        {
            int rem = binary % 10;
            decimal_number = decimal_number + rem * weight;
            binary = binary / 10;
            weight = weight * 2; //due to  converting from base 2(binary) to base 10(decimal)
        }
        printf("-----------------------\n>>> Conversion result >>>\n-----------------------\n ");
        printf("the equivalent decimal is :%ld", decimal_number);
    }


    else
    {
        printf("Invalid input \a");
    }

}

//==============================//
void binary_to_hexadecimal()
{
    int binary, weight = 1;
    long hexaDecimal = 0;
    printf("please enter the binary number to convert it :");
    scanf("%d", &binary);


    if (check_Has_One_Or_Zero(binary) > 0)
    {
        while (binary != 0) //convert binary to decimal
        {
            int rem = binary % 10;
            hexaDecimal = hexaDecimal + rem * weight;
            binary = binary / 10;
            weight = weight * 2; //due to converting from base 10 to base 2
        }

        printf("-----------------------\n>>> Conversion result >>>\n-----------------------\n ");
        printf("The equivalent Hexadecimal is: %lX\n", hexaDecimal);
    }
    else
    {
        printf("Invalid input \a");
    }
}

//==============================//
void octaltodecimal()
{
    long octal_number;
    int decimal = 0, i = 0;
    printf("Please Enter the octal number to convert:");
    scanf("%ld", &octal_number);
    int temp_octal = octal_number;
    while (temp_octal != 0)
    {
        int digit = temp_octal % 10;
        if (digit >= 8)
        {
            printf("Error: Invalid octal number \a\n");
            return;
        }
        temp_octal /= 10;
    }
    while (octal_number != 0)
    {
        decimal += (octal_number % 10) * pow(8, i);
        i++;
        octal_number /= 10;
    }
    i = 1;
    printf("-----------------------\n>>> Conversion result >>>\n-----------------------\n ");
    printf("Decimal number is :%d", decimal);
    // return decimal;
}

//==============================//
void octaltobinary()
{
    long octal_number;
    int decimal = 0, i = 0;
    printf("Please Enter the octal number to convert:");
    scanf("%ld", &octal_number);
    long binary_number = 0;
    int temp_octal = octal_number;
    while (temp_octal != 0)
    {
        int digit = temp_octal % 10;
        if (digit >= 8)
        {
            printf("Error: Invalid octal number\a\n");
            return;
        }
        temp_octal /= 10;
    }

    while (octal_number != 0)
    {
        decimal += (octal_number % 10) * pow(8, i);
        i++;
        octal_number /= 10;
    }
    i = 1;
    while (decimal != 0)
    {
        binary_number += (decimal % 2) * i;
        decimal /= 2;
        i *= 10;
    }
    printf("-----------------------\n>>> Conversion result >>>\n-----------------------\n ");
    printf("Binary number is :%ld", binary_number);
    // return binary_number;
}

//==============================//
void octal_hexa() //it will convert from octal to decimal then from decimal to hexadecimal
{
    int octal_number, decimal = 0;
    printf(" Enter the octal number: ");
    scanf("%d", &octal_number);
    int temp_octal = octal_number;
    while (temp_octal != 0)
    {
        int digit = temp_octal % 10;
        if (digit >= 8)
        {
            printf("Error: Invalid octal number\a \n");
            return;
        }
        temp_octal /= 10;
    }

    int i = 0;
    while (octal_number != 0) // it convert octal to decimal
    {
        int reminder = octal_number % 10;
        decimal = decimal + (reminder * pow(8, i));
        octal_number = octal_number / 10;
        i++;
    }

    int hexa[50], j = 1, temp = decimal, reminder2; //array to store the conversion answer
    while (temp != 0)
    {
        reminder2 = temp % 16;
        if (reminder2 < 10)
        {
            reminder2 = reminder2 + 48;
        }
        else
        {
            reminder2 = reminder2 + 55;
        }
        hexa[j++] = reminder2;
        temp = temp / 16;
    }
    printf("-----------------------\n>>> Conversion result >>>\n-----------------------\n ");
    printf("The octal number in hexadecimal is: ");
    for (int t = j - 1; t > 0; t--) //take the reversed result
    {
        printf("%c", hexa[t]);
    }
}
void menu()
{
    textColor();
    printf("-------------------------------------------------\n >>Welcome to Number System Converter<<\n-------------------------------------------------\n");
    printf(">> Select Conversion Type: \n");
    printf(
        ">1. Binary Conversion \n>2. Decimal conversion \n>3. Octal Conversion \n>4. Hexadecimal Conversion \n>5. Exit the Program\n");
}

//==============================//
void Source_Code()
{
    textColor();
    menu();
    int number, x, num, y, z, m;
    int decimal = 0, remainder = 0, place =0;
    printf("Enter the number & Hit ENTER :  ");
    scanf("%d", &number);
    switch (number)
    {
    case 1:
        clear_screen_and_buffer();
        printf(">1. convert to Decimal \n>2. convert to Octal\n>3. convert to Hexadecimal \n ");
        printf("Choose the exact conversion :  ");
        scanf("%d", &x);
        if (x == 1)
        {
            clear_screen_and_buffer();
            binary_to_decimal(); // Calling  the function that converts binary to decimal
        }
        else
        {
            if (x == 2)
            {
                printf("-----------------------\n>>> Conversion result <<<\n-----------------------\n ");
                clear_screen_and_buffer();
                convert_BINARY_to_OCTAL();

            }
            else
            {
                if (x == 3)
                {
                    clear_screen_and_buffer();
                    binary_to_hexadecimal(); //calling the function that converts binary to hexadecimal
                }
            }
        }
        break;
    case 2:
        clear_screen_and_buffer();
        printf(">1. convert to Binary \n>2. convert to Octal\n>3. convert to Hexadecimal \n ");
        printf("choose the exact conversion :  ");
        scanf("%d", &y);
        if (y == 1)
        {
            clear_screen_and_buffer();
            decimal_to_binary();
        }
        else
        {
            if (y == 2)
            {
                clear_screen_and_buffer();
                decimal_to_octal();
            }
            else
            {
                if (y == 3)
                {
                    clear_screen_and_buffer();
                    decimal_to_hexadecimal();
                }
            }
        }
        break;
    case 3:
        clear_screen_and_buffer();
        printf(">1. convert to Binary \n>2. convert to Decimal\n>3. convert to Hexadecimal \n ");
        printf("choose the exact conversion :  ");
        scanf("%d", &z);
        if (z == 1)
        {
            clear_screen_and_buffer();
            octaltobinary();
        }
        else
        {
            if (z == 2)
            {
                clear_screen_and_buffer();
                octaltodecimal();
            }
            else
            {
                if (z == 3)
                {
                    clear_screen_and_buffer();
                    octal_hexa();
                }
            }
        }
        break;
    case 4:
        clear_screen_and_buffer();
        printf(">1. convert to Binary \n>2. convert to Decimal \n>3. convert to Octal \n ");
        printf("choose the exact conversion :  ");
        scanf("%d", &m);
        if (m == 1)
        {
            clear_screen_and_buffer();
            HexatoBinary();
        }
        else
        {
            if (m == 2)
            {
                clear_screen_and_buffer();
                char hex[20];
                hexTodeci(hex);
            }
            else
            {
                if (m == 3)
                {
                    clear_screen_and_buffer();
                    hexToOct();
                }
            }
        }
        break;
    case 5:
        clear_screen_and_buffer();
        credits();
        exit(0);
        break;


    default:
        printf("illegal choice \a");
    }
}

//==============================//
int tryagain()
{
    char ch;
    printf("\n Do you want to do another operation? (y|n)\n");
    scanf(" %c", &ch);
    if (ch == 'y' || ch == 'Y')
    {
        clear_screen_and_buffer();
        menu();
        //it will execute the code again
        return 1;
    }
    else if (ch == 'n' || ch == 'N')
    {
        clear_screen_and_buffer();
        //  it will not execute the code again
        credits();
        exit(0);
    }
    else
    {
        printf("\n Invalid input \a\n");
        return tryagain(); //return tryagain function to ask the user again if he inputted an invalid input
    }
}

//==============================//
void textColor()
{
    printf("\033[1;36m");
}
//==============================//
int credits()
{
    printf("-------------------------------\n");
    printf(">>> Creators { BlazingByte } >>>\n");
    printf("-------------------------------\n\n");

    printf("> Loay Ehab:    - Binary To Hexa ,Binary To Decimal ,Decimal To Binary\n");
    printf("                - Color/Clear Screen/Prototyping\n");
    printf("                - Error Handling\n\n");

    printf("> Aya Elsaid:   - Octal To Decimal ,Octal To Binary\n\n");

    printf("> Sara Sameh:   - Octal To Hexadecimal\n");
    printf("                - Try Again Function\n\n");

    printf("> Basmala Sayed:- Exit/Display Menu\n");
    printf("                - Collecting Binary Conversions\n\n");

    printf("> Shaymaa Ghanim: - Prototyping/Binary Error Handling\n");
    printf("                  - Binary To Octal Conversion\n\n");

    printf("> Aya Ahmed:    - Hexadecimal To Decimal -Hexadecimal To Binary\n\n");

    printf("> Mariam Mohamed: - Clear Screen\n");
    return 0;
}
//==========//
int check_Has_One_Or_Zero(int num)
{
    int count = 0;

    while (num > 0)
    {
        int digit = num % 10;
        if (digit != 0 && digit != 1)
        {
            return 0;
        }
        count++;
        num = num / 10;
    }
    return count;
}
//===============//
void convert_BINARY_to_OCTAL()
{
    int num;
    printf("please enter the binary number to convert it :");
    scanf("%d", &num);
    if (check_Has_One_Or_Zero(num) > 0)


    {

        int decimal = 0, remainder = 0, place = 0;
        while (num)
        {
            remainder = num % 10;
            decimal = decimal + remainder * (pow(2, place));
            num = num / 10;
            place++;
        }

        place = 1;
        int octal = 0;

        while (decimal)
        {
            remainder = decimal % 8;
            octal = octal + remainder * place;
            decimal = decimal / 8;
            place = place * 10;
        }

        printf("The octal value is: %d", octal);
    }
    else
    {
        printf("Invalid input\a");
    }
}
