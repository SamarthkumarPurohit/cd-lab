#include <stdio.h> 
#include <string.h> 
char stack[20]; 
int top = -1; 
char input[20]; 
int i = 0; 
/* Push operation */ 
void push(char c) 
{ 
stack[++top] = c; 
} 
/* Pop operation */ 
void pop(int n) 
{ 
top = top - n; 
} 
/* Display stack */ 
void display() 
{ 
for(int j=0; j<=top; j++) 
printf("%c", stack[j]); 
} 
/* Check for reductions */ 
void reduce() 
{ 
if(stack[top]=='i') 
{ 
printf("\nReduce: E -> i"); 
stack[top]='E'; 
} 
if(top>=2 && stack[top]=='E' && stack[top-1]=='+' && stack[top-2]=='E') 
{ 
printf("\nReduce: E -> E+E"); 
pop(2); 
stack[top]='E'; 
} 
if(top>=2 && stack[top]=='E' && stack[top-1]=='*' && stack[top-2]=='E') 
{ 
printf("\nReduce: E -> E*E"); 
pop(2); 
stack[top]='E'; 
} 
} 
int main() 
{ 
printf("Enter input string (use i for id): "); 
scanf("%s", input); 
printf("\nStack\tInput\tAction\n"); 
while(i < strlen(input)) 
{ 
push(input[i]); 
printf("\n"); 
display(); 
printf("\t%s\tShift %c", input+i, input[i]); 
reduce(); 
i++; 
} 
reduce(); 
if(stack[top]=='E') 
printf("\n\nString Accepted\n"); 
else 
printf("\n\nString Rejected\n"); 
return 0; 
} 