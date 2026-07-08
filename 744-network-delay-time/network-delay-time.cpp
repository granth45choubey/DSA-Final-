class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> adj(n + 1);

        // Build Adjacency List
        for(int i = 0; i < times.size(); i++)
        {
            int source = times[i][0];
            int dest = times[i][1];
            int weight = times[i][2];

            adj[source].push_back({dest, weight});
        }

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        vector<int> dist(n + 1, INT_MAX);

        dist[k] = 0;

        pq.push({0, k});

        while(!pq.empty())
        {
            pair<int,int> current = pq.top();
            pq.pop();

            int d = current.first;
            int node = current.second;

            if(d > dist[node])
            {
                continue;
            }

            for(int j = 0; j < adj[node].size(); j++)
            {
                int neigh = adj[node][j].first;
                int weight = adj[node][j].second;

                if(d + weight < dist[neigh])
                {
                    dist[neigh] = d + weight;
                    pq.push({dist[neigh], neigh});
                }
            }
        }

        int ans = 0;

        for(int i = 1; i <= n; i++)
        {
            if(dist[i] == INT_MAX)
            {
                return -1;
            }

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};