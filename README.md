# PJC Semestral work - Shortest paths problem

## _Assignment:_
The implementation of a single-threaded (optionally multi-threaded) algorithm for
finding the shortest path distance between all nodes (vertices) of the weighted graph.
The input graph may be directed or undirected and it may contain the positive or
negative length edges but no negative cycles.


## _Implementation:_
For solving the given assignment, the Floyd-Warshall algorithm has been selected.
Both single and multi-threaded modes of the algorithm have been implemented.

The algorithm works with the weighted either directed or undirected graphs with positive or negative length edges but
with no negative cycles.

The algorithm expects the input graph to be in the form of adjacency matrix, as one of the forms how to represent 
the graph and the most suitable for the given algorithm.

The fundamental idea behind the single-threaded Floyd-Warhsall algorithm is based on the iteration of
the intermediate node _**`k`**_ for all pairs of starting and ending nodes _**`[i, j]`**_, 
and if any shorter path from node _**`i`**_ to node _**`j`**_ via node _**`k`**_ is found,
then its corresponding value in the distance matrix is rewritten.

The multi-threaded mode of the algorithm works on the same principle, but just properly divides
the iteration and computation of starting and ending nodes _**`[i, j]`**_ into seperate threads.

Both single and multi-threaded algorithms are implemented and can be found in source file **`Graph.cpp`**.

All additional functions for reading the inputs from file or writing the results into file are implemented in source file **`utils.cpp`**.

The program has two executables. The first one, the main one, is implemented in source file **`main.cpp`**, it implements the main functionality
of the program. It reads the input graph from file (the filename provided as program argument), computes the shortest paths between all nodes, 
writes the result into output file (the filename provided as program argument). 
This executable may be run with two additional options. The first one is **`--help`**, 
with this option the program prints the description of the program. The second one is **`-m`**, 
then the program runs the multi-threaded algorithm. If the multi-threaded mode isn't selected, 
the program runs single-threaded algorithm.

The second executable is implemented in source file **`main2.cpp`**. It measures and compares 
the time consumption by single and multi-threaded algorithm for randomly generated graph of the specified size. The size 
can be provided as a program argument.
If no program argument was provided, the program will generate a graph with default size.
This program prints time consumptions to the console in millisecond units.

## _Project building:_

```
$ git clone git@gitlab.fel.cvut.cz:ostasolg/b6b36pjc-semestral-work.git
$ cd ostasolg
$ mkdir build
$ cd build
$ cmake ..
$ make
```

## _Usage:_

It is expected that program has been built in direcotry `ostasolg/build` and data instances are in directory `ostasolg/data`.



```
$ cd ostasolg/build
$ 
$ ### Print the usage message
$ ./ostasolg_semestralka --help
$ ...

$ ### Run computation with single-threaded algorithm
$ ./ostasolg_semestralka ../data/data_01.in ../data/data_01.out
$ ...

$ ### Run computation with multi-threaded algorithm
$ ./ostasolg_semestralka -m ../data/data_01.in ../data/data_01.out
$...
```

##### Expected input file format:
Program expects the input data file with the values of adjacency matrix representing the input graph. 
Each row must be on a separate line and the values in the rows must be separated by space.
Adjacency matrix must be a square matrix with the size equal to the number of nodes in the graph. 
Each element _**`[i, j]`**_ of the adjacency matrix represents a distance between graph nodes _**`i`**_ and _**`j`**_. 
If there is no edge between two nodes, then its distance in adjacency matrix must be specified as _**`INF`**_ (infinity).

##### Output file format:
Program computes the shortest path distance between all nodes of the graph and 
writes result to the output file in the form of distance matrix. 
Each value of the distance matrix _**`[i, j]`**_ represents the shortest path 
distance from node _**`i`**_ to node _**`j`**_. Each row of the distance matrix is 
on a separate line and the values in the rows are separated by '|'. 
Distance matrix is always a square matrix with the size equal 
to the number of nodes in the graph. If there is no path from one node to another 
then its distance in the distance matrix is specified as _**`INF`**_ (infinity).

