#include<vector>
#include<string>
#include<map>
#ifndef _GRAPH_HPP
#define _GRAPH_HPP
class Node {
  private:
    std::string name;
    int prereqs;
    std::vector<std::string> adjacents;
  public:
    Node(std::string);
    ~Node();
    void addAdjacent(std::string);
    void remAdjacent(std::string);
    void incPrereq();
    void decPrereq();
    int getPrereqs() const;
    std::string getName() const;
    void printNode();
    bool operator ==(const Node&);
    bool operator ==(const std::string&);
    std::vector<std::string> getAdjacents() const;
};

class Graph {
  private:
    std::vector<Node*> nodes;
  public:
    Graph();
    void addNode(std::string);
    void addEdge(std::string, std::string);
    void removeNode(std::string);
    Node* mostPrereqs();
    std::vector<Node*> getNodes() const;
    void printGraph();
    ~Graph();
};
#endif