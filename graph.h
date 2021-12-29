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

void build_graph_cmd(pnode *head);

void insert_node_cmd(pnode *head);


// to delete the queueNode we need to do the following:
// 1. First I clean the linked list that I contain
// 2. Then I iterate over the nodes, and I clean all the edges that contain the queueNode to delete
// 3. Then and only then I free the queueNode itself. (a temp is needed here)

void delete_node_cmd(pnode *head, int nodeId);

void printGraph_cmd(pnode head); //for self debug
void deleteGraph_cmd(pnode *head);

void shortsPath_cmd(pnode head);

void TSP_cmd(pnode head);


//privat functions
void handleEdgeAdding();

void buildGraphNodes();

pnode findNode(int id, pnode *head);

void createEdge(pedge *edgesHead, pnode dest, int weight);

void freeEdges(pedge *edgeHead);

void freeGraph(pnode *pNode);

pnode addCustomNode(pnode *head, int id);

void connectEdge(int dest, int weight, node *currNode);

void handleCustomNodeAdding();

void handleDeleteNode();

void deleteSrcEdges(pnode *head, int nodeId);

double dijkstra(pnode *head, int srcNodeID, int destNodeID);

void checkMemoryAllocation(void* pointer);

void handleShortestPath();

#endif
