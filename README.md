# infosec-playground

This is playground for learning about and experimenting with infosec related topics.

## stack-smashing

Demonstrations of return address manipulation.
Based partially on https://insecure.org/stf/smashstack.html.

### 001

Manually modify the return address of a function in order to skip over an instruction.

### 002

In this example we develop a buffer overflow exploit in order to modify the
return address of a function call such that we start executing data that we
have written to the stack.

1. shellcode.c:
Here we write some code to spawn a shell. We compile and disassemble this code
in order to work out what assembly is required in order to achieve this on the
machine that we are working with.

2. shellcode\_asm.c
Here we write some inline assembly that spawns a shell and then issues an exit
syscall once the shell terminates. Additionally, we make sure that the bytecode
generated from this asm does not contain any NUL bytes.
We compile and disassemble this inline asm in order to get the byte code that is
generated therefrom.

3. sc\_stckex.c:
Taking the byte code that we disassembled in step 2, we create a `char` buffer
on the stack that contains this byte code. We modify the return address of the
function such that it points at our `char` array, and therefore, when we compile
and execute this code, we can spawn a subshell.

4. buf\_of\_vuln.c:
Here we pull everything that we have done up until now together.
We demonstrate how we can exploit insecure usage of the `memcpy` function, using
a carefully crafted input, to manipulate a program into spawning a shell.
(Note that we have to disable ASLR and stack protection, and enable execution of
stack data in order to achieve this)

-------------------------------------------------------------------------------

## Tools

### aslrd
This can be used to execute a sub-program with ASLR disabled:
```
./aslrd my-sub-prog
```

-------------------------------------------------------------------------------

Everything here is built/executed within WSL2 running Ubuntu 22.04 on Windows 10
on an Intel x86\_64 machine.
