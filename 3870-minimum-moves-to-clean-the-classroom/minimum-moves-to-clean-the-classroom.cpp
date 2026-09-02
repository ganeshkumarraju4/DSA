class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        vector<vector<int>> id(m, vector<int>(n, -1));
        int k = 0;
        int sr = 0,sc = 0;

        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(classroom[r][c] == 'S'){
                    sr = r;sc = c;
                }
                else if(classroom[r][c] == 'L'){
                    id[r][c] = k++;
                }
            }
        }

        if(k==0)return 0;
        int totalMask = (1 << k) - 1;

        vector<vector<vector<int>>> best(
            m, vector<vector<int>>(n, vector<int>(1 << k, -1))
        );
        struct State{
            int r,c,mask,e,moves;
        };

        queue<State> q;
        best[sr][sc][0] = energy;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        q.push({sr,sc,0,energy,0});

        while(!q.empty()){
            State curr = q.front();
            q.pop();

            for(int d=0;d<4;d++){
                int nr = dr[d] + curr.r;
                int nc = dc[d] + curr.c;
                
                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                if (classroom[nr][nc] == 'X')
                    continue;

                int ne = curr.e - 1;

                if (ne < 0)
                    continue;

                int nmask = curr.mask;

                if (classroom[nr][nc] == 'R') {
                    ne = energy;
                }

                if (classroom[nr][nc] == 'L') {
                    nmask |= (1 << id[nr][nc]);
                }

                if (nmask == totalMask) {
                    return curr.moves + 1;
                }

                if (ne <= best[nr][nc][nmask])
                    continue;

                best[nr][nc][nmask] = ne;

                q.push({nr, nc, nmask, ne, curr.moves + 1});
            }
        }
        return -1;

    }
};