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
void Quicksort_Lomuto(int a[], int left,int right){
    if(left<right){
        int pi=partition_Lomuto(a,left,right);
        Quicksort_Lomuto(a,left,pi-1);// ben trai pivot
        Quicksort_Lomuto(a,pi+1,right);// ben phai pivot
    }
}
int partition_Hoare(int a[], int left, int right){
    int i=left-1;
    int j=right+1;
    int pi=a[left];
    while(true){
        do{
            i++;
        }while(a[i]<pi);
        do{
            j--;
        }
    while(a[j]>pi);
    if(i>=j) return j;
    swap(a[i],a[j]);
    }
}
void Quicksort_Hoare(int a[], int left, int right){
    if(left<right){
        int pi2=partition_Hoare(a,left,right);
        Quicksort_Hoare(a,left,pi2);
        Quicksort_Hoare(a,pi2+1,right);
        }
}
int main(){
    int n;
    cin>>n;
    int a[100];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    // Quicksort_Lomuto(a,0,n-1);
    Quicksort_Hoare(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}