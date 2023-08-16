#include<stdio.h>
#include<string.h>

struct stud{
int roll_no;
float percent;
char name[10];
};

int main(){
struct stud s[5];
float temp;

	//taking input from user
	for(int i=0;i<=4;i++){
	printf("enter the rollno of student%d:",i+1);
	scanf("%d",&s[i].roll_no);
	
	printf("enter the percentage of student%d:",i+1);
	scanf("%f",&s[i].percent);
	
	printf("enter the name of student%d:",i+1);
	scanf("%s",s[i].name);
	
	}
	//percentage sorting in descending order
	for(int i=0;i<=4;i++){
	
		for(int j=i+1;j<=5;j++){
		
			if(s[i].percent< s[j].percent){
			//sorting condition
				temp = s[i].percent;
				s[i].percent = s[j].percent;
				s[j].percent = temp;
			}
		}	
	}
	
	//Displaying output 
	for(int i=0;i<=4;i++){
		
		printf("Roll_no :%d\n",s[i].roll_no);
		printf("Percentage : %f\n",s[i].percent);
		printf("Name : %s\n",s[i].name);
		
		}
}
