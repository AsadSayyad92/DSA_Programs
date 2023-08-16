#include <stdio.h>

int main() {
    int n, i;
    int first = 0, second = 1, next,flag=0;

    printf("Enter the number: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");

    for (i = 0; i < 10; i++) {
        if (i <= 1)
          next = i;
        while (second <= n) {
                next= second;
                second = first + second;
                first= next;
                if (second == n) {
                        flag = 1;
                        break;
                }
        }
	}
		
        
        if (flag) {
                printf("%d is a fibonacci number\n", n);
        } else {
                printf("%d is not a fibonacci number\n", n);
        }
        return 0;
  
}
