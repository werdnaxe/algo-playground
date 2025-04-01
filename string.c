#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORDLEN 256
#define MAXTABLELEN 26

// Find first occurrance of non-repeating character in a string

char naive_search(const char* str) {   // O(n^2) solution

  int len = strlen(str);
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (str[i] == str[j]) {
	break;
      }
      if (j == len - 1) {   // no match means we've found non-repeating char
	return str[i];
      }
    }
  }

  return 'z';
	
}

// Store string characters in hash table by count values (num times char appears in the string)
char search(const char* str) {

  int alph_table[MAXTABLELEN] = {0};
  //  int str_table[MAXWORDLEN] = {0};
  int index = 0;
  const char* word = strdup(str);
  while (*str != '\0') {
    index = *str - 'a';
    alph_table[index]++;
    str++;
  }

  for (int i = 0; i < strlen(word); i++) {
    index = word[i] - 'a';
    if (alph_table[index] == 1) {   // need to index into letter
      return word[i];
    }
  }

  return 'z';
  
}

int main(int argc, char** argv) {

  if (argc != 2) {
    fprintf(stderr, "Wrong number of args\n");
    exit(EXIT_FAILURE);
  }
  char* str = argv[1];

  //  char letter = naive_search(str);
  char letter = search(str);
  printf("%c\n", letter);
  
  return 0;
}
