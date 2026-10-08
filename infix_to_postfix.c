#include <stdio.h>
#define SIZE 100
char stack[SIZE];
int top=-1;
void push(char x) {
    if(top==SIZE-1)
        printf("Stack Overflow\n");
    else {
        top++;
        stack[top] = x;
    }
}
char pop() {
    if(top==-1) {
        printf("Stack Underflow\n");
        return '\0';
    } else {
        return stack[top--];
    }
}
int priority(char x) {
    if(x=='^')
        return 3;
    else if(x=='*'||x=='/')
        return 2;
    else if(x=='+'||x=='-')
        return 1;
    else
        return 0;
}
void POLISH(char Q[], char P[]) {
    int i=0, j=0;
    while(Q[i]!='\0') {
        if((Q[i]>='a'&&Q[i]<='z')||(Q[i]>='A'&&Q[i]<='Z')||(Q[i]>='0'&&Q[i]<='9')) {
            P[j++] = Q[i];
        } 
        else if(Q[i]=='(') {
            push(Q[i]);
        } 
        else if(Q[i]==')') {
            while((top!=-1)&&(stack[top]!='(')) {
                P[j++] = pop();
            }
            if(top!=-1) {
                pop();
            }
        } 
        else {
            while((top!=-1)&&(stack[top]!='(')&&(priority(stack[top])>=priority(Q[i]))) {
                P[j++] = pop();
            }
            push(Q[i]);
        }
        i++;
    }
    while(top!=-1) {
        P[j++] = pop();
    }
    P[j] = '\0';
}
int main() {
    char Q[SIZE], P[SIZE];
    printf("Enter the infix expression: ");
    scanf("%s", Q);
    POLISH(Q, P);
    printf("The postfix expression is: %s\n", P);
    return 0;
}