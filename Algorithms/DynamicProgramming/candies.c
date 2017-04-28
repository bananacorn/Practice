/* Candies challenge on HackerRank.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
  // Variable declarations
  int i, j, count, *scores, *left, *right;
  long long int sum = 0;

  scanf("%d\n", &count);
  scores = (int *) malloc(count*sizeof(int));
  left = (int *) malloc(count*sizeof(int));
  right = (int *) malloc(count*sizeof(int));
  for (i = 0; i < count; i++) {
    scanf("%d\n", &scores[i]);
  }

  for (i = 0; i < count; i++) {
    left[i] = 1;
    right[i] = 1;
  }


  for (i = 1; i < count; i++) {
    if (scores[i] > scores[i-1]) {
      left[i] = left[i-1] + 1;
    }
  }
  for (i = count-2; i >= 0; i--) {
    if (scores[i] > scores[i+1]) {
      right[i] = right[i+1] + 1;
    }
  }

  for (i = 0; i < count; i++) {
    if (right[i] > left[i]) {
      sum += right[i];
    } else {
      sum += left[i];
    }
  }

  printf("%lld\n", sum);

  // Clean up
  free(scores);
  free(right);
  free(left);
  return 0;
}
