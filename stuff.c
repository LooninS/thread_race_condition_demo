#include "shared.h"
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

char shared_string[STRING_SIZE] = "lorem ipsum";

void *writer_function(void *arg) {
  int i = 0;
  while (1) {
    strncpy(shared_string, sentences[i], STRING_SIZE - 1);
    shared_string[STRING_SIZE - 1] = '\0';
    i = (i + 1) % NUM_SENTENCES;
    sleep(5);
  }
  return NULL;
}

int main() {
  pthread_t writer_thread;
  pthread_create(&writer_thread, NULL, writer_function, NULL);
  FILE *fp = fopen("shared_string.txt", "a");
  for (long k = 0; k < 250000000; k++) {
    fprintf(fp, "%s\n", shared_string);
  }
  fclose(fp);
  return 0;
}
