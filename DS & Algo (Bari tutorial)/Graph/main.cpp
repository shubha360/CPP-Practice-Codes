#include<iostream>
#include<queue>

using namespace std;

static const int N = 8;

void Breadth_First_Search(int A[N][N], int starting) {

    int track[N] {};
    track[starting] = 1;

    queue<int> q;
    q.push(starting);

    while (!q.empty()) {

        int p = q.front();
        q.pop();

        cout << p << " ";

        for (int i = 1; i < N; i++) {
            
            if(A[p][i] == 1 && track[i] == 0) {

                q.push(i);
                track[i] = 1;
            }
        }
    }

    cout << endl;
}

void Depth_First_Search(int A[N][N], int starting) {

    static int track[N] {};

    cout << starting << " ";
    track[starting] = 1;

    for (int i = 1; i < N; i++) {

        if (A[starting][i] == 1 && track[i] == 0)
            Depth_First_Search(A, i);
    }
}

int main() {

    int graph[N][N] = {
        {0,0,0,0,0,0,0,0},  //0
        {0,0,1,1,1,0,0,0},  //1
        {0,1,0,1,1,0,0,0},  //2
        {0,1,1,0,1,1,0,0},  //3
        {0,1,1,1,0,1,0,0},  //4
        {0,0,0,1,1,0,1,1},  //5
        {0,0,0,0,0,1,0,0},  //6
        {0,0,0,0,0,1,0,0}   //7
        };

    Breadth_First_Search(graph, 7);

    Depth_First_Search(graph, 7);
    
    return 0;
}