#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int* m[2];
	m[0] = new int[n + 1]; // minimal costs for 1...n
	m[1] = new int[n + 1]; // operations
	m[0][1] = 0;

	// Minimal cost search
	for (int i = 2; i <= n; i++)
	{
		// Adding 1
		m[0][i] = m[0][i - 1] + i; // count current cost
		m[1][i] = 1; // put an operation

		// Division by 2
		if (i % 2 == 0 && m[0][i / 2] + i < m[0][i])
		{
			m[0][i] = m[0][i / 2] + i; // changing current cost if nessesary
			m[1][i] = 2; // put an operation
		}

		// Division by 3
		if (i % 3 == 0 && m[0][i / 3] + i < m[0][i])
		{
			m[0][i] = m[0][i / 3] + i; // changing current cost if nessesary
			m[1][i] = 3; // put an operation
		}
	}
	cout << m[0][n] << endl; // print the lowest cost

	// Searching for a transformation
	for (int j = n; j > 1;)
	{
		if (m[1][j] == 1)
		{
			cout << "-1";
			j--;
		}
		else if (m[1][j] == 2)
		{
			cout << "/2";
			j /= 2;
		}
		else if (m[1][j] == 3)
		{
			cout << "/3";
			j /= 3;
		}
		if (j > 1) cout << " "; // divide by space characters
	}
	cout << endl;

	return 0;
}