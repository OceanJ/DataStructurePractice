#include "Graph.h"
bool IsVertex(Graph G, VertexType V)
{
	return (V >= 1 && V <= G->VexNum);
}
//�������ӵ��ڽӱ�ĩβ
void LinkEdge(Edge List, Edge NewEdge)
{
	Edge e = List;
	while (e->NextEdge)
		e = e->NextEdge;
	e->NextEdge = NewEdge;

}

int Min(int a, int b)
{
	return a < b ? a : b;
}

//��������ͼ
Graph CreateDG(Graph G)
{
	VertexType VStart, VEnd;
	int HasInfo;
	cout << "���ڴ�������ͼ" << endl;
	for (int i = 0; i < G->EdgeNum; i++)
	{
		cout << "�������" << i + 1 << "�����Ļ�ͷ����β���Ƿ��ж�����Ϣ��0�ޣ������У���ʽΪ: VStart VEnd Bool" << endl;
		fflush(stdin);
		cin >> VStart >> VEnd >> HasInfo;
		while (!IsVertex(G, VStart) || !IsVertex(G, VEnd))
		{
			cout << "���벻�Ϸ�,����������" << endl;
			fflush(stdin);
			cin >> VStart >> VEnd >> HasInfo;
		}
		InfoType Info = "";
		if (HasInfo)
		{
			cout << "�����������Ϣ��" << endl;
			fflush(stdin);
			cin >> Info;
		}
		Edge NewEdge = new EdgeNode;
		NewEdge->Vertex = VEnd; NewEdge->Weight = Infinity; NewEdge->Info = Info;
		NewEdge->NextEdge = NULL;
		//�����Ƿ��е�һ����
		if (G->AdjList[VStart - 1]->FristEdge == NULL)
			G->AdjList[VStart - 1]->FristEdge = NewEdge;
		else
			LinkEdge(G->AdjList[VStart - 1]->FristEdge, NewEdge);
	}
	return G;
}
Graph CreateDN(Graph G)
{
	cout << "���ڴ���������" << endl;
	VertexType VStart, VEnd, Weight;
	int HasInfo;
	for (int i = 0; i < G->EdgeNum; i++)
	{
		cout << "�������"<<i+1<<"�����Ļ�ͷ����β��Ȩֵ���Ƿ��ж�����Ϣ��0�ޣ������У���ʽΪ: VStart VEnd Weight Bool" << endl;
		fflush(stdin);
		cin >> VStart >> VEnd >> Weight>>HasInfo;
		while (!IsVertex(G, VStart) || !IsVertex(G, VEnd))
		{
			cout << "���벻�Ϸ�,����������"<<endl;
			fflush(stdin);
			cin >> VStart >> VEnd >> Weight>>HasInfo;
		}
		InfoType Info = "";
		if (HasInfo)
		{
			cout << "�����������Ϣ��"<<endl;
			fflush(stdin);
			cin >> Info;
			fflush(stdin);
		}
		Edge NewEdge = new EdgeNode;
		NewEdge->Vertex = VEnd; NewEdge->Weight = Weight; NewEdge->Info = Info; NewEdge->NextEdge = NULL;
		if (G->AdjList[VStart - 1]->FristEdge == NULL)
			G->AdjList[VStart - 1]->FristEdge = NewEdge;
		else
			LinkEdge(G->AdjList[VStart - 1]->FristEdge, NewEdge);
	}
	return G;
}
Graph CreateUDG(Graph G)
{
	cout << "���ڴ�������ͼ" << endl;
	VertexType VStart, VEnd;
	int HasInfo;
	for (int i = 0; i < G->EdgeNum; i++)
	{
		cout << "�������" << i + 1 << "�������������㡢�Ƿ��ж�����Ϣ��0�ޣ������У���ʽΪ: V1 V2 Bool" << endl;
		fflush(stdin);
		cin >> VStart >> VEnd >> HasInfo;
		while (!IsVertex(G, VStart) || !IsVertex(G, VEnd))
		{
			cout << "���벻�Ϸ�,����������";
			fflush(stdin);
			cin >> VStart >> VEnd >> HasInfo;
		}
		InfoType Info = "";
		if (HasInfo)
		{
			cout << "�����������Ϣ��" << endl;
			fflush(stdin);
			cin >> Info;
		}
		Edge NewEdge1 = new EdgeNode;
		NewEdge1->Vertex = VEnd; NewEdge1->Weight = Infinity; NewEdge1->Info = Info; NewEdge1->NextEdge = NULL;
		if (G->AdjList[VStart - 1]->FristEdge == NULL)
			G->AdjList[VStart - 1]->FristEdge = NewEdge1;
		else
			LinkEdge(G->AdjList[VStart - 1]->FristEdge, NewEdge1);

		//����ԳƱ�
		Edge NewEdge2 = new EdgeNode;
		NewEdge2->Vertex = VStart; NewEdge2->Weight = Infinity; NewEdge2->Info = Info; NewEdge2->NextEdge = NULL;
		if (G->AdjList[VEnd - 1]->FristEdge == NULL)
			G->AdjList[VEnd - 1]->FristEdge = NewEdge2;
		else
			LinkEdge(G->AdjList[VEnd - 1]->FristEdge, NewEdge2);
	}
	return G;
}

