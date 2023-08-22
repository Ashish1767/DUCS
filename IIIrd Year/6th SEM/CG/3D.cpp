#include<iostream>  
#include<conio.h>  
#include<math.h>  
#include<stdlib.h>
#include<iomanip>  
#include<stdio.h> 
#include<graphics.h>

using namespace std;

class ThreeDim_transformation
{
	int n;
	float **x;
	public:
		void input();
		void Translation();
		float **multiplication(float **a, float **b);    
		void Scaling();
		void Rotation();
		void Reflection(); 
		void display_graph(int,float**); 
};

void ThreeDim_transformation::input()
{
	cout<<"ENTER THE NO OF VERTICES\n";  
    cin>>n; 
	
	x=new float*[n];
	for(int i=0;i<n;i++)
		x[i]=new float[4];
    for (int i=0;i<n;i++)  
    {  
        cout<<"ENTER THE "<<i+1<<" COORDINATES \n";  
        cin>>x[i][0]>>x[i][1]>>x[i][2];
		x[i][3]=1; 
		 
    }  
   
    cout<<"\n\nInput Matrix:-\n";
    for(int i=0;i<n;i++)
	{   
	    for(int j=0;j<4;j++) {
		
	    	x[3][j]=1;
    		cout<<setw(3)<<x[i][j]<<"  ";
    }
	cout<<"\n";
	}
    cout<<"\n\n"; 
    
    //Display points on the graph
   // display_graph(n,x);
}

void ThreeDim_transformation::Scaling()
{
	float **s;
	int sx,sy,sz;
	cout<<"Enter The Scaling Factor Along X-Axis: ";
	cin>>sx;
	cout<<"Enter The Scaling Factor Along Y-Axis: ";
	cin>>sy;
	cout<<"Enter The Scaling Factor Along Y-Axis: ";
	cin>>sz;
		
	s=new float*[4];
	for(int i=0;i<4;++i)
		s[i]=new float[3];
		
	for(int i=0;i<4;++i)
		for(int j=0;j<4;++j)
			s[i][j]=0;
			
	s[0][0]=sx;
	s[1][1]=sy;
	s[2][2]=sz;
	s[3][3]=1;
	
	
	cout<<"\n\nScaling Matrix:\n";
	for(int i=0;i<4;i++)
	{
	    for(int j=0;j<4;++j)
    		cout<<setw(3)<<s[i][j]<<"  ";
	cout<<"\n";
	}
	
	float **x1=multiplication(x,s);
	cout<<"\n\n Matrix after Scaling :\n";
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<4;++j)
    		cout<<setw(3)<<x1[i][j]<<"  ";
	cout<<"\n";
	}
	
	display_graph(n,x1);
}


int main()
{
	int gd=DETECT,gm;  
    initgraph (&gd, &gm, ""); 
	ThreeDim_transformation a1;
	a1.input();
}

