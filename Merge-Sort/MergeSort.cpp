#include <iostream>
using namespace std;

void Merge(int *arr,int l,int m,int h)
{
    int arr1Size=m-l+1;
    int arr2Size=h-m;
    int LeftArr[arr1Size],RightArr[arr2Size];

    for(int i=0;i<arr1Size;i++)
        LeftArr[i]=arr[l+i];

    for(int i=0;i<arr2Size;i++)
        RightArr[i]=arr[m+1+i];
    
    int i=0,j=0,k=l;
    while (i<arr1Size&&j<arr2Size)
    {
        if(LeftArr[i]<=RightArr[j]){
            arr[k]=LeftArr[i];
            i++;
        }
        else
        {
            arr[k]=RightArr[j];
            j++;
        }
        k++;
    }
    while (i < arr1Size)
	{
		arr[k] = LeftArr[i];
		i++;
		k++;
	}

	while (j < arr2Size)
	{
		arr[k] = RightArr[j];
		j++;
		k++;
	}
    
}

void MergeSort(int arr[],int low, int high)
{
    if(low<high)        /// if low=high > merge 1'elemnt, if low<high > merge 2'elemnts or more!
    {
        int mid=(low+high)/2;
        MergeSort(arr,low,mid);
        MergeSort(arr,mid+1,high);
        Merge(arr,low,mid,high);
     }
}


int main()
{
        int arr[] = {1,3,5,0,8,9,2,4,7,6};
		int n = sizeof(arr) / sizeof(arr[0]);
        MergeSort(arr, 0, n-1);
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
    
}