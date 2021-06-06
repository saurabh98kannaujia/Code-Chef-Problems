#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	while(n--)
	{
	    int x,y,a,b;
	    cin>>x>>y>>a>>b;
	    int count=0;
	    count = count + a/x +b/y;
	    cout<<count<<"\n";
	}
	
	return 0;
}
