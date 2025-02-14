#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void search(char* text, char* pattern, int text_len, int pattern_len) {


  for (int i = 0; i <= text_len - pattern_len; i++) {
    
    int start = i;
    for (int j = 0; j < pattern_len; j++) {

      if (pattern[j] == text[i++]) {
      } else {
	i = start;
	break;
      }

      if (j == pattern_len - 1) {
	int index = start;
	printf("String match found at offset of %d\n", index);
	i--;
      }
    }
  }
}

int main() {

   char* text = "ABCDBCDAABDBCCAAA";
   char* pattern = "BCD";

   int text_len = strlen(text);
   int pattern_len = strlen(pattern);

   search(text, pattern, text_len, pattern_len);

   return 0;
  
}
