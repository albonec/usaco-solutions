#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void can_visit_farms(int N, int Q, vector<int>& close_times, vector<int>& visit_times, vector<pair<int, int>>& queries) {
    // Create a vector of pairs (closing time, farm number)
    vector<pair<int, int>> farm_schedule(N);
    for (int i = 0; i < N; ++i) {
        farm_schedule[i] = {close_times[i], i+1};
    }
    // Sort farms by closing time
    sort(farm_schedule.begin(), farm_schedule.end());

    for (int q = 0; q < Q; ++q) {
        int v = queries[q].first;
        int s = queries[q].second;

        // Initialize a priority queue to keep track of farms Bessie can visit
        priority_queue<int, vector<int>, greater<int>> pq;
        // Index of the next farm to visit
        int next_farm = 0;
        // Counter for the number of farms Bessie visited
        int visited_farms = 0;

        // Simulate Bessie's visits to farms starting from time s
        for (int i = 0; i < N && visited_farms < v; ++i) {
            // Check if Bessie can visit farm i
            if (s + visit_times[i] < farm_schedule[i].first) {
                visited_farms++;
            }
        }

        // Check if Bessie visited enough farms
        if (visited_farms >= v) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> close_times(N);
    vector<int> visit_times(N);
    vector<pair<int, int>> queries(Q);

    for (int i = 0; i < N; ++i) {
        cin >> close_times[i];
    }

    for (int i = 0; i < N; ++i) {
        cin >> visit_times[i];
    }

    for (int i = 0; i < Q; ++i) {
        cin >> queries[i].first >> queries[i].second;
    }

    can_visit_farms(N, Q, close_times, visit_times, queries);

    return 0;
}
