int main(void) {
    // To detemine what opcodes are required in order to
    // implement a sum function, compile the inline asm:
    //
    // asm volatile (
    //     "mov %edi,%eax\n\t"
    //     "add %esi,%eax\n\t"
    //     "ret"
    // );
    //
    // And inspect the generated opcodes by running:
    // $ gdb test -ex="disassemble /r main"
    // %esi and %edi are used to store function arguments,
    // %eax stores the return value.
    //
    // These conventions change depending on machine & compiler,
    // they can be tested by defining an equivalent (real) function
    // and inspecting the generated asm.

    char sum[] = {
        0x89,0xf8,  // mov %edi,%eax
        0x01,0xf0,  // add %esi,%eax
        0xc3        // ret
    };
    int (*sum_func)(int, int) = sum;
    return sum_func(1, 2);
}
