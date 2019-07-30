#include <iostream>
#include <vector>
#include <algorithm> // std::partition
#include <utility> // std::swap

using namespace std;

vector<int>::iterator partition_local (vector<int>::iterator begin, vector<int>::iterator end){
    int pivot = *(end-1);
    auto i = begin-1;
 
    for (auto j = begin; j < end-1; j++){
        if (*j <= pivot){
            i++;   swap(*i, *j);
        }
    }
    swap(*(i+1), *(end-1));
    return (i + 1);
}

void quick_sort(vector<int>::iterator begin, vector<int>::iterator end){
    if (end - begin > 1){
        auto p = partition(begin, end-1, [&] (int i) {return i <= *(end-1);});
     // you can also use partition_local as  partition_local(begin, end) instead of above 2 lines
        quick_sort(begin, p);
        quick_sort(p + 1, end);
    }
}

int main(){
	int n; cin >> n;
	vector<int> v(n);
	for(int i=0; i<n; i++) cin >> v[i];
	quick_sort(v.begin(), v.end());
	for(int i=0; i<n; i++) cout << v[i] << ' ';
	cout << '\n';
	return 0;
}
