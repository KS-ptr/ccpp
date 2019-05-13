#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n, a;
	vector<int> inv;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> a;
		inv.push_back(a);
	}

	int tmin = inv[0];
	int tmax = -99999;
	for(int i = 1; i < n; i++)
	{
		tmax = max(tmax, inv[i]-tmin);
		tmin = min(tmin, inv[i]);
	}
	cout << tmax << endl;
	return 0;
}