#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<int> &v){
    auto begin = v.begin(), end = v.end();
    for(auto it=begin; it!=end; it++){
        int key = *it;
        auto temp = it - 1 ;
        while(temp-begin>=0 && *temp>key)   *(temp+1) = *temp--;
        *(temp+1) = key;
    }
}

int main(){
	int n; cin >> n;
	vector<int> v(n);
	for(int i=0; i<n; i++) cin >> v[i];
	insertion_sort(v);
	for(int i=0; i<n; i++) cout << v[i] << ' ';
	cout << '\n';
	return 0;
}
