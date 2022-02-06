#include "types.h"
#include "user.h"

// argc = number of arguments + 1 (discovered priting argc)
#define MINIMUM_ARGS 3
#define MINIMUM_PRIORITY 1
#define MAXIMUM_PRIORITY 10
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

    if (priority >= MINIMUM_PRIORITY && priority <= MAXIMUM_PRIORITY)
    {
        setprio(pid, priority);
        exit();
    }
    else
    {
        printerr("An error occurred running the schedule command: wrong value to priority!\n");
        exit();
    }
}