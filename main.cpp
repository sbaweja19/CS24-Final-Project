#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cstring>
#include <algorithm>
#include "movies.h"
#include "utility.h"

using namespace std;

bool parseLine(string &line, string &movieName, double &movieRating);

int main(int argc, char** argv){
  if(argc < 4){
    cerr << "Usage: " << argv[ 0 ] << "arg1 arg2 arg3" << endl;
    exit(1);
  }

  bool flag = false;
  if(strcmp(argv[1], "true") == 0){
    flag = true;
  } else if(strcmp(argv[1], "false") == 0) {
    flag = false;
  } else {
    cerr << "Argument 1 must be a boolean (true/false)" << endl;
    exit(1);
  }
  
  ifstream movieFile (argv[2]);
  string line, movieName;
  double movieRating;

  if (movieFile.fail()){
    cerr << "Could not open file " << argv[2];
    exit(1);
  }

  // Create an objects of the BST class you defined 
  // to contain the name and rating in the input file

  // Read each file and store the name and rating
  MovieBST bst;
  PrefixBST pbst;
  string prefix = argv[3];

  while (getline (movieFile, line) && parseLine(line, movieName, movieRating)){
    // Use std::string movieName and double movieRating
    // to construct your Movie objects
    bst.insert(line);
    if (movieName.substr(0, prefix.size()) == prefix && strcmp(argv[1], "true") == 0){
      pbst.insert(movieName, movieRating);
    }
    //cout << movieName << " has rating " << movieRating << endl;
  }
  movieFile.close();

  if(strcmp(argv[1], "true") == 0){
    bst.printPreOrder();
    cout << endl;
    pbst.printBest(prefix);
  }

  if(strcmp(argv[1], "false") == 0){
    double w = stoi(argv[3]);
    clock_t start;
    start = clock();
    for(int i = 0; i < w; i++){
      getline (movieFile, line);
      parseLine(line, movieName, movieRating);
      bst.contains(movieName);
    }
    cout << "Average time to search: " << ((clock() - start) * 1000.0) / w << " microseconds" << endl;

    MovieBST test;

    ifstream movieFile (argv[2]);
    string line, movieName;
    double movieRating;

    ofstream visited, nodes;
    visited.open("visited.txt");
    nodes.open("nodes.txt");

    int nNodes = 0;

    while (getline (movieFile, line) && parseLine(line, movieName, movieRating)){
      test.insert(line);
      
      visited << test.depth(movieName) << endl;
      nodes << nNodes << endl;
      
      nNodes++;
    }
    visited.close();
    nodes.close();
    movieFile.close();
  }

  

  
  return 0;
}


bool parseLine(string &line, string &movieName, double &movieRating) {
  if(line.length() <= 0) return false;
  string tempRating = "";

  bool flag = false;
  movieName = tempRating = "", movieRating = 0.0, flag = false;

  for (int i = 0; i < line.length(); i++){
    if(flag) tempRating += line[i];
    else if(line[i]==','&& line[0]!='"') flag = true;
    else {
      if(i==0 && line[0]=='"') continue;
      if(line[i]=='"'){ i++; flag=true; continue;}
      movieName += line[i];
    }
  }
  
  movieRating = stod(tempRating);
  return true;
}

