#include "types.h"
#include "user.h"

int stdout = 1;
int stderr = 2;

int main(int argc, char *argv[])
{

    int pid = fork();
    if (pid != 0)
    {
        char *argvv[] = {"mixedTest"};
        int execR = exec("mixedTest", argvv);
        printf(stderr, "execR: %d\n", execR);
        // printf(stderr, "Scheduler test finished p1\n");
    }
    else
    {
        char *argvv[] = {"mixedTest"};
        int execR = exec("mixedTest", argvv);
        printf(stderr, "execR: %d\n", execR);
        // printf(stderr, "Scheduler test finished p2\n");
    }
    exit();
}