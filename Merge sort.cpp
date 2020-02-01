#include<bits/stdc++.h>
using namespace std;

void merge_fun(int A[], int left, int mid, int right){
    int l_size = mid - left+1; //<-------->
    int r_size = right - mid;
    int L[l_size], R[r_size];

    for(int i = 0; i < l_size; i++){
        L[i] = A[left+i];
    }
    for(int i = 0; i < r_size; i++){
        R[i] = A[mid+1+i];
    }
    int index_a, index_l = 0, index_r = 0;
    for(index_a = left; index_l < l_size && index_r < r_size; index_a++){
        if(L[index_l] < R[index_r]){
            A[index_a] = L[index_l];
            index_l++;
        }else{
            A[index_a] = R[index_r];
            index_r++;
        }
    }

    while(index_l < l_size){
        A[index_a] = L[index_l];
        index_a++;
        index_l++;
    }

    while(index_r < r_size){
        A[index_a] = R[index_r];
        index_a++;
        index_r++;
    }
}

void merge_sort(int A[], int left, int right){

    if(left >= right){
        return;
    }

    int mid = left + (right - left) / 2;

    merge_sort(A, left, mid);
    merge_sort(A, mid+1, right);
    merge_fun(A, left, mid, right);
}

int main(){

    int A[] = {3, 4, 8, 9, 2, 3, 23, 1, 2};

    int n = 8;

    merge_sort(A, 0, n);

    for(int i = 0; i <= n; i++){
        cout<<A[i]<<" ";
    }

    return 0;
}
