#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <list>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> iPair;
vector<int> shortestPath(int src,int V,list<pair<int,int> > adj[]){
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
    vector<int> dist(V, 99999);
    pq.push(make_pair(0, src));
    dist[src] = 0;
    while (!pq.empty()) {
        int u=pq.top().second;
        pq.pop();
        list< pair<int, int> >::iterator i;
        for (list<pair<int, int> >::iterator i=adj[u].begin(); i!=adj[u].end(); ++i) {
            int v = (*i).first;
            int weight = (*i).second;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    return dist;
}
int main(){
    int t,b,r,num,st,end,l,max=0;
    cin>>t;
    for (int i=0; i<t; i++) {
        cin>>b>>r>>num;
        list<pair<int,int> > pp[b];
        for (int j=0; j<r; j++) {
            cin>>st>>end>>l;
            pp[st].push_back(make_pair(end, l));
            pp[end].push_back(make_pair(st, l));
        }
        vector<int> vv;
        vv=shortestPath(num,b ,pp );
        max=0;
        for (int k=0; k<vv.size(); k++) {
            if (max<vv[k] && vv[k]!=99999) {
                max=vv[k];
            }
            
        }
        
        for (int l=0; l<vv.size(); l++) {
            if (vv[l]==max) {
            	cout<<l<<" ";
            }
        }
        cout<<endl;
    }
}
