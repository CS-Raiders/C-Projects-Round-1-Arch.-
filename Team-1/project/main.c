#include<math.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define MAX 1000

//menu functions
//menu functions
void mainMenu()
{
    char choice[10];
    printf("===========================================\n");
    printf("\033[1;33m    Welcome To Number System Converter \033[0m\n");
    printf("===========================================\n");
    printf("\n");
    printf("\n");
    printf("\033[1;31m>>\033[0m");
    printf(" Please select a type conversion from the list below ");
    printf("\033[1;31m<<\033[0m\n");
    printf("\n");
    printf("\033[1;31m1.\033[0m Binary Conversion\n");
    printf("\033[1;31m2.\033[0m Decimal Conversion\n");
    printf("\033[1;31m3.\033[0m Octal Conversion\n");
    printf("\033[1;31m4.\033[0m Hexadecimal Conversion\n");
    printf("\033[1;31m5.\033[0m Exit the program\n");
    printf("Choose a number then press enter: ");
    userInput(choice[10]);
}

void exitMenumes()
{
    printf("=========================================================\n");
    printf("\033[1;33m     Thank you for using our Console Application ^_^\033[0m\n");
    printf("=========================================================\n");
    printf("\n");
    printf("\033[1;31m*\033[0m Project \"Number System Converter\" \033[1;31m*\033[0m\n");
    printf("   Version 1.0.0\n");
    printf("\n");
    printf("\033[1;31m*\033[0m Made with passion by:\033[1;33m MemszCode\033[0m \033[1;31m*\033[0m\n");
    printf("\n");
    printf("\n");
    printf("\033[1;31m*\033[0m Members and their Roles: \033[1;31m*\033[0m\n");
    printf("\033[1;32m   1.\033[0m Sobih Mohamed -> {Binary ==> Decimal\n\t\t\tBinary ==> Octal\n\t\t\tBinary ==> Hexadecimal,in the binary function}\n\n");
    printf("\033[1;32m   2.\033[0m Mostafa Mohamed -> {Octal ==> Decimal,in the octal function\n\t\t\t Hexadecimal ==> Decimal,in the hexadecimal function}\n\n");
    printf("\033[1;32m   3.\033[0m Malak Hassan -> {Decimal ==> Binary\n\t\t\tDecimal ==> Octal\n\t\t\tDecimal ==> Hexadecimal \"FractionalPart\" ,in the decimal function}\n\n" );
    printf("\033[1;32m   4.\033[0m Zeyad Abdalla -> {Responsible for the overall design, tryagain() functions and code structure.\n\t\t\tDecimal ==> binary,in the hexadecimal function }\n\n" );
    printf("\033[1;32m   5.\033[0m Mai Bakry -> {Decimal ==> Octal,in the hexadecimal function\n\t\t\tDecimal ==> Hexadecimal,in the octal function\n\t\t\tSecretMes}\n\n" );
    printf("\033[1;32m   6.\033[0m Sondos Khaled -> {Octal ==> Binary,in the octal function}\n\n" );
    printf("\033[1;32m   7.\033[0m Menna Allah Hesham -> {Decimal ==> Binary\n\t\tDecimal ==> Octal\n\t\tDecimal ==> Hexadecimal \"IntegralPart\" ,in the decimal function}\n\n" );
    printf("\n");
    printf("\n");
    printf("\n");
    printf("=========================================================\n");
}


