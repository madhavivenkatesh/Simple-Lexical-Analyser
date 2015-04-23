#include <stdio.h>
#define MAXSIZE 11

struct stack
{
    int stk[MAXSIZE];
    int top;
};
typedef struct stack STACK;
STACK s;

void push(char);
void  pop(void);
void display(void);
char top();

void main ()
{
    s.top = -1;
    int e=0,f=0,v=0;
    push('E');
    int i;
    char *string1 = "w*zy+w*y+xx";
    char *string2 = "w*zy+yy*z+xx";
    printf("Select the string\n");
    printf("\n1) String 1: %s \n2) String 2: %s\n\n", string1, string2);
    int n=0;
    char *string;
    scanf("%d",&n);
    if(n==1)
        string=string1;
    else if(n==2)
        string = string2;
    else
    {
        printf("\nInvalid choice");
        exit(0);
    }


    for(i=0;i<lengthOf(string);i++)
    {
        int temp=0;
        printf("\n\nToken: %c", string[i]);
        if(top()=='E')
        {
            temp++;
            printf("\nTop of stack: E");
            e++;
            if(e<3)
            {
                pop();
                push('x');
                push('E');
                push('+');
                push('T');
            }
            else
            {
                pop();
            }
        }
        if(top()=='T')
        {
            temp++;
            printf("\nTop of stack: T");
            pop();
            push('V');
            push('w');
        }
        if(top()=='V')
        {
            temp++;
            printf("\nTop of stack: V");
            v++;
            if(v%2!=0)
            {
                pop();
                push('V');
                push('y');
                push('F');
                push('*');
            }
            else
            {
                pop();
            }

        }
        if(top()=='F')
        {
            temp++;
            printf("\nTop of stack: F");
            f++;
            if(f==1)
            {
                pop();
                push('z');
            }

            else
                pop();
        }
        if(top()=='w' && string[i]=='w')
        {
            temp++;
            printf("\nTop of stack: w");
            pop();
        }
        if(top()=='+' && string[i]=='+')
        {
            temp++;
            printf("\nTop of stack: +");
            pop();
        }
        if(top()=='x'&& string[i]=='x')
        {
            temp++;
            printf("\nTop of stack: x");
            pop();
        }
        if(top()=='z' && string[i]=='z')
        {
            temp++;
            printf("\nTop of stack: z");
            pop();

        }
        if(top()=='*' && string[i]=='*')
        {
            temp++;
            printf("\nTop of stack: *");
            pop();
        }
        if(top()=='y' && string[i]=='y')
        {
            temp++;
            printf("\nTop of stack: y");
            pop();
        }
        if(temp==0)
        {
            printf("\n\nString Rejected (no such rule in PDA)\n\n");
            exit(0);
        }


    }
    printf("\n\nString Accepted\n\n");

}
/*  Function to add an element to the stack */
void push (char token)
{
        if (s.top == (MAXSIZE - 1))
        {
            printf ("Stack is Full\n");
            return;
        }
        s.top = s.top + 1;
        s.stk[s.top] = token;
}
/*  Function to delete an element from the stack */
    void pop ()
    {
        s.top = s.top - 1;
    }

char top()
{
    return s.stk[s.top];
}
/*  Function to display the status of the stack */
void display ()
{
    int i;
    if (s.top == -1)
    {
        printf ("Stack is empty\n");
        return;
    }
    else
    {
        printf ("\n The status of the stack is \n");
        for (i = s.top; i >= 0; i--)
        {
            printf ("%c\n", s.stk[i]);
        }
    }
    printf ("\n");
}
int lengthOf(char *t)
{
    int count=0;
    while(*t!='\0')
    {
        count++;
        t++;
    }
    return(count);

}
