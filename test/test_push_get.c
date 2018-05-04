#include <stdio.h>
#include <stdlib.h>
#include "dvector.h"


int main() {
    dvector* v;
    double values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Allocate the vector
    v = dvector_alloc(0);

    // Check to make sure that the allocation was successful
    if (!v) {
        printf("ERROR: Failed vector allocation\n");
        return EXIT_FAILURE;
    }

    // Push values on to the back
    for(int i = 0; i < 10; i++) {
        int ret = dvector_push(v, values[i]);
        if (ret == EXIT_FAILURE) {
            printf("ERROR: Failed vector push.\n");
            return EXIT_FAILURE;
        }
    }

    // Get and print
    double out;
    for (int i = 0; i < 10; i++) {
        int ret = dvector_get(v, i, &out);
        if (ret == EXIT_FAILURE) {
            printf("ERROR: Failed vector get.");
            return EXIT_FAILURE;
        }
        printf("%d: %1.0f (%1.0f)\n", i, out, values[i]);
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