Graph CreateUDN(Graph G)
{
	cout << "���ڴ���������" << endl;
	VertexType VStart, VEnd;
	int Weight;
	int HasInfo;
	for (int i = 0; i < G->EdgeNum; i++)
	{
		cout << "�������" << i + 1 << "�������������㡢�Ƿ��ж�����Ϣ��0�ޣ������У���ʽΪ: V1 V2 Weight Bool" << endl;
		fflush(stdin);
		//cin >> VStart >> VEnd >> Weight >> HasInfo;
		cin >> VStart >> VEnd >> Weight>>HasInfo ;
		while (!IsVertex(G, VStart) || !IsVertex(G, VEnd))
		{
			cout << "���벻�Ϸ�,����������";
			fflush(stdin);		
			cin >> VStart >> VEnd >> Weight >> HasInfo;
		}
		InfoType Info = "";
		if (HasInfo)
		{
			cout << "�����������Ϣ��" << endl;
			fflush(stdin);
			cin >> Info;
		}
		Edge NewEdge1 = new EdgeNode;
		NewEdge1->Vertex = VEnd; NewEdge1->Weight = Weight; NewEdge1->NextEdge = NULL;
		if (G->AdjList[VStart - 1]->FristEdge == NULL)
			G->AdjList[VStart - 1]->FristEdge = NewEdge1;
		else
			LinkEdge(G->AdjList[VStart - 1]->FristEdge, NewEdge1);

		Edge NewEdge2 = new EdgeNode;
		NewEdge2->Vertex = VStart; NewEdge2->Weight = Weight; NewEdge2->NextEdge = NULL;
		if (G->AdjList[VEnd - 1]->FristEdge == NULL)
			G->AdjList[VEnd - 1]->FristEdge = NewEdge2;
		else
			LinkEdge(G->AdjList[VEnd - 1]->FristEdge, NewEdge2);
	}
	return G;
}

	
Graph CreateGraph(int VNum, int ENum, GraphType GType)
{
	Graph G = new GraphNode;
	if (!G)
	{
		cerr << "Out of Space";
		exit(-1);
	}
	G->VexNum = VNum; G->EdgeNum = ENum; G->Type = GType;
	G->AdjList = new AdjListNode[G->VexNum];
	for (int i = 0; i < G->VexNum; i++)
	{
		G->AdjList[i] = new VNode;
		G->AdjList[i]->Vertex = i + 1;
		G->AdjList[i]->FristEdge = NULL;
	}
	switch (GType)
	{
	case DG:
		return CreateDG(G); break;
	case DN:
		return CreateDN(G); break;
	case UDG:
		return CreateUDG(G); break;
	case UDN:
		return CreateUDN(G); break;
	default:
		break;
	}
}


