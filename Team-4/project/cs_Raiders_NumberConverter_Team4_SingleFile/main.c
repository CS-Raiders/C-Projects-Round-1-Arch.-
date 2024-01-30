#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <string.h>

//Main menu and exit menu:
void mainMenu ();
void exitMenu ();

//Try Again Functions:
void tryAgain(int choice);
void decimalTryAgain(int choice);
void binaryTryAgain(int choice);
void octalTryAgain(int choice);
void hexadecimalTryAgain(int choice);

// BinaryConversionFunctions:
void binaryConversions(int choice);
double binaryToDecimal(int choice, int *isNegative, int *invalidDigit);

// DecimalConversionFunctions:
void decimalConversions(int choice);
void decimalToBinary(double decimal);
void decimalToOctal(double decimal) ;
void decimalToHexadecimal(double decimal);

// OctalConversionFunctions:
void octalConversions(int choice);
double octalToDecimal(int choice, int *isNegative, int *invalidDigit);

// HexadecimalConversionFunctions:
void hexadecimalConversions(int choice);
double hexadecimalToDecimal(int choice, int *isNegative,int *errorHexa);




int main()
{
    mainMenu();
    return 0;
}



//menu Functions:
void mainMenu()
{
    int choice;
    printf("----------------------------------------------\n");
    printf(">>> Welcome To Number System Converter <<<\n");
    printf("----------------------------------------------\n\n");
    printf(">> Select Conversion Type:\n");
    printf("> 1.Binary Conversion\n");
    printf("> 2.Decimal Conversion\n");
    printf("> 3.Octal Conversion\n");
    printf("> 4.Hexadecimal Conversion\n");
    printf("> 5.Exit\n\n");

    printf("Choose a conversion type & hit enter: ");
    scanf("%d",&choice);
    //clearing the input buffer
    int c;
    while ((c=getchar()) !='\n' && c!=EOF) {}

    switch (choice)
    {
    case 1:
        binaryConversions(choice);
        break;

    case 2:
        decimalConversions(choice);
        break;

    case 3:
        octalConversions(choice);
        break;

    case 4:
        hexadecimalConversions(choice);
        break;

    case 5:
        exitMenu();
        break;
    default:
        system("cls");
        printf("=>INVALID CHOICE<=\n");
        mainMenu();
    }
}



void exitMenu()
{
        system("cls");
        printf("----------------------------------------------\n");
        printf(">>> Creator: {Team 4} <<<\n");
        printf("----------------------------------------------\n\n");
        printf("Hamed Azam , Worked on: All decimal conversions , All binary conversions , All octal conversions \n");
        printf("-------------------------------------------------------------------------------------------------------------------\n");
        printf("Gehad AbdulAziz , Worked on: All decimal conversions. \n");
        printf("-------------------------------------------------------------------------------------------------------------------\n");
        printf("Ghada Saeed , Worked on: All decimal conversions\n");
        printf("-------------------------------------------------------------------------------------------------------------------\n");
        printf("Malk Mostafa , Worked on: Conversions from octal to decimal and binary, conversion from decimal to octal.\n");
        printf("-------------------------------------------------------------------------------------------------------------------\n");
        printf("Nour Hatem , Worked on: Octal system conversions \n");
        printf("-------------------------------------------------------------------------------------------------------------------\n");
        printf("Omar Ayman , Worked on: All hexadecimal conversions And from octal and binary to decimal,writing the program code.\n");
        printf("-------------------------------------------------------------------------------------------------------------------\n");
        printf("Pola Talaat , Worked on: Binary system conversions\n");
        exit(0);

}



void decimalTryAgain(int choice)
{
    int  loopFlag=1;
    char charAnotherConversion;
    //clearing the input buffer
    int c;
    while ((c=getchar()) !='\n' && c!=EOF) {}

    do
    {
        printf("\nDo you want to convert another decimal number ? [y:Convert /N:Main menu]: ");
        charAnotherConversion=getchar();
        switch(charAnotherConversion)
        {
            case 'Y':
            case 'y':
                decimalConversions(choice);
                loopFlag=0;
                break;

            case 'n':
            case 'N':
                system("cls");
                loopFlag=0;
                mainMenu();
                break;

            default:
                system("cls");
                printf("----------------------------------------------\n");
                printf(">>> PLEASE CHOOSE EITHER A SMALL OR CAPITAL Y OR A SMALL OR CAPITAL N <<<\n");
                printf("----------------------------------------------\n\n");
        }
    }while(loopFlag);
}



