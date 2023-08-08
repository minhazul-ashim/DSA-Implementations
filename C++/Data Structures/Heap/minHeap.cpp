#include<bits/stdc++.h>
using namespace std;

vector<int> v;

void insertInHeap() {
    int x;
    cin >> x;
    v.push_back(x);
    int cur_idx = v.size() - 1;
    while(cur_idx != 0) {
        int parent_idx = (cur_idx - 1) / 2;
        if(v[parent_idx] > v[cur_idx]) {
            swap(v[parent_idx], v[cur_idx]);
        } else {
            break;
        }
        cur_idx = parent_idx;
    }
}

void deleteFromHeap() {
    v[0] = v[v.size() - 1];
    v.pop_back();
    int cur = 0;
    while(true) {
        int leftIdx = cur * 2 + 1;
        int rightIdx = cur * 2 + 2;
        int lastIdx = v.size() - 1;

        if(leftIdx <= lastIdx && rightIdx <= lastIdx) {

            if(v[leftIdx] <= v[rightIdx] && v[leftIdx] < v[cur]) { 

                swap(v[leftIdx], v[cur]);
                cur = leftIdx;
            } else if(v[rightIdx] <= v[leftIdx] && v[rightIdx] < v[cur]) {

                swap(v[rightIdx], v[cur]);
                cur = rightIdx;
            } else {

                break;
            } 
        } else if(leftIdx <= lastIdx) {

            if(v[leftIdx] < v[cur]) {

                swap(v[leftIdx], v[cur]);
                cur = leftIdx;
            } else {

                break;
            }
        } else if(rightIdx <= lastIdx) {

            if(v[rightIdx] < v[cur]) {

                swap(v[rightIdx], v[cur]);
                cur = rightIdx;
            } else {
                    
                    break;
            }
        } else {
            break;
        }
    }
}

void printHeap() {
    for(int x : v) {
        cout << x << " ";
    }
    cout << endl;
}

int main () {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        insertInHeap();
    }
    deleteFromHeap();
    printHeap();
    return 0;
}