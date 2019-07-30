#include <iostream>
#include <vector>
#include <algorithm> // std::make_heap, std::pop_heap
#include <utility> // std::swap

using namespace std;

void max_heapify(vector<int> &v, int sz, int i){
    while(true){
        int l = 2*i + 1;
        int r = 2*i + 2, largest;
        
        largest = i;
        if(l<sz && v[l]>v[i])   largest = l;
        if(r<sz && v[r]>v[largest]) largest = r;
        
        if(largest == i) return;
        else{
            swap(v[i], v[largest]);
            i = largest;
        }
    }
        
}

void build_max_heap(vector<int> &v){
    int sz = v.size();
    for(int i=(sz-2)/2; i>=0; i--)  max_heapify(v, sz, i);
}
void heap_sort(vector<int> &v){
    make_heap(v.begin(), v.end()); //you can also use build_max_heap as build_max_heap(v);
    int sz = v.size();
    
    for(int i=0; i<sz; i++) pop_heap(v.begin(), v.end()-i);
 /* you can also use below code instead of this:
        for(int i=sz-1; i>1; i--){
            swap(v[0], v[i]);
            max_heapify(v, i, 0);
        }
 */
    
}

int main(){
	int n; cin >> n;
	vector<int> v(n);
	for(int i=0; i<n; i++) cin >> v[i];
	heap_sort(v);
	for(int i=0; i<n; i++) cout << v[i] << ' ';
	cout << '\n';
	return 0;
}
