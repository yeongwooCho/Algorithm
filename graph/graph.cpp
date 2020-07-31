#include<bits/stdc++.h>
using namespace std;

typedef struct node {
    int index;
    list<tuple<int,int>> link;
    bool visited=false;
    int length=0;
}Node;

vector<Node> wGraph;
ifstream ifs("graph.inp");
ofstream ofs("graph.out");

void readEdge();
void printGraph();
void init(int n, int k) {
    for(int i=0; i<wGraph.size(); ++i)
        wGraph[i].index = i+1;
    for(int i=0; i<k; ++i) {
        readEdge();
    }
}
void edgeSort();
int BFS(Node& node);
void Reset() {
    for(int i=0; i<wGraph.size(); ++i) {
        wGraph[i].length=0;
        wGraph[i].visited = false;
    }
}
int getIndex(tuple<int,int> tp);
void result(Node& node);
void sortForResult();
void result1(Node&);
void result2(Node&);

int main() {
    int n, k;
    ifs >> n >> k;
    wGraph.resize(n); // ��� ������ŭ �Ҵ�
    init(n,k); //read data
    edgeSort(); //BFS���� weight �������� ����
//    printGraph(); //read data �� ����� Ȯ��

    int maximum = BFS(wGraph[0]);
    int centerIndex = 0;
    Reset();
    for(int i=1; i<wGraph.size(); ++i) {
        int tempLength = BFS(wGraph[i]); // BFS���� ���� �� length ��ȯ
        if(maximum > tempLength) { //center��� ã��
            maximum = tempLength;
            centerIndex = i;
        }
        Reset(); //�� ��� visited�� length �ʱ�ȭ.
    }

  //  cout << "centerIndex: " << centerIndex+1 << endl;
    sortForResult(); //��� ��� ���� ����ȣ �������� ����
    result1(wGraph[centerIndex]);
    Reset();
    result2(wGraph[centerIndex]); //��� ���
    ifs.close();
    ofs.close();
}

bool isLeaf(const Node& node) { //result ���� �ش� ��尡 leaf���� Ȯ��.
    bool flag=false;
    for(auto s: node.link) {
        if(wGraph[getIndex(s)].visited==false)
            flag = true;
    }
    return flag;
}

void result1(Node& node) {
    queue<Node> Q;
    int cnt=0;
    node.visited = true;
    Q.push(node);
    while(!Q.empty()) {
        if(isLeaf(Q.front())) { //leaf�� �ƴϸ� ���� �� ��� ���
            cnt++;
            for(auto s: Q.front().link) {
                if(wGraph[getIndex(s)].visited == false) {
                    wGraph[getIndex(s)].visited = true;
                    Q.push(wGraph[getIndex(s)]);
                }
            }
        }
        Q.pop();

    }
    ofs << cnt << endl;
}

bool isLast(const list<tuple<int,int>>& link, const tuple<int,int>& s,int cnt) {
    bool flag=true;
    auto iter = link.begin();
    advance(iter, cnt);
    for(iter; iter != link.end(); ++iter) {
        int index = getIndex(*iter);
        if(wGraph[index].visited == false)
            flag = false;
    }
    return flag;

}

void result2(Node& node) {
    queue<Node> Q;

    node.visited = true;
    Q.push(node);
    while(!Q.empty()) {
        if(isLeaf(Q.front())) { //leaf�� �ƴϸ� ���� �� ��� ���
            int cnt=0;
            ofs << Q.front().index << ",";
            for(auto s: Q.front().link) {
                if(wGraph[getIndex(s)].visited == false) {
                    wGraph[getIndex(s)].visited = true;
                    if(isLast(Q.front().link,s,cnt))
                        ofs << getIndex(s)+1 << endl;
                    else
                        ofs << getIndex(s)+1 << ",";
                    Q.push(wGraph[getIndex(s)]);
                    cnt++;
                }
            }
        }
        Q.pop();

    }
}

int getIndex(tuple<int,int> tp) {
    return get<0>(tp)-1;
}

int BFS(Node& node) { //���� ��� ã�� ����.
    queue<Node> Q;
    node.visited = true; //ó�� ���� ������ q�� �����鼭 ����
    Q.push(node);
    int longestLength=0;
    while(!Q.empty()) {
        for(auto s: Q.front().link) {
            if(wGraph[getIndex(s)].visited == false) { //�湮 �������� visited true�� ����� Q�� push
                wGraph[getIndex(s)].visited = true;
                wGraph[getIndex(s)].length += get<1>(s) + Q.front().length; //length �� �����ش�. get<1>(s)�� weight
                Q.push(wGraph[getIndex(s)]);
            }
            if(Q.front().length > longestLength) {
                longestLength = Q.front().length;
            }
        }
       // cout << Q.front().index << " length: " << Q.front().length << endl;
        Q.pop();
    }
 //   printf("node%d longestLength: %d\n", node.index, longestLength);
    return longestLength;
}

bool mycomp(const tuple<int,int>& first, const tuple<int,int>& second) {
    return (get<1>(first) < get<1>(second));
}

void edgeSort() {
    for(int i=0; i<wGraph.size(); ++i)
        wGraph[i].link.sort(mycomp);
}

void readEdge() {
    int s,d,w;
    char trash;
    ifs >> s >> trash >> d >> trash >> w;
    auto first = make_tuple(d,w);
    auto second = make_tuple(s,w);

    wGraph[s-1].link.push_back(first);
    wGraph[d-1].link.push_back(second);
}

void printGraph() {
    for(auto s: wGraph) {
        cout << s.index << ": ";
        for(auto t: s.link) {
           cout << "(" << get<0>(t) << "," << get<1>(t) << ") ";
        }
        cout << endl;
    }
}

bool compForResult(const tuple<int,int>& first, const tuple<int,int>& second) {
    return (get<0>(first) < get<0>(second));
}

void sortForResult() {
    for(int i=0; i<wGraph.size(); ++i)
        wGraph[i].link.sort(compForResult);
}
