#include<bits/stdc++.h>
using namespace std;

int partition_a(int A[], int low, int high){
    int i, j, temp;
    int pivot = A[high];
    for(i = low-1, j = low; j < high; j++){
        if(A[j] < pivot){
            i++;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    temp = A[high];
    A[high] = A[i+1];
    A[i+1] = temp;
    return i+1;
}

void quick_sort(int A[], int left, int right){
    if(left >= right){
        return;
    }
    int p = partition_a(A, left, right);
    quick_sort(A, left, p-1);
    quick_sort(A, p+1, right);
}

int main(){

    int A[1000], data, a_size = 0;

    ifstream input("input_quickSort.txt");

    while(input>>data){
        A[a_size] = data;
        a_size++;
    }

    quick_sort(A, 0, a_size);

    for(int i = 0; i < a_size; i++){
        cout<<A[i]<<" ";
    }

    return 0;
}
