/*
B. Ehab Fails to Be Thanos

You're given an array 𝑎 of length 2𝑛. Is it possible to reorder it in such way
so that the sum of the first n elements isn't equal to the sum of the last 𝑛
elements?

The first line contains an integer (1 < n < 1000), where 2n num elements
The second line contains 2n integers, elements of the array
*/



#include <bits/stdc++.h>

 using  namespace std;
 int main()
 {
    int q;
    int a[2022];
    set<int>s;

    cin >> q;
    q*=2;
    for(int i = 0; i < q; i++)
    {
        cin >> a[i];
        s.insert(a[i]);
    }
    if(s.size() <= 1)
        cout << "-1\n";
    else
    {
      sort(a,a+q);
      for(int i = 0; i < q; i++) cout << a[i] << "  ";
    }
      return  0 ;
}
