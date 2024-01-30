#include<string.h>
#include <math.h>
#include<conio.h>
#include<ctype.h>
#include <stdio.h>
#include <stdlib.h>
//////validation
int exceptionBinary(int num)
{
  while(num!=0)
  {
      int digit =num%10;
      if(digit!=0 && digit!=1 )
      {
         return 0;
      }
      num/=10;
  }
  return 1;
}
int exceptionOctal(int num)
{
     if (num < 0) {
       return 0;
    }
  while (num !=0&& num>0)
    {
       int digit =num%10;
       if(digit >=8)
       {
         return 0;
       }
       num/=10;
    }
 return 1;
}
int exceptionHexa(const char *str) {
    int i = 0;
    while (str[i] != '\0') {
        char ch = str[i];
        if (!((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'F') || (ch >= 'a' && ch <= 'f'))) {
            return 0;
        }
        i++;
    }
    return 1;
}




int exceptionDecimal(int *num)
{
    if (scanf("%d", num) != 1 || *num < 0)
    {

        return 0;
    }
}
///////////////////////////////////////////////

/////////////Binary

void displayResults(int dec_num, int hexa_num, int octal_num)
{
    printf(" Decimal number: %d\n", dec_num);
    printf(" Hexadecimal number: %x\n", hexa_num);
    printf(" Octal number: %o\n", octal_num);
}
int binaryTodecimal( int bin_num)
{
    int dec_num = 0, i = 1, rem;
    while (bin_num != 0)
    {
        rem = bin_num % 10;
        dec_num = dec_num + rem * i;
        bin_num = bin_num/10;
        i = i * 2;
    }
    return dec_num;
}
int binaryToHexadecimal( int bin_num)
{
     int  hexa_num = 0, i = 1, rem;
    while (bin_num != 0)
    {
        rem = bin_num % 10;
    hexa_num = hexa_num + rem * i;
    i = i * 2;
    bin_num = bin_num / 10;
}
    return hexa_num;
}
int binaryToOctal (int bin_num)
{
    int octal_num = 0, i = 1, rem;
       while (bin_num != 0)
       {
        rem = bin_num % 10;
        octal_num = octal_num + rem * i;
         i= i * 2;
         bin_num = bin_num / 10;
         }
   return octal_num;
}



///////////////Decimal

 void ConvertFromDecimal()
 { int input,counter;
 //for(counter=1;counter<2;counter++)
 //{
 char c;

     printf("please Enter The Decimal Number: ");
     if (!exceptionDecimal(&input))
       {
        printf("This number is not valid\n");
        //continue;
        }


    printf("------------------------------\n >>>> Conversion Results<<<<\n------------------------------\n");
    unsigned long long helper,binary=0,place=1;
    int reminder;
    helper=input;
    while(helper)
    {
        reminder =helper%2;
        helper=helper/2;
        binary+= (reminder*place);
        place*=10;
    }
     printf("Binary Number : %llu\n",binary);
     printf("Octal Number : %o\n",input);
     printf("Hexa-decimal Number : %X\n",input);

 }
 //}
//////////Octal

void OctalToDecimal(int octalnum){
    int place=0, digit, result=0;
    while(octalnum!=0){
        digit=octalnum%10;
        result=result+(digit*pow(8,place));
        octalnum=octalnum/10;
        place++;
        }
    printf("The Decimal equivalent: %d",result);
}

void OctalToBinary(int octalnum ){
    int result,digit,bits;
    printf("The Binary equivalent: ");
    while (octalnum != 0){
        digit = octalnum % 10;
        for (bits = 0 ; bits < 3 ; bits++){
            int temp = digit % 2;
            printf("%d",temp);
            digit=digit / 2;
        }
        octalnum /= 10;
    }
}

