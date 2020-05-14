#include <bits/stdc++.h>
using namespace std;
int parents[100];
int find(int x)
{
    if(parents[x]==x){
        return x;
    }
    return find(parents[x]);
    
}

void unionn(int x ,int y)
{
    int find_x = find(x);
    int find_y = find(y);
    parents[find_x]=find_y;
}
int main()
{
    for(int i=0;i<100;i++)
        parents[i]=i;
    
    int N_nodes,N_edges,weight,a,b;
    vector<pair<int,pair<int,int>>>Edge;
    cin>>N_nodes>>N_edges;
    
    /// Take inputs !
    
    for(int i=0;i<N_edges;i++){
        cin>>a>>b>>weight;
        Edge.push_back(make_pair( weight ,make_pair(a,b) ) );
    }

    /// Sort the queue according to the weights "The First key"
    sort(Edge.begin(),Edge.end());
   /* cout<<"\n ------------------------------------------ \n";
    for(int i=0;i<N_edges;i++)
    {
        cout<<Edge[i].first<<" ";
        cout<<Edge[i].second.first<<" ";
        cout<<Edge[i].second.second<<"\n";
    }*/
    
    int E_mst=0; 
    int i=0;
    int TotalWeight=0;
    while (E_mst<N_nodes-1 || i<N_edges)
    {
        weight=Edge[i].first;
        a=Edge[i].second.first;
        b=Edge[i].second.second;
        
        if(find(a) != find(b))
        {
            unionn(a,b);
            TotalWeight+=weight;
            E_mst++;
        }
        i++;

    }
    cout<<TotalWeight;
    





}