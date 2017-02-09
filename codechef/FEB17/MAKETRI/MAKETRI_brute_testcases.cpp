#include<bits/stdc++.h>
using namespace std;

bool show_intervals = false;
bool show_testcase = false;

int n;
long long l, r, a[1000000], range;

long long large_rand() {
    float mod_100 = (float)(rand() % 100) / 100.0;
    long long multiplied = mod_100 * range;
    return multiplied;
}

void generate_testcase() {
    long long lim1, lim2;
    lim1 = large_rand();
    lim2 = large_rand();

    //l = min(lim1, lim2);
    //r = max(lim1, lim2);

    for (int i = 0; i < n; i++) a[i] = large_rand();
}

void print_testcase() {
    cout << "Testcase: " << endl;
    cout << n << " " << l << " " << r << endl;
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl << endl;
}




vector<pair<long long, long long> > ranges;
long long ans;

bool sortInterval(const pair<long long, long long> &a, const pair<long long, long long> &b) {
    return a.first < b.first;
}

void mergeRanges() {
    if (!ranges.size()) return;
    ans = 0;
    sort(ranges.begin(), ranges.end(), sortInterval);

    pair<long long, long long> current_merged_range;
    current_merged_range = ranges[0];

    for (int i = 1; i < ranges.size(); i++) {
        if (max(current_merged_range.first, ranges[i].first) > min(current_merged_range.second, ranges[i].second)) {
            ans += current_merged_range.second - current_merged_range.first + 1;
            if (show_intervals) cout << "(" << current_merged_range.first << " - " << current_merged_range.second << ") ";
            current_merged_range = ranges[i];
        }
        else {
            current_merged_range.first = min(current_merged_range.first, ranges[i].first);
            current_merged_range.second = max(current_merged_range.second, ranges[i].second);
        }
    }
    ans += current_merged_range.second - current_merged_range.first + 1;
    if (show_intervals) cout << "(" << current_merged_range.first << " - " << current_merged_range.second << ") ";
}


void brute() {
ranges.clear();
    pair<long long, long long> this_range;
    long long low, high;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            low = abs(a[i] - a[j]) + 1;
            high = a[i] + a[j] - 1;

            if (show_intervals) cout << "Range of triangles for " << a[i] << ", " << a[j] << " is " << low << " - " << high;

            if (max(low, l) <= min(high, r)){
                if (show_intervals) cout << ", valid range is " << max(low, l) << " - " << min(high, r);
                ranges.push_back(make_pair(max(low, l), min(high, r)));
            }
            if (show_intervals) cout << endl;
        }
    }

    if (show_intervals) cout << "Finally all ranges are: ";
    mergeRanges();
    if (show_intervals) cout << endl << "B1====================> ";
    cout << ans;
}



vector<pair<long long, long long> > all_ranges;
void brute2_insert(long long low, long long high) {
    //cout << "called to insert " << low << " - " << high << endl;
    pair<long long, long long> this_range;

    if (max(low, l) <= min(high, r)) {
        this_range = make_pair(max(low, l), min(high, r));
        bool is_covered = false;

        for (int i = 0; i < all_ranges.size(); i++) {
            if (this_range.first >= all_ranges[i].first && this_range.second <= all_ranges[i].second) {
                //cout << "Fully covered range" << endl;
                is_covered = true;
                break;
            }
            if (this_range.first < all_ranges[i].first && this_range.second >= all_ranges[i].first) {
                //cout << "Lower extension needed on " << all_ranges[i].first << " - " << all_ranges[i].second << endl;
                brute2_insert(this_range.first, all_ranges[i].first - 1);
                is_covered = true;
            }
            if (this_range.second > all_ranges[i].second && this_range.first <= all_ranges[i].second) {
                //cout << "Higher extension needed on " << all_ranges[i].first << " - " << all_ranges[i].second << endl;
                brute2_insert(all_ranges[i].second + 1, this_range.second);
                is_covered = true;
            }
        }

        if (!is_covered) {
            all_ranges.push_back(this_range);
            ans += this_range.second - this_range.first + 1;
        }
    }
}


void brute2() {

    all_ranges.clear();
    long long low, high;
    ans = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            low = abs(a[i] - a[j]) + 1;
            high = a[i] + a[j] - 1;

            if (show_intervals) cout << "Range of triangles for " << a[i] << ", " << a[j] << " is " << low << " - " << high;

            if (max(low, l) <= min(high, r)) {
                if (show_intervals) cout << ", valid range is " << max(low, l) << " - " << min(high, r);
                brute2_insert(max(low, l), min(high, r));
            }
            if (show_intervals) cout << endl;
        }
    }

    if (show_intervals) cout << "Finally all ranges are: ";
    if (show_intervals) for (int i = 0; i < all_ranges.size(); i++) cout << "(" << all_ranges[i].first << " - " << all_ranges[i].second << ") ";
    if (show_intervals) cout << endl << "B2====================> ";

    cout << ans;

}


