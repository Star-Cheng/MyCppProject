#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <climits>

using namespace std;

// 定义景点结构体
struct Node {
    string name; // 景点名称
    string code; // 代号
    string intro; // 简介
};

// 定义边结构体
struct Edge {
    int length; // 路径长度
};

// 定义图类
class CampusMap {
private:
    map<string, Node> nodes; // 保存景点信息
    map<string, map<string, Edge>> edges; // 保存路径信息

public:
    // 添加景点
    void addNode(string code, string name, string intro) {
        Node node = {name, code, intro};
        nodes[code] = node;
    }

    // 添加路径
    void addEdge(string start, string end, int length) {
        Edge edge = {length};
        edges[start][end] = edge;
        edges[end][start] = edge; // 假设路径是双向的
    }

    // 查询景点信息
    void queryNodeInfo(string code) {
        Node node = nodes[code];
        cout << "景点名称：" << node.name << endl;
        cout << "代号：" << node.code << endl;
        cout << "简介：" << node.intro << endl;
    }

    // 最短路径查询
    void shortestPath(string start, string end) {
        map<string, int> distance;
        map<string, string> previous;
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

        for (auto it = nodes.begin(); it != nodes.end(); ++it) {
            distance[it->first] = INT_MAX;
        }

        distance[start] = 0;
        pq.push(make_pair(0, start));

        while (!pq.empty()) {
            string current = pq.top().second;
            pq.pop();

            for (auto it = edges[current].begin(); it != edges[current].end(); ++it) {
                string neighbor = it->first;
                int weight = it->second.length;
                int newDistance = distance[current] + weight;

                if (newDistance < distance[neighbor]) {
                    distance[neighbor] = newDistance;
                    previous[neighbor] = current;
                    pq.push(make_pair(newDistance, neighbor));
                }
            }
        }

        vector<string> path;
        string current = end;
        while (previous.find(current) != previous.end()) {
            path.push_back(current);
            current = previous[current];
        }
        path.push_back(start);

        cout << "最短路径为：";
        for (int i = path.size() - 1; i >= 0; --i) {
            cout << nodes[path[i]].name;
            if (i != 0) {
                cout << " -> ";
            }
        }
        cout << endl;
        cout << "路径长度为：" << distance[end] << endl;
    }
};

int main() {
    CampusMap map;
    // 添加景点信息
    map.addNode("A", "图书馆", "这是学校的图书馆");
    map.addNode("B", "食堂", "这是学校的主食堂");
    // 添加路径信息
    map.addEdge("A", "B", 300);

    // 查询景点信息
    map.queryNodeInfo("A");

    // 查询最短路径
    map.shortestPath("A", "B");

    return 0;
}
