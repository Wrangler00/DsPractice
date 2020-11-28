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
		
		void printHeap(){
			for(auto v:heap){
				cout<<v<<" ";
			}
		};
		
		//kth smallest element
		void kthTask(int x){
			if(heap_size<1)
				return;
				
			if(x<heap[0]){
				heap[0]=x;
				heapify(0);
			}
		};
		
		int getRoot(){
			if(heap_size<1)
				return -1;
			return heap[0];
		};
};

//kth smallest element
int kthElement(Heap &hp,int k,vector<int> arr){
	
	int sz = arr.size();
	
	if(k>sz){
		cout<<"OUT OF BOUNDS!\n";
		return -1;
	}
		
	for(int i=k;i<sz;i++){
		hp.kthTask(arr[i]);
	}
	
	return hp.getRoot();
}

int main(){
	vector<int> arr = {101,1,2,3,5,5,6};
	
	int k = 1;
	Heap hp = Heap(k,arr);
	
	hp.buildHeap();
	
	hp.printHeap();
	
	cout<<endl;
	cout<<k<<"th smallest element :: "<<kthElement(hp,k,arr);
	
	//hp.printHeap();
	return 0;
}
