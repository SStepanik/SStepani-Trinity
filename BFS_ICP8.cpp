//Sean Stepanik
#include<list>
#include<bits/stdc++.h>
#include<iostream>
#include<queue>
using namespace std;

int t; 

class Node
{
public:
    char label;
    string color;//used in DFS only
    int depth;   //used in BFS only
    int d;       //discovery time
    int f;       //finish time
    vector<Node> adj;//adjacent list
    Node(char label, string color, int depth, int d, int f) // Constructor
    {
        this->label = label;
        this->color = color;
        this->depth = depth;
        this->d = d;
        this->f = f;
    };
};

int search_node(vector<Node> nodes, char label)//search a node in nodes by its label and return its location
{
    vector<Node>::iterator it;
    it = find_if(nodes.begin(), nodes.end(), [&label](Node const& obj)
    {
        return obj.label == label;
    } );
    if(it != nodes.end())
        return distance(nodes.begin(), it); //return position
}

class Graph
{
public:
    int n;    // No. of vertices
    vector<Node> nodes;

    Graph(int n){this->n = n;}; // Constructor

    void addNode (Node &node) {nodes.push_back(node);}

    void addEdge(Node &v, Node &w)
    {
        int i = search_node(nodes, v.label);
        nodes[i].adj.push_back(w);
        //(v.adj).push_back(w);
    }
 };


void BFS(Graph &g, Node &s)
{
    for (int i=0; i<g.nodes.size(); i++)
        if (g.nodes[i].label == s.label) //the source node
            g.nodes[i].depth = 0;     //depth = 0

    //for (int i=0; i<g.nodes.size(); i++)
    //    cout << g.nodes[i].label << " " << g.nodes[i].adj.size() << "\n";

    queue<Node> Q;                       //Q = NULL
    Q.push(s);                           //Enqueue(s)

    while (!Q.empty())                   //while Q is not empty
    {
        Node u = Q.front();              //Dequeue[u]
        Q.pop();
        int i = search_node(g.nodes, u.label);//search u in nodes
        cout << "Depth_" << g.nodes[i].depth << " " << u.label << "\n";//print u
        for (Node v : g.nodes[i].adj)              //for all adjacent nodes
        {
            int j = search_node(g.nodes, v.label);//find v in nodes
            if (g.nodes[j].depth == INT_MAX)  //if unvisited
            {
                g.nodes[j].depth = g.nodes[i].depth + 1; //increase depth
                Q.push(g.nodes[j]);                      //Enqueue[v]
            }
        }
    }
}

int main()
{   //node(label, color, depth, discovery time, finish time)
    Node n0('0', "WHITE", INT_MAX, 0, 0);
    Node n1('1', "WHITE", INT_MAX, 0, 0);
    Node n2('2', "WHITE", INT_MAX, 0, 0);
    Node n3('3', "WHITE", INT_MAX, 0, 0);

    Graph g(4);

    g.addNode(n0);
    g.addNode(n1);
    g.addNode(n2);
    g.addNode(n3);

    g.addEdge(n0, n1);
    g.addEdge(n0, n2);
    g.addEdge(n1, n2);
    g.addEdge(n2, n0);
    g.addEdge(n2, n3);
    g.addEdge(n3, n3);

    //Breath First Traversal (starting at vertex 2);
    cout <<"BFS traversal. Traverse the entire graph if starts at vertex 2" << "\n";
    BFS(g, n2);
    
    return 0;
}
