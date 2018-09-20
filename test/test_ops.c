#include <stdio.h>
#include <stdlib.h>
#include "dvector.h"


int test_sum(dvector* v) {
    double sum, val;
    int ret = dvector_sum(v, &sum);
    if (ret == EXIT_FAILURE) {
        printf("dvector_sum failed!\n");
        return EXIT_FAILURE;
    }
    printf("Sum of {");
    for (size_t i = 0; i < dvector_size(v); i++) {
        ret = dvector_get(v, i, &val);
        if (ret == EXIT_FAILURE) {
            printf("Failed to retrieve vector element!");
            return EXIT_FAILURE;
        }
        printf("%1.3f, ", val);
    }
    printf("} = %1.4f\n", sum);
    return EXIT_SUCCESS;
}


int test_dot(dvector* v1, dvector* v2) {
    double val;
    int ret;
    printf("Dot product of {");
    for (size_t i = 0; i < dvector_size(v1); i++) {
        ret = dvector_get(v1, i, &val);
        if (ret == EXIT_FAILURE) {
            printf("Failed to retrieve vector element!");
            return EXIT_FAILURE;
        }
        printf("%1.3f, ", val);
    }
    printf("} and {");
    for (size_t i = 0; i < dvector_size(v2); i++) {
        ret = dvector_get(v2, i, &val);
        if (ret == EXIT_FAILURE) {
            printf("Failed to retrieve vector element!");
            return EXIT_FAILURE;
        }
        printf("%1.3f, ", val);
    }
    ret = dvector_dot(v1, v2, &val);
    if (ret == EXIT_FAILURE) {
        printf("Exit failure in dvector_dot!\n");
        return EXIT_FAILURE;
    }
    printf("} = %1.4f\n", val);
    return EXIT_SUCCESS;
}


int main() {
    // Allocate the vectors
    dvector* v1 = dvector_alloc(3);
    dvector* v2 = dvector_alloc(3);

    // Populate the vectors
    dvector_push(v1, 1);
    dvector_push(v1, 2);
    dvector_push(v1, 3);

    dvector_push(v2, 4);
    dvector_push(v2, 5);
    dvector_push(v2, 6);

    // Sum the vectors
    int ret = test_sum(v1);
    if (ret == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }
    ret = test_sum(v2);
    if (ret == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }

    // Dot the vectors
    ret = test_dot(v1, v2);
    if (ret == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }




    // Deallocate the vectors
    dvector_dealloc(v1);
    dvector_dealloc(v2);
    return EXIT_SUCCESS;
}
