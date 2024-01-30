#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <ctype.h>

// Function to check if the input number is valid
int validdeci(long long deci) {
    while (deci != 0) {
        int digit = deci % 10;
        if (digit < 0 || digit > 9 || isalpha(digit + '0')) {
            return 0;
        }
        deci /= 10;
    }
    return 1;
}

// Function to convert from Decimal to binary
long long decimal_to_binary(long long num) {
    long long binarynum = 0, y = 1;
    while (num > 0) {
        binarynum = binarynum + (num % 2) * y;
        y *= 10;
        num /= 2;
    }
    return binarynum;
}

// Function to convert from Decimal to octal
long long decimal_to_octal(long long num) {
    long long octalnumber = 0, z = 1;
    while (num > 0) {
        octalnumber = octalnumber + (num % 8) * z;
        z *= 10;
        num /= 8;
    }
    return octalnumber;
}

// Function to convert from Decimal to hexadecimal
void decimal_to_hexadecimal(long long num) {
    int hexadecimal = 0;
    if (num <= 0)
        return;
    else {
        decimal_to_hexadecimal(num / 16);
        if (num % 16 < 10)
            printf("%d", (num % 16));
        else
            printf("%c", (num % 16) + 55);
    }
}

// Menu to be displayed on the screen for numbers entry
int decimal(long long num) {
    printf("Please enter the number: ");
    scanf("%lld", &num);
    if (validdeci(num)) {
        printf("Binary number = %lld\n", decimal_to_binary(num));
        printf("Octal number = %lld\n", decimal_to_octal(num));
        printf("Hexadecimal Number = ");
        decimal_to_hexadecimal(num);
        printf("\n");
    } else {
        printf("Invalid decimal number\n");
    }
    return 0;
}

// Function to check if the input number is valid binary
int validbinry(long long binarynum) {
    int digit;
    while (binarynum > 0) {
        digit = binarynum % 10;
        if (digit != 0 && digit != 1) {
            return 0;
        }
        binarynum /= 10;
    }
    return 1;
}

// Function to convert from binary to decimal
long long BinaryToDecimal(long long binary) {
    int remainder;
    long long decimal = 0, base = 1;
    while (binary != 0) {
        remainder = binary % 10;
        decimal += remainder * base;
        base *= 2;
        binary /= 10;
    }
    return decimal;
}

// Function to convert from binary to octal
long long BinaryToOctal(long long binary) {
    int remainder;
    long long octal = 0, base = 1;
    binary = BinaryToDecimal(binary);
    while (binary != 0) {
        remainder = binary % 8;
        octal += remainder * base;
        base *= 10;
        binary /= 8;
    }
    return octal;
}

// Function to convert from binary to hexadecimal
int BinarytoHexa(long long binary) {
    int remainder, hexadecimal = 0, base = 1;
    binary = BinaryToDecimal(binary);
    remainder = binary % 16;
    if (binary != 0)
        return;
    else {
        BinarytoHexa(binary / 16);
        if (remainder < 10)
            printf("%d", remainder);
        else
            printf("%c", remainder + 55);
    }
}

// Function for binary choice
int binary(long long binary) {
    printf("Please enter the Binary number\n");
    scanf("%lld", &binary);
    if (validbinry(binary)) {
        printf("Decimal number = %lld\n", BinaryToDecimal(binary));
        printf("Octal number = %lld\n", BinaryToOctal(binary));
        printf("Hexadecimal Number = %llx\n",(unsigned long long )BinarytoHexa(binary));
    } else {
        printf("Invalid binary number\n");
    }
    return 0;
}

// Check if the octal number entered is a valid octal number
int validoctal(long long octal) {while (octal != 0) {
        int digit = octal % 10;
        if (digit < 0 || digit > 7) {
            return 0;
        }
        octal /= 10;
    }
    return 1;
}

// Function to convert from octal to decimal
long long octalToDecimal(long long num) {
    long long dec = 0, rem = 0, place = 0;

    while (num != 0) {
        rem = num % 10;
        dec += rem * pow(8, place);
        num /= 10;
        place++;
    }

    return dec;
}

// Function to convert from octal to binary
long long octalToBinary(long long num) {
    long long dec = octalToDecimal(num);
    long long bin = 0, place = 1, rem = 0;

    while (dec != 0) {
        rem = dec % 2;
        bin += rem * place;
        dec /= 2;
        place *= 10;
    }

    return bin;
}

// Function to convert from octal to hexadecimal
long long octalToHexadecimal(long long num) {
    long long dec = octalToDecimal(num);
    long long binary = octalToBinary(num);
    long long hexadecimal = 0, tempBinary = binary, placeValue = 1;

    while (tempBinary != 0) {
        int rem = tempBinary % 10000;
        switch (rem) {
            case 0: break;
            case 1: hexadecimal += placeValue; break;
            case 10: hexadecimal += 2 * placeValue; break;
            case 11: hexadecimal += 3 * placeValue; break;
            case 100: hexadecimal += 4 * placeValue; break;
            case 101: hexadecimal += 5 * placeValue; break;
            case 110: hexadecimal += 6 * placeValue; break;
            case 111: hexadecimal += 7 * placeValue; break;
            case 1000: hexadecimal += 8 * placeValue; break;
            case 1001: hexadecimal += 9 * placeValue; break;
            case 1010: hexadecimal += 0xA * placeValue; break;
            case 1011: hexadecimal += 0xB * placeValue; break;
            case 1100: hexadecimal += 0xC * placeValue; break;
            case 1101: hexadecimal += 0xD * placeValue; break;
            case 1110: hexadecimal += 0xE * placeValue; break;
            case 1111: hexadecimal += 0xF * placeValue; break;
            default: break;
        }
        placeValue *= 0x10;
        tempBinary /= 10000;
    }

    return hexadecimal;
}

