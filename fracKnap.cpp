// Write a program to solve fractional knapsack problem using greedy approach
#include<iostream>
#include <bits/stdc++.h> 
using namespace std; 
  
class Item 
{ 	public:
    int value, weight; 
  
}; 

// Function to sort according to value/weight ratio 
bool compare(struct Item item1, struct Item item2) 
{ 
    double ratio1 = (double)item1.value / item1.weight; 
    double ratio2 = (double)item2.value / item2.weight; 
    return ratio1 > ratio2; 
} 
  
// Main Function 
void fractionalKnapsack(int Weight, struct Item array[], int n) 
{ 
    sort(array, array + n, compare); 
  
    int currentWeight = 0;  
    double finalvalue = 0.0; 
  
    for (int i = 0; i < n; i++) 
    { 
        // add it completely 
        if (currentWeight + array[i].weight <= Weight) 
        { 
            currentWeight += array[i].weight; 
            finalvalue += array[i].value; 
            //cout<<"("<<array[i].weight<<","<<array[i].value<<")"<<"\t";
        } 
  
        // add fractional part of it 
        else
        { 
            int remain = Weight - currentWeight; 
            finalvalue += array[i].value * ((double) remain / array[i].weight); 
            //cout<<"("<<array[i].weight<<","<<array[i].value<<")"<<"\t";
            break; 
        } 
    } 
  
    cout<<"Max value obtained :"<<finalvalue<<endl;
} 
  
int main() 
{ 	int Weight;
	cout<<"Enter the maximum value"<<endl;
	cin>>Weight;
	
	int n;
	cout<<"Enter the number of value-weight pairs"<<endl;
	cin>>n;
    
    cout<<"Enter the value-weight pair"<<endl;
    Item array[n];
    for(int i=0;i<n;i++){
    	cin>>array[i].value>>array[i].weight;
	}
  
   //Knapsack function is called
   	fractionalKnapsack(Weight, array, n); 
    return 0; 
} 
