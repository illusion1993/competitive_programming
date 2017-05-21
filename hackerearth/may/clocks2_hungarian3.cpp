#include <bits/stdc++.h>
using namespace std;

#define INF (0x7FFFFFFF)
int size1, size2;
#define verbose (0)

int Array[17][50];
char Result[17][50];    // used as boolean

void initArray()
{
    int i,j;

    for (i = 0;i<size1;++i)
        for (j = 0;j<size2;++j)
            Array[i][j] = 99999999;
}

int hungarian(){
    int i,j;
    // int false = 0,true = 1;

    unsigned int m = size1,n = size2;
    int k;
    int l;
    int s;
    int col_mate[17] = {0};
    int row_mate[50] = {0};
    int parent_row[50] = {0};
    int unchosen_row[17] = {0};
    int t;
    int q;
    int row_dec[17] = {0};
    int col_inc[50] = {0};
    int slack[50] = {0};
    int slack_row[50] = {0};
    int unmatched;
    int cost = 0;

    for (i = 0;i<size1;++i)
        for (j = 0;j<size2;++j)
            Result[i][j] = false;

    // Begin subtract column minima in order to start with lots of zeroes 12
    if (verbose) printf("Using heuristic\n");
    for (l = 0;l<n;l++)
    {
        s = Array[0][l];
        for (k = 1;k<n;k++)
            if (Array[k][l]<s)
                s = Array[k][l];
        cost += s;
        if (s != 0)
            for (k = 0;k<n;k++)
                Array[k][l] -= s;
    }
    // End subtract column minima in order to start with lots of zeroes 12

    // Begin initial state 16
    t = 0;
    for (l = 0;l<n;l++)
    {
        row_mate[l] =  -1;
        parent_row[l] =  -1;
        col_inc[l] = 0;
        slack[l] = INF;
    }
    for (k = 0;k<m;k++)
    {
        s = Array[k][0];
        for (l = 1;l<n;l++)
            if (Array[k][l]<s)
                s = Array[k][l];
        row_dec[k] = s;
        for (l = 0;l<n;l++)
            if (s == Array[k][l] && row_mate[l]<0)
            {
                col_mate[k] = l;
                row_mate[l] = k;
                if (verbose)
                    printf("matching col %d == row %d\n",l,k);
                goto row_done;
            }
        col_mate[k] =  -1;
        if (verbose)
            printf("node %d: unmatched row %d\n",t,k);
        unchosen_row[t++] = k;
    row_done:
        ;
    }
    // End initial state 16
     
    // Begin Hungarian algorithm 18
    if (t == 0)
        goto done;
    unmatched = t;
    while (1)
    {
        if (verbose)
            printf("Matched %d rows.\n",m-t);
        q = 0;
        while (1)
        {
            while (q<t)
            {
                // Begin explore node q of the forest 19
                {
                    k = unchosen_row[q];
                    s = row_dec[k];
                    for (l = 0;l<n;l++)
                        if (slack[l])
                        {
                            int del;
                            del = Array[k][l]-s+col_inc[l];
                            if (del<slack[l])
                            {
                                if (del == 0)
                                {
                                    if (row_mate[l]<0)
                                        goto breakthru;
                                    slack[l] = 0;
                                    parent_row[l] = k;
                                    if (verbose)
                                        printf("node %d: row %d == col %d--row %d\n",
                                            t,row_mate[l],l,k);
                                    unchosen_row[t++] = row_mate[l];
                                }
                                else
                                {
                                    slack[l] = del;
                                    slack_row[l] = k;
                                }
                        }
                    }
                }
                // End explore node q of the forest 19
                q++;
            }
     
            // Begin introduce a new zero into the matrix 21
            s = INF;
            for (l = 0;l<n;l++)
                if (slack[l] && slack[l]<s)
                    s = slack[l];
            for (q = 0;q<t;q++)
                row_dec[unchosen_row[q]] += s;
            for (l = 0;l<n;l++)
                if (slack[l])
                {
                    slack[l] -= s;
                    if (slack[l] == 0)
                    {
                        // Begin look at a new zero 22
                        k = slack_row[l];
                        if (verbose)
                            printf(
                                "Decreasing uncovered elements by %d produces zero at [%d,%d]\n",
                                s,k,l);
                        if (row_mate[l]<0)
                        {
                            for (j = l+1;j<n;j++)
                                if (slack[j] == 0)
                                    col_inc[j] += s;
                            goto breakthru;
                        }
                        else
                        {
                            parent_row[l] = k;
                            if (verbose)
                                printf("node %d: row %d == col %d--row %d\n",t,row_mate[l],l,k);
                            unchosen_row[t++] = row_mate[l];
                        }
                        // End look at a new zero 22
                    }
                }
                else
                    col_inc[l] += s;
            // End introduce a new zero into the matrix 21
        }
    breakthru:
        // Begin update the matching 20
        if (verbose)
            printf("Breakthrough at node %d of %d!\n",q,t);
        while (1)
        {
            j = col_mate[k];
            col_mate[k] = l;
            row_mate[l] = k;
            if (verbose)
                printf("rematching col %d == row %d\n",l,k);
            if (j<0)
                break;
            k = parent_row[j];
            l = j;
        }
        // End update the matching 20
        if (--unmatched == 0)
            goto done;
        // Begin get ready for another stage 17
        t = 0;
        for (l = 0;l<n;l++)
        {
            parent_row[l] =  -1;
            slack[l] = INF;
        }
        for (k = 0;k<m;k++)
            if (col_mate[k]<0)
            {
                if (verbose)
                    printf("node %d: unmatched row %d\n",t,k);
                unchosen_row[t++] = k;
            }
        // End get ready for another stage 17
    }
    done:

    // Begin doublecheck the solution 23
    for (k = 0;k<m;k++)
        for (l = 0;l<n;l++)
            if (Array[k][l]<row_dec[k]-col_inc[l])
                exit(0);
    for (k = 0;k<m;k++)
    {
        l = col_mate[k];
        if (l<0 || Array[k][l] != row_dec[k]-col_inc[l])
            exit(0);
    }
    k = 0;
    for (l = 0;l<n;l++)
        if (col_inc[l])
            k++;
    if (k>m)
        exit(0);
    // End doublecheck the solution 23
    // End Hungarian algorithm 18

    for (i = 0;i<m;++i)
    {
        Result[i][col_mate[i]] = true;
     /*TRACE("%d - %d\n", i, col_mate[i]);*/
    }
    for (k = 0;k<m;++k)
    {
        for (l = 0;l<n;++l)
        {
            /*TRACE("%d ",Array[k][l]-row_dec[k]+col_inc[l]);*/
            Array[k][l] = Array[k][l]-row_dec[k]+col_inc[l];
        }
        /*TRACE("\n");*/
    }
    for (i = 0;i<m;i++)
        cost += row_dec[i];
    for (i = 0;i<n;i++)
        cost -= col_inc[i];
    if (verbose) printf("Cost is %d\n",cost);
    return cost;
}

