#include <bits/stdc++.h> 
using namespace std;  
typedef long int li;
int block; 
struct Query 
{ 
	int L, R,index;
    li sum; 
}; 
bool compare(Query x, Query y) 
{ 
	if (x.L/block != y.L/block) 
		return x.L/block < y.L/block; 
	return x.R < y.R; 
} 
bool compare1(Query x,Query y)
{
    return x.index<y.index;
}
void queryResults(vector<li>&a, int n, Query q[], int m) 
{ 
	block = (int)sqrt(n); 
	sort(q, q + m, compare); 
    li currL = 0, currR = 0; 
	li currSum = 0; 
    for (int i=0; i<m; i++) 
	{ 
		int L = q[i].L, R = q[i].R; 
        while (currL < L) 
		{ 
			currSum -= a[currL]; 
			currL++; 
		} 
        while (currL > L) 
		{ 
			currSum += a[currL-1]; 
			currL--; 
		} 
		while (currR <= R) 
		{ 
			currSum += a[currR]; 
			currR++; 
		} 
        while (currR > R+1) 
		{ 
			currSum -= a[currR-1]; 
			currR--; 
		} 
		q[i].sum=currSum;

	} 
} 
int main() 
{ 
    int n,q,value;
    cin>>n>>q;
    vector<li>v1(n),v2(n),v3(n);
    for(int i=0;i<n;i++)
    {
        cin>>value;
        v1[i]=value;
    }
    for(int i=0;i<n;i++)
    {
        cin>>value;
        v2[i]=value;
        v3[i]=v1[i]*v2[i];
    }
    Query *qu=new Query[q];
    int l1,l2;
    for(int i=0;i<q;i++)
    {
        cin>>l1>>l2;
        qu[i].L=l1-1;
        qu[i].R=l2-1;
        qu[i].index=i;
    }
    queryResults(v3,n,qu,q);
    sort(qu,qu+q,compare1);
    for(int i=0;i<q;i++)
        cout<<qu[i].sum<<endl;
	return 0; 
} 
