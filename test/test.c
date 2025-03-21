#include <stdio.h>
#include <stdlib.h>
#include "../src/iterator/iterator.h"


typedef struct {
    size_t size;
    int *arr;
} Vector;


static void * vector_next(Iterator * it) {
    if(it->index < ((Vector*) it->context)->size) {
        return &((Vector*) it->context)->arr[it->index];
    } else {
        return NULL;
    }
}


Vector vector(size_t size, int * arr) {
    return (Vector) {
        .size = size
        , .arr = arr
    };
}


Iterator vector_iterator(Vector * self) {
    return (Iterator) {
        .context = self
        , .next = vector_next
    };
}


int main(void) {
    int arr[] = {0, 1, 2, 4, 8, 16, 32, 64, 128, 256};
    Vector v = vector(sizeof(arr)/sizeof(*arr), arr);

    iterate(vector_iterator(&v), int*, i, {
        printf("%ld - %d\n", iterator.index, *i);
    });

    printf("Program exit..\n");
    return EXIT_SUCCESS;
}


