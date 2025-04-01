#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_string(char* string) {

  for (int i = 0; i < strlen(string); i++) {
    printf("%c", string[i]);
  }
  printf("\n");
}

int main(int argc, char** argv) {

  if (argc != 2) {
    fprintf(stderr, "Wrong number of args\n");
    exit(EXIT_FAILURE);
  }
  char* string = argv[1];
  
  /* char string[12] = "Hello World!"; */
  print_string(string);

  int i = 0;
  char temp1 = ' ';
  char temp2 = ' ';
  int len = strlen(string);
  int n = len - 1;
  while (i < len / 2) {
    temp1 = string[i];
    temp2 = string[n];

    string[i++] = temp2;
    string[n--] = temp1;
  }

  print_string(string);

  return 0;
}