// Menu to be displayed on screen for numbers entry
int octal(long long octal) {
    printf("Please enter the octal number\n");
    scanf("%lld", &octal);
    if (validoctal(octal)) {
        printf("Decimal number = %lld\n", octalToDecimal(octal));
        printf("Binary number = %lld\n", octalToBinary(octal));
        printf("Hexadecimal number = %llx\n", octalToHexadecimal(octal));
    } else {
        printf("Invalid octal number\n");
    }
    return 0;
}

// Function to validate if a string represents a valid hexadecimal number
int ValidHex(char hexa[]) {
    for (int i = 0; hexa[i] != '\0'; i++) {
        char ch = hexa[i];
        // Check if the character is within the range of hexadecimal digits
        if ((ch < '0' || ch > 'f') && (ch < 'A' || ch > 'F')) {
            return 0;  // The character is not valid
        }
    }
    return 1;  // The characters are valid
}

// Function to convert a hexadecimal string to decimal, binary, and octal
void convertHex(char hexa[]) {
    long long decimal = 0, i = 0, j;
    long long binary[32], octal[32];

    // Convert hexadecimal to decimal
    for (int k = 0; hexa[k] != '\0'; k++) {
        if (hexa[k] >= '0' && hexa[k] <= '9')
            decimal = decimal * 16 + (hexa[k] - '0');
        else if (hexa[k] >= 'a' && hexa[k] <= 'f')
            decimal = decimal * 16 + (hexa[k] - 'a' + 10);
        else if (hexa[k] >= 'A' && hexa[k] <= 'F')
            decimal = decimal * 16 + (hexa[k] - 'A' + 10);
    }

    // Store the decimal value for later use
    long long temp = decimal;

    // Output the decimal value
    printf("The decimal is %lld\n", decimal);

    // Convert decimal to binary
    while (decimal > 0) {
        binary[i] = decimal % 2;
        decimal /= 2;
        i++;
    }

    // Output the binary value
    printf("The binary is: ");
    for (j = i - 1; j >= 0; j--)
        printf("%lld", binary[j]);
    printf("\n");

    i = 0;
    decimal = temp;  // Reset decimal to the original value

    // Convert decimal to octal
    while (decimal > 0) {
        octal[i] = decimal % 8;
        decimal /= 8;
        i++;
    }

    // Output the octal value
    printf("The octal is: ");
    for (j = i - 1; j >= 0; j--)
        printf("%lld", octal[j]);
    printf("\n");
}

// Main function
int hexa() {
    char hexa[33];
    printf("Please enter hexadecimal number\n");
    scanf("%s", hexa);
    // Check if the entered string is a valid hexadecimal number
    if (ValidHex(hexa)) {
        convertHex(hexa);
    } else {
        // Ask the user if they want to try again after entering an invalid number
        printf("Invalid hexadecimal number\n");
    }
    return 0;
}

int main() {
    long long num;
    char tryagain;
    printf(">>> Welcome to Number System Converter <<<\n");
    do {
        system("cls");
        // Built-in function in C that clears the output screen.
        printf(">> Select Conversion Type:\n");
        printf("> 1. Binary Conversion \n");
        printf("> 2. Decimal Conversion \n");
        printf("> 3. Octal Conversion \n");
        printf("> 4. Hexadecimal Conversion \n");
        printf("> 5. Exit the Program \n");
        printf("Enter the number & Hit ENTER:\n");
        scanf("%lld", &num);
        if (num == 1) {
            binary(num);
        } else if (num == 2) {
            decimal(num);
        } else if (num == 3) {
            octal(num);
        } else if (num == 4) {
            hexa(num);
        } else if (num == 5) {
            // If the user selects number 5, the exit screen will appear
            printf(">>> Creator: <<<\n");
            printf("> Member 1 Sofian, worked on: search & optional function num1\n");
            printf("> Member 2 Basant, worked on: search & optional function num2\n");
            printf("> Member 3 Mohamed, worked on: the conversion from Octal system to the rest of systems\n");
            printf("> Member 4 Tasneem, worked on: the conversion from Decimal system to the rest of systems\n");
            printf("> Member 5 Syada, worked on: the conversion from Binary system to the rest of system\n");
            printf("> Member 6 Fatma, worked on: the conversion from Hexadecimal system to the rest of systems\n");
            printf("> Member 7 Mariam, worked on: the welcome screen and the exit screen\n");
            exit(0);
        } else {
            printf("Invalid input\n");
        }
        printf("Do you want to try again? (y/n)\n");
        tryagain = getch();
        while (tryagain != 'y' && tryagain != 'Y' && tryagain != 'n' && tryagain != 'N') {
            printf("Invalid input. Please enter 'y' or 'n':\n");
            tryagain = getch();
        }
    } while (tryagain == 'y' || tryagain == 'Y');

    return 0;
}