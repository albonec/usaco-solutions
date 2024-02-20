#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 1;
int n, m, res, a[N];
char c[N];
signed main() {
    scanf("%lld%lld%s", &n, &m, c);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        res += a[i];
    }
    if(c[0] == 'L' && c[n - 1] == 'R')
        c[0] = ' ', c[n - 1] = ' ';
    for(int i = 1; i < n; i++)
        if(c[i - 1] == 'R' && c[i] == 'L')
            c[i - 1] = ' ', c[i] = ' ';
    for(int i = 0; i < n; i++) {
        int suma = 0, sumb = 0;
        int l = i - 1;
        if(l < 0)
            l = n - 1;
        if(c[l] != ' ' || c[i] != ' ')
            continue;
        bool flag = false;
        for(int j = l - 1; j >= 0 && !flag; j--) {
            if(c[j] == 'R')
                suma = min(suma + a[j + 1], m);
            else
                flag = true;
        }
        if(!flag) {
            for(int j = n - 1; j >= 0 && !flag; j--) {
                if(c[j] == 'R')
                    suma = min(suma + a[j + 1], m);
                else
                    flag = true;
            }
        }
        flag = false;
        for(int j = i + 1; j < n && !flag; j++) {
            if(c[j] == 'L')
                sumb = min(sumb + a[j + 1], m);
            else
                flag = true;
        }
        if(!flag) {
            for(int j = 0; j < n && !flag; j++) {
                if(c[j] == 'L')
                    sumb = min(sumb + a[j + 1], m);
                else
                    flag = true;
            }
        }
        res -= suma + sumb;
    }
    printf("%lld", res);
    return 0;
}