void OctalToHexadecimal(int octalnum) {
    int result = 0, i = 1, rem, bin_num = 0;
    while (octalnum != 0) {
        int digit = octalnum % 10;
        for (int bits = 0; bits < 3; bits++) {
            int temp = digit % 2;
            bin_num = bin_num + (temp * i);
            i = i * 10;
            digit = digit / 2;
        }
        octalnum /= 10;
    }
    printf("The Hexadecimal equivalent: ");
    while (bin_num != 0) {
        rem = bin_num % 10000;
        switch (rem) {
            case 0000: printf("0"); break;
            case 0001: printf("1"); break;
            case 0010: printf("2"); break;
            case 0011: printf("3"); break;
            case 0100: printf("4"); break;
            case 0101: printf("5"); break;
            case 0110: printf("6"); break;
            case 0111: printf("7"); break;
            case 1000: printf("8"); break;
            case 1001: printf("9"); break;
            case 1010: printf("A"); break;
            case 1011: printf("B"); break;
            case 1100: printf("C"); break;
            case 1101: printf("D"); break;
            case 1110: printf("E"); break;
            case 1111: printf("F"); break;
            default: printf("Invalid binary number");
        }
        bin_num /= 10000;
    }
}


/////////////Hexa



// Function to convert hexadecimal to decimal
int hexadecimal_Decimal(const char *hexa) {
    int sum = 0, len = strlen(hexa), j = 0;

    // Convert each character to uppercase while processing
    for (int i = len - 1; i >= 0; i--) {
        char ch = toupper(hexa[i]);

        if (ch >= '0' && ch <= '9')
            sum += (ch - '0') * pow(16, j);
        else if (ch >= 'A' && ch <= 'F')
            sum += (ch - 'A' + 10) * pow(16, j);

        j++;
    }

    return sum;
}

// Function to convert hexadecimal to binary
void hexadecimal_Binary(const char *hexa, char *binaryResult) {
    // Initialize an empty string
    strcpy(binaryResult, "");

    // Convert each hexadecimal digit to binary while processing
    for (int i = 0; hexa[i] != '\0'; i++) {
        char ch = toupper(hexa[i]);

        switch (ch) {
        case '0':
            strcat(binaryResult, "0000");
            break;
        case '1':
            strcat(binaryResult, "0001");
            break;
        case '2':
            strcat(binaryResult, "0010");
            break;
        case '3':
            strcat(binaryResult, "0011");
            break;
        case '4':
            strcat(binaryResult, "0100");
            break;
        case '5':
            strcat(binaryResult, "0101");
            break;
        case '6':
            strcat(binaryResult, "0110");
            break;
        case '7':
            strcat(binaryResult, "0111");
            break;
        case '8':
            strcat(binaryResult, "1000");
            break;
        case '9':
            strcat(binaryResult, "1001");
            break;
        case 'A':
            strcat(binaryResult, "1010");
            break;
        case 'B':
            strcat(binaryResult, "1011");
            break;
        case 'C':
            strcat(binaryResult, "1100");
            break;
        case 'D':
            strcat(binaryResult, "1101");
            break;
        case 'E':
            strcat(binaryResult, "1110");
            break;
        case 'F':
            strcat(binaryResult, "1111");
            break;
        default:
            printf("\nInvalid Number");
        }
    }
}

int hexadecimal_Octadecimal(const char *hexa) {
    char binaryResult[100];
    hexadecimal_Binary(hexa, binaryResult);

    int binary = atoi(binaryResult);
    int octal_num = binaryToOctal(binary);
    return octal_num;
}



////////////Exit screen
void DisplayExitScreen()
{
  printf("\n\n");

    printf("--------------------------------------------------------------------------------------------------\n");

printf("^!^!^!^!^!^1^!^!^!^!^->->->->->-> Creator  [Team 12] <-<-<-<-<-<-^!^!^!^!^!^!^!^!^!^!^\n");

    printf("---------------------------------------------------------------------------------------------------\n\n");

printf("> Member 1  Ahlam Reda  worked on -> Function Exit Screen and Try again and screen cleaner \n");
printf("> Member 2  Alaa Mahmoud  worked on -> Function Validation \n");
printf("> Member 3  Mariam Elghazaly  worked on -> Function  decimal Conversion \n");
printf("> Member 4  Nayyera Alashry  worked on -> Function  Octal Conversion\n");
printf("> Member 7  Hager Hisham  worked on -> Function Hexadecimal Conversion \n");
printf("> Member 5  Lamis Orabi  worked on -> Function  Binary Conversion\n");
printf("> Member 6  Sara Mohamed worked on -> Function  user choice and menu \n");
}


 void TryAgain()
   {
       char c;


       printf("\nDo You Want To Try Again [Y|N]\n");
     scanf(" %c", &c);
       if(c=='y' || c=='Y')
          {
             displayMainMenu();

          }
          else
                    exit(0);


         }
  ////////////menu

