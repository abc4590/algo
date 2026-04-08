#include<iostream>
using namespace std;
int comp=0;
void merge(int a[],int l,int m,int r){
    int i=l,j=m+1,k=0;
    int temp[100];

    while(i<=m && j<=r){
        comp++;
        if(a[i]<=a[j])
        temp[k++]=a[i++];
        else
        temp[k++]=a[j++];
    }
    while(i<=m)
    temp[k++]=a[i++];

    while(j<=r)
    temp[k++]=a[j++];
    for (i=l,k=0;i<=r;i++,k++)
    a[i]=temp[k];
}
void mergesort(int a[],int l,int r){
    if(l<r){
        int m=(l+r)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        merge(a,l,m,r);
    }
}
int main(){
    int n,a[100];
    cout<<"enter number of elements:";
    cin>>n;

    cout<<"enter element:\n";
    for(int i=0;i<n;i++)
    cin>>a[i];

    mergesort(a,0,n-1);
    cout<<"\nSorted array:\n";
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";

    cout<<"\n\nnumber of comparisons:"<<comp;
    return 0;
}