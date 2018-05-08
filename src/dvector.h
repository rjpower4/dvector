#ifndef DVECTOR_H
#define DVECTOR_H

#include <stdlib.h>

#define DEFAULT_INITIAL_SIZE 10
#define RESIZE_MULTIPLIER 2

/* Definition of dvector struct */
typedef struct DVECTOR {
    size_t capacity;
    size_t size;
    double* arr;
} dvector;

/*Print a dvector*/
void dvector_print(dvector* v);

/*Allocate a new dvector*/
dvector* dvector_alloc(size_t n);

/*Deallocate an existing dvector*/
int dvector_dealloc(dvector* v);

/*Create a new copy of a vector*/
dvector* dvector_copy(dvector* v);

/*Get size of vector*/
size_t dvector_size(dvector* v);

/*Push value onto the end*/
int dvector_push(dvector* v, double val);

/*Set Value*/
int dvector_set(dvector* v, size_t ind, double val);

/*Get value*/
int dvector_get(dvector* v, size_t ind, double* ret);

/*Resize the vector*/
int dvector_resize(dvector* v, size_t new_cap);

/*Sum the elements in a vector*/
int dvector_sum(dvector* v, double* sum);

/*Dot product between two vectors*/
int dvector_dot(dvector* v1, dvector* v2, double* out);

/*Add two vectors -- puts result in v1*/
int dvector_add(dvector* v1, dvector* v2, double* out);

#endif
