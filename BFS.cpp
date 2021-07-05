https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
class Solution {
public:
    void bfs(int src,vector<int>adj[],vector<int>&ans,int*vis)
    {
        queue<int>q;
        q.push(src);
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
                        vis[u]=1;
            ans.push_back(u);

            for(auto i:adj[u])
            {
                if(vis[i]==0)
                {
                    vis[i]=1;
                    q.push(i);
                }
            }
        }
        
        
    }
	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    vector<int>ans;
	    int vis[V+1];
	    memset(vis,0,sizeof(vis));
	    bfs(0,adj,ans,vis);
	    return ans;
	
	    
	}
};
