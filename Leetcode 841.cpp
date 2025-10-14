class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>visited(n,0);
        queue<int>q1;
        q1.push(0);
        visited[0]=1;

        int count =0;

        while(!q1.empty()){
            int node = q1.front();
             q1.pop();
             count++;

             for(int i = 0;i<rooms[node].size();i++){
                if(!visited[rooms[node][i]]){
                    q1.push(rooms[node][i]);
                    visited[rooms[node][i]] =1;
                }
             }
        }

        if(count==n){
            return 1;
        }
        else{
            return 0;
        }
        
    }
};