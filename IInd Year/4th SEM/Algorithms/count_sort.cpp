#include<iostream>
#include<cstdlib>
using namespace std;

class count_sort{
	
	int *arr, size;
	public:
		count_sort();
		void input();
		void Countsort(int[], int);
		void output();
};

count_sort :: count_sort(){
	
	cout<<"\n enter the size of array";
	cin>>size;
	arr = new int[size];
}

void count_sort :: input(){
	
	for(int i=0; i<size; i++){
		arr[i] = rand()%100;
	}
	
	cout<<"\n\nRandom Array = ";
	output();
	
	Countsort(arr, size);
	cout<<"\nSorted Array = ";
	output();
	cout<<endl;
}
void count_sort ::Countsort(int arr[], int size) {
 int output[10];
  int count[10];
  int max = arr[0];
  
  for (int i = 1; i < size; i++) {
    if (arr[i] > max)
      max = arr[i];
  }

  
  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }

 
  for (int i = 0; i < size; i++) {
    count[arr[i]]++;
  }

 
  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }


  for (int i = size - 1; i >= 0; i--) {
    output[count[arr[i]] - 1] = arr[i];
    count[arr[i]]--;
  }

 
  for (int i = 0; i < size; i++) {
    arr[i] = output[i];
  }
  
  
}


void count_sort :: output(){
	
	for(int i=0; i<size; i++){
		
		cout<<arr[i]<<"  ";
	}
}

int main(){
	
	int m;
	cout<<"***********************************************"<<endl;
	cout<<"\t\t\t\t\t\t\tRANDOMNISED QUICK SORT"<<endl;
	cout<<"***********************************************"<<endl;
	cout<<"\nEnter the number of arrays you wanted to sort = ";
	cin>>m;
	
	for(int i=0; i<m; i++){
		count_sort ob;
		ob.input();
			
		ob.output();
	}
	return 0;
}
