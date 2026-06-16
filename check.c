#include "shared.h"
#include <stdio.h>
#include <string.h>

void error_func(void) {
  // open shared_string.txt
  FILE *fp = fopen("shared_string.txt", "r");
  if (!fp) {
    printf("Error: file not found\n");
    return;
  }

  char line[STRING_SIZE];
  int lineNum = 1;

  while (fgets(line, sizeof line, fp) != NULL) {
    line[strcspn(line, "\n")] = '\0';

    int found = 0;
    // compare each line against set of sentences in sentence.c
    for (int i = 0; i < NUM_SENTENCES; i++) {
      if (strcmp(line, sentences[i]) == 0) {
        found = 1;
        break;
      }
    }
    // print error msg if sentence different from sentence.c
    if (!found) {
      printf("ERROR %d: %s\n", lineNum, line);
    }

    lineNum++;
  }

  fclose(fp);
}

int main(void) {
  error_func();
  return 0;
}
