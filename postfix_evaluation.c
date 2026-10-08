#include <stdio.h>
#include <ctype.h>
int stack[100];
int top=-1;
void main() {
    char exp[100];
    int i,a,b;
    printf("Enter the postfix expression: ");
    scanf("%s",exp);
    for(i=0;exp[i]!='\0';i++) {
        if(isdigit(exp[i])) {
            top++;
            stack[top]=exp[i]-'0';
        }
        else {
            b=stack[top--];
            a=stack[top--];
            if(exp[i]=='+')
            stack[++top]=a+b;
            else if(exp[i]=='-')
            stack[++top]=a-b;
            else if(exp[i]=='*')
            stack[++top]=a*b;
            else if(exp[i]=='/')
            stack[++top]=a/b;
        }
    }
    printf("Result = %d",stack[top]);
}
