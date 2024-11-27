#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

class Solution {
private:
    void dfs(int x,int y,vector<vector<int>>&grid,int dir,int m,int n)
    {   
        // matrix out of the boundary maintain
        if(x < 0 or y < 0 or x >= m or y>=n){
            return;
        }
        if(grid[x][y] == 2 or grid[x][y] == 1){
            return;
        }
        grid[x][y] = 3;

       // according to direction we have to move into matrix
        if(dir == 1){
           dfs(x+1,y,grid,dir,m,n);
        }else if(dir == 2){
            dfs(x,y+1,grid,dir,m,n);
        }else if(dir == 3){
            dfs(x-1,y,grid,dir,m,n);
        }else{
            dfs(x,y-1,grid,dir,m,n);
        }
    }
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m,vector<int>(n,0));
        
        // setUp Grid using 1,2 to represent the guards and walls
        for(auto i: guards){
            grid[i[0]][i[1]] = 1;
        }
        // guards[i] = [rowi, coli]
        for(auto i : walls){
            // go to both of indexes value
            // mark it this cells 
            grid[i[0]][i[1]] = 2;
        }

    // A guard can see every cell in the four cardinal directions (north, east, south, or west) starting from their position unless obstructed by a wall
    // Left+right
    // top+bottom
        for(auto i : guards){
            int x = i[0];
            int y = i[1];
            dfs(x+1,y,grid,1,m,n);
            dfs(x,y+1,grid,2,m,n);
            dfs(x-1,y,grid,3,m,n);
            dfs(x,y-1,grid,4,m,n);
        }

        // count the number of ungurads cells, same to same number of encavls
        // number of islands
        int count = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 0){
                    count ++;
                }
            }
        }
       // Return the number of unoccupied cells that are not guarded.
        return count;
    }
};
