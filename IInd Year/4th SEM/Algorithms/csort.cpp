#include<iostream>
#include<cstdlib>
using namespace std;
class count_sort{
	public:
	int n,arr[100],outp[100];
	public:
		void input();
		 void count(int[],int);
		 void output();
};
void count_sort::input(){
	
	cout<<"enter the size of array";
	cin>>n;
	
	for(int j=1;j<=n;j++){
	cout<<"enter the "<<j<<"th element";cin>>arr[j];
	}count(arr,n);
}
void count_sort::count(int arr[], int n){
	int max=0;
	for(int i=1;i<=n;i++)
{
if(max<arr[i])
max=arr[i];	
}

int temp[max];
for(int i=0;i<=max;i++){

temp[i]=0;
}
for(int i=1;i<=n;i++){

temp[arr[i]]=temp[arr[i]]+1;
}
for(int i=1;i<=max;i++){

temp[i]=temp[i]+temp[i-1];
}
outp[n];
for(int i=n;i>=1;i--){

    outp[temp[arr[i]]]=arr[i];
    temp[arr[i]]=temp[arr[i]]-1;
}}

     void count_sort::output(){
	  for(int i=1;i<=n;i++){
	  	
		  cout<<outp[i]<<"  ";
	  }
	 }
	 int main(){
	 	count_sort obj;
		 obj.input();
		 obj.output();
		 return 0;
	 }
	 
