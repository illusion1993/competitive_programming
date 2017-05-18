#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include<bits/stdc++.h>
using namespace std;

void assign_land_id(int rows, int cols, int target_row, int target_col, int target_land_id, int** grid, int** land_id) {
	cout << "Called on " << target_row << ", " << target_col << "\n";
    // Assign id to self
    land_id[target_row][target_col] = target_land_id;
    
    // Assign to left
    if (target_col > 0 && !grid[target_row][target_col - 1] && land_id[target_row][target_col - 1] != target_land_id) {
        land_id[target_row][target_col - 1] = target_land_id;
        assign_land_id(rows, cols, target_row, target_col - 1, target_land_id, grid, land_id);
    }
    
    // Assign to right
    if (target_col < cols - 1 && !grid[target_row][target_col + 1] && land_id[target_row][target_col + 1] != target_land_id) {
        land_id[target_row][target_col + 1] = target_land_id;
        assign_land_id(rows, cols, target_row, target_col + 1, target_land_id, grid, land_id);
    }
    
    // Assign to down
    if (target_row < rows - 1 && !grid[target_row + 1][target_col] && land_id[target_row + 1][target_col] != target_land_id) {
        land_id[target_row + 1][target_col] = target_land_id;
        assign_land_id(rows, cols, target_row + 1, target_col, target_land_id, grid, land_id);
    }
}
    
int encoded_msg(int rows, int cols, int** grid) {
    int largest_landmass = 0, last_land_id = 0;

    int** land_id = (int**)malloc(rows * sizeof(int*));
    for(int i = 0 ; i < rows ; i++)
    	land_id[i] = (int*)malloc(cols * (sizeof(int)));
    for(int i = 0 ; i < rows ; i++) {
    	for (int j = 0; j < cols; j++) {
    		land_id[i][j] = 0;
    	}
    }

    for (int row_number = 0; row_number < rows; row_number++) {
        for (int col_number = 0; col_number < cols; col_number++) {
            if (!grid[row_number][col_number] && !land_id[row_number][col_number]) {
                last_land_id++;
                assign_land_id(rows, cols, row_number, col_number, last_land_id, grid, land_id);
            }
        }
    }
    
    int landmass_sizes[last_land_id + 1];
    memset(landmass_sizes, 0, sizeof(landmass_sizes));
    
    for (int row_number = 0; row_number < rows; row_number++) {
        for (int col_number = 0; col_number < cols; col_number++) {
            if (land_id[row_number][col_number]) { 
                landmass_sizes[land_id[row_number][col_number]]++;
                if (landmass_sizes[land_id[row_number][col_number]] > largest_landmass)
                    largest_landmass = landmass_sizes[land_id[row_number][col_number]];
            }
        }
    }
    return largest_landmass;
}

int main() {
    int output = 0;
    int ip1_rows = 0;
    int ip1_cols = 0;
    scanf("%d", &ip1_rows);
    scanf("%d", &ip1_cols);
    
    int** ip1 = (int**)malloc(ip1_rows*sizeof(int*));
    int ip1_init_i=0;
    for(ip1_init_i=0 ; ip1_init_i<ip1_rows ; ++ip1_init_i)
    {
        ip1[ip1_init_i] = (int*)malloc(ip1_cols*(sizeof(int)));
    }
    
    int ip1_i, ip1_j;
    for(ip1_i = 0; ip1_i < ip1_rows; ip1_i++) {
        for(ip1_j = 0; ip1_j < ip1_cols; ip1_j++) {
            int ip1_item;
            scanf("%d", &ip1_item);
            
            ip1[ip1_i][ip1_j] = ip1_item;
        }
    }
    output = encoded_msg(ip1_rows, ip1_cols,ip1);
    printf("%d\n", output);
    return 0;
}