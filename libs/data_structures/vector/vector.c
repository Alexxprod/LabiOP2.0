#include <malloc.h>
#include <stdio.h>
#include <limits.h>


typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

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

int main() {

    vector v = createVector(SIZE_MAX);

    return 0;
}
