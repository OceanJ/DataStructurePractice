#ifndef _GRAPH_H_
#define _GRAPH_H_
#include "BaseInclude.h"
#include "Queue.h"
//ADT�ṹ
typedef int VertexType;//��������
typedef string InfoType;//������Ϣ����
const int Infinity = INT_MAX/2; //��ֹ�ӷ����
enum GraphType //ͼ����������
{
	DG,DN,UDG,UDN,
};
typedef struct EdgeNode
{
	int Vertex; //��β����ͷ������
	EdgeNode* NextEdge; //ͬ��ʼ�������һ����
	InfoType Info; //������Ϣ
	int Weight;//��ȨͼΪ�������ȨͼΪȨֵ
}*Edge;

typedef struct VNode
{
	VertexType Vertex; //������ֵ 1,2,3,4
	Edge FristEdge; //�Ըö���Ϊ���ĵ�һ����
}*AdjListNode; //�ڽӾ���ڵ�
typedef AdjListNode* AdjListType;
typedef struct GraphNode
{
	AdjListType AdjList;//�ڽӾ���
	int VexNum, EdgeNum;//�㣬������
	GraphType Type;//ͼ����
}*Graph;

//ADT����
//����ͼ VNum:�������� ENum�������� GType��ͼ����ö��ֵ
Graph CreateGraph(int VNum, int ENum,GraphType GType);
//��ӡͼ�Ļ�����Ϣ���ڽӾ���
void DisplayGraph(Graph G);
//������������㷨 
void DFSTraverse(Graph G, void(*VisitFunc)(Graph, VertexType),VertexType StartVertex);
//����������������ݹ麯��
void DFS(Graph G, VertexType V, bool* Visited, void(*VisitFunc)(Graph,VertexType));
//������������㷨
void BFSTraverse(Graph G, void(*VisitFunc)(Graph, VertexType), VertexType StartVertex);
//�ж�V�Ƿ�Ϊ�Ѵ��ڵĺϷ��ĵ�
bool IsVertex(Graph G, VertexType V);
//����������С������Prim�㷨
void UDNMinSpanTree_Prim(Graph G);
//����������С������Kruskal�㷨
void UDNMinSpanTree_Kruskal(Graph G);
//����ͼ/�������������㷨
void TopSort(Graph G);
//������Ȩͼ�����·���㷨
void DGShortestPath(Graph G, VertexType StartVertex);
//�������ĵ�Դ���·��Dijkstra�㷨(Ȩֵ�Ǹ�)
void DNShortestPath_Dijkstra(Graph G,VertexType StartVertex);
//����������Ե����·��Floyd�㷨(Ȩֵ�Ǹ�)
void DNShortestPath_Floyd(Graph G);
//����ͼ���ͷſռ�
void DisposeGraph(Graph G);
#endif