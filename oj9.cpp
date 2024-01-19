#include <iostream>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
struct Node {//定义结点
    int vertex;//结点编号
    int time;//时间
    int cost;//花费
    Node* next;//指向相邻结点
    Node(int v, int t, int p) : vertex(v), time(t), cost(p), next(nullptr) {}//构造函数
    long long int alltime = 4294967295;//起点到该结点最短时间
    long long int allcost = 4294967295;//起点到该结点最小花费
};
class Graph {//定义图
public:
    int number;//节点数目
    vector<Node*> adjacencyList;//邻接表
    Graph(int vertices) : number(vertices), adjacencyList(vertices, nullptr) {};//初始化
    void addEdge(int start, int end, int time, int cost)//添加边的函数
    {
        Node* newNode = new Node(end, time, cost);
        newNode->next = adjacencyList[start];
        adjacencyList[start] = newNode;
    }
};
long long int costmin = 4294967295;//花费最小值
void DFS(Graph& graph, int start, int end, vector<int>& visited, long long int& totaltime, long long int& totalcost, int limit, long long int& costmin) //深度遍历图
{
    visited[start] = 1;//该结点被访问过
    if (start == end) {//到达终点
        if (totaltime <= limit)//判断是否满足时间要求
        {
            if (totalcost <= costmin)//是否为当前最小
            {
                costmin = totalcost;//更新最小值
            }
        }
    }
    else {//未到达终点
        Node* current = graph.adjacencyList[start];//根据邻接表找到当前结点相邻结点
        while (current != nullptr) {
            if (visited[current->vertex] != 1) {//结点存在且之前未被访问过
                int flag = 0;
                if (totalcost <= current->allcost) { current->allcost = totalcost; flag = 1; }
                if (totaltime <= current->alltime) { current->alltime = totaltime; flag = 1; }//时间或花费有一者更优，则更新最优值
                totaltime += current->time;//经过该结点后总时间
                totalcost += current->cost;//经过该结点总花费
                if ((totaltime <= limit) && (totalcost < costmin) && (flag == 1))//剪枝：时间满足限制、花费不大于当前最小值、该结点总时间或花费最优时才接着DFS
                {
                    DFS(graph, current->vertex, end, visited, totaltime, totalcost, limit, costmin);
                }
                totaltime -= current->time;//回溯
                totalcost -= current->cost;//回溯
            }
            current = current->next;//进入下一个邻接点
        }
    }
    visited[start] = 0;//该结点处理完毕，置于未被访问
}
void DFS1(Graph& graph, int start, int end, vector<int>& visited, long long int& totaltime, long long int& totalcost, int limit, long long int& costmin) {//正常处理，不剪枝
    visited[start] = 1;
    if (start == end) {
        if (totaltime <= limit)
        {
            if (totalcost <= costmin)
            {
                costmin = totalcost;
            }
        }
    }
    else {
        Node* current = graph.adjacencyList[start];
        while (current != nullptr) {
            if (visited[current->vertex] != 1) {
                int flag = 0;
                totaltime += current->time;
                totalcost += current->cost;
                if ((totaltime <= limit) && (totalcost < costmin))
                {
                    DFS1(graph, current->vertex, end, visited, totaltime, totalcost, limit, costmin);
                }
                totaltime -= current->time;
                totalcost -= current->cost;
            }
            current = current->next;
        }
    }
    visited[start] = 0;
}
int main() {
    std::ios::sync_with_stdio(false);
    int N, M, init, target, limit;
    cin >> N >> M;
    if (N <= 50000)//结点较少，正常处理
    {
        Graph graph(N);
        for (int i = 0; i < M; i++)
        {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            graph.addEdge(a, b, c, d);
        }//初始化图
        vector<int> visited(graph.number, 0);
        long long int alltime = 0;
        long long int allcost = 0;
        cin >> init >> target >> limit;
        DFS1(graph, init, target, visited, alltime, allcost, limit, costmin);
        if (costmin < 4294967295)
        {
            cout << costmin;
        }//若找到最小花费，输出
        else cout << -1;//没有满足限制的最小花费，输出-1
    }
    else //节点较多，剪枝
    {
        Graph graph(N);
        for (int i = 0; i < M; i++)
        {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            graph.addEdge(a, b, c, d);
        }
        vector<int> visited(graph.number, 0);
        long long int alltime = 0;
        long long int allcost = 0;
        cin >> init >> target >> limit;
        DFS(graph, init, target, visited, alltime, allcost, limit, costmin);
        if (costmin < 4294967295)
        {
            cout << costmin;
        }
        else cout << -1;
    }
    return 0;
}
