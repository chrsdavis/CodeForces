#include <bits/stdc++.h>
using namespace std;

/*
             #
      [#] -> # #
             #
*/

long long main()
{
  long long n;
  cin >> n;
  char a[n][n];
  for(long long i = 0; i < n; i++)
    for(long long j = 0; j < n; j++)
      cin >> a[i][j];

  for(long long i = 0; i < n; i++)
    for(long long j = 0; j < n; j++)
    {
      if(a[i][j] == '.')
      {
        a[i][j] == '#';

        if( i+1 < n && j<n && a[i+1][j]=='.' )
        {
          a[i+1][j]='#';
        } else
        {
          cout << "NO";
          return 0;
        }

        if( i+1 < n && j+1<n && a[i+1][j+1]=='.' )
        {
          a[i+1][j+1]='#';
        } else
        {
          cout << "NO";
          return 0;
        }

        if( i+1 < n && j-1<n && a[i+1][j-1]=='.' )
        {
          a[i+1][j-1]='#';
        } else
        {
          cout << "NO";
          return 0;
        }

        if( i+2 < n && j<n && a[i+2][j]=='.' )
        {
          a[i+2][j]='#';
        } else
        {
          cout << "NO";
          return 0;
        }

      }
    }

    cout << "YES";


  return 0;
}
