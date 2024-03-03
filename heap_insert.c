#include<stdio.h>
#include<stdlib.h>
typedef struct heap{
    int capacity;
    int size;
    int* arr;
}heap;
heap* createHeap(int cap){
    heap* hp=(heap*)(malloc(sizeof(heap)));
    hp->capacity=cap;
    hp->size=0;
    hp->arr=(int*)(malloc(sizeof(int)*hp->capacity));
    return hp;
}
void printHeap(heap* hp){
    for(int i=0;i<hp->size;i++)
        printf("%d ",hp->arr[i]);
    printf("\n");
}
void swap(int a[],int i,int j)
{
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
int parent(int i){
    return (i-1)/2;
}
void insert(int x,heap* hp){
    if(hp->size==hp->capacity) return;
    hp->size++; hp->arr[hp->size-1]=x;
    int i=hp->size-1;
    while(i!=0 && hp->arr[parent(i)]>hp->arr[i]){
        swap(hp->arr,i,parent(i));
        i=parent(i);
    }
}

int main(){
    heap* hp=createHeap(10);
    insert(10,hp);
    insert(20,hp);
    insert(15,hp);
    insert(40,hp);
    insert(50,hp);
    insert(100,hp);
    insert(25,hp);
    insert(45,hp);
    printHeap(hp);
    insert(12,hp);
    printHeap(hp);


    return 0;
}