vector<int> clk_vec(string s) {
    vector<int> ans;
    ans.push_back(((int)s[0] - 48) * 10 + ((int)s[1] - 48));
    ans.push_back(((int)s[3] - 48) * 10 + ((int)s[4] - 48));
    ans.push_back(((int)s[6] - 48) * 10 + ((int)s[7] - 48));
    return ans;
}

int shift_hand(int hand_value, int hand_index, int shift) {
    if (hand_index) {
        if (shift > 0) {
            if (hand_value == 59) return 0;
            return hand_value + 1;
        }
        else {
            if (hand_value == 0) return 59;
            return hand_value - 1;
        }
    }
    else {
        if (shift > 0) {
            if (hand_value == 23) return 0;
            return hand_value + 1;
        }
        else {
            if (hand_value == 0) return 23;
            return hand_value - 1;
        }
    }
}

int set_alarm(vector<int> clk, vector<int> alm, int hand, int cost_so_far) {
    if (hand < 0) return cost_so_far;
    int direc, indirec, min_cost = INT_MAX;
    vector<int> clk_now;
    direc = abs(clk[hand] - alm[hand]);
    indirec = (hand) ? 60 - direc : 24 - direc;
    if (direc <= indirec) {
        clk_now = clk;
        clk_now[hand] = alm[hand];
        min_cost = min(min_cost, set_alarm(clk_now, alm, hand - 1, cost_so_far + direc));
    }
    if (indirec <= direc) {
        clk_now = clk;
        if (hand) {
            clk_now[hand - 1] = (clk[hand] > alm[hand]) ? 
                shift_hand(clk_now[hand - 1], hand - 1, 1) :
                shift_hand(clk_now[hand - 1], hand - 1, -1);
            if (hand - 1) {
                if (clk_now[hand - 1] == 0)
                    clk_now[hand - 2] = shift_hand(clk_now[hand - 2], hand - 2, 1);
                else if (clk_now[hand - 1] == 59)
                    clk_now[hand - 2] = shift_hand(clk_now[hand - 2], hand - 2, -1);
            }
        }
        min_cost = min(min_cost, set_alarm(clk_now, alm, hand - 1, cost_so_far + indirec));
    }
    return min_cost;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int t, n, k;
    string s;
    vector<string> clocks;
    cin >> t;
    while(t--) {
        initArray();
        clocks.clear();
        cin >> n >> k;
        
        size1 = k;
        size2 = n;

        while(n--) {
            cin >> s;
            clocks.push_back(s);
        }
        for (int r = 0; r < k; r++) {
            cin >> s;
            for (int i = 0; i < clocks.size(); i++) {
                Array[r][i] = set_alarm(clk_vec(clocks[i]), clk_vec(s), 2, 0);
            }
        }
        cout << hungarian() << "\n";
    }
    return 0;
}

/*

6
1 1
11:59:59
12:00:00
1 1
06:09:48
05:04:52
1 1
07:00:28
06:59:58
1 1
07:00:29
06:59:58
1 1
07:00:28
07:00:58
1 1
10:10:10
05:02:58

*/