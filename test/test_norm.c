#include <stdio.h>
#include <stdlib.h>
#include "dvector.h"

#define CHECK_RETURN(x) if(x == EXIT_FAILURE) {return EXIT_FAILURE;}

int main() {
    int ret;
    double  res;
    dvector* v = dvector_alloc(3);
    dvector_push(v, 0);
    dvector_push(v, 3);
    dvector_push(v, 4);

    ret = dvector_norm(v, &res);
    CHECK_RETURN(ret);
    printf("Norm = %1.5f\n", res);

    dvector_dealloc(v);
    return EXIT_SUCCESS;
}
