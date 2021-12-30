#ifndef GRAPH_
#define GRAPH_

typedef struct GRAPH_NODE_ *pnode;;

char c;

typedef struct edge_ {
    int weight;
    pnode dest;
    struct edge_ *next;
} edge, *pedge;


typedef struct GRAPH_NODE_ {
    int node_num;
    int dist;
    pedge edges;
    struct GRAPH_NODE_ *next;
} node, *pnode;


void insert_node_cmd(pnode *head);

//privat functions
void handleEdgeAdding();

void buildGraphNodes();

pnode findNode(int id, pnode *head);

void createEdge(pedge *edgesHead, pnode dest, int weight);

void freeEdges(pedge *edgeHead);

void freeGraph();

pnode addCustomNode(pnode *head, int id);

void connectEdge(int dest, int weight, node *currNode);

void handleCustomNodeAdding();

void handleDeleteNode();

void deleteSrcEdges(pnode *head, int nodeId);

double dijkstra(pnode *head, int srcNodeID, int destNodeID);

void checkMemoryAllocation(void *pointer);

void handleShortestPath();

void handleTSP();

int TSP(pnode *head, pnode *nodeArr, int len);

void swap(node *x, node *y);

void permute(pnode *nodeArr, int start, int end, int len, int *shortestPath);

#endif
