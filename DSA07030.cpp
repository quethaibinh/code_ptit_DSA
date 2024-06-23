#include <iostream>
#include <vector>
using namespace std;

int maxRectangleArea(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if (n == 0) return 0;
    int m = matrix[0].size();

    // Tạo một ma trận DP với kích thước tương tự ma trận input
    // DP[i][j] sẽ lưu chiều rộng của hình chữ nhật lớn nhất kết thúc ở hàng i và cột j
    vector<vector<int>> DP(n, vector<int>(m, 0));

    // Khởi tạo DP cho hàng đầu tiên
    for (int j = 0; j < m; ++j) {
        DP[0][j] = matrix[0][j];
    }

    // Tính toán DP cho các hàng và cột còn lại
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // Nếu ô (i, j) là 1, tăng chiều rộng lên 1
            if (matrix[i][j] == 1) {
                DP[i][j] = DP[i - 1][j] + 1;
            }
        }
    }

    int maxArea = 0;

    // Duyệt qua từng hàng để tính toán diện tích lớn nhất của hình chữ nhật có cạnh song song với cạnh của bảng
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int minWidth = DP[i][j];
            for (int k = j; k < m; ++k) {
                // Tìm chiều rộng nhỏ nhất của hình chữ nhật trong các ô từ (i, j) đến (i, k)
                minWidth = min(minWidth, DP[i][k]);
                // Tính diện tích mới và cập nhật diện tích lớn nhất
                maxArea = max(maxArea, minWidth * (k - j + 1));
            }
        }
    }

    return maxArea;
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); 

    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        // Đọc ma trận input
        vector<vector<int>> matrix(N, vector<int>(M));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                cin >> matrix[i][j];
            }
        }

        // In ra diện tích lớn nhất của hình chữ nhật thoả mãn yêu cầu
        cout << maxRectangleArea(matrix) << endl;
    }

    return 0;
}



