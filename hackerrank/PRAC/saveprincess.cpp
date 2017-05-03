#include <iostream>
#include <vector>
using namespace std;
void displayPathtoPrincess(int n, vector <string> grid){
    int p_i, p_j, m_i, m_j;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'm') {
                m_i = i;
                m_j = j;
            }
            else if (grid[i][j] == 'p') {
                p_i = i;
                p_j = j;
            }
        }
    }
    for (int i = 0; i < m_i - p_i; i++) cout << "UP\n";
    for (int i = 0; i < p_i - m_i; i++) cout << "DOWN\n";
    for (int i = 0; i < m_j - p_j; i++) cout << "LEFT\n";
    for (int i = 0; i < p_j - m_j; i++) cout << "RIGHT\n";
}
int main(void) {

    int m;
    vector <string> grid;

    cin >> m;

    for(int i=0; i<m; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    displayPathtoPrincess(m,grid);

    return 0;
}