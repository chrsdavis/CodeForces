/*
A. There Are Two Types Of Burgers

There are two types of burgers in your restaurant — hamburgers and chicken
burgers! To assemble a hamburger you need two buns and a beef patty. To
assemble a chicken burger you need two buns and a chicken cutlet.

You have 𝑏 buns, 𝑝 beef patties and 𝑓 chicken cutlets in your restaurant. You
can sell one hamburger for h dollars and one chicken burger for c dollars.
Calculate the maximum profit you can achieve.

https://codeforces.com/problemset/problem/1207/A
*/





#include <bits/stdc++>
using namespace std;
int main()
{
  int q; cin >> q;
  int b, p, f, h, c;
  int price =  0;

  for(int i = 0; i < q; i++)
  {
    cin >> b >> p >> f;
    cin >> h >> c;
    b /= 2;

    if(h > c)
    {
      if(b >= p)
        price+= p*h;
      else
        price+= b*h;
      b -= p;
    }else{
      if(b >= f)
        price+= f*c;
      else
        price+= b*c;
      b -= f;

      if(b > 0)

    }



    printf("%d\n",price);
  }

  return 0;
}
