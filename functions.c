//
// Created by Marley on 19/04/2023.
//

#include <malloc.h>
#include "functions.h"

// Structure to create a point
typedef struct point POINT;

// Function which creates a point using the structure
POINT *createPoint(int x, int y) {
    POINT *p = malloc(sizeof(POINT));
    p->x = x;
    p->y = y;
    return p;
}

LINE *createLine(POINT *p1, POINT *p2) {
    LINE *l = malloc(sizeof(LINE));
    l->p1 = p1;
    l->p2 = p2;
    return l;
}