/*
C. Simple Polygon Embedding
The statement of this problem is the same as the statement of problem C2.
The only difference is that, in problem C1, n is always even, and in C2, n
 is always odd.
 You are given a regular polygon with 2⋅𝑛

Find minimum length of square that encloses 2*n sided regular polygon.
*/

#include <tgmath.h>
#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

const double p = std::acos(-1.0);
const double rads = p / 180.0;

int main()
{

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int x;
  scanf("%d",&x);
  int a;
  while(--x)
  {
    scanf("%d",&a);
    std::cout << std::fixed << std::setprecision(9) << 1.0/tan(90.0/x*rads) << "\n";
  }

  return 0;
}
