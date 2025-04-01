#include <stdio.h>

void print_list(int list[], int len) {

  printf("[");
  int i = 0;
  for (i; i < len; i++) {
    if (i == len - 1) {
      break;
    }
    printf("%d, ", list[i]);
  }
  printf("%d]\n", list[i]);

}

int main() {

  int len = 10;
  // Initialize list
  int list[len];
  for (int i = 0; i < len; i++) {
    list[i] = i + 1;
  }

  print_list(list, len);   // [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

  // Reverse list
  int i = 0;
  int j = len - 1;
  while (i < len / 2) {

    // Store first and last values in temp variable
    int first_temp = list[i];
    int second_temp = list[j];

    list[i] = second_temp;   // set first index to last value
    list[j] = first_temp;   // set last index to first value

    i++;
    j--;
    
  }

  print_list(list, len);   // [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
  
  return 0;
  
}
