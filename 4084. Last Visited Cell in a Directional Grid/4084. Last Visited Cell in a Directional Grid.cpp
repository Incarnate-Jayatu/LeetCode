class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        vector<vector<char>> matrix = grid;
        int m=matrix.size();
        int n=m>0?matrix[0].size():0;
        int r=0, c=0;
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        visited[0][0]=true;
        while(true){
            char move=matrix[r][c];
            int dr=0, dc=0;
            if(move=='L') dc=-1;
            else if(move=='R') dc=1;
            else if(move=='U') dr=-1;
            else if(move=='D') dr=1;

            int nr=r+dr;
            int nc=c+dc;

            if(nr>=0 && nr<m && nc>=0 && nc<n && !visited[nr][nc]){
                r=nr;
                c=nc;
                visited[r][c]=true;
                
            }else{
                break;
            }
        }
        return {r,c};
    }
};
