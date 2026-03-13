sjarray - simple generic macro-based header for safe, encapsulated arrays
=====
This is a small header-only library designed to assist with creating
bounds-checked, encapsulated, fixed-size arrays in C with minimal code
repetition. At the moment, it's a fairly simple and straightforward
implementation that provides the minimum required functionality.

Example usage is as follows:

```c
// Creates a type called Arr_int64_t and all associated functions
DefineArray(int64_t);

// Creates a new array of 10 elements called "my_array"
CreateArray(int64_t, my_array, 10);

// Returns the value of index 5 from my_array, similar to `my_array[5];`
int64_t_ArrGet(my_array, 5);

// Sets the value of index 5 of my_array, similar to `my_array[5] = 256;`
int64_t_ArrSet(my_array, 5, 256);
```

It may be recommended to add your `DefineArray()`s to the header itself, to
prevent redeclarations that may bloat your executable.

There is a demonstrable performance impact for this type of bounds checking
(around 1.3x~1.5x,) so there is a non-insignificant trade-off for this type of
safety. Of course, the compiler is just as likely to optimize the performance
impact out depending on your use case.

As of now, the header simply `abort()`s on an out-of-bounds error, for lack of a
more robust error handling system, and with the belief that "Crash Early" is an
ideal philosophy. However, the error behavior is in its own function and can be
easily modified.
