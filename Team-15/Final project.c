#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
//Global variables
long long int usernum;

//Welcome function
void welcome(void) {
    printf("            Welcome to Number system converter!\nHere you can convert any number system to other systems easly\n");
    printf("--------------------------------------------------------------\n\n");
}

//Menu function
int menu(int con) {
    printf("Systems Menu:\n 1) Bianry\n 2) Decimal\n 3) Octal\n 4) Hexadecimal\n 5) Exit\n\n");
    printf("Select the system of the entering number and press enter button: ");
    scanf("%d",&con);
    while(con>5 || con<1) {
        printf("Try again(write number from 1 to 5): ");
        scanf("%d",&con);
    }
    system("cls");
    return con;
}

//Exit screen function
void exitscr() {
    printf("\n\nCreator: Team 15\n\n");
    printf("Members: \n~Doah Hamed (octal functions) \n");
    printf("~Hager Ahmed (Welcome, menu and exit functions, switch...case, and code connection) \n");
    printf("~Jana Ahmed (Hexadecimal function) \n");
    printf("~Malak Essam (Hexadecimal function) \n");
    printf("~Shahd Mohamed (Searching, clear screen, and clean code) \n");
    printf("~Shahd Sayed (Binary function) \n");
    printf("~Shams Hesham (Decimal function)\n");
}

//continue function
char checkcontinue(char continu) {
    char confirmation;
    printf("\n\nDo you want to continue (Y/N)? ");
    scanf(" %c", &confirmation);
    if (confirmation == 'Y' || confirmation == 'y') {
        system("cls");
        return 'N';
    }
    else if (confirmation == 'N' || confirmation == 'n') {
        system("cls");
        return 'Y';
    }
    else {
        printf("invalid\n");
    }
}

//check the number is digit or not:
void CheckIsNumber() {
    char check[100];
    scanf("%s",&check);
    for (int i=0; check[i]!='\0'; i++) {
        if (!isdigit(check[i])) {
            while(!isdigit(check[i])) {
                printf("Invalid!\n");
                printf("Enter the number again: ");
                scanf("%s",&check);
            }
        }
        else {
            usernum=atoi(check);
        }
    }
}
//decimal to binary function
long long int decimaltobianry(long long int decimalnum) {
    long long int binarynum=0, rem;
    int base=1;
    while(decimalnum!=0)
    {
        rem=decimalnum%2;
        binarynum=binarynum+rem*base;
        decimalnum=decimalnum/2;
        base=base*10;
    }
    return binarynum;
}

//Binary converter function
int limit=0;
char trial;
void Bin_Converter(long long int binary)
{
    double i, weight, sum=0, rem;
    int decimal;
    for(i=0; binary>0 ; i++)
    {
        rem = binary%10;
        if (rem > 1)
        {
            printf("\n!! Invalid Input !! Please Enter Binary Number in 0s and 1s only\n ");
            limit++;
            break;
        }
        weight = pow(2,i);
        sum = sum + (rem * weight);
        binary = binary / 10;
    }
    if (!limit)
    {
        decimal = sum;
        printf("\n\n--------------------------\n>>> Conversion Result <<< \n--------------------------\n\n");
        printf("Decimal number : %d\n",decimal);
        printf("Octal number : %o\n",decimal);
        printf("Hexa-decimal number : %X\n",decimal);
    }
}

