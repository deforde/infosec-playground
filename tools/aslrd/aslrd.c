#include <unistd.h>
#include <sys/syscall.h>
#include <sys/personality.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        return 1;
    }
    syscall(SYS_personality, ADDR_NO_RANDOMIZE);
    execve(argv[1], (char*[]){argv[1], NULL}, NULL);
    return 0;
}
