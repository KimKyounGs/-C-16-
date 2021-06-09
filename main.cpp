//// 이 문제의 핵심은 왼쪽 위에서 오는 경우와 왼쪽 아래에서 오는 경우 그리고 왼쪽에서 오는 경우를 각각 나누어서 계산하는 것이 포인트인것같다. 
//// 내가 한 것을 보면 한번에 계산할려 하니 답이 안나온 것 같다. 시간안에 풀지 못하엿고 아예 답 근처에 가지도 못 했다.. 다이나믹.. 어렵지만 계속 공부해야겠다..!!!!! 
// 내가 한 것
#include <bits/stdc++.h>

using namespace std;

int t, n, m;

int main() {
        ios::sync_with_stdio(false);
 	cin.tie(NULL);

        cin >> t;
        while(t--) {
                int d[21][21];
                int arr[21][21];
                cin >> n >> m;
                for (int i = 0; i < n; i ++) {
                        for (int j = 0; j < m; j ++) {
                                cin >> arr[i][j];
                        }
                }
                
                d[0][0] = arr[0][0];
                for (int i = 1; i < n; i ++) {
                        for (int j = 0; j < m; j ++) {
                                d[i][j] = max(d[i-1][j], d[i][j] + arr[i][j]);
                        }
                }

                cout << d[n-1][m-1] << '\n';
        }
}




// 답
#include <bits/stdc++.h>

using namespace std;

int testCase, n, m;
int arr[20][20];
int dp[20][20];

int main(void) {
    // 테스트 케이스(Test Case) 입력
    cin >> testCase;
    for (int tc = 0; tc < testCase; tc++) {
        // 금광 정보 입력
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        // 다이나믹 프로그래밍을 위한 2차원 DP 테이블 초기화
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j] = arr[i][j];
            }
        }
        // 다이나믹 프로그래밍 진행
        for (int j = 1; j < m; j++) {
            for (int i = 0; i < n; i++) {
                int leftUp, leftDown, left;
                // 왼쪽 위에서 오는 경우
                if (i == 0) leftUp = 0;
                else leftUp = dp[i - 1][j - 1];
                // 왼쪽 아래에서 오는 경우
                if (i == n - 1) leftDown = 0;
                else leftDown = dp[i + 1][j - 1];
                // 왼쪽에서 오는 경우
                left = dp[i][j - 1];
                dp[i][j] = dp[i][j] + max(leftUp, max(leftDown, left));
            }
        }
        int result = 0;
        for (int i = 0; i < n; i++) {
            result = max(result, dp[i][m - 1]);
        }
        cout << result << '\n';
    }
}