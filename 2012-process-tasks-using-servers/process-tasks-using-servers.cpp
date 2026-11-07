class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int m = servers.size();
        int n = tasks.size();

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>ava;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>unava;
        //push all to available queue
        for(int i=0;i<m;i++){
            ava.push({servers[i],i});
        }

        vector<int> ans(n);
        int j = 0;long long time = 0;
        while(j<n){
            // to break the loop
            bool x = true;
            //if servers become free add to available queue
            while(!unava.empty() && x){
                auto [t,i] = unava.top();
                if(t<=time){
                    unava.pop();
                    ava.push({servers[i],i});
                }
                else x = false;
            }
            //if server available assign a task
            while(!ava.empty() && j<=time && j<n){
                auto [s,idx] = ava.top();
                ava.pop();
                ans[j] = idx;
                unava.push({time+tasks[j],idx});
                j++;
            }
            
            if(ava.empty() && j <= time) {
                time = unava.top().first;
            }
            else {
                time++;
            }
        }
        return ans;
    }
};