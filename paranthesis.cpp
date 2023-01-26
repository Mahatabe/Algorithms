#include<stdio.h>
#include<string.h>


int main(){
    int bf = 0;
    int i;
    char exp[100];
    
    scanf("%s", &exp);
    
    for(i=0; i< strlen(exp); i++){
        
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            bf++;
        }
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
            bf--;
            if(bf<0){
                break;
            }
        }
        
    }
    if(bf==0){
        printf("Balanced \n");
    }
    else{
        printf("Not Balanced\n");
    }
    return 0;
}
