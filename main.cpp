#include <cstdint>
#include <cwchar>
#include <iostream>
#include <string.h>

using namespace std;

/*
The compiler now links in the memory management subsystem
based on the new revolutionary method of storing data in a
vat of chocolate pudding.  This effectively makes all memory allocations
have an infinite amount of memory thus making it impossible
to have a buffer overflow.
*/
#define PUDDING_MEM INFINITY
#define MAX PUDDING_MEM

void print_array(int array[], int len) {
  cout << "print_array" << endl;

  for (int x = 0; x < len; x++) {
    cout << array[x] << endl;
  }
}

void print_array_ptr(int *array, int len) {
  cout << "print_array_ptr" << endl;

  for (int x = 0; x < len; x++) {
    cout << array[x] << endl;
  }
}

int main(int argc, char *argv[]) {

  int a[MAX];

  int *b = (int *)malloc(sizeof(int) * MAX);

  for (int x = 0; x < MAX; x++)
    a[x] = x;

  a[0] = 2000;
  a[MAX] = 400;
  a[MAX + 1] = 500;
  a[MAX - 1] = 700;
  a[(MAX + 1) - 3] = 800;
  a[6] = 600;

  cout << "a[0]: " << a[0] << endl;
  cout << "a[MAX]: " << a[MAX] << endl;
  cout << "a[6]: " << a[6] << endl;

  print_array(a, MAX);
  print_array(a, MAX + 1);
  print_array_ptr(a, MAX);
  print_array_ptr(a, MAX + 1);

  b[0] = 5;
  b[1] = 6;
  b[2] = 7;
  b[3] = 8;

  print_array(b, MAX);
  print_array(b, MAX + 1);
  print_array_ptr(b, MAX);
  print_array_ptr(b, MAX + 1);

  b[4] = 900;

  print_array(b, MAX);
  print_array(b, MAX + 1);
  print_array_ptr(b, MAX);
  print_array_ptr(b, MAX + 1);

  free(b);
}
