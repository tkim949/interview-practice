#include <iostream>
#include <vector>

using namespace std;

//DP Bottom-up
int maxMinAlt(vector<vector<int>> & grid) {
    //set 2D vector array for dynamic programming with the same size!
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size()));
    //then, the last element set the maximum!
    dp[grid.size() -1][grid[0].size() -1] = INT_MAX; // init value

    //run through 2d array using nested for loops
    for(int row = grid.size() -1; row >= 0; row--) {

        for( int col = grid[0].size() -1; col >=0; col--) {

            if(row == 0 && col == 0) break; //break if both of row and column is 0

            if(row >= grid.size() -1 && col >= grid[0].size() -1) { // continue if both of row and colum is the largest we already knew this.
                continue;
            } else if (row == grid.size() -1){
                dp[row][col] = min(grid[row][col], grid[row][col+1]); //for elements in the last row
            } else if (col == grid[0].size()-1) {
                dp[row][col] = min(grid[row][col], grid[row+1][col]); //for elements in the last column
            } else{ //otherwise!
                dp[row][col]=min(grid[row][col], max(dp[row+1][col], dp[row][col+1])); //find the minimum from the maximum
            }
        }
    }

    return max(dp[0][1], dp[1][0]);
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    vector<vector<int>> vect {{5,1},{4,5}};
    vector<vector<int>> vect2 {{1,2,3}, {4, 5, 1}};
    cout<<"Test1: "<<maxMinAlt(vect)<<endl;
    cout<<"Test2: "<<maxMinAlt(vect2) <<endl;
    vector<vector<int>> vect3 {{7,5,3}, {2,0,9}, {4, 5, 9}};
    cout<<"Test3: "<<maxMinAlt(vect3)<<endl;

    return 0;
}