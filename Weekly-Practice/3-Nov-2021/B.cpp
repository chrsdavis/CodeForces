/*
B. Wilbur and Swimming Pool

After making bad dives into swimming pools, Wilbur wants to build a swimming
pool in the shape of a rectangle in his backyard.
He has set up coordinate axes, and he wants the sides of the rectangle to be
parallel to them. Of course, the area of the rectangle must be positive. Wilbur
had all four vertices of the planned pool written on a paper, until his friend
came along and erased some of the vertices.

Now Wilbur is wondering, if the remaining n vertices of the initial rectangle
give enough information to restore the area of the planned swimming pool.

Input
The first line of the input contains a single integer n (1 ≤ n ≤ 4) — the number
 of vertices that were not erased by Wilbur's friend.

Each of the following n lines contains two integers xi and yi
( - 1000 ≤ xi, yi ≤ 1000) —the coordinates of the i-th vertex that remains.
Vertices are given in an arbitrary order.

It's guaranteed that these points are distinct vertices of some rectangle,
that has positive area and which sides are parallel to the coordinate axes.

Output
Print the area of the initial rectangle if it could be uniquely determined by
the points remaining. Otherwise, print  - 1.
*/

#include <stdio.h>
#include <unordered_set>
#include <cmath>

int main()
{
  std::unordered_set<int>xa;
  std::unordered_set<int>ya;
  int n;
  scanf("%d",&n);
  int x,y;
  for(int i = 0; i < n; i++)
  {
    scanf("%d%d",&x,&y);
    xa.insert(x);
    ya.insert(y);

    if(xa.size() == 2 && ya.size() == 2)
      {
        printf("%d", (std::abs((*xa.end()) - (*xa.begin())) * std::abs((*ya.end()) - (*ya.begin())) ) );
        return 0;
      }
  }

    printf("-1");

  return 0;
}
