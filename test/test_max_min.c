#include <stdio.h>
#include <stdlib.h>
#include "dvector.h"

#define CHECK_RETURN(x) if(x == EXIT_FAILURE) {return EXIT_FAILURE;}

int main() {
    int ret;
    double  res;
    dvector* v = dvector_alloc(3);
    dvector_push(v, 1);
    dvector_push(v, 2);
    dvector_push(v, 3);

    ret = dvector_max(v, &res);
    CHECK_RETURN(ret);
    printf("Maximum = %1.5f\n", res);

    ret = dvector_min(v, &res);
    CHECK_RETURN(ret);
    printf("Minimum = %1.5f\n", res);

    dvector_dealloc(v);
    return EXIT_SUCCESS;
}