//Decimal function
void Decimal(int decimal)
{
    printf("\n---------------------------\n>>> Conversion Results <<<\n---------------------------\n\n");
    printf("Number in Binary: %d\n",decimaltobianry(decimal));
    //convert to octal
    printf("Number in Octal: %o\n",decimal);
    //convert to hexa
    printf("Number in Hexa-Decimal: %X",decimal);
}
//Octal function
int oct_num,c;
double oct_dec(int);
long int oct_bin();
long long int decimaltobianry(long long int);
void octal(int oct_num) {
    int digit,num=oct_num;
    for(; num!=0;) {
        digit=num%10;
        if(digit>7) {
            printf("Invalid  number. Please enter number between 0-7 \n");
            c+=1;
            break;
        }
        num/=10;
    }
    if(!c) {
        long long int dec=oct_dec(oct_num);
        printf("\n---------------------------\n>>> Conversion Results <<<\n---------------------------\n\n");
        printf("Number In Binary: %lld \n",decimaltobianry(dec));
        printf("Number In Decimal: %.0lf \n",oct_dec(oct_num));
        printf("Number In Hexadecimal: %X \n",(int)oct_dec(oct_num)); //ther is a format specifier to convert from decimal to hexadecimal
    }
}
double oct_dec(int oct_num) { //fun convert from octal to decimal
    double oct_result=0,oct_base,oct_place,oct_place_num; //oct_place->الاس الخاص موقع العدد، oct_base-> ناتج ٨ اس الموقع الخاص بها، oct_place_num-> ابتداء الرقم من اليمين الى اليسار
    for(oct_place=0; oct_num>0; oct_place++) {
        oct_base=pow(8,oct_place);
        oct_place_num=oct_num%10;
        oct_num/=10;
        oct_result+=oct_base*oct_place_num;
    }
    return oct_result;
}

//Hexadecimal function
char h[100];
int i;
void hexadecimal(char h[100])
{
    int l;
    int dec=0;
    int j=0;
    l=strlen(h);
    for(i=l-1; i>=0; i--) //first is entered in the first during the next step
    {
        if (('A'<=h[i])&&(h[i]<='F'))
        {
            dec=dec+(h[i]-55)*pow(16,j); //to calculate each(element((base)power(its weight))
            j++;
        }
        else if(h[i]>='0'&&h[i]<='9')
        {
            dec=dec+(h[i]-48)*pow(16,j);
            j++;
        }
        else if (('a'<=h[i])&&(h[i]<='f')) {
            dec=dec+(h[i]-87)*pow(16,j);
            j++;
        }
    }
    printf("\n\n--------------------------\n>>> Conversion Result <<< \n--------------------------\n\n");
    printf("Number in Binary: %ld\n",decimaltobianry(dec));
    printf("Number in Decimal: %d\n",dec);
    printf("Number in Octal: %o\n",dec);
}

//main function
int menuNum, con;
char choice, continu;
int main()
{
    welcome();
    do {
        menuNum=menu(con);
        switch(menuNum) {
        case 1:
            do {
                system("cls");
                printf("Enter the Binary number: ");
                CheckIsNumber();
                Bin_Converter(usernum);
                printf("\nDo you want to try again(Y/N)? ");
                scanf(" %c",&trial);
                limit=0;
            } while(trial=='y'||trial=='Y');
            continu=checkcontinue(continu);
            break;
        case 2:
            do {
                system("cls");
                printf("Enter the Decimal number: ");
                CheckIsNumber();
                Decimal(usernum);
                printf("\nDo you want to try again(Y/N)? ");
                scanf(" %c",&trial);
            } while(trial=='y'||trial=='Y');
            continu=checkcontinue(continu);
            break;
        case 3:
            do {
                system("cls");
                printf("Enter the Octal number: ");
                CheckIsNumber();
                octal(usernum);
                printf("\nDo you want to try again(Y/N)? ");
                scanf(" %c",&trial);
                c=0;
            } while(trial=='y'||trial=='Y');
            continu=checkcontinue(continu);
            break;
        case 4:
            do {
                system("cls");
                printf("Enter the Hexadecimal number: ");
                scanf("%s",&h);
                while(h[i]<48||h[i]>57&&h[i]<65||h[i]>70&&h[i]<97||h[i]>102) {
                    printf("Invalid number!\n");
                    printf("Enter the Hexadecimal number again: ");
                    scanf("%s",&h);
                }
                hexadecimal(h);
                printf("\nDo you want to try again(Y/N)? ");
                scanf(" %c",&trial);
            } while(trial=='y'||trial=='Y');
            continu=checkcontinue(continu);
            break;
        case 5:
            printf("Do you want to Exit(Y/N)?");
            scanf(" %c",&continu);
            break;
        }
    } while(continu!='Y'&& continu!='y');
    exitscr();
    return 0;
}