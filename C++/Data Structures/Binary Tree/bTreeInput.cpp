#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int val;
        Node *left;
        Node *right;
    
    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void levelOrder(Node * root) {
    queue<Node *> q;
    q.push(root);

    while(!q.empty()) {
        // take front;
        Node *current = q.front();
        q.pop();

        // the tasks;
        cout << current->val << " ";

        // put the children in the queue to be executed right after the root itself;
        if(current->left) q.push(current->left);
        if(current->right) q.push(current->right);
    }
}

Node * bTreeInput() {
    fstream inputFile;
    inputFile.open("input.txt", ios::in);
    if(!inputFile) {
        cout << "No Input File Found" << endl;
    }
    int val;
    inputFile >> val;
    Node *root;
    if(val == -1) {
        root = NULL;
    } else {
        root = new Node(val);
    }
    queue<Node *> q;
    if(root) {
        q.push(root);
    }
    while(!q.empty()) {
        Node * f = q.front();
        q.pop();

        int l, r;
        inputFile >> l >> r;
        Node *left;
        Node *right;
        if(l == -1) {
            left = NULL;
        }
        else {
            left = new Node(l);
        }

        if(r == -1) {
            right = NULL;
        } else {
            right = new Node(r);
        }

        f->left = left;
        f->right = right;

        if(f->left) {
            q.push(f->left);
        }
        if(f->right) {
            q.push(f->right);
        }
    }
    return root;
}

int main () {
    Node *root = bTreeInput();

    levelOrder(root);
    return 0;
}