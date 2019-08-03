#include <iostream>
#include <string>
#include <vector>

using namespace std;

void LPS(const string &pat, vector<int> &lps){
    int m = pat.size();
    lps[0] = 0; // For 1 length string there is no "proper" prefix which is also a suffix.
    int q = 0; // no. of characters matched
    
    for (int i = 1; i < m; ++i)
    {
        while(q > 0 && pat[q] != pat[i])    // This loop runs maximum 'm' times in total
            q = lps[q-1];
        if(pat[q] == pat[i])    q++;
        lps[i] = q;
    }
    /*
    q increases in line no. 15. While loop can decrease q to 0. 
    Since q increases one at a time and can increase to 'm' at maximum, while loop runs maximum 'm' times in total.
    So time complexity is O(m).
    */
}

void KMP(string txt, string pat)
{
    int m=pat.size(),  n=txt.size();
    std::vector<int> lps(m);

    LPS(pat, lps);

    int q = 0;  // no. of characters matched
    for(int i=0; i<n; i++){
        while(q > 0 && pat[q] != txt[i])  // This loop runs maximum 'm' times in total
            q = lps[q-1];
        if(pat[q] == txt[i])    q++;
        if(q == m){
            cout << "Pattern occurs with shift " << i-m+1 << '\n';
            q = lps[q-1];
        }
    }
    /*
    Using same logic as used in LPS the time complexity of above loop is O(n).
    So total time complexity is O(n+m).
    */
    
}

int main()
{
    string txt("ABABDABACDABABCABAB");
    string pat("ABABCABAB");
    KMP(txt, pat);
    return 0;
}
