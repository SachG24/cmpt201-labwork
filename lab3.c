#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5
int main() {
  char *line = NULL;
  size_t size = 0;
  char *inputs[MAX] = {NULL};
  int counter = 0;

  while (1) {
    printf("Enter input: ");

    line = NULL;
    size = 0;
    if (getline(&line, &size, stdin) == -1) {
      free(line);
      break;
    }

    line[strcspn(line, "\n")] = '\0';

    if (counter == MAX) {
      free(inputs[0]);
      for (int i = 0; i < MAX - 1; i++) {
        inputs[i] = inputs[i + 1];
      }
      counter = MAX - 1;
    }

    inputs[counter++] = line;

    if (strcmp(line, "print") == 0) {
      for (int j = 0; j < counter; j++) {
        if (inputs[j] != NULL) {
          printf("%s\n", inputs[j]);
        }
      }
    }
  }

  for (int i = 0; i < counter; i++)
    free(inputs[i]);

  return 0;
}