void exitMenu()
{
    printf("=========================================================\n");
    printf("\033[1;33m     Thank you for using our Console Application ^_^\033[0m\n");
    printf("=========================================================\n");
    printf("\n");
    printf("\033[1;31m*\033[0m Project \"Number System Converter\" \033[1;31m*\033[0m\n");
    printf("   Version 1.0.0\n");
    printf("\n");
    printf("\033[1;31m*\033[0m Made with passion by:\033[1;33m MemszCode\033[0m \033[1;31m*\033[0m\n");
    printf("\n");
    printf("\n");
    printf("\033[1;31m*\033[0m Members and their Roles: \033[1;31m*\033[0m\n");
    printf("\033[1;32m   1.\033[0m Sobih Mohamed -> {Binary ==> Decimal\n\t\t\tBinary ==> Octal\n\t\t\tBinary ==> Hexadecimal,in the binary function}\n\n");
    printf("\033[1;32m   2.\033[0m Mostafa Mohamed -> {Octal ==> Decimal,in the octal function\n\t\t\t Hexadecimal ==> Decimal,in the hexadecimal function}\n\n");
    printf("\033[1;32m   3.\033[0m Malak Hassan -> {Decimal ==> Binary\n\t\t\tDecimal ==> Octal\n\t\t\tDecimal ==> Hexadecimal \"FractionalPart\" ,in the decimal function}\n\n" );
    printf("\033[1;32m   4.\033[0m Zeyad Abdalla -> {Responsible for the overall design, tryagain() functions and code structure.\n\t\t\tDecimal ==> binary,in the hexadecimal function }\n\n" );
    printf("\033[1;32m   5.\033[0m Mai Bakry -> {Decimal ==> Octal,in the hexadecimal function\n\t\t\tDecimal ==> Hexadecimal,in the octal function\n\t\t\tSecretMes}\n\n" );
    printf("\033[1;32m   6.\033[0m Sondos Khaled -> {Octal ==> Binary,in the octal function}\n\n" );
    printf("\033[1;32m   7.\033[0m Menna Allah Hesham -> {Decimal ==> Binary\n\t\tDecimal ==> Octal\n\t\tDecimal ==> Hexadecimal \"IntegralPart\" ,in the decimal function}\n\n" );
    printf("\n");
    printf("\n");
    printf("\n");
    printf("=========================================================\n");
    secret_mes();

}

//clear menus and input buffer function
void clearMenuAndInputBuffer()
{
    while (getchar() != '\n');
    system("cls");
}



///////////////////////////////////////////////////////////////

