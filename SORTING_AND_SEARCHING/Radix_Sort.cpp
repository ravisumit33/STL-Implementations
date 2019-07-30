#include <iostream>
#include <vector>
#include <algorithm> // std::max_element, std::min
#include <cmath> // floor, log2

using namespace std;

void radix_sort(vector<int> &a) {
  int n = a.size(), pos=0;
  int bits = min((int)sizeof(a[0])*8, (int)log2(n));
  int m = *max_element(a.begin(), a.end());

  vector<int> b(n);
  int buckets = 1<<bits;
  int mask = buckets-1;

  while ((m>>(pos*bits)) > 0) {
    vector<int> bucket(1<<bits);
    for (int i = 0; i < n; i++)       bucket[(a[i]>>(pos*bits)) & mask]++;
    for (int i = 1; i < buckets; i++) bucket[i] += bucket[i - 1];
    for (int i = n - 1; i >= 0; i--)  b[--bucket[(a[i]>>(pos*bits)) & mask]] = a[i];
    for (int i = 0; i < n; i++)       a[i] = b[i];
    pos++;
  }
}


int main(){
	int n; cin >> n;
	vector<int> v(n);
	for(int i=0; i<n; i++) cin >> v[i];
	radix_sort(v);
	for(int i=0; i<n; i++) cout << v[i] << ' ';
	cout << '\n';
	return 0;
}
