/*
There are N cities in Chefland numbered from 1 to N and every city has a railway station. 
Some cities have a train and each city has at most one train originating from it. The trains
 are represented by an array A, where Ai=0 means the i-th city doesn't have any train originating
  from it, Ai=1 means the train originating from the i-th city is moving right (to a higher numbered city),
   and Ai=2 means the train originating from the i-th city is moving left (to a lower numbered city).

Each train keeps on going forever in its direction and takes 1 minute to travel from the current station to
 the next one. There is a special station at city 1 which lets travellers instantaneously teleport to any other
  station that currently has a train. Teleportation and getting on a train once in the city both take 0 minutes 
  and all trains start at time 0.

There are M travellers at city 1, and the i-th traveller has destination city Bi. They ask Chef to guide them to
 teleport to a particular station from which they can catch a train to go to their destination in the least time 
 possible. In case it's not possible for a person to reach his destination, print −1.

Note: The input and output of this problem are large, so prefer using fast input/output methods.

Input
	The first line contains an integer T, the number of test cases. Then the test cases follow.
	Each test case contains three lines of input.
	The first line contains two integers N, M.
	The second line contains N integers A1,A2,…,AN.
	The third line contains M integers B1,B2,…,BM.
Output
	For each test case, output M space-separated integers C1,C2,…,CM, where Ci is the minimum time required 
	by the i-th traveller to reach his destination and if the i-th traveller can't reach his destination, Ci=−1.

Constraints
	1≤N,M≤105
	0≤Ai≤2
	1≤Bi≤N
	The sum of N over all test cases is at most 106.
	The sum of M over all test cases is at most 106.
Subtasks
	#1 (100 points): original constraints

Sample Input
	3
	5 1
	1 0 0 0 0
	5
	5 1
	1 0 0 0 2
	4
	5 2
	2 0 0 0 1
	3 1
Sample Output
	4
	1
	-1 0
Explanation
	Test Case 1: The only person takes the train from station 1 and hence takes |5−1|=4 minutes to reach his destination.

	Test Case 2: The only person takes the train from station 5 and hence takes |5−4|=1 minute to reach his destination.

	Test Case 3: Since no train passes station 3, it's impossible for the first person to reach his destination 
				and since the second person is already at station 1, it takes him 0 minutes to reach his destination.
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	

	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int a[n], b[m];
		for (int i = 0; i < n; i++)
		{
			cin>>a[i];
		}
		for (int i = 0; i < m; i++)
		{
			cin>>b[i];
		}
		//two vectros
		vector<int> v1,v2;
		int o = -1, t= -1;
		int max = 1e9;
		//move right
		for (int i = 0; i < n; i++)
		{
			if(a[i]==1)
			{
				v1.push_back(0);
				o = i;
			}
			else if(o == -1)
			{
				v1.push_back(max);
			}
			else if(a[i]==2)
			{
				v1.push_back(0);
			}
			else
			{
				v1.push_back(i-o);
			}
		}

		//move left
		for (int i = n-1;i>=0;i--)
		{
			if (a[i]==2)
			{
				v2.push_back(0);
				t = i;
			}
			else if (t == -1 && a[i] == 0)
			{
				v2.push_back(max);
			}
			else if (a[i]==1)
			{
				v2.push_back(0);
			}
			else
			{
				v2.push_back(t-i);
			}
		}

		//reverse v2
		reverse(v2.begin(),v2.end());
		for (int i = 0; i < m; i++)
		{
			int cur = b[i];
			if (a[0]!=0 &&a[cur-1]!=0)
			{
				cout<<"0"<<" ";
			}
			else if(cur == 1)
			{
				cout<<"0"<<" ";
			}
			else
			{
				int res = 0;
				if(v1[cur - 1] == max && v2[cur - 1] == max)
				res = -1;
				else
				res = min(v1[cur - 1],v2[cur - 1]);
				cout<<res<<" ";
				
			}
		}
		cout<<"\n";
	}
	return 0;
}
