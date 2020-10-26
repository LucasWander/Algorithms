#include <stdio.h>
#include "console.h"
#include "file.h"

void open(char *name, int mode)
{
}
void close()
{
}
int read()
{
    int c;

    printf("teste\n");

    return c;
}
void write(char c)
{
}
void seek(long index, int mode)
{
}


struct FILE console = {open, close, read, write, seek};