void binaryTryAgain(int choice)
{
    int  loopFlag=1;
    char charAnotherConversion;

    //clearing the input buffer
    int c;
    while ((c=getchar()) !='\n' && c!=EOF) {}

    do
    {
        printf("\nDo you want to convert another binary number ? [y:Convert/N:Main menu]: ");
        charAnotherConversion=getchar();
        switch(charAnotherConversion)
        {
            case 'Y':
            case 'y':
                binaryConversions(choice);
                loopFlag=0;
                break;

            case 'n':
            case 'N':
                system("cls");
                loopFlag=0;
                mainMenu();
                break;

            default:
                system("cls");
                printf("----------------------------------------------\n");
                printf(">>> PLEASE CHOOSE EITHER A SMALL OR CAPITAL Y OR A SMALL OR CAPITAL N <<<\n");
                printf("----------------------------------------------\n\n");
        }
    }while(loopFlag);
}


void octalTryAgain(int choice)
{
    int  loopFlag=1;
    char charAnotherConversion;

    //clearing the input buffer
    int c;
    while ((c=getchar()) !='\n' && c!=EOF) {}

    do
    {
        printf("\nDo you want to convert another octal number ? [y:Convert/N:Main menu]: ");
        charAnotherConversion=getchar();
        switch(charAnotherConversion)
        {
            case 'Y':
            case 'y':
                octalConversions(choice);
                loopFlag=0;
                break;

            case 'n':
            case 'N':
                system("cls");
                loopFlag=0;
                mainMenu();
                break;

            default:
                system("cls");
                printf("----------------------------------------------\n");
                printf(">>> PLEASE CHOOSE EITHER A SMALL OR CAPITAL Y OR A SMALL OR CAPITAL N <<<\n");
                printf("----------------------------------------------\n\n");
        }
    }while(loopFlag);
}


void hexadecimalTryAgain(int choice)
{
    int  loopFlag=1;
    char charAnotherConversion;

    do
    {
        printf("\nDo you want to convert another hexadecimal number ? [y:Convert/N:Main menu]: ");
        charAnotherConversion=getchar();
        //clearing the input buffer
        int c;
        while ((c=getchar()) !='\n' && c!=EOF) {}
        switch(charAnotherConversion)
        {
            case 'Y':
            case 'y':
                hexadecimalConversions(choice);
                loopFlag=0;
                break;

            case 'n':
            case 'N':
                system("cls");
                loopFlag=0;
                mainMenu();
                break;

            default:
                system("cls");
                printf("----------------------------------------------\n");
                printf(">>> PLEASE CHOOSE EITHER A SMALL OR CAPITAL Y OR A SMALL OR CAPITAL N <<<\n");
                printf("----------------------------------------------\n\n");
        }
    }while(loopFlag);
}


void tryAgain(int choice)
{
    switch (choice)
    {
        case 1:
            binaryTryAgain(choice);
            break;
        case 2:
            decimalTryAgain(choice);
            break;
        case 3:
            octalTryAgain(choice);
            break;
        case 4:
            hexadecimalTryAgain(choice);
            break;
    }
}



// BinaryConversionFunctions:
double binaryToDecimal(int choice, int *isNegative, int *invalidDigit)
{
    system("cls");
    char binaryString[1024]; char *remainingString;
    double binary;
    double decimal = 0.0;
    int i, j, digit;
    unsigned long long int integerPart, fractionalPart;

    //Taking the number as a string
    printf("Enter a binary number: ");
    scanf("%s",&binaryString);


    //checking for invalid digits.
    int  n=strlen(binaryString)-1;
    for (int v=0; v<=n; v++)
    {
        if (!(( (binaryString[v]=='0' || binaryString[v]=='1') || binaryString[v]=='-' || binaryString[v]=='.'  )))
        {
            *invalidDigit=1;
            break;
        }
    }


    /*This part Converts in case the number is valid or showing an error message otherwise*/
    if (*invalidDigit)
    {
        system("cls");
        printf("=>A NON-BINARY DIGIT IS ENTERED<=\n");
    }

    else
    {
        //turn the string to a double
        binary=strtod(binaryString, &remainingString);
        // Check for negative input
        if (binary < 0)
        {
            *isNegative = 1;
            binary = -binary;  // Make binary positive for conversion
        }

        /*This part converts the number into decimal*/
        // Separate the integer and fractional parts
        integerPart = (unsigned long long int)binary;
        fractionalPart = (unsigned long long int)(binary * 10000 - integerPart * 10000);

        // Converting integer part
        for (i = 0; integerPart > 0; i++)
        {
            digit = integerPart % 10;
            decimal += digit * pow(2, i);
            integerPart /= 10;
        }
        //Reversing the fractional part so that it gets converted properly.
        int reversedFractionalPart=0,remainder=0;
        while (fractionalPart!=0)
        {
            remainder=fractionalPart%10;
            reversedFractionalPart*=10;
            reversedFractionalPart+=remainder;
            fractionalPart/=10;

        }
        //Converting fractional part
        for (j = 1; reversedFractionalPart > 0; j++)
        {
            digit = reversedFractionalPart % 10;
            decimal += digit * pow(2, -j);
            reversedFractionalPart /= 10;
        }

        return decimal;
    }
}

