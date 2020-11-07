#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
int menu();
void note();
void main()
{
    FILE *fp;
	char uname[20]="computer";
	char month[9];
	char pin[5]="1234";
	float a[10];
    char b[10][50]={"Household Expenses","House rent","Electricity","Educational expenses","Entertainment","Medical","Transportation","Insurance","Extra Savings","Others"};
    char pasword[5];
    char usrname[10];
    char ch,ch1;
    int i,s,f,k,c,length,q,e,scale=1,l;
    float inc,tex=0,sum,max;
    printf("________________________________________________________________________________________________________________________");
	printf("\n\n                                              Welcome To Budget Manager\n");
	printf("________________________________________________________________________________________________________________________\n\n");

    printf("Enter User name: ");
    gets(usrname);
    printf("Enter the 4 number PIN :");

    for(i=0;i<4;i++)
    {
        ch = getch();
        pasword[i] = ch;
        ch = '*' ;
        printf("%c",ch);
    }
    if(strcmp(pin,pasword)==0 &&strcmp(usrname,uname)<1)
    {
     //clrscr();
        printf("....welcome to budget manager,");
        puts(usrname);
        printf("\nEnter month name in words : ");
        gets(month);
        printf("Enter total income of this month : ");
        scanf("%f",&inc);
        printf("\n***Enter field wise Expenses ***\n\n");

        for(i=0;i<10;i++)
        {
            printf("%s : ",b[i]);
            scanf("%f",&a[i]);
        }
        max=a[0];
        fp=fopen("budget manager.txt","a");
        fprintf(fp,"%s\n\n",month);
        for(i=0;i<10;i++)
        {
            length=strlen(b[i]);
            for(q=0;q<(25-length);q++)
            {
                fprintf(fp," ");
            }
        fprintf(fp,"%s\t",b[i]);
        fprintf(fp,"%f\n",a[i]);
        }
        fclose(fp);
        for(i=0;i<10;i++)
        {
            tex=tex+a[i];
        }
        s:if (inc>tex)
        {
            sum=inc-tex;
        }
         else
        {
            printf("\n[it is not possible,Your expenses is greater than income]");
        }
    //clrscr();
        printf("\n\                                                User's Menu \n");
        printf("_________________________________________________________________________________________________________________________\n\n");
        c=menu();
        switch(c)
        {
            case 1:
  	//clrscr();
            {
                printf("\nyour balance is = total income - total expenses \n \t\t= %f -  %f\n \t\t= %f",inc,tex,sum);

            printf("\n\nEnter 1 for main menu :");
            scanf("%d",&f);
            if (f== 1)
            {goto s;}
            break;
            }
            case 2:
  	 //clrscr();
            {
                printf("your all expenses are given below \n\n");
                printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _  _ _ _ \n\n");
                for(i=0;i<10;i++)
                {
                    printf("%s : ",b[i]);
                    printf("%f\n",a[i]);
                }

            printf("\n\nEnter 1 for main menu:");
            scanf("%d",&f);
            if (f== 1)
            {goto s;}
            break;
            }

            case 3:
            {
                printf("\nThe graph of your savings is.\n");
                printf("____________________________________________________________\n\n");
                 for(i=0;i<10;i++)
                    {
                        if(max<a[i])
                        {
                            max=a[i];
                        }
                    }
                    l=(int)log10(max);
                    for(i=1;i<l;i++)
                    {
                        scale=scale*10;
                    }
                printf("%s:\n",month);
                for(i=0;i<10;i++)
                {
                    length=strlen(b[i]);
                    for(q=0;q<(25-length);q++)
                    {
                        printf(" ");
                    }
                    printf("%s|",b[i]);

                    c=(a[i]/scale)+1;
                    for(k=0;k<c;k++)
                    {
                        printf("*");
                    }
                    printf("\n");
                }
                printf("SCALE: %d",scale);
  		//clrscr();
                printf("\n\nEnter 1 for main menu: ");
                scanf("%d",&f);
                if (f==1)
                {goto s;}
                break;
            }

            case 4:
            {
                fp=fopen("budget manager.txt","r");
                ch1=fgetc(fp);
                while(ch1!=EOF)
                {
                    printf("%c",ch1);
                    ch1=fgetc(fp);
                }
                printf("\n\nEnter 1 for main menu: ");
                scanf("%d",&f);
                if (f==1)
                {goto s;}
                break;
            }
            case 5:
            {
                exit(1);
            }
        }
    }
    else
	{
		printf("\n\n\n**Password or UserName is incorrect**");
    }
}


int menu()
{
	int n;
	printf(" 1 : check your balance(your saving)\n ");
	printf("2 : your Expenses\n ");
	printf("3 : Graphical view of expenses\n ");
	printf("4 : Previous Month Expenses(if exists)\n");
	printf(" 5 : exit\n\n");
	printf("Enter your choice : ");
	scanf("%d",&n);
	return n;
}
