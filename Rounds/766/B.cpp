#include <bits/stdc++.h>
using namespace std;


void s(int m, int n;)
{
  long long lim = n*m -1;
  int nextMax = 3;
  int dist = 1;
  swap(m,max(m,n));
  for(long long i = 0; i < n*m-1; i++)
  {
    if(dist <= n)
    {
      if(i < nextMax)
      {
        cout << dist;
      }else{
        nextMax += nextMax + 2;
        dist++;
      }
    }else{
      if(dist < m)
      {
        cout << dist;
        dist++;
      }else{
        /* (m-n) * (n-1) rect */
        break;
      }
    }
  }
  /* (m-n) * (n-1) rect */
  /* dist   | dist+1 | dist+2
     dist+1 | dist+2 | dist+N     */
  long long area = (m-n) * (n-1);
  cout << "\n";
}

int main()
{
  int q; cin >> q;
  while(q--)
    s();
}
