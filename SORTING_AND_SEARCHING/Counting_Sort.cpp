#include <iostream>
#include <vector>
#include <algorithm> // std::max_element

using namespace std;

void counting_sort(vector<int> &v){
  int mx = *max_element(v.begin(), v.end());
  vector<int> count(mx+1, 0);
  int sz = v.size();
  vector<int> ans(sz);
  for(int i=0; i<sz; i++) count[v[i]]++;
  for(int i=1; i<mx+1; i++) count[i] += count[i-1];
  for(int i=sz-1; i>-1; i--) ans[--count[v[i]]] = v[i];
  v.assign(ans.begin(), ans.end());
}


int main(){
	int n; cin >> n;
	vector<int> v(n);
	for(int i=0; i<n; i++) cin >> v[i];
	counting_sort(v);
	for(int i=0; i<n; i++) cout << v[i] << ' ';
	cout << '\n';
	return 0;
}
