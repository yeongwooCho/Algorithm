#include <iostream>
#include <fstream>
using namespace std;

class MatrixTerm
{
private:
    int row;
    int col;
    int value;
public:
    MatrixTerm() : row(0), col(0), value(0)
    { }
    MatrixTerm(int r, int c, int v)
        :row(r), col(c), value(v)
    { }
    int GetRow(void) {return row;}
    int GetCol(void) {return col;}
    int GetValue(void) {return value;}
    void SetRow(int r) {row = r;}
    void SetCol(int c) {col = c;}
    void SetValue(int v) {value = v;}
    void SetValue(int v, int overload) {value += v;}
};

class SparseMatrix
{
private:
    int n; //Matrix size
    int m; //element of nonzero
    MatrixTerm* smArr; //each element
    int smNum; //numbering
public:
    SparseMatrix(ifstream& ifs)
    {
        ifs >> n;
        ifs >> m;
        smNum = 0;
        smArr = new MatrixTerm[m];
        char wastle;
        for(int i = 0; i < m; i++)
        {
            int arr[3] = {0, 0, 0};
            ifs >> arr[0];
            ifs >> wastle;
            ifs >> arr[1];
            ifs >> wastle;
            ifs >> arr[2];
            smArr[i].SetRow(arr[0] - 1);
            smArr[i].SetCol(arr[1] - 1);
            smArr[i].SetValue(arr[2]);
        }
    }

    SparseMatrix(int num, int mum)
        :n(num), m(mum), smNum(0)
    {
        //assignment memory
        smArr = new MatrixTerm[m];
        for(int i = 0; i < m; i++) //Init
        {
            smArr[i].SetRow(0);
            smArr[i].SetCol(0);
            smArr[i].SetValue(0);
        }
    }

    SparseMatrix(SparseMatrix& copy)
    {
        n = copy.n;
        m = copy.m;
        smNum = copy.smNum;
        smArr = new MatrixTerm[copy.m];
        for(int i = 0; i < m; i++)
        {
            smArr[i] = copy.smArr[i];
        }
    }

    SparseMatrix Multiply(SparseMatrix& B)
    {
		SparseMatrix D(n, m*B.m);
		if(n != B.n)
            {
                cout << "곱할수 없는 두 행렬" << endl;
                return D;
            }
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < B.m; j++)
			{
				if (smArr[i].GetCol() == B.smArr[j].GetRow())
				{
					int check = 0;
					for (int num = 0; num < smNum; num++)
					{

						if ((smArr[num].GetRow() == smArr[i].GetRow()) && smArr[num].GetCol() == B.smArr[j].GetCol())
						{
							smArr[num].SetValue(smArr[i].GetValue() * B.smArr[j].GetValue(), 1);
							check = 1;
						}
					}
					if (!check)
					{
						D.smArr[smNum].SetRow(smArr[i].GetRow());
						D.smArr[smNum].SetCol(B.smArr[j].GetCol());
						D.smArr[smNum++].SetValue(smArr[i].GetValue() * B.smArr[j].GetValue());
					}
				}
			}
		}
		SparseMatrix E(n, smNum);
		for (int i = 0; i < smNum; i++)
		{
			E.smArr[i].SetRow(D.smArr[i].GetRow());
			E.smArr[i].SetCol(D.smArr[i].GetCol());
			E.smArr[i].SetValue(D.smArr[i].GetValue());
		}
		return E;
	}

    void SparsePrint(void)
    {
        cout << "SparsePrint" <<endl;
        cout << "n : " << n << endl;
        cout << "m : " << m << endl;

        for (int i = 0; i < m; i++)
        {
            cout << smArr[i].GetRow() << ", ";
            cout << smArr[i].GetCol() << ", ";
            cout << smArr[i].GetValue() << endl;
        }
    }
    void Print(void)
    {
        ofstream ofs;
        ofs.open("matix.out");
        ofs << n << endl;
        cout << n << endl;
        int arr[n][n] = {};

        for(int i = 0; i < m; i++)
        {
            arr[smArr[i].GetRow()][smArr[i].GetCol()] = smArr[i].GetValue();
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << arr[i][j];
                ofs << arr[i][j];
                if(j != n - 1)
                {
                    cout << ',';
                    ofs << ',';
                }
            }
            cout << endl;
            ofs << endl;
        }
        ofs.close();
    }

    ~SparseMatrix() {delete []smArr;}
};

int main(void)
{
    ifstream ifs;
    ifs.open("matix.inp");
    SparseMatrix A(ifs);
    SparseMatrix B(ifs);
    ifs.close();

    //After multiply, print to file
    A.Multiply(B).Print();

    return 0;
}
