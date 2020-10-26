#include "file.h"

#pragma once

void newOpen(char *name, int mode);
void newClose();
int newRead();
void newWrite(char c);
void newSeek(long index, int mode);

extern struct FILE newConsole;
