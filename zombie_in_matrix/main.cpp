#include <iostream>
#include <string>
#include <queue>

using namespace std;

int minHours(vector<vector<int>> &grid, int m, int n){

    //set variable and return, int
    queue<vector<int>> q;
    int hours=0, humans=0;

    //check zombie and put into a queue and count human! (there is only two, either zombie or human!
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (grid[i][j]==1) //this is zombie!
                q.push({i, j});
            else
                humans++;
        }
    }

    //for the direction check!
    vector<vector<int>> dir= {{-1,0}, {1,0}, {0,-1}, {0,1}}; //up, down, left, right

    //check the queue
    while (humans>0 && !q.empty()) {
        //hours++;
        bool flag = false;
        int nq=q.size();
        //run through current whole element in the queue, which are zombies!
        for (int i=0; i<nq; i++) {
            int x=q.front()[0];
            int y=q.front()[1];
            q.pop();
            //change the adjacent cell from human to zombie!
            for (int k=0;k<4; k++) { // 4 directions!
                int newx=x+ dir[k][0]; // -1, 1, 0, 0
                int newy=y+ dir[k][1]; // 0, 0, -1, 1
                //boundary check!
                if (newx<0 || newy<0 || newx>=m || newy>=n || grid[newx][newy]==1)
                    continue;
                grid[newx][newy]=1; //change to zombie
                q.push({newx, newy}); // put the new zombie cell into queue
                humans--; // if human change to zombie, decrement human
                flag = true; //this need for hour check!
            }
        }
        if(flag) hours++;
    }

    return hours;
}

int main() {
    vector<vector<int>> grid = {
            {0, 1, 1, 0, 1},
            {0, 1, 0, 1, 0},
            {0, 0, 0, 0, 1},
            {0, 1, 0, 0, 0},
    };
    int m = grid.size(), n = grid[0].size();
    cout << minHours(grid, m, n);

    return 0;
}