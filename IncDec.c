#include <stdio.h>
int main() {
    int a = 5;
    printf("Before: a = %d\n", a);
    printf("a++ gives: %d\n", a++);   // uses old value, THEN adds 1
    printf("After:  a = %d\n", a);
    return 0;
}


#include <stdio.h>
int main() {
    int b = 5;
    printf("Before: b = %d\n", b);
    printf("++b gives: %d\n", ++b);   // adds 1 FIRST, then uses new value
    printf("After:  b = %d\n", b);
    return 0;
}


Before: c = 5
c-- gives: 5
After:  c = 4

#include <stdio.h>
int main() {
    int d = 5;
    printf("Before: d = %d\n", d);
    printf("--d gives: %d\n", --d);   // subtracts 1 FIRST, then uses new value
    printf("After:  d = %d\n", d);
    return 0;
}


Before: d = 5
--d gives: 4
After:  d = 4