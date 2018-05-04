#include "dvector.h"

/*Allocate a new dvector
  If 0 is passed as the length, then use default initial size
*/
dvector* dvector_alloc(size_t n) {
    // Make sure that n is valid
    if (n < 0) { // Negative length...
        return NULL;
    } else if (n == 0) {    // Use default initial size
        n = DEFAULT_INITIAL_SIZE;
    }

    // Allocate structure
    dvector* ret = malloc(sizeof(*ret));

    // Check allocation
    if (!ret) {
        return NULL;
    }

    // set the capacity and size
    ret->capacity = n;
    ret->size = 0;

    // Allocate the array
    ret->arr = calloc(n, sizeof(double));

    // Check allocation
    if (!(ret->arr)) {
        free(ret);
        return NULL;
    }

    return ret;
}

/*Deallocate an existing dvector*/
int dvector_dealloc(dvector* v) {
    if (!v) { // Null vector passed in, don't do anything
        return EXIT_SUCCESS;
    }

    // Only free arr if not null
    if (v->arr) {
        free(v->arr);
    }

    free(v);
    return EXIT_SUCCESS;
}

/*Push value onto the end*/
int dvector_push(dvector* v, double val) {
    if (!(v)) {
        return EXIT_FAILURE;
    }

    // Determine if we need to resize
    if (v->capacity == v->size) {
        int ret = dvector_resize(v, RESIZE_MULTIPLIER*(v->capacity));
        if (ret == EXIT_FAILURE) {
            return EXIT_FAILURE;
        }
    }

    // Put the value in the right spot
    v->arr[v->size] = val;
    v->size = v->size + 1;

    return EXIT_SUCCESS;
}

/*Get value*/
int dvector_get(dvector* v, size_t ind, double* ret) {
    if (!v || !(v->arr)) {
        return EXIT_FAILURE;
    } else if (ind >= v->size) {
        return EXIT_FAILURE;
    }

    *ret = v->arr[ind];
}

/* Resize the vector */
int dvector_resize(dvector* v, size_t new_cap) {
    if (!v) {
        return EXIT_FAILURE;
    } else if (!(v->arr)) {
        v->arr = calloc(new_cap, sizeof(double));
        if (!(v->arr)) {
            return EXIT_FAILURE;
        }
    }

    // Reallocate with new size
    double* new_arr = realloc(v->arr, new_cap);
    if (!(new_arr)) {
        return EXIT_FAILURE;
    }

    v->arr = new_arr;
}
