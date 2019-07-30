#include <iostream>
#include <vector>
#include <utility>  // std::swap

using namespace std;

void bubble_sort(vector<int> &v){
   auto begin = v.begin(), end = v.end();
   int sz = v.size();
   for (int i=0; i != sz-1; i++)
       for (auto it2=begin; it2!=end-i-1; it2++) 
           if (*it2 > *(it2+1))
              swap(*it2, *(it2+1));
}

int main(){
	int n; cin >> n;
	vector<int> v(n);
	for(int i=0; i<n; i++) cin >> v[i];
	bubble_sort(v);
	for(int i=0; i<n; i++) cout << v[i] << ' ';
	cout << '\n';
	return 0;
}
