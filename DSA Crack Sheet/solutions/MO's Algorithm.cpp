// Program to compute sum of ranges
#include <bits/stdc++.h>
using namespace std;

struct Query
{
	int L, R;
};

void printQuerySums(int a[], int n, Query q[], int m)
{
	for (int i=0; i<m; i++)
	{
		int L = q[i].L, R = q[i].R;

		int sum = 0;
		for (int j=L; j<=R; j++)
			sum += a[j];

		cout << "Sum of [" << L << ", "
			<< R << "] is " << sum << endl;
	}
}

// Driver program
int main()
{
	int a[] = {1, 1, 2, 1, 3, 4, 5, 2, 8};
	int n = sizeof(a)/sizeof(a[0]);
	Query q[] = {{0, 4}, {1, 3}, {2, 4}};
	int m = sizeof(q)/sizeof(q[0]);
	printQuerySums(a, n, q, m);
	return 0;
}
