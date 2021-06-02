#include <stdio.h> 
#include<bits/stdc++.h>
  
struct Stack 
{ 
    int top; 
    unsigned capacity; 
    int* array; 
}; 
  
struct Stack* createStack( unsigned capacity ) 
{ 
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack)); 
  
    if (!stack)  
        return NULL; 
  
    stack->top = -1; 
    stack->capacity = capacity; 
  
    stack->array = (int*) malloc(stack->capacity * sizeof(int)); 
  
    return stack; 
} 
int isEmpty(struct Stack* stack) 
{ 
    return stack->top == -1 ; 
} 
char ElementAtTop(struct Stack* stack) 
{ 
    return stack->array[stack->top]; 
} 
char pop(struct Stack* stack) 
{ 
    if (!isEmpty(stack)) 
        return stack->array[stack->top--] ; 
    return '$'; 
} 
void push(struct Stack* stack, char op) 
{ 
    stack->array[++stack->top] = op; 
} 
  
  
int isOperand(char ch) 
{ 
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'); 
} 
  
int Precedence(char ch) 
{ 
    switch (ch) 
    { 
    case '+': 
    case '-': 
        return 1; 
  
    case '*': 
    case '/': 
        return 2; 
  
    case '^': 
        return 3; 
    } 
    return -1; 
} 
   
int infixToPostfix(char* str) 
{ 
    int i, k; 
   
    struct Stack* stack = createStack(strlen(str)); 
    if(!stack)
        return -1 ; 
  
    for (i = 0, k = -1; str[i]; ++i) 
    { 
        if (isOperand(str[i])) 
            str[++k] = str[i]; 
          
        else if (str[i] == '(') 
            push(stack, str[i]); 

        else if (str[i] == ')') 
        { 
            while (!isEmpty(stack) && ElementAtTop(stack) != '(') 
                str[++k] = pop(stack); 
            if (!isEmpty(stack) && ElementAtTop(stack) != '(') 
                return -1;               
            else
                pop(stack); 
        } 
        else 
        { 
            while (!isEmpty(stack) && Precedence(str[i]) <= Precedence(ElementAtTop(stack))) 
                str[++k] = pop(stack); 
            push(stack, str[i]); 
        } 
  
    } 
      while (!isEmpty(stack)) 
        str[++k] = pop(stack ); 
  
    str[++k] = '\0'; 
    printf( "%s", str ); 
} 
  
int main() 
{
    char str[1000];
    printf("ENTER THE EXPRESSION\n");
    scanf("%s",&str);
    printf("Postfix of the expression is:\t");
    infixToPostfix(str); 
    return 0; 
}