bool DEBUG = false;
struct interval {
    long long low, high;
    int height;
    interval *left, *right;

    interval(long long l, long long h) : low(l), high(h) {
        left = right = NULL;
        height = 0;
    }
    interval(long long l, long long h, int d) : low(l), high(h), height(d) {
        left = right = NULL;
    }

    bool operator<(interval b) {
        return low < b.low;
    }

    bool operator>(interval b) {
        return low > b.low;
    }

    bool operator==(interval b) {
        return max(low, b.low) <= min(high, b.high);
        //return max(low, b.low) <= min(high, b.high) + 1;
    }

    bool operator!=(interval b) {
        return max(low, b.low) > min(high, b.high);
        //return max(low, b.low) > min(high, b.high) + 1;
    }

    interval * operator+(interval b) {
        interval * result = new interval(min(low, b.low), max(high, b.high), height);
        return result;
    }
};

ostream & operator << (ostream &o, const interval &a){
    return o << "(" << a.low << " - " << a.high << " : " << a.height << ")";
}

class IntervalTree {

    public:
        IntervalTree() {
            root = NULL;
        }

        void insert_interval(long long l, long long h) {
            interval * inserted_interval = new interval(l, h, 0);
            if (!root) root = inserted_interval;
            else root = insert_merge_balance_interval(root, inserted_interval);
        }

        long long get_total_interval_length() {
            return get_subtree_interval_length(root);
        }

        void print_tree_preorder() {
            cout << "preorder traversal:" << endl;
            print_subtree_preorder(root);
        }

    private:
        interval * root;

        void print_subtree_preorder(interval * a) {
            if (a == NULL) return;
            cout << "(" << a -> low << " - " << a -> high << " : " << a -> height << ") ";
            print_subtree_preorder(a -> left);
            print_subtree_preorder(a -> right);
        }

        long long get_subtree_interval_length(interval * a) {
            if (a == NULL) return 0;
            return get_subtree_interval_length(a -> left) + get_subtree_interval_length(a -> right) + a -> high - a -> low + 1;
        }

        interval * insert_merge_balance_interval(interval * root_interval, interval * inserted_interval) {
            if (DEBUG) cout << "Inserting " << *inserted_interval << endl;
            if (root_interval == NULL) return inserted_interval;

            interval * this_interval;

            if (*inserted_interval != *root_interval) {
                if (*inserted_interval > *root_interval) {
                    if (DEBUG) cout << "Getting into right subtree of " << *root_interval << endl;

                    root_interval -> right = insert_merge_balance_interval(root_interval -> right, inserted_interval);

                    if (get_interval_height(root_interval -> right) - get_interval_height(root_interval -> left) == 2) {
                        if (DEBUG) cout << *root_interval << " is unbalanced, ";
                        if (*inserted_interval > *root_interval -> right) {
                            if (DEBUG) cout << "going to apply RR rotation" << endl;
                            this_interval = rr_rotate(root_interval);
                            if (root_interval == root) root = this_interval;
                            return this_interval;
                        }
                        else {
                            if (DEBUG) cout << "going to apply RL rotation" << endl;
                            this_interval = rl_rotate(root_interval);
                            if (root_interval == root) root = this_interval;
                            return this_interval;
                        }
                    }
                }

                // New interval's low value is <= than root interval' low value
                else {
                    if (DEBUG) cout << "Getting into left subtree of " << *root_interval << endl;

                    root_interval -> left = insert_merge_balance_interval(root_interval -> left, inserted_interval);

                    if (get_interval_height(root_interval -> left) - get_interval_height(root_interval -> right) == 2) {
                        if (DEBUG) cout << *root_interval << " is unbalanced, ";
                        if (*inserted_interval > *root_interval -> left) {
                            if (DEBUG) cout << "going to apply LR rotation" << endl;
                            this_interval = lr_rotate(root_interval);
                            if (root_interval == root) root = this_interval;
                            return this_interval;
                        }
                        else {
                            if (DEBUG) cout << "going to apply LL rotation" << endl;
                            this_interval = ll_rotate(root_interval);
                            if (root_interval == root) root = this_interval;
                            return this_interval;
                        }
                    }
                }
            }
            else {
                if (DEBUG) cout << *inserted_interval << " intersects with " << *root_interval << endl;

                if (inserted_interval -> low < root_interval -> low) {
                    interval * low_extension = new interval(inserted_interval -> low, root_interval -> low - 1);
                    root_interval -> left = insert_merge_balance_interval(root_interval -> left, low_extension);

                    if (get_interval_height(root_interval -> left) - get_interval_height(root_interval -> right) == 2) {
                        if (DEBUG) cout << *root_interval << " is unbalanced, ";
                        if (*low_extension > *root_interval -> left) {
                            if (DEBUG) cout << "going to apply LR rotation" << endl;
                            this_interval = lr_rotate(root_interval);
                            if (root_interval == root) root = this_interval;
                            return this_interval;
                        }
                        else {
                            if (DEBUG) cout << "going to apply LL rotation" << endl;
                            this_interval = ll_rotate(root_interval);
                            if (root_interval == root) root = this_interval;
                            return this_interval;
                        }
                    }
                }

                if (inserted_interval -> high > root_interval -> high) {
                    interval * high_extension = new interval(root_interval -> high + 1, inserted_interval -> high);
                    root_interval -> right = insert_merge_balance_interval(root_interval -> right, high_extension);

                    if (get_interval_height(root_interval -> right) - get_interval_height(root_interval -> left) == 2) {
                        if (DEBUG) cout << *root_interval << " is unbalanced, ";
                        if (*high_extension > *root_interval -> right) {
                            if (DEBUG) cout << "going to apply RR rotation" << endl;
                            this_interval = rr_rotate(root_interval);
                            if (root_interval == root) root = this_interval;
                            return this_interval;
                        }
                        else {
                            if (DEBUG) cout << "going to apply RL rotation" << endl;
                            this_interval = rl_rotate(root_interval);
                            if (root_interval == root) root = this_interval;
                            return this_interval;
                        }
                    }
                }
            }
            root_interval -> height = max(get_interval_height(root_interval -> left), get_interval_height(root_interval -> right)) + 1;
            //if (DEBUG) cout << "After insertion, Updated height of " << *root_interval << " to be " << root_interval -> height << endl;
            //balance_subtree(root_interval, inserted_interval);
            return root_interval;
        }

