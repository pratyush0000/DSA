#include <bits/stdc++.h>
using namespace std;

//struct of the node
struct Node{ 
    int val; //stores value of the node
    int lockedBy; //stores who locked the node(if any)
    bool isLocked; //bool to return if it is locked or not
    Node* parent; //whos the parent?
    vector<Node*> children; //vector filled with children nodes

    Node(int v){
        val = v;
        lockedBy = -1;
        parent = nullptr;
    }

    bool isItLocked() const {
        return lockedBy != -1;
    }
};


int main() {
    int n,m,q;
    cin>>n>>m>>q;
    cout<<"n = " << n << " m = "<< m <<" q = "<<q;
}