#include <bits/stdc++.h>

using namespace std;

vector< pair<int, int> > points;

bool sortBySecond(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;
}

int findMax(int left_x, int right_x, int next_point_pos) {

    if (left_x == right_x) return 0;

    if (next_point_pos == points.size()) return (right_x - left_x) * 500;

    if (points[next_point_pos].first > left_x && points[next_point_pos].first < right_x)
        return max(max((right_x - left_x) * points[next_point_pos].second, findMax(left_x, points[next_point_pos].first, next_point_pos + 1)),
                findMax(points[next_point_pos].first, right_x, next_point_pos + 1));
    else
        return findMax(left_x, right_x, next_point_pos + 1);

}

int main () {
    int n, x_tmp, y_tmp;

    cin >> n;
    while(n--) {
        cin >> x_tmp >> y_tmp;
        pair<int, int> point;
        point = make_pair(x_tmp, y_tmp);
        points.push_back(point);
    }

    sort(points.begin(), points.end(), sortBySecond);

    cout << findMax(0, 100000, 0);

	return 0;
}
