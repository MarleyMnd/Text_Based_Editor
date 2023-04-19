//
// Created by Marley on 19/04/2023.
//

#include <stdio.h>
#include "functions.h"


int main() {
    int x, y;

    printf("Choose an option:\n");
    printf("1. Create a point\n");
    printf("2. Create a line\n");
    printf("3. Exit\n");

    int option;
    printf("Enter your choice:");
    scanf("%d", &option);

    switch(option) {
        case 1:
            printf("Enter two coordinates :");
            scanf("%d %d", x, y);
            POINT *p = createPoint(x, y);
            printf("Point created at (%d, %d)", p->x, p->y);
            break;
        case 2:
            printf("Enter two coordinates for point 1:");
            scanf("%d %d", x, y);
            POINT *p1 = createPoint(x, y);
            printf("Enter two coordinates for point 2:");
            scanf("%d %d", x, y);
            POINT *p2 = createPoint(x, y);
            LINE *l = createLine(p1, p2);
            printf("Line created between (%d, %d) and (%d, %d)", l->p1->x, l->p1->y, l->p2->x, l->p2->y);
            break;
        case 3:
            break;
        default:
            printf("Invalid option");
    }
    return 0;
}