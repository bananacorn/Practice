/* Quicksort In-Place challenge by HackerRank.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Global array length
int length;

void quicksort(int start, int end, int arr[]) {
  // Variable declarations
  int i, temp, pivot = start;

  if (end <= start + 1) {
    return 0;
  }

  // Sort around partition
  for (i = start; i < end; i++) {
    if (arr[i] < arr[end-1]) {
      if (i != pivot) {
        temp = arr[i];
        arr[i] = arr[pivot];
        arr[pivot] = temp;
      }
      pivot++;
    }
  }
  temp = arr[end-1];
  arr[end-1] = arr[pivot];
  arr[pivot] = temp;

  // Print current array
  for (i = 0; i < length; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  // Recursive calls
  quicksort(start, pivot, arr);
  quicksort(pivot+1, end, arr);
}

int main() {
  // Variables
  int i;

  // Acquire input array
  scanf("%d", &length);
  int arr[length];
  for (i = 0; i < length; i++) {
    scanf("%d", &arr[i]);
  }

  // Call to quicksort()
  quicksort(0, length, arr);

  return 0;
}
