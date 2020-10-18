#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
#define p 1000000007
class math
{
    public:
    //Recursive relation:pow(x,n)={  pow(x,n/2)*pow(x,n/2)      n is even
    //                            {  x*pow(x,n/2)*pow(x,n/2)    n is odd
    //T(n)=T(n/2)+O(1)==>
    //Time complexity=O(logn)
    //Space Complexity=O(1)
    ll power(int x,int n)
    {
        if(n==0)return 1;
        ll temp=power(x,n/2);
        if(n&1)return x*temp*temp;
        else return temp*temp;
    }

    //Recursive relation:gcd(a,b)={ if(b==0) return a
    //                           ={   else return gcd(b,a%b)
    //Time complexity =O(log(min(m,n)))
    //Space  Complexity=O(1)
    //Proof of correctness:https://cp-algorithms.com/algebra/euclid-algorithm.html
    ll gcd(int a,int b)
    {
        if(b==0)return a;
        else return gcd(b,a%b);       
    }
    //Algorithm First we remove 2 and 3 factors from number .Then we have to check the prime numbers from 5 with stride 6.
    //We check for both i and i+2.As they are the only probable primes.
    //Time complexity:O(sqrt(n))
    //Spcae Complexity:O(No of factors)   
    vector<ll> factorization(ll n)
    {
        vector<ll>ans;
        if(n%2==0)
        {
            while(n%2==0)
            {
                    ans.pb(2);
                    n=n/2;
            }
        }

        if(n%3==0)
        {
            while(n%3==0)
            {
                    ans.pb(3);
                    n=n/3;
            }
        }
        for(ll i=5;i*i<=n;i+=6)
        {
            if(n%i==0)
            {
                while(n%i==0)
                {
                        ans.pb(i);
                        n=n/i;
                }		
            }
            if(n%(i+2)==0)
            {
                while(n%(i+2)==0)
                {
                        ans.pb(i+2);
                        n=n/(i+2);
                }
            }
        }
        
        if(n>2)
        {
            ans.pb(n);
        }

        return ans;
 
 
    }

    //Recursive relation :NCR=(N-1)CR+(N-1)C(R-1)
    //Time complexity:O(n^2)
    //Space complexity:O(n^2)

    ll NCR(ll a,ll b)
    {
        vector<vector<ll>>dp(a+1,vector<ll>(a+1,0));

        for(ll i=0;i<=a;i++)
        {
            dp[i][0]=1;
        }

        for(ll i=1;i<=a;i++)
        {
            for(ll j=1;j<=a;j++)
            {   
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
            }
        }

        return dp[a][b];
    }


};

int main()
{
    ll a,b;
    cin>>a>>b;
    math operation;
    cout<<operation.NCR(a,b);
}