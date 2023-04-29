#include<iostream>
#include<cstdlib>
using namespace std;

class merge_sort{
	
	int *arr, size;
	
	public:
		merge_sort();
		void input();
		void mergeArray(int[], int, int, int);
		void mergeSort(int[], int, int);
		void output();
};

merge_sort :: merge_sort(){
	
	cout<<"\n\n Enter the size of the array : ";
	cin>>size;
	
	arr = new int[size];
}

void merge_sort :: input(){
	
	for(int i=0; i<size; i++){
		arr[i] = rand();
	}
	
	cout<<"\n\n Random Array : ";
	output();
	
	mergeSort(arr, 0, size-1);
	cout<<"\n Sorted Array : ";
	output();
}

void merge_sort :: mergeArray(int arr[], int l, int mid, int r){
	
	int s1 = mid - l + 1, s2 = r - mid;
	int tempArr1[s1], tempArr2[s2];
	
	for(int i=0; i<s1; i++){
		
		tempArr1[i] = arr[l+i];
	}
	
	for(int i=0; i<s2; i++){
		
		tempArr2[i] = arr[mid+1+i];
	}
	int i=0, j=0, k=l;
	
	while(i<s1 && j<s2){
		
		if(tempArr1[i] < tempArr2[j]){
			arr[k] = tempArr1[i];
			k++;
			i++;
		}
		
		else{
			arr[k] = tempArr2[j];
			k++;
			j++;
		}
	}
	
	while(i<s1){
		
		arr[k] = tempArr1[i];
		k++;
		i++;
	}
	
	while(j<s2){
		
		arr[k] = tempArr2[j];
		k++;
		j++;
	}
}

void merge_sort :: mergeSort(int arr[], int l, int r){
	
	if(l < r){
		
		int mid = (l+r)/2;
		mergeSort(arr, l, mid);
		mergeSort(arr, mid+1, r);
		mergeArray(arr, l, mid, r);
	}
}

void merge_sort :: output(){
	
	for(int i=0; i<size; i++){
		
		cout<<arr[i]<<"  ";
	}
}
int main(){
	int m;
	cout<<"\n Enter the number of arrays you wish to sort : ";
	cin>>m;
	for(int i=0; i<m; i++){
		merge_sort ob;
		ob.input();	
	}
	return 0;
}

