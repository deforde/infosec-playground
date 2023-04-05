#include <unistd.h>

int main(void) {
    char *name[] = {
        "/bin/sh",
        NULL,
    };
    execve(name[0], name, NULL);
    return 0;
}
