#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<time.h>
using namespace std;
class sorting
{
private:
    /* data */
    int n;
    int *arr;
public:
int insertionSort(int arr[], int n)  {  
    int i, key, j,count=0;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
        while (j >= 0 && arr[j] > key && ++count) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
    return count;
	}
	int bubbleSort(int arr[], int n) {  
	int count=0;
    for (int i = 0; i < n-1; i++)     
    for (int j = 0; j < n-i-1; j++)  {
		count++;
        if (arr[j] > arr[j+1])  
          {
          	int temp=arr[j];
          	arr[j]=arr[j+1];
          	arr[j+1]=temp;	
		 }  
	}
	return count;
    }   
    int selectionSort(int arr[], int n)  
	{  
    int least,temp,count=0;  
    for (int i = 0; i < n-1; i++)  
    {  
        least= i;  
        for (int j = i+1; j < n; j++) 
		{ 
		count++;
        if (arr[j] < arr[least])  
            least= j;  
        }
        if(i!=least){
        temp=arr[least];
		arr[least]=arr[i];
		arr[i]=temp; 
		}
    }  
    return count;
}  
  
    void print(int *arr,int n){
        for(int i=0;i<n;i++){
        if(i%10==0)
        cout<<"\n";
        cout<<arr[i]<<" ";
    }}
};
int main(){
	srand((unsigned)time(0));
    sorting s;
    int n;
    int size[10],insert_count[10],select_count[10],bubble_count[10];
    for(int j=0;j<2;j++)
    {
    n=(rand()%(50+1-20)+20);
    size[j]=n;
    int *arr=new int[n];
    int *arr1=new int[n];
    int *arr2=new int[n];
    cout<<"Enter "<<n<<" values"<<endl;
    for(int k=0;k<n;k++)
    {
    	cin>>arr[k];
    	arr1[k]=arr[k];
    	arr2[k]=arr[k];
	}
	cout<<endl<<endl;
	int c1=s.insertionSort(arr,n);
	insert_count[j]=c1;
	int c2=s.bubbleSort(arr1,n);
	select_count[j]=c2;
	int c3=s.selectionSort(arr2,n);
	bubble_count[j]=c3;
	}
    
    for(int i=2;i<10;i++)
    {
    n=(rand()%(50+1-20)+20);
    size[i]=n;
    int *arr=new int[n];
    int *arr1=new int[n];
    int *arr2=new int[n];
    for(int j=0;j<n;j++)
    {
    	arr[j]=rand();
    	arr1[j]=arr[j];
    	arr2[j]=arr[j];
	}
	cout<<endl<<endl;
	insert_count[i]=s.insertionSort(arr,n);
	select_count[i]=s.bubbleSort(arr1,n);
	bubble_count[i]=s.selectionSort(arr2,n);
	}
	cout<<"\n\n\n";
	cout<<"[";
	for(int i=0;i<10;i++)
	{
		cout<<size[i]<<",";
	}
	cout<<"]";
	cout<<"\n\n\n";
	cout<<"[";
	for(int i=0;i<10;i++)
	{
		cout<<insert_count[i]<<",";
	}
	cout<<"]";
	cout<<endl<<endl;
	cout<<endl;
	cout<<"[";
	for(int i=0;i<10;i++)
	{
		cout<<select_count[i]<<",";
	}
	cout<<"]";
	cout<<endl<<endl;
	cout<<endl;
	cout<<"[";
	for(int i=0;i<10;i++)
	{
		cout<<bubble_count[i]<<",";
	}
	cout<<"]";
	
   getch();
   return 0;
}

