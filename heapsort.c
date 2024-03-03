#include<stdio.h>
#include<stdlib.h>
typedef struct heap{
    int size;
    int capacity;
    int* arr;
}heap;
void printHeap(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

void swap(int a[],int i,int j){
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
int parent(int n){
    return (n-1)/2;
}
heap* createHeap(int cap){
    heap* hp=(heap*)(malloc(sizeof(heap)));
    hp->capacity=cap;
    hp->size=0;
    hp->arr=(int*)(malloc(sizeof(int)*cap));
    return hp;
}
void insert_heap(int x,heap* hp){
    if(hp->size==hp->capacity) return;
    hp->size++; hp->arr[hp->size-1]=x;
    int i=hp->size-1;
    while(i!=0 && hp->arr[parent(i)]<hp->arr[i]){   //To insert or create a random order heap
        swap(hp->arr,i,parent(i));
    }
}
void heapify(int a[],int n,int i){
    int left=2*i+1;
    int right=2*i+2;
    int max=i;
    if(left<n && a[left]>a[max]) max=left;
    if(right<n && a[right]>a[max]) max=right;
    if(max!=i){
        swap(a,max,i);
        heapify(a,n,max);
    }
}
void heapSort(int a[],int n){
    for(int i=n-1;i>0;i--){
        swap(a,i,0);
        heapify(a,i,0);
    }
}


void buildHeap(int a[],int n){
    int start=(n/2)-1;
    for(int i=start;i>=0;i--){
        heapify(a,n,i);
    }
    heapSort(a,n);
}

int main(){
    heap* nHeap=createHeap(6);
    insert_heap(20,nHeap);
    insert_heap(10,nHeap);
    insert_heap(5,nHeap);
    insert_heap(50,nHeap);
    insert_heap(40,nHeap);
    insert_heap(30,nHeap);

    printHeap(nHeap->arr,6);
    buildHeap(nHeap->arr,6);
    printHeap(nHeap->arr,6);
    return 0;
}