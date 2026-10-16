#include <stdio.h>

int main() {
    int n; long long f = 1;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) f *= i;   // combined multiply-and-assign, skip i=1
    printf("%lld\n", f);
    return 0;
}