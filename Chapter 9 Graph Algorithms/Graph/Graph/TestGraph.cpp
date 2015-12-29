#include"Graph.h"
void PrintVertex(Graph G, VertexType V)
{
	cout << G->AdjList[V - 1]->Vertex << "-->";
}
int main()
{
	Graph TestGraph = NULL;
	int Type,VNum, ENum;
	cout << "请输入创建图的类型(1 DG,2 DN,3 UDG,4 UDN)、顶点个数、边的个数（以空格分隔回车结束）" << endl;
	cin >> Type >> VNum >> ENum;
	TestGraph = CreateGraph(VNum,ENum,(GraphType)(Type-1));
	DisplayGraph(TestGraph);
	cout << "\n测试遍历:";
	cout << "\n从V1开始进行深度优先搜索DFS: ";
	DFSTraverse(TestGraph, PrintVertex,1);
	cout << "\n从V1开始进行广度优先搜索BFS: ";
	BFSTraverse(TestGraph, PrintVertex, 1);
	//cout << "\n测试生成树:";
	//UDNMinSpanTree_Prim(TestGraph);
	//UDNMinSpanTree_Kruskal(TestGraph);
	//cout << "\n测试有向无权无圈图拓扑排序:";
	//TopSort(TestGraph);
	//cout << "\n测试有向无权图单源最短路径:";
	//DGShortestPath(TestGraph, 1);
	cout << "\n测试有向网的单源最短路径:";
	DNShortestPath_Dijkstra(TestGraph, 1);
	cout << "\n测试有向网顶点对的最短路径:";
	DNShortestPath_Floyd(TestGraph);
	cout << "\n正在销毁图...";
	DisposeGraph(TestGraph);
	cout << "\n测试成功!";
	fflush(stdin);
	getchar();
}