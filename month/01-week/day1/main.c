// Реализовать динамический массив в C: malloc/realloc,
// при переполнении — увеличить буфер (удвоить), скопировать элементы.
// Интерфейс: создать, push, pop, get по индексу, set по индексу, размер,
// освободить память. Без готовых векторов — только стандартная библиотека C.

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char *buf;
  int len; // кол-во заполненных данных
  int cap; // кол-во доступной памяти
} Array;

int init_array(Array *list) {

  void *res_alloc = calloc(1, sizeof(*list->buf));
  if (!res_alloc) {
    perror("Не удалось выделить память.");
    return 1;
  }

  list->buf = res_alloc;
  list->len = 0;
  list->cap = 1;

  return 0;
}

void mem_alloc(Array *list) {

  if (list->len == list->cap || list->len == 0) {
    int capacity = list->cap * 2;

    char *res = realloc(list->buf, sizeof(list->buf) * capacity);
    if (res) {

      list->buf = res;
      list->cap = capacity;
    } else {
      perror("Неудалось увеличить память буфера");
    }
  }
}

void push(Array *list, char c) {
  if (list->len == list->cap) {
    mem_alloc(list);
  }

  list->buf[list->len] = c;
  list->len += 1;
}

char pop(Array *list) {
  char r = list->buf[list->len - 1];
  list->buf[list->len - 1] = '\0';
  list->len -= 1;
  return r;
}

char get(Array *list, int i) {

  if (!list->buf[i]) {
    perror("Запрашиваемая ячейка не существует");
    return 1;
  }

  return list->buf[i];
}

char set(Array *list, int i, char c) {
  if (list->len == list->cap) {
    mem_alloc(list);
  }

  return list->buf[i] = c;
}

int main(void) {

  Array list;
  init_array(&list);

  mem_alloc(&list);

  push(&list, 'p');

  push(&list, 'u');
  push(&list, 'p');
  push(&list, 's');
  pop(&list);
  push(&list, 'e');
  push(&list, 'j');
  get(&list, 2);

  set(&list, 5, 'a');
  printf("%s\n", list.buf);

  free(list.buf);
  list.buf = NULL;

  return 0;
}
