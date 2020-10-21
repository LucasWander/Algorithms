#include <stdio.h>
#include "point.h"

int main() {

    struct Point *p = createPoint(45,0.565);
    struct Point *p2 = createPoint(1,1);

    p->x = 45;

    showPoint(p);
    showPoint(p2);

    double distance = distanceBetween(p,p2);

    printf("%f\n",distance);

    return 0;
}
