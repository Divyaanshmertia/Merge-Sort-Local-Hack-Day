#include<stdio.h>
#include<conio.h>
// function to sort the subsection a[i .. j] of the array a[]
void merge_sort(int i, int j, int a[], int aux[]) {
    if (j <= i) {
        return;     // the subsection is empty or a single element
    }
    int mid = (i + j) / 2;

    // left sub-array is a[i .. mid]
    // right sub-array is a[mid + 1 .. j]
    
	// sort the left sub-array 
    merge_sort(i, mid, a, aux);
	// sort the right sub-array      
    merge_sort(mid + 1, j, a, aux);     

    int pointer_left = i;      
    int pointer_right = mid + 1;       
    int k;     

    // we loop from i to j to fill each element of the final merged array
    for (k = i; k <= j; k++) {
        if (pointer_left == mid + 1) {      // left pointer has reached the limit
            aux[k] = a[pointer_right];
            pointer_right++;
        } else if (pointer_right == j + 1) {        // right pointer has reached the limit
            aux[k] = a[pointer_left];
            pointer_left++;
        } else if (a[pointer_left] < a[pointer_right]) {   // pointer left points to smaller element
            aux[k] = a[pointer_left];
            pointer_left++;
        } else {        // pointer right points to smaller element
            aux[k] = a[pointer_right];
            pointer_right++;
        }
    }

    for (k = i; k <= j; k++) {      // copy the elements from aux[] to a[]
        a[k] = aux[k];
    }
}

int main() {
  int a[100], aux[100], n, i, d, swap;
  printf("*************************************************************************************\n");
  printf(" Heloo there!! Welcome to Divyaansh sorting service :)\n");
  printf(" Enter number of elements to sort:");
  scanf("\t \t %d", &n);
  printf(" Entering %d  random integers\n", n);
 
  for (i = 0; i < n; i++){
  	a[i]=rand();
  	printf("\n\t \t %d",a[i]);
  }
    
  merge_sort(0, n - 1, a, aux);
 
  printf("\n Printing the sorted list:\n");
 
  for (i = 0; i < n; i++)
     printf("\t \t %d\n", a[i]);
     printf("*************************************************************************************\n");
 
  return 0;
}
