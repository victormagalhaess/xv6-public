#include "types.h"
#include "user.h"
#include "date.h"

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

// Prints 5 frogs, so it takes time to do
int main(int argc, char *argv[])
{
    for (int i = 0; i < 5; i++)
    {
        sleep(1);
        printf(stdout, toad);
    }
    exit();
}