#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct ArrayStack                                         //Step 1.1: to make a structure
{
    int top;                                              //Step 1.2: to make an int top which will show the current position of Stack
    unsigned capacity;                                    //Step 1.3: to make capacity variable which will make an array of the desired capacity
    int *array;                                           //Step 1.4: to make an array variable which will store the data
};
struct ArrayStack* CreateStack(int cap)                   //Step 2.1: to make a function block which will make stack
{
    struct ArrayStack *Stack;                             //Step 2.2: to create a pointer which will point to Structure
    Stack=malloc(sizeof(struct ArrayStack));              //Step 2.3: to assign memory with the help of DMA
    Stack->capacity=cap;                                //Step 2.4: to put in the value of capacity got from user
    Stack->top = -1;                                        //Step 2.5: to assign a position to top to start the stack from
    Stack->array=malloc(sizeof(sizeof(int)*(Stack->capacity))); //Step 2.6: to make an array of 'capacity' size
    return (Stack);                                       //Step 2.7: returning the address of stack pointer
}
int isFULL(struct ArrayStack *Stack)                      //Step 3.1: to make a function which will check if the stack is full or not
{
    if(Stack->top == (Stack->capacity-1))                     //do not forget to use arrow pointer from stack to data type since we cant access data type directly
        return 1;
    else
        return 0;
}
int isEmpty(struct ArrayStack *Stack)                     //Step 4.1: to make a function which will check if the stack is empty or not
{
    if(Stack->top==-1)
        return 1;
    else
        return 0;
}
void push(struct ArrayStack *Stack, int item)             //Step 5.1: to make a function which will add a value in the stack

{
    if(isFULL(Stack))                                     //Step 5.2: checking if the stack is full or not
    {
        printf("Sorry you cant add more values Stack is already full\n");
        getch();
    }
    else
    {
        Stack->top++;                                     //Step 5.3: incrementing the value of top so the pointer on array move forward to the next empty block and put in the value
        Stack->array[Stack->top]=item;
    }
}
int pop(struct ArrayStack *Stack)                         //Step 6.1: to make a function which will remove the value from the stack
{
    int item;
    if(isEmpty(Stack))                                    //Step 6.2: checking if the stack is empty or not
        return (-1);
    else
    {
        item=Stack->array[Stack->top];                    //Step 6.3: allotting value to item for further display of removed item
        Stack->top--;                                     //Step 6.4: decrementing top value so that it will point the new last number
        return (item);
    }
}
int peek(struct ArrayStack *Stack)                        //Step 7.1: to make a function which will show case the value at the top
{
        return (Stack->array[Stack->top]);
}
int menu()                                                //Step 8.1: just a simple printf routine
{
    int a;
    printf("======================================================\n");
    printf("===================STACK LIST MAKER===================\n");
    printf("======================================================\n");
    printf("1.push\n");
    printf("2.pop\n");
    printf("3.peek\n");
    printf("4.X-IT\n");
    printf("Enter choice:");
    scanf("%d",&a);
    return a;
}
int main()
{
    struct ArrayStack *Stack;
    int a,item,cap;                                       //Step 9.1: declaring stack pointer earlier
    printf("Enter the capacity of the stack:");
    scanf("%d",&cap);
    Stack=CreateStack(cap);
    while(1)                                              //infinite loop
    {
        switch(menu())                                    //9.2: calling menu function in switch and making case for desired choice
        {
        case 1:
              {
                printf("Enter the number you wanna insert in stack:");
                scanf("%d",&a);
                push(Stack,a);break;
              }
        case 2:
               {
                   item=pop(Stack);
                   if(item==-1)
                   {
                    printf("Stack is empty");
                    getch();
                   }
                   else
                   printf("popped value is %d",item);
                   getch();break;
               }
        case 3:
                {
                    item=peek(Stack);
                    if(isEmpty(Stack))                                    //Step 7.2: same as 6.2
                      printf("Stack is Empty");
                    else
                    printf("top value is %d",item);
                    getch();break;
                }
        case 4:
                exit(0);break;
        default:
            {
                printf("invalid choice\n");
                getch();break;
            }

        }
        system("cls");
    }
}
