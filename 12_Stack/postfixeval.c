//SIYA P P CU3_55
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define MAX_SIZE 100
int stack[MAX_SIZE];
int top = -1;
void push(int value) 
{
    if (top == MAX_SIZE - 1) 
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    top++;
    stack[top] = value;
}
int pop() 
{
    if (top == -1) 
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    int poppedElement = stack[top];
    top--;
    return poppedElement;
}
int evaluatePostfix(char postfix[])
{
    int i, operand1, operand2, result;
    for (i = 0; postfix[i] != '\0'; i++) 
    {
        if (isdigit(postfix[i])) 
        {
            push(postfix[i] - '0');
        } 
        else 
        {
            operand2 = pop();
            operand1 = pop();
            switch (postfix[i]) 
            {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                case '^':
                    result = (int) pow(operand1,operand2);
                    break;
                default:
                    printf("Invalid operator\n");
                    exit(1);
            }
            push(result);
        }
    }
    return pop();
}
int main() {
    char postfix[MAX_SIZE];
    printf("Enter the postfix expression: ");
    scanf("%s", postfix);
    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);
    return 0;
}

       OUTPUT
Enter the postfix expression: 123*+4-
Result: 3