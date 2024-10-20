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

void DFS_VISIT(Graph &g, Node &u)//call by reference
{
    t += 1;
    u.d = t; //set discovery time
    u.color = "GRAY";//discovering

    for (Node v : u.adj) //for each child
    {
        int j = search_node(g.nodes, v.label);//find it in nodes

        if (g.nodes[j].color.compare("WHITE") == 0)//if unvisited
            DFS_VISIT(g, g.nodes[j]);            //build up a DFS tree
    }

    u.color = "BLACK";//finished
    t += 1;
    u.f = t;//set finish time

    cout <<u.label << ".d =" << u.d << "  " << u.label << ".f = " << u.f << "\n\n";//print u
}

void DFS(Graph g)
{
    t = 0; //start timer

    for (int i = 0; i < g.nodes.size(); i++)  //for each vertex
    {
        if (g.nodes[i].color.compare("WHITE") == 0)//if unvisited
            DFS_VISIT(g, g.nodes[i]); //build a DFS tree
    }
}
// Driver code
int main()
{   //a node is constructed by label, color, depth, discovery time, and finish time
    Node n0('0', "WHITE", INT_MAX, 0, 0);
    Node n1('1', "WHITE", INT_MAX, 0, 0);
    Node n2('2', "WHITE", INT_MAX, 0, 0);
    Node n3('3', "WHITE", INT_MAX, 0, 0);

    // Create a graph by adding nodes and edges to it
    Graph g(4);

    //Starting at node 0 will generate a single DFS tree (0->1->2->3)
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

    //Depth First Traversal (return a single tree or a collection of trees, depends on the order of nodes)
    cout <<"DFS traversal. Read it bottom up because of the stack" << "\n";
    DFS(g);
    return 0;
}
