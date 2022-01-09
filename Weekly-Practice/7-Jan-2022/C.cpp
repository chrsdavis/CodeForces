/*
C. Snacktower

You have to stack n snacks of n sizes, ranging 1 - n. The snacks have to be
stacked in increasing order, so must wait to output until the next lowest value
is received.

Input:
The first line contains single integer n.
The second line contains n integers (1-n) in the order they arrived

Example:
In: n = 5 | 3 5 4 1 2
Out: 5 43 21
In: n = 5 | 5 4 3 1 2
Out: 5 4 3 21

*/


#include <bits/stdc++.h>

using namespace std;

int x[100001];
bool y[100001]; //flag array

int main(){

  int n;
	while((scanf("%d",&n))!=EOF)
  {
		memset(x,0,sizeof(x)); //clear arrays
		memset(y,0,sizeof(y));

		int temp=n;
		for(int i=1; i<=n; i++)
    {
			cin >> x[i];
			y[x[i]] = 1;
			for(/*temp*/; y[temp] == 1; temp--)
			  printf("%d ",temp);
			cout << "\n";
		}
	}
	return 0;
}
