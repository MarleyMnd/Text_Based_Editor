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
    printf("3. Create a square\n");
    printf("10. Exit\n");

    int option;
    printf("Enter your choice:");
    scanf("%d", &option);

    switch(option) {
        case 1:
            printf("Enter two coordinates (format: \033[0;31mA B\033[0;0m):");
            scanf("%d %d", &x, &y);
            POINT *p = createPoint(x, y);

            printPoint(p);
            break;
        case 2:
            printf("Enter two coordinates for point 1 (format: \033[0;31mA B\033[0;0m):");
            scanf("%d %d", &x, &y);
            POINT *p1 = createPoint(x, y);

            printf("Enter two coordinates for point 2 (format: \033[0;31mA B\033[0;0m):");
            scanf("%d %d", &x, &y);
            POINT *p2 = createPoint(x, y);

            LINE *l = createLine(p1, p2);

            printLine(l);
            break;
        case 3:
            printf("Enter two coordinates for point 1 (format: \033[0;31mA B\033[0;0m):");
            scanf("%d %d", &x, &y);
            POINT *p3 = createPoint(x, y);

            printf("Enter two coordinates for point 2 (format: \033[0;31mA B\033[0;0m):");
            scanf("%d %d", &x, &y);
            POINT *p4 = createPoint(x, y);

            printf("Enter two coordinates for point 3 (format: \033[0;31mA B\033[0;0m):");
            scanf("%d %d", &x, &y);
            POINT *p5 = createPoint(x, y);

            printf("Enter two coordinates for point 4 (format: \033[0;31mA B\033[0;0m):");
            scanf("%d %d", &x, &y);
            POINT *p6 = createPoint(x, y);

            SQUARE *s = createSquare(p3, p4, p5, p6);

            printSquare(s);
            break;
        case 10:
            printf("Exiting...");
            break;
        default:
            printf("Invalid option");
    }
    return 0;
}