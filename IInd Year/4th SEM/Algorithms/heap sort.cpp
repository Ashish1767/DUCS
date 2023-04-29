#include<iostream>l
#include<cstdlib>
using namespace std;
class heap_sort{
	int *arr,size;
	public: 
	heap_sort();
	void input();
	int heapify(int[],int,int);
	void heapsort(int[],int);
	void output(); 
};
heap_sort:: heap_sort(){
	cout<<"enter the n size of array:";
	cin>>size;
	arr=new int[size];
}
void heap_sort::input(){
	for(int i=0;i<size;i++){
	
	arr[i]=rand()%100;
}
cout<<"random array=";
output();
heapsort(arr,size);
cout<<"sorted array";
output();
cout<<endl;
}
int heap_sort::heapify(int arr[],int n,int i){
int large=i;
int l=2*i;
int r=2*i+1;

if(l<n &&arr[l]>arr[large])
large=l;
if(r<n && arr[r]>arr[large])
large=r;
if(large!=1){
	swap(arr[i],arr[large]);
	heapify(arr,n,large);
}
}
void  heap_sort::heapsort(int arr[],int n){
	for(int i=n/2-1;i>=0;i--)
	heapify(arr,n,i);
	for(int i=n-1;i>=0;i--){
		swap(arr[0],arr[i]);
		heapify(arr,i,0);
	}
}
void heap_sort::output(){
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
}
int main(){
	int n1;
	cout<<"enter the no. of array you wanted to sort";
	cin>>n1;
for(int i=0;i<n1;i++){
heap_sort obj;
obj.input();
}	
return 0;
}
