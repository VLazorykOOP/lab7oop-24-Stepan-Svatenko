#include <iostream>
#include "tasks.h"

using namespace std;

// Задача 1.6. Написати родову функцію у вигляді функції-шаблон. Функція
// міняє місцями два аргументи. Написати специфікацію функції-шаблон
// для типу char*.

template <class T>
void mswap(T& a, T& b) {
  T temp = a;
  a = b;
  b = temp;
}

template <>
void mswap<char*>(char*& a, char*& b) {
  char* temp = a;
  a = b;
  b = temp;
}

void swap_unit() {
  int a = 5, b = 4;
  mswap(a, b);
  cout << "a = " << a << ", b = " << b << endl;
  char* s1 = (char*)"text", * s2 = (char*)"txt";
  mswap(s1, s2);
  cout << "s1 = " << s1 << ", s2 = " << s2 << endl;
}
