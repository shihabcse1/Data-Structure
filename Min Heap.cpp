#include<bits/stdc++.h>
using namespace std;

int left_child(int parent){
    return 2 * parent;
}

int right_child(int parent){
    return 2 * parent + 1;
}

void min_heapify(int Heap[], int heapSize, int index){

    int left, right, largest, temp;
    left = left_child(index);
    right = right_child(index);

    if(left <= heapSize && Heap[index] > Heap[left]){ // Checking left child whether it is out of Heap size And Comparing left child with it's parent.
        largest = left; // Just storing the index of large node
    }else{
        largest = index;
    }

    if(right <= heapSize && Heap[largest] > Heap[right]){ // Checking right child whether it is out of Heap size And Comparing right child with it's parent.
        largest = right;
    }

    if(largest != index){ // if index is not equal largest, that means their current parent isn't largest among 2 children. So we need to swap to keep heap's property.
        temp = Heap[index];
        Heap[index] = Heap[largest];
        Heap[largest] = temp;

        min_heapify(Heap, heapSize, largest); //Again call Min_heap to ensure the property of heap of other ancestors.
    }
}

void build_minHeap(int Heap[], int heapSize){
    for(int i = heapSize/2; i >= 1; i--){
        min_heapify(Heap, heapSize, i);
    }
}

void print_heap(int Heap[], int heap_size){
    for(int i = 1; i <= heap_size; i++){
        cout<<Heap[i]<<" ";
    }
    cout<<endl;
}

void heap_sort(int Heap[], int heap_size){
    int i, temp;
    for(int i = heap_size; i >= 1; i--){
        cout<<Heap[1]<<" "; //Root is smallest value so print it.
        temp = Heap[1]; //Swap root with node and delete it(not delete actually it is decreasing size)
        Heap[1] = Heap[i];
        Heap[i] = temp;
        heap_size--;
        min_heapify(Heap, heap_size, 1); // Calling it again for containing heap properties.
    }
}

int main(){

    int heap_size = 9;
    int Heap[] = {0, 19, 7, 12, 3, 5, 17, 10, 1, 2};

    //heap_size = sizeof(Heap)/sizeof(Heap[1]);

    build_minHeap(Heap, heap_size);

    cout<<"Print Heap : ";
    print_heap(Heap, heap_size);

    cout<<"Heap sort : ";
    heap_sort(Heap, heap_size);

    return 0;
}
