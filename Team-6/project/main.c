#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
void begin();
void menu();
void BinaryToDecimal();
void Decimal_To_Binary();
void DecimalTo_O_H(int d);
void OctalToDecimal(long long n2);
void OctalToBinary(long long n2 );
void HexaToDecimal();
void end();
void clear();
void stars();
int main(){
    begin();
    menu();
    while(1){
        char choice[3];
        char x;
        scanf("%s",&choice);
        clear();
        if(choice[1]!='\0'){
            stars();printf("Invalid choice\n");stars();
            printf("Select Conversion Type: \n");menu();
            continue;}
        switch(choice[0]){
            case '1':{
                BinaryToDecimal();
                break;}
            case '2':{
                long long d;
                printf("Enter the Decimal: ");
                scanf("%llu",&d);
                Decimal_To_Binary(d);
                DecimalTo_O_H(d);
                break;}
            case '3':{
                long long n2;
                printf("Enter the Octal: ");
                scanf("%llu",&n2);
                OctalToDecimal(n2);
                OctalToBinary(n2);
                break;}
            case '4':{
                HexaToDecimal();
                break;}
            case '5':{
                printf("This Program is Ended \n Do you want to see the Menu again?(y/n): ");
                scanf(" %c", &x);
                clear();
                if(x=='y' || x=='Y'){
                    menu();
                    continue;
                    }
                else if(x=='n' || x=='N'){
                    end();
                    return 0;
                    }
                else{
                    stars();printf("Invalid choice ,Please enter (Y) or (N)\n");stars();
                    break;
                }
                break;}
            default:{
                stars();printf("Invalid choice ,Please enter a number from 1 to 5\n");stars();break;}}
        printf("Do you want to try again(y/n): ");
        scanf(" %c", &x);
        clear();
        if(x=='y'|| x=='Y'){
            printf("Select Conversion Type: \n");menu();
            }
        else if(x=='n'||x=='N'){
            end();
            return 0; }
        else{stars();printf("Invalid choice ,Please enter (Y) or (N)\n");stars();
            printf("Do you want to try again(y/n): ");
            scanf(" %c", &x);
            if(x=='y'|| x=='Y'){system("cls");
            printf("Select Conversion Type: \n");menu();
            }
            else if(x=='n'||x=='N'){
                end();
                return 0;
                }
            }
        }
     }
void begin(){
    stars();
    printf("Welcome to Number Conversion Application\n");
    stars();
    printf("Select Conversion Type:\n");
    }
void menu(){
    printf(" > 1.Binary\n > 2.Decimal\n > 3.Octal \n > 4.Hexadecimal \n > 5.Exit\n Please click a number and press enter: ");
}
void BinaryToDecimal(){
    long long bin=1,bin2;
    printf("Enter the Binary: ");
    scanf("%llu",&bin2);
    int dec=0,r,i=0,x,negative;
    if(bin2<0){
        bin2*=-1;
        negative=-1;
        }
    bin=bin2;
    while(bin>0){
        x=bin%10;
        if(x!=0 && x!=1){
            printf("Error:the number is not binary\n\a");
            return;
            }
        bin/=10;
        }
        bin=bin2;
    while (bin!=0){
        r=bin%10;
        dec+=r*pow(2,i);
        bin=bin/10;
        i++;}
    if(negative<0){
        dec*=-1;
        }
    printf("Decimal Number: %d\n",dec);
    DecimalTo_O_H(dec);
    }
void Decimal_To_Binary(long long d){
long long b=0,k=1;//d for decimal, b for binary
     int negative=1;
     if(d!=0&&d<0){
         d=abs(d);
         negative=-1;
         }
     for(long long i=d;i>0;i/=2){
         b+=k*(d%2);
         k*=10;
         d/=2;
         }
     if(negative<0){
         printf("Binary Number: - %llu\n",b);return;}
     printf("Binary Number: %llu\n",b);
     }
void DecimalTo_O_H(int d){
    if(d>=0)
        printf("Octal Number: %o\nHexa-Decimal Number: %X\n",d,d);
    else
        printf("Octal Number: - %o\nHexa-Decimal Number: - %X\n",(-d),(-d));
}
void OctalToDecimal(long long n2){
    int x2,sum=0,k=0,negative;
    if(n2<0){
        n2*=-1;
        negative=-1;
        }
    while(n2){
        x2=n2%10;
        if(x2>7||x2<-7){
            printf("This is not an octal number \n\a");
            return;
            }
        n2=n2/10;
        sum=sum+(x2*pow(8,k));
        k++;
        }
    if(negative<0){
        printf("Decimal Number: - %llu\n",sum);
        printf("Hexadecimal Number: - %X\n",sum);
        }
    else{
        printf("Decimal Number:  %llu\n",sum);
        printf("Hexadecimal Number:  %X\n",sum);
        }
    }
void OctalToBinary(long long n2){
    long long c,sum5=0,n1,b=0;
    int negative=1;
    if(n2<0){
        n2*=-1;
        negative=-1;
        }
    n1=n2;
    while(n1){
        c=n1%10;
        if(c<0||c>7){
            return;;
        }
        n1/=10;
        sum5=(c*pow(8,b))+sum5;
        b++;
        }
    n1=n2;
    long long a[1000],x,i=0;
    while(sum5){
        x=sum5%2;
        if(x<-7||x>7){
                return;
                }
        sum5=sum5/2;
        a[i]=x;
        i++;}
    printf("Binary Number: ");
    if(negative<0)
        printf("-");
    for(long long j=i-1;j>=0;j--){
        printf("%llu",a[j]);}
    printf("\n");
    }
void HexaToDecimal(){
    char hexa[100];
    long long sum=0,i,j=0,size;
    int negative =1;
    printf("Enter the Hexadecimal: ");
    scanf("%s",&hexa);
    if(hexa[0]=='-'){
        strcpy(hexa, hexa + 1);
        negative=-1;
    }
    size=strlen(hexa);
    for(i=size-1;i>=0;i--){
        if(hexa[i]>='0' && hexa[i]<='9'){
            sum=sum+(hexa[i]-48)*pow(16,j);
        }else if (hexa[i]>='A' && hexa[i]<='F'){
            sum=sum+(hexa[i]-55)*pow(16,j);
        }else if (hexa[i]>='a' && hexa[i]<='f'){
            sum=sum+(hexa[i]-87)*pow(16,j);
        }
       else {printf("The number is not Hexa-Decimal\n\a");return;}
       j++;
       }
    if(negative<0)
        sum*=-1;

     printf("Decimal Number:%d\n",sum);
     if(negative<0)
        printf("Octal Number:-%o\n",abs(sum));
     else
         printf("Octal Number:%o\n",sum);
     Decimal_To_Binary(sum);
}
void end(){
    printf("------------------------\n");
    printf(">>>Creator: {Team 6}<<<\n");
    printf("------------------------\n");
    printf("> Member 1 Salma Essam,worked on :conversion 1\n> Member 2 Sara Mohamed,worked on :conversion 2& added negative numbers\n> Member 3 Mariam Adel,worked on :conversion 3\n> Member 4 Moaz Hassanien,worked on :conversion 4\n> Member 5 Sara Hatem,worked on :clear function\n> Member 6 Sama Abdelnaser,worked on:welcome,exit screen\n> Member 7 Sama Sayed,worked on :collecting the code\n");
    }
void clear()
{
    int i;
    system("cls");
    for(;(i=getchar())!='\n'&&i!=EOF;);
}
void stars(){
    printf("*\n");
}
