#include <stdio.h>
#include "newconsole.h"
#include "file.h"

void newOpen(char *name, int mode)
{
}
void newClose()
{
}
int newRead()
{
    int c;

    printf("lol\n");

    return c;
}
void newWrite(char c)
{
}
void newSeek(long index, int mode)
{
}


struct FILE newConsole = {newOpen, newClose, newRead, newWrite, newSeek};
