// Given N numbers in an array. Your task is to keep at-most K numbers at the top (According to their frequency).  We basically need to print top k numbers when input stream has included k distinct elements, else need to print all distinct elements sorted by frequency.

// Input:
// First line consists of T test cases. First line of every test case consists of 2 integers N and K and second line of every test case consists of elements of array.

// Output:
// Single line output, print the atmost top K elements of the array.

// Constraints:
// 1 <= T <= 103
// 1 <= N, K <= 106

// Example:
// Input:
// 2
// 5 4
// 5 2 1 3 2
// 5 4
// 5 2 1 3 4
// Output:
// 5 2 5 1 2 5 1 2 3 5 2 1 3 5 
// 5 2 5 1 2 5 1 2 3 5 1 2 3 4 

// Explanation:
// For 1st test case:
// arr[] = 5 2 1 3 2
// Firstly their was 5 whose frequency is max till now. so print 5.
// Then 2 , which is smaller than 5 but their frequency is same so print 2 5.
// Then 1, Which is smallet among all the number arrived, so print 1 2 5.
// Then 3 , so print 1 2 3 5
// Then again 2, which has the highest frequency among all number so 2 1 3 5.

// For 2nd test case:
// arr[] = 5 2 1 3 4
// Firstly their was 5 whose frequency is max till now. so print 5.
// Then 2 , which is smaller than 5 but their frequency is same so print 2 5.
// Then 1, Which is smallest among all the number arrived, so print 1 2 5.
// Then 3 , so print 1 2 3 5.
// Then 4, so 1 2 3 4 as K is 4 so print at-most k elements.


#include <bits/stdc++.h>
using namespace std;

typedef pair <int,int> pd;

struct myComp 
{ 
    bool operator()( 
        pair<int, int> const& a, 
        pair<int, int> const& b) 
	    { 
	        return (a.second < b.second || 
	        	        (a.second==b.second && a.first>b.first)); 
	    } 
};

int main() 
{
	#ifndef ONLINE_JUDGE
		freopen("ip.txt", "r" , stdin);
		freopen("op.txt","w",stdout);
	#endif
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int a[n];
		unordered_map <int,int> mp;
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
			mp[a[i]]+=1;
			priority_queue <pd,vector<pd>,myComp> 
			pq(mp.begin(),mp.end());
			int cnt=0;
			while (!pq.empty() && cnt<k)
			{
			    pd top = pq.top();
			    cout << top.first<<" ";
		        pq.pop();
		        cnt++;
			}
		}
		cout<<"\n";
	}
}
