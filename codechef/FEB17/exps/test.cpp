#include<bits/stdc++.h>
using namespace std;

int n;
long long l, r, a[1000000], tri_count = 0;
vector<pair<long long, long long> > triangle_intervals;
stack<pair<long long, long long> > final_intervals;

bool sortInterval(const pair<long long, long long> &a, const pair<long long, long long> &b) {
    return a.first < b.first;
}

bool isOverlap(pair<long long, long long> a, pair<long long, long long> b) {
    return (max(a.first, b.first) <= min(a.second, b.second) + 1);
}

bool isValidInterval(pair<long long, long long> a) {
    return (max(a.first, l) <= min(a.second, r));
}

pair<long long, long long> getValidInterval(pair<long long, long long> a) {
    return make_pair(max(a.first, l), min(a.second, r));
}

pair<long long, long long> mergeIntervals(pair<long long, long long> a, pair<long long, long long> b) {
    return make_pair(min(a.first, b.first), max(a.second, b.second));
}

void makeFinalIntervals() {
    sort(triangle_intervals.begin(), triangle_intervals.end(), sortInterval);
    if (triangle_intervals.size()) final_intervals.push(triangle_intervals[0]);

    for (int i = 1; i < triangle_intervals.size(); i++) {
        if (isOverlap(final_intervals.top(), triangle_intervals[i])) {
            final_intervals.top() = mergeIntervals(final_intervals.top(), triangle_intervals[i]);
        }
    }
}

int main() {
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    stack<pair<long long, long long> > vertex_triangles;
    for (int i = 0; i < n - 1; i++){
        //cout << "Triangle Intervals For vertex " << a[i] << endl;
        for (int j = i + 1; j < n - 1; j++) {
            //cout << "With vertex " << a[j] << ": ";
            pair<long long, long long> this_interval;
            this_interval = make_pair(a[j] - a[i] + 1, a[j] + a[i] - 1);

            //cout << this_interval.first << " - " << this_interval.second << "...";

            if (isValidInterval(this_interval)) {
                this_interval = getValidInterval(this_interval);

                //cout << "Lies in l - r range, so valid interval is: " << this_interval.first << " - " << this_interval.second << endl;

                if (vertex_triangles.empty()) vertex_triangles.push(this_interval);

                else if (isOverlap(this_interval, vertex_triangles.top())) {
                    vertex_triangles.top() = mergeIntervals(vertex_triangles.top(), this_interval);
                }

                else vertex_triangles.push(this_interval);
            }
        }
        //cout << "All intervals for i = vertex " << a[i] << endl;
        while (!vertex_triangles.empty()) {
            triangle_intervals.push_back(vertex_triangles.top());
            //cout << vertex_triangles.top().first << " - " << vertex_triangles.top().second << endl;
            vertex_triangles.pop();
        }
        //cout << "Total triangle intervals so far: " << triangle_intervals.size() << endl;
    }

    makeFinalIntervals();

    while(!final_intervals.empty()) {
        tri_count += final_intervals.top().second - final_intervals.top().first + 1;
        final_intervals.pop();
    }
    cout << tri_count;

    return 0;

}
