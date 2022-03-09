// 문제 링크 : https://www.acmicpc.net/problem/14405

// 7시 40분
// 7시 51분      [  걸린시간 : 11분 | 제출시도 : 2회  ]



#include <iostream>
#include <string>

using namespace std;

string solve(string S);

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string S;
	cin >> S;
	
	cout << solve(S);
	
	return 0;
}

string solve(string S) {
	char now;
	
	for (int i = 0; i < S.length(); i++) {
		if (S.length() - i == 1)
			return "NO";
		
		now = S[i];
		
		// pi
		if (now == 'p' && S[i+1] == 'i') {
			i++;
		} // ka
		else if (now == 'k' && S[i+1] == 'a') {
			i++;
		} // chu
		else if (S.length() - i >= 2 && now == 'c' && S[i+1] == 'h' && S[i+2] == 'u') {
			i += 2;
		} else {
			return "NO";
		}
	}
	
	return "YES";
}