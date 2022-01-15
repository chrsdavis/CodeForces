#include <bits/stdc++.h>

using namespace std;

void s()
{
  bool flag = true;
  int r,c,rx,cy;
  cin >> r;
  cin >> c;
  cin >> rx;
  cin >> cy;
  char a[55][55];

  for(int i = 0; i < r; i++)
  {
    for(int j = 0; j < c; j++)
    {
      cin >> a[i][j];

      if(a[i][j] == 'B')
        flag = false;
    }
  }

  if(a[rx-1][cy-1] == 'B')
  {
    cout << 0 << endl;
    return;
  }

  if(flag)
  {
    cout << -1 << endl;
    return;
  }

  bool col = false;
  bool row = false;

  for(int i = 0; i < r; i++)
  {
    if(a[i][cy-1] == 'B')
    {
      cout << 1 << endl;
      return;
    }
  }
  for(int i = 0; i < c; i++)
  {
    if(a[rx-1][i] == 'B')
    {
      cout << 1 << endl;
      return;
    }
  }

  cout << 2 << endl;
  return;
}

int main()
{
  int q; cin >> q;
  while(q--)
  {
    s();
  }

  return 0;
}
