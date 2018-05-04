#include <stdio.h>
#include <stdlib.h>
#include "dvector.h"

#define VECTOR_SIZE 10

int main() {
    dvector* v;

    // Allocate the vector
    v = dvector_alloc(VECTOR_SIZE);

    // Check to make sure that the allocation was successful
    if (!v) {
        printf("ERROR: Failed vector allocation\n");
        return EXIT_FAILURE;
    }

    // Deallocate the vector
    int ret = dvector_dealloc(v);

    // Make sure that the vector is null
    if (ret == EXIT_FAILURE) {
        printf("ERROR: Failed vector deallocation\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
