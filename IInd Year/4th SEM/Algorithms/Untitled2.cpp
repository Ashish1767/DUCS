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
				int n = 25;
				for(int i=0; i<size; i++){
					arr[i] = n++;
					temp_arr[i] = arr[i];
				}
				
				break;
			}
			
		case 3 : {
				int n = 885;
				for(int i=0; i<size; i++){
					arr[i] = n--;
					temp_arr[i] = arr[i];
				}
			break;
		}
		
		default : cout<<"\n Wrong Choice \n";
		goto start;
	}
		
	cout<<"\n\n Entered Array : ";
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
	
	cout<<"\n Total number of comparisons : "<<comp<<endl;
	
	cout<<"\n QUICK SORT \n";
	int comp2 = quick_sort(arr, 0, size-1);
	cout<<" Sorted Array : ";
	output();
	
	cout<<"\n Total number of comparisons : "<<comp2<<endl;
	
	cout<<endl;
}

void sort :: output(){
	
	for(int i=0; i<size; i++){
		
		cout<<arr[i]<<"  ";
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
	
		 
	cout<<"\n Total number of comparisons : "<<comp<<endl;
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
	
	int min,temp,count=0;
	for(int i=0;i<size;i++)
	{
		min=i;
		temp=arr[i];
		for(int j=i+1;j<size;j++)
		{
			count++;
			if(arr[j]<temp)
			{
				min=j;
				temp=arr[j];
			}
		}
		int m=arr[i];
		arr[i]=arr[min];
		arr[min]=m;
	}
	cout<<"\nArray after sorting(selection_sort) :";
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	cout<<"Total number of comparisions are :"<<count<<endl;	
}
int sort :: merge_array(int arr[], int l, int mid, int r){
	
	int s1 = mid - l + 1;
	int s2 = r - mid;
	int tempArr1[s1], tempArr2[s2];
	
	for(int i=0; i<s1; i++){
		
		tempArr1[i] = arr[l+i];
	}
	
	for(int i=0; i<s2; i++){
		
		tempArr2[i] = arr[mid+1+i];
	}
	int i=0, j=0, k=l;
	
	while(i<s1 && j<s2){
		comparison++;
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
	
	return comparison;
}

int sort :: merge_sort(int arr[], int l, int r){
	
	int comp;
	
	if(l < r){
		
		int mid = (l+r)/2;
		merge_sort(arr, l, mid);
		merge_sort(arr, mid+1, r);
		comp = merge_array(arr, l, mid, r);
	}
	
	return comp;
}

int sort :: partit(int arr[], int l, int r){
	
	int pivot = arr[r];
	int i = l - 1;
	
	for(int j=l; j<r; j++){
		if(arr[j] <= pivot){
			comp++;
			i++;
			swap(arr[i], arr[j]);
		}
	}
	
	swap(arr[i+1], arr[r]);
	
	return i+1;
}

int sort :: quick_sort(int arr[], int l, int r){
	
	if(l < r){
		
		int pointer = partit(arr, l, r);
		quick_sort(arr, l, pointer-1);
		quick_sort(arr, pointer+1, r);
	}
	
	return comp;
}

int main(){
	
	int m;
	cout<<"\n Enter the number of arrays you wish to sort : ";
	cin>>m;
	
	for(int i=0; i<m; i++){
		sort ob;
		ob.input();
	}
	
	return 0;
}
