//Reg No. 21BCB0231
//YASH NEGI

#include<iostream> 
#include<vector>
using namespace std; 


vector<int> bellFord(int s, int t, vector<vector<int>> &g){ 
    vector<int> ans(t,1e8);
    ans[s]=0;

    for(int i=0; i<t-1; i++){ 
        for(auto it: g){
            int u=it[0]; 
            int v=it[1]; 
            int w=it[2];

            if(ans[u]!=1e8 && ans[u]+w<ans[v]) 
            ans[v]=ans[u]+w;
        }
    }

    for(auto it: g){ 
        int u=it[0]; 
        int v=it[1]; 
        int w=it[2];
    if(ans[u]!=1e8 && ans[u]+w<ans[v]) 
    return {-1};
    }

    return ans;
}


int main(){
    vector<vector<int>> 
    g={{0,1,11},{0,2,17},{1,2,5},{1,4,18},{2,1,5},{2,3,15},{2,4,12},{3,2,15},
    {3,4,21},{4,1,18},{4,2,12},{4,3,12}};
    vector<int> v=bellFord(0,5,g);
    cout<<"Result of distance vector Routing is: "<<endl; 
    for(int i=0; i<v.size(); i++){
        if(i==0) cout<<"Eve -> "<<v[i]<<endl; 
        if(i==1) cout<<"Clog -> "<<v[i]<<endl; 
        if(i==2) cout<<"Dodo -> "<<v[i]<<endl; 
        if(i==3) cout<<"Adam -> "<<v[i]<<endl; 
        if(i==4) cout<<"Bert -> "<<v[i]<<endl;
    }
}
