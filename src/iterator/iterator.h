#ifndef _ITERATOR_H_
#define _ITERATOR_H_

typedef struct Iterator {
    void * context;
    void* (*next)(struct Iterator*);
    size_t index;
} Iterator;


#define iterator_next(T) ((T)->next((T)))


#define iterate(it, type, var, block) \
    do { \
        for(type var = iterator_next((it)); var != NULL; var = iterator_next((it))) \
            block \
    } while(0)


#endif

