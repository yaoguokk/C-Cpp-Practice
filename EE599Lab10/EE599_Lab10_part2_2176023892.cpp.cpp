#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;
struct Edge 
{ 
    int src, dest, weight; 
}; 
struct Node{
    int dist;
    int parent;
};
class Graph{
public:
    int V;
    int E;
    vector<Edge> edge;

public:
    Graph(int V);
    void addEdge(int src,int dest, int weight);
    void GBellmanFord(int src);
};

void readfile(string filename,int &num,vector<string> *a){
    ifstream infile;
    infile.open(filename.c_str());
    while(!infile.eof()){
        string temp;
        infile>>temp;
        a->push_back(temp);
        num++;
    }
    
   
    infile.close();
}
void initialGraph(Graph &g, vector<string> *li,int num){
    // void Graph::addEdge(int, int);
    vector<string>::iterator a;
    int column= 0;
    for(a = li->begin();a!=li->end();a++){
        int row = 0;
        int n = (*a).length(); 
        char str[n + 1]; 
        strcpy(str, (*a).c_str());
    
        char *pch = strtok(str,",");
        while(pch!=NULL ){
            char p = '*';
            if(*pch != p && *pch != '0'){
                //&& *pch != '0'
                int inter = atoi(pch);
                g.addEdge(column,row,inter);
            }
            row++;
            pch = strtok (NULL, ",");
        }
        column++;
    }
 
}
//reference http://www.cplusplus.com/reference/cstring/strtok/


Graph::Graph(int V){
    this->V = V;  
}

void Graph::addEdge(int src,int dest, int weight){
    struct Edge a;
    a.dest= dest;
    a.src = src;
    a.weight = weight;
    edge.push_back(a);
    //  cout << "index:"<<edge.size()<<" from "<<src<<" to "<<dest<<": "<< weight<<"; ";
        
}

void Graph::GBellmanFord(int src=0){
    void outputfile(string,Node *,int,bool);
    int E = edge.size();
    int i,j;
    //initial all distance from src to other vertices also the parent of each vertices
    Node nodes[V];
    for(i=0;i<V;i++){
        nodes[i].dist=__INT_MAX__;
        nodes[i].parent = -1;
    }
    
    nodes[src].dist=0;
    nodes[src].parent = -1;

    //relax all edges for V-1 times update if smaller distance is founded
    for(i=1; i< V; i++){
        for(j=0;j<E;j++){
            int u = edge[j].src;
            int v = edge[j].dest;
            int weight = edge[j].weight;
            if(nodes[u].dist!=__INT_MAX__ && (nodes[u].dist+weight) < nodes[v].dist){
                nodes[v].dist = nodes[u].dist+weight;
                nodes[v].parent = u;
            }
                
        }
    }   

//check for negative weight cycle, if distance change after V-1 cycle, there is negative loop
    bool is_cycle ;
    for(i=0;i<E;i++){
        int u = edge[i].src;
        int v = edge[i].dest;
        int weight = edge[i].weight;
        if(nodes[u].dist!=__INT_MAX__ && nodes[u].dist + weight < nodes[v].dist){
            cout<<"there is negative cycle"<<endl;
            is_cycle =  true;
        }else{
            is_cycle = false;
        }
    }

    
    string nameout = "output2.txt";
    outputfile(nameout,nodes,V,is_cycle);

   
}
//reference https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23/

void outputfile(string filename,Node *nodes,int V,bool is_cycle){
    int i,j;
    ofstream outfile;
    outfile.open(filename.c_str());
    for(i=0;i<V;i++){
        outfile << nodes[i].dist;
        if(i<V-1)
            outfile << ',';
    }
    outfile << '\n';
    for(i=0;i<V;i++){
        int j=i;
        // outfile<<j;
        stack<int> numvec;
        numvec.push(j);
        while(nodes[j].parent!=-1){
            // outfile <<"->" <<nodes[j].parent;
            // cout << nodes[j].parent<<" ";
            numvec.push(nodes[j].parent);
            j=nodes[j].parent;
        }
        // numvec.push(0);
        // cout << numvec.size()<<endl;  
        // cout <<"top is "<<numvec.top();
        int count1=0;
        while(!numvec.empty()){
            if(count1!=0){
                outfile<<"->";
            }
            outfile<<numvec.top();
            count1++;
            numvec.pop();
        }
        outfile <<"\n";
        
    }
    if(is_cycle){
        outfile<<"Negative Loop Detected";
    }
}
   

int main(int argc,char** argv){
 if(argc<2){
        cout<<"invalid input"<<endl;
        return 0;
    }
    string name = argv[1];
    vector<string> *li = new vector<string>;
    int num=0;
   
    readfile(name,num,li); 
    Graph g(num);
    initialGraph(g,li,num);
    g.GBellmanFord(0);
  
} 
