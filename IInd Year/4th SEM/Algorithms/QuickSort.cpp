#include<iostream>
#include<cstdlib>
using namespace std;

class quick_sort{
	
	int *arr, size;
	
	public:
		quick_sort();
		void input();
		int partit(int[], int, int);
		void quickSort(int[], int, int);
		void output();
};

quick_sort :: quick_sort(){
	
	cout<<"\n\n Enter the size of the array : ";
	cin>>size;
	arr = new int[size];
}

void quick_sort :: input(){
	
	for(int i=0; i<size; i++){
		arr[i] = rand()%100;
	}
	
	cout<<"\n\n Random Array is given as  : ";
	output();
	
	quickSort(arr, 0, size-1);
	cout<<"\n Sorted Array  is given as : ";
	output();
}

int quick_sort :: partit(int arr[], int l, int r){
	int pivot = arr[r];
	int i = l - 1;
	for(int j=l; j<r; j++){
		if(arr[j] <= pivot){
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i+1], arr[r]);
	return i+1;
}
void quick_sort :: quickSort(int arr[], int l, int r){
	
	if(l < r){
		
		int pointer = partit(arr, l, r);
		quickSort(arr, l, pointer-1);
		quickSort(arr, pointer+1, r);
	}
}

void quick_sort :: output(){
	
	for(int i=0; i<size; i++){
		
		cout<<arr[i]<<"  ";
	}
}

int main(){
	
	int m;
	cout<<"\n Enter the number of arrays you wanted to sort : ";
	cin>>m;
	
	for(int i=0; i<m; i++){
		quick_sort ob;
		ob.input();	
	}
	
	return 0;
}
