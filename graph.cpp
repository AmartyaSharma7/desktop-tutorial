	//https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
    //bfs
    vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	   
	   vector<int> bfs; 
	    vector<int> vis(V, 0); 
	    queue<int> q; 
	    q.push(0); 
	    vis[0] = 1; 
	    while(!q.empty()) {
	        int node = q.front();
	        q.pop(); 
	        bfs.push_back(node); 
	        
	        for(auto it : adj[node]) {
	            if(!vis[it]) {
	                q.push(it); 
	                vis[it] = 1; 
	            }
	        }
	    }
	    
	    return bfs;
	}


//dfs
 void dfsrec(vector<int> adj[],int s,bool visited[],vector<int> &res){
    
    visited[s]=true;
    res.push_back(s);
    for(int u : adj[s]){
        if(visited[u] == false){
            dfsrec(adj,u,visited,res);
        }
    }
    
}
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> res;
        bool visited[V];
        for(int i=0;i<V;i++){
            visited[i]=false;
        }
        for(int i=0;i<V;i++){
            if(visited[i]==false)
              dfsrec(adj,i,visited,res);
        }
        return res;
    }
    