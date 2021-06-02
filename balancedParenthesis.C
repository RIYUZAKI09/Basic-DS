#include<stdio.h>
#include<bits/stdc++.h>
#define size 20


struct Stack{
	char stack[size];
	int top;
};

void push(struct Stack* st,char num){
		if(st->top< size-1){
			st->top = st->top+1;
			st->stack[st->top]=num;
			return;
		}
		else {
			printf("Stack overflow\n");
			return;
		}
	}
	
char pop(struct Stack* st){
		if(st->top>-1){
			char x;
			x = st->stack[st->top];
			st->top = st->top-1;
			return x;
		}
		else {
			printf("Stack underflow\n");
			return '\0';
		}
	}
	
void displayStack(struct Stack* st){
	if(st->top >= 0){
		int m=st->top;
		while(m>= 0){
			printf("%c\n",st->stack[m]);
			m--;
		}
		return;
	}
	else {
		printf("Stack underflow\n");
		return;
	}
}

bool isEmpty(struct Stack* st){
	if(st->top == '\0'){
		return true;
	}else{
		return false;
	}
}

bool isMatchingPair(char c1, char c2) 
{ 
    if (c1 == '(' && c2 == ')') 
        return true; 
    else if (c1 == '{' && c2 == '}') 
        return true; 
    else if (c1 == '[' && c2 == ']') 
        return true; 
    else
        return false; 
} 
  

bool balancedParathesis(char str[]) 
{ 
    int i = 0; 
    struct Stack s ;
    s.top = '\0';
  
    while (str[i]) { 
    	char k = str[i];
        if (str[i] == '{' || str[i] == '(' || str[i] == '[') 
            push(&s, str[i]);
 
        if (str[i] == '}' || str[i] == ')' || str[i] == ']') { 
            if (s.top == '\0') 
                return 0; 

            else if ( !isMatchingPair(pop(&s),k) ) 
                return 0; 
        } 
        i++; 
    } 

    if (s.top == '\0' ) 
        return 1; 
    else
        return 0; 
}

int main(int argc, char const *argv[])
{
	char str[100000];
	printf("Enter the equation: \n");
	scanf("%s",str);
	if(balancedParathesis(str)){
		printf("equation is balanced.\n");
	}else{
		printf("equation is not balanced.\n");
	}
	return 0;
}