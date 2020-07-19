class Solution {
    struct Node{
        int val;
        vector<Node*> child;
    };
    
public:
    Node* newNode(int val){
        Node *tmp = new Node;
        tmp->val = val;
        tmp->child = vector<Node*>();
        
        return tmp;
    }
    
    //preorder traversal
    void preorder(Node *pNode){
        if(pNode == NULL)
            return;
        
        cout<<pNode->val<<" ";
        
        for(Node* v:pNode->child){
            recurse(v);
        }
    }
    
    //level order traversal
    void lot(Node *pNode){
        if(pNode == NULL)
            return;
        
        queue<Node*> st;
        st.push(pNode);
        
        while(!st.empty()){
            Node *tmp = st.front();
            st.pop();
            cout<<tmp->val<<" ";
            
            for(Node* v:tmp->child){
                st.push(v);
            }
        }
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& e, string l) {
        vector<int> ans;
        vector<vector<int>> list(n,vector<int>());
        int tree[4*n];
        
        //egdes to adj list conversion
        for(auto v: e){
            list[v[0]].push_back(v[1]);
        }
        
        stack<Node*> st;
        Node *root = newNode(0);
        st.push(root);
        
        //adj list to tree conversion
        while(!st.empty()){
            Node *tmp = st.top();
            st.pop();
            
            for(auto v:list[tmp->val]){
                Node *node = newNode(v);
                tmp->child.push_back(node);
                st.push(node);
            }
        }
        
        lot(root);
        
        return ans;
    }
};
