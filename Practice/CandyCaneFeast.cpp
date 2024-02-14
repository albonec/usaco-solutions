#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int N, M;
    cin >> N >> M;
    ll cows[N];
    for (int i = 0; i < N; i++) {
        cin >> cows[i];
    }
    ll cane, current_height, candy_eaten;
    for (int i = 0; i < M; i++) {
        cin >> cane;
        current_height = 0;
        for (int j = 0; j < N && cane > current_height; j++) {
            if (cows[j] > current_height) {
                candy_eaten = min(cows[j], cane) - current_height;
                cows[j] += candy_eaten;
                current_height += candy_eaten;
            }
        }
    }
    for (auto& c: cows) {
        cout << c << endl;
    }
    return 0;
}