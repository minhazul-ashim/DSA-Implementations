#include<bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    cin.ignore();
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<long long int>prefixSum(n);
    prefixSum[0] = nums[0];
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + nums[i];
    }
    while(n--) {
        cout << prefixSum[n] << " ";
    }
    return 0;
}