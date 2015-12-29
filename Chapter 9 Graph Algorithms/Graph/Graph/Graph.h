#ifndef _GRAPH_H_
#define _GRAPH_H_
#include "BaseInclude.h"
#include "Queue.h"
//ADT结构
typedef int VertexType;//顶点类型
typedef string InfoType;//附加消息类型
const int Infinity = INT_MAX/2; //防止加法溢出
enum GraphType //图的四种类型
{
	DG,DN,UDG,UDN,
};
typedef struct EdgeNode
{
	int Vertex; //边尾（弧头）顶点
	EdgeNode* NextEdge; //同起始顶点的下一条边
	InfoType Info; //额外信息
	int Weight;//无权图为无穷大，有权图为权值
}*Edge;

typedef struct VNode
{
	VertexType Vertex; //顶点数值 1,2,3,4
	Edge FristEdge; //以该顶点为起点的第一条边
}*AdjListNode; //邻接矩阵节点
typedef AdjListNode* AdjListType;
typedef struct GraphNode
{
	AdjListType AdjList;//邻接矩阵
	int VexNum, EdgeNum;//点，边数量
	GraphType Type;//图类型
}*Graph;

//ADT方法
//创建图 VNum:顶点数量 ENum：边数量 GType；图类型枚举值
Graph CreateGraph(int VNum, int ENum,GraphType GType);
//打印图的基本信息和邻接矩阵
void DisplayGraph(Graph G);
//深度优先搜索算法 
void DFSTraverse(Graph G, void(*VisitFunc)(Graph, VertexType),VertexType StartVertex);
//深度优先搜索辅助递归函数
void DFS(Graph G, VertexType V, bool* Visited, void(*VisitFunc)(Graph,VertexType));
//广度优先搜索算法
void BFSTraverse(Graph G, void(*VisitFunc)(Graph, VertexType), VertexType StartVertex);
//判断V是否为已存在的合法的点
bool IsVertex(Graph G, VertexType V);
//无向网的最小生成树Prim算法
void UDNMinSpanTree_Prim(Graph G);
//无向网的最小生成树Kruskal算法
void UDNMinSpanTree_Kruskal(Graph G);
//有向图/网的拓扑排序算法
void TopSort(Graph G);
//有向无权图的最短路径算法
void DGShortestPath(Graph G, VertexType StartVertex);
//有向网的单源最短路径Dijkstra算法(权值非负)
void DNShortestPath_Dijkstra(Graph G,VertexType StartVertex);
//有向网顶点对的最短路径Floyd算法(权值非负)
void DNShortestPath_Floyd(Graph G);
//销毁图，释放空间
void DisposeGraph(Graph G);
#endif