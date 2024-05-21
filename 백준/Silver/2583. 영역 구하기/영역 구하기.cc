#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int paper[103][103];
int check[103][103];

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	queue<pair<int, int>> Q;
	int M, N, K; // M 행 N 열인데 돌리면 M이 열 N이 행이됨
	int x1, y1, x2, y2;
	int count = 0;
	int paperArea = 0;
	vector<int> v;
	cin >> M >> N >> K;

	for (int i = 0; i < K; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = x1; j < x2; j++) {
			for (int k = y1; k < y2; k++) {
				paper[j][k] = 1;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (paper[i][j] == 0 && check[i][j] == 0) {
				count++;
				check[i][j] = 1;
				Q.push({ i,j });
				while (!Q.empty()) {
					paperArea++;
					pair<int,int> cur = Q.front();
					Q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = cur.first + dx[k];
						int ny = cur.second + dy[k];
						if (nx < 0 || nx >= N || ny < 0 || ny >= M)continue;
						if (check[nx][ny] == 1 || paper[nx][ny] == 1) continue;
						check[nx][ny] = 1;
						Q.push({ nx,ny });
					}
				}
			}
			if (paperArea != 0) { // 여기가 문제야
				v.push_back(paperArea);
				paperArea = 0;
			}
		}
		
		
	}
	cout << count << "\n";
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	
}