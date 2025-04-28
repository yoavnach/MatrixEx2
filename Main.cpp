//yoav1.nach@gmail.com

#include "SquareMat.h"

using namespace Matrix;

int main()
{
	double** mat = new double*[3];
	
	int n = 1;
	for (int i = 0; i < 3; i++)
	{
		mat[i] = new double[3];
		for (int j = 0; j < 3; j++)
		{
			mat[i][j] = n;
			n++;
		}
	}
	double** mat2 = new double* [3];

	for (int i = 0; i < 3; i++)
	{
		mat2[i] = new double[3];
		for (int j = 0; j < 3; j++)
		{
			mat2[i][j] = n;
			n++;
		}
	}
	SquareMat s =  SquareMat(3, mat);
	SquareMat s2 =  SquareMat(3, mat2);
	s.printMat();
	s2.printMat();
	SquareMat s3 = s + s2;
	s3.printMat();
	s3 = s2 - s;
	s3.printMat();

	s3 = s2 * s;

	s3.printMat();

	s3 = s * 2;
	s3.printMat();
	s3 = 2 * s;
	s3.printMat();

	s3 = s % s2;

	s3.printMat();

	~s3;

	s3.printMat();

	cout << s3[0][0] << endl << endl;
	cout << s3[2][1] << endl << endl;
	cout << !s3<<endl<<endl;

	cout << s3;
	for (int i = 0; i < 3; i++)
	{
		delete[] mat[i];
		delete[] mat2[i];
	}
	delete[] mat;
	delete[]mat2;
	
}