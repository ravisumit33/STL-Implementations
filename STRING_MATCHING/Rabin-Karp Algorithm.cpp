#include <iostream>
#include <string>
 
// d is the number of characters in input alphabet
#define d 256

using namespace std;

void rabinKarp(string &txt, string &pat, int q)
{
    int m = pat.size(), n = txt.size();

    int h = 1;
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
    int q = 101; // A prime number
    rabinKarp(txt, pat, q);
    return 0;
}