void showBinaryMenu()
{
    int isbinary(const char *str)
    {
        int i=0;
        int is_more_than_one_point=0;
        for ( i = 0; str[i] != '\0'; i++)//101.101
        {
            if (str[i] != '0' && str[i] != '1' && str[i] != '.')return 0;
            if(str[i]=='.')is_more_than_one_point++;
            if(is_more_than_one_point>1)return 0;
        }
        if(str[0]=='.'&&i==1)return 0;
        return 1;
    }



    double binaryToDecimal(char *str)
    {
        long fraction_number = 0, int_number = 0, decimal_point = 0;
        double sum_of_fracrion=0;
        int j=-1;

        for (int i = 0; str[i] != '\0'; i++)
        {
            if (str[i] == '.')
            {
                decimal_point = 1;
                continue;
            }

            if (decimal_point)
            {
                fraction_number =(str[i] - '0');
                sum_of_fracrion=sum_of_fracrion+(double)fraction_number*pow(2, j);
                j--;
            }
            else
            {
                int_number = int_number * 10 + (str[i] - '0');
            }
        }


        long sum_int = 0;
        for (int i = 0; int_number != 0; i++)
        {
            int rem = int_number % 10;
            sum_int = sum_int + (long)rem * pow(2, i);
            int_number /= 10;
        }

        return (sum_of_fracrion+ (double)sum_int);
    }

    void DECIMAL_TO_OCTAL(double decimal_num,char *str)
    {
        long num_in_int= decimal_num;
        double num_in_fraction=decimal_num-(long)decimal_num;
        long result_of_int=0,posetion=1;

        for(int i=0; num_in_int!=0; num_in_int/=8,i++)
        {
            int reminder_1= num_in_int%8;
            result_of_int=result_of_int+reminder_1*posetion;
            posetion*=10;
        }

        printf("The number %s in binary is = \033[1;33m%li\033[0m", str,result_of_int);
        if(num_in_fraction!=num_in_int) printf(".");

        long result_of_fraction=0;
        for(int i=0; i<10&&num_in_fraction>0; i++)
        {
            num_in_fraction*=8;
            int digit=(int)num_in_fraction;
            printf("\033[1;33m%d\033[0m",digit);
            num_in_fraction-=digit;
        }
        printf(" in OCTAL\n");
        return;
    }
    void DECIMAL_TO_HEXA(double decimal_num,char *str )
    {
        long num_in_int= decimal_num;
        double num_in_fraction=decimal_num-(long)decimal_num;
        char hexa[30];
        printf("The number %s in binary is = ",str);
        int i=0,test_to_print_zero=0;

        for( i; num_in_int!=0; num_in_int/=16,i++)
        {
            test_to_print_zero=1;
            int reminder_1= num_in_int%16;
            if(reminder_1==10)hexa[i]='A';
            if(reminder_1==11)hexa[i]='B';
            if(reminder_1==12)hexa[i]='C';
            if(reminder_1==13)hexa[i]='D';
            if(reminder_1==14)hexa[i]='E';
            if(reminder_1==15)hexa[i]='F';
            if(reminder_1<10||reminder_1>15)hexa[i]='0'+reminder_1;
        }

        for(int j=i-1; hexa[j]!='\0'&&j>=0; j--)
        {
            printf("\033[1;33m%c\033[0m",hexa[j]);
        }
        if(test_to_print_zero==0)printf("\033[1;33m0\033[0m");
        if(num_in_fraction!=num_in_int) printf(".");
        for(int i=0; i<10&&num_in_fraction>0; i++)
        {
            num_in_fraction*=16;
            int digit=(int)num_in_fraction;
            if(digit==10)printf("\033[1;33mA\033[0m");
            if(digit==11)printf("\033[1;33mB\033[0m");
            if(digit==12)printf("\033[1;33mC\033[0m");
            if(digit==13)printf("\033[1;33mD\033[0m");
            if(digit==14)printf("\033[1;33mE\033[0m");
            if(digit==15)printf("\033[1;33mF\033[0m");
            if(digit<10||digit>15)printf("\033[1;33m%d\033[0m",digit);;
            num_in_fraction-=digit;
        }

        printf(" in HEXA_DECIMAL\n");
        return;
    }
    char str[20];

    do
    {
        printf("Please enter a binary number ==>(0,1)<==\n");
        scanf("%s", str);

        if (isbinary(str))
        {
            break;
        }
        else
        {
            printf("\033[1;31mError, Invalid binary number. Please enter it again\033[0m\n");
        }
    }
    while (1);

    double decimal_num=binaryToDecimal(str);
    printf("The number %s in binary is = \033[1;33m%lf\033[0m in DECIMAL\n", str, decimal_num);
    DECIMAL_TO_OCTAL(decimal_num,str);
    DECIMAL_TO_HEXA(decimal_num,str);
    tryAgainBinary();
    return 0;
}



