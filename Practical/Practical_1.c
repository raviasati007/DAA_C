#include <stdio.h>
/* Aim:- You are a DevOps engineer at a data center in Pune, managing a critical web server that supports millions of users across India. One day, the server crashes, leaving behind a massive, unsorted log file of user requests with Unix timestamps. To help the DevOps team trace the exact sequence of events leading to the failure, you must sort the log entries chronologically.
This is essentially a sorting problem, where timestamps act as keys. Efficient algorithms like Merge Sort or Quick Sort are used to handle large datasets.
*/

// Function to swap two elements
void swap(long long* a, long long* b) {
    long long t = *a;
    *a = *b;
    *b = t;
}

// Partition function using the last element as pivot
int partition(long long arr[], int low, int high) {
	int j;
    long long pivot = arr[high]; 
    int i = (low - 1); 

    for (j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// The main Quick Sort function
void quickSort(long long arr[], int low, int high) {
    if (low < high) {
        // pi is partitioning index
        int pi = partition(arr, low, high);

        // Separately sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n,i;
    printf("Enter number of log Entries: ");
    scanf("%d", &n);

    if (n <= 0) return 0;

    long long logs[n];
    printf("Enter %d Unix Timestamps:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%lld", &logs[i]);
    }

    quickSort(logs, 0, n - 1);

    printf("\nChronologically Sorted Timestamps:\n");
    for (i = 0; i < n; i++) {
        printf("%lld\n", logs[i]);
    }

    return 0;
}

