#ifndef _bd_graph_h_
#define _bd_graph_h_

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#include "bd_array.h"

// values has n ints, indicies [0, n-1]
// adj_list is a 1bigchunk array thats num_nodes by num_nodes
// for now imma just allocate the number of nodes at construction
// otherwise id need to make a bd_array that can hold pointers
//
// https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)Graphs.html
//
typedef struct bd_graph {
  int32_t num_nodes;
  int32_t* values;
  int32_t* adj_list;
} bd_graph;

// values is an array of size num_nodes
// edges is an array of 2*num_edges
bd_graph bd_graph_init(int32_t num_nodes, int32_t* values, int32_t num_edges,
                      int32_t* edges );

#endif
