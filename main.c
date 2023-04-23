//
// Created by Marley on 19/04/2023.
//

#include <stdio.h>
#include <malloc.h>
#include "functions.h"


int main() {
    char choice1;
    int choice2;
    printf("Please select an action:\n"
           "A- Add a shape\n"
           "B- Display the list of shapes\n"
           "C- Delete a shape\n"
           "D- Drawing the shapes\n"
           "E- Help\n");
    scanf("%c", &choice1);
    if (choice1 == 'A') {
        printf("Please select an action:\n"
               "1- Add a point\n"
               "2- Add a line\n"
               "3- Add circle\n"
               "4- Add a square\n"
               "5- Add a rectangle\n"
               "6- Add a polygon\n"
               "7- Return to previous menu\n");
        scanf("%d", &choice2);
        if (choice2 == 1) {
            int x, y;
            printf("Give the coordinates in the form \033[0;31mx y\033[0;0m");
            scanf("%d %d", &x, &y);
            Point *Point1 = create_point(x, y);
            print_point(Point1);

            printf("\nglobal_id = %d");
        }
        if (choice2 == 2) {
            int x1, y1, x2, y2;

            printf("Enter the \033[0;31mx\033[0;0m and \033[0;31my\033[0;0m coordinates for the starting point:\n");
            scanf("%d %d", &x1, &y1);
            Point *p1 = create_point(x1, y1);

            printf("Enter the \033[0;31mx\033[0;0m and \033[0;31my\033[0;0m coordinates for the ending point:\n");
            scanf("%d %d", &x2, &y2);
            Point *p2 = create_point(x2, y2);

            Line *line = create_line(p1, p2);
            print_line(line);

            printf("\nglobal_id = %d");
        }
        if (choice2 == 3) {
            int x5, y5;
            double rad;
            printf("Enter the \033[0;31mx\033[0;0m and \033[0;31my\033[0;0m coordinates for the center of your circle:\n");
            scanf("%d %d", &x5, &y5);

            printf("Now choose a radius for your circle:\n");
            scanf("%lf", &rad);

            Point *point = create_point(x5, y5);
            Circle *circle = create_circle(point, rad);
            print_circle(circle);

            printf("\nglobal_id = %d");
        }
        if (choice2 == 4) {
            int x3, y3, length;

            printf("Enter the \033[0;31mx\033[0;0m and \033[0;31my\033[0;0m coordinates of your top left point:\n");
            scanf("%d %d", &x3, &y3);

            printf("Now enter the length of the square\n ");
            scanf("%d", &length);

            Point *point = create_point(x3, y3);
            Square *square = create_square(point, length);
            print_square(square);

            printf("\nglobal_id = %d");
        }
        if (choice2 == 5) {
            int x4, y4, height, width;
            printf("Enter the \033[0;31mx\033[0;0m and \033[0;31my\033[0;0m coordinates of your top left point:\n");
            scanf("%d %d", &x4, &y4);

            printf("Now enter the width of the square\n");
            scanf("%d", &width);

            printf("Now enter the height of the square\n");
            scanf("%d", &height);

            Point *point = create_point(x4, y4);
            Rectangle *rectangle = create_rectangle(point, width, height);
            print_rect(rectangle);

            printf("\nglobal_id = %d");
        }
        if (choice2 == 6) {
            int numb;
            printf("Enter the number of points in the polygon: ");
            scanf("%d", &numb);

            Point *points = malloc(numb * sizeof(Point));
            for (int i = 0; i < numb; i++) {
                int x, y;
                printf("Enter the \033[0;31mx\033[0;0m and \033[0;31my\033[0;0m coordinates of point %d: ", i + 1);
                scanf("%d %d", &x, &y);
                points[i] = *create_point(x, y);
            }
            Polygon *polygon = create_polygon(numb, points);
            print_polygon(polygon);

            printf("\nglobal_id = %d");
        }
    } else if (choice1 == 'B') {
        printf("List of the created shapes:\n");
        //print_list(list);
    }

    return 0;
}