void DisplayGraph(Graph G)
{
	cout << "��ʾͼ������:"<< endl;
	switch (G->Type)
	{
	case DG:
		cout << "����ͼ"; break;
	case DN:
		cout << "������"; break;
	case UDG:
		cout << "����ͼ"; break;
	case UDN:
		cout << "������"; break;
	default:
		break;
	}
	cout << "G��" << G->VexNum << "�����㣬" << G->EdgeNum << "����"<<endl;
	cout << "�ڽӱ�Ϊ:" << endl;
	for (int i = 0; i < G->VexNum; i++)
	{
		cout << "V" << G->AdjList[i]->Vertex<< " |";
		Edge E = G->AdjList[i]->FristEdge;
		while (E)
		{
			cout << " -->��V" << E->Vertex;
			if (E->Weight != Infinity)
				cout << " Weight: " << E->Weight;
			if (E->Info != "")
				cout << " Info: " << E->Info;
			cout << " ��" ;
			E = E->NextEdge;
		}
		cout << endl;
	}
}
//������������㷨 
void DFSTraverse(Graph G, void(*VisitFunc)(Graph, VertexType), VertexType StartVertex)
{
	bool* Visited = new bool[G->VexNum + 1];
	//��ʼ����־����
	for (int i = 1; i <=G->VexNum; i++)
		Visited[i] = false;
	//���α���ÿ�����㣬��δ���ʹ������DFS
	for (int i = StartVertex; i <= G->VexNum; i++)
	{
		if (!Visited[i])
			DFS(G, i, Visited, VisitFunc);
	}
	delete[] Visited;
}

//����������������ݹ麯�� V:���ʵ� Visited:��־���� VisitFunc:������ʺ���
void DFS(Graph G, VertexType V, bool* Visited, void(*VisitFunc)(Graph,VertexType))
{
	VisitFunc(G, V);
	Visited[V] = true;
	Edge E = G->AdjList[V-1]->FristEdge;
	while (E)
	{
		if (!Visited[E->Vertex])
			DFS(G, E->Vertex, Visited, VisitFunc);
		E = E->NextEdge;
	}
}
//������������㷨 (ʹ�ö���)  V:���ʵ� Visited:��־���� VisitFunc:������ʺ���
void BFSTraverse(Graph G, void(*VisitFunc)(Graph, VertexType), VertexType StartVertex)
{
	bool* Visited = new bool[G->VexNum + 1];
	Queue VisitQueue = CreateQueue(20); //Ĭ�����20����
	//��ʼ����־����
	for (int i = 1; i <= G->VexNum; i++)
		Visited[i] = false;
	//�������
	VisitFunc(G, StartVertex);
	Visited[StartVertex] = true;
	//������
	Enqueue(StartVertex, VisitQueue);
	//�ؼ�ѭ�� ���в�Ϊ��->����->����δ���ʵ��ڽӵ�->���ʵĵ����
	while (!IsEmpty(VisitQueue))
	{
		VertexType NextVertex = FrontAndDequeue(VisitQueue);
		Edge E = G->AdjList[NextVertex - 1]->FristEdge;
		while (E)
		{
			if (!Visited[E->Vertex])
			{
				VisitFunc(G, E->Vertex);
				Visited[E->Vertex] = true;
				Enqueue(E->Vertex, VisitQueue);
			}
			E = E->NextEdge;
		}
	}
	delete[] Visited;
}

