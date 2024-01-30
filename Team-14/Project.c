#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <windows.h>
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
//---------------------------check if number is right----------------------------------
#define RED     12
#define GREEN   10
#define YELLOW  14
#define WHITE   15
#define BLUE    9
#define CYAN    11
#define ORANGE  6
//----------------------check if number is binary------------------------------------------\
//-------------------------------------power function----------------------------
double customPow(double base, int exponent) {
    double result = 1.0;
    if (exponent < 0) {
        base = 1.0 / base;
        exponent = -exponent;}
    for (int i = 0; i < exponent; i++) {
        result *= base;}
    return result;}
//-----------------------------------  1- hexaconvert    -----------------------------------
#include <stdio.h>
#include <string.h>
void hextoBinary(char hexa1[])
{
  unsigned long long  int i = 0;
   unsigned long long  int binary = 0 ;
     unsigned long long  int powerten=1;
while (hexa1[i])
    {
    switch (hexa1[i])
        {
            case '0':
                binary = binary *10000 ;
               break;
            case '1':
                binary = 1 + binary*10;
               break;
            case '2':
                binary = 10 + binary*100;
               break;
            case '3':
                binary = 11 + binary*100 ;
               break;
            case '4':
                binary = 100 + binary*1000;
               break;
            case '5':
                binary = 101 + binary*1000;
               break;
            case '6':
                binary = 110 + binary*1000;
               break;
            case '7':
                binary = 111 + binary*1000;
               break;
            case '8':
                binary = 1000 + binary*10000;
               break;
            case '9':
                binary = 1001 + binary*10000;
               break;
            case 'A':   case 'a':
                binary =1010 + binary*10000 ;
               break;
            case 'B':   case 'b':
                binary =1011 + binary*10000 ;
               break;
            case 'C':   case 'c':
                binary =1100 + binary*10000;
               break;
            case 'D':   case 'd':
                binary=  1101 + binary*10000;
               break;
            case 'E':   case 'e':
                binary = 1110 + binary*10000;
               break;
            case 'F':   case 'f':
                binary = 1111 + binary*10000;
               break;
            default:
                 setColor(RED);
                printf("\n Invalid hexadecimal %c", hexa1[i]);
                return;
            }
            i=i+1;
        }
     unsigned long long  int binaryNumber = binary ;
     setColor(BLUE);
     printf(" the equivalent binaryNumber %llu \n", binaryNumber);
    unsigned long long int decimalNumber = 0, base = 1, remainder;
    // Convert binary to decimal
    while (binaryNumber > 0) {
        remainder = binaryNumber % 10;
        decimalNumber = decimalNumber + remainder * base;
        base = base * 2;
        binaryNumber = binaryNumber / 10;
    }
    // Display the result
    setColor(BLUE);
    printf("The equivalent decimal number: %llu\n", decimalNumber);
    //-----------------------------------------------------------
   unsigned long long int octalNumber = 0, base1 = 1, remainder1;
    // Convert decimal to octal
    while (decimalNumber > 0) {
        remainder1 = decimalNumber % 8;
        octalNumber = octalNumber + remainder1 * base1;
        base1 = base1 * 10;
        decimalNumber = decimalNumber / 8;
    }
    // Display the result
    setColor(BLUE);
    printf("The equivalent octal number: %llu\n", octalNumber);
}
//---------------------------------------  2- octal convert    -----------------------------------
#include<stdio.h>
long long int n ;
long long int decimalTobinary (long long int );
long long int octalTodecimal (long long int );

 long long int octalTodecimal (long long int n)
 {
  long long int decimal =0,i=1,j,d,p=1;
  for (j=n ; j>0 ; j=j/10)
  {
   d=j%10;
   if (i==1)
    p=p*1;
   else
    p=p*8;
   decimal = decimal +(d*p);
   i++;
  }
   return decimal ;
 }
 long long int decimalTobinary(long long int number)
 {
  long long int i,j,binary =0;
  i=1;
  for (j=number;j>0;j=j/2)
  {
   binary = binary +(number%2)*i;
   i=i*10;
   number=number/2;
   }
   return binary ;
 }
//---------------------------------------  3- binaryconvert    -----------------------------------
int isValidBinary(long long n) {
    while (n != 0) {
        if (n % 10 != 0 && n % 10 != 1) {
            printf( "Enter a valid binary number.\n" );
            return 0;
        }
        n = n / 10;
    }
    return 1;
}
long long int binaryToDecimal(long long int n) {
    long long int decimal = 0, i = 1, d;
    while (n > 0) {
        d = n % 10;
        decimal += d * i;
        i *= 2;
        n = n / 10;
    }
    return decimal;
}
//---------------------------------------  4- decimalconvert    -----------------------------------
#include <stdlib.h>
#include <stdio.h>
void decimalconversion(){
   unsigned char  ch;
     unsigned long long int   decimalNOc=0;
    unsigned long long int binaryNOc=0;
    unsigned long long int i=1,remiderc=1;
  printf("enter here >> ");
   while((ch=getch())!='\r'){
    switch(ch){
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
    putch(ch);
    decimalNOc=decimalNOc*10+ch- '0';
    break;
        case 8:
            putch('\b');
            putch(' ');
            putch('\b');
        break;
    }
    }
printf("\n **you get decimal number:""%d\n""",decimalNOc);
unsigned long long int  tempc =decimalNOc;
    while(decimalNOc !=0){
        remiderc= decimalNOc % 2;
        binaryNOc=binaryNOc +remiderc *i;
        i=i*10;
        decimalNOc=decimalNOc/2;}
    printf("binary represent of decimal number %d is %llu\n",tempc,binaryNOc);
    printf ("octal represent of decimal number %d is %o\n",tempc,tempc);
    printf ("hexa decimal represent of decimal %d is %x\n",tempc,tempc);}
