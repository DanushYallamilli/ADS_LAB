#include<stdio.h>

void qs(int a[], int l, int h)
{
    if(l >= h)
    {
        return;
    }

    int p = a[h] , i = l-1;

    for(int j = l; j < h; j++)
    {
        if(a[j] < p)
        {
            i++;
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }

    int t = a[i+1];
    a[i+1] = a[h];
    a[h] = t;

    int m = i+1;

    qs(a,l,m-1);
    qs(a,m+1,h);
}

int main()
{
    int n;
    printf("Enter the no of elements:\n");
    scanf("%d",&n);

    int a[n];
    
    printf("Enter the elements:\n");
    for(int i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
    }

    qs(a,0,n-1);

    printf("Sorted Array:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}