#include <stdio.h>

int interpolation_search_iterative(int arr[], int n, int x) {
    int l = 0;
    int h = n - 1;

    while (l <= h && x >= arr[l] && x <= arr[h]) 
    {
        if (l == h) 
        {
            if (arr[l] == x)
            {
                return l;
            }
            return -1;
        }

        int pos = l + ((x - arr[l]) * (h - l)) / (arr[h] - arr[l]);

        if (arr[pos] == x)
        {
            return pos;
        }
        if (arr[pos] < x)
        {
            l = pos + 1;
        }
        else
        {
            h = pos - 1;
        }
    }

    return -1;
}

int interpolation_search_recursive(int arr[], int l, int h, int x) 
{
    if (l > h || x < arr[l] || x > arr[h])
    {
        return -1;
    }

    if (l == h) 
    {
        if (arr[l] == x)
            return l;
        return -1;
    }

    int pos = l + ((x - arr[l]) * (h - l)) / (arr[h] - arr[l]);

    if (pos < l || pos > h)
    {
        return -1;
    }

    if (arr[pos] == x)
    {
        return pos;
    }
    if (arr[pos] < x)
    {
        return interpolation_search_recursive(arr, pos + 1, h, x);
    }
    return interpolation_search_recursive(arr, l, pos - 1, x);
}

int main() 
{
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) 
    {
        printf("Invalid size\n");
        return 1;
    }

    int arr[n];
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    int x;
    printf("Enter value to search: ");
    scanf("%d", &x);

    int choice;
    printf("Choose search method:\n1. Iterative\n2. Recursive\nEnter choice: ");
    scanf("%d", &choice);

    int index = -1;
    switch (choice) 
    {
        case 1:
            index = interpolation_search_iterative(arr, n, x);
            break;
        case 2:
            index = interpolation_search_recursive(arr, 0, n - 1, x);
            break;
        default:
            printf("Invalid choice\n");
            return 1;
    }

    if (index != -1)
    {
        printf("Element found at index %d\n", index);
    }
    else
    {
        printf("Element not found\n");
    }

    return 0;
}
