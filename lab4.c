#define _GNU_SOURCE
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
const int heap_increase = 256;
const int memory_block_size = 128;

struct header {
  uint64_t size;
  struct header *next;
};

int main() {
  void *increased_memory = sbrk(heap_increase);
  struct header *zeroes = (struct header *)increased_memory;
  struct header *ones = (struct header *)((char *)increased_memory + memory_block_size);
     

  zeroes->size = memory_block_size;
  zeroes->next = NULL;
  ones->size = memory_block_size;
  ones->next = zeroes;

  int data_size = memory_block_size - sizeof(struct header);
  char *zeroesArray = (char *)zeroes + sizeof(struct header);
  for (int i = 0; i < data_size; i++) {
    zeroesArray[i] = 0;
  }
  char *onesArray = (char *)ones + sizeof(struct header);
  for (int i = 0; i < data_size; i++) {
    onesArray[i] = 1;
  }
  printf("first block:    %p\n", (void *)zeroes);
  printf("second block:    %p\n", (void *)ones);

  printf("first block size:  %lu\n", zeroes->size);
  printf("first block next:  %p\n", (void *)zeroes->next);

  printf("second block size: %lu\n", ones->size);
  printf("second block next: %p\n", (void *)ones->next);

  for (int i = 0; i < data_size; i++) {
    print_out("%d\n", &zeroesArray[i], sizeof(uint64_t));
  }
  for (int i = 0; i < data_size; i++) {
    print_out("%d\n", &onesArray[i], sizeof(uint64_t));
  }

  return 0;
}
