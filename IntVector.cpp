#include "IntVector.h"
#include <stdexcept>

IntVector *int_vector_new(size_t initial_capacity) {
  IntVector *vec = new IntVector;
  vec->size = 0;
  vec->capacity = initial_capacity;
  vec->data = new int[initial_capacity];
  return vec;
}

IntVector *int_vector_copy(const IntVector *v) {
  IntVector *copied_vec = new IntVector;
  copied_vec->size = v->size;
  copied_vec->capacity = v->capacity;
  copied_vec->data = new int[v->capacity];

  for (size_t i = 0; i < v->size; i++) {
    copied_vec->data[i] = v->data[i];
  }

  return copied_vec;
}

void int_vector_free(IntVector *v) {
  delete[] v->data;
  delete v;
}

int int_vector_get_item(const IntVector *v, size_t index) {
  if (index < v->size) {
    return v->data[index];
  } else {
    throw std::out_of_range("Index out of bounds");
  }
}

void int_vector_set_item(IntVector *v, size_t index, int item) {
  if (index < v->size) {
    v->data[index] = item;
  } else {
    throw std::out_of_range("Index out of bounds");
  }
}

size_t int_vector_get_size(const IntVector *v) { return v->size; }

size_t int_vector_get_capacity(const IntVector *v) { return v->capacity; }

int int_vector_push_back(IntVector *v, int item) {
  if (v->size == v->capacity) {
    size_t new_capacity = v->capacity * 2;
    int *new_data = new int[new_capacity];

    for (size_t i = 0; i < v->size; i++) {
      new_data[i] = v->data[i];
    }

    delete[] v->data;
    v->data = new_data;
    v->capacity = new_capacity;
  }

  v->data[v->size] = item;
  v->size++;

  return 0;
}

void int_vector_pop_back(IntVector *v) {
  if (v->size > 0) {
    v->size--;
  }
}

int int_vector_shrink_to_fit(IntVector *v) {
  if (v->capacity > v->size) {
    int *new_data = new int[v->size];

    for (size_t i = 0; i < v->size; i++) {
      new_data[i] = v->data[i];
    }

    delete[] v->data;
    v->data = new_data;
    v->capacity = v->size;
    return 0;
  } else {
    return -1;
  }
}

int int_vector_resize(IntVector *v, size_t new_size) {
  if (new_size > v->capacity) {
    size_t new_capacity = new_size * 2;
    int *new_data = new int[new_capacity];

    for (size_t i = 0; i < v->size; i++) {
      new_data[i] = v->data[i];
    }

    delete[] v->data;
    v->data = new_data;
    v->capacity = new_capacity;
  }

  v->size = new_size;
  return 0;
}

int int_vector_reserve(IntVector *v, size_t new_capacity) {
  if (new_capacity > v->capacity) {
    int *new_data = new int[new_capacity];

    for (size_t i = 0; i < v->size; i++) {
      new_data[i] = v->data[i];
    }

    delete[] v->data;
    v->data = new_data;
    v->capacity = new_capacity;
    return 0;
  } else {
    return -1;
  }
}