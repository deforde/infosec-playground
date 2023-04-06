shellcode: shellcode.c
	gcc -g3 -fno-stack-protector -z execstack -D_FORTIFY_SOURCE=0 -static shellcode.c -o shellcode

shellcode_asm: shellcode_asm.c
	gcc -g3 -fno-stack-protector -z execstack -D_FORTIFY_SOURCE=0 -static shellcode_asm.c -o shellcode_asm

sc_stckex: sc_stckex.c
	gcc -g3 -fno-stack-protector -z execstack -D_FORTIFY_SOURCE=0 -static sc_stckex.c -o sc_stckex
