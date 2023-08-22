

#define _USE_MATH_DEFINES
#include <conio.h>
#include <graphics.h>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define COORD_SHIFT 100
using namespace std;
double **inputFigure(int n)
{
  cout << "Enter the matrix for the 3-D shape (homogeneous):\n";

  double **figure = NULL;
  figure = new double *[n];

  for (int i = 0; i < n; i++)
  {
    figure[i] = new double[4];
    for (int j = 0; j < 4; j++)
    {
      cin >> figure[i][j];
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      cout << figure[i][j]<<" ";
      
    }
    cout<<"\n";
   
  }
  

  return figure;
}

double **translate(double **figure, int dim, int l, int m, int n)
{
  double **_figure = NULL;
  int T[dim][4] = {{1, 0, 0, 0},
                   {0, 1, 0, 0},
                   {0, 0, 1, 0},
                   {l, m, n, 1}};

  _figure = new double *[dim];

  for (int i = 0; i < dim; i++)
  {
    _figure[i] = new double[4];
    for (int j = 0; j < 4; j++)
    {
      for (int k = 0; k < dim; k++)
      {
        _figure[i][j] += figure[i][k] * T[k][j];
      }
    }
  }

  return _figure;
}

double **rotate(double **figure, int dim, double theta)
{
  double **_figure = NULL;
  double T[dim][3] = {{cos(theta * M_PI / 180.0), sin(theta * M_PI / 180.0), 0},
                      {-sin(theta * M_PI / 180.0), cos(theta * M_PI / 180.0), 0},
                      {0, 0, 1}};

  _figure = new double *[dim];

  for (int i = 0; i < dim; i++)
  {
    _figure[i] = new double[3];
    for (int j = 0; j < 2; j++)
    {
      for (int k = 0; k < dim; k++)
      {
        _figure[i][j] += figure[i][k] * T[k][j];
      }
    }
  }

  return _figure;
}

double **scale(double **figure, int dim, double l, double m, double n)
{
  double **_figure = NULL;
  double T[dim][4] = {{l, 0, 0, 0},
                      {0, m, 0, 0},
                      {0, 0, n, 0},
                      {0, 0, 0, 1}};

  _figure = new double *[dim];

  for (int i = 0; i < dim; i++)
  {
    _figure[i] = new double[4];
    for (int j = 0; j < 4; j++)
    {
      for (int k = 0; k < dim; k++)
      {
        _figure[i][j] += figure[i][k] * T[k][j];
      }
    }
  }

  return _figure;
}

double **scale(double **figure, int dim, double s)
{
  double **_figure = NULL;
  double T[dim][4] = {{1, 0, 0, 0},
                      {0, 1, 0, 0},
                      {0, 0, 1, 0},
                      {0, 0, 0, s}};

  _figure = new double *[dim];

  for (int i = 0; i < dim; i++)
  {
    _figure[i] = new double[4];
    for (int j = 0; j < 4; j++)
    {
      for (int k = 0; k < dim; k++)
      {
        _figure[i][j] += figure[i][k] * T[k][j];
      }
    }
  }

  return _figure;
}

