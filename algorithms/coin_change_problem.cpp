#include<iostream>
#include<vector>
int _tmain(int argc, _TCHAR* argv[])
{
    int CoinChange(vector<vector<int>> table,vector<int> nums, vector<int> row, int sum, int n);
    vector<int> nums{2, 3, 8, 10 };
    int n = nums.size();
    int sum = 54;
    int i, j = 0;
    vector<vector<int>> table;
    vector<int> row;
    for (j = 0; j <= sum; j++)      //initialize first row of solution table to an out of range value.
    {
        row.push_back(100000);
        cout << " " << "x";
    }
    table.push_back(row);
    cout << "\n";
    row.clear();
    cout<<CoinChange(table, nums, row, sum, n);
    system("pause");
    return 0;
}

int CoinChange(vector<vector<int>> table, vector<int> nums,vector<int> row, int sum, int n)
{

    int i = 0;
    int j = 0;
    int total = 0;
for (i = 1; i <= n; i++)
{
    for (j = 0; j <= sum; j++)
    {
        if (nums[i - 1]>j)    //check if the current coin's value is greater than the sum and push back previous row's value if true.
        {
            row.push_back(table[i - 1][j]);
        }
        else
        {

            if (table[i - 1][j] < 1 + row[j - nums[i - 1]] && table[i - 1][j] < 1 + table[i - 1][j - nums[i - 1]])     //check if the previous row's value is the minimum
            {
                if (nums[i - 1] == j)    //check if the sum is equal to the value of the current coin and push back a 1 if true.
                {
                    row.push_back(1);
                }
                else    //push back the previous row's value if false.
                {
                    row.push_back(table[i - 1][j]);
                }
            }
            else
            {
                if (1 + row[j - nums[i - 1]] < 1 + table[i - 1][j - nums[i - 1]])
                {
                    row.push_back(1 + row[j - nums[i - 1]]);
                }
                else
                {
                        row.push_back(1 + table[i - 1][j - nums[i - 1]]);
                }
            }
        }
    }
    table.push_back(row);
    row.clear();

}
return table[i-1][j-1];
}
