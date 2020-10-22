#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "point.h"


struct Point{
    double x;
    double y;
};

struct Point* createPoint(double x, double y) {
    struct Point* point = (struct Point*) malloc(sizeof(struct Point));

    point->x = x;
    point->y = y;

    return point;
}


void showPoint(struct Point *point) {

    printf("x: %f\n", point->x);
    printf("y: %f\n", point->y);
}

double distanceBetween(struct Point *point1, struct Point *point2) {

    double x = point1->x - point2->x;
    double y = point1->y - point2->y;

    return sqrt(x * x + y * y);
}
