/*
       Articulation points
       undirected graph
       connected graph
       nodes are numbered from 1 to n
    */
     
    #include <bits/stdc++.h>
    using namespace std;
    #define endl '\n';
    const int MXSIZE = 1e6+6;
     
     
    int parent [MXSIZE];
    int child  [MXSIZE];
    int low    [MXSIZE];
    int tym    [MXSIZE];
    bool seen  [MXSIZE];
    bool is_cut[MXSIZE];
    static int times=0;

     typedef struct u{
       int par;
       int val;
       int d;
       string color;
       bool ap;
       int low;
       u(int vals, string cols):val(vals),color(cols),ap(false) {}
       vector<u*>neigh;
       u() {};
     }u;
 vector<u*>adj[MXSIZE];

void dfs(vector<u*>adj[],u* uk){

times+=1;
uk->d=times;
uk->low=times;
uk->color="grey";
for(int k=0;k<=adj[uk->val][0]->neigh.size()-1;k++){
u*vk=adj[uk->val][0]->neigh[k];
 if(vk->val==uk->par)
 continue;

 if(vk->color=="white" && vk->val!=uk->par)
{
  vk->par=uk->val;
  dfs(adj,vk);//pas balik 
  if(uk->par==-1){
    if(uk->neigh.size()>=2){
      uk->ap=true;
    }
  }else{
    uk->low=min(uk->low,vk->low);
    if(vk->low >=uk->d){
      uk->ap=true;
    }
  }
}else if(vk->val!=uk->par && (vk->d<uk->d)){//untuk kalo ktemu back edge
uk->low=min(uk->low,vk->d); //back edge 
}
uk->color="black";


}

}



void buildgraph(){
u* n1=new u(1,"white");
u* n2=new u(2,"white");
u* n3=new u(3,"white");
u* n4=new u(4,"white");
u* n5=new u(5,"white");
u* n6=new u(6,"white");
u* n7=new u(7,"white");
u* n8=new u(8,"white");

vector<u*>v;
v.push_back(n1);
v.push_back(n3);
v.push_back(n5);
v.push_back(n4);
n2->neigh=v;
v.clear();
v.push_back(n3);
v.push_back(n2);
n1->neigh=v;
v.clear();
v.push_back(n1);
v.push_back(n2);
n3->neigh=v;
v.clear();
v.push_back(n2);
v.push_back(n5);
v.push_back(n6);
n4->neigh=v;
v.clear();
v.push_back(n2);
v.push_back(n4);
v.push_back(n6);
n5->neigh=v;
v.clear();
v.push_back(n5);
v.push_back(n4);
v.push_back(n7);
v.push_back(n8);
n6->neigh=v;
v.clear();
v.push_back(n6);
v.push_back(n8);
n7->neigh=v;
v.clear();
v.push_back(n6);
v.push_back(n7);
n8->neigh=v;
v.clear();



adj[1].push_back(n1);
adj[2].push_back(n2);
adj[3].push_back(n3);
adj[4].push_back(n4);
adj[5].push_back(n5);
adj[6].push_back(n6);
adj[7].push_back(n7);
adj[8].push_back(n8);
}


   int main(){
  
      buildgraph();
         adj[2][0]->par=-1;
      dfs(adj,adj[2][0]);
       for(int i=1;i<=8;i++){
         for(int j=0;j<adj[i].size();j++)
         if(adj[i][j]->ap==true)
         cout<<adj[i][j]->val<<" ";
       }
   }