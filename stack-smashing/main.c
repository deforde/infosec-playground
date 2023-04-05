#include <stdint.h>
#include <stdio.h>

void foo(void) {
    int i;
    int64_t *ret = (int64_t*)((char*)&i + 20);
    *ret += 7;
}

int main(void) {
    int x = 0;
    foo();
    x = 1;
    printf("x = %i\n", x);
    return 0;
}
