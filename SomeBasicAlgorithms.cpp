#include<bits/stdc++.h>
using namespace std;

//General utility function to calculate the integral power of a float or int

template<class T>
double power(T n,int r){
    if(r==0) return 1;
    else{
        double k = power(n,r/2) ; 
        if (r%2 == 0) return k*k ;
        else return k*k*n ;
    }
}

unsigned long long int fibonacci(int n){
    const float phi = (sqrt(5) + 1)/2 ; 
    return round(power(phi,n)/sqrt(5)) ;
}

void printVector(vector<int> v){
    for(auto i=v.begin();i!=v.end();i++){
        cout << *i<< " ";
    }
    cout << "\n" ; 
}

template<class T>
void swap(T a, T b)
{
    T tmp = std::move(b);
    b = std::move(a);
    a = std::move(tmp);
}

//Kadanes algorithm for maximum contiguous sum subarray
template<class T>
T kadane(T* arr , int size){
    T max_so_far = 0 ;
    T max_ending_here = 0 ; 
    for(auto i=0; i< size; i++){
        max_ending_here += arr[i] ; 
        max_ending_here = max_ending_here < 0  ? 0 : max_ending_here ; 
        max_so_far = max_so_far < max_ending_here ? max_ending_here : max_so_far ;
    }
    return max_so_far ; 
}

class Graph{
    public:
        int V; 
        list<int> *adj ; 
        Graph(int V) ; 
        void addEdge(int src, int dest);
        void DFS();
        ~Graph(){
            delete [] adj; 
        }
};

Graph::Graph(int V){
    this->V = V ; 
    adj = new list<int>[V] ;
}

void Graph::addEdge(int src,int dest){
    adj[src].push_back(dest); 
}

void DFSUtil(int v, bool* visited){
    visited[v] = true ;
    cout << v << " " ;
    for(auto i=adj[v].begin() ; i!=adj[v].end();i++){
        if (!visited[i]) DFSUtil(i,visited) ; 
    }
}

void Graph::DFS(){
    bool* visited = new bool[V] ; 
    memset(visited,0,V) ; 
    for(int i=0;i<V;i++) DFSUtil(i,visited) ;
    delete [] visited; 
}

Graph makeGraph(){
    cout << "Number of vertices? " << endl ;
    int v; 
    cin >> v; 
    Graph g(v) ; 

    cout << "Number of edges? " << endl ; 
    int k ; 
    cin >> k ; 

    cout << "Enter the source and destinations" << endl ; 
    while(k--){

    
int main(){
    float arr[] = {1.2,-2,-4,5,-1.4,-2.6,4.9,4.1};

    cout << kadane(arr,sizeof(arr)/sizeof(arr[0])) << "\n"; 

}

