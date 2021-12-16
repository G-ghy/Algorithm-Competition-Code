#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
string direction[4] = {"East", "North", "West", "South"};
class Robot {
public:
    int x, y;
    int orientation;
    int width, height;
    vector<vector<int>> graph;
    
    Robot(int width, int height) {
        x = y = 0;
        orientation = 0;
        this->width = width, this->height = height;
        graph = vector<vector<int>> (height, vector<int>(width));
    }
    
    void move(int num) {
        int step = 0;
        while (step < num) {
            int a = x + dx[orientation], b = y + dy[orientation];
            if (a < 0 || a >= height || b < 0 || b >= width) {
                orientation = (orientation + 1) % 4;
            } else {
                x = a, y = b;
                ++step;
            }
        }
    }
    
    vector<int> getPos() {
        vector<int> pos;
        pos.push_back(x);
        pos.push_back(y);
        return pos;
    }
    
    string getDir() {
        return direction[orientation];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->move(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */

int main() {
    return 0;
}