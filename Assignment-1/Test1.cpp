//===- Software-Analysis-Teaching Assignment 1-------------------------------------//
//
//     SVF: Static Value-Flow Analysis Framework for Source Code
//
// Copyright (C) <2013->
//

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
//===-----------------------------------------------------------------------===//

/*
 // Software-Analysis-Teaching Assignment 1 : Graph Traversal
 //
 //
 */

#include "Assignment-1.h"
#include <assert.h>

void Test1()
{
  /*


      1
     /  \
    2   3
     \ /
      4
      |
      5

*/
  // init nodes
  Node *node1 = new Node(1);
  Node *node2 = new Node(2);
  Node *node3 = new Node(3);
  Node *node4 = new Node(4);
  Node *node5 = new Node(5);

  // init edges
  Edge *edge1 = new Edge(node1, node2);
  Edge *edge2 = new Edge(node1, node3);
  node1->addOutEdge(edge1);
  node1->addOutEdge(edge2);
  Edge *edge3 = new Edge(node2, node4);
  Edge *edge4 = new Edge(node3, node4);
  node2->addOutEdge(edge3);
  node3->addOutEdge(edge4);
  Edge *edge5 = new Edge(node4, node5);
  node4->addOutEdge(edge5);

  // init Graph
  Graph *g = new Graph();
  g->addNode(node1);
  g->addNode(node2);
  g->addNode(node3);
  g->addNode(node4);
  g->addNode(node5);
  // test
  std::set<std::string> expected_answer{"START: 1->2->4->5->END", "START: 1->3->4->5->END"};
  std::set<const Node *> visited;
  std::vector<const Node *> path;
  GraphTraversal *dfs = new GraphTraversal();
  dfs->DFS(visited, path, node1, node5);
  assert(dfs->getPaths() == expected_answer && "Test case 1 failed!");
  std::cout << "Test case 1 passed!\n";
}

void SimpleBranch()
{
  // Test case 2
  Node *node6 = new Node(6);
  Node *node7 = new Node(7);
  Node *node8 = new Node(8);
  Edge *edge6 = new Edge(node6, node7);
  node6->addOutEdge(edge6);
  Edge *edge7 = new Edge(node7, node8);
  node7->addOutEdge(edge7);
  Graph *g2 = new Graph();
  g2->addNode(node6);
  g2->addNode(node7);
  g2->addNode(node8);
  std::set<std::string> expected_answer2{"START: 6->7->8->END"};
  std::set<const Node *> visited;
  std::vector<const Node *> path;
  GraphTraversal *dfs2 = new GraphTraversal();
  dfs2->DFS(visited, path, node6, node8);
  assert(dfs2->getPaths() == expected_answer2 && "Test case 2 failed!");
  std::cout << "Test case 2 passed!\n";
}

void MultiplePathsVaryingLengths()
{

  /*
       9
     /   \
   10    11
         |
         12
*/
  // Nodes
  Node *node9 = new Node(9);
  Node *node10 = new Node(10);
  Node *node11 = new Node(11);
  Node *node12 = new Node(12);

  // Edges
  Edge *edge8 = new Edge(node9, node10);
  Edge *edge9 = new Edge(node9, node11);
  Edge *edge10 = new Edge(node11, node12);
  node9->addOutEdge(edge8);
  node9->addOutEdge(edge9);
  node11->addOutEdge(edge10);

  std::set<std::string> expected_answer3{"START: 9->11->12->END"};
  std::set<const Node *> visited3;
  std::vector<const Node *> path3;
  GraphTraversal *dfs3 = new GraphTraversal();
  dfs3->DFS(visited3, path3, node9, node12);

  assert(dfs3->getPaths() == expected_answer3 && "Test case 3 failed!");
  std::cout << "Test case 3 passed!\n";
}

void ComplexCycle()
{
  // Nodes
  Node *node13 = new Node(13);
  Node *node14 = new Node(14);
  Node *node15 = new Node(15);
  Node *node16 = new Node(16);
  Node *node17 = new Node(17);

  // Edges
  Edge *edge11 = new Edge(node13, node14);
  Edge *edge12 = new Edge(node13, node15);
  Edge *edge13 = new Edge(node14, node15);
  Edge *edge14 = new Edge(node14, node16);
  Edge *edge15 = new Edge(node15, node17);
  Edge *edge16 = new Edge(node16, node17);
  node13->addOutEdge(edge11);
  node13->addOutEdge(edge12);
  node14->addOutEdge(edge13);
  node14->addOutEdge(edge14);
  node15->addOutEdge(edge15);
  node16->addOutEdge(edge16);

  std::set<std::string> expected_answer4{"START: 13->14->15->17->END", "START: 13->14->16->17->END", "START: 13->15->17->END"};
  std::set<const Node *> visited4;
  std::vector<const Node *> path4;
  GraphTraversal *dfs4 = new GraphTraversal();
  dfs4->DFS(visited4, path4, node13, node17);

  assert(dfs4->getPaths() == expected_answer4 && "Test case 4 failed!");
  std::cout << "Test case 4 passed!\n";
}

void DisconnectedSubgraphs()
{
  // Nodes
  Node *node18 = new Node(18);
  Node *node19 = new Node(19);
  Node *node20 = new Node(20);
  Node *node21 = new Node(21);
  Node *node22 = new Node(22);

  // Edges
  Edge *edge17 = new Edge(node18, node19);
  Edge *edge18 = new Edge(node19, node20);
  Edge *edge19 = new Edge(node21, node22);
  node18->addOutEdge(edge17);
  node19->addOutEdge(edge18);
  node21->addOutEdge(edge19);

  std::set<std::string> expected_answer5{"START: 18->19->20->END"};
  std::set<const Node *> visited5;
  std::vector<const Node *> path5;
  GraphTraversal *dfs5 = new GraphTraversal();
  dfs5->DFS(visited5, path5, node18, node20);

  assert(dfs5->getPaths() == expected_answer5 && "Test case 5 failed!");
  std::cout << "Test case 5 passed!\n";
}

void EmptyGraph()
{
  Node *node20 = new Node(20);
  Node *node21 = new Node(21);
  std::set<std::string> expected_answer6{"START: END"};
  std::set<const Node *> visited6;
  std::vector<const Node *> path6;
  GraphTraversal *dfs6 = new GraphTraversal();
  dfs6->DFS(visited6, path6, node20, node21);
  assert(dfs6->getPaths() == expected_answer6 && "Test case 5 failed!");
  std::cout << "Test case 5 passed!\n";
}

/// Entry of the program
int main()
{
  Test1();
  SimpleBranch();
  MultiplePathsVaryingLengths();
  ComplexCycle();
  DisconnectedSubgraphs();
  // EmptyGraph();
  return 0;
}