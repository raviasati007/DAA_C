#include <stdio.h>

/* Aim :- You are the chief archivist at Nalanda Mahavihara, the legendary ancient Indian university renowned for its vast collection of manuscripts. Palm-leaf manuscripts and birch-bark scrolls are stored in meticulously catalogued order using Archive IDs.
The Rajguru (Royal Priest) requests a specific manuscript for a sacred Vedic ritual. Multiple copies of the same manuscript may exist, but tradition dictates that the priest must always receive the oldest preserved copy, which corresponds to the first occurrence of the Archive ID in the catalog.
Your challenge is to locate this first occurrence efficiently. A linear search through the sprawling manuscript vault would take too long and result in a Time Limit Exceeded (TLE) verdict. Instead, you must apply the power of Binary Search to swiftly find the earliest preserved copy.
*/

// Function to find the first occurrence of an Archive ID
int findFirstOccurrence(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    int result = -1; // Default if not found

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            result = mid;     // Record the potential answer
            high = mid - 1;   // Keep searching left to find an earlier copy
        } 
        else if (arr[mid] < target) {
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }
    return result;
}

int main() {
    int n,i, target;

    printf("Enter number of scrolls in the vault: ");
    scanf("%d", &n);

    int archive[n];
    printf("Enter sorted Archive IDs:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &archive[i]);
    }

    printf("Enter the Archive ID to search for: ");
    scanf("%d", &target);

    int index = findFirstOccurrence(archive, n, target);

    if (index != -1) {
        printf("\nScroll found! Oldest copy (first occurrence) is at position: %d\n", index);
    } else {
        printf("\nError: Scroll ID %d not found in the archives.\n", target);
    }

    return 0;
}

