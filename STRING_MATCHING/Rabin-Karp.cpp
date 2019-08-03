#include <iostream>
#include <string>
using namespace std;


void rabinKarp(const string &txt, const string &pat, const int d, const int q)
{
    int m = pat.size(), n = txt.size();

    int h = 1; 
    // Make h = (d^(m-1))%q. It will be used to remove the first character from hash value when window is shifted.
    for (int i = 0; i < m-1; i++)
        h = (h*d)%q;
    
 
    int p = 0, t = 0; // hash value for pattern and text

    for (int i = 0; i < m; i++)
    {
        p = (d*p + pat[i])%q;
        t = (d*t + txt[i])%q;
    }

    for (int s = 0; s <= n - m; s++)
    {
        if ( p == t )
        {
            int i;
            for (i = 0; i < m; i++)
            {
                if (txt[s+i] != pat[i])
                    break;
            }
            if (i == m)
                cout << "Pattern occurs with shift "  << s <<  '\n';
        }
        if ( s < n-m )
        {
            t = (d*(t - txt[s]*h) + txt[s+m])%q;
            if (t < 0)  t = (t + q);
        }
    }
}
 

int main()
{
    string txt("People for People");
    string pat("People");
 
    const int d = 256; // d is the number of characters in input alphabet
 
    const int q = 101; // A prime number such that d*q fits within a computer word
                 // This is done so that all the multiplications with d above doesn't overflow.
    
    rabinKarp(txt, pat, d, q);
    return 0;
}
