#include "Graph.h"
bool IsVertex(Graph G, VertexType V)
{
	return (V >= 1 && V <= G->VexNum);
}
//将边连接到邻接表末尾
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

//创建有向图
Graph CreateDG(Graph G)
{
	VertexType VStart, VEnd;
	int HasInfo;
	cout << "正在创建有向图" << endl;
	for (int i = 0; i < G->EdgeNum; i++)
	{
		cout << "请输入第" << i + 1 << "条弧的弧头、弧尾、是否有额外信息（0无，其他有）格式为: VStart VEnd Bool" << endl;
		fflush(stdin);
		cin >> VStart >> VEnd >> HasInfo;
		while (!IsVertex(G, VStart) || !IsVertex(G, VEnd))
		{
			cout << "输入不合法,请重新输入" << endl;
			fflush(stdin);
			cin >> VStart >> VEnd >> HasInfo;
		}
		InfoType Info = "";
		if (HasInfo)
		{
			cout << "请输入额外信息：" << endl;
			fflush(stdin);
			cin >> Info;
		}
		Edge NewEdge = new EdgeNode;
		NewEdge->Vertex = VEnd; NewEdge->Weight = Infinity; NewEdge->Info = Info;
		NewEdge->NextEdge = NULL;
		//区别是否有第一条边
		if (G->AdjList[VStart - 1]->FristEdge == NULL)
			G->AdjList[VStart - 1]->FristEdge = NewEdge;
		else
			LinkEdge(G->AdjList[VStart - 1]->FristEdge, NewEdge);
	}
	return G;
}
Graph CreateDN(Graph G)
{
	cout << "正在创建有向网" << endl;
	VertexType VStart, VEnd, Weight;
	int HasInfo;
	for (int i = 0; i < G->EdgeNum; i++)
	{
		cout << "请输入第"<<i+1<<"条弧的弧头、弧尾、权值、是否有额外信息（0无，其他有）格式为: VStart VEnd Weight Bool" << endl;
		fflush(stdin);
		cin >> VStart >> VEnd >> Weight>>HasInfo;
		while (!IsVertex(G, VStart) || !IsVertex(G, VEnd))
		{
			cout << "输入不合法,请重新输入"<<endl;
			fflush(stdin);
			cin >> VStart >> VEnd >> Weight>>HasInfo;
		}
		InfoType Info = "";
		if (HasInfo)
		{
			cout << "请输入额外信息："<<endl;
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
	cout << "正在创建无向图" << endl;
	VertexType VStart, VEnd;
	int HasInfo;
	for (int i = 0; i < G->EdgeNum; i++)
	{
		cout << "请输入第" << i + 1 << "条弧的两个顶点、是否有额外信息（0无，其他有）格式为: V1 V2 Bool" << endl;
		fflush(stdin);
		cin >> VStart >> VEnd >> HasInfo;
		while (!IsVertex(G, VStart) || !IsVertex(G, VEnd))
		{
			cout << "输入不合法,请重新输入";
			fflush(stdin);
			cin >> VStart >> VEnd >> HasInfo;
		}
		InfoType Info = "";
		if (HasInfo)
		{
			cout << "请输入额外信息：" << endl;
			fflush(stdin);
			cin >> Info;
		}
		Edge NewEdge1 = new EdgeNode;
		NewEdge1->Vertex = VEnd; NewEdge1->Weight = Infinity; NewEdge1->Info = Info; NewEdge1->NextEdge = NULL;
		if (G->AdjList[VStart - 1]->FristEdge == NULL)
			G->AdjList[VStart - 1]->FristEdge = NewEdge1;
		else
			LinkEdge(G->AdjList[VStart - 1]->FristEdge, NewEdge1);

		//处理对称边
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
	cout << "正在创建无向网" << endl;
	VertexType VStart, VEnd;
	int Weight;
	int HasInfo;
	for (int i = 0; i < G->EdgeNum; i++)
	{
		cout << "请输入第" << i + 1 << "条弧的两个顶点、是否有额外信息（0无，其他有）格式为: V1 V2 Weight Bool" << endl;
		fflush(stdin);
		//cin >> VStart >> VEnd >> Weight >> HasInfo;
		cin >> VStart >> VEnd >> Weight>>HasInfo ;
		while (!IsVertex(G, VStart) || !IsVertex(G, VEnd))
		{
			cout << "输入不合法,请重新输入";
			fflush(stdin);		
			cin >> VStart >> VEnd >> Weight >> HasInfo;
		}
		InfoType Info = "";
		if (HasInfo)
		{
			cout << "请输入额外信息：" << endl;
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
	cout << "显示图的数据:"<< endl;
	switch (G->Type)
	{
	case DG:
		cout << "有向图"; break;
	case DN:
		cout << "有向网"; break;
	case UDG:
		cout << "无向图"; break;
	case UDN:
		cout << "无向网"; break;
	default:
		break;
	}
	cout << "G有" << G->VexNum << "个顶点，" << G->EdgeNum << "条边"<<endl;
	cout << "邻接表为:" << endl;
	for (int i = 0; i < G->VexNum; i++)
	{
		cout << "V" << G->AdjList[i]->Vertex<< " |";
		Edge E = G->AdjList[i]->FristEdge;
		while (E)
		{
			cout << " -->【V" << E->Vertex;
			if (E->Weight != Infinity)
				cout << " Weight: " << E->Weight;
			if (E->Info != "")
				cout << " Info: " << E->Info;
			cout << " 】" ;
			E = E->NextEdge;
		}
		cout << endl;
	}
}
//深度优先搜索算法 
void DFSTraverse(Graph G, void(*VisitFunc)(Graph, VertexType), VertexType StartVertex)
{
	bool* Visited = new bool[G->VexNum + 1];
	//初始化标志数组
	for (int i = 1; i <=G->VexNum; i++)
		Visited[i] = false;
	//依次遍历每个顶点，若未访问过则调用DFS
	for (int i = StartVertex; i <= G->VexNum; i++)
	{
		if (!Visited[i])
			DFS(G, i, Visited, VisitFunc);
	}
	delete[] Visited;
}

//深度优先搜索辅助递归函数 V:访问点 Visited:标志数组 VisitFunc:具体访问函数
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
//广度优先搜索算法 (使用队列)  V:访问点 Visited:标志数组 VisitFunc:具体访问函数
void BFSTraverse(Graph G, void(*VisitFunc)(Graph, VertexType), VertexType StartVertex)
{
	bool* Visited = new bool[G->VexNum + 1];
	Queue VisitQueue = CreateQueue(20); //默认最大20顶点
	//初始化标志数组
	for (int i = 1; i <= G->VexNum; i++)
		Visited[i] = false;
	//访问起点
	VisitFunc(G, StartVertex);
	Visited[StartVertex] = true;
	//起点入队
	Enqueue(StartVertex, VisitQueue);
	//关键循环 队列不为空->出队->访问未访问的邻接点->访问的点入队
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

//无向网的最小生成树Prim算法
//每次找到具有与已知点集邻接边权值最小的未知点，遍历所以与其领接的点，更新邻接点的最小权值和路径
void UDNMinSpanTree_Prim(Graph G)
{
	bool *Known = new bool[G->VexNum+1];//标示顶点Vi是否已知
	int *MinWeightToKnown = new VertexType[G->VexNum+1];//标示顶点Vi到已知点集的边中最小的权
	VertexType* PathToV = new VertexType[G->VexNum + 1];//标示导致顶点Vi最小权值更新的顶点
	//标志数组初始化
	for (int i = 1; i <= G->VexNum; i++)
	{
		Known[i] = false;
		MinWeightToKnown[i] = Infinity;
		PathToV[i] = 0;
	}
	//初始化起点V1
	MinWeightToKnown[1] = 0; PathToV[1] = 0;
	while (1)
	{
		int MinWeightVertex=0;
		//找到有最小权的未知点
		for (int i = 1,MinWeight=Infinity; i <= G->VexNum; i++)
		{
			if (!Known[i]&&MinWeightToKnown[i] < MinWeight)
			{
				MinWeight = MinWeightToKnown[i];
				MinWeightVertex = i;
			}
		}
		//若为0即所以点都已知，开始输出结果
		if (!MinWeightVertex)
		{
			int SumWeight = 0;
			cout << "\n最小生成树(Prim算法)各边为: ";
			for (int i = 2; i <= G->VexNum; i++)
			{
				cout << "【(V" << i << ",V" << PathToV[i] << ") Weight:" << MinWeightToKnown[i] << " 】,";
				SumWeight += MinWeightToKnown[i];
			}
			cout << "总权值为: " << SumWeight<<endl;
			return;
		}
		//遍历所以与其领接的点，更新邻接点的最小权值和路径
		Edge E = G->AdjList[MinWeightVertex-1]->FristEdge;
		while (E)
		{
			//如果邻接点未知，且其最小权值小于连接未知点的边的权值则更新
			if (!Known[E->Vertex] && E->Weight<MinWeightToKnown[E->Vertex])
			{				MinWeightToKnown[E->Vertex] = E->Weight;
				PathToV[E->Vertex] = MinWeightVertex;
			}
			E = E->NextEdge;
		}
		//将最小权值未知点标为已知
		Known[MinWeightVertex] = true;
	}
	delete[] Known;
	delete[] MinWeightToKnown;
	delete[] PathToV;
}

//Kruskal算法准备
//新建边结构
typedef struct EdgeStruct{
	VertexType VStart;
	VertexType VEnd;
	int Weight;
	bool Accepted;
}*EdgeType;
//得到边数组
EdgeType* GetEdges(Graph G)
{
	EdgeType* Edges = new EdgeType[G->EdgeNum];
	int EdgeNumCount = 0;
	//遍历邻接表得到所有不重复边
	for (int i = 1; i <= G->VexNum; i++)
	{
		Edge e = G->AdjList[i - 1]->FristEdge;
		while (e)
		{
			//去除无向图另一半重复边
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
	//按照边权值进行排序（冒泡排序）
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
//得到V的根，若根相同则在同一连通子图中 （不相交集思想）
int GetRoots(VertexType* Roots, VertexType V)
{
	while (Roots[V]!=0)
	{
		V = Roots[V];
	}
	return V;
}
//无向网的最小生成树Kruskal算法开始
//每次找到权值最小的边，当所选的边不产生圈时接受该边否则放弃
void UDNMinSpanTree_Kruskal(Graph G)
{
	EdgeType* Edges = GetEdges(G);//得到已按权值排序好的所有边
	VertexType* Roots = new VertexType[G->VexNum+1]; //保存每个顶点的根，若根相同则在同一连通分量
	for (int i = 1; i <= G->VexNum; i++)
	{
		Roots[i] = 0;//初始化根为无效值
	}
	//遍历所有边，若边两头顶点不在同一连通子图（Roots不同）则接受边，当得到VexNum-1条边时循环结束
	for (int i = 0, j = 0; j < G->VexNum - 1&&i < G->EdgeNum; i++)
	{
		VertexType VStart = Edges[i]->VStart;
		VertexType VEnd = Edges[i]->VEnd;
		if (GetRoots(Roots, VStart) != GetRoots(Roots,VEnd))
		{
			Edges[i]->Accepted = true;
			j++;
			Roots[VStart] = VEnd; //更新根
		}
	}

	//输出所有接受的边，统计总权值
	cout << "\n最小生成树(Kruskal算法)各边为: ";
	int SumWeight = 0;
	for (int i = 0; i < G->EdgeNum; i++)
	{
		if (Edges[i]->Accepted)
		{
			cout <<"【(V" << Edges[i]->VStart << ",V" << Edges[i]->VEnd << ") Weight:" << Edges[i]->Weight << " 】,";
			SumWeight += Edges[i]->Weight;
		}
	}
	cout << "总权值为: " << SumWeight << endl;

	delete[] Edges;
	delete[] Roots;
}

//得到所有顶点的入度
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
//有向图/网的拓扑排序算法
//思想：每次把入度为0的点出队，然后将其邻接点入度减一，再将入度为0的点入队,
//直到队列为空时算法结束，出队顺序即为拓扑排序结果
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
	cout << "\n拓扑排序：";
	//队列为空时算法结束
	while (!IsEmpty(Q))
	{
		VertexType V = FrontAndDequeue(Q); //将入度为0的点出队
		cout << "V" << V<<" -> ";
		Counter++;
		Edge e = G->AdjList[V - 1]->FristEdge;
		//将出队点的邻接点入度减一
		while (e)
		{
			//若入度变为0则入队
			if (--Indegree[e->Vertex] == 0)
				Enqueue(e->Vertex, Q);
			e = e->NextEdge;
		}
	}
	//若不是所有点都出队，则认定图中有圈
	if (Counter != G->VexNum)
		cerr << "图是有圈图"<<endl;

	//垃圾回收
	delete[] Indegree;
	DisposeQueue(Q);
}
//递归打印从StartVertex到V的路径
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
//有向无权图的最短路径算法
//思想：广度优先搜索 复杂度O(VexNum+EdgeNum)
void DGShortestPath(Graph G, VertexType StartVertex)
{
	Queue VertexQueue = CreateQueue(20); //待处理的顶点队列
	int *Distance = new int[G->VexNum + 1];//保存每个顶点的距离
	VertexType *PathToV = new VertexType[G->VexNum + 1];//保存从StartVertex到V的路径
	for (int i = 1; i <= G->VexNum; i++)
	{
		Distance[i] = Infinity; //距离初始化为无穷大
		PathToV[i] = 0;		//路径初始化为无效值
	}
	Distance[StartVertex] = 0;	//起点距离初始化为0
	Enqueue(StartVertex, VertexQueue); //起点入队
	//队列为空时循环结束
	while (!IsEmpty(VertexQueue))
	{
		VertexType V = FrontAndDequeue(VertexQueue);
		Edge E = G->AdjList[V - 1]->FristEdge;
		while (E)
		{
			//若顶点未访问过，则更新其值,并入队
			if (Distance[E->Vertex] == Infinity)
			{
				Distance[E->Vertex] = Distance[V] + 1;
				PathToV[E->Vertex] = V;
				Enqueue(E->Vertex, VertexQueue);
			}
			E = E->NextEdge;
		}
	}
	cout <<"\n有向无权图中每个顶点到V" << StartVertex << "的最短路径为\n";
	for (int V = 1; V <= G->VexNum; V++)
	{
		cout << "V" << V << " |(";
		PrintPathToV(V,StartVertex,PathToV);
		cout << "） 总边数为:" << Distance[V]<<endl;
	}
	delete[] Distance;
	delete[] PathToV;
	DisposeQueue(VertexQueue);
}


//有向网的单源最短路径Dijkstra算法(权值非负) 非常类似最小生成树的Prim算法
//思想:每次找到具有与已知点集邻接边总距离最小的未知点，遍历所以与其领接的点，更新邻接点的距离和路径
//复杂度O(VexNum^2+EdgeNum)
void DNShortestPath_Dijkstra(Graph G, VertexType StartVertex)
{
	bool *Known = new bool[G->VexNum + 1];//标示顶点Vi是否已知
	int *Distance = new VertexType[G->VexNum + 1];//标示顶点Vi到已知点集的边中最小的权
	VertexType* PathToV = new VertexType[G->VexNum + 1];//标示导致顶点Vi最小权值更新的顶点
	//标志数组初始化
	for (int i = 1; i <= G->VexNum; i++)
	{
		Known[i] = false;
		Distance[i] = Infinity;
		PathToV[i] = 0;
	}
	//初始化起点StartVertex
	Distance[StartVertex] = 0; 
	while (1)
	{
		int MinDistanceVertex = 0;
		//找到有最小距离的未知点
		for (int i = 1, MinDistance = Infinity; i <= G->VexNum; i++)
		{
			if (!Known[i] && Distance[i] < MinDistance)
			{
				MinDistance = Distance[i];
				MinDistanceVertex = i;
			}
		}
		//若为0即所以点都已知，开始输出结果
		if (!MinDistanceVertex)
		{
			cout << "\n有向网V1到每个顶点的最短路径Dijkstra算法(权值非负)结果: "<<endl;
			for (int V = 1; V <= G->VexNum; V++)
			{
				cout << "V" << V << " |(";
				PrintPathToV(V, StartVertex, PathToV);
				cout << ") 总权值为: " << Distance[V] << endl;
			}
			return;
		}
		//遍历所以与其领接的点，更新邻接点的最小距离和路径
		Edge E = G->AdjList[MinDistanceVertex - 1]->FristEdge;
		while (E)
		{
			//如果邻接点未知，且其距离大于最小距离加上连接未知点的边权值的值则更新
			if (!Known[E->Vertex] && Distance[MinDistanceVertex]+E->Weight <Distance[E->Vertex])
			{
				Distance[E->Vertex] = Distance[MinDistanceVertex]+E->Weight;
				PathToV[E->Vertex] = MinDistanceVertex;
			}
			E = E->NextEdge;
		}
		//最后将未知点标为已知
		Known[MinDistanceVertex] = true;
	}
	delete[] Distance;
	delete[] PathToV;
	delete[] Known;
}

//有向网顶点对的最短路径Floyd算法(权值非负)
/*
Floyd算法的基本思想：
定义一个n阶方阵序列：
D(-1),  D(0),  …,  D(n-1).
其中  D(-1) [i][j] = G.arcs[i][j]；
D(k) [i][j] = min { D(k-1)[i][j]，
D(k-1)[i][k] + D(k-1)[k][j] }, k = 0,1,…, n-1
D(0) [i][j]是从顶点vi 到vj , 中间顶点是v0的最短路径的长度,
D(k) [i][j]是从顶点vi 到vj ,  中间顶点的序号不大于k的最短路径长度,
D(n-1)[i][j]是从顶点vi 到vj 的最短路径长度。

O(VexNum^3)复杂度 但编程简单易于理解
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
	//V:加入的中间点 S:起点 W:终点
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
	
	cout << "\n有向网顶点对的最短路径Floyd算法结果（省略不可达点对和自反点对）：" << endl;
	for (int S = 1; S <= G->VexNum; S++)
	{
		for (int W = 1; W <= G->VexNum; W++)
		{
			if (S!=W&&Distances[S][W] != Infinity)
			{
				cout << "V" << S << "-->V" << W << " |(";
				PrintPathToV(W, S, Path[S]);
				cout << ") 总权值为: " << Distances[S][W] << endl;
			}
			//else
			//	cout << "V" << S << "-->V" << W << " |不可达"<<endl;
		}
	}
}
void DisposeGraph(Graph G)
{
	//释放所有的边
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
	//释放所有的点
	for (int i = 0; i < G->VexNum; i++)
	{
		delete G->AdjList[i];
	}
	//释放邻接矩阵
	delete [] G->AdjList;
	//释放图
	delete G;
}