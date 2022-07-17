#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    vector<int> v;
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0){
            v.push_back(arr[i]);
            idx++;
        }
        else {
            if ((i != 0 && arr[i-1] < 0) || i == 0) v.push_back(arr[i]);
            else v[idx] += arr[i];
        }
    }
    int positiveCnt = 0;
    int lastPostvIdx = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] >= 0) {
            lastPostvIdx = i;
            positiveCnt++;
        }
    }

    int max = -1000;
    if (positiveCnt < 2) {
        for (auto n : v) max = (max > n) ? max : n;
    }
    else {
        int delim = 1;
        while(delim <= positiveCnt) {
            int k = 0;
            while(true) {
                int positivCnt_tmp = 0;
                int sum = 0;
                for (int i = k; i <= lastPostvIdx; i++) {
                    if (v[i] >= 0) {
                        positivCnt_tmp++;
                        if (delim >= positivCnt_tmp) sum += v[i];
                        if (delim < 2) k++;
                        else k = i;
                    }
                    else {
                        if (delim == 1);
                        else if (positivCnt_tmp < delim) sum += v[i];
                    }
                    if (positivCnt_tmp >= delim) break;
                }
                if (positivCnt_tmp >= delim) max = (max > sum) ? max : sum;
                
                if (k == lastPostvIdx) break;
            } // inner while
            delim++;
        } // outer while
    } //else
    cout << max << endl;
}