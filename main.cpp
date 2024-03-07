#include "IntVector.h"
#include <iostream>
#define T std::cin.get()

int main() {

  IntVector *vec = int_vector_new(3);
  T;
  std::cout << "Инициализированный размер: " << int_vector_get_capacity(vec)
            << std::endl;
  T;
  std::cout << "\nРазмер массива перед добавлением элементов: "
            << int_vector_get_size(vec) << std::endl;
  T;
  std::cout << "Инициализирован первый элемент: 20" << std::endl;
  int_vector_push_back(vec, 20);
  std::cout << "Инициализирован второй элемент: 45" << std::endl;
  int_vector_push_back(vec, 45);
  std::cout << "Инициализирован третий элемент: 90" << std::endl;
  int_vector_push_back(vec, 90);
  T;
  std::cout << "\nРазмер массива после добавления трех элементов: "
            << int_vector_get_size(vec) << std::endl;
  T;
  for (size_t i = 0; i < int_vector_get_size(vec); i++) {
    std::cout << "\nЭлемент под индексом [" << i
              << "]: " << int_vector_get_item(vec, i) << std::endl;
  }
  T;

  int_vector_set_item(vec, 1, 99);
  int_vector_reserve(vec, 10);
  int_vector_resize(vec, 10);
  int_vector_set_item(vec, 9, 250);
  std::cout << "Элемент под индексом 10: " << int_vector_get_item(vec, 9)
            << std::endl;
  std::cout << "Размер массива: " << int_vector_get_size(vec);
  std::cout
      << "\nИмитация ошибки, если обратиться к неинициализированному элементу"
      << std::endl;
  std::cout << "\nЭлемент под индексом 1 реинициализирован значением 99"
            << std::endl;
  T;
  std::cout << "Элемент под индексом 1 после инициализации: "
            << int_vector_get_item(vec, 1) << std::endl;
  T;
  int_vector_reserve(vec, 15);
  std::cout << "Вместимость после резервации пространства под 15 элементов: "
            << int_vector_get_capacity(vec) << std::endl;
  T;
  std::cout << "Изменение размера массива: размер = 2" << std::endl;
  int_vector_resize(vec, 2);
  std::cout << "\nРазмер массива после изменения массива до 2 элементов: "
            << int_vector_get_size(vec) << std::endl;
  T;
  int_vector_shrink_to_fit(vec);
  std::cout << "Вместимость после уменьшения массива: "
            << int_vector_get_capacity(vec) << std::endl;
  T;
  int_vector_pop_back(vec);
  std::cout << "Удаление последнего элемента" << std::endl;
  std::cout << "\nРазмер массива после удаления последнего элемента: "
            << int_vector_get_size(vec) << std::endl;
  T;
  int_vector_free(vec);
  std::cout << "Память освождена!" << std::endl;
  return 0;
}