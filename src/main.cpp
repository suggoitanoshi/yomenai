#include<iostream>
#include<vector>
#include<fstream>

#include "parser.hpp"
#include "graph.hpp"
#include "TopoSort.hpp"
#include "Num2Roman.hpp"

int main(int argc, char ** argv){
  std::string filename, line;
  std::vector<std::string> names;
  std::ifstream fileStream;
  Graph g = Graph();

  if(argc == 1) filename = "test";
  else filename = argv[1];

  // Parsing File
  fileStream = std::ifstream(filename);
  int delimPos, curPos;
  while(getline(fileStream, line)){
    names.clear();
    parse(line, &names);
    g.addNode(names.at(0));
    for(int i = 1; i != names.size(); i++){
      g.addEdge(names.at(i), names.at(0));
    }
  }
  fileStream.close();

  std::vector<std::vector<std::string>*>* sorted = TopoSort(g);
  int counter;
  for(int c = sorted->size()-1; c >= 0; c--){
    std::cout << "Semester " << Num2Roman(sorted->size()-c) << ": ";
    counter = 1;
    for(std::string mk: *(sorted->at(c))){
      std::cout << mk;
      if(counter < sorted->at(c)->size()) std::cout << ", ";
      counter++;
    }
    std::cout << std::endl;
  }
}