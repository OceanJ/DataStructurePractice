#include"Graph.h"
void PrintVertex(Graph G, VertexType V)
{
	cout << G->AdjList[V - 1]->Vertex << "-->";
}
int main()
{
	Graph TestGraph = NULL;
	int Type,VNum, ENum;
	cout << "�����봴��ͼ������(1 DG,2 DN,3 UDG,4 UDN)������������ߵĸ������Կո�ָ��س�������" << endl;
	cin >> Type >> VNum >> ENum;
	TestGraph = CreateGraph(VNum,ENum,(GraphType)(Type-1));
	DisplayGraph(TestGraph);
	cout << "\n���Ա���:";
	cout << "\n��V1��ʼ���������������DFS: ";
	DFSTraverse(TestGraph, PrintVertex,1);
	cout << "\n��V1��ʼ���й����������BFS: ";
	BFSTraverse(TestGraph, PrintVertex, 1);
	//cout << "\n����������:";
	//UDNMinSpanTree_Prim(TestGraph);
	//UDNMinSpanTree_Kruskal(TestGraph);
	//cout << "\n����������Ȩ��Ȧͼ��������:";
	//TopSort(TestGraph);
	//cout << "\n����������Ȩͼ��Դ���·��:";
	//DGShortestPath(TestGraph, 1);
	cout << "\n�����������ĵ�Դ���·��:";
	DNShortestPath_Dijkstra(TestGraph, 1);
	cout << "\n��������������Ե����·��:";
	DNShortestPath_Floyd(TestGraph);
	cout << "\n��������ͼ...";
	DisposeGraph(TestGraph);
	cout << "\n���Գɹ�!";
	fflush(stdin);
	getchar();
}