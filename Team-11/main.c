#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
void welcom()
{
    printf("<welcome to the best number system convert>\n");
    printf("-------------------------------------------\n");
    printf("menu:\n1_binary\n2_octal\n3_decimal\n4_hexadecimal\n5_EXIT\n");
    printf("-------------------------------------------\n");
    printf("please enter your choice:");

}
void ex()
{
    printf("creator:team 11\n");
    printf("MENBER  1(LEADER):Menna samir\n");
    printf("MEMBER  2:Menna shehata\n");
    printf("MEMBER  3:Hend adel\n");
    printf("MEMBER  4:Youseef kamal\n");
    printf("MEMBER  5:Rawan khaled\n");
}
/////////////////////////////////////BINARYYYYYYYYYYYYYYYYYYYYYYYYYY BART
void binaryToDecimal(int x) {
    int y, remainder, n = 0, sum = 0;
    if (x == 0) {
        printf("Decimal number : 0\n");
    } else if (x == 1) {
        printf("Decimal number : 1\n");
    } else {
        do {
            remainder = x % 10;
            if (remainder == 1) {
                y = pow(2, n);
                sum = y + sum;
            } else if (remainder == 0) {

            }
            n++;
            x = x / 10;
        } while (x != 0);
        printf("Decimal number : %d", sum);
    }
}
//==================================================
int binaryToOctal(int binaryNumber) {
    int octalNumber = 0, decimalNumber = 0, i = 0;

    // Convert binary to decimal
    while (binaryNumber != 0) {
        decimalNumber += (binaryNumber % 10) * pow(2, i);
        ++i;
        binaryNumber /= 10;
    }

    i = 1;

    // Convert decimal to octal
    while (decimalNumber != 0) {
        octalNumber += (decimalNumber % 8) * i;
        decimalNumber /= 8;
        i *= 10;
    }

printf("Octal number: %d\n", octalNumber);

    return octalNumber;
}
//==============================================
void binaryToHexa(int x) {

    int remainder,y, n = 0, sum = 0;

    if (x == 0) {
        printf("Hexadecimal number: 0\n");
    } else if (x == 1) {
        printf("Hexadecimal number: 1\n");
    } else {
        do {
            remainder = x % 10;
            if (remainder == 1) {
                y=  pow(2, n);
                sum=sum+y;
            }
            n++;
            x = x / 10;
        } while (x != 0);

        printf("\nHexadecimal number: %x\n", sum);
    }

}
///////////////////////////////////////octalllllllllllllllllllllllllllllllll

void octalToBinary(int octal) {
    printf("Binary equivalent: ");
    // To convert each octal digit to 3-bit binary representation
    for (int i = 0; octal != 0; i++) {
        // Extract the last digit of octal
        int digit = octal % 10;

        // Convert the octal digit to 3-bit binary
        switch (digit) {
            case 0: printf("000"); break;
            case 1: printf("001"); break;
            case 2: printf("010"); break;
            case 3: printf("011"); break;
            case 4: printf("100"); break;
            case 5: printf("101"); break;
            case 6: printf("110"); break;
            case 7: printf("111"); break;
            default: printf("\nInvalid octal digit %d", digit);
        }

        // Remove the last digit
        octal /= 10;
    }
    printf("\n");
}

//===========================================
int OctalToDecimal(int octalnumber) {
    int decimalnum = 0, i = 0, remainder;

    while(octalnumber != 0) {
        remainder = octalnumber % 10;
        octalnumber /= 10;
        decimalnum += remainder * pow(8, i);
        ++i;
    }

    printf("\nDecimal value: %d\n", decimalnum);  // Moved printf inside the function
    return decimalnum;
}

//========================================
void octalToHexadecimal(int octalNumber) {
    int decimalNumber = 0, i = 0, remainder;
    char hexadecimalNumber[50];
    while (octalNumber != 0) {
        remainder = octalNumber % 10;
        octalNumber /= 10;
        decimalNumber += remainder * pow(8, i);
        ++i;
    }
    i = 0;
    while (decimalNumber != 0) {
        remainder = decimalNumber % 16;
        if (remainder < 10)
            hexadecimalNumber[i] = remainder + '0';
        else
            hexadecimalNumber[i] = remainder + 'A' - 10;
        ++i;
        decimalNumber /= 16;
    }

    printf("Hexadecimal number: ");
    for (int j = i - 1; j >= 0; --j)
        printf("%c", hexadecimalNumber[j]);
}
/////////////////////////////DECIMALLLLLLLLLLLLLLLLLLLLL PART

void DecimalToBinary(x)
{
   int binary [32],i=0;

   if(x==0)
     printf("Binary:0");

   while(x>0)
   {
     binary[i]=x%2;
     x/=2;
     i++;
   }
   printf("the Binary num is: ");
   for(int j=i-1;j>=0;j--)
      printf("%d",binary[j]);

}

