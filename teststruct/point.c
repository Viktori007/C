#include <stdio.h>
#include <stdlib.h>

struct point {
    float x, y;
    float (*dist) (const struct point p1, const struct point p2);
};

float distFunc(const struct point p1, const struct point p2) { return pow((pow((p1.x - p2.x),2) + pow((p1.y - p2.y),2)),0.5) }

void *unitInit()
{
  struct point *ptr = (struct point*) malloc(sizeof(struct point));
  ptr->dist = &distFunc;
  return ptr;
}

int main(int argc, char **argv)
{
    struct point *U = unitInit();
    U->x = 2;
    U->y = 3;
    struct point *U1 = unitInit();
    U1->x = 2;
    U1->y = 5;

    float res;
    res = U->dist(U, U1);
    printf("Result is %f\n", res);

    free(U);

  return 0;
}
