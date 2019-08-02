#include <iostream>
#include <string>
#include <vector>

using namespace std;

void LPS(const string &pat, vector<int> &lps){
    int m = pat.size();
    lps[0] = 0;
    int q = 0;
    for (int i = 1; i < m; ++i)
    {
        while(q > 0 && pat[q] != pat[i])    q = lps[q-1];
        if(pat[q] == pat[i])    q++;
        lps[i] = q;
    }
}

void KMP(string txt, string pat)
{
    int m=pat.size(),  n=txt.size();
    std::vector<int> lps(m);

    LPS(pat, lps);

    int q = 0;  // no. of characters matched
    for(int i=0; i<n; i++){
        while(q > 0 && pat[q] != txt[i])  q = lps[q-1];
        if(pat[q] == txt[i])    q++;
        if(q == m){
            cout << "Pattern occurs with shift " << i-m+1 << '\n';
            q = lps[q-1];
        }
    }
}

int main()
{
    string txt("ABABDABACDABABCABAB");
    string pat("ABABCABAB");
    KMP(txt, pat);
    return 0;
}
