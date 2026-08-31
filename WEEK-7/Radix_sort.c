#include<stdio.h>

int getMax(int a[], int n)
{
    int max = a[0];
    for(int i= 0; i<n; i++)
    {
        if(a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}

void countSort(int a[], int n, int exp)
{
    int out[n], count[10] = {0};

    for(int i = 0; i < n; i++)
    {
        count[(a[i]/exp)%10]++;
    }

    for(int i = 1; i < 10; i++)
    {
        count[i] += count[i-1];
    }
    for(int i = n-1; i >= 0; i--)
    {
        out[--count[(a[i]/exp)%10]] = a[i];
    }
    for(int i = 0; i < n; i++)
    {
        a[i] = out[i];
    }
}

void radixSort(int a[], int n)
{
    int max = getMax(a,n);
    for(int exp = 1 ; max/exp > 0; exp *= 10)
    {
        countSort(a,n,exp);
    }
}

int main()
{
    int n;
    printf("Enter the no of elements:\n");
    scanf("%d", &n);

    int a[n];

    printf("Enter the elements:\n");
    
    for(int i = 0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }

    radixSort(a,n);

    printf("Sorted Array:\n");
    for(int i = 0; i<n; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}