        interval * ll_rotate(interval * critical_node) {
            interval * tmp = critical_node -> left;
            critical_node -> left = tmp -> right;
            tmp -> right = critical_node;
            critical_node -> height = max(get_interval_height(critical_node -> left), get_interval_height(critical_node -> right)) + 1;
            tmp -> height = max(get_interval_height(tmp -> left), get_interval_height(tmp -> right)) + 1;
            return tmp;
        }

        interval * rr_rotate(interval * critical_node) {
            interval * tmp = critical_node -> right;
            critical_node -> right = tmp -> left;
            tmp -> left = critical_node;
            critical_node -> height = max(get_interval_height(critical_node -> left), get_interval_height(critical_node -> right)) + 1;
            tmp -> height = max(get_interval_height(tmp -> left), get_interval_height(tmp -> right)) + 1;
            return tmp;
        }

        interval * lr_rotate(interval * critical_node) {
            critical_node -> left = rr_rotate(critical_node -> left);
            return ll_rotate(critical_node);
        }

        interval * rl_rotate(interval * critical_node) {
            critical_node -> right = ll_rotate(critical_node -> right);
            return rr_rotate(critical_node);
        }

        int get_interval_height(interval * a) {
            if (a == NULL) return -1;
            return a -> height;
        }

};

pair<long long, long long> getIntersectionRange(long long a, long long b, long long l, long long r) {

    pair <long long, long long> intersection;
    if (max(a, l) <= min(b, r)) {
        return make_pair(max(a, l), min(b, r));
    }

    return make_pair(-1, -1);

}


void i_tree() {
    IntervalTree i_tree;
    long long low, high;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            low = abs(a[i] - a[j]) + 1;
            high = a[i] + a[j] - 1;

            if (show_intervals) cout << "Range of triangles for " << a[i] << ", " << a[j] << " is " << low << " - " << high;
            if (max(low, l) <= min(high, r)) {
                if (show_intervals) cout << ", valid range is " << max(low, l) << " - " << min(high, r);
                i_tree.insert_interval(max(low, l), min(high, r));
            }
            if (show_intervals) cout << endl;
        }
    }

    if (show_intervals) cout << endl << "IT====================> ";

    cout << i_tree.get_total_interval_length();
}

int main() {
    int t, nmax;
    long long rmax;
    char ch;
    do{
        system("clear");
        cout << "Max size of testcase array: ";
        cin >> nmax;
        cout << "Max range of testcase inputs: ";
        cin >> rmax;

        for (n = 2; n <= nmax; n++) {
            for (range = 10; range <= rmax; range *= 5) {
                l = range / 5;
                r = l * 4;
                generate_testcase();
                if (show_testcase) print_testcase();
                cout << "Bruteforce: " << endl;
                brute();
                cout << endl << endl << "Bruteforce 2: " << endl;
                brute2();
                cout << endl << endl << "Interval tree: " << endl;
                i_tree();
                cout << endl << endl;
            }
        }

        cout << "More? (y/n)";
        cin >> ch;
    }
    while(ch == 'y');

    return 0;
}

/*

*/
