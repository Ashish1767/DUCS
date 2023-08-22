#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

class three_dim_transform{
	int n,i,j;
	int **arr;
	public:
	void input();
	void multiplication();
	void transform();
	void scaling();
	void rotation();
};
void three_dim_transform::input(){
	
cout<<"enter the size of the matrix:-";
cin>>n;
arr= new int*[n];
for(i=0;i<n;i++){
	arr[i]= new int[4];
}
cout<<" enter the vertices of the matrix:-";
for(i=0;i<n-1;i++){
    for(int j=0;j<n-1;j++){

		cin>>arr[i][j]                 a b c 1
		                             d e f 1
		                             g h i 1
		                }            1 1 1 1
		
		

	
}
for(i=0;i<n;i++){
	for(int j=0;j<n;j++){
		cout<<arr[i][j]<<" ";
	                    }
	cout<<endl;
               }
}
int main(){

three_dim_transform a1;
a1.input();



return 0;
}
