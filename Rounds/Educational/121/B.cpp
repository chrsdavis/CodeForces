#include <iostream>
#include <string>
using namespace std;

void solution()
{
  string str; cin >> str;
  int len = static_cast<int>(str.length());
  int pos = -1;
  for(int i = len-2; i >= 0; i--)
  {
    int sum = str[i] + str[i+1]-96;
    if(sum > 9)
    {
      pos = i;
    }
  }
  if(pos == -1)
  {
    int temp = str[len-2] + str[len-1] - 96;
    str[len-2] = (temp % 10) + 48;
    str[len-1] = (temp / 10) + 48;
  }else{
    int temp = str[pos] + str[pos+1] - 96;
    str[pos+1] = (temp % 10) + 48;
    str[pos] = (temp / 10) + 48;
  }
  if(str[0] != 0)
    cout << str[0];
  for(size_t j = 1; j < len; j++)
    cout << str[j];
  cout << "\n";
}

int main()
{
  int q; cin >> q;
  while(q--)
  {
    solution();
  }
  return 0;
}
