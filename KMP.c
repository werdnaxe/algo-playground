#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void KMP(char* seq, char* pattern, int seq_len, int pattern_len) {

  // Zero out LPS array
  int LPS[pattern_len];   // do I need for loop to zero out?
  for (int i = 0; i < pattern_len; i++) {
    LPS[i] = 0;
  }

  // Populate LPS array
  for (int i = 0; i < pattern_len - 1; i++) {

    int j = i + 1;
    int k = i;
    while (k > 0 && pattern[i+1] != pattern[k]) {
      k = LPS[j - 1];
      j--;
    }
    
    if (pattern[i+1] == pattern[k]) {
      if (k == i) {   // never entered while loop
	if (pattern[i+1] == pattern[LPS[i]]) {
	  LPS[i+1] = LPS[i] + 1;
	} else {
	  if (pattern[i+1] == pattern[0]) {
	    LPS[i+1] = 1;
	  } else {
	    LPS[i+1] = 0;
	  }
	}
      } else {   // entered while loop
	LPS[i+1] = k + 1;
      }
    } else {
      LPS[i+1] = 0;
    }
    
  }

  // Print LPS array
  printf("PRINTING LPS ARRAY for %s\n", pattern);
  printf("[");
  for (int i = 0; i < pattern_len; i++) {
    
    if (i != pattern_len - 1) {
      printf("%d, ", LPS[i]);
    } else {
      printf("%d]\n", LPS[i]);
    }
    
  }
  
}

  
int main() {

  char* seq = "ABABACDDBDCAABABACABABAA";
  char* pattern = "ABABAC";
  int seq_len = strlen(seq);
  int pattern_len = strlen(pattern);

  KMP(seq, pattern, seq_len, pattern_len);

  char* pattern2 = "AABCBA";
  int pattern2_len = strlen(pattern2);
  KMP(seq, pattern2, seq_len, pattern2_len);

  char* pattern3 = "ABCADABCAA";
  int pattern3_len = strlen(pattern3);
  KMP(seq, pattern3, seq_len, pattern3_len);

  char* pattern4 = "ABCADABCDA";
  int pattern4_len = strlen(pattern4);
  KMP(seq, pattern4, seq_len, pattern4_len);

  char* pattern5 = "ABCAAABCAA";
  int pattern5_len = strlen(pattern5);
  KMP(seq, pattern5, seq_len, pattern5_len);

  char* pattern6 = "ABCAAABCDA";
  int pattern6_len = strlen(pattern6);
  KMP(seq, pattern6, seq_len, pattern6_len);

  char* pattern7 = "ABCADABCAD";
  int pattern7_len = strlen(pattern7);
  KMP(seq, pattern7, seq_len, pattern7_len);

  char* pattern8 = "ABCADABCDA";
  int pattern8_len = strlen(pattern8);
  KMP(seq, pattern8, seq_len, pattern8_len);
  
  return 0;
}
