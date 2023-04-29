#include<iostream>
 #include<cstdlib>
 using namespace std;
  class heap_sort{
  	int *arr,size;
    public:
    
    	void input();
    	 int  heapify( int[], int,int);
    	   void heap();
    	    void output();
  };
   
   void heap_sort::input(){
   	  	 cout<<" enter the size of the array";
   	 cin>>size;
   	 arr= new int[size];
   
   	 cout<<"enter the elements of the array";
   	 for(int i=0;i<size;i++){
   	 	cin>>arr[i];
		} 
		cout<<" the given array is :";
		output();
		heap();
		cout<<"array after sorting";
       output();   
   }
 int heap_sort::heapify(int arr[],int size,int i){
    int largest=i;
     int left=2*i+1;
     int right=2*i+2;
     if(left<size && arr[left]>arr[largest])
     largest= left;
     if(right<size &&  arr[right]>arr[largest])
     largest= right;
     if(largest!=i){
	 
     swap(arr[i],arr[largest]);
     heapify(arr,size,largest);
	}}
	 void  heap_sort::heap(){
	 	for(int i=size/2-1;i>=0;i--)
	 		heapify(arr,size,i);
	 		for(int i=size-1;i>=0;i--){
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
	   	 heap_sort obj;
	   	  obj.input();
	   	  return 0;
	   }
