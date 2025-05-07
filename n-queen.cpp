#include <iostream>
using namespace std;

const int MAX_N = 20; // Maximum N value supported
int N;
int board[MAX_N][MAX_N];
bool col[MAX_N], diag1[2 * MAX_N - 1], diag2[2 * MAX_N - 1];

void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << (board[i][j] ? "Q " : ". ");
        cout << endl;
    }
    cout << "--------------------\n";
}
bool solve(int row) {
    if (row == N) {
        printBoard(); // One valid solution found
        return true;  // return true to stop at first solution
    }
    for (int c = 0; c < N; c++) {
        if (!col[c] && !diag1[row - c + N - 1] && !diag2[row + c]) {
            board[row][c] = 1;
            col[c] = diag1[row - c + N - 1] = diag2[row + c] = true;

            if (solve(row + 1))
                return true; // Stop at first solution

            // Backtrack
            board[row][c] = 0;
            col[c] = diag1[row - c + N - 1] = diag2[row + c] = false;
        }
    }
    return false;
}
int main() {
    cout << "Enter the value of N (number of queens): ";
    cin >> N;
    if (N > MAX_N) {
        cout << "N is too large. Max supported value is " << MAX_N << "." << endl;
        return 1;
    }
    for (int i = 0; i < N; i++) {
        col[i] = 0;
        for (int j = 0; j < N; j++)
            board[i][j] = 0;
    }
    for (int i = 0; i < 2 * N - 1; i++) {
        diag1[i] = diag2[i] = 0;
    }
    if (!solve(0))
        cout << "No solution exists for N = " << N << endl;
    return 0;
}
