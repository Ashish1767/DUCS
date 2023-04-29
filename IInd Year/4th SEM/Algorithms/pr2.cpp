#include<iostream>
#include<cstdlib>
using namespace std;
class sort{
	int *arr, *temp_arr, size, comparison, comp, comp2;
	public:
		sort();
		void input();
		void insertion_sort();
		void bubble_sort();
		void selection_sort();
		int merge_array(int[], int, int, int);
		int merge_sort(int[], int, int);
		int partit(int[], int, int);
		int quick_sort(int[], int, int);
		void output();
		void array_change();
};

sort :: sort(){
	
	comparison = comp = 0;
	cout<<"\n Enter the size of the array : ";
	cin>>size;
	
	arr = new int[size];
	temp_arr = new int[size];
}

void sort :: input(){
	
	start:
	int c;
	cout<<" how do you want to enter the array:-";
	cout<<"\n 1: Random Order \n 2: Increasing Order \n 3: Decreasing order \n";
	cout<<"\n Enter your choice : "; cin>>c;
	
	switch(c){
		
		case 1 : {
				for(int i=0; i<size; i++){
				arr[i] = rand()%100;
				temp_arr[i] = arr[i];
			}
			break;
		}
			
		case 2 : {
				int n = 55;
				for(int i=0; i<size; i++){
					arr[i] = n++;
					temp_arr[i] = arr[i];
				}
				
				break;
			}
			
		case 3 : {
				int n = 785;
				for(int i=0; i<size; i++){
					arr[i] = n--;
					temp_arr[i] = arr[i];
				}
			break;
		}
		
		default : cout<<"\n Wrong Choice \n";
		goto start;
	}
		
	cout<<"\n\n random array is given by: ";
	output();
	cout<<endl;
	
	cout<<"\n INSERTION SORT \n";
	insertion_sort();
	
	cout<<"\n BUBBLE SORT \n";
	bubble_sort();
	
	cout<<"\n SELECTION SORT \n";
	selection_sort();
	
	cout<<"\n MERGE SORT \n";
	int comp = merge_sort(arr, 0, size-1);
	cout<<" Sorted Array : ";
	output();
	array_change();
	cout<<"\n Total number of comparisons are given as : "<<comp<<endl;
	
	cout<<"\n QUICK SORT \n";
	int comp2 = quick_sort(arr, 0, size-1);
	cout<<" Sorted Array : ";
	output();
	array_change();
	cout<<"\n Total number of comparisons  are given as : "<<comp2<<endl;
	
	cout<<endl;
}

void sort :: output(){
	
	for(int i=0; i<size; i++){
		
		cout<<arr[i]<<"  ";
	}
}

void sort :: array_change(){
	
	for(int i=0; i<size; i++){
		
		arr[i] = temp_arr[i];
	}
}

void sort :: insertion_sort(){
	
	int comp = 0;
	for(int i=1; i<size; i++)
	{
		int k = arr[i];
		int j = i-1;
		
		if(i>1)
		comp++;
		
		while(k<arr[j] && j>=0) 
		{
			comp++;
			arr[j+1] = arr[j];
			j--;
		}
		 
		arr[j+1] = k;
	 }
	 
	cout<<" Sorted Array : ";
	output();
	
	array_change();
	 
	cout<<"\n Total number of comparisons  are given as : "<<comp<<endl;
}

void sort :: bubble_sort(){
	
	int temp,count=0;
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size-1;j++)
		{
			count++;
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	cout<<"\nArray after sorting(bubble_sort) :";
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	cout<<"Total number of comparisions are :"<<count<<endl;
}


void sort :: selection_sort(){
	
	int temp, comp, sumcomp = 0;

	for(int i=0, j, least; i<size-1; i++)
	{
		comp = 0;
		
		least = i;
		
 		for(j=i+1; j<size; j++)
 		{
 			comp++;
 			
 			if(arr[j] < arr[least])
 			{
 				least = j;
 			}
 		}
 		temp = arr[least];
		arr[least] = arr[i];
		arr[i] = temp;
		
		sumcomp += comp;
 	}
	cout<<" Sorted Array : ";
	output();
	array_change();
	 
	cout<<"\n Total number of comparisons  are given as : "<<sumcomp<<endl;
}

int sort :: merge_array(int arr[], int l, int mid, int h){
	
	int a1 = mid - l + 1;
	int a2 = h - mid;
	int temparr1[a1], temparr2[a2];
	
	for(int i=0; i<a1; i++){
		
		temparr1[i] = arr[l+i];
	}
	
	for(int i=0; i<a2; i++){
		
		temparr2[i] = arr[mid+1+i];
	}
	int i=0, j=0, k=l;
	
	while(i<a1 && j<a2){
		comparison++;
		if(temparr1[i] < temparr2[j]){
			arr[k] = temparr1[i];
			k++;
			i++;
		}
		
		else{
			arr[k] = temparr2[j];
			k++;
			j++;
		}
	}
	
	while(i<a1){	
		arr[k] = temparr1[i];
		k++;
		i++;
	}
	while(j<a2){
		arr[k] = temparr2[j];
		k++;
		j++;
	}
	
	return comparison;
}

int sort :: merge_sort(int arr[], int l, int h){
	
	int comp;
	
	if(l < h){
		
		int mid = (l+h)/2;
		merge_sort(arr, l, mid);
		merge_sort(arr, mid+1, h);
		comp = merge_array(arr, l, mid, h);
	}
	
	return comp;
}

int sort :: partit(int arr[], int l, int h){
	
	int pivot = arr[h];
	int i = l - 1;
	
	for(int j=l; j<h; j++){
		if(arr[j] <= pivot){
			comp++;
			i++;
			swap(arr[i], arr[j]);
		}
	}
	
	swap(arr[i+1], arr[h]);
	
	return i+1;
}

int sort :: quick_sort(int arr[], int l, int h){
	
	if(l < h){
		
		int pointer = partit(arr, l, h);
		quick_sort(arr, l, pointer-1);
		quick_sort(arr, pointer+1, h);
	}
	
	return comp;
}

int main(){
	
	int c;
	cout<<"\n Enter the no. of arrays you wanted to sort : ";
	cin>>c;
	for(int i=0; i<c; i++){
		sort obj;
		obj.input();
	}
	return 0;
}
