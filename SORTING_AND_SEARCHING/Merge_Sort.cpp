#include <iostream>
#include <vector>
#include <climits> // INT_MAX
#include <algorithm> // std::inplace_merge

using namespace std;

// implementation of merge procedure
void merge(vector<int>::iterator begin, vector<int>::iterator mid, vector<int>::iterator end){
	int n1 = mid - begin;
	int n2 = end - mid;
	vector<int> l(n1+1), r(n2+1);
	
	for(int i=0; i<n1; i++)	l[i] = *(begin + i);
	for(int j=0; j<n2; j++)	r[j] = *(mid + j);
	l[n1] = INT_MAX; r[n2] = INT_MAX;
	
	int i=0, j=0;
	 for(auto it=begin; it!=end; it++){
	 	if(l[i] <= r[j])  *it = l[i++];
	 	else *it = r[j++];
	 }
}

void merge_sort(vector<int>::iterator begin, vector<int>::iterator end){
	if(end-begin > 1){
		auto mid = begin + (end-begin)/2;
		merge_sort(begin, mid);
		merge_sort(mid, end);
		inplace_merge(begin, mid, end); // you can also use merge procedure above
	}
}

int main(){
	int n; cin >> n;
	vector<int> v(n);
	for(int i=0; i<n; i++) cin >> v[i];
	merge_sort(v.begin(), v.end());
	for(int i=0; i<n; i++) cout << v[i] << ' ';
	cout << '\n';
	return 0;
}
