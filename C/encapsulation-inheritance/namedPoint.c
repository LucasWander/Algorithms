#include <stdlib.h>
#include "namedPoint.h"

struct NamedPoint {
    double x;
    double y;
    char *name;
};


struct NamedPoint* createNamedPoint(double x, double y, char *name) {

    struct NamedPoint *namedPoint = malloc(sizeof(struct NamedPoint));

    namedPoint->x = x;
    namedPoint->y = y;
    namedPoint->name = name;

    return namedPoint;
}


void setName(struct NamedPoint *namedPoint, char *name) {
    namedPoint->name = name;
}

char* getName(struct NamedPoint *namedPoint) {
    return namedPoint->name;
}