double **reflect(double **figure, int dim, int c)
{
  double **_figure = NULL;
  int T[dim][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

  switch (c)
  {
  case 1:
    T[1][1] = -1;
    break;
  case 2:
    T[0][0] = -1;
    break;
  case 3:
    T[0][0] = 0;
    T[0][1] = 1;
    T[1][0] = 1;
    T[1][1] = 0;
    break;
  case 4:
    T[0][0] = -1;
    T[1][1] = -1;
    break;
  default:
    return NULL;
    break;
  }

  _figure = new double *[dim];

  for (int i = 0; i < dim; i++)
  {
    _figure[i] = new double[3];
    for (int j = 0; j < 3; j++)
    {
      for (int k = 0; k < dim; k++)
      {
        _figure[i][j] += figure[i][k] * T[k][j];
      }
    }
  }

  return _figure;
}

double **shear(double **figure, int dim, int m, int n)
{
  double **_figure = NULL;
  int T[dim][3] = {{1, n, 0}, {m, 1, 0}, {0, 0, 1}};

  _figure = new double *[dim];

  for (int i = 0; i < dim; i++)
  {
    _figure[i] = new double[3];
    for (int j = 0; j < 3; j++)
    {
      for (int k = 0; k < dim; k++)
      {
        _figure[i][j] += figure[i][k] * T[k][j];
      }
    }
  }

  return _figure;
}

double **project(double **figure, int dim, int p)
{
  double **_figure = NULL;
  int P[dim][4] = {{1, 0, 0, 0},
                   {0, 1, 0, 0},
                   {0, 0, 1, 0},
                   {0, 0, 0, 1}};

  switch (p)
  {
  case 1:
    P[2][2] = 0;
    break;
  case 2:
    P[1][1] = 0;
    break;
  case 3:
    P[0][0] = 0;
    break;
  }

  _figure = new double *[dim];

  for (int i = 0; i < dim; i++)
  {
    _figure[i] = new double[4];
    for (int j = 0; j < 4; j++)
    {
      for (int k = 0; k < dim; k++)
      {
        _figure[i][j] += figure[i][k] * P[k][j];
      }
    }
  }

  return _figure;
}

void menu(double **figure, int dim)
{
  int ch = 0;
  double l, m, n, p;
  double **_figure, **_projected;

  do
  {
   
    cout << "\nMenu\n-------\n(1) Translation\n(2) Rotation";
    cout << "\n(3) Scaling\n(4) Reflection\n(5) Shearing";
    cout << "\n(6) View Figure\n(7) Exit\n\nEnter Choice: ";
    cin >> ch;
    cout << endl;
    switch (ch)
    {
    case 1:

      cout << "Enter translation in x-axis: ";
      cin >> l;
      cout << "Enter translation in y-axis: ";
      cin >> m;
      cout << "Enter translation in z-axis: ";
      cin >> n;

      _figure = translate(figure, dim, l, m, n);

      cout << "\nChoose Projection:\n(1) xy-plane\n(2) xz-plane\n(3) yz-plane\n"
           << "\nEnter Choice: ";
      cin >> p;

      if (p > 3 || p < 1)
      {
        cout << "\nInvalid Projection!";
        cin.ignore();
        cin.get();
        continue;
      }

      
      break;
     case 2:
       double theta;

       cout << "Enter rotation angle (degrees): ";
       cin >> theta;

       _figure = rotate(figure, dim, theta);

      
       break;
    case 3:
      int scalingCh;
      cout << "Scaling:\n(1) Overall Scaling\n(2) Local Scaling\n\nEnter Choice: ";
      cin >> scalingCh;

      switch (scalingCh)
      {
      case 1:
        cout << "Enter scaling factor: ";
        cin >> l;
        _figure = scale(figure, dim, l);
        break;

      case 2:
        cout << "Enter scaling in x-axis: ";
        cin >> l;
        cout << "Enter scaling in y-axis: ";
        cin >> m;
        cout << "Enter scaling in z-axis: ";
        cin >> n;
        _figure = scale(figure, dim, l, m, n);
        break;
      }

   
      break;
     case 4:
       cout << "Reflect along\n(1) x-axis\n(2) y-axis\n(3) y = x\n(4) y = -x\n"
           << "\nEnter Choice: ";
       cin >> m;

       _figure = reflect(figure, dim, m);

       
       break;
     case 5:
       cout << "Enter shearing in x-axis: ";
       cin >> m;
       cout << "Enter shearing in y-axis: ";
      cin >> n;

       _figure = shear(figure, dim, m, n);

      break;
    case 6:

      cout << "\nChoose Projection:\n(1) xy-plane\n(2) xz-plane\n(3) yz-plane\n"
           << "\nEnter Choice: ";
      cin >> p;

      if (p > 3 || p < 1)
      {
        cout << "\nInvalid Projection!";
        cin.ignore();
        cin.get();
        continue;
      }

     
    case 7:
    default:
    break;
    }

   
    }
   while (ch != 7);
};

int main()
{
  int n;
  double **fig;

  cout << "Enter number of points in the figure: ";
  cin >> n;

  fig = inputFigure(n);

  menu(fig, n);

 
  return 0;
}
