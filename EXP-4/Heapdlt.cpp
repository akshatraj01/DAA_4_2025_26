#include<bits/stdc++.h>
using namespace std;

int heap[1000];
int heapSize=0;

void heapifyDown(int i){
  int small =i;
  int lft =2*i+1;
  int ryt =2*i+2;     
  
  if(lft<heapSize && heap[small] > heap[lft]) 
    small = lft;
  if(ryt <heapSize && heap[small] > heap[ryt]) 
    small =ryt;
  if(small!=i){
    swap(heap[i],heap[small]);
    heapifyDown(small);
    }
}
void heapifyUp(int i){
    while(i>0 && heap[(i-1)/2]>heap[i]){
      swap(heap[(i-1)/2],heap[i]);
      i =(i-1)/2;
    }
}
void insert(int val){
    if(heapSize ==1000){
    cout<<"overflow";
    return ;
  }
    heap[heapSize]=val;
    heapSize++;
    heapifyUp(heapSize-1);
}

void dlt(){
  if(heapSize ==0){
		cout<<"No Element";
    return;
  }
  heap[0] = heap[heapSize-1];
  heapSize--;
  heapifyDown(0);
}
void dltvalue(int val) {
    int index =-1;
    for(int i=0;i<heapSize;i++) {
        if(heap[i]==val) {
            index=i;
            break;
        }
    }
    if(index==-1) {
        cout<<"Not Element";
        return;
    }
    heap[index]= heap[heapSize-1];
    heapSize--;
    heapifyUp(index);
    heapifyDown(index);
    cout<<"Deleted:"<<val;
}


int main() {
    insert(1);
    insert(7);
    insert(9);
    dlt();
    dlt();
    for(int i=0;i<heapSize;i++) 
    cout<<heap[i]<< " ";
    dltvalue(1);
}