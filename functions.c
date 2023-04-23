//
// Created by Marley on 19/04/2023.
//

#include <stdio.h>
#include <malloc.h>
#include "functions.h"


// Function which creates a point using the structure
POINT *createPoint(int x, int y) {
    POINT *p = malloc(sizeof(POINT));
    p->x = x;
    p->y = y;
    return p;
}

// Function which creates a line using the structure
LINE *createLine(POINT *Point1, POINT *Point2) {
    LINE *line = malloc(sizeof(LINE));
    line->p1 = createPoint(Point1->x, Point1->y);
    line->p2 = createPoint(Point2->x, Point2->y);
    return line;
}

// Function to create a square with 4 lines
SQUARE *createSquare(POINT *p1, POINT *p2, POINT *p3, POINT *p4) {
    SQUARE *square = malloc(sizeof(SQUARE));
    square->l1 = *createLine(p1, p2);
    square->l2 = *createLine(p2, p3);
    square->l3 = *createLine(p3, p4);
    square->l4 = *createLine(p4, p1);
    return square;
}

// Function to print a point
void *printPoint(POINT *p) {
    printf("Point (%d, %d)", p->x, p->y);
}

// Function to print a line
void *printLine(LINE *line) {
    printf("Line from ");
    printPoint(line->p1);
    printf(" to ");
    printPoint(line->p2);
    printf("\n");
}

// Function to print a square
void *printSquare(SQUARE *square) {
    printf("Square with lines:\n");
    printLine(&square->l1);
    printLine(&square->l2);
    printLine(&square->l3);
    printLine(&square->l4);
}