//����������С������Prim�㷨
//ÿ���ҵ���������֪�㼯�ڽӱ�Ȩֵ��С��δ֪�㣬��������������ӵĵ㣬�����ڽӵ����СȨֵ��·��
void UDNMinSpanTree_Prim(Graph G)
{
	bool *Known = new bool[G->VexNum+1];//��ʾ����Vi�Ƿ���֪
	int *MinWeightToKnown = new VertexType[G->VexNum+1];//��ʾ����Vi����֪�㼯�ı�����С��Ȩ
	VertexType* PathToV = new VertexType[G->VexNum + 1];//��ʾ���¶���Vi��СȨֵ���µĶ���
	//��־�����ʼ��
	for (int i = 1; i <= G->VexNum; i++)
	{
		Known[i] = false;
		MinWeightToKnown[i] = Infinity;
		PathToV[i] = 0;
	}
	//��ʼ�����V1
	MinWeightToKnown[1] = 0; PathToV[1] = 0;
	while (1)
	{
		int MinWeightVertex=0;
		//�ҵ�����СȨ��δ֪��
		for (int i = 1,MinWeight=Infinity; i <= G->VexNum; i++)
		{
			if (!Known[i]&&MinWeightToKnown[i] < MinWeight)
			{
				MinWeight = MinWeightToKnown[i];
				MinWeightVertex = i;
			}
		}
		//��Ϊ0�����Ե㶼��֪����ʼ������
		if (!MinWeightVertex)
		{
			int SumWeight = 0;
			cout << "\n��С������(Prim�㷨)����Ϊ: ";
			for (int i = 2; i <= G->VexNum; i++)
			{
				cout << "��(V" << i << ",V" << PathToV[i] << ") Weight:" << MinWeightToKnown[i] << " ��,";
				SumWeight += MinWeightToKnown[i];
			}
			cout << "��ȨֵΪ: " << SumWeight<<endl;
			return;
		}
		//��������������ӵĵ㣬�����ڽӵ����СȨֵ��·��
		Edge E = G->AdjList[MinWeightVertex-1]->FristEdge;
		while (E)
		{
			//����ڽӵ�δ֪��������СȨֵС������δ֪��ıߵ�Ȩֵ�����
			if (!Known[E->Vertex] && E->Weight<MinWeightToKnown[E->Vertex])
			{				MinWeightToKnown[E->Vertex] = E->Weight;
				PathToV[E->Vertex] = MinWeightVertex;
			}
			E = E->NextEdge;
		}
		//����СȨֵδ֪���Ϊ��֪
		Known[MinWeightVertex] = true;
	}
	delete[] Known;
	delete[] MinWeightToKnown;
	delete[] PathToV;
}

//Kruskal�㷨׼��
//�½��߽ṹ
typedef struct EdgeStruct{
	VertexType VStart;
	VertexType VEnd;
	int Weight;
	bool Accepted;
}*EdgeType;
//�õ�������
EdgeType* GetEdges(Graph G)
{
	EdgeType* Edges = new EdgeType[G->EdgeNum];
	int EdgeNumCount = 0;
	//�����ڽӱ�õ����в��ظ���
	for (int i = 1; i <= G->VexNum; i++)
	{
		Edge e = G->AdjList[i - 1]->FristEdge;
		while (e)
		{
			//ȥ������ͼ��һ���ظ���
			if (e->Vertex > i)
			{
				Edges[EdgeNumCount] = new EdgeStruct;
				Edges[EdgeNumCount]->VStart = i;
				Edges[EdgeNumCount]->VEnd = e->Vertex;
				Edges[EdgeNumCount]->Weight = e->Weight;
				Edges[EdgeNumCount]->Accepted = false;
				EdgeNumCount++;
			}
			e = e->NextEdge;
		}
	}
	//���ձ�Ȩֵ��������ð������
	for (int i = 0; i < G->EdgeNum; i++)
	{
		for (int j= i+1; j < G->EdgeNum; j++)
		{
			if (Edges[i]->Weight > Edges[j]->Weight)
			{
				EdgeType Tmp = Edges[j];
				Edges[j] = Edges[i];
				Edges[i] = Tmp;
			}
		}
	
	}
	return Edges;
}
//�õ�V�ĸ���������ͬ����ͬһ��ͨ��ͼ�� �����ཻ��˼�룩
int GetRoots(VertexType* Roots, VertexType V)
{
	while (Roots[V]!=0)
	{
		V = Roots[V];
	}
	return V;
}
//����������С������Kruskal�㷨��ʼ
//ÿ���ҵ�Ȩֵ��С�ıߣ�����ѡ�ı߲�����Ȧʱ���ܸñ߷������
void UDNMinSpanTree_Kruskal(Graph G)
{
	EdgeType* Edges = GetEdges(G);//�õ��Ѱ�Ȩֵ����õ����б�
	VertexType* Roots = new VertexType[G->VexNum+1]; //����ÿ������ĸ���������ͬ����ͬһ��ͨ����
	for (int i = 1; i <= G->VexNum; i++)
	{
		Roots[i] = 0;//��ʼ����Ϊ��Чֵ
	}
	//�������бߣ�������ͷ���㲻��ͬһ��ͨ��ͼ��Roots��ͬ������ܱߣ����õ�VexNum-1����ʱѭ������
	for (int i = 0, j = 0; j < G->VexNum - 1&&i < G->EdgeNum; i++)
	{
		VertexType VStart = Edges[i]->VStart;
		VertexType VEnd = Edges[i]->VEnd;
		if (GetRoots(Roots, VStart) != GetRoots(Roots,VEnd))
		{
			Edges[i]->Accepted = true;
			j++;
			Roots[VStart] = VEnd; //���¸�
		}
	}

	//������н��ܵıߣ�ͳ����Ȩֵ
	cout << "\n��С������(Kruskal�㷨)����Ϊ: ";
	int SumWeight = 0;
	for (int i = 0; i < G->EdgeNum; i++)
	{
		if (Edges[i]->Accepted)
		{
			cout <<"��(V" << Edges[i]->VStart << ",V" << Edges[i]->VEnd << ") Weight:" << Edges[i]->Weight << " ��,";
			SumWeight += Edges[i]->Weight;
		}
	}
	cout << "��ȨֵΪ: " << SumWeight << endl;

	delete[] Edges;
	delete[] Roots;
}

