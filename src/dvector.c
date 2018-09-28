#include <stdio.h>
#include <string.h>
#include <math.h>
#include "dvector.h"

/*Print a dvector*/
void dvector_print(dvector* v) {
    if (v && v->arr && v->size > 0) {
        printf("[");
        for (size_t i = 0; i < v->size; i++) {
            printf("%1.4g, ", v->arr[i]);
        }
        printf("\b\b]\n");
    }
}

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

/*Create a new copy of a vector*/
dvector* dvector_copy(dvector* v) {
    dvector* out = dvector_alloc(v->capacity);
    if (!out) {
        return NULL;
    }

    out->size = v->size;

    if (v->arr) {
        out->arr = memcpy(out->arr, v->arr, v->capacity * sizeof(double));
    }

    return out;
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

/*Get size of vector*/
size_t dvector_size(dvector* v) {
    if (!v) {
        return 0;
    }

    return v->size;
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

/*Set Value*/
int dvector_set(dvector* v, size_t ind, double val) {
    if (!v || !(v->arr) || ind >= v->size) {
        return EXIT_FAILURE;
    }

    v->arr[ind] = val;
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

/*Resize the vector */
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

/*Sum the elements in a vector*/
int dvector_sum(dvector* v, double* sum) {
    size_t i;
    *sum = 0;

    if (!v || !(v->arr)) {
        return EXIT_FAILURE;
    }

    for(i = 0; i < v->size; i++) {
        *sum += v->arr[i];
    }

    return EXIT_SUCCESS;
}

/*Dot product between two vectors*/
int dvector_dot(dvector* v1, dvector* v2, double* out) {
    if (!v1 || !v2 || !(v1->arr) || !(v2->arr) || v1->size != v2->size) {
        return EXIT_FAILURE;
    }

    double dot = 0;
    for (size_t i = 0; i < v1->size; i++) {
        dot += v1->arr[i] * v2->arr[i];
    }

    *out = dot;

    return  EXIT_SUCCESS;
}

/*Add two vectors*/
int dvector_add(dvector* v1, dvector* v2) {
    if (!v1 || !v2 || !(v1->arr) || !(v2->arr) || v1->size != v2->size) {
        return EXIT_FAILURE;
    }

    for (size_t i = 0; i < v1->size; i++) {
        v1->arr[i] += v2->arr[i];
    }

    return EXIT_SUCCESS;
}

/*Take the norm of a vector */
int dvector_norm(dvector* v, double* out) {
    if (!v) {
        *out = 0;
        return EXIT_FAILURE;
    }

    *out = 0;

    if ((v->arr) && v->size != 0) {
        for (size_t i = 0; i < v->size; i++) {
            *out += v->arr[i] * v->arr[i];
        }
        *out = sqrt(*out);
    }

    return EXIT_SUCCESS;
}

/* Get the minimum of a vector */
int dvector_min(dvector* v, double* out) {
    if (!v || !(v->arr)) {
        return EXIT_FAILURE;
    }

    if (v->size == 0) {
        return EXIT_FAILURE;
    } else {
        *out = v->arr[0];
    }

    for(size_t i = 1; i < v->size; i++) {
        if (*out > v->arr[i]) {
            *out = v->arr[i];
        }
    }
    return EXIT_SUCCESS;
}    

/* Get the maximum element in a vector */
int dvector_max(dvector* v, double* out) {
    if (!v || !(v->arr)) {
        return EXIT_FAILURE;
    }

    if (v->size == 0) {
        return EXIT_FAILURE;
    } else {
        *out = v->arr[0];
    }

    for (size_t i = 1; i < v->size; i++) {
        if (*out < v->arr[i]) {
            *out = v->arr[i];
        }
    }
    return EXIT_SUCCESS;
}
