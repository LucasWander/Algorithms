#include "file.h"
#include "myin.h"

extern struct FILE* STDIN;

int getchar() {
    return STDIN->read();
}
