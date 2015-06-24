/**
 * Demo of opaque-type oriented programming in C
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

typedef struct dynarray {
    float *pdata;
    size_t size;
    size_t capacity;
} dynarray;


void dynarray_init(dynarray *parray, size_t capacity)
{
    parray->pdata = malloc(capacity * sizeof(float));
    parray->capacity = capacity;
    parray->size = 0;
}

void dynarray_add(dynarray *parray, float elem)
{
    if (parray->size + 1 > parray->capacity) {
        parray->pdata = realloc(parray->pdata, (parray->capacity + 10) * sizeof(float));
        assert(parray->pdata);
        parray->capacity += 10;
    }

    parray->pdata[parray->size++] = elem;
}


