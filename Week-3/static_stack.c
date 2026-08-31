#include<stdio.h>

#define max 10

struct stack
{
    int a[max];
    int top;
}s;

void push(int x)
{
    if(s.top == max-1)
    {
        printf("Stack Overflow\n");
        return;
    }
    else
    {
        s.a[++s.top] = x;
    }
}

int pop()
{
    if(s.top == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        return (s.a[s.top--]);
    }
}

int peek()
{
    if(s.top == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return (s.a[s.top]);

}


void display()
{
    if(s.top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack element:\n");
    for(int i=0; i<=s.top; i++)
    {
        printf("%d ", s.a[i]);
    }
    printf("\n");
}

int main()
{
    s.top = -1;
    int ch,val,r;
    while(1)
    {
        printf("\nMENU\n");
        printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
            {
                printf("Enter value to push:\n");
                scanf("%d",&val);
                push(val);
                break;
            }
            case 2:
            {
                r = pop();
                if(r!= -1)
                {
                    printf("Popped element: %d\n",r);
                }
                break;
            }
            case 3:
            {
                r = peek();
                if(r!= -1)
                {
                    printf("Top element: %d\n",r);

                }
                break;
            }
            case 4:
            {
                display();
                break;
            }
            case 5:
            {
                return 0;
            }
            default:
            {
                printf("Invalid choice\n");
            }
        }
    }
    return 0;
}