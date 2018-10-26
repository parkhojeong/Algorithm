#include <iostream>
using namespace std;
#include <vector>
#include <fstream>
#include <iomanip>

#define INFINITE 10000

void matPrn(vector<vector<int>> A, char* matName);
int minimum(int a, int b);
int main() {

	fstream fin("input.txt");
	vector<vector<int>> D;
	vector<vector<int>> P;
	vector<vector<int>> W;
	int N , i , j , k;

	fin >> N;

	W.assign(N, vector<int>(N, 0));// 행렬 크기에 맞는 W,D,P 선언
	D.assign(N, vector<int>(N, 0)); 
	P.assign(N, vector<int>(N, 0)); // 보기 좋게 하도록 0번 인덱스 미사용, 1-N 의 인덱스 사용
	

	for (i = 0; i < N; i++) {		// 초기 입력값 저장
		for (j = 0; j < N; j++) {
			fin >> W[i][j];
		}
	}
	matPrn(W,"W");
	D = W;					// 입력 배열을 D에 저장


	matPrn(D,"D");

	for (k = 0; k < N; k++) { // floyd 알고리즘 
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if (D[i][k] + D[k][j] < D[i][j]) {
					P[i][j] = k+1;
					D[i][j] = D[i][k] + D[k][j];
				}
			}
		}
	}

	matPrn(D,"D");
	matPrn(P,"P");
	return 0;
}

void matPrn(vector<vector<int>> A, char* matName) {
	
	int fontWidth = 10;   // 10 이상의 짝수로 해야 출력 모양이 정상적으로 나옴.
	int blockWidth = fontWidth/2;

	for (int i = 0; i <= A.size()*fontWidth+blockWidth*3; i++) {
		cout <<  "-";
	}
	cout << endl;
	cout << "l" <<setw(fontWidth-8)<< right << matName <<"[i][j] l"  ;
	for (int i = 0; i < A.size() ; i++) {
		cout << setw(fontWidth) <<  i+1;
	}
	cout << setw(blockWidth)<<right<<"l"<< endl;
	for (int i = 0; i <= A.size()*fontWidth + blockWidth * 3; i++) {
		cout << "-";
	}
	cout << endl;

	for (int i = 0; i < A.size(); i++) {
		cout << "l"<<setw(blockWidth) << i + 1 << setw(blockWidth)<<"l";

		for (int j = 0; j < A.size(); j++) {
			cout << setw(fontWidth) << A[i][j] ;
		}

		cout << setw(blockWidth)<< right<<"l"<< endl;
	}
	for (int i = 0; i <= A.size()*fontWidth + blockWidth * 3; i++) {
		cout << "-";
	}
	cout << endl;
	cout << endl;
}
int minimum(int a, int b) {
	if (a > b) {
		return b;
	}
	else {
		return a;
	}
}