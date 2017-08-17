extern int count; // #1

int lookup_example(int count) { // #2
  if (count < 0) { // -> #2
    int count = 1; // #3
    lookup_example(count); // -> #3
  }
  return count /* #2 */ + ::count /* #1 */;
}
