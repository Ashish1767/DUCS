#include<iostream>  
#include<conio.h>  
#include<math.h>  
#include<stdlib.h>
#include<iomanip>  
#include<stdio.h> 
#include<graphics.h>    
                                           
using namespace std;                        
                                          
										  
class TwoDim_transformation
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

void TwoDim_transformation::input()
{
	cout<<"ENTER THE NO OF VERTICES\n";  
    cin>>n; 
	
	x=new float*[n];
	for(int i=0;i<n;++i)
		x[i]=new float[3];
    for (int i=0;i<n;i++)  
    {  
        cout<<"ENTER THE "<<i+1<<" COORDINATES \n";  
        cin>>x[i][0]>>x[i][1];
		x[i][2]=1;  
    }  
   
    cout<<"\n\nInput Matrix:-\n";
    for(int i=0;i<n;i++)
	{
	    for(int j=0;j<3;++j)
    		cout<<setw(3)<<x[i][j]<<"  ";
	cout<<"\n";
	}
    cout<<"\n\n";
    
    //Display points on the graph
//    display_graph(n,x);
}

float **TwoDim_transformation::multiplication(float **a,float **b)
{
	float **c;
	c=new float*[n];
	for(int i=0;i<n;++i)
		c[i]=new float[3];
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<3;++j)
		{
			c[i][j]=0;
			for(int k=0;k<3;++k)
			{
				c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	
	return c;
}

void TwoDim_transformation::Translation()
{
	float **t;
	float tx,ty;
	cout<<"\nEnter Translation factor for X axis:\t";
	cin>>tx;
	
	cout<<"\nEnter Translation factor for Y axis:\t";
	cin>>ty;
	
	t=new float*[3];
	for(int i=0;i<3;++i)
		t[i]=new float[3];
		
	for(int i=0;i<3;++i)
		for(int j=0;j<3;++j)
			if(i==j)
				t[i][j]=1;
			else
			t[i][j]=0;
			
	
	t[2][0]=tx;
	t[2][1]=ty;
	
	cout<<"\n\nTranslation Matrix:\n";
	for(int i=0;i<3;i++)
	{
	    for(int j=0;j<3;++j)
    		cout<<setw(3)<<t[i][j]<<"  ";
	cout<<"\n";
	}
	
	float **x1=multiplication(x,t);
	cout<<"\n\nPoints after transformation\n\n";
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<3;++j)
    		cout<<setw(3)<<x1[i][j]<<"  ";
	cout<<"\n";
	}
	
//	display_graph(n,x1);
}
void TwoDim_transformation::Scaling()
{
	float **s;
	int sx,sy;
	cout<<"Enter The Scaling Factor Along X-Axis: ";
	cin>>sx;
	cout<<"Enter The Scaling Factor Along Y-Axis: ";
	cin>>sy;
	
	s=new float*[3];
	for(int i=0;i<3;++i)
		s[i]=new float[3];
		
	for(int i=0;i<3;++i)
		for(int j=0;j<3;++j)
			s[i][j]=0;
			
	s[0][0]=sx;
	s[1][1]=sy;
	s[2][2]=1;
	
	
	cout<<"\n\nScaling Matrix:\n";
	for(int i=0;i<3;i++)
	{
	    for(int j=0;j<3;++j)
    		cout<<setw(3)<<s[i][j]<<"  ";
	cout<<"\n";
	}
	
	float **x1=multiplication(x,s);
	cout<<"\n\n Matrix after Scaling :\n";
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<3;++j)
    		cout<<setw(3)<<x1[i][j]<<"  ";
	cout<<"\n";
	}
	
//	display_graph(n,x1);
}


