//yoav1.nach@gmail.com

#pragma once
#include <iostream>
using namespace std;
namespace Matrix
{
	class SquareMat
	{
	private:
		double** mat;
		int size;
		int getSum()const;
		double determinanta();

	public:
		SquareMat(int size,double** mat);
		SquareMat(int size);
		void printMat();

		~SquareMat()
		{
			if (this->mat != NULL)
			{
				for (int i = 0; i < this->size; i++)
				{
					if (this->mat[i] != NULL)
						delete[] this->mat[i];
				}
				delete[] mat;
			}
			
		}
		SquareMat operator+(const SquareMat& other) const;
		SquareMat operator-(const SquareMat& other) const;
		SquareMat operator-();
		SquareMat operator*(const SquareMat& other) const;
		SquareMat& operator=(const SquareMat& other) ;
		SquareMat operator*(const double scalar) const;
		friend SquareMat operator*(const double scalar, const SquareMat& mat);
		SquareMat operator%(const SquareMat& other) const;
		SquareMat operator%(const int scalar) const;
		SquareMat operator/(const double scalar) const;
		SquareMat operator^(const int scalar) const;
		double* operator[](int index)const;
		SquareMat& operator++(); 
		SquareMat operator++(int);
		void operator~();
		bool operator==(const SquareMat& other)const;
		bool operator!=(const SquareMat& other)const;
		bool operator<(const SquareMat & other)const;
		bool operator>(const SquareMat& other)const;
		bool operator>=(const SquareMat& other)const;
		bool operator<=(const SquareMat& other)const;
		double operator!();
		SquareMat& operator+=(const SquareMat& other);
		SquareMat& operator-=(const SquareMat& other);
		SquareMat& operator*=(const SquareMat& other);
		SquareMat& operator%=(const SquareMat& other);
		SquareMat& operator/=(const double scalar);
		SquareMat& operator%=(const int scalar);
		SquareMat& operator*=(const double scalar);
		friend std::ostream& operator<<(std::ostream& os, const SquareMat& mat);



		
		

	};
	
}