//�õ����ж�������
int* GetIndegree(Graph G)
{
	int* Indegree = new int[G->VexNum + 1];
	for (int i = 1; i <= G->VexNum; i++)
	{
		Indegree[i] = 0;
	}
	for (int i = 1; i <= G->VexNum; i++)
	{
		Edge e = G->AdjList[i-1]->FristEdge;
		while (e)
		{
			Indegree[e->Vertex]++;
			e = e->NextEdge;
		}
	}
	return Indegree;
}
//����ͼ/�������������㷨
//˼�룺ÿ�ΰ����Ϊ0�ĵ���ӣ�Ȼ�����ڽӵ���ȼ�һ���ٽ����Ϊ0�ĵ����,
//ֱ������Ϊ��ʱ�㷨����������˳��Ϊ����������
void TopSort(Graph G)
{
	int * Indegree = GetIndegree(G);
	Queue Q = CreateQueue(20);

	for (int i = 1; i <= G->VexNum;i++)
	{
		if (Indegree[i] == 0)
			Enqueue(i, Q);
	}
	int Counter = 0;
	cout << "\n��������";
	//����Ϊ��ʱ�㷨����
	while (!IsEmpty(Q))
	{
		VertexType V = FrontAndDequeue(Q); //�����Ϊ0�ĵ����
		cout << "V" << V<<" -> ";
		Counter++;
		Edge e = G->AdjList[V - 1]->FristEdge;
		//�����ӵ���ڽӵ���ȼ�һ
		while (e)
		{
			//����ȱ�Ϊ0�����
			if (--Indegree[e->Vertex] == 0)
				Enqueue(e->Vertex, Q);
			e = e->NextEdge;
		}
	}
	//���������е㶼���ӣ����϶�ͼ����Ȧ
	if (Counter != G->VexNum)
		cerr << "ͼ����Ȧͼ"<<endl;

	//��������
	delete[] Indegree;
	DisposeQueue(Q);
}
//�ݹ��ӡ��StartVertex��V��·��
void PrintPathToV(VertexType V, VertexType StartVertex,VertexType * PathToV)
{
	if (V == StartVertex)
		cout << "V" << StartVertex;
	else
	{
		PrintPathToV(PathToV[V], StartVertex, PathToV);
		cout << "V" << V;
	}
	cout << "->";
}
//������Ȩͼ�����·���㷨
//˼�룺����������� ���Ӷ�O(VexNum+EdgeNum)
void DGShortestPath(Graph G, VertexType StartVertex)
{
	Queue VertexQueue = CreateQueue(20); //������Ķ������
	int *Distance = new int[G->VexNum + 1];//����ÿ������ľ���
	VertexType *PathToV = new VertexType[G->VexNum + 1];//�����StartVertex��V��·��
	for (int i = 1; i <= G->VexNum; i++)
	{
		Distance[i] = Infinity; //�����ʼ��Ϊ�����
		PathToV[i] = 0;		//·����ʼ��Ϊ��Чֵ
	}
	Distance[StartVertex] = 0;	//�������ʼ��Ϊ0
	Enqueue(StartVertex, VertexQueue); //������
	//����Ϊ��ʱѭ������
	while (!IsEmpty(VertexQueue))
	{
		VertexType V = FrontAndDequeue(VertexQueue);
		Edge E = G->AdjList[V - 1]->FristEdge;
		while (E)
		{
			//������δ���ʹ����������ֵ,�����
			if (Distance[E->Vertex] == Infinity)
			{
				Distance[E->Vertex] = Distance[V] + 1;
				PathToV[E->Vertex] = V;
				Enqueue(E->Vertex, VertexQueue);
			}
			E = E->NextEdge;
		}
	}
	cout <<"\n������Ȩͼ��ÿ�����㵽V" << StartVertex << "�����·��Ϊ\n";
	for (int V = 1; V <= G->VexNum; V++)
	{
		cout << "V" << V << " |(";
		PrintPathToV(V,StartVertex,PathToV);
		cout << "�� �ܱ���Ϊ:" << Distance[V]<<endl;
	}
	delete[] Distance;
	delete[] PathToV;
	DisposeQueue(VertexQueue);
}


