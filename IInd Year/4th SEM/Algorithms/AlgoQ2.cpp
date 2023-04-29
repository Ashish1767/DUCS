/*Implement Bubble, selection, insertion, merge, quick sort. And count the number of comparisons in each case. 
For each algorithm, test run the algorithm on 100 different inputs of sizes varying from 30 to 1000. 
Count the number of comparisons and draw the graph.
*/

#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

template<class T>
class sort{
	public:
		int size;
		int count; //to count the number of comparisons performed
		T *arr1;	//array for insertion sort
		T *arr2;	//array for selection sort 
		T *arr3;	//array for bubble sort
		T *arr4;	//array for merge sort
		int *arrofSizes;	//array for the random sizes generated
		int *comp1,*comp2,*comp3, *comp4;	//arrays for numbers of comparisons in each case
		int x,index1,index2,index3,index4;	//

		sort(){
			arrofSizes=new int[10];
			
			comp1=new int[15];	//for insertion sort
			comp2=new int[15];	//for selection sort
			comp3=new int[15];	//for bubble sort
			comp4=new int[15];	//for merge sort
			
			size=0;
			x=0;	//x used for storing values in arrofSizes
			
			//for storing values in arrays comp1,comp2,comp3
			index1=0;
			index2=0;
			index3=0; 
			index4=0;
			
			count=0;	//counting the number of comparisons
		}
		void getdata();
		void insertionSort();
		void swap(T &a,T &b);
		void selectionSort();
		void bubbleSort();
		void mergeSort(int arr[],int p,int r);
		void merge(int arr[],int p,int q,int r);
		void showdata();
		
		void tempsort();	//used to sort within the program, to set the data to best case & worst case
};

template<class T>
void sort<T>::getdata(){
	//random size
//	size=(rand()%31)+20;	//size between 20 to 50
	
	size+=10;
	
	arr1=new T[size];
	arr2=new T[size];
	arr3=new T[size];
	arr4=new T[size];
	
	//giving random array elements
	for(int i=0;i<size;i++){
		arr1[i]=rand()%100;	//random array element is >=0 && <100
		arr2[i]=arr1[i];
		arr3[i]=arr1[i];
		arr4[i]=arr1[i];
	}
	
	//setting data for best and worst case
	if(x==0 || x==14){
		//sorting the data
		tempsort();
		if(x==14){
			for(int i=0,j=size-1;i<=size/2;i++,j--){
				swap(arr1[i],arr1[j]);
				swap(arr2[i],arr2[j]);
				swap(arr3[i],arr3[j]);
				swap(arr4[i],arr4[j]);
			}
		}
	}
	//storing sizes
	arrofSizes[x++]=size;
}

template<class T>
void sort<T>::swap(T &a, T &b){
	T temp=a;
	a=b;
	b=temp;
}

template<class T>
void sort<T>:: tempsort(){
	for(int i=1,j;i<size;i++){
		T temp=arr1[i];
		for(j=i;j>0 && temp<arr1[j-1];j--)
			arr1[j]=arr1[j-1];
		arr1[j]=temp;
	}
	for(int i=0;i<size;i++){
		arr2[i]=arr1[i];
		arr3[i]=arr1[i];
	}
}

template<class T>
void sort<T>:: insertionSort(){
	count=0;
	for(int i=1,j;i<size;i++){
		T temp=arr1[i];
		for(j=i;j>0 && ++count && temp<arr1[j-1];j--){
			arr1[j]=arr1[j-1];
		}
		arr1[j]=temp;
	}
//	cout<<"\nNo. of comparisons performed: "<<count<<endl;
	comp1[index1++]=count;
}

template<class T>
void sort<T>:: selectionSort(){
	count=0;
	int least;
	for(int i=0;i<size-1;i++){
		least=i;
		for(int j=i+1;j<size;j++)
		 	if(++count && arr2[j]<arr2[least])
		 		least=j;
		swap(arr2[least],arr2[i]);
	}
//	cout<<"\nNo. of comparisons performed: "<<count<<endl;
	comp2[index2++]=count;
}

