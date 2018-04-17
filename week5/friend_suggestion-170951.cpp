#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool CompareData(pair<int,int> a, pair<int,int> b)
{
   if (a.second > b.second) return true;
   if (a.second < b.second) return false;

   if (a.first < b.first) return true;
   if (b.first < a.first) return false;

   return false;
}


int main(){
    int n,m;
    cin>>n>>m;
    int sizelen=0;
    vector<int> adj_lst[n];
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj_lst[x-1].push_back(y-1);
        adj_lst[y-1].push_back(x-1);
    }
    for(int i=0;i<n;i++){
        sort(adj_lst[i].begin(),adj_lst[i].end());
    }
    int k=0;
    cin>>k;
    k=k-1;
    vector<int> unfriends;
    for(int i=0,j=0;i<n;){
    	if(i==k){
    		i++;
    		continue;
    	}
		if(j>adj_lst[k].size()-1){
			unfriends.push_back(i);
            i++;
            continue;
		}
       	if(i<adj_lst[k][j]){
            unfriends.push_back(i);
            i++;
        }else{
            j++;
            i++;
        }
    }
    vector<int> mutual_friends;
    sizelen=unfriends.size();
    for(int i=0;i<sizelen;i++){
    	int p=0,q=0,c=0;
    	int adj_sizeF=adj_lst[unfriends[i]].size();
    	int adj_sizeK=adj_lst[k].size();
    	while(p!=adj_sizeF&&q!=adj_sizeK){
    		if(adj_lst[unfriends[i]][p]<adj_lst[k][q]){
    			p++;
			}else if(adj_lst[unfriends[i]][p]>adj_lst[k][q]){
				q++;
			}else{
				q++;
				p++;
				c++;
			}
		}
		mutual_friends.push_back(c);
	}
	vector<pair<int,int> > pair_friends;
	sizelen=unfriends.size();
	for(int i=0;i<unfriends.size();i++){
		pair<int,int> fri=make_pair(unfriends[i]+1,mutual_friends[i]);
		pair_friends.push_back(fri);
	}
	sort(pair_friends.begin(),pair_friends.end(), CompareData);
	sizelen=pair_friends.size();
	for(int i=0;i<sizelen && i < 10;i++){
		cout<<pair_friends[i].first<<" "<<pair_friends[i].second<<endl;
	}

}
