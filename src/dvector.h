#ifndef DVECTOR_H
#define DVECTOR_H

#include <stdlib.h>

#define DEFAULT_INITIAL_SIZE 10
#define RESIZE_MULTIPLIER 2.5

/* Definition of dvector struct */
typedef struct DVECTOR {
    size_t capacity;
    size_t size;
    double* arr;
} dvector;

/*Allocate a new dvector*/
dvector* dvector_alloc(size_t n);

/*Deallocate an existing dvector*/
int dvector_dealloc(dvector* v);

/*Push value onto the end*/
int dvector_push(dvector* v, double val);

/*Get value*/
int dvector_get(dvector* v, size_t ind, double* ret);

/*Resize the vector*/
int dvector_resize(dvector* v, size_t new_cap);


#endif