void binaryConversions(int choice)
{
    /*We convert from binary to decimal , and the converted value is passed to functions converting decimal to other systems
      to convert the number to them */
    int isNegative=0,invalidDigit=0;
    double decimal= binaryToDecimal(choice,&isNegative,&invalidDigit);

    if(invalidDigit)
    {
        tryAgain(choice);
    }
    else
    {
        printf("\n----------------------------------------------\n");
        printf(">>> Conversion Results <<<\n");
        printf("----------------------------------------------\n");

        (isNegative)?printf("Octal Number: -"):printf("Octal Number: "); decimalToOctal(decimal);
        (isNegative)?printf("Decimal Number: -%.6lf\n",decimal):printf("Decimal Number: %.6lf\n", decimal);
        (isNegative)?printf("Hexadecimal Number: -"):printf("Hexadecimal Number: "); decimalToHexadecimal(decimal);
        printf("\n");

        tryAgain(choice);
    }
}



// DecimalConversionFunctions:
void decimalToBinary(double decimal)
{
    //Removing the negative sign if it is there to convert properly.
    int isNegative=0;
    if(decimal<0)
    {
        decimal=-decimal;
        isNegative++;
    }


	int TempNUMBER, i=0 , number = decimal;
	double FractionPART=decimal -number;
	int intNumber[32] ,fractionNumber[32] ;

	//This loop converts the integer part of the decimal into binary but in reverse.
	while (number !=0)
	{
	    TempNUMBER=number;
	    intNumber[i]=TempNUMBER%2;
	    number/=2;
	    i++;
	}

    /*This part prints the converted number.*/

    //To add a negative sign if nessecary.
    if (isNegative)
    {
        printf("-");
    }

    //This loop prints the integer part of the binary converted from decimal .
	for (int j =i-1 ; j>=0 ; j--)
	{
	    printf("%d",intNumber[j]);
	}
	//This if statement prints the fraction part and the decimal point .
	if (FractionPART!=0)
    {
            printf(".");
            i=0;
        do
        {
            FractionPART*=2;
            fractionNumber[i]=(int)FractionPART;
            printf("%d",fractionNumber[i]);
            FractionPART-=(int)FractionPART;
            i++;
        }while (FractionPART>0.01 &&i<20);
    }
}


void decimalToOctal(double decimal)
{

    //Removing the negative sign if it is there to convert properly.
    int isNegative=0;
    if(decimal<0)
    {
        decimal=-decimal;
        isNegative++;
    }


    /*Splitting the decimal number to an integral part and a fractional part*/
    int integerPart = (int)decimal;
    double fractionalPart = decimal - integerPart;




    //converting the decimal integer part and storing it in a variable .//
    int OctalIntegerPart = 0, i = 1, rem;
        while (integerPart != 0)
    {
        rem = integerPart % 8;
        OctalIntegerPart += (rem * i);
        integerPart /= 8;
        i *= 10;
    }



    /*This part displays the coverted number*/
    // Display octal integer part//
    if (isNegative)  //To add a negative sign if nessecary.
    {
        printf("-");
    }
    printf("%d", OctalIntegerPart);

    //This part displays the fraction part.//
    printf(".");

    //precision determines how many times we are going to multiply//
    int precision=5;
    while (precision--)
    {
        fractionalPart *= 8;
        int octalnumber = (int)fractionalPart;
        printf("%d", octalnumber);
        fractionalPart -= octalnumber;
    }

    printf("\n");
}


