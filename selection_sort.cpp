#include <iostream>
using namespace std;

void s_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int minInd=i;
        int temp;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minInd])
            {
                temp=arr[j];
                arr[j]=arr[minInd];
                arr[minInd]=temp;
            }
        }
    }
}
int main()
{
    int n;
    cout<<"Enter no.of elements.";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    s_sort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}