//===================================================
void decToH(int n) {
    char hexNum[100];// declare array of size 100 and type char
    int r,c=0;// declare remainder (r) and counter(c)

    while(n != 0) {
        r= n % 16;//getting remainder of n / 16
        if (r < 10)
        {
         //48 is the decimal value of character 0
         //counter will be incremented now
            hexNum[c++]= 48 + r;
        }
        else {
         //55 is the decimal value of character 7
            hexNum[c++]= 55 + r;
        }

        n= n / 16;
    }
    printf("The hexaNum is : ");
        for ( c=c-1; c>= 0; c--)
        printf ("%c",hexNum[c]);
        printf("\n");

}
//===========================================================
void decToOctal(int n) {
    int octalNum[100];// declare array of size 100
    int r,oct=0,i=0;// declare remainder (r) and counter(c)

    while(n != 0) {
        octalNum[i]= n % 8;//getting remainder of n / 8
        n= n / 8;
        i++;
    }
    printf("The octalNum is :");

    for(int j= i-1;j>=0; j--){
         printf("%d",octalNum[j]);
    }
 printf("\n");


}
////////////////////////////////////hexaaaaaaaaaaaaaaaaaaaaaaaa

void hexToBinary(char hex[]) {
    printf("Binary equivalent: ");
    for (int i = 0; hex[i] != '\0'; ++i) {
        switch (hex[i]) {
            case '0': printf("0000"); break;
            case '1': printf("0001"); break;
            case '2': printf("0010"); break;
            case '3': printf("0011"); break;
            case '4': printf("0100"); break;
            case '5': printf("0101"); break;
            case '6': printf("0110"); break;
            case '7': printf("0111"); break;
            case '8': printf("1000"); break;
            case '9': printf("1001"); break;
            case 'A':
            case 'a': printf("1010"); break;
            case 'B':
            case 'b': printf("1011"); break;
            case 'C':
            case 'c': printf("1100"); break;
            case 'D':
            case 'd': printf("1101"); break;
            case 'E':
            case 'e': printf("1110"); break;
            case 'F':
            case 'f': printf("1111"); break;
            default: printf("\nInvalid hexadecimal digit %c", hex[i]);
        }
    }
    printf("\n");
}
//===========================================================
void hexToDecimal(char hex[]) {
    long int decimal = strtol(hex, NULL, 16);
    printf("Decimal equivalent: %ld\n", decimal);
}
//============================================================
void hexToOctal(char hex[]) {
    long int decimal = strtol(hex, NULL, 16);
    long int octal = 0;
    int i = 1, remainder;

    while (decimal != 0) {
        remainder = decimal % 8;
        octal = octal + remainder * i;
        i = i * 10;
        decimal = decimal / 8;
    }

    printf("Octal equivalent: %lo\n", octal);
}
/////////////////////////////////////////////////////////////////
void clearScreen() {
    #ifdef _WIN32
        system("cls"); // For Windows
    #else
        system("clear"); // For Unix/Linux
    #endif

    // Flush input buffer
    while (getchar() != '\n');
}

//-----------------------------------------------
int main()
{
    while(1)
    {
        welcom();
        int choice;
        scanf("%d",&choice);
        clearScreen();
        int n,z,x;
        char hex[20];
        long int decimal;
        switch(choice)
        {
        case 1:
            printf("Enter the binary number");
            scanf("%d", &x);
            printf("convertion results:\n");
            printf("-----------------------\n");
            binaryToOctal(x);
            binaryToDecimal(x);
            binaryToHexa(x);
            break;
        case 2:
            printf("Enter an octal number: ");
            scanf("%d", &z);
            printf("convertion results:\n");
            printf("-----------------------\n");
            octalToBinary(z);
            octalToHexadecimal(z);
            OctalToDecimal(z);
            break;
        case 3:
            printf("Enter a decimal number:");
            scanf("%d",&n);
            printf("convertion results:\n");
            printf("-----------------------\n");
            decToH(n);
            decToOctal(n);
            DecimalToBinary(n);
            break;
        case 4:
            printf("Enter a hexadecimal number: ");
            scanf("%s", hex);
            printf("convertion results:\n");
            printf("-----------------------\n");
            hexToBinary(hex);
            hexToDecimal(hex);
            hexToOctal(hex);
            break;
        case 5:
            ex();
            break;
        default:
            printf("Invalid choice. Please enter a number between 1 and 5.\n");
            break;
        }
        if(choice==5)
        {
            break;
        }
        printf("\nDo you want to try again? [y or n]: ");
        char r;
        scanf(" %c", &r);
        if (r == 'y' || r == 'Y')
        {
            clearScreen();
            continue;
        }
        else
        {
            printf("good bye");
            break;
        }
    }
}



