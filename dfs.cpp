https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
class Solution {
public:
    void dfs(int n,vector<int>adj[],vector<int>&ans,int *vis)
    {
        vis[n]=1;
        ans.push_back(n);
        for(auto i:adj[n])
        {
            if(vis[i]==0)
            {
                dfs(i,adj,ans,vis);
            }
        }
        
    }
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	    int vis[V+1];
	    vector<int>ans;
	    memset(vis,0,sizeof(vis));
	    dfs(0,adj,ans,vis);
	    return ans;
	}
};