void decimalToHexadecimal(double decimal)
{

    //Removing the negative sign if it is there to convert properly.
    int isNegative=0;
    if(decimal<0)
    {
        decimal=-decimal;
        isNegative++;
    }


    /*separating the floating-point number into its integral and fractional parts*/
    double number = decimal;
    int TempNmber = (int)number;
    double FractionNumber = number -TempNmber;


    /*one array to save int part in and another one for the fraction part*/
    int letterAndNumber[32] , letterANDnumberFRACTION[32];


    //This loop stores the converted number in the arrays.
    int i=0;
    while (TempNmber !=0)//operation on int part , and when the result of multiple division is ZERO , it will exit.
    {
            int num2 =TempNmber%16;;//taking the modulus cuz the output is the mod of number not anything else
            if (num2 >=0 && num2<=9){//make sure in any range the number is in
                letterAndNumber[i]=num2;//add the number in array
                }
            else if(num2 ==10){
                letterAndNumber[i]='A';// save the ASCII CODE
                }
            else if(num2 ==11){
                letterAndNumber[i]='B';// save the ASCII CODE
                }
            else if(num2 ==12){
                letterAndNumber[i]='C';// save the ASCII CODE
                }
            else if(num2 ==13){
                letterAndNumber[i]='D';// save the ASCII CODE
                }
            else if(num2 ==14){
                letterAndNumber[i]='E';// save the ASCII CODE
                }
            else if(num2 ==15){
                letterAndNumber[i]='F';// save the ASCII CODE
                }
            TempNmber =TempNmber /16;// reduce the value of number
            i++;
    }



    /*This part is for printing the converted number. The for loop prints the integer part
     ,and the following if statement deals with the fraction part*/


    if (isNegative)  //To add a negative sign if nessecary.
    {
        printf("-");
    }


    for (int j =i-1 ; j>=0;j--)//making j equal i-1"cuz the array start with 0 not 1 " to print the number right not inverse
    {
            if (letterAndNumber[j] >= 0 && letterAndNumber[j] <= 9)//if the number in the array is really number print the value of it
                printf("%d", letterAndNumber[j]);
            else// if the value is ASCII"not 0:9" , print the char , it depends on the operation that we made in "else if "
                printf("%c",letterAndNumber[j]);
    }


    if (FractionNumber!=0) //if there are a fraction , it will continue the code , if not , this is the end
    {
        printf(".");//the point in the decimal number with fraction
        i = 0 ;// new value cuz i will use it in the second array
        do//operation on fraction part
        {
            FractionNumber*=16;//making multiple multiplication
            int num2 =FractionNumber;// saving the int number cuz we will print it
            if (num2 >=0 && num2<=9)//THE SAME REASONS I SAID BEFORE
            {
                letterANDnumberFRACTION[i]=num2;
                printf("%d",letterANDnumberFRACTION[i]);// will print at the same time of operation
            }
            else if(num2 ==10){
                letterANDnumberFRACTION[i]='A';
                printf("%c",letterANDnumberFRACTION[i]);
                }
            else if(num2 ==11){
                letterANDnumberFRACTION[i]='B';
                printf("%c",letterANDnumberFRACTION[i]);
                }
            else if(num2 ==12){
                letterANDnumberFRACTION[i]='C';
                printf("%c",letterANDnumberFRACTION[i]);
                }
            else if(num2 ==13){
                letterANDnumberFRACTION[i]='D';
                printf("%c",letterANDnumberFRACTION[i]);
                }
            else if(num2 ==14){
                letterANDnumberFRACTION[i]='E';
                printf("%c",letterANDnumberFRACTION[i]);
                }
            else if(num2 ==15){
                letterANDnumberFRACTION[i]='F';
                printf("%c",letterANDnumberFRACTION[i]);
                }
        FractionNumber=FractionNumber-num2;//taking the fraction part
        i++;
        }while ( i<=32 &&FractionNumber>.001);// the end of the loop , AND END OF SMALL FUNCTION
    }
}


void decimalConversions(int choice)
{
    system("cls");
    char decimalString[1024]; char *remainingString;
    double decimal;
    printf("Enter a decimal number: ");
    scanf("%s",&decimalString);

    //checking for invalid digits.
    int invalidDigit=0, n=strlen(decimalString)-1;
    for (int v=0; v<=n; v++)
    {
        if (!(( (decimalString[v]>='0' && decimalString[v]<='9') || decimalString[v]=='-' || decimalString[v]=='.'  )))
        {
            invalidDigit=1;
            break;
        }
    }

    if (invalidDigit)
    {
        system("cls");
        printf("=>A NON-DECIMAL DIGIT IS ENTERED<=\n");
    }
    else
    {
        //turn the string to a double
        decimal=strtod(decimalString, &remainingString);
        printf("\n----------------------------------------------\n");
        printf(">>> Conversion Results <<<\n");
        printf("----------------------------------------------\n\n");
        printf("Binary Number: "); decimalToBinary(decimal);
        printf("\nOctal Number: "); decimalToOctal(decimal);
        printf("Hexadecimal Number: "); decimalToHexadecimal(decimal);
        printf("\n");
    }

    tryAgain(choice);

}



