#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <map>

using namespace std;

int main()
{
  int q; cin >> q;
  vector<string> v;
  while(q--)
  {
    string str; cin >> str;
    v.push_back(str);
  }
  for(size_t i = 0; i < v.size(); i++)
  {
    unordered_map<char,int> m;
    for(size_t e = 0; e < v[i].length(); e++)
    {
      m[v[i][e]]++;
    }
    multimap<int, char> mm;
    for (auto& it : m)
    {
        mm.insert({ it.second, it.first });
    }

    for (auto& it : mm)
    {
        for(int i = 0; i < it.first; i++)
          cout << it.second;
    }
    cout << "\n";
  }
  return 0;
}
