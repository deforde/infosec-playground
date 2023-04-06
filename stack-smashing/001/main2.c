int main(void) {
    // To detemine what opcodes are required in order to
    // implement a sum function, compile the inline asm
    // below, and inspect the generated opcodes by running:
    // $ gdb test -ex="disassemble /r main"
    //
    // asm volatile (
    //     "mov %edi,%eax\n\t"
    //     "add %esi,%eax\n\t"
    //     "ret"
    // );
    char sum[] = {
        0x89,0xf8,  // mov %edi,%eax
        0x01,0xf0,  // add %eax,%esi
        0xc3        // ret
    };
    int (*sum_func)(int, int) = sum;
    return sum_func(1, 2);
}
