//
// Created by Marley on 19/04/2023.
//
#include <stdio.h>
#include <malloc.h>

unsigned int global_id = 0;
unsigned char list = 0;

unsigned int get_next_id();

typedef struct {
    int pos_x;
    int pos_y;
} Point;

typedef struct {
    Point *p1;
    Point *p2;
} Line;

typedef struct {
    Point *p;
    double radius;
} Circle;

typedef struct {
    Point *p;
    int i;
} Square;

typedef struct {
    Point *p;
    int width;
    int height;
} Rectangle;

typedef struct {
    int num_points;
    Point *points;
} Polygon;

typedef enum {
    POINT, LINE, SQUARE, RECTANGLE, CIRCLE, POLYGON
} SHAPE_TYPE;


typedef struct shape {
    int id;
    SHAPE_TYPE shape_type;
    void *ptrShape;
} Shape;

//typedef struct {
//    Shape data;
//    struct node *next;
//}NODE;
//
//
//void add_list(Point *p) {
//    NODE *new_node = malloc(sizeof(NODE));
//    new_node->data = p;
//    new_node->next = list;
//    list = new_node;
//
//    if (list == NULL) {
//        list = new_node;
//    } else {
//        NODE *current = list;
//        while (current->next != NULL) {
//            current = current->next;
//        }
//        current->next = new_node;
//    }
//}
//
//void print_list(NODE *head) {
//    NODE *current = head;
//    while (current != NULL) {
//        printf("%d\n", current->data);
//        current = current->next;
//    }
//}

Point *create_point(int px, int py) {
    Point *p = malloc(sizeof(Point));
    p->pos_x = px;
    p->pos_y = py;

    // add_list(p);

    return p;
}

Line *create_line(Point *p1, Point *p2) {
    Line *line = malloc(sizeof(Line));
    line->p1 = create_point(p1->pos_x, p1->pos_y);
    line->p2 = create_point(p2->pos_x, p2->pos_y);

    // add_list(line);

    get_next_id();

    return line;
}

Circle *create_circle(Point *point, double radius) {
    Circle *circle = malloc(sizeof(Circle));
    circle->p = create_point(point->pos_x, point->pos_y);
    circle->radius = radius;

    // add_list(circle);

    get_next_id();
    return circle;
}

Square *create_square(Point *point, int length) {
    Square *square = malloc(sizeof(Square));
    square->p = create_point(point->pos_x, point->pos_y);
    square->i = length;

    // add_list(square);

    get_next_id();

    return square;
}

Rectangle *create_rectangle(Point *point, int width, int height) {
    Rectangle *rectangle = malloc(sizeof(Rectangle));
    rectangle->p = create_point(point->pos_x, point->pos_y);
    rectangle->width = width;
    rectangle->height = height;

    // add_list(rectangle);

    get_next_id();

    return rectangle;
}

Polygon *create_polygon(int num_points, Point *points) {
    Polygon *polygon = malloc(sizeof(Polygon));
    polygon->num_points = num_points;
    polygon->points = malloc(num_points * sizeof(Point));
    for (int i = 0; i < num_points; i++) {
        polygon->points[i].pos_x = points[i].pos_x;
        polygon->points[i].pos_y = points[i].pos_y;
    }

    // add_list(polygon);

    get_next_id();

    return polygon;
}


void print_point(Point *p) {
    printf("POINT[p(%d,%d)]", p->pos_x, p->pos_y);
}


void print_line(Line *line) {
    printf("Line start:[%d,%d] end:[%d,%d]", line->p1->pos_x, line->p1->pos_y, line->p2->pos_x, line->p2->pos_y);
}

void print_circle(Circle *circle) {
    printf("Circle of center (%d,%d) and radius %f", circle->p->pos_x, circle->p->pos_y, circle->radius);
}

void print_square(Square *square) {
    printf("Square (%d, %d) of length (%d)", square->p->pos_x, square->p->pos_y, square->i);
}

void print_rect(Rectangle *rectangle) {
    printf("Rectangle (%d,%d) of height %d and width %d", rectangle->p->pos_x, rectangle->p->pos_y, rectangle->height,
           rectangle->width);
}

void print_polygon(Polygon *poly) {
    printf("Polygon with %d points:\n", poly->num_points);
    for (int i = 0; i < poly->num_points; i++) {
        printf("Point %d: (%d, %d)\n", i + 1, poly->points[i].pos_x, poly->points[i].pos_y);
    }
}

void delete_line(Line *line) {
    free(line);
}

void delete_point(Point *point) {
    free(point);
}

void delete_circle(Circle *circle) {
    free(circle);
}

void delete_square(Square *square) {
    free(square);
}

void delete_rect(Rectangle *rectangle) {
    free(rectangle);
}

void delete_polygon(Polygon *polygon) {
    free(polygon);
}

Shape *create_empty_shape(SHAPE_TYPE shape_type) {
    Shape *shp = (Shape *) malloc(sizeof(Shape));
    shp->ptrShape = NULL;
    shp->id = 1;
    shp->shape_type = shape_type;
    return shp;
}

Shape *create_point_shape(int px, int py) {
    Shape *shp = create_empty_shape(POINT);
    Point *p = create_point(px, py);
    shp->ptrShape = p;
    return shp;
}

Shape *create_line_shape(int px1, int py1, int px2, int py2) {
    Shape *shp = create_empty_shape(LINE);
    Point *p1 = create_point(px1, py1);
    Point *p2 = create_point(px2, py2);
    Line *p = create_line(p1, p2);
    shp->ptrShape = p;
    return shp;
}

Shape *create_square_shape(int px, int py, int length) {
    Shape *shp = create_empty_shape(SQUARE);
    Point *p = create_point(px, py);
    Square *square = create_square(p, length);
    shp->ptrShape = square;
    return shp;
}

Shape *create_rectangle_shape(int px, int py, int width, int height) {
    Shape *shp = create_empty_shape(RECTANGLE);
    Point *p = create_point(px, py);
    Rectangle *rectangle = create_rectangle(p, width, height);
    shp->ptrShape = rectangle;
    return shp;
}

unsigned int get_next_id() {
    return ++global_id;
}

Shape *create_polygon_shape(int lst[], int n) {

}