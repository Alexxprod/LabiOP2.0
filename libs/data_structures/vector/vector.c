#include <malloc.h>
#include "vector.h"
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

vector createVector(size_t n) {
    if (n > SIZE_MAX) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    int *data = (int *) malloc(sizeof(int) * n);
    return (vector) {data, 0, n};
}



void reserve(vector *v, size_t newCapacity) {
    if (newCapacity > SIZE_MAX) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    realloc(v->data, sizeof(int) * newCapacity);

    if (newCapacity < v->size) {
        v->size = newCapacity;
    }
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    v->size = v->capacity;
}

void deleteVector(vector *v) {
    free(v->data);
}

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity;;
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void pushBack(vector *v, int x) {
    if (v->capacity == 0) {
        v->capacity++;
    }

    if (v->size < v->capacity) {
        v->data[v->size++] = x;
    } else {
        reserve(v, v->capacity * 2);
        v->data[v->size++] = x;
    }
}

void popBack(vector *v) {
    if (v->size == 0) {
        fprintf(stderr, "empty vector");
        exit(1);
    }

    v->size--;
}

int *atVector(vector *v, size_t index) {
    if (index >= v->size) {
        fprintf(stderr, "IndexError: a[index] is not exists");
        exit(1);
    }

    return (int *) &v->data[index];
}

int *back(vector *v) {
    return (int *) &v->data[v->size - 1];
}

int *front(vector *v) {
    return (int *) &v->data[0];
}

