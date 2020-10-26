#include <stdio.h>
#include "console.h"
#include "myin.h"
#include "newconsole.h"

void copy() {
    int c;

    c = getchar();
}

int main(){

    STDIN = &console;
    copy();

    STDIN = &newConsole;
    copy();

    return 0;
}
