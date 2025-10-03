//binary tree paths
#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node*left;
    Node*right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};
static int idx=-1;
Node*buildTree(vector<int>arr){
    idx++;
    if(arr[idx]==-1){
        return NULL;
    }
    Node*root=new Node(arr[idx]);
    root->left=buildTree(arr);
    root->right=buildTree(arr);
    return root;
}
void check(Node*root,string path,vector<string>&result){
    if(root->left==NULL && root->right==NULL){
        result.push_back(path);
        return;
    }
    if(root->left){
    check(root->left,path+"->"+to_string(root->left->data),result);
}
if(root->right){
    check(root->right,path+"->"+to_string(root->right->data),result);
}
}
int main(){
    vector<int>arr={1,2,-1,5,-1,-1,3,-1,-1};
    Node*root=buildTree(arr);
    vector<string>result;
    string path=to_string(root->data);
    check(root,path,result);
    for(string ans:result){
        cout<<ans<<endl;
    }
    return 0;
}
