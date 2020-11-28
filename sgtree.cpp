#include<bits/stdc++.h>
using namespace std;

#define l(n) 2*n+1
#define r(n) 2*n+2
#define treesize(x) 2*(int)pow(2, (int)(ceil(log2(x)))) - 1

vector<int> arr= {1, 3, 5, 7, 9, 11};

const int sz = arr.size();
const int tsize = treesize(sz);
vector<int> sgtree(tsize,0);

void updatesum(int tl,int tr,int i,int node,int diff){
    if(i>tr || i<tl)
        return;

    sgtree[node]+=diff;

    if(tl!=tr){
        int mid=(tl+tr)/2;
        updatesum(tl,mid,i,l(node),diff);
        updatesum(mid+1,tr,i,r(node),diff);
    }
}

int getsum(int tl,int tr,int l,int r,int node){
    if(tr<l || tl>r)
        return 0;
    
    if(tl>=l && tr<=r)
        return sgtree[node];

    int mid = (tl+tr)/2;
    return getsum(tl,mid,l,r,l(node))+getsum(mid+1,tr,l,r,r(node));
}

int contructsg(int l,int r,int node){
    // cout<<l<<" "<<r<<" "<<node<<endl;
    if(l==r){
        sgtree[node] = arr[l];
        return sgtree[node];
    }

    int mid = (l+r)/2;

    sgtree[node] = contructsg(l,mid,l(node)) + contructsg(mid+1,r,r(node));

    return sgtree[node];
}

int main(){
    
    contructsg(0,sz-1,0);

    // for(auto &i:sgtree){
    //     cout<<i<<" ";
    // }

    //Print sum of values in array from index 1 to 3 
	cout<<"Sum of values in given range = "<<getsum(0,sz-1,1, 3,0)<<endl; 

    // Update: set arr[1] = 10 and update corresponding 
	// segment tree nodes 
    const int upind = 1;
    const int upval = 10;
    int diff = upval-arr[upind];
    arr[upind]=upval;
	updatesum(0,sz-1,1,0,diff); 

    //Print sum of values in array from index 1 to 3 
	cout<<"Sum of values in given range(after update) = "<<getsum(0,sz-1,1, 3,0)<<endl; 
    return 0;
}