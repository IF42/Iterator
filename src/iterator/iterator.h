#ifndef _ITERATOR_H_
#define _ITERATOR_H_

typedef struct Iterator {
    void * context;
    void* (*next)(struct Iterator*);
    size_t index;
} Iterator;


#define iterator_next(T) ((T)->next((T)))


#define iterate(it_expr, type, var, block) \
    do { \
        Iterator iterator = (it_expr); \
        for(type var = iterator_next(&iterator); var != NULL; iterator.index++, var = iterator_next(&iterator)) \
            block \
    } while(0)


#endif

