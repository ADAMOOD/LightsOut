
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Z2 {
private:
	int value;

public:
	// Constructor: the +2 factor guarantees positive output of %
	Z2(int v = 0) : value((v % 2 + 2) % 2) {}

	// Overload arithmetic operators for Z2
	Z2 operator+(const Z2& other) const { return Z2(value + other.value); }
	Z2 operator-(const Z2& other) const { return Z2(value - other.value); }
	Z2 operator*(const Z2& other) const { return Z2(value * other.value); }
	Z2 operator/(const Z2& other) const {
		if (other.value == 0) {
			throw std::runtime_error("Division by zero in Z2.");
		}
		return Z2(value); // only possible division is by 1
	}

	Z2& operator+=(const Z2& other) { value = (value + other.value) % 2; return *this; }
	Z2& operator-=(const Z2& other) { value = (value - other.value + 2) % 2; return *this; }
	Z2& operator*=(const Z2& other) { value = (value * other.value) % 2; return *this; }

	bool operator==(const Z2& other) const { return value == other.value; }
	bool operator!=(const Z2& other) const { return value != other.value; }
};

vector<vector<int>> buildA(int n)
{
	const int N = n * n;
	vector<vector<int>> A(N, vector<int>(N, 0));
	int  directions[5][2] = {
		{0, 0}, // self
			{ -1, 0}, // left
			{1, 0 }, // right
			{0, -1}, // down
			{0, 1 }   // up
	};
	for (int j = 0; j < N; j++) {        // column = button
		int r = j / n;                    // row of the button
		int c = j % n;                    // column of the button
		for (int k = 0; k < 5; k++) {    // foreach direction
			int nr = r + directions[k][0];
			int nc = c + directions[k][1];
			if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
				int i = nr * n + nc;     // light index
				A[i][j] = 1;             // press of the button j affects light i
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << A[i][j];
		}
		cout << endl;
	}
	return A;
}

int main(int argc, char* argv[]) {
	const int n = std::stoi(argv[1]);
	const int N = n * n;

	if (argc != N + 2) {
		cerr << "Invalid number of arguments\n";
		return -1;
	}

	vector<Z2> b;
	for (int i = 0; i < N; i++)
		b.push_back(Z2(std::stoi(argv[i + 2])));

	auto A_int = buildA(n);
	vector<vector<Z2>> A(N, vector<Z2>(N, Z2(0)));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			A[i][j] = Z2(A_int[i][j]);

	// Gauss GF(2)
	for (int col = 0; col < N; col++) {
		int pivotRow = -1;
		for (int row = col; row < N; row++) {
			if (A[row][col] == Z2(1)) {
				pivotRow = row;
				break;
			}
		}
		if (pivotRow == -1) continue;

		if (pivotRow != col) {
			swap(A[col], A[pivotRow]);
			swap(b[col], b[pivotRow]);
		}

		for (int row = 0; row < N; row++) {
			if (row == col) continue;
			if (A[row][col] == Z2(1)) {
				for (int k = col; k < N; k++)
					A[row][k] += A[col][k]; // XOR
				b[row] += b[col];           // XOR
			}
		}
	}

	for (int i = 0; i < N; i++)
		cout << (b[i] == Z2(1) ? 1 : 0) << " ";
	cout << "\n";

	return 0;
}