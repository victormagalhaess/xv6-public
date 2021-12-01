#include "types.h"
#include "user.h"
#include "date.h"

// argc = number of arguments + 1 (discovered priting argc)
#define zeroargs 1
#define timemsg "%s      "
#define real "real"
#define user "user"
#define sys "sys "
#define defaultpid 0

int stdout = 1;
int stderr = 2;

void printt(int time, char *type);

// User program that runs the program passed as argument
// and mensure the program's real, user and sys times
// This program depends on the syscall sys_waitCountTicks.
// sys_waitCountTicks acts exactly as a normal wait,
// but instead of just waiting the children die, it actually gets the
// number of ticks of the child process before it dies and returns it
// (via pointers) to the time function.
int main(int argc, char *argv[])
{

    if (argc == zeroargs)
    {
        printt(0, real);
        printt(0, user);
        printt(0, sys);
        exit();
    }

    char *command = argv[1];
    char **params = argv + 1;
    int ticksOnStart = uptime();
    int sysTicks = 0;
    int usrTicks = 0;

    //fork logic copyied from init.c file
    int pid = fork();
    if (pid < defaultpid)
    {
        printf(stdout, "time: fork failed\n");
        exit();
    }

    if (pid == defaultpid)
    {
        usrTicks = uptime() - ticksOnStart;
        exec(command, params);
        exit();
    }

    if (pid > defaultpid)
    {
        waitCountTicks(&sysTicks, &usrTicks);
        int ticksOnEnd = uptime();
        int totalTicks = ticksOnEnd - ticksOnStart;
        printt(totalTicks, real);
        printt(usrTicks, user);
        printt(sysTicks, sys);
        exit();
    }

    exit();
}

// Print the ticks on 0m0.000s format
void printt(int ticks, char *type)
{
    printf(stdout, timemsg, type);
    int decim = ticks % 100;
    int sec = ticks / 100;
    int min = sec / 60;
    sec %= 60;
    if (decim < 10)
        printf(stdout, "%dm%d.00%ds\n", min, sec, decim);
    else if (decim < 100 && decim >= 10)
        printf(stdout, "%dm%d.0%ds\n", min, sec, decim);
    else
        printf(stdout, "%dm%d.%ds\n", min, sec, decim);
}