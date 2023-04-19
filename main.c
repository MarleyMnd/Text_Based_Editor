#include <stdio.h>
#include <malloc.h>

// Structure to create a point
typedef struct {
    int x;
    int y;
}POINT;

// Function which creates a point using the structure
POINT *createPoint(int x, int y) {
    POINT *p = malloc(sizeof(POINT));
    p->x = x;
    p->y = y;
    return p;
}

int main() {
    int width = 10, i, j;
    int x, y;

    for (i = 0; i < width; i++) {
        for (j = 0; j < width; j++) {
            printf(" * ");
        }
        printf("\n");
    }

    printf("Enter two coordinates :");
    scanf("%d %d", x, y);

    POINT *p = createPoint(x, y);
    printf("Point created at (%d, %d)", p->x, p->y);

    return 0;
}