void showDecMenu()
{
    int binary(double decimal_number)
    {
        long long int binary_number=0,remainder=0,postion=1;
        int int_decimal_number=(int)decimal_number;
        double fraction=decimal_number-int_decimal_number;

        //جزء الرقم الصحيح
        while(int_decimal_number>0)
        {
            remainder = int_decimal_number%2;
            int_decimal_number=int_decimal_number/2;
            binary_number = binary_number+(remainder*postion);
            postion = postion*10;


        }
        printf("\033[1;33m%lld\033[0m",binary_number);


        if(fraction ==0)
        {
            return;
        }
        else
        {
            printf("\033[1;33m.\033[0m");
        }

        //جزء الرقم الكسري

        int j=0;//any variable(اي متغير)
        while(fraction>0 && j<10)
        {
            fraction=fraction*2;
            int i=(int)fraction;//any variable(اي متغير)
            printf("\033[1;33m%d\033[0m",i);
            fraction=fraction-i;
            j++;
        }
    }


    int octal(double decimal_number)
    {
        //نلاحظ انا مغيرتش الكود بنفس المتغيرات لكن كل واحد في الفانكشن بتاعته


        int binary_number=0,remainder=0,postion=1;
        int int_decimal_number=(int)decimal_number;
        double fraction=decimal_number-int_decimal_number;

        //جزء الرقم الصحيح
        while(int_decimal_number>0)
        {
            remainder = int_decimal_number%8;
            int_decimal_number=int_decimal_number/8;
            binary_number = binary_number+(remainder*postion);
            postion = postion*10;


        }
        printf("\033[1;33m%d\033[0m",binary_number);

        if(fraction ==0)
        {
            return;
        }
        else
        {
            printf("\033[1;33m.\033[0m");
        }



        //جزء الرقم الكسري

        int j=0;//any variable(اي متغير)
        while(fraction>0 && j<10)
        {
            fraction=fraction*8;
            int i=(int)fraction;//any variable(اي متغير)
            printf("\033[1;33m%d\033[0m",i);
            fraction=fraction-i;
            j++;
        }
    }

    int hexa(double decimal_number)
    {

        int int_decimal_number=(int)decimal_number;
        double fraction = decimal_number-int_decimal_number;
        char hexa[100];
        int index = 0;//القيمه في الاراي
        if (int_decimal_number == 0)
        {
            printf("\033[1;33m0\033[0m");
        }
        else
        {
            while ( int_decimal_number!= 0)
            {
                int remainder = int_decimal_number % 16;
                if (remainder < 10)
                {
                    hexa[index++] = '0' + remainder;
                }
                else
                {
                    hexa[index++] = 'A' + (remainder - 10);
                }
                int_decimal_number /= 16;
            }
        }


        while (--index >= 0)
        {
            printf("\033[1;33m%c\033[0m", hexa[index]);
        }


        if(fraction ==0)
        {
            return;
        }
        else
        {
            printf("\033[1;33m.\033[0m");
        }




        int j=0;//any variable
        while(fraction>0 && j<10)
        {
            fraction=fraction*16;
            int i=(int)fraction;//any variable
            if(i>=10 && i<=15)
            {
                if(i==10)
                {
                    printf("\033[1;33mA\033[0m");
                }
                else if(i==11)
                {
                    printf("\033[1;33mB\033[0m");
                }
                else if(i==12)
                {
                    printf("\033[1;33mC\033[0m");
                }
                else if(i==13)
                {
                    printf("\033[1;33mD\033[0m");
                }
                else if(i==14)
                {
                    printf("\033[1;33mE\033[0m");
                }
                else
                {
                    printf("\033[1;33mF\033[0m");
                }
            }
            else
            {
                printf("\033[1;33m%d\033[0m",i);
            }

            fraction=fraction-i;
            j++;
        }


    }


    double decimal_number;
    char dot;

    printf("Please enter the number in decimal: ");

    if (scanf("%lf%c", &decimal_number, &dot) != 2 || dot != '\n')
    {
        printf("\033[1;31mInvalid Input. Please enter a valid decimal number.\033[0m\n");
        while (getchar() != '\n');
        showDecMenu();
        return 0;
    }

    printf("Binary equivalent: ");
    binary(decimal_number);

    printf("\nOctal equivalent: ");
    octal(decimal_number);

    printf("\nHexadecimal equivalent: ");
    hexa(decimal_number);

    printf("\n");
    tryAgainDec();
}

