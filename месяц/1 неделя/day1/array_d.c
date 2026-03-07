// Реализовать динамический массив в C: malloc/realloc,
// при переполнении — увеличить буфер (удвоить), скопировать элементы.
// Интерфейс: создать, push, pop, get по индексу, set по индексу, размер,
// освободить память. Без готовых векторов — только стандартная библиотека C.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *arr;
  int len; // кол-заполненых данных
  int cap;
} DynamicArray;

static inline char get_element(DynamicArray *self, int index) {
  if (index > self->len) {
    printf("Ошибка, такого элемента не существует %d\n", index);
  }
  return self->arr[index];
}

static inline int mem_allocate(DynamicArray *self) {

  if (self->len == self->cap) {
    size_t capacity = self->len * 2;

    void *res = realloc(self->arr, capacity);
    if (!res) {
      free(res);
      return 1;
    }

    self->arr = res;
  }

  return 0;
}

static inline int set_element(DynamicArray *self, char c, int index) {

  int res_mem = mem_allocate(self);
  if (res_mem == 0 && index <= self->cap) {
    self->arr[index] = c;
    self->len += 1;
  } else {
    return 1;
  }

  return 0;
}

static inline int push_element(DynamicArray *self, char c) {

  int res_mem = mem_allocate(self);
  if (res_mem == 0) {
    self->arr[self->len] = c;
    self->len += 1;
  } else {
    return 1;
  }

  return 0;
}

static inline void pop_element(DynamicArray *self) {
  if (self->len > 0) {
    self->len -= 1;
    self->arr[self->len] = '\n';
  }
}

int main(void) {

  DynamicArray realeseData;

  realeseData.arr = malloc(sizeof(char) * 1);
  if (realeseData.arr == NULL) {
    return 1;
  }

  // инициализировали данные
  realeseData.len = 1;
  realeseData.cap = 1;
  realeseData.arr[0] = 'c';

  set_element(&realeseData, 's', 1);
  push_element(&realeseData, 'w');
  pop_element(&realeseData);

  printf("%s ------ \n", realeseData.arr);

  free(realeseData.arr);
  return 0;
}
