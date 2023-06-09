#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
class RadixSort
{
		int *a;
		string *arr;
		int size,len;
		
		public:

		void countsort(int*,int,int);
		void getdata();
		int getmax();
		void radixsort();
		void display();
		
		
};
int RadixSort::getmax()
{
	int max=a[0];
	for(int i=1;i<size;++i)
		if(a[i]>max)
			max=a[i];
	return max;
}

void RadixSort::getdata()
{
	cout<<"\nSize of the array:-";
	cin>>size;
	a=new int[size];
	cout<<"\nEnter the array:-";
	for(int i=0;i<size;++i)
		cin>>a[i];
}

void RadixSort::countsort(int *array,int size,int place)
{
	const int max = 10;
  int output[size];
  int count[max];

  for (int i = 0; i < max; ++i)
    count[i] = 0;
 
  for (int i = 0; i < size; i++)
    count[(array[i] / place) % 10]++;

  
  for (int i = 1; i < max; i++)
    count[i] += count[i - 1];

 
  for (int i = size - 1; i >= 0; i--) {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
    array[i] = output[i];
	
}


void RadixSort::radixsort()
{	
	int max=getmax();

	for(int place=1;max/place>0;place*=10)
	{
			countsort(a,size,place);
		
	}	
}

void RadixSort::display()
{
		for(int i=0;i<size;++i)
 		cout<<a[i]<<"  ";
}

int main()
{
	
	RadixSort r1;
		    r1.getdata();
			cout<<"\nOriginal array:-";
			r1.display();
			r1.radixsort();
			cout<<"\n\nSorted array:-";
			r1.display();
			
	getch();
return 0;

}

		
/*		void countsort_string(string*,int,int);
		void getdata_string();
		int getmax_string();
		void radixsort_string();
		void display_string();	
*/

/*


void RadixSort::display_string()
{
		for(int i=0;i<size;++i)
		cout<<arr[i]<<"  ";
}

void RadixSort::getdata_string()
{
//	int len;
	cout<<"\nSize of the array:-";
	cin>>size;
	cout<<"\nEnter the length of each string:-";
	cin>>len;
	arr=new string[size];
	cout<<"\nEnter the array of string:-";
	for(int i=0;i<size;++i)
		cin>>arr[i];
		
}

void RadixSort::countsort_string(string *a,int n,int k)
{
	string output[size];
	int count[257];
	
	for(int i=0;i<257;++i)
		count[i]=0;
		
	// Calculate count of elements
	for(int i=0; i<n; i++)
		count[(int)(char)a[i][k]]++;
		
		//calculating cumulative count
	for(int i=1; i<257; i++)	
		count[i]+=count[i-1];
    
	
	for(int i=n-1; i>=0; i--)
	{
		output[count[(int)(char)a[i][k]]-1] = a[i];
		count[(int)(char)a[i][k]]--;
		
	}
	
		for(int i=0; i<n; i++)
		a[i] = output[i];
}

int RadixSort::getmax_string()
{
	int max=arr[0].size();
	for(int i=1;i<size;++i)
		if(arr[i].size()>max)
				max=arr[i].size();
				
	return max;
}

void RadixSort::radixsort_string()
{

	for(int i=len-1;i>=0;--i)
		countsort_string(arr,size,i);
}


*/
//	int choice;
	//cout<<"\n\nInteger";
	//cout<<"\nString";
	//cout<<"\nEnter your choice:-";
	//cin>>choice;
	
	//switch(choice)
	//{
	//	case 1:
		
			//break;
			
	/*	case 2:
			r1.getdata_string();
			cout<<"\nOriginal array:-";
		//	r1.display_string();
		//	r1.radixsort_string();
			cout<<"\n\nSorted array:-";
			r1.display_string();
			break;
			
		default:
			cout<<"\nINVALID CHOICE!!!";
			break;
	}*/

