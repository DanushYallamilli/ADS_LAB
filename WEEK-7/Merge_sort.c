#include<stdio.h>

void merge(int a[], int l, int m, int h)
{
    int i =l, j = m+1, k=0, temp[h-l+1];

    while(i <= m &&  j <= h)
    {
        temp[k++] = a[i] < a[j]? a[i++] : a[j++];
    }
    while(i <= m)
    {
        temp[k++] = a[i++];
    }
    while(j <= h)
    {
        temp[k++] = a[j++];
    }
    for(i = l, k = 0 ; i <= h; i++, k++)
    {
        a[i] = temp[k];
    }

}

void ms(int a[], int l, int h)
{
    if(l >= h)
    {
        return;
    }
    int m = (l+h)/2;
    ms(a,l,m);
    ms(a,m+1,h);
    merge(a,l,m,h);
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

    ms(a,0,n-1);

    printf("Sorted Array:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}