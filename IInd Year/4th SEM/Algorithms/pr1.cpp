#include<iostream>
#include<cstdlib>
using namespace std;
class pr1{
	int n,array[400];
	public:
		void inp();
		void insert_sort();
		void selection_sort();
		void bubble_sort();
		void disp();
};
void pr1::inp(){
	cout<<"Enter the no. of elements :";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		array[i]=rand()%100;
	}
}
void pr1::disp(){
	cout<<"Random generated array  is : ";
	for(int i=0;i<n;i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
}
void pr1::insert_sort(){
	int key,count=0;
	for(int i=1;i<n;i++)
	{
		key=array[i];
		int j=i-1;
		if(i>1)
		count++;
		while(j>=0 && array[j]>key)
		{
			array[j+1]=array[j];
			count++;
			j=j-1;
		}
		array[j+1]=key;
		count++;
	}
	cout<<"\nArray after sorting(insert_sort) :";
	for(int i=0;i<n;i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
	cout<<"Total number of comparisions are :"<<count<<endl;
}
void pr1::selection_sort(){
	int min,temp,count=0;
	for(int i=0;i<n;i++)
	{
		min=i;
		temp=array[i];
		for(int j=i+1;j<n;j++)
		{
			count++;
			if(array[j]<temp)
			{
				min=j;
				temp=array[j];
			}
		}
		int m=array[i];
		array[i]=array[min];
		array[min]=m;
	}
	cout<<"\nArray after sorting(selection_sort) :";
	for(int i=0;i<n;i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
	cout<<"Total number of comparisions are :"<<count<<endl;	
}
void pr1::bubble_sort(){
	int temp,count=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			count++;
			if(array[j]>array[j+1])
			{
				temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
			}
		}
	}
	cout<<"\nArray after sorting(bubble_sort) :";
	for(int i=0;i<n;i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
	cout<<"Total number of comparisions are :"<<count<<endl;
}
int main()
{
	char ch;
	do{
		pr1 obj;
		obj.inp();
		obj.disp();
		obj.insert_sort();
		obj.selection_sort();
		obj.bubble_sort();
		cout<<"\n\nDo you want to continue(press y to continue and n to terminate) :";
		cin>>ch;
	}while(ch=='y' || ch=='Y');
	
}
