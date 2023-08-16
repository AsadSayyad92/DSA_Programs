#include<stdio.h>

int main()
{

 int largest[100];
 int n;
 	printf("enter the number of elemnts:");
 	scanf("%d",&n);
 	
 	for(i=1;i<=n;i++){
 	printf("enter the number%d:",i);
 	scanf("%d",&largest[i]);
 	}
 	
 	 	for(int i=1;i<=n;i++){
 	 	
 	 		if(largest[0]<largest[i]){
 	 		largest[0]=largest[i];
 	 		}
 	 	}
 	 	
 	 printf("largest element =%d",largest[0]);
 }
 		