//�������ĵ�Դ���·��Dijkstra�㷨(Ȩֵ�Ǹ�) �ǳ�������С��������Prim�㷨
//˼��:ÿ���ҵ���������֪�㼯�ڽӱ��ܾ�����С��δ֪�㣬��������������ӵĵ㣬�����ڽӵ�ľ����·��
//���Ӷ�O(VexNum^2+EdgeNum)
void DNShortestPath_Dijkstra(Graph G, VertexType StartVertex)
{
	bool *Known = new bool[G->VexNum + 1];//��ʾ����Vi�Ƿ���֪
	int *Distance = new VertexType[G->VexNum + 1];//��ʾ����Vi����֪�㼯�ı�����С��Ȩ
	VertexType* PathToV = new VertexType[G->VexNum + 1];//��ʾ���¶���Vi��СȨֵ���µĶ���
	//��־�����ʼ��
	for (int i = 1; i <= G->VexNum; i++)
	{
		Known[i] = false;
		Distance[i] = Infinity;
		PathToV[i] = 0;
	}
	//��ʼ�����StartVertex
	Distance[StartVertex] = 0; 
	while (1)
	{
		int MinDistanceVertex = 0;
		//�ҵ�����С�����δ֪��
		for (int i = 1, MinDistance = Infinity; i <= G->VexNum; i++)
		{
			if (!Known[i] && Distance[i] < MinDistance)
			{
				MinDistance = Distance[i];
				MinDistanceVertex = i;
			}
		}
		//��Ϊ0�����Ե㶼��֪����ʼ������
		if (!MinDistanceVertex)
		{
			cout << "\n������V1��ÿ����������·��Dijkstra�㷨(Ȩֵ�Ǹ�)���: "<<endl;
			for (int V = 1; V <= G->VexNum; V++)
			{
				cout << "V" << V << " |(";
				PrintPathToV(V, StartVertex, PathToV);
				cout << ") ��ȨֵΪ: " << Distance[V] << endl;
			}
			return;
		}
		//��������������ӵĵ㣬�����ڽӵ����С�����·��
		Edge E = G->AdjList[MinDistanceVertex - 1]->FristEdge;
		while (E)
		{
			//����ڽӵ�δ֪��������������С�����������δ֪��ı�Ȩֵ��ֵ�����
			if (!Known[E->Vertex] && Distance[MinDistanceVertex]+E->Weight <Distance[E->Vertex])
			{
				Distance[E->Vertex] = Distance[MinDistanceVertex]+E->Weight;
				PathToV[E->Vertex] = MinDistanceVertex;
			}
			E = E->NextEdge;
		}
		//���δ֪���Ϊ��֪
		Known[MinDistanceVertex] = true;
	}
	delete[] Distance;
	delete[] PathToV;
	delete[] Known;
}

