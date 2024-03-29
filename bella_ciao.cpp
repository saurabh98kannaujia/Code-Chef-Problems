/*
Chef is planning a heist in the reserve bank of Chefland.
They are planning to hijack the bank for D days and print the money.
The initial rate of printing the currency is P dollars per day and 
they increase the production by Q dollars after every interval of d days.
For example, after d days the rate is P+Q dollars per day, and after 2d days the
rate is P+2Q dollars per day,
and so on. Output the amount of money they will be able to print in the given period.


Input
    The first line contains an integer T, the number of test cases. Then the test cases follow.
    Each test case contains a single line of input, four integers D,d,P,Q.

Output
    For each test case, output in a single line the answer to the problem.

Constraints
    1≤T≤105
    1≤d≤D≤106
    1≤P,Q≤106

Subtasks
    Subtask #1 (15 points): d≤D≤100
    Subtask #2 (85 points): original constraints

Sample Input
    3
    2 1 1 1
    3 2 1 1
    5 2 1 2
Sample Output
    3
    4
    13
Explanation
    Test Case 1:

        On the first day, the rate of production is 1 dollar per day so 1 dollar is printed on the first day.
        On the second day, the rate of production is 1+1=2 dollars per day so 2 dollars are printed on the second day.
        The total amount of money printed in 2 days is 1+2=3 dollars.
    Test Case 2:

        For the first two days, the rate of production is 1 dollar per day so 1⋅2=2 dollars are printed on the first two days.
        On the third day, the rate of production is 1+1=2 dollars per day so 2 dollars are printed on the third day.
        The total amount of money printed in 3 days is 2+2=4 dollars.
    Test Case 3:

        For the first two days, the rate of production is 1 dollar per day so 1⋅2=2 dollars are printed on the first two days.
        On the next two days, the rate of production is 1+2=3 dollars per day so 3⋅2=6 dollars are printed on the next two days.
        On the last day, the rate of production is 3+2=5 dollars per day so 5 dollars are printed on the last day.
        The total amount of money printed in 5 days is 2+6+5=13 dollars.

*/



#include <iostream>
using namespace std;

int main() {
	
	   int t;
	   cin>>t;
	   while(t--)
	   {
    		long long d, d1, p, q;
    		cin>>d>>d1>>p>>q;
    		long long sum = 0, n;
    		n = d/d1;
    		sum =sum + (n*p + (q * (n-1) * n)/2) * d1 ;
    		if(d%d1!=0)
    		{
    		    sum = sum + (d%d1)*(p+n*q);
    		}
    		cout<<sum<<"\n";
	   }
	return 0;
}