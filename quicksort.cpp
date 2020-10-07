#include<iostream>
using namespace std;
 
void swap(int* a, int* b);
  
// Using last element as pivot
int partition (int arr[], int a, int b)  
{  
    int pivot = arr[b];  
    int i = (a - 1); 
  
    for (int j = a; j <= b - 1; j++)  
    {  
        if (arr[j] < pivot)  
        {  
            i++; 
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[b]);  
    return (i + 1);  
}  
  

void quickSort(int arr[], int a, int b)  
{  
    if (a < b)  
    {  
     
        int part = partition(arr, a, b);  
    
        quickSort(arr, a, part - 1);  
        quickSort(arr, part + 1, b);  
    }  
}  
  

int main()  
{  	int n,item;
	cout<<"Enter the number of elements in the unsorted array"<<endl;
	cin>>n;
    int arr[n];
	
	//Input
	cout<<"Enter the elements of array"<<endl;
	for(int i=0;i<n;i++){
		cin>>item;
		arr[i] = item;
	}  
	
    quickSort(arr, 0, n - 1);  
    
	//Sorted Array
	for(int i=0;i<n;i++){
		cout<<arr[i]<<' ';
	}
	
	return 0;  
}  

void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  