//---------------------------------------  5-end of programm   -----------------------------------
int main(){
    setColor(WHITE);
    printf("|------------------------------------------\n");
    setColor(ORANGE);
    printf("|welcome to number system convertor<< |\n");
    setColor(WHITE);
    printf("|------------------------------------------\n");
    setColor(ORANGE);
    printf("| >> select conversion type :      |\n");
    setColor(YELLOW);
    printf("|>1-binary conversion              |\n");
    setColor(YELLOW);
    printf("|>2-decimal conversion             |\n");
    setColor(YELLOW);
    printf("|>3-octal conversion               |\n");
    setColor(YELLOW);
    printf("|>4-hexadecimal conversion         |\n");
    setColor(ORANGE);
    printf("|>5-exit the programm              |\n");
    setColor(WHITE);
    printf("----------------------------------------- \n");
    int input;
 int choice;
char continuesign;
 do {
         setColor(GREEN);
        printf("•Enter the number and hit enter: ");
        setColor(WHITE);
        scanf("%d", &choice);
        if (choice == 4) {
           char hexa1[16];
           setColor(WHITE);
           printf("\n-----------------------------------------| \n");
           setColor(CYAN);
           printf("                                         | \n >>the conversions of the hexadecimal<<;\n");
           setColor(WHITE);
           printf("                                         |\n-----------------------------------------| \n");
           setColor(YELLOW);
           printf("--your input-- \n");
           printf("enter here >>>");
            scanf("%s", &hexa1);
          printf("----------------------------------------- \n");
          setColor(ORANGE);
         printf("vvvvvvvvvvvvv result  vvvvvvvvvvvvvvvv");
            setColor(WHITE);
            printf("\n----------------------------------------- \n");
           hextoBinary(hexa1);
            printf("----------------------------------------- \n");
        } else if (choice == 5) {
             setColor(WHITE);
            printf("\n----------------------------------------- \n");
            printf("Program exited successfully\n");
            setColor(GREEN);
             printf("thank you team cs raiders for your effort and we hope you like our project \n");
          printf("thank for contributer : Ezzeldeen , Hassan Hagag , Rana Waleed , Donia Ahmad , Kaled waleed , Hatem tamer , Doaa mohmade ");
            printf("------------------------ \n");
             setColor(WHITE);
            printf("\n----------------------------------------- \n");
            break;
        } else if (choice == 3) {
                       setColor(WHITE);
                        printf("\n-----------------------------------------| \n");
                        setColor(CYAN);
                        printf("                                         | \n >>the conversions of the octal<<;\n");
                        setColor(WHITE);
                        printf("                                         |\n-----------------------------------------| \n");
                        setColor(WHITE);
                        setColor(YELLOW);
                        printf("--your input-- \n");
                        printf("enter here >>>");
                       scanf("%lld",&n);
                       printf("----------------------------------------- \n");
                       setColor(ORANGE);
                       printf("vvvvvvvvvvvvv result  vvvvvvvvvvvvvvvv");
                       long long  int copy1 = n;
                       while(copy1 != 0){
                           if (n%10 == 8 || n%10 ==9 ){
                                setColor(RED);
                                printf("enter valid octal \n");
                                setColor(WHITE);
                                copy1 = copy1/10 ;

                           }
                          else{
                       long long int y=octalTodecimal (n);
                       long long int z=decimalTobinary (y);
                       setColor(BLUE);
                       printf("\nthe equivalent decimal number:%lld\n\n",y);
                       setColor(BLUE);
                       printf("the equivalent hexadecimal number:%x\n\n",y);
                       setColor(BLUE);
                       printf("the equivalent binary number:%lld\n\n",z);
                       printf("----------------------------------------- \n");
                       break;}
                       }
          } else if (choice == 1) {
                printf( "please enter binary number: " );
               long long num;
               scanf("%lld", &num);
              int result = isValidBinary(num);
                  if (result) {
                         long long int decimalEquivalent = binaryToDecimal(num);
                         printf( ">> The equivalent decimal number: %lld\n" , decimalEquivalent);
                         printf( ">> The equivalent octal number: %o\n" , decimalEquivalent);
                         printf( ">> The equivalent hexadecimal number: %x\n" , decimalEquivalent);}
        } else if (choice == 2) {
               printf(".--------------------------------------- |\n                                      |");
                setColor(BLUE);
                printf("\n the conversions of decimal:          |\n");
                setColor(WHITE);
                printf("--------------------------------------|\n \  \n");
             decimalconversion();
             printf("----------------------------------------- \n");
             }else {
                 setColor(RED);
                 printf("error you enter valid choice");}
        setColor(WHITE);
        printf("\n Do you want to try again? Press 'y' : ");
        scanf(" %c", &continuesign);
 }while (continuesign == 'Y' || continuesign == 'y');
}