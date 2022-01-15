#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n; cin >> n;
  int sum = n * (n+1) / 2;
  for(int i = 0; i < n; i++)
  {
    cin >> x;
    sum -= x;
  }

  printf("%d", sum);


  return 0;
}
