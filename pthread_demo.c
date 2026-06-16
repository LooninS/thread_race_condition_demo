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
  pthread_t writer_thread_1, writer_thread_2, writer_thread_3, writer_thread_4;

  pthread_create(&writer_thread_1, NULL, writer_function, NULL);
  pthread_create(&writer_thread_2, NULL, writer_function, NULL);
  pthread_create(&writer_thread_3, NULL, writer_function, NULL);
  pthread_create(&writer_thread_4, NULL, writer_function, NULL);


  FILE *fp = fopen("shared_string.txt", "a");
  for (long k = 0; k < 250000000; k++) {
    fprintf(fp, "%s\n", shared_string);
  }

  fclose(fp);

  pthread_join(writer_thread_1, NULL);
  pthread_join(writer_thread_2, NULL);
  pthread_join(writer_thread_3, NULL);
  pthread_join(writer_thread_4, NULL);

  return 0;
}
