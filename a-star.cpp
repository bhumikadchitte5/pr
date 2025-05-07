#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

const int dx[] = {-1, 0, 1, 0};  // Directions: up, right, down, left
const int dy[] = {0, 1, 0, -1};

struct Node {
    int x, y;
    int g, h;  // g = cost from start, h = heuristic to goal
    Node* parent;

    Node(int _x, int _y, int _g, int _h, Node* _parent = nullptr)
        : x(_x), y(_y), g(_g), h(_h), parent(_parent) {}

    int f() const { return g + h; }  // total cost
};

// Custom comparator for priority queue
struct Compare {
    bool operator()(const Node* a, const Node* b) {
        return a->f() > b->f();
    }
};

// Manhattan Distance
int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

bool isValid(int x, int y, int n, int m, vector<vector<int>>& grid) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 0;
}

void printPath(Node* end) {
    stack<pair<int, int>> path;
    while (end) {
        path.push({end->x, end->y});
        end = end->parent;
    }
    cout << "Path: ";
    while (!path.empty()) {
        auto p = path.top();
        path.pop();
        cout << "(" << p.first << "," << p.second << ") ";
    }
    cout << endl;
}

void AStarSearch(vector<vector<int>>& grid, pair<int, int> start, pair<int, int> goal) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    priority_queue<Node*, vector<Node*>, Compare> pq;

    Node* startNode = new Node(start.first, start.second, 0, heuristic(start.first, start.second, goal.first, goal.second));
    pq.push(startNode);

    while (!pq.empty()) {
        Node* current = pq.top();
        pq.pop();

        int x = current->x, y = current->y;

        if (visited[x][y]) continue;
        visited[x][y] = true;

        if (x == goal.first && y == goal.second) {
            cout << "Path found!\n";
            printPath(current);
            return;
        }

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (isValid(nx, ny, n, m, grid) && !visited[nx][ny]) {
                int gNew = current->g + 1;
                int hNew = heuristic(nx, ny, goal.first, goal.second);
                Node* neighbor = new Node(nx, ny, gNew, hNew, current);
                pq.push(neighbor);
            }
        }
    }

    cout << "No path found.\n";
}

int main() {
    vector<vector<int>> grid = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0}
    };

    pair<int, int> start = {0, 0};
    pair<int, int> goal = {4, 4};

    AStarSearch(grid, start, goal);
    return 0;
}

// using an arrays

#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 50;
const int dx[4] = {-1, 0, 1, 0}; // up, right, down, left
const int dy[4] = {0, 1, 0, -1};

struct Node {
    int x, y;
    int g;         // Cost from start
    int h;         // Heuristic to goal
    int f;         // Total cost f = g + h
    int parentX, parentY; // For path tracing
    bool visited;
    bool inOpenList;
};

// Simple grid size and structure
int grid[5][5] = {
    {0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 1, 0},
    {1, 1, 0, 1, 0},
    {0, 0, 0, 0, 0}
};

Node nodes[MAX][MAX];
int openList[MAX * MAX];
int openListSize = 0;

// Manhattan Distance
int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

// Check bounds and not blocked
bool isValid(int x, int y) {
    return x >= 0 && x < 5 && y >= 0 && y < 5 && grid[x][y] == 0;
}

// Push to open list
void pushToOpenList(int index) {
    openList[openListSize++] = index;
}

// Pop lowest f() from open list
int popLowestF() {
    int minIndex = 0;
    for (int i = 1; i < openListSize; i++) {
        int idx1 = openList[i];
        int idx2 = openList[minIndex];
        if (nodes[idx1 / 5][idx1 % 5].f < nodes[idx2 / 5][idx2 % 5].f) {
            minIndex = i;
        }
    }

    int result = openList[minIndex];
    for (int i = minIndex; i < openListSize - 1; i++) {
        openList[i] = openList[i + 1];
    }
    openListSize--;
    return result;
}

// Print path
void printPath(int x, int y) {
    if (nodes[x][y].parentX == -1 && nodes[x][y].parentY == -1) {
        cout << "(" << x << "," << y << ") ";
        return;
    }
    printPath(nodes[x][y].parentX, nodes[x][y].parentY);
    cout << "(" << x << "," << y << ") ";
}

void AStar(int startX, int startY, int goalX, int goalY) {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) {
            nodes[i][j].x = i;
            nodes[i][j].y = j;
            nodes[i][j].g = 9999;
            nodes[i][j].h = heuristic(i, j, goalX, goalY);
            nodes[i][j].f = 9999;
            nodes[i][j].parentX = -1;
            nodes[i][j].parentY = -1;
            nodes[i][j].visited = false;
            nodes[i][j].inOpenList = false;
        }

    nodes[startX][startY].g = 0;
    nodes[startX][startY].f = nodes[startX][startY].h;
    pushToOpenList(startX * 5 + startY);
    nodes[startX][startY].inOpenList = true;

    while (openListSize > 0) {
        int idx = popLowestF();
        int x = idx / 5;
        int y = idx % 5;
        nodes[x][y].visited = true;

        if (x == goalX && y == goalY) {
            cout << "Path found: ";
            printPath(x, y);
            cout << endl;
            return;
        }

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (isValid(nx, ny) && !nodes[nx][ny].visited) {
                int gNew = nodes[x][y].g + 1;
                int fNew = gNew + nodes[nx][ny].h;
                if (!nodes[nx][ny].inOpenList || fNew < nodes[nx][ny].f) {
                    nodes[nx][ny].g = gNew;
                    nodes[nx][ny].f = fNew;
                    nodes[nx][ny].parentX = x;
                    nodes[nx][ny].parentY = y;
                    if (!nodes[nx][ny].inOpenList) {
                        pushToOpenList(nx * 5 + ny);
                        nodes[nx][ny].inOpenList = true;
                    }
                }
            }
        }
    }

    cout << "No path found." << endl;
}

int main() {
    int startX = 0, startY = 0;
    int goalX = 4, goalY = 4;
    AStar(startX, startY, goalX, goalY);
    return 0;
}
