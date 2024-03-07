#ifndef INTVECTOR_H
#define INTVECTOR_H

#include <cstddef>

struct IntVector {
  int *data;
  size_t size;
  size_t capacity;
};

IntVector *
int_vector_new(size_t initial_capacity); // Создает новый динамический массив
                                         // IntVector с начальной емкостью//

IntVector *int_vector_copy(
    const IntVector *v); // Создает копию существующего динамического массива//

void int_vector_free(
    IntVector *v); // Освобождает память, занимаемую динамическим массивом//

int int_vector_get_item(const IntVector *v,
                        size_t index); // Получает элемент по индексу из
                                       // динамического массива//

void int_vector_set_item(IntVector *v, size_t index,
                         int item); // Устанавливает значение  по индексу в
                                    // динамическом массиве IntVector//

size_t int_vector_get_size(
    const IntVector *v); // Возвращает текущий размер (количество
                         // элементов) динамического массива//

size_t int_vector_get_capacity(
    const IntVector
        *v); // Возвращает текущую емкость (общее количество элементов, которое
             // может содержать) динамического массива //

int int_vector_push_back(
    IntVector *v,
    int item); // Добавляет элемент в конец динамического массива//

void int_vector_pop_back(
    IntVector *v); // Удаляет последний элемент из динамического массива//

int int_vector_shrink_to_fit(
    IntVector *v); // Уменьшает емкость динамического массива,
                   // чтобы она соответствовала его текущему размеру//

int int_vector_resize(
    IntVector *v,
    size_t new_size); // Изменяет размер динамического массива на
                      // новый размер. При необходимости массив будет
                      // заполнен нулями или обрезан//

int int_vector_reserve(
    IntVector *v,
    size_t new_capacity); // Резервирует память для динамического массива,
                          // чтобы он мог содержать как минимум элементов без
                          // необходимости перевыделения памяти//

#endif
