#include<iostream>
#include<cstdlib>
using namespace std;
class counting_sort{
	public:
		int n ,arr[100],out[100];
	public:
		void input();
		void counting(int[],int);
		void output();
	
};
void counting_sort::input(){
		cout<<"Enter the size of array :";
		cin>>n;
		cout<<"Enter the elements :";
		for(int j=1;j<=n;j++)
		{
			cin>>arr[j];
		}
		counting(arr,n);
}
void counting_sort::counting(int arr[],int n)
{
	int max=0;
	for(int i=1;i<=n;i++)
	{
		if(max<arr[i])
		max=arr[i];
	}
	int temp[max];
	for(int i=0;i<=max;i++)
	{
		temp[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		temp[arr[i]]=temp[arr[i]]+1;
	}
	
	for(int i=1;i<=max;i++)
	{
		temp[i]=temp[i]+temp[i-1];
	}
	out[n];
	for(int i=n;i>=1;i--)
	{
		out[temp[arr[i]]]=arr[i];
		temp[arr[i]]=temp[arr[i]]-1;
	}
}
void counting_sort::output()
{
	cout<<"Sorted array :";
	for(int i=1;i<=n;i++)
	{
		cout<<out[i]<<" ";
	}
}
int main(){
	counting_sort obj;
	obj.input();
	obj.output();
	return 0;
}