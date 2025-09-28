
#include <iostream>
#include <string>
#include <vector>
using namespace std;
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
				int i = nr * n + nc;     // index svìtla
				A[i][j] = 1;             // stisk tlaèítka j pøepne svìtlo i
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

int main(int argc, char* argv[1]) {
	const int n = std::stoi(argv[1]);
	const int N = n * n;
	if (argc != N + 2) {
		std::cerr << "Invalid number of arguments\n";
		return -1;
	}

	std::vector<int> rhs;
	for (int i = 0; i < N; i++) {
		rhs.push_back(std::stoi(argv[i + 2]));
	}
	for (auto x : rhs)
	{
		std::cout << x << std::endl;
	}
	buildA(n);
}