void showOctaMenu()
{

    double OCTAL_DECI()
    {
        char OCTAL_NUM[100];
        double DECI_NUM=0;
        long Count_22=0,POWER_1=-1;
        int Count_11=0;
        printf("Enter an Octal Number: ");
        scanf("%s",&OCTAL_NUM);

        while(OCTAL_NUM[Count_11]!='\0')
        {
            while(OCTAL_NUM[0]==46&&OCTAL_NUM[1]=='\0')
            {
                printf("\033[1;31mInvalid Number\033[0m\n");
                printf("Please,Enter an Octal Number: ");
                scanf("%s",&OCTAL_NUM);
            }
            switch(OCTAL_NUM[Count_11])
            {
            case '0' ... '7':
                Count_11=Count_11+1;
                break;
            case 46:
                Count_11=Count_11+1;
                while(OCTAL_NUM[Count_11]!='\0')
                {
                    if(OCTAL_NUM[Count_11]>=48&&OCTAL_NUM[Count_11]<=55)
                    {
                        Count_11=Count_11+1;
                    }
                    else
                    {
                        printf("\033[1;31mInvalid Number\033[0m\n");
                        printf("Please,Enter an Octal Number: ");
                        scanf("%s",&OCTAL_NUM);
                        Count_11=0;
                        break;
                    }
                }
                break;
            default:
                printf("\033[1;31mInvalid Number\033[0m\n");
                printf("Please,Enter an Octal Number: ");
                scanf("%s",&OCTAL_NUM);
                Count_11=0;
                break;
            }
        }

        while((OCTAL_NUM[Count_22]>=48&&OCTAL_NUM[Count_22]<=55))
        {
            Count_22=Count_22+1;
            POWER_1=POWER_1+1;
        }

        Count_22=0;
        while((OCTAL_NUM[Count_22]>=48&&OCTAL_NUM[Count_22]<=55)||OCTAL_NUM[Count_22]==46)
        {
            switch (OCTAL_NUM[Count_22])
            {
            case 48 ... 55:
                DECI_NUM=DECI_NUM+(OCTAL_NUM[Count_22]-48)*pow(8,POWER_1);
                Count_22++;
                POWER_1=POWER_1-1;
                break;
            case 46:
                Count_22=Count_22+1;
                POWER_1=-1;
                while(OCTAL_NUM[Count_22]>=48&&OCTAL_NUM[Count_22]<=55)
                {
                    switch (OCTAL_NUM[Count_22])
                    {
                    case 48 ... 55:
                        DECI_NUM=DECI_NUM+(OCTAL_NUM[Count_22]-48)*pow(8,POWER_1);
                        Count_22++;
                        POWER_1=POWER_1-1;
                        break;
                    }
                }
            }
        }
        return DECI_NUM;

    }


    void DecimalToBinary(double DECI_NUM)
    {
        int integerPart = (int)DECI_NUM;
        double fractionalPart = DECI_NUM - integerPart;
        int intArr[100], fracArr[100];
        int intgCounter = 0, fracCounter = 0;

        while (integerPart != 0)
        {
            int rem = integerPart % 2;
            intArr[intgCounter] = rem;
            intgCounter++;
            integerPart /= 2;
        }
        while (fractionalPart != 0)
        {
            fractionalPart *= 2;
            fracArr[fracCounter] = (int)fractionalPart;
            fracCounter++;
            fractionalPart -= (int)fractionalPart;
        }
        printf("Binary equivalent: ");
        if (intgCounter == 0)
        {
            printf("\033[1;33m0\033[0m");
        }
        else
        {
            for (int i = intgCounter - 1; i >= 0; i--)
            {
                printf("\033[1;33m%d\033[0m", intArr[i]);
            }
        }
        if (fracCounter > 0)
        {
            printf("\033[1;33m.\033[0m");
            for (int i = 0; i < fracCounter; i++)
            {
                printf("\033[1;33m%d\033[0m", fracArr[i]);


            }
        }
        printf("\n");
    }
    void Hexadecimal_converter(double DECI_NUM)
    {
        int integerPart = (int)DECI_NUM;
        double fractionalPart = DECI_NUM - integerPart;
        int intArr[10], fracArr[10];
        int intgCounter = 0, fracCounter = 0;
        while (integerPart != 0)
        {
            int rem = integerPart % 16;
            intArr[intgCounter] = rem;
            intgCounter++;
            integerPart /= 16;
        }
        while (fractionalPart != 0)
        {
            fractionalPart *= 16;
            fracArr[fracCounter] = (int)fractionalPart;
            fracCounter++;
            fractionalPart -= (int)fractionalPart;
        }
        printf("Hexadecimal equivalent: ");
        if (intgCounter == 0)
        {
            printf("\033[1;33m0\033[0m");
        }
        else
        {
            for (int i = intgCounter - 1; i >= 0; i--)
            {
                if (intArr[i] < 10)
                {
                    printf("\033[1;33m%d\033[0m", intArr[i]);
                }
                else
                {
                    printf("\033[1;33m%c\033[0m", intArr[i] + 55);
                }
            }
        }
        if (fracCounter > 0)
        {
            printf("\033[1;33m.\033[0m");
            for (int i = 0; i < fracCounter; i++)
            {
                if (fracArr[i] < 10)
                {
                    printf("\033[1;33m%d\033[0m", fracArr[i]);
                }
                else
                {
                    printf("\033[1;33m%c\033[0m", fracArr[i] + 55);
                }
            }
        }
        printf("\n");

    }

    double DECI_NUM = OCTAL_DECI();
    printf("Decimal Equivalent: \033[1;33m%lf\033[0m\n", DECI_NUM);
    DecimalToBinary(DECI_NUM);
    Hexadecimal_converter(DECI_NUM);
    tryAgainOcta();
}

