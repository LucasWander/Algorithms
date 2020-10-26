#include "file.h"

#pragma once

void open(char *name, int mode);
void close();
int read();
void write(char c);
void seek(long index, int mode);

extern struct FILE console;
