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
        isLocked = false;
        parent = nullptr;
    }
};


class Tree{
    vector<Node*> nodes;
public:
    Tree(int n, vector<int>& parent) {
        nodes.resize(n);
        //making all nodes
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node(i);
        }
        //connecting to parents
        for (int i = 0; i < n; i++) {
            if (parent[i] != -1) {
                nodes[i]->parent = nodes[parent[i]];
                nodes[parent[i]]->children.push_back(nodes[i]);
            }
        }
    }


    bool lock(int v, int id){
        //condition check
        //v is not already locked
        if(nodes[v]->isLocked==true) return false;
        
        //no ancestor of v is locked
        Node* cur = nodes[v]->parent;
        while (cur != nullptr) {
            if (cur->isLocked) return false;  // found locked ancestor
            cur = cur->parent;               // go one level up
        }

        //no descendant of v is locked
        queue<Node*> qq;
        for (Node* child : nodes[v]->children) {
            qq.push(child); //start from children as node is already checked
        }
        while(!qq.empty()){
            Node* curr = qq.front();
            qq.pop();

            if(curr->isLocked) return false;
            for(int i=0; i<curr->children.size(); i++){
                qq.push(curr->children[i]);
            }
        }

        //lock
        nodes[v]->isLocked=true;
        nodes[v]->lockedBy=id;
        return true;
    }

    bool unlock(int v, int id){
        //condition check
        //v is locked
        if(nodes[v]->isLocked==false) return false;

        //it is locked by the same user id.
        if(nodes[v]->lockedBy!=id) return false;

        //unlock
        nodes[v]->isLocked=false;
        nodes[v]->lockedBy=-1;
        return true;
    }

    bool upgrade(int v, int id){
        //condition check
        //v is not locked
        if(nodes[v]->isLocked) return false;

        //v has at least one locked descendant
        //every locked descendant of v is locked by the same id
        queue<Node*> qq;
        for (Node* child : nodes[v]->children) {
            qq.push(child); //start from children as node is already checked
        }
        int lockedcount=0;
        while(!qq.empty()){
            Node* curr = qq.front();
            qq.pop();

            if(curr->isLocked){
                if(curr->lockedBy!=id) return false;
                lockedcount++;
            }
            for (auto child : curr->children) {
                qq.push(child);
            }
        }
        if(lockedcount==0) return false;

        //no ancestor of v is locked
        Node* cur = nodes[v]->parent;
        while (cur != nullptr) {
            if (cur->isLocked) return false;  // found locked ancestor
            cur = cur->parent;               // go one level up
        }

        //if you have reached this part you are successful
        //On success:
        //unlock all locked descendants of v
        queue<Node*> upgradeQ;
        for (Node* child : nodes[v]->children) {
            upgradeQ.push(child); //start from children as node is already checked
        }
        while(!upgradeQ.empty()){
            Node* curr = upgradeQ.front();
            upgradeQ.pop();

            if(curr->isLocked){
                curr->isLocked = false;
                curr->lockedBy = -1;
            }
            for (auto child : curr->children) {
                upgradeQ.push(child);
            }
        }

        //lock v with id
        nodes[v]->isLocked=true;
        nodes[v]->lockedBy=id;

        return true;
    }

    ~Tree() {
        for (auto node : nodes) {
            delete node;
        }
    }
};



int main() {
    int n,m,q;
    cin>>n>>m>>q;

    //build tree
    vector<int> parent(n);
    for (int i = 0; i < n; i++) cin >> parent[i];
    Tree tree(n, parent);

    //process queries
    for(int i=0; i<q; i++){
        string op;
        int v,id;

        cin>>op>>v>>id;
        bool res = false;
        if (op == "lock") res = tree.lock(v, id);
        else if (op == "unlock") res = tree.unlock(v, id);
        else if (op == "upgrade") res = tree.upgrade(v, id);

        cout << (res ? "true" : "false") << "\n";
    }

    return 0;
}