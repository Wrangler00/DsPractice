//MIn heap to extract min k elements
//this is just to lear about heaps
//this can be optimized to extract k smallest/largest elements

#include<bits/stdc++.h>

using namespace std;

#define l(i) 2*i+1
#define r(i) 2*i+2

template <typename T>
bool compare(T &a1,T &a2){
		return a1>a2;
}

class Heap{
	private:
		int heap_size;
		int *h_arr;
	public:
		Heap(int arr[],int size){
			h_arr= arr;
			heap_size = size;
			buildHeap();
		}
		
		void buildHeap(){
			
			for(int i=(heap_size-1)/2;i>=0;i--){
				heapify(i);
			}
		}
		
		void heapify(int curr){
			int minn=curr;
			int left = l(curr);
			int right = r(curr);
			
			if(left<heap_size && compare<int>(h_arr[left],h_arr[minn])){
				minn = left;
			}
			
			if(right<heap_size && compare<int>(h_arr[right],h_arr[minn])){
				minn = right;
			}
			
			if(minn!=curr){
				swap(h_arr[curr],h_arr[minn]);
				heapify(minn);
			}
		}
};

void swap(int &a,int &b){
	int tmp = a;
	a=b;
	b=tmp;
}

void kthSmallest(int arr[],Heap &hp,int k,int sz){
	--sz;
	while(k--){
		int root=arr[0];
		
		cout<<root<<" ";
		
		if(sz>0){
			arr[0] = arr[sz];
			hp.heapify(0);
		}
		
		--sz;
	}
}

int main(){
	int arr[] = { 11, 15, 5, 4,1,3,2}; 
	int size = (int)(sizeof(arr)/sizeof(arr[0]));
	Heap hp(arr,size);
	
	int k=3;
	
	kthSmallest(arr,hp,k,size);
	return 0;
}
