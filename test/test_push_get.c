#include <stdio.h>
#include <stdlib.h>
#include "dvector.h"

void check_return(int ret, const char * str) {
    if (ret == EXIT_FAILURE){
        printf("%s\n", str);
        exit(EXIT_FAILURE);
    }
}


int main() {
    dvector* v;
    int ret;
    double values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Allocate the vector
    v = dvector_alloc(5);

    // Check to make sure that the allocation was successful
    if (!v) {
        printf("ERROR: Failed vector allocation\n");
        return EXIT_FAILURE;
    }

    // Push values on to the back
    for(size_t i = 0; i < 10; i++) {
        ret = dvector_push(v, -1);
        check_return(ret, "Failed vector push");
        ret = dvector_set(v, i, values[i]*.13);
        check_return(ret, "Failed vector set");
    }
    dvector_print(v);
    dvector* v2 = dvector_copy(v);
    dvector_print(v2);

    // Get and print
    double out;
    for (size_t i = 0; i < 10; i++) {
        ret = dvector_get(v, i, &out);
        check_return(ret, "Failed vector get");
    }

    // Print sum
    double sum = 0;
    ret = dvector_sum(v, &sum);
    check_return(ret, "Failed vector sum");
    printf("Sum = %f\n", sum);

    // Print self dot
    double n_squared = 0;
    ret = dvector_dot(v, v, &n_squared);
    check_return(ret, "Failed vector dot.");
    printf("Norm Squared = %f\n", n_squared);

    // Deallocate the vector
    ret = dvector_dealloc(v);
    check_return(ret, "Failed vector deallocate");
    ret = dvector_dealloc(v2);
    check_return(ret, "Failed vector deallocate");

    return EXIT_SUCCESS;
}
