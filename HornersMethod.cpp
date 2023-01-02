#include<stdio.h>
int main(void){

int i,j;
int a[10];
int p[10];
//int a[3]=1,a[2]=-4,a[1]=1,a[0]=6,x=2;
int x=2;
for(i=3;i>=0;i--){

  printf("a%d=",i);
  scanf("%d",&a[i]);
  printf("\n");

}

p[3]=a[3];
printf("p3 =%d",p[3]);

for(i=2;i>=0;i--){

   p[i]= (p[i+1]*x)+ a[i];
   printf(" P%d = ",i);
   printf("%d",p[i]);
   printf("\n");


}



}