template<class T>
void sort<T>:: bubbleSort(){
	count=0;
	for(int i=0;i<size-1;i++){
		for(int j=size-1;j>i;j--)
			if(++count && arr3[j]<arr3[j-1])
				swap(arr3[j],arr3[j-1]);
	}
//	cout<<"\nNo. of comparisons performed: "<<count<<endl;
	comp3[index3++]=count;
}

template<class T>
void sort<T>:: mergeSort(int arr4[],int p,int r){
	if(p<r){
		int q=((p+r)/2);
		mergeSort(arr4,p,q);
		mergeSort(arr4,q+1,r);
		merge(arr4,p,q,r);
	}
}

template<class T>
void sort<T>:: merge(int arr4[],int p,int q,int r){
	int n1 = q-p+1;
	int n2 = r-q;
	
	int *L=new int[n1];
	int *R=new int[n2];
	
	for(int i=0;i<n1;i++)
		L[i]=arr4[p+i];
	
	for(int j=0;j<n2;j++)
		R[j]=arr4[q+1+j];
	
//	L[n1]=2^31-1; //or 2 147 483 647 
//	R[n2]=2^31-1; //or 2 147 483 647
	
	int i=0,j=0,k=p;
	while(i<n1 && j<n2){
		if(++count && L[i]<=R[j])
			arr4[k++]=L[i++];
		
		else
			arr4[k++]=R[j++];
	}
	
	//copying the values of the leftover elements of the other array
	if(i==n1){
		while(j!=n2)
		arr4[k++]=R[j++];
	}
	if(j==n2){
		while(i!=n1)
		arr4[k++]=L[i++];
	}
}

template<class T>
void sort<T>::showdata(){
	cout<<"\nARRAY OF SIZES:\n";
	for(int i=0;i<15;i++)
	cout<<arrofSizes[i]<<",";
	
	cout<<"\n\nINSERTION SORT:\n";
	for(int i=0;i<15;i++)
	cout<<comp1[i]<<",";
	
	cout<<"\n\nSELECTION SORT:\n";
	for(int i=0;i<15;i++)
	cout<<comp2[i]<<",";
	
	cout<<"\n\nBUBBLE SORT:\n";
	for(int i=0;i<15;i++)
	cout<<comp3[i]<<",";
	
	cout<<"\n\nMERGE SORT:\n";
	for(int i=0;i<15;i++)
	cout<<comp4[i]<<",";
}


int main(){
	cout<<"**SORTING TECHNIQUES**\n";
	srand(time(NULL)); // randomize seed	
	sort<int>ob;
	
	for(int i=0;i<15;i++){
//		cout<<"\n\n------------------------------------\n";
		ob.getdata();
		
//		cout<<"\nINSERTION SORT:";
		ob.insertionSort();
		
//		cout<<"\nSELECTION SORT:";
		ob.selectionSort();
		
//		cout<<"\nBUBBLE SORT:";
		ob.bubbleSort();
		
//		count<<"\nMERGE SORT:";
		ob.count=0;
		ob.mergeSort(ob.arr4,0,ob.size-1);
		ob.comp4[ob.index4++]=ob.count;
	}
	
	ob.showdata();
	getch();
	return 0;
}

/*

**SORTING TECHNIQUES**

ARRAY OF SIZES:
10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,

INSERTION SORT:
9,132,207,370,618,886,1303,1576,2202,2413,3372,3615,3786,5341,11130,

SELECTION SORT:
45,190,435,780,1225,1770,2415,3160,4005,4950,5995,7140,8385,9730,11175,

BUBBLE SORT:
45,190,435,780,1225,1770,2415,3160,4005,4950,5995,7140,8385,9730,11175,

MERGE SORT:
22,63,110,168,219,280,340,403,479,550,613,683,743,830,902,

*/
