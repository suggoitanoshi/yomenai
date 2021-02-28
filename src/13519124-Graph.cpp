#include<vector>
#include<map>
#include<iostream>
#include<algorithm>
#include "13519124-graph.hpp"

/* Konstruktor Graph */
Graph::Graph(){}
void Graph::addNode(std::string name){
  std::vector<Node*>::iterator nodeIdx = std::find_if(nodes.begin(), nodes.end(), [&name](Node* n){ return *n == name; });
  if(nodeIdx == nodes.end()){
    nodes.push_back(new Node(name));
  }
}
void Graph::addEdge(std::string from, std::string to){
  std::vector<Node*>::iterator fromIdx = std::find_if(nodes.begin(), nodes.end(), [&from](Node* n){ return *n == from; });
  Node *f, *t;
  if(fromIdx == nodes.end()){
    f = new Node(from);
    nodes.push_back(f);
  }
  else{
    f = *fromIdx;
  }

  f->addAdjacent(to);
  std::vector<Node*>::iterator toIdx = std::find_if(nodes.begin(), nodes.end(), [&to](Node* n){ return *n == to; });
  if(toIdx == nodes.end()){
    t = new Node(to);
    nodes.push_back(t);
  }
  else{
    t = *toIdx;
  }
  t->incPrereq();
}
void Graph::removeNode(std::string from){
  std::vector<Node*>::iterator fromIdx = std::find_if(nodes.begin(), nodes.end(), [&from](Node* n){ return *n == from; });
  if(fromIdx != nodes.end()){
    std::vector<std::string> adjs = (*fromIdx)->getAdjacents();
    for(std::string adj: adjs){
      std::vector<Node*>::iterator idx = std::find_if(nodes.begin(), nodes.end(), [&adj](Node *n){ return *n == adj; });
      if(idx != nodes.end()) (*idx)->decPrereq();
    }
    nodes.erase(fromIdx);
  }
  for(Node *n: nodes){
    n->remAdjacent(from);
  }
}

Node* Graph::mostPrereqs(){
  Node* n = nodes.at(0);
  for(Node* o: nodes){
    if(o->getPrereqs() > n->getPrereqs()) n = o;
  }
  return n;
}

std::vector<Node*> Graph::getNodes() const{ return nodes; }

void Graph::printGraph(){
  for(Node *n: nodes){
    n->printNode();
  }
}

Graph::~Graph(){}

Node::Node(std::string _name){
  this->name = _name;
  this->prereqs = 0;
}

void Node::addAdjacent(std::string to){
  this->adjacents.push_back(to);
}

void Node::remAdjacent(std::string name){
  auto el = std::find(adjacents.begin(), adjacents.end(), name);
  if(el != this->adjacents.end())
    this->adjacents.erase(el);
}

void Node::incPrereq(){ this->prereqs++; }

void Node::decPrereq(){ this->prereqs--; }

int Node::getPrereqs() const { return this->prereqs; }

std::string Node::getName() const { return this->name; }

void Node::printNode(){
  std::cout << "adj. list for ";
  std::cout << name;
  std::cout << " <";
  for(std::string adj: adjacents){
    std::cout << adj << ", ";
  }
  std::cout << ">" << std::endl;
  std::cout << "prereq: " << prereqs << std::endl;
}

bool Node::operator ==(const Node& other){ return other.name == this->name; }
bool Node::operator ==(const std::string& other){ return other == this->name; }

std::vector<std::string> Node::getAdjacents() const { return adjacents; }