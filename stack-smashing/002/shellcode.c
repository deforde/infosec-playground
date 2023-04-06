#include <unistd.h>

/*

Disassembly of the relevant parts of `main`:

lea    0x968ac(%rip),%rax # 0x498004 - loads the address of the "/bin/sh" string (i.e. %rip + 0x968ac) into %rax, %rip is the instruction pointer
mov    %rax,-0x10(%rbp) # copies the address now stored in %rax into the memory address %rbp-0x10, %rbp is the base pointer, which points to the beginning of the current stack frame, this is effectively `name[0] = "/bin/sh"`
movq   $0x0,-0x8(%rbp) # copies 0x0 into the address %rbp-0x8, this is effectively `name[1] = NULL`
mov    -0x10(%rbp),%rax # copies the address of %rbp-0x10 into rax, i.e. %rax = &name[0], or just %rax = name
lea    -0x10(%rbp),%rcx # copies the _value_ at %rbp-0x10 (i.e. the address of "/bin/sh"), into %rcx
mov    $0x0,%edx # copies 0x0 into %edx
mov    %rcx,%rsi # copies %rcx into %rsi, %rcx is the address of "/bin/sh", %rsi stores the 2nd arg of execve
mov    %rax,%rdi # copies %rax into %rdi, %rax is the address of `name`, %rdi stores the 1st arg of execve
call   0x446730 <execve> # calls execve


Disassembly of the relevant parts of `execve`:

mov    $0x3b,%eax # copies 0x3b into %eax, this is the offset into the syscall table, 59 is the index of execve
syscall # makes the syscall

*/

int main(void) {
    char *name[] = {
        "/bin/sh",
        NULL,
    };
    execve(name[0], name, NULL);
    return 0;
}
