// https://twitter.com/reiya_2200/status/1130761526959267841

#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc >= 0) {
    /*
    printf("startup: %d", argc);
    for (int i = 0; i < argc; ++i) {
      printf(", %s", argv[i]);
    }
    printf("\n");
    */
    printf("%d\n", main(-1, argv+1));
    return 0;
  }
  if (argv[0] == NULL) {
    return 0;
  }
  /*
  printf("rec call: %d", argc);
  for (int i = 0; argv[i] != NULL; ++i) {
    printf(", %s", argv[i]);
  }
  printf("\n");
  */
  return argv[0][0] - '0' + main(argc, argv+1);
}
