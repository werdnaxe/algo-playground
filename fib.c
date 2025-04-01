#include <stdio.h>
#include <stdlib.h>

int fib_recursive(int n, int first, int second) {

  // first = 0
  // second = 1
  int result = first + second;

  if (n == 0) {
    return result;
  }

  fib_recursive(n - 1, second, result);
  
}

int fib_iterative(int n) {

  int first = 0;
  int second = 1;
  int count = 0;
  int result = 0;

  if (n == 0) {
    return 0;
  }
  
  while (count < n) {
    result = first + second;   // 
    first = second;   // 
    second = result;   //
    count++;   // 
  }
    
  return result;
}

int main(int argc, char** argv) {

  if (argc != 2) {
    fprintf(stderr, "Wrong number of args\n");
    exit(EXIT_FAILURE);
  }
  int n = atoi(argv[1]);
  if (n == 0) {
    printf("0\n");
    return 0;
  } else if (n == 1) {
    printf("1\n");
    return 1;
  }

  int first = 0;
  int second = 1;
  int result = fib_iterative(n);
  printf("%d\n", result);
  
  return 0;
}
