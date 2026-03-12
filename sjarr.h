#pragma once

#include <stdio.h>
#include <stdlib.h>

#define DefineArray(type)                                               \
  typedef struct {                                                      \
    size_t length;                                                      \
    type* data;                                                         \
  } Arr_##type;                                                         \
                                                                        \
  static void type##_ArrErrorOut() {                                    \
    fprintf(stderr, "ERROR: Index out of range!\n");                    \
    abort();                                                            \
  }                                                                     \
                                                                        \
  static type type##_ArrGet(const Arr_##type arr, size_t index) {       \
    if (index < arr.length) {                                           \
      return arr.data[index];                                           \
    } else {                                                            \
      type##_ArrErrorOut();                                             \
      return 0; /* never called */                                      \
    }                                                                   \
  }                                                                     \
                                                                        \
  static void type##_ArrSet(Arr_##type arr, size_t index, type value) { \
    if (index < arr.length) {                                           \
      arr.data[index] = value;                                          \
    } else {                                                            \
      type##_ArrErrorOut();                                             \
    }                                                                   \
  }

#define CreateArray(type, name, size) \
  type _raw_##name[size];             \
  Arr_##type name = {.length = size, .data = _raw_##name};
