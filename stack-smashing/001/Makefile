a.out: main.c
	gcc -fno-stack-protector -g3 main.c

test: main2.c
	gcc -fno-stack-protector -g3 -z execstack main2.c -o test
