#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

template<class T>
class Heap_Sort{
	private:
		T *arr;
		int size,*sizeArray,*noc,s,numberOfComp;
	public:
		void get();
		void min_heapify(T arr[],int size,int i);
		void heapsort(T arr[],int size);
		void print(T arr[],int size);
		void menu();	
};

template<class T>
void Heap_Sort<T>::get(){
	 s=15;
	sizeArray = new int[s];
	noc = new int[s];
	for(int i=0; i<s; i++){
		numberOfComp=0;
		sizeArray[i] = (rand() % 71)+30;
		arr=new int[sizeArray[i]];
		for(int j=0; j<sizeArray[i]; j++){
			T data = rand()%100; 
			arr[j] = data;
		}
		 
		heapsort(arr,sizeArray[i]);	
		 
		noc[i] = numberOfComp;
	}
}
template<class T>
void Heap_Sort<T>::min_heapify(T arr[],int size,int i){
	int smallest=i;
	int left=2*i+1;
	int right=2*(i+1);
	
	while(left<size && arr[left]<arr[smallest] && ++numberOfComp){
		smallest=left;
	}
	while(right<size && arr[right]<arr[smallest]  && ++numberOfComp){
		smallest=right;
	}
	if(smallest!=i){
		T temp = arr[smallest];
		arr[smallest] = arr[i];
		arr[i] = temp;
		min_heapify(arr,size,smallest);
	}
}

template<class T>
void Heap_Sort<T>::heapsort(T arr[],int size){
	
	for(int i=((size/2)-1);i>=0;i--){
		min_heapify(arr,size,i);
	}
	
	for(int i=size-1;i>0;i--){
		T temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		min_heapify(arr,i,0);
	}
}

template<typename T>
void Heap_Sort<T>::print(T arr[],int size){
	for(int i=0;i<size;i++){
		cout<<"\n"<<arr[i]<<" ";
	}
	cout<<endl;
}

template <class T>
void Heap_Sort<T>::menu(){
	get();
	
	cout<<"\n size of arrays : \n";
	print(sizeArray,s);
	cout<<"\n number of comparison : \n";
	print(noc,s);
	
}
int main(){	
	Heap_Sort<int> obj;
	obj.menu();
	getch();
	return 0;
}

