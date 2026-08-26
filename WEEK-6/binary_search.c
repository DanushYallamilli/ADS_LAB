#include<stdio.h>

int binary_search_i(int arr[], int n, int k)
{
    int low = 0;
    int high = n-1;
    
    while(low <= high)
    {
        int mid = low + (high-low) / 2;

        if (arr[mid] == k)
        {
            return mid;
        }
        else if(arr[mid] < k)
        {
            low = mid+1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int binary_search_r(int arr[], int low, int high, int k)
{
    if (low > high)
    {
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == k)
    {
        return mid;
    } 
    else if (arr[mid] > k) 
    {
        return binary_search_r(arr, low, mid - 1, k);
    } 
    else 
    {
        return binary_search_r(arr, mid + 1, high, k);
    }
}

int main()
{
    int n;
    printf("Enter the size of the array:\n");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array :\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int choice = 0;
    while (1) 
    {
        printf("\nBinary Search\n1. Iterative binary search\n2. Recursive binary search\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);

        int k, res;
        switch (choice) 
        {
            case 1:
                printf("Enter the value to search:\n");
                scanf("%d", &k);
                res = binary_search_i(arr, n, k);
                if (res != -1)
                {
                    printf("Element %d found at index %d.\n", k, res);
                }
                else
                {
                    printf("Element %d not found in the array.\n", k);
                }
                break;

            case 2:
                printf("Enter the value to search:\n");
                scanf("%d", &k);
                res = binary_search_r(arr, 0, n - 1, k);
                if (res != -1)
                {
                    printf("Element %d found at index %d.\n", k, res);
                }
                else
                {
                    printf("Element %d not found in the array.\n", k);
                }
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}