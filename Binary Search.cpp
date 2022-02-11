#include<bits/stdc++.h>
using namespace std;
const int size = 10;
int myarr[size] = {2, 3, 4, 5, 6, 7, 8, 9, 36, 45};
int cnt = 0;

int binary_search(int start_Index,int end_Index,int value){
    cnt++;
    int mid_Index = start_Index + (end_Index - start_Index) / 2; // To avoid integer overflow
    //int mid_Index = (start_Index + end_Index) / 2;
    if(myarr[mid_Index] == value){
        return mid_Index;
    }
    else{
        if(start_Index >= end_Index){
            return -1;
        }
        else{
            if(value < myarr[mid_Index]){
                binary_search(start_Index, mid_Index-1, value);
            }
            else{
                binary_search(mid_Index+1, end_Index, value);
            }
        }
    }
}
int main()
{

    int result = binary_search(0, size-1, 5);
    if(result < 0){
        cout<<"Item not Found"<<endl;
    }
    else{
        cout<<"Item is found in Index : "<<result<<endl;
        cout<<"We have found it after "<<cnt<<" time Search."<<endl;
    }
    return 0;
}
