#include <stdio.h>

int main(void) {
    int num = 0;
    scanf("%d", &num);

    int result = 1;
    for (int i = 2; i <= num; i++) {
        result *= i;
    }
    printf("%d", result);

    return 0;
}