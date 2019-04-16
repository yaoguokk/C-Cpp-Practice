#include <iostream>
#include <fstream>
#include <list>
#include <string.h>
#include <stdlib.h>



using namespace std;

class Graph{
    int V;
    int **A;
    list<int> *adj;

public:
    Graph(int V);
    void initial(int num, list<string> *str);
    void addEdge(int v, int w);
    void BFS(int s);
    list<int> maxClique();
};
Graph::Graph(int v){
    this->V= v;
    adj= new list<int>[V];}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void readfile(ifstream &infile,int &num,list<string> *str){
    infile>>num;
    string temp;
    
    while(getline(infile,temp)){  
        str->push_back(temp);
    }
    //pop the first empty line
    str->pop_front();
}

void Graph::initial(int num, list<string> *str){
    int i=0,j=0;


    A = new int*[V];
    for(int i=0;i<V;i++){
        A[i]=new int[V];
    }

    while(!str->empty()){
        string s = str->front();
        int n= s.length();
        char tempchar[n+1];
        char p=' ';
        strcpy(tempchar,s.c_str());

        char *pch = strtok(tempchar," ");
        j=0; /*start the row number count*/
        while(pch!=NULL){
            if(*pch != '0'){
                addEdge(i,j);
                A[i][j]=1;
            }else{
                A[i][j]=0;
            }
               
            j++;
            pch = strtok(NULL," ");
        }
        i++;
        str->pop_front();
    }
}

void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
 
    // Create a queue for BFS
    list<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
 
    // 'i' will be used to get all adjacent
    // vertices of a vertex
    list<int>::iterator i;
 
    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited, 
        // then mark it visited and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
    cout << endl;
}

list<int> Graph::maxClique(){
    list<int> result;
   
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout << A[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i =0;i<V; i++){
        result.push_back(adj[i].size());
    }



    return result;
}

int main(int argc, char** argv){
    if(argc <2){
        cout<<"invalid input "<<endl;
        return 0;
    }
    string filename = argv[1];
    ifstream infile;
    infile.open(filename.c_str());
    int num;
    list<string> *li = new list<string>;
    readfile(infile,num,li);
    Graph g(num);
    g.initial(num,li);
    g.maxClique();

    g.BFS(0);


    // list<string>::iterator it;
    // for(it = li->begin();it!=li->end();it++){
    //     cout << *it<<endl;
    // }
}