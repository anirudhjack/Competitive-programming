#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;

//seive of eratosthenes
//We start to mark the multiples of each prime as non prime.
//complexities O(nlog(logn))  
vector<int> seive(int n)
{
    vector<bool>prime(n+1,true);
    prime[0]=false;
    prime[1]=false;
    for(int i=2;i*i<n;i++)
    {
        if(prime[i]==true)
        {
            for(int j=i*i;j<=n;j+=i)
            {
                prime[j]=false;
            }   
        }
    }

    vector<int>ans;
    for(int i=2;i<=n;i++)
    {
        if(prime[i]==true)
        {
            ans.pb(i);
        }
    }

    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int>ans=seive(n);

    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}