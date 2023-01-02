
#include<stdio.h>
#include <ctype.h>
//#include<conio.h>


int str[20];
int top=-1;

void push(int x){

   top=top+1;
   str[top]=x;

}

int pop(){

int temp;

if(top==-1)
     return -1;
temp=str[top];

 top--;
 return temp;
}


int main(void){

char exp[20];
char *e,x,op1,op2;
int i,r=1;
printf("enter the postfix expression");


  scanf("%s",exp);
  e=exp;
  while(*e!='\0'){
     if(isdigit(*e))
          push(*e-'0');
        else
        {        /* Operator,pop two  operands */
            op2=pop();
            op1=pop();
            switch(*e)
            {
            case '^':for(i=1;i<=op2;i++){
                        r=r*op1;
                       }
                       push(r);
                       break;

            case '+':push(op1+op2);break;
            case '-':push(op1-op2);break;
            case '*':push(op1*op2);break;
            case '/':push(op1/op2);break;
            }
        }


  e++;
}

   //printf("\n Given Postfix Expn: %s\n",pofx);
    rintf("\n Result after Evaluation: %s\n",str[top]);

}



