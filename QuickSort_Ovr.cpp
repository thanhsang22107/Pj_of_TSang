#include<iostream>
using namespace std;
int partition_Lomuto(int a[], int left,int right){
    int pivot=a[right];
    int i=left-1;
    for(int j=left;j<=right-1;j++){
        if(a[j]<=pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[right]);
    return i+1;
}
void Quicksort(int a[], int left,int right){
    if(left<right){
        int pi=partition_Lomuto(a,left,right);
        Quicksort(a,left,pi-1);// ben trai pivot
        Quicksort(a,pi+1,right);// ben phai pivot
    }
}
int main(){
    int n;
    cin>>n;
    int a[100];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    Quicksort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}