// Hexadecimal to Decimal conversion
double HEXA_DECI()
{
    char HEXA_NUM[100];
    double DECI_NUM=0;
    long Count_2=0,POWER=-1;
    int Count_1=0;
    printf("Enter a Hexadecimal Number: ");
    scanf("%s",&HEXA_NUM);
    while(HEXA_NUM[Count_1]!='\0')
    {
        while(HEXA_NUM[0]==46&&HEXA_NUM[1]=='\0')
        {
            printf("Invalid Number\n");
            printf("Please,Enter a Hexadecimal Number: ");
            scanf("%s",&HEXA_NUM);
        }
        switch(HEXA_NUM[Count_1])
        {
        case '0' ... '9':
            Count_1=Count_1+1;
            break;
        case 'A' ... 'F':
            Count_1=Count_1+1;
            break;
        case 46:
            Count_1=Count_1+1;
            while(HEXA_NUM[Count_1]!='\0')
            {
                if((HEXA_NUM[Count_1]>='A'&&HEXA_NUM[Count_1]<='F')||(HEXA_NUM[Count_1]>=48&&HEXA_NUM[Count_1]<=57))
                {
                    Count_1=Count_1+1;
                }
                else
                {
                    printf("\033[1;31mInvalid Number\033[0m\n");
                    printf("Please,Enter a Hexadecimal Number: ");
                    scanf("%s",&HEXA_NUM);
                    Count_1=0;
                    break;
                }
            }
            break;
        default:
            printf("\033[1;31mInvalid Number\033[0m\n");
            printf("Please,Enter a Hexadecimal Number: ");
            scanf("%s",&HEXA_NUM);
            Count_1=0;
            break;
        }
    }
    while((HEXA_NUM[Count_2]>=65&&HEXA_NUM[Count_2]<=70)||(HEXA_NUM[Count_2]>=48&&HEXA_NUM[Count_2]<=57))
    {
        Count_2=Count_2+1;
        POWER=POWER+1;
    }
    Count_2=0;
    while((HEXA_NUM[Count_2]>=65&&HEXA_NUM[Count_2]<=70)||(HEXA_NUM[Count_2]>=48&&HEXA_NUM[Count_2]<=57)||HEXA_NUM[Count_2]==46)
    {
        switch (HEXA_NUM[Count_2])
        {
        case 48 ... 57:
            DECI_NUM=DECI_NUM+(HEXA_NUM[Count_2]-48)*pow(16,POWER);
            Count_2++;
            POWER=POWER-1;
            break;
        case 65 ... 70:
            DECI_NUM=DECI_NUM+(HEXA_NUM[Count_2]-55)*pow(16,POWER);
            Count_2++;
            POWER=POWER-1;
            break;
        case 46:
            Count_2=Count_2+1;
            POWER=-1;
            while((HEXA_NUM[Count_2]>=65&&HEXA_NUM[Count_2]<=70)||(HEXA_NUM[Count_2]>=48&&HEXA_NUM[Count_2]<=57))
            {
                switch (HEXA_NUM[Count_2])
                {
                case 48 ... 57:
                    DECI_NUM=DECI_NUM+(HEXA_NUM[Count_2]-48)*pow(16,POWER);
                    Count_2++;
                    POWER=POWER-1;
                    break;
                case 65 ... 70:
                    DECI_NUM=DECI_NUM+(HEXA_NUM[Count_2]-55)*pow(16,POWER);
                    Count_2++;
                    POWER=POWER-1;
                    break;
                }
            }
        }
    }

    return DECI_NUM;  //returning the value of hexadecimal to decimal.
}


