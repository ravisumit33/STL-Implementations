 y760#include <iostream>
#include <algorithm> // std::max_element, std::stable_sort
#include <vector>

using namespace std;

void bucket_sort(vector<int> &arr){
	int n = arr.size();
	vector<int> b[n];
	int mx = *max_element(arr.begin(), arr.end())+1;
	
	for (int i=0; i<n; i++){
	  int bi = n*((float)arr[i]/mx); // use other hash function as required
	  b[bi].push_back(arr[i]);
	}

	for (int i=0; i<n; i++)
	  stable_sort(b[i].begin(), b[i].end());

	int index = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < b[i].size(); j++)
		  arr[index++] = b[i][j];
}


int main()
{
	int n; cin >> n;
	vector<int> v(n);
	for(int i=0; i<n; i++)  cin >> v[i];
	bucket_sort(v);
	for (int i=0; i<n; i++) cout << v[i] << " ";
	cout << '\n';
	return 0;
}
