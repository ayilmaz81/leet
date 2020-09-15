#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


struct UF{
  void merge(int v1, int v2){
      auto high = find(v1);
      auto low = find(v2);
      if (high.first != low.first){

          if(high.second<low.second){
              swap(high,low);
          }
          parent[low.first].first = high.first;
          parent[high.first].second += parent[low.first].second;
          parent[low.first].second = 0;
      }
  }  
  pair<int,int> find(int v){
      if (parent[v].first == -1) return {v,parent[v].second};
      auto ret = find(parent[v].first);
      parent[v].first = ret.first;
      return ret;
  }
  //parent/rank.
  vector<pair<int,int> > parent;
};

void printParents( UF &uf){
    
    for (int i = 0;i<uf.parent.size();++i){
        auto p = uf.find(i);
        cout<<i<<" : "<<p.first<<","<<p.second<<'\n';
    }
    cout<<"==========\n";
}

namespace DetectCycleIndirectedGraph{
    void Solve(vector<pair<int,int> > &graph, int vertices){
        UF uf;
        uf.parent = vector<pair<int,int>>(vertices,{-1,1});

        for (auto&v:graph){
            uf.merge(v.first, v.second);
            printParents(uf);
        }

    }

    pair<vector<pair<int,int>>, int>   Input() {
        
        int n,v;
        cin>>n>>v;
        pair<vector<pair<int,int>> , int> ret;
        ret.second = v;
        ret.first = vector<pair<int,int>> (n);
        while(n--){
            cin>>ret.first[n].first>>ret.first[n].second;
        }
        reverse(ret.first.begin(),ret.first.end());
        return ret;
    }
}