//hexadecimal menu and their conversions
void showHexaDecimalMenu()
{
    double decimal = HEXA_DECI();

    if (decimal != -1)
    {
        printf("Decimal Equivalent: \033[1;33m%lf\033[0m\n", decimal);
    }

    int integerPart = (int)decimal;
    double fractionalPart = decimal - integerPart;
    long long octal = 0;
    int pos = 1;
    while (integerPart != 0)
    {
        int rem = integerPart % 8;
        octal += rem * pos;
        pos *= 10;
        integerPart /= 8;
    }
    printf("Octal equivalent: \033[1;33m%lld\033[0m", octal);
    if (fractionalPart != 0)
    {
        printf("\033[1;33m.\033[0m");
        int numofdigits= 6;
        while (fractionalPart != 0 && numofdigits > 0)
        {
            fractionalPart *= 8;
            int digit = (int)fractionalPart;
            printf("\033[1;33m%d\033[0m", digit);
            fractionalPart -= digit;
            numofdigits--;
        }
    }

    printf("\n");

    double binDecimal = decimal;

    int binaryintegerPart = (int)binDecimal;
    double binaryfractionPart = binDecimal - binaryintegerPart;

    long long int BinIntegerPart = 0, BinMultiplier = 1;

    while(binaryintegerPart != 0)
    {
        int digit = binaryintegerPart % 2;
        BinIntegerPart = BinIntegerPart + (digit * BinMultiplier);
        binaryintegerPart /= 2;
        BinMultiplier *= 10;
    }

    printf("Binary Equivalent: ");
    printf("\033[1;33m%lld\033[0m", BinIntegerPart);
    if(binaryfractionPart != 0.0)
    {
        printf("\033[1;33m.\033[0m");
        int maxPrecision = 10;
        int precision = 0;

        while(binaryfractionPart > 0.0 && precision < maxPrecision)
        {
            binaryfractionPart *= 2;
            printf("\033[1;33m%lld\033[0m", (long long int)binaryfractionPart);
            binaryfractionPart -= (long long int)binaryfractionPart;
            precision++;
        }
    }
    printf("\n");

    tryAgainHexa(); //try again function based on user input

}


//try again funcion

void tryAgainErrHandle()
{
    printf("\033[1;31mYou can type [y/yes] or [n/no]\n\033[0m");
}

void tryAgainHexa()
{

    char choice[10];

    printf("Do you want to try another number? [y / n]: ");
    scanf("%s", choice);

    if (strcasecmp(choice, "y") == 0 || strcasecmp(choice, "yes") == 0 ||
            strcasecmp(choice, "n") == 0 || strcasecmp(choice, "no") == 0)
    {
        clearMenuAndInputBuffer();
        if(strcasecmp(choice, "y") == 0 || strcasecmp(choice, "yes") == 0)
        {
            showHexaDecimalMenu();
        }
        else
        {
            mainMenu();
        }

    }
    else
    {
        tryAgainErrHandle();
        tryAgainHexa();
    }
}

