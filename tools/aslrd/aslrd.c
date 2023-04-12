#include <string.h>

#include <unistd.h>
#include <sys/syscall.h>
#include <sys/personality.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        return 1;
    }
    syscall(SYS_personality, ADDR_NO_RANDOMIZE);
    memmove(argv, &argv[1], (argc - 1) * sizeof(*argv));
    argv[argc - 1] = NULL;
    execve(argv[0], argv, NULL);
    return 0;
}
