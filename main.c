#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
# define MAX 20
char str[MAX],stack[MAX];
int top=-1,a[MAX];
void push(char c)
{
   stack[++top]=c;
}
char pop()
{
   return stack[top--];
}
void pre_post()
{
   int n,i,j=0; char c[20];
   char a,b,op;
   printf("Enter the prefix expression\n");
   gets(str);
   n=strlen(str);
   for(i=0;i<MAX;i++)
   stack[i]='\0';
   printf("Postfix expression is:\t");
   for(i=0;i<n;i++)
   {
      if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
      {
         push(str[i]);
      }
      else
      { c[j++]=str[i];
        while((top!=-1)&&(stack[top]=='@'))
        {
            a=pop(); c[j++]=pop();
        }
        push('@');
      }
   }
   c[j]='\0';
   printf("%s",c);
}

void post_pre()
{
   int n,i,j=0; char c[20];
   char a,b,op;
   printf("Enter the postfix expression\n");
   gets(str);
   n=strlen(str);
   for(i=0;i<MAX;i++)
   stack[i]='\0';
   printf("Prefix expression is:\t");
   for(i=n-1;i>=0;i--)
   {
      if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
      {
         push(str[i]);
      }
      else
      { c[j++]=str[i];
        while((top!=-1)&&(stack[top]=='@'))
        {
            a=pop(); c[j++]=pop();
        }
        push('@');
      }
   }
   c[j]='\0';
   strrev(c);
   printf("%s",c);
}

int prcd(char c)
{   if(c=='(')
    return 0;
    else if(c=='+'||c=='-')
    return 1;
    else if(c=='*'||c=='/')
    return 2;
}
int infixtopostfix(char infix[MAX],char postfix[MAX])
{
    char temp,x;
    int i=0,j=0;
    while(infix[i]!='\0')
    {
        temp=infix[i];
       if(isalnum(temp))
        {
            postfix[j++]=temp;
        }
        else if(temp=='(')
         push(temp);
        else if(temp==')')
            {
         while((x=pop())!='(')
         {
          postfix[j++]=x;
           }
          }
        else
        {  while(prcd(a[top])>=prcd(temp))
            {postfix[j++]=pop();}
                push(temp);
        }
        i++;
    }
    while(top!= -1)
    postfix[j++]=pop();
    postfix[j]='\0';
}

void post_in()
{
   int n,i,j=0;
   char a,b,op,x[20];
   printf("Enter the postfix expression\n");
   fflush(stdin);
   gets(str);
   strrev(str);
   n=strlen(str);
   for(i=0;i<MAX;i++)
      stack[i]='\0';
   printf("Infix expression is:\t");
   for(i=0;i<n;i++)
   {
      if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
      {
         push(str[i]);
      }
      else
      {
         x[j]=str[i]; j++;
         x[j]=pop(); j++;
      }
   }
   x[j]=str[top--];
    strrev(x);
   printf("%s\n",x);
}

void pre_in()
{
   int n,i;
   char a,b,op;
   printf("Enter the prefix expression\n");
   fflush(stdin);
   gets(str);
   n=strlen(str);
   for(i=0;i<MAX;i++)
      stack[i]='\0';
   printf("Infix expression is:\t");
   for(i=0;i<n;i++)
   {
      if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
      {
         push(str[i]);
      }
      else
      {
         op=pop();
         a=str[i];
         printf("%c%c",a,op);
      }
   }
   printf("%c\n",str[top--]);
}


int main()
{
    int choice;

    while(1)
    {
    printf("\n\tMENU DRIVEN\n");
    printf("\n1.Prefix to Postfix\n");//
    printf("\n2.Infix to Postfix\n");//
    printf("\n3.Postfix to Prefix\n");//
    printf("\n4.Postfix to Infix\n");//
    printf("\n5.Prefix to Infix\n");
    printf("\n6.Exit\n");
    printf("\nEnter your choice:");
    scanf("%d",&choice);
    fflush(stdin);

switch(choice)
{
case 1:
    pre_post();
    break;
case 2:
    {
    char infix[MAX],postfix[MAX];
    printf("Enter the infix expression\n");
    gets(infix);
    printf("The infix expression is %s\n",infix);
    infixtopostfix(infix, postfix);
    printf("The postfix expression is %s\n",postfix);
    }
    break;
case 3:
       post_pre();
       break;

case 4:
       post_in();
       break;

case 5:
      pre_in();
       break;
case 6:
    exit(0);
break;
default:
    printf("Invalid Choice!");
}

    }

    return 0;
}
