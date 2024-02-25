//Reg No. 21BCB0231
//YASH NEGI

#include<iostream> 
#include<stdio.h> 
using namespace std; 
#define INFINITY 9999
#define max 7

void dijkstra(int G[max][max],int n,int startnode); 

int main() {
    int G[max][max]={{0,4,2,8,0,0,0},{0,0,0,0,5,0,0},{0,0,0,1,0,10,0},{0,2,0,0,7,2,0},
    {0,0,0,0,0,0,8},{0,0,0,0,0,0,3},{0,0,0,6,0,0,0}};
    int n=7; 
    int u=0;
    dijkstra(G,n,u); 
    return 0;
}

void dijkstra(int G[max][max],int n,int startnode) { 
    int cost[max][max],distance[max],pred[max];
    int visited[max],count,mindistance,nextnode,i,j; 
    for(i=0;i<n;i++)
    for(j=0;j<n;j++) 
    if(G[i][j]==0)
    cost[i][j]=INFINITY; 
    else
    cost[i][j]=G[i][j]; 
    for(i=0;i<n;i++) {
        distance[i]=cost[startnode][i]; 
        pred[i]=startnode;
        visited[i]=0;
    }
    distance[startnode]=0; 
    visited[startnode]=1; 
    count=1;
    while(count<n-1) {
        mindistance=INFINITY; 
        for(i=0;i<n;i++)
        if(distance[i]<mindistance&&!visited[i]) { 
            mindistance=distance[i];
            nextnode=i;
        }
        visited[nextnode]=1; 
        for(i=0;i<n;i++)
        if(!visited[i]) 
        if(mindistance+cost[nextnode][i]<distance[i]) {
            distance[i]=mindistance+cost[nextnode][i]; 
            pred[i]=nextnode;
        }
        count++;
    }
    for(i=0;i<n;i++) 
    if(i!=startnode) {
        cout<<"\nDistance of node"<<i+1<<"="<<distance[i]; 
        cout<<"\nPath="<<i+1;
        j=i; 
        do {
            j=pred[j]; 
            cout<<"<-"<<j+1;
        }
        while(j!=startnode);
    }
}

