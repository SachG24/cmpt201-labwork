#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  char *line = NULL;
  size_t size = 0;
  printf("Please enter some text: ");
  ssize_t num_char = getline(&line, &size, stdin);

  if (num_char != -1) {
    // printf("Buffer: %s\n", line);
    printf("Tokens: \n");
    char *ret = NULL;
    char *saveptr = NULL;
    char *str = line;
    while ((ret = strtok_r(str, " ", &saveptr))) {
      printf("%s\n", ret);
      str = NULL;
    }

  } else {
    printf("Error");
  }

  free(line);
  return 0;
}
