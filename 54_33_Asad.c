#include <stdio.h>
#define size 100
int a[size];
int t=-1;

void push(int data){
    if(t>=size-1){
        printf("Stack Overflow");
    }
    t++;
    a[t]=data;
}

int pop(){
    if(t==-1){
        printf("Stack Empty");
    }
    int r=a[t];
    t--;
    return r;
}

void peek(){
    if(t==-1){
        printf("Stack Empty");
    }
    for(int i=0;i<=t;i++){
        printf("%d\n",a[i]);
    }
}

void search(int data){
    for(int i=0;i<=t;i++){
        if(a[i]==data){
            printf("Found at %d\n",i+1);
            return;
        }
    }
    printf("Not Found\n");
}
int main() {
    int choice, data;
    while (1) {
        printf("\nStack Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Search\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                data = pop();
                    printf("Popped element: %d\n", data);

                break;
            case 3:
                peek();
                break;
            case 4:
                printf("Enter element to search: ");
                scanf("%d", &data);
                search(data);
                break;
            case 5:
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
