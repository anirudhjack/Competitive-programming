#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
//Stability:A sorting algorithm is said to be stable if two objects with equal or same keys appear
// in the same order in sorted output as they appear in the input array to be sorted.
//Selection sort  
//Run Time:O(n^2)
//Space Complexity:O(1)
//stability:NO
//Algorithm :find minimum in A[i:n] for each 0<=i<=n-1 and swap it with A[i]  
 void selectionsort(vector<int>&a)
 {
     int n=a.size();
     for(int i=0;i<n-1;i++)
     {
         int ma=a[i];
         int index=i;
         for(int j=i+1;j<n;j++)
         {
             if(a[j]<ma)
             {
                 ma=a[j];
                 index=j;
             }
         }
         swap(a[index],a[i]);
     }

     return ;
 }

//Bubble sort
//Time complexity:best case:O(n):Average and worst:O(n^2)
//Space complexity:O(1)
//Stability:YES
//At each iteration of swap operation maximum gets embeded at right side of array(bubbling of water bubbles)
void bubblesort(vector<int>&a)
{
    int n=a.size();
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=n-i-1;j++)
        {
            if(a[j+1]<a[j])
            {
                swap(a[j],a[j+1]);
            }
        }
    }

    return;
}

//Insertion sort
//Time complexity:best case :O(n) Average and worst case:O(n^2)
//SpaceComplexity:O(1)
void Insertionsort(vector<int>&a)
{
    for(int i=1;i<a.size();i++)
    {
        int hole=i;
        int value=a[hole];//Value need to be inserted in left side of hole(which is sorted)
        while(hole>0&&a[hole-1]>value) //find an element which is less than value and insert hole after it.
        {
            a[hole]=a[hole-1];
            hole--;
        }
        a[hole]=value;
    }
}

//Merge sort 
//The idea behind merge sort is merging two sorted arrays
//Time Complexity:O(nlogn) for all cases
//Space Complexity:O(n)
//Stable:YES
//Applications no of inversion in an array using merge sort
void merge(vector<int>&a,int l,int r,int mid)
{
    int n1=mid-l+1;//No of elements j-i+1;
    int n2=r-mid-1+1;

    vector<int>L(n1);
    vector<int>R(n2);

    for(int i=0;i<n1;i++)//L starts from l and has n1 elements
    {
        L[i]=a[l+i];
    }

    for(int i=0;i<n2;i++)//R starts from mid+1 and has n2 elements 
    {
        R[i]=a[mid+1+i];
    }

    int i=0,j=0,k=l; //start merging elements from A[l] to A[r];

    while(i<n1&&j<n2)
    {
        if(L[i]<=R[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k]=R[j];
            j++;
        }
        k++;
    }

    while(i<n1)
    {
        a[k]=L[i];
        i++;
        k++;
    }

    while(j<n2)
    {
        a[k]=R[j];
        j++;
        k++;
    }
}

void Mergesort(vector<int>&a,int l,int r)
{
    if(r>l)
    {
        int mid=l+(r-l)/2;
        Mergesort(a,l,mid);
        Mergesort(a,mid+1,r);
        merge(a,l,r,mid);
    }
}

//Quick sort
//Time complexity :Best case :Middle element :pivot:T(n)=2T(n/2)+O(n)=O(nlogn)
//                :Average case:T(n)=T(n/10)+T(9n/10)+O(n)=O(nlogn)
//                :Worst case:pivot is highest element and array is sorted:T(n)=T(n-1)+O(n)=O(n^2)
//Space complexity:O(1)
//Stable:NO
//Many applications for partition:kth smallest element,median of two sorted arrays,etc. 
int partition(vector<int>&a,int l,int r)
{
    int pivot=a[r];
    int pindex=l;
    for(int i=l;i<r;i++)
    {
        if(a[i]<=pivot)
        {
            swap(a[i],a[pindex]);
            pindex++;
        }
    }
    swap(a[r],a[pindex]);

    return pindex;
}

void Quicksort(vector<int>&a,int l,int r)
{
    if(r>l)
    {
        int pivot=partition(a,l,r);
        Quicksort(a,l,pivot-1);
        Quicksort(a,pivot+1,r);
    }
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

    // selectionsort(a);
    //bubblesort(a);
    //Insertionsort(a);
    //Mergesort(a,0,n-1);
    Quicksort(a,0,n-1);

    cout<<"After sorting :"<<"\n";
    for(int i:a)
    {
        cout<<i<<" ";
    }


    
}