**_Example 1:_**

```text
$ ./ostasolg_semestralka ../data/data_03.in ../data/data_03.out
```

_Input file (`data/data_03.in`):_
```text
0 3 INF 7
8 0 2 INF
5 INF 0 1
2 INF INF 0

```
_Output file (`data/data_03.out`):_
```text
0  |  3  |  5  |  6
5  |  0  |  2  |  3
3  |  6  |  0  |  1
2  |  5  |  7  |  0 
```


**_Example 2:_**

```text
$ ./ostasolg_semestralka ../data/data_02.in ../data/data_02.out
```

_Input file (`data/data_02.in`):_
```text
0 6 10 inf inf inf inf inf inf inf
6 0 12 11 14 inf inf inf inf inf
10 12 0 12 inf inf 8 16 inf inf
inf 11 12 0 inf 6 3 inf inf inf
inf 14 inf inf 0 4 inf inf 6 inf
inf inf inf 6 4 0 inf inf 12 inf
inf inf 8 3 inf inf 0 inf 16 6
inf inf 16 inf inf inf inf 0 inf 8
inf inf inf inf 6 12 16 inf 0 13
inf inf inf inf inf inf 6 8 13 0
```
_Output file (`data/data_02.out`):_
```text
0  |  6  |  10  |  17  |  20  |  23  |  18  |  26  |  26  |  24
6  |  0  |  12  |  11  |  14  |  17  |  14  |  28  |  20  |  20
10  |  12  |  0  |  11  |  21  |  17  |  8  |  16  |  24  |  14
17  |  11  |  11  |  0  |  10  |  6  |  3  |  17  |  16  |  9
20  |  14  |  21  |  10  |  0  |  4  |  13  |  27  |  6  |  19
23  |  17  |  17  |  6  |  4  |  0  |  9  |  23  |  10  |  15
18  |  14  |  8  |  3  |  13  |  9  |  0  |  14  |  16  |  6
26  |  28  |  16  |  17  |  27  |  23  |  14  |  0  |  21  |  8
26  |  20  |  24  |  16  |  6  |  10  |  16  |  21  |  0  |  13
24  |  20  |  14  |  9  |  19  |  15  |  6  |  8  |  13  |  0  
```


## _Measurements:_

The second executable **`compare_measurements`** has been used to measure and compare 
the time consumption by single and multi-threaded algorithms. The program generates a random
graph of the specified size, given as a program argument.

_Simulation run - for graph with 500 nodes:_
```text

$ ./compare_measurements 500
$ Size of graph: 500
$ Needed 1968 ms to finish program in a single-threaded mode.
$ Needed 1005 ms to finish program in a multi-threaded mode.

```

_Simulation run - for graph with 1000 nodes:_
```text
$ ./compare_measurements 1000
$ Size of graph: 1000
$ Needed 16088 ms to finish program in a single-threaded mode.
$ Needed 8182 ms to finish program in a multi-threaded mode.
```

**_Measured time consumptions:_**

| **Number of nodes:** | **Single-threaded FW:** | **Multi-threaded FW:** |
|:----------------:|:-------------------:|:------------------:|
|        100       |         40 ms        |        17 ms       |
|        200       |        148 ms       |        78 ms       |
|        300       |        439 ms       |       245 ms       |
|        400       |       1013 ms       |      525 ms       |
|        500       |       1968 ms       |       1005 ms       |
|        600       |       3415 ms       |       1752 ms       |
|        700       |       5346 ms       |       2776 ms      |
|        800       |       8042 ms       |       4255 ms      |
|        900       |       11514 ms       |      5867 ms      |
|       1000       |       16088 ms      |       8182 ms      |


**Simulated measurements have proven, that for graphs with size as of 100 nodes and more, the multi-threaded algorithm works much faster.** 

**_Measurements have been performed on:_**
* **OS**: Ubuntu 20.04.1 LTS
* **CPU**: Intel® Core™ i7-6500U CPU @ 2.50GHz × 4
* **RAM**: 8 GB

