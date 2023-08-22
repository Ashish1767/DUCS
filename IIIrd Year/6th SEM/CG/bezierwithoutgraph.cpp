#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void bezier(int x[4], int y[4])
{
  for (double t = 0.0; t < 1.0; t += 0.00005)
  {
    double xt = pow(1 - t, 3) * x[0] + 3 * t * pow(1 - t, 2) * x[1] + 3 * pow(t, 2) * (1 - t) * x[2] + pow(t, 3) * x[3];
    double yt = pow(1 - t, 3) * y[0] + 3 * t * pow(1 - t, 2) * y[1] + 3 * pow(t, 2) * (1 - t) * y[2] + pow(t, 3) * y[3];
    cout << "(" << xt << ", " << yt << ")" << endl;
  }

  for (int i = 0; i < 4; i++)
  {
    cout << "Point " << i + 1 << ": (" << x[i] << ", " << y[i] << ")" << endl;
  }

  return ;
}

int main()
{
  int i;
  int x[4], y[4];

  for (i = 0; i < 4; i++)
  {
    cout << "Enter Point " << i + 1 << " (x, y): ";
    cin >> x[i] >> y[i];
  }

  bezier(x, y);
  return 0;
}

