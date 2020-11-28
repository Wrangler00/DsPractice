#include<bits/stdc++.h>

using namespace std;

#define l(i) 2*i+1
#define r(i) 2*i+2

void swap(int &a,int &b){
	int tmp = a;
	a=b;
	b=tmp;
}

//function that decides max heap and min heap comparison
bool heapCompare(int &a,int &b){
	//less than < for max heap
	//greater than > for min heap
	return a<b;
}

class Heap{
	private:
		int heap_size;
		vector<int> heap;
	public:
		Heap(int size,vector<int> arr){
			heap_size = size;
			heap = arr;
		}
		
		//standard build heap function from CLRS
		void buildHeap(){
			
			//here we call heapify for non-leaf nodes in a
			//bottom up manner in tree
			//Note: all nodes > heap_size/2 are leaf nodes
			int pos = (heap_size-1)/2;
			while(pos>=0){
				heapify(pos);
				--pos;
			}
		};
		
		//this is a standard heapify function
		//also written in CLRS book
		void heapify(int pos){
			int tmp=pos;
			
			int left = l(pos);
			int right = r(pos);
			
			if(left<heap_size && heapCompare(heap[tmp],heap[left]))
				tmp=left;
				
			if(right<heap_size && heapCompare(heap[tmp],heap[right]))
				tmp=right;
				
			if(tmp!=pos){
				swap(heap[tmp],heap[pos]);
				heapify(tmp);
			}
		};
		
		//standard heap sort from CLRS
		void heapSort(){
			--heap_size;
			while(heap_size>0){
				swap(heap[0],heap[heap_size]);
				heapify(0);
				--heap_size;
			}
		};
		
		void printHeap(){
			for(auto v:heap){
				cout<<v<<" ";
			}
		};
};

int main(){
	vector<int> arr = {1,2,3,4,5,6,6,7,7,8,0,12,1};
	Heap hp = Heap(arr.size(),arr);
	
	hp.buildHeap();
	
	hp.printHeap();
	hp.heapSort();
	
	cout<<endl;
	
	hp.printHeap();
	return 0;
}
