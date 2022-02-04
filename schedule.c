#include "types.h"
#include "user.h"

// argc = number of arguments + 1 (discovered priting argc)
#define MINIMUM_ARGS 3
int stdout = 1;
int stderr = 2;

void printerr(char *message)
{
    printf(stderr, message);
}

int main(int argc, char *argv[])
{
    if (argc < MINIMUM_ARGS)
    {
        printerr("An error occurred running the schedule command: too few arguments!\n");
        exit();
    }
    int pid = atoi(argv[1]);
    int priority = atoi(argv[2]);

    if (priority < 0 || priority > 20)
    {
        printerr("An error occurred running the schedule command: invalid priority (0-20)!\n");
        exit();
    }
    setpriority(pid, priority);
    exit();
}