//����������Ե����·��Floyd�㷨(Ȩֵ�Ǹ�)
/*
Floyd�㷨�Ļ���˼�룺
����һ��n�׷������У�
D(-1),  D(0),  ��,  D(n-1).
����  D(-1) [i][j] = G.arcs[i][j]��
D(k) [i][j] = min { D(k-1)[i][j]��
D(k-1)[i][k] + D(k-1)[k][j] }, k = 0,1,��, n-1
D(0) [i][j]�ǴӶ���vi ��vj , �м䶥����v0�����·���ĳ���,
D(k) [i][j]�ǴӶ���vi ��vj ,  �м䶥�����Ų�����k�����·������,
D(n-1)[i][j]�ǴӶ���vi ��vj �����·�����ȡ�

O(VexNum^3)���Ӷ� ����̼��������
*/
void DNShortestPath_Floyd(Graph G)
{
	int Distances[20][20];
	int Path[20][20];
	for (int i = 1; i <= G->VexNum;i++)
	for (int j = 1; j <= G->VexNum; j++)
	{
		if (i == j)
		{
			Distances[i][j] = 0;
			Path[i][j] = i;
		}
		else
		{
			Distances[i][j] = Infinity;
			Path[i][j] = 0;
		}
	}
	for (int V = 1; V<= G->VexNum; V++)
	{
		Edge E = G->AdjList[V - 1]->FristEdge;
		while (E)
		{
			Distances[V][E->Vertex] = E->Weight;
			Path[V][E->Vertex] = V;
			E = E->NextEdge;
		}
	}
	//V:������м�� S:��� W:�յ�
	for (int V = 2; V <= G->VexNum; V++)
	for (int S = 1; S <= G->VexNum; S++)
	for (int W = 1; W <= G->VexNum; W++)
	{
		if (Distances[S][V] + Distances[V][W]< Distances[S][W])
		{
			Distances[S][W] = Distances[S][V] + Distances[V][W];
			Path[S][W] = V;
		}
	}
	
	cout << "\n����������Ե����·��Floyd�㷨�����ʡ�Բ��ɴ��Ժ��Է���ԣ���" << endl;
	for (int S = 1; S <= G->VexNum; S++)
	{
		for (int W = 1; W <= G->VexNum; W++)
		{
			if (S!=W&&Distances[S][W] != Infinity)
			{
				cout << "V" << S << "-->V" << W << " |(";
				PrintPathToV(W, S, Path[S]);
				cout << ") ��ȨֵΪ: " << Distances[S][W] << endl;
			}
			//else
			//	cout << "V" << S << "-->V" << W << " |���ɴ�"<<endl;
		}
	}
}
void DisposeGraph(Graph G)
{
	//�ͷ����еı�
	for (int i = 0; i < G->VexNum; i++)
	{
		Edge e = G->AdjList[i]->FristEdge;
		while (e)
		{
			Edge Tmp = e;
			e = Tmp->NextEdge;
			delete Tmp;
		}
	}
	//�ͷ����еĵ�
	for (int i = 0; i < G->VexNum; i++)
	{
		delete G->AdjList[i];
	}
	//�ͷ��ڽӾ���
	delete [] G->AdjList;
	//�ͷ�ͼ
	delete G;
}