#include <bits/stdc++.h>

using namespace std;



int main()
{
  string str; cin >> str;

  long long a[str.length()+1];
  a[0] = 1;
  a[1] = a[0];

  for(int i = 0; i < str.length(); i++)
    if(s[i] == 'w' || s[i] == 'm')
    {
      cout << 0;
      return 0;
    }

  for(int i = 1; i < str.length(); i++)
  {
    if(str[i] == str[i-1] && (s[i] == 'u' || s[i] == 'n'))
    {
      a[i+1] = (a[i] + a[i-1]) % 1e9+7;
    }else{
      a[i+1] = a[i]; /* keep the same */
    }
  }

  cout << a[str.length()] % 1e9+7;

  return 0;

}




/*
int main()
{
  long long point = 0;
  string str;
  cin >> str;

  for(int i = 0; i < str.size(); i++)
  {
    if(str[i] == 'w' || str[i] == 'm')
    {
      cout << 0;
      return 0;
    }

    if(str[i] == 'u' || str[i] == 'n')
    {
      //consecutive letters
      int e = i + 1;
      while(e < str.size() -1 && str[i] == str[e])
        e++;
      point += e-1;
    }
  }

  long double ans = powl(2, (long double)point)

  if(ans > (1e9+7))
      return (long long)ans % (10e9+7);
    return ans;


  return 0;
}

*/
