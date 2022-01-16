#include <stdio.h>
#include <stdlib.h>


int stack[256];
int top, insert;
int i, j, k;
int rep = 5;
int pushable = 1;

void Push(int insert)
{
    stack[top] = insert;
    top++;
}

void Pop()
{
    // No popping for now
    stack[top] = NULL;
    top--;
}

void Search(int insert)
{
    if (top == 0)
    {
        Push(insert);
    } else
    {
        for(j=0; j<top; j++) {
            if (insert == stack[j])
            {
                pushable = 0;
            }
        }
        if (pushable)
        {
            Push(insert);
        } else
        {
            pushable = 1;
        }
    }
}

int main()
{
    printf("Add %d Values to the stack:\n", rep);
    for(i=0; i<rep; i++)
    {
        scanf("\n%d\n", &insert);
        Search(insert);
        // bug where for loop runs one too long, or the stack is pushed one to little times
    }

    for(k=0; k<top; k++)
    {
        printf("    %d", stack[k]);
    }

    return 0;
}
