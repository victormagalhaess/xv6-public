#include "types.h"
#include "user.h"

int stdout = 1;
int stderr = 2;

// heavily intensive USER TIME

int main(int argc, char *argv[])
{
    char *toad = "    _    _\n"
                 "   (o)--(o)\n"
                 "  /.______.\\\n"
                 "  \\________/\n"
                 " ./        \\.\n"
                 "( .        , )\n"
                 " \\ \\_\\  /_/ /\n"
                 "  ~~  ~~  ~~\n";

    char *twobe = "Everything that lives is designed to end. We are perpetually trapped in a never-ending spiral of life and death. Is this a curse? Or some kind of punishment? I often think about the god who blessed us with this cryptic puzzle...and wonder if we'll ever get the chance to kill him.\n";
    char *simone = "Such nonsense! It's physically impossible to obtain beauty by consuming androids flesh. But I tried it anyway. I would try anything. I wanted to vomit, but I kept going. It tasted like oil.\n";
    //Simone's quote is quite horrifing. May I remove it?
    for (int i = 0; i < 25000; i++)
    {
        strcpy(simone, twobe);
        strcmp(twobe, simone);
        strlen(twobe);
        strlen(simone);
        strlen(toad);
    }
    exit();
}