// OctalConversionFunctions:
double octalToDecimal(int choice, int *isNegative, int *invalidDigit)
{

    system("cls");
    char octalString[1024]; char *remainingString;
    double octal;
    double decimal = 0.0;
    int i, j, digit;
    unsigned long long int integerPart, fractionalPart;

    //Taking the number as a string
    printf("Enter an octal number: ");
    scanf("%s",&octalString);

    //checking for invalid digits.
    int  n=strlen(octalString)-1;
    for (int v=0; v<=n; v++)
    {
        if (!(( (octalString[v]>='0' && octalString[v]<='7') || octalString[v]=='-' || octalString[v]=='.'  )))
        {
            *invalidDigit=1;
            break;
        }
    }


    /*This part Converts in case the number is valid or showing an error message otherwise*/
    if (*invalidDigit)
    {
        system("cls");
        printf("=>A NON-OCTAL DIGIT IS ENTERED<=\n");
    }

    else
    {
        //turn the string to a double
        octal=strtod(octalString, &remainingString);

        // Check for negative input
        if (octal < 0)
        {
            *isNegative = 1;
            octal = -octal;  // Make octal positive for conversion
        }

        /*This part converts the number into decimal*/
        // Separate the integer and fractional parts
        integerPart = (unsigned long long int)octal;
        fractionalPart = (unsigned long long int)(octal * 10000 - integerPart * 10000);

        // integer part
        for (i = 0; integerPart > 0; i++)
        {
            digit = integerPart % 10;
            decimal += digit * pow(8, i);
            integerPart /= 10;
        }

        //Reversing the fractional part so that it gets converted properly.
        int reversedFractionalPart=0,remainder=0;
        while (fractionalPart!=0)
        {
            remainder=fractionalPart%10;
            reversedFractionalPart*=10;
            reversedFractionalPart+=remainder;
            fractionalPart/=10;

        }
        //fractional part
        for (j = 1; reversedFractionalPart > 0; j++)
        {
            digit = reversedFractionalPart % 10;
            decimal += digit * pow(8, -j);
            reversedFractionalPart /= 10;
        }

        return decimal;
    }

}
void octalConversions(int choice)
{
    /*We convert from octal to decimal , and the converted value is passed to functions converting decimal to other systems
      to convert the octal to them */
    int isNegative=0,invalidDigit=0;
    double decimal= octalToDecimal(choice,&isNegative,&invalidDigit);

    if(invalidDigit)
    {
        tryAgain(choice);
    }
    else
    {
        printf("\n----------------------------------------------\n");
        printf(">>> Conversion Results <<<\n");
        printf("----------------------------------------------\n\n");

        (isNegative)?printf("Binary Number: -"):printf("Binary Number: "); decimalToBinary(decimal);
        (isNegative)?printf("\nDecimal Number: -%.6lf\n",decimal):printf("\nDecimal Number: %.6lf\n", decimal);
        (isNegative)?printf("Hexadecimal Number: -"):printf("Hexadecimal Number: "); decimalToHexadecimal(decimal);

        tryAgain(choice);
    }
}



