//https://leetcode.com/problems/clone-graph/description/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    public:
    
        vector<Node*> collection=vector<Node*>(1000,NULL);
    
        Node* dfs(Node* root, vector<bool> &vis){
            if(root==NULL)return NULL;
            vis[root->val]=true;
            Node* tempNode= new Node(root->val);
            for(auto &x:root->neighbors){
                if(vis[x->val]==false){
                    vis[x->val]=true;
                    Node* neigh=dfs(x,vis);
                    tempNode->neighbors.push_back(neigh);
                    neigh->neighbors.push_back(tempNode);
                }else{
                    Node* neigh=collection[x->val];
                    if(neigh==NULL)continue;
                    tempNode->neighbors.push_back(neigh);
                    neigh->neighbors.push_back(tempNode);
                }
            }
            return collection[tempNode->val]=tempNode;
        }
    
        Node* cloneGraph(Node* node) {
            vector<bool> vis(1000,0);
            return dfs(node, vis);
        }
};