#include "types.h"
#include "user.h"
#include "date.h"
#define ONE_SEC 100

const char *toad = "    _    _\n"
                   "   (o)--(o)\n"
                   "  /.______.\\\n"
                   "  \\________/\n"
                   " ./        \\.\n"
                   "( .        , )\n"
                   " \\ \\_\\  /_/ /\n"
                   "  ~~  ~~  ~~\n";

int stdout = 1;
int stderr = 2;

// Prints 5 frogs, so it takes time to do.
// Each frog has a sleep of one second betwheen it print state,
// so the execution of this program MUST take at least 5 seconds.
// heavily intensive USER TIME
int main(int argc, char *argv[])
{
    for (int i = 0; i < 5; i++)
    {
        printf(stdout, toad);
        sleep(ONE_SEC);
    }
    exit();
}