void displayMainMenu() {
    printf("\n=== Number System Converter ===\n");
    printf("1. Binary Conversions\n");
    printf("2. Decimal Conversions\n");
    printf("3. Octal Conversions\n");
    printf("4. Hexadecimal Conversions\n");
    printf("5. Exit the Program \n");
}



  void ScreenCleaner() {
    //  clrscr();
      system("cls");
      // int c;
      // while((c = getchar()) != '\n' && c !=EOF)
       // break;

   }



void UserInput(int choice)
{


        int bin_num, isBinaryNumber;
        int dec_num, hexa_num, octal_num;
        int octalnum;
         char hexa[100];
         switch (choice) {
            case 1:


                  printf("Enter the binary number: ");
                  scanf("%d", &bin_num);
                       if( exceptionBinary (bin_num))
                    {
                    printf("\n--------------------------------------\n");

                         printf(">>> Conversion results <<<\n");
                    printf("--------------------------------------\n");

                       dec_num = binaryTodecimal(bin_num);
                       hexa_num = binaryToHexadecimal(bin_num);
                        octal_num = binaryToOctal(bin_num);
                       displayResults(dec_num, hexa_num, octal_num);
                    }
                     else {
                           printf("This number is not valid\n");
                        }
                         TryAgain();
                         ScreenCleaner();



                break;

        case 2:
                ConvertFromDecimal();
                   TryAgain();
                        ScreenCleaner();



                break;
            case 3:
                     printf("Enter The octal number: ");
                           scanf("%d",&octalnum);
                           if(exceptionOctal( octalnum))
                           {
                printf("--------------------------------------\n");

                       printf(">>> Conversion results <<<\n");
                printf("---------------------------------------\n");


                   OctalToDecimal(octalnum);
                     printf("\n");

                   OctalToBinary(octalnum);
                     printf("\n");

                    OctalToHexadecimal(octalnum);
                      printf("\n");}
                      else
                      {
                        printf("This number is not valid\n");
                      }
                           TryAgain();
                        ScreenCleaner();


                break;

            case 4:

    // Get input from the user
    printf("Enter Hexadecimal Number: ");
    scanf("%s", hexa);

    // Validate input
    if (exceptionHexa(hexa)) {
        printf("------------------------------\n >>>> Conversion Results<<<<\n------------------------------\n");
        // Call the functions with the user input
        int decimalResult = hexadecimal_Decimal(hexa);
        printf("Decimal Number: %d\n", decimalResult);

        char binaryResult[100];
        hexadecimal_Binary(hexa, binaryResult);
        printf("Binary Number: %s\n", binaryResult);

        int octalResult = hexadecimal_Octadecimal(hexa);
        printf("Octadecimal Number: %o\n", octalResult);
    }
    else {
        printf("Invalid Hexadecimal Number\n");
    }

                  TryAgain();
                  ScreenCleaner();


                break;


            case 5:
              printf("Exiting.........\n");
              //DisplayExitScreen();
              //ScreenCleaner();

                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    }

int main(){
int choice;
 while(1){
        printf("-------------------------------------------------------------------------------------------------\n");
        printf("*|*|*|*|*|*|*|*|*|*|*|*|*|*|*|->Welcome To Number System Converter<-|*|*|*|*|*|*|*|*|*|*|*|*|*|*|*\n");
        printf("-------------------------------------------------------------------------------------------------\n");

    displayMainMenu();
    printf(">>>>>>Select Conversion Type : ");

    scanf("%d",&choice);
    if(choice==5){
        break;
    }
    UserInput(choice);

 }
 DisplayExitScreen();
return 0;
}







