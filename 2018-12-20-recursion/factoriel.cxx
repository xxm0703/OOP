#include<iostream>

using namespace std;

int fact_rec(int n)
{
	if (!n)
		return 1;

	return n * fact_rec(n - 1);
}

int fact_optimize(int n, int result=1)
{
	if (!n)
		return result;

	return fact_optimize(n - 1, n * result);
}

int fact_iter(int n)
{
	int a = 1;
	do
		a *= n;
	while(--n);
	return a;
}

int main()
{
	cout << fact_rec(5) << endl;
	cout << fact_optimize(5) << endl;
	cout << fact_iter(5) << endl;

	return 0;
}
