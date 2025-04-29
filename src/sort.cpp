#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstring>

using namespace std;

// Задача 2.1. Написати функцію-шаблон функцію впорядкування методом
// швидкого впорядкування. Написати специфікацію функції-шаблон для
// типу char*

template <class T>
void sort(T* arr, int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        T temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}
template<> void sort<char*>(char** arr, int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (strcmp(arr[j], arr[j+1])>0) {
        char* temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

}
template <class T>
void print(T* arr, int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void sort_unit(){
  int l_int[] = {1,2,3,4,6,5};
  sort(l_int, 6);
  print(l_int, 6);
  char* l_char[] = {"a","b","c","d","e","f"};
  sort(l_char, 6);
  print(l_char, 6);

}

