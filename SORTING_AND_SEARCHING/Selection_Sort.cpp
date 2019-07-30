#include <iostream>
#include <vector>
#include <algorithm> // std::min_element
#include <utility> // std::swap

using namespace std;

void selection_sort(vector<int> &v){
    auto begin = v.begin(), end = v.end();
    vector<int>::iterator min_idx;
    for (auto it=begin; it!=end-1; it++){   
        min_idx = min_element(it, end);
        swap(*min_idx, *it);
    }
}

int main(){
	int n; cin >> n;
	vector<int> v(n);
	for(int i=0; i<n; i++) cin >> v[i];
	selection_sort(v);
	for(int i=0; i<n; i++) cout << v[i] << ' ';
	cout << '\n';
	return 0;
}
