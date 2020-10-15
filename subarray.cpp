#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
#define p 1000000007
//Subarray questions 

//MAXIMUM SUB ARRAY SUM

//We use kadane algorithm to find maximum subarray sum in an array.
//Algorithm:If an array contains positve integers only then whole array would be the maximum subarray.
//          If an array contains only negative integers only then largest -ve element will be the the maximum subarray.
//          A=[-3,6,-5,7,9,-4,6]-->sum=-3-->sum=6-->sum=1-->sum=8-->sum=17-->sum=13-->sum=19.
//          So when ever we get sum as negative we update it 0 because it can't contribute to maximum subarray.
// Time complexity:O(n)
//Space  complexity=O(1)  
int kadane(vector<int>a)
{
    int ans=INT_MIN;
    int sum=0;
    int n=a.size();
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        ans=max(ans,sum);
        sum=max(0,sum);
    }

    return ans;
}

//MAXIMUM PRODUCT SUBARRAY
//Algorithm:If an array contains only non-zero positive elements the wjole array is the answer.
//          If an array contains all integers so when an element is positive we need maximum positive product currently,conversely 
//          when element is negative we nee minimum negative product and multiply with them.
//          But exception case is when array element is zero.We need to take the maximum of element itself when array elements are negative.
//Time complexity:O(n);
//space complexity:O(1);

int maximum_product(vector<int>a)
{
    int ans=INT_MIN;
    int positive_product=1;
    int negative_product=1;
    int prev_positive=1;
    int prev_negative=1;
    for(int i=0;i<a.size();i++)
    {
        positive_product=max(a[i],max(a[i]*prev_positive,a[i]*prev_negative));
        negative_product=min(a[i],min(a[i]*prev_negative,a[i]*prev_positive));
        ans=max(ans,max(positive_product,negative_product));
        prev_positive=positive_product;
        prev_negative=negative_product;
    }

    return ans;    

}
//NO OF SUBARRAYS WITH SUM K
//Algorithm:We need to check no of prefix sums whose difference is K.
//          So we start iterating through the array adding the prefix sums and checking for prefix with sum=sum-k before it in a hashmap  
//Time Complexity :O(n)
//Space Complexity:O(n)

int subarray_sumK(vector<int>a,int k)
{
    int ans=0;
    unordered_map<int,int>m;
    int sum=0;
    m[0]++;
    for(int i=0;i<a.size();i++)
    {
        sum+=a[i];
        ans+=m[sum-k];
        m[sum]++;
    }

    return ans;
}

//NO OF SUBARRAYS WHOSE SUM IS DIVISIBLE BY K
//Algorithm:We need to check for prefix sums whose diffference is divisble by k;
//          Let a and b be the prefix sums ==>a-b=nk
//          Let fix a and running prefix sums ==>b=a-nk
//          ==>b%k=a&k--->We need to check for map of (running sum modulo k).
//Time Complexity:O(n)
//Space complexity:O(k)
int subarray_sumdivk(vector<int>a,int k)
{
    int ans=0;
    unordered_map<int,int>m;
    int sum=0;
    m[0]++;
    for(int i=0;i<a.size();i++)
    {
        sum=(sum+a[i]%k+k)%k;
        ans+=m[sum];
        m[sum]++;
    }

    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }


}