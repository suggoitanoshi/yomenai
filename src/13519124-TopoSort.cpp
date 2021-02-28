#include<iostream>
#include<vector>
#include<map>
#include "13519124-TopoSort.hpp"

std::vector<std::vector<std::string>*>* TopoSort(const Graph& g){
  Graph gg(g);
  std::vector<Node*> nodes = gg.getNodes();
  std::vector<std::vector<std::string>*>* theReturn;
  std::vector<std::string>* currentIter = new std::vector<std::string>;
  for(Node* n: nodes){
    if(n->getPrereqs() == 0){
      currentIter->push_back(n->getName());
    }
  }
  for(std::string name: *currentIter){
    gg.removeNode(name);
  }
  if(gg.getNodes().size() > 0)
    theReturn = TopoSort(gg);
  else
    theReturn = new std::vector<std::vector<std::string>*>;
  theReturn->push_back(currentIter);
  return theReturn;
}