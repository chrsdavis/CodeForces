/*
D. Palindromic Twist

You can change a string by changing one letter to the next letter.
I.e. b->a or b->c. You can make k of these changes. See if you can make a
string into a palindrome with these k changes.

Example:
k = 1 (only 1 letter change)
abc -> aba -> palindrome possible
abe -> abd, abf, etc. -> no palindrome possible

Input:
q queries:
  n string length
  s string

*/



#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,q,i;
	char str[100001]; //string
	cin>>q;
	while(q--)
  {
		scanf("%d", &n);
    scanf("%s", str);
		bool f = 1;
		for(i=0; i<n; i++)
			if(abs(str[i]-str[n-i-1])!=2 && str[i]!=str[n-i-1])
				f = 0;
		if(f)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}