// HexadecimalConversionFunctions:
double hexadecimalToDecimal(int choice, int *isNegative, int *errorHexa)
{
    /*We convert from hexadecimal to decimal , and the converted value is passed to functions converting decimal to other systems
      to convert the number to them */
    system("cls");

    char hexa[100];
    int i, k, n, decimalPointIndex, fractionFlag=0, j=-1, decimalPointExists=0, isValidNegative=0;
    double decimal=0;

    printf("Enter a hexadecimal number: ");
    scanf("%s",&hexa);
    //clearing the input buffer
    int c;
    while ((c=getchar()) !='\n' && c!=EOF) {}

    n=strlen(hexa)-1;
    char  negativeHexa[n];



    //This part sees if the number entered is negative .
    if (hexa[0]=='-')
    {
        *isNegative=1;

    }


    for (k=0; k<=n; k++)
    {
        if (hexa[k]=='.')
        {
           decimalPointExists++;
           if (decimalPointExists==1)
           {
               decimalPointIndex=k;
           }

           if (decimalPointExists==2)
           {
               n=k-1;
           }

        }
        //To see if the number is a valid negative , in case it is a negative .
        if (hexa[k]=='-')
        {
            isValidNegative++;
        }
    }



    if (isValidNegative==1&&*isNegative==1)
    {
        strcpy(negativeHexa,hexa +1);
        n--;
        decimalPointIndex--;
    }

    if (isValidNegative>1)
    {
        system("cls");
        printf("=>MORE THAN ONE NEGATIVE IS ENTERED<=\n");
        *errorHexa=1;
    }
    else
    {

            /*This loop's job is to convert the hexadecimal number into a decimal .
        To get the integer value of the charachters from '0' to '9' ,we subtract 48 from their ASCII values
        E.G.  '9'-48=9
               57-48=9  {57 ASCII of '9' }
        To get the integer value of the charachters from 'A' to 'F' ,we subtract 55 from their ASCII values
        E.G.  'F'-55=15
              70-55=15  {70 ASCII of 'F' }
        To get the integer value of the charachters from '0' to '9' ,we subtract 87 from their ASCII values
        E.G.  'f'-87=9
              102-87=9  {57 ASCII of 'f' }
             */
        for (i=0; i<=n; i++)
        {
            if((*isNegative?negativeHexa[i]:hexa[i])=='.')
            {
                fractionFlag=1;
                continue;
            }

            if (fractionFlag)
            {

                if((*isNegative?negativeHexa[i]:hexa[i])>='0' && (*isNegative?negativeHexa[i]:hexa[i])<='9')
                {
                    decimal+=((*isNegative?negativeHexa[i]:hexa[i])-48)*pow(16,j);
                    j--;
                }

                else if((*isNegative?negativeHexa[i]:hexa[i])>='A' && (*isNegative?negativeHexa[i]:hexa[i])<='F')
                {
                    decimal+=((*isNegative?negativeHexa[i]:hexa[i])-55)*pow(16,j);
                    j--;
                }

                else if((*isNegative?negativeHexa[i]:hexa[i])>='a' && (*isNegative?negativeHexa[i]:hexa[i])<='f')
                {
                    decimal+=((*isNegative?negativeHexa[i]:hexa[i])-87)*pow(16,j);
                    j--;
                }

                else
                {
                    system("cls");
                    printf("=>A NON-HEXADECIMAL DIGIT IS ENTERED\n");
                    *errorHexa=1;
                }
            }
            else
            {
                if((*isNegative?negativeHexa[i]:hexa[i])>='0' && (*isNegative?negativeHexa[i]:hexa[i])<='9')
                {
                    decimal+=((*isNegative?negativeHexa[i]:hexa[i])-48)*(( decimalPointExists )?pow(16,decimalPointIndex-i-1):pow(16,n-i));
                }

                else if((*isNegative?negativeHexa[i]:hexa[i])>='A' && (*isNegative?negativeHexa[i]:hexa[i])<='F')
                {
                    decimal+=((*isNegative?negativeHexa[i]:hexa[i])-55)*(( decimalPointExists )?pow(16,decimalPointIndex-i-1):pow(16,n-i));
                }

                else if((*isNegative?negativeHexa[i]:hexa[i])>='a' && (*isNegative?negativeHexa[i]:hexa[i])<='f')
                {
                    decimal+=((*isNegative?negativeHexa[i]:hexa[i])-87)*(( decimalPointExists )?pow(16,decimalPointIndex-i-1):pow(16,n-i));
                }
                else
                {
                    system("cls");
                    printf("=>A NON-HEXADECIMAL DIGIT IS ENTERED\n");
                    *errorHexa=1;
                }
            }
        }

    }
    return decimal;
}


void hexadecimalConversions(int choice)
{
    int isNegative=0;
    int errorHexa=0;
    double decimal= hexadecimalToDecimal(choice,&isNegative,&errorHexa);

    if (errorHexa)
    {
        tryAgain(choice);
    }
    else
    {
        printf("\n----------------------------------------------\n");
        printf(">>> Conversion Results <<<\n");
        printf("----------------------------------------------\n\n");

        (isNegative)?printf("Binary Number: - "):printf("Binary Number: "); decimalToBinary(decimal);
        (isNegative)?printf("\nOctal Number: - "):printf("\nOctal Number: "); decimalToOctal(decimal);
        (isNegative)?printf("Decimal Number: - %.6lf \n",decimal):printf("Decimal Number: %.6lf \n",decimal);

        tryAgain(choice);
    }

}
