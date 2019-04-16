#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

void readfile(string filename,int &num,list<string> *a){
    ifstream infile;
    infile.open(filename.c_str());
    string temp1;
    infile >> temp1;
    num = atoi(temp1.c_str());
    
    while(!infile.eof()){
        string temp;
        infile>>temp;
        a->push_back(temp);
    }
    //drop the last item which is a "\n"
    a->pop_back();

    
}
class Graph{
public:
    int V;
    list<int> *adj;

public:
    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int s);
    bool isCircle(int v, bool visited[],int parent);
    bool isTree();
};
Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v,int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}
bool Graph::isCircle(int v,bool visited[],int parent){    
    list<int>::iterator it;
    visited[v] = true;
    for(it = adj[v].begin();it!=adj[v].end();it++){
        if(!visited[*it]){
            if(isCircle(*it,visited,v))
                return true;
        }else if(*it != parent)
            return true;        
    }
    return false;

}
bool Graph::isTree(){
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
  
    if (isCircle(0, visited, -1)){
            cout<<"Graph is a not valid tree"<<endl;
             return false; 
    }
    // If we find a vertex which is not reachable from 0  
    // (not marked by isCircle(), then we return false 
    for (int u = 0; u < V; u++) 
        if (!visited[u]) {
            cout<<"Graph is a not valid tree"<<endl;
           return false; 

        }
    cout<<"Graph is a valid tree"<<endl;
    return true; 
}
//https://www.geeksforgeeks.org/check-given-graph-tree/

void initialGraph(Graph &g, list<string> *li){
    list<string>::iterator a;
    for(a = li->begin();a != li->end();a++){
        int firstcomma = (*a).find(',');
        int remain = (*a).length()-firstcomma;
        string sub1 =(*a).substr(0,firstcomma);
        
        string sub2 =(*a).substr(firstcomma+1,remain);
        // int secondcomma = sub1.find(',');
        // cout << secondcomma<<endl;
        // cout <<"sub1 :"<< sub1<<" sub2: "<<sub2<<endl;
        int temp1= atoi(sub1.c_str());
        int temp2= atoi(sub2.c_str());
        // cout << temp1<<" " << temp2 <<endl;
        g.addEdge(temp1,temp2);
        
    }

    
}

int main(int argc,char** argv){
    if(argc<2){
        cout<<"invalid input"<<endl;
        return 0;
    }
    string name = argv[1];
    list<string> *li = new list<string>;
    int num;
    readfile(name,num,li);
    Graph g(num);
    initialGraph(g,li);
    //  g.BFS(0);
   g.isTree();
  

}
