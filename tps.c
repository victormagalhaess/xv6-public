#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int stdout = 1;
int stderror = 2;
#define timemsg "%s "
#define alert "Time elapsed: "

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

int main(int argc, char *argv[])
{
    int pid = fork();
    int ticksOnStart = uptime();
    ps();

    if (pid == 0)
    {
        char *command = argv[1];
        char **arguments = argv + 1;
        if (exec(command, arguments) < 0)
        {
            exit();
        }
    }
    else if (pid > 0)
    {
        printf(stdout, "Waiting for child\n");
        wait();
    }
    else
    {
        printf(stderror, "scheduler test: Fork error\n");
        exit();
    }
    ps();

    int ticksOnEnd = uptime();
    int ticksDifference = ticksOnEnd - ticksOnStart;
    printt(ticksDifference, alert);
    exit();
    ps();
}