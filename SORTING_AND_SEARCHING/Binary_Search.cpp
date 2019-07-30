#include <iostream>
#include <algorithm> // std::binary_search

using namespace std;

bool search(vector<int>::iterator begin, vector<int>::iterator end, int el){
  while(end - begin > 0){
    auto it = begin + (end-begin)/2;
    if(*it == el) return true;
    else if(*it < el) begin++;
    else end--;
  }
  return false;
}

int main(){
  int n; cin >> n;
  vector<int> v(n);
  for(int i=0; i<n; i++)  cin >> v[i];
  int el; cin >> el;
  sort(v.begin(), v.end());
  if (binary_search(v.begin(), v.end(), el))  cout << "Found\n"; // you can also use search as search(v.begin(), v.end(), el)
  else cout << "Not Found\n";
  return 0;
}
