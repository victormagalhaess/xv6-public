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

// User program that runs the program passed as argument and mensure the program's real, user and sys times
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
    int rstart = uptime();
    int send = 0;
    int uend = 0;

    //fork logic copyied from init.c file
    int pid = fork();
    if (pid < defaultpid)
    {
        printf(stdout, "time: fork failed\n");
        exit();
    }

    if (pid == defaultpid)
    {
        uend = uptime() - rstart;
        exec(command, params);
        exit();
    }

    if (pid > defaultpid)
    {
        twait(&send, &uend);
        int rend = uptime();
        int rtotal = rend - rstart;
        printt(rtotal, real);
        printt(uend, user);
        printt(send, sys);
        exit();
    }

    exit();
}

// Print the miliseconds on 0m0.000s format
void printt(int milisec, char *type)
{
    printf(stdout, timemsg, type);
    int decim = milisec % 1000;
    int sec = milisec / 1000;
    int min = sec / 60;
    sec %= 60;
    if (decim < 10)
        printf(stdout, "%dm%d.00%ds\n", min, sec, decim);
    else if (decim < 100 && decim >= 10)
        printf(stdout, "%dm%d.0%ds\n", min, sec, decim);
    else
        printf(stdout, "%dm%d.%ds\n", min, sec, decim);
}