void TwoDim_transformation::Rotation()
{
	float degree;
	float PI=3.14159;
	float  **r;
	cout<<"\nEnter the degree of rotation: ";
	cin>>degree;
	int choice;
	float theta=(PI*degree)/180;
	
	r=new float*[3];
	for(int i=0;i<3;++i)
		r[i]=new float[3];
		
	for(int i=0;i<3;++i)
		for(int j=0;j<3;++j)
			r[i][j]=0;
			
	cout<<"\n\nChoose the direction of rotation:-";
	cout<<"\n1.Clockwise";
	cout<<"\n2.Anti-Clockwise";
	cout<<"\nEnter your choice:-";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			r[0][0]=(cos(theta));
			r[0][1]=(-sin(theta));
			r[1][0]=(sin(theta));
			r[1][1]=(cos(theta));
			r[2][2]=1;
			break;
			
		case 2:
			r[0][0]=(cos(theta));
			r[0][1]=(sin(theta));
			r[1][0]=(-sin(theta));
			r[1][1]=(cos(theta));
			r[2][2]=1;
			break;
			
	};
	
	cout<<"\n\nRotation Matrix:\n";
	for(int i=0;i<3;i++)
	{
	    for(int j=0;j<3;++j)
    		cout<<fixed<<setw(4)<<fixed<<setprecision(1)<<r[i][j]<<"  ";
	cout<<"\n";
	}
	
	float **x1=multiplication(x,r);
	
	cout<<"\n\n Matrix after Rotation :\n";
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<3;++j)
    		cout<<setw(3)<<x1[i][j]<<"  ";
	cout<<"\n";
	}
//	display_graph(n,x1);	
	
}

void TwoDim_transformation::Reflection()
{
	int choice;
	float **r;
	
	r=new float*[3];
	for(int i=0;i<3;++i)
		r[i]=new float[3];
		
	for(int i=0;i<3;++i)
		for(int j=0;j<3;++j)
			r[i][j]=0;
			
	
	cout<<"\nChoose the line or axis of reflection:-";
	cout<<"\n1.Against X-axis or y=0";
	cout<<"\n2.Against Y-axis or x=0";
	cout<<"\n3.Against y=x line";
	cout<<"\n4.Against y=-x line";
	cout<<"\n5.Against origin";
	cout<<"\nEnter your choice:-";
	cin>>choice;
	
	switch(choice)
	{
	
		case 1:
			r[0][0]=1;
			r[1][1]=-1;
			r[2][2]=1;
			break;
			
		case 2:
			r[0][0]=-1;
			r[1][1]=1;
			r[2][2]=1;
			break;
			
		case 3:
			r[0][1]=1;
			r[1][0]=1;
			r[2][2]=1;
			break;
			
			
		case 4:
			r[0][1]=-1;
			r[1][0]=-1;
			r[2][2]=1;
			break;
			
		case 5:
			r[0][0]=-1;
			r[1][1]=-1;
			r[2][2]=1;
			break;
			
	};
	
	cout<<"\n\nReflection Matrix:\n";
	for(int i=0;i<3;i++)
	{
	    for(int j=0;j<3;++j)
    		cout<<setw(3)<<r[i][j]<<"  ";
	cout<<"\n";
	}
	
	float **x1=multiplication(x,r);
	
	cout<<"\n\n Matrix after Rotation :\n";
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<3;++j)
    		cout<<setw(3)<<x1[i][j]<<"  ";
	cout<<"\n";
	}
	display_graph(n,x1);	
}
void TwoDim_transformation::display_graph(int n,float **c)
{
	float maxx,maxy;
	int i;
	maxx=getmaxx();
	maxy=getmaxy();

	maxx=maxx/2;
	maxy=maxy/2;
	
	i=0;
	while(i<n-1)
	{
		line(maxx+c[i][0],maxy-c[i][1],maxx+c[i+1][0],maxy-c[i+1][1]);
		i++;
	}

	i=n-1;
	line(maxx+c[i][0],maxy-c[i][1],maxx+c[0][0],maxy-c[0][1]);
	setcolor(15);
	line(0,maxy,maxx*2,maxy);
	line(maxx,0,maxx,maxy*2);
	setcolor(WHITE);	
}

int main()
{int gd= DETECT,gm;
    initgraph (&gd, &gm,NULL); 
	TwoDim_transformation a1;
	a1.input();
	int choice;
	
		cout<<"2-D Transformation:-";
		cout<<"\n1.Translation.";
		cout<<"\n2.Scaling.";
		cout<<"\n3.Rotation.";
		cout<<"\n4.Reflection.";
		cout<<"\nEnter your choice:-";
		cin>>choice;
		switch(choice)
		{
			case 1:
					a1.Translation();
					break;
				
			case 2:
					a1.Scaling();
					break;
				
			case 3:
					a1.Rotation();
					break;
				
			case 4:
				a1.Reflection();
				break;
			
			default:
				cout<<"\n\nWrong Choice!!!!\n";
				break;
				
			
		};
	
	getch();
	return 0;
}
