#include <stdio.h>
#include "point.h"
#include "namedPoint.h"

int main() {

    struct Point *p = createPoint(45,0.565);
    struct Point *p2 = createPoint(1,1);
    struct NamedPoint *np = createNamedPoint(45,20, "Teste");
    struct NamedPoint *np2 = createNamedPoint(1,20, "QWER");


    showPoint(p);
    showPoint(p2);
    showPoint((struct Point*) np);

    double distance = distanceBetween(p,p2);

    printf("%f\n",distance);

    return 0;
}
