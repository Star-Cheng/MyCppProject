#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <limits>

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
        if (nodes.find(code) != nodes.end()) {
            Node node = nodes[code];
            cout << "景点名称：" << node.name << endl;
            cout << "代号：" << node.code << endl;
            cout << "简介：" << node.intro << endl;
        } else {
            cout << "未找到该景点信息。" << endl;
        }
    }

    // 最短路径查询
    void shortestPath(string start, string end) {
        if (nodes.find(start) == nodes.end() || nodes.find(end) == nodes.end()) {
            cout << "输入的景点代号不存在，请重新输入。" << endl;
            return;
        }

        map<string, int> distance;
        map<string, string> previous;
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

        for (const auto& it : nodes) {
            distance[it.first] = numeric_limits<int>::max();
        }

        distance[start] = 0;
        pq.push(make_pair(0, start));

        while (!pq.empty()) {
            string current = pq.top().second;
            pq.pop();

            for (const auto& it : edges[current]) {
                string neighbor = it.first;
                int weight = it.second.length;
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

    // 添加节点信息
    map.addNode("A", "图书馆", "这是学校的图书馆");
    map.addNode("B", "食堂", "这是学校的主食堂");
    map.addNode("C", "操场", "这是学校的操场");
    map.addNode("D", "实验楼", "这是学校的实验楼");
    map.addNode("E", "教学楼", "用于教学活动的楼宇");
    map.addNode("F", "行政楼", "用于学校行政管理的建筑");
    map.addNode("G", "学生宿舍", "用于学生居住的宿舍楼");
    map.addNode("H", "体育馆", "用于体育活动和比赛的场馆");
    map.addNode("I", "校园商店", "提供学生日常用品的商店");
    map.addNode("J", "医务室", "提供基本的医疗服务");
    map.addNode("K", "艺术馆", "用于举办艺术展览和文化活动的场所");
    map.addNode("L", "图书馆分馆", "如果有多个图书馆分馆，可以分别表示");
    map.addNode("M", "停车场", "提供学生和教职员工停车的区域");
    map.addNode("N", "美食广场", "聚集了各种美食的区域");
    map.addNode("O", "科研楼", "用于进行科学研究的建筑");
    map.addNode("P", "电脑中心", "提供计算机和网络服务的中心");
    map.addNode("Q", "礼堂", "用于举办大型会议、讲座和演出的大厅");
    map.addNode("R", "篮球场", "提供篮球运动的场地");
    map.addNode("S", "足球场", "提供足球运动的场地");
    map.addNode("T", "草坪区", "用于休憩和户外活动的绿化区域");
    map.addNode("U", "实习基地", "为学生提供实习机会的地方");
    map.addNode("V", "天文台", "用于天文观测和研究的设施");
    map.addNode("W", "音乐厅", "用于音乐会和表演的场地");
    map.addNode("X", "语言实验室", "提供语言学习和实践的设施");
    map.addNode("Y", "游泳池", "提供游泳运动的场地");
    map.addNode("Z", "电影院", "用于播放电影和举办放映会的场所");
    map.addNode("AA", "科普馆", "展示科学知识和科技发展的场馆");
    map.addNode("AB", "电子阅览室", "提供电子文献阅读和学习的场所");
    map.addNode("AC", "社团办公室", "供各类学生社团组织使用的办公空间");
    map.addNode("AD", "环保园区", "强调环保和生态教育的区域");
    map.addNode("AE", "历史建筑", "具有历史价值的建筑物");
    map.addNode("AF", "漫画图书馆", "提供漫画和轻小说的阅读空间");
    map.addNode("AG", "健身房", "提供学生和教职员工锻炼身体的设施");
    map.addNode("AH", "心理咨询中心", "提供心理健康服务和咨询的地方");

    // 继续添加路径信息
    map.addEdge("A", "B", 300); 
    map.addEdge("A", "C", 500);
    map.addEdge("B", "D", 200);
    map.addEdge("C", "D", 400);
    map.addEdge("D", "E", 150);
    map.addEdge("D", "F", 300);
    map.addEdge("E", "G", 250);
    map.addEdge("F", "G", 200);
    map.addEdge("G", "H", 300);
    map.addEdge("H", "I", 100);
    map.addEdge("I", "J", 150);
    map.addEdge("J", "K", 200);
    map.addEdge("K", "L", 300);
    map.addEdge("L", "M", 100);
    map.addEdge("M", "N", 200);
    map.addEdge("E", "O", 400);
    map.addEdge("P", "Q", 150);
    map.addEdge("R", "S", 200);
    map.addEdge("S", "T", 100);
    map.addEdge("U", "V", 300);
    map.addEdge("V", "W", 250);
    map.addEdge("X", "Y", 180);
    map.addEdge("Y", "Z", 120);
    map.addEdge("Z", "AA", 300);
    map.addEdge("AB", "AC", 180);
    map.addEdge("AC", "AD", 250);
    map.addEdge("AE", "AF", 150);
    map.addEdge("AG", "AH", 200);
    map.addEdge("AI", "AJ", 120);
    map.addEdge("AK", "AL", 80);
    map.addEdge("AM", "AN", 200);
    map.addEdge("AO", "AP", 150);
    map.addEdge("AQ", "AR", 100);
    map.addEdge("AS", "AT", 120);
    map.addEdge("AU", "AV", 180);
    map.addEdge("AW", "AX", 90);
    map.addEdge("AY", "AZ", 150);
    map.addEdge("BA", "BB", 130);
    map.addEdge("BC", "BD", 110);
    map.addEdge("BE", "A", 250);

    // 查询任意节点信息
    map.queryNodeInfo("A");
    map.queryNodeInfo("B");
    map.queryNodeInfo("C");

    // 查询最短路径
    map.shortestPath("E", "O");
    map.shortestPath("E", "A");
    map.shortestPath("B", "O");
    map.shortestPath("C", "O");

    return 0;
}
