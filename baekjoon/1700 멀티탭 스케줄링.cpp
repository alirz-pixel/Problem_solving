#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solve(vector<int>& input, vector<queue<int>>& useIndex, int N);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    vector<int> input(K+1);
    vector<queue<int>> useIndex(K+1);
    for (int i = 0; i < K; i++) {
        cin >> input[i];
        useIndex[input[i]].push(i);
    }

    cout << solve(input, useIndex, N);

    return 0;
}


int solve(vector<int>& input, vector<queue<int>>& useIndex, int N) {
    int ret = 0, useCnt = 0;

    vector<bool> usingPdu(input.size());
    vector<pair<int, int>> inPlug;
    for (auto i : input) {
        useIndex[i].pop();

        // 뽑지 않아도 됨
        if (usingPdu[i]) {
            for (auto j : inPlug) {
                if (j.second == i) {
                    
                }
            }
            continue;
        }

        // 빈 플러그가 있는 경우
        if (!usingPdu[i] && useCnt < N) {
            if (useIndex[i].size() == 0)
                inPlug.push_back({102 , i});
            else 
                inPlug.push_back({useIndex[i].front() , i});

            usingPdu[i] = true;
            useCnt++;
            continue;
        }

        // 뽑아야 함
        for (auto j : inPlug)
            cout << j.first << " " << j.second << "\n";
        cout << "\n";

        ret++;

        int maxIndex = 0;
        for (int j = 0; j < N; j++) {
            if (inPlug[j].first > inPlug[maxIndex].first)
                maxIndex = j;
        }

        if (useIndex[i].size() == 0)
            inPlug[maxIndex].first = 102;
        else
            inPlug[maxIndex].first = useIndex[i].front();

        usingPdu[i] = true;
        usingPdu[inPlug[maxIndex].second] = false;
        inPlug[maxIndex].second = i;
    }

    return ret;
}