void tryAgainOcta()
{

    char choice[10];

    printf("Do you want to try another number? [y / n]: ");
    scanf("%s", choice);

    if (strcasecmp(choice, "y") == 0 || strcasecmp(choice, "yes") == 0 ||
            strcasecmp(choice, "n") == 0 || strcasecmp(choice, "no") == 0)
    {
        clearMenuAndInputBuffer();
        if(strcasecmp(choice, "y") == 0 || strcasecmp(choice, "yes") == 0)
        {
            showOctaMenu();
        }
        else
        {
            mainMenu();
        }

    }
    else
    {
        tryAgainErrHandle();
        tryAgainOcta();
    }
}


void tryAgainDec()
{

    char choice[10];

    printf("Do you want to try another number? [y / n]: ");
    scanf("%s", choice);

    if (strcasecmp(choice, "y") == 0 || strcasecmp(choice, "yes") == 0 ||
            strcasecmp(choice, "n") == 0 || strcasecmp(choice, "no") == 0)
    {
        clearMenuAndInputBuffer();
        if(strcasecmp(choice, "y") == 0 || strcasecmp(choice, "yes") == 0)
        {
            showDecMenu();
        }
        else
        {
            mainMenu();
        }

    }
    else
    {
        tryAgainErrHandle();
        tryAgainDec();
    }
}


void tryAgainBinary()
{
    char choice[10];

    printf("Do you want to try another number? [y / n]: ");
    scanf("%s", choice);

    if (strcasecmp(choice, "y") == 0 || strcasecmp(choice, "yes") == 0 ||
            strcasecmp(choice, "n") == 0 || strcasecmp(choice, "no") == 0)
    {
        clearMenuAndInputBuffer();
        if(strcasecmp(choice, "y") == 0 || strcasecmp(choice, "yes") == 0)
        {
            showBinaryMenu();
        }
        else
        {
            mainMenu();
        }

    }
    else
    {
        tryAgainErrHandle();
        tryAgainBinary();
    }
}
//user input function that checks the input from user. if user is n, call the function.
void userInput()
{
    char choise[10];
    scanf("%s", &choise);
    if(strcmp(choise,"5")==0)
    {
        clearMenuAndInputBuffer();
        exitMenu();
    }
    if(strcmp(choise,"4")==0)
    {
        clearMenuAndInputBuffer();
        //calling the showhexadecimalmenu() function because the user chose 4
        showHexaDecimalMenu();
    }
    if (strcmp(choise,"3")==0)
    {
        clearMenuAndInputBuffer();
        showOctaMenu();
    }

    if(strcmp(choise,"2")==0)
    {
        clearMenuAndInputBuffer();
        showDecMenu();
    }

    if(strcmp(choise,"1")==0)
    {
        clearMenuAndInputBuffer();
        showBinaryMenu();
    }
    if(!(strcmp(choise,"5")==0|| strcmp(choise,"4")==0 || strcmp(choise,"3")==0||strcmp(choise,"2")==0 || strcmp(choise,"1")==0))
    {
        clearMenuAndInputBuffer();
        printf("\033[1;31mPlease choose numbers only form the numbered list!.\n\033[0m");
        mainMenu();
    }
}

void secret_mes()
{

    char choice[10];

    printf("Do you want our Secret Message? [y / n]: ");
    scanf("%s", choice);

    if (strcasecmp(choice, "y") == 0 || strcasecmp(choice, "yes") == 0 ||
            strcasecmp(choice, "n") == 0 || strcasecmp(choice, "no") == 0)
    {
        clearMenuAndInputBuffer();
        if(strcasecmp(choice, "y") == 0 || strcasecmp(choice, "yes") == 0)
        {
            message();
        }
        else
        {
            exitMenumes();
        }

    }
    else
    {
        tryAgainErrHandle();
        secret_mes();
    }
}


void message()
{
    printf("Just wanted to shout out our amazing programming crew! \nYour skills and dedication make our projects rock.\nEach one of you is a key player, and I'm grateful for the fantastic teamwork. Let's keep coding brilliance together!");
}

int main()
{
    mainMenu();
}
