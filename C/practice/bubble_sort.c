#include<stdio.h>
int main()
{
      int arr[100], a,b,n ,swap;
      printf("Enter the number of elements-> ");
      scanf("%d",&n);
      printf("Enter the elements-> ");
      for(a=0;a<n;a++)
            scanf("%d",&arr[a]);

      for(a=0;a<n-1;a++)
            for(b=0;b<n-a-1;b++)
            {
                  if(arr[b]>arr[b+1])
                  {
                        swap=arr[b];
                        arr[b]=arr[b+1];
                        arr[b+1]=swap;
                  }
            }   
      printf("the sorted array ");
      for(a=0;a<n;a++)
            printf("\t%d",arr[a]);
      return 0;
}