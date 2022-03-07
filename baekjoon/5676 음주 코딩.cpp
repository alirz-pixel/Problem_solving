// 시작시간 | 15:07
// 종료시간 | 15:43       [  걸린시간 : 36분 | 제출시도 : 2회  ]

// cin.eof() 의 미숙으로 고생했네요..


#include <iostream>
#include <vector>

using namespace std;

// 세그먼트 트리
vector<int> arr;
vector<int> seg;
 // 초기화
int init(int start, int end, int node) {
	if (start == end) return seg[node] = arr[start]; // leafnode 초기화
	int mid = (start + end) / 2;
	return seg[node] = init(start, mid, node * 2) * init(mid + 1, end, (node * 2) + 1); // 왼,오른쪽 자식의 값을 현재 node에 더해가며 세그먼트 트리 완성
}

 // 변경
void update(int start, int end, int node, int index, int value) {
	if (index < start || end < index) return;  // 범위를 벗어났을 경우
	if (start == end) {    // 수정하려는 index에 온 경우
		seg[node] = value; // 세그먼트 트리에 해당하는 index에 value값 저장
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, value); // 왼쪽 자식 (start ~ mid)
	update(mid + 1, end, (node * 2) + 1, index, value); // 오른쪽 자식 (mid+1 ~ end)
	seg[node] = seg[node * 2] * seg[(node * 2) + 1]; // 구간합 갱신
}

 // 쿼리
int query(int start, int end, int node, int nodeLeft, int nodeRight) {
	if (end < nodeLeft || nodeRight < start) return 1; // 범위에 포함되지 않을 경우, 1을 리턴 (곱셈이므로)
	if (nodeLeft <= start && end <= nodeRight) return seg[node]; // 범위에 포함될 경우, 미리 구한 구간합 리턴
	int mid = (start + end) / 2; 
	return query(start, mid, node * 2, nodeLeft, nodeRight) * query(mid + 1, end, (node * 2) + 1, nodeLeft, nodeRight);
}



int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K, c1, c2;
	char cmd;
	while (true) {
        cin >> N >> K;
        if (cin.eof() == true) break; // 입력이 끝이 났을 때, 프로그램이 종료되도록 함.
        
		arr = vector<int>(N);
		seg = vector<int>(N * 4);

		// 수열 입력
		for (auto& i : arr) {
			cin >> i;
			if (i < 0) {
				i = -1; // overflow 방지를 위해 음수일 경우, -1로 세팅
			} else if (i > 0) {
				i = 1;  // overflow 방지를 위해 음수일 경우, 1로 세팅
			}
		}


		// 세그먼트 init;
		init(0, N - 1, 1);
		
		for (int i = 0; i < K; i++) {
			// 커맨드, { i, V } 또는 { i, j }
			cin >> cmd >> c1 >> c2;
		
			// 변경
			if (cmd == 'C') {
				c1--;
				if (c2 < 0) { // overflow 방지를 위해 음수일 경우, -1로 세팅
					c2 = -1;
				} else if (c2 > 0) {
					c2 = 1;   // overflow 방지를 위해 양수일 경우, 1로 세팅
				}
				update(0, N - 1, 1, c1, c2);
			} // 곱셈
			else if (cmd == 'P') {
				c1--; c2--;  // index는 0부터 시작하므로 left ~ right의 범위를 입력값에서 하나씩 제외시켜줌
				int result = query(0, N - 1, 1, c1, c2); // 구간계산
				
				// 출력
				if (result == 0) {
					cout << 0;
				} else if (result < 0) {
					cout << "-";
				} else {
					cout << "+";
				}
			}
		}

		cout << "\n";
	}
	return 0;
}