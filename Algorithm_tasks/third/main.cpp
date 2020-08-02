#include <iostream>
#include <string>
using namespace std;

class Maze {
private:
	bool** check;
	string input;
	int size;
	int numberOfPath;
public:
	Maze(int _size) : size(_size), numberOfPath(0) {
		check = new bool* [size + 2];
		for (int i = 0; i < size + 2; i++) { check[i] = new bool[size + 2]{ false }; }

		//init
		for (int i = 0; i < size + 1; i++) {
			check[0][i] = true;
			check[i][size+1] = true;
			check[i+1][0] = true;
			check[size+1][i+1] = true;
		}
		cin >> input; //string 받기
	}
	~Maze() {
		for (int i = 0; i < size; ++i) { delete[] check[i]; }
		delete[] check;
	}

	void print() const { cout << numberOfPath << endl; }

	bool ladle(int i, int j); //뜻 : 국자
    bool promising(int i, int j, int step);
	void escape(int i, int j, int step);
};



int main() {
	Maze maze(7);
	maze.escape(1, 1, 0);
	maze.print();

	return 0;
}



bool Maze::ladle(int i, int j){
    if(check[i][j-1] == check[i][j+1] && check[i][j+1] == true){
        if(check[i-1][j] != check[i+1][j]) {return false;}
        return true;
    }
    else if(check[i-1][j] == check[i+1][j] && check[i+1][j] == true){
       if(check[i][j-1] != check[i][j+1]) {return false;}
       return true;
    }
    return true;
}



bool Maze::promising(int i, int j, int step) {
		if (check[i][j] == true) { return false; }
		if (check[i][j+1]==check[i][j-1] && check[i+1][j]==check[i-1][j]) { return false; }
        if (i == 7 && j == 1 && step != 48) { return false; }

        if(check[i-1][j-1] == 0){ return ladle(i-1, j-1); }
        if(check[i-1][j+1] == 0){ return ladle(i-1, j+1); }
        if(i!=6 && j!=2){
            if(check[i+1][j-1] == 0){ return ladle(i+1, j-1); }
        }
        if(check[i+1][j+1] == 0){ return ladle(i+1, j+1); }

		return true;
}



void Maze::escape(int i, int j, int step) {
		//step는 [0]번째 string을 읽어서 가동함을 의미함
		if (promising(i, j, step)) {
			check[i][j] = true;
			if (input[step] == '?') {
				escape(i - 1, j, step + 1);  //Up
				escape(i, j + 1, step + 1);  //Right
				escape(i + 1, j, step + 1);  //Down
				escape(i, j - 1, step + 1);  //Left
            }
			else if (input[step] == 'U') {
				escape(i - 1, j, step + 1); //Up
			}
			else if (input[step] == 'R') {
				escape(i, j + 1, step + 1); //Right
			}
			else if (input[step] == 'L') {
				escape(i, j - 1, step + 1); //Left
			}
			else if (input[step] == 'D') {
				escape(i + 1, j, step + 1); //Down
			}
			check[i][j] = false;
		}
		else if (step == 48 && i == 7 && j == 1) {
			numberOfPath++;
			return;
		}
}
