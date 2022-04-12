#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	int arr[10], sum;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		for (int i = 0;i < 10;i++)
			cin >> arr[i];
		sum = 0;
		for (int i = 0;i < 10;i++)
			if (arr[i] % 2)
				sum += arr[i];
		cout << '#' << test_case << ' ' << sum << endl;
	}
	return 0;
}