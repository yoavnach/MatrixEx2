//yoav1.nach@gmail.com

#include "SquareMat.h"

namespace Matrix
{
	int SquareMat::getSum() const
	{
		int sum = 0;
		for (int i = 0; i < this->size; i++)
		{
			for (int j = 0; j < this->size; j++)
			{
				sum += this->mat[i][j];
			}
		}
		return sum;
	}
	double SquareMat::determinanta()
	{
		if (this->size == 0)
		{
			throw "mat is size zero";
		}
		if (this->size == 1)
		{
			return mat[0][0];
		}
		if (size == 2)
		{
			return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
		}
		double det = 0;
		int sign = 1;
		for (int i = 0; i < this->size; i++)
		{
			SquareMat newMat = SquareMat(this->size - 1);
			for (int j = 0; j < this->size-1; j++)
			{
				for (int k = 0; k < this->size-1; k++)
				{
					if (k < i)
					{
						newMat[j][k] = mat[j+1][k];
					}
					if (k >= i)
					{
						newMat[j][k] = mat[j+1][k + 1];
					}
				}
			}
			//newMat.printMat();
			det += sign * this->mat[0][i] * newMat.determinanta();
			sign *= -1;
		}
		return det;
	}
	SquareMat::SquareMat(int size, double** mat)
	{
		
		if (size < 1)
		{
			throw "size must be greater than zero!";
		}
		this->mat = new double* [size];
		for (int i = 0; i < size; i++)
		{
			this->mat[i] = new double[size];
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				this->mat[i][j] = mat[i][j];
			}
		}
		this->size = size;
	}

	SquareMat::SquareMat(int size)
	{

		if (size < 1)
		{
			throw "size must be greater than zero!";
		}
		this->mat = new double* [size];
		for (int i = 0; i < size; i++)
		{
			this->mat[i] = new double[size];
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				this->mat[i][j] = 0;
			}
		}
		this->size = size;
		this->mat = mat;
	}


	void SquareMat::printMat()
	{
		
		for (int i = 0; i < this->size; i++)
		{
			cout << "|";
			for (int j = 0; j < this->size-1; j++)
			{
				cout << this->mat[i][j] << " ,";
			}
			cout << this->mat[i][size - 1] << "|"<<endl;
		}
		cout << endl;
	}

	SquareMat SquareMat::operator+(const SquareMat& other) const
	{
		if (this->size != other.size)
		{
			throw "not the same size";
		}
		SquareMat ans = SquareMat(this->size, this->mat);
		for (int i = 0; i < this->size; i++)
		{
			for (int j = 0; j < this->size; j++)
			{
				ans.mat[i][j] = this->mat[i][j] + other.mat[i][j];
			}
		}
		return ans;
	}
	SquareMat SquareMat::operator-(const SquareMat& other) const
	{
		if (this->size != other.size)
		{
			throw "not the same size";
		}
		SquareMat ans = SquareMat(this->size, this->mat);
		for (int i = 0; i < this->size; i++)
		{
			for (int j = 0; j < this->size; j++)
			{
				ans.mat[i][j] -= other.mat[i][j];
			}
		}
		return ans;
	}
	SquareMat SquareMat::operator-()
	{
		
		SquareMat ans = SquareMat(this->size, this->mat);
		for (int i = 0; i < this->size; i++)
		{
			for (int j = 0; j < this->size; j++)
			{
				ans.mat[i][j] *= -1;
			}
		}
		return ans;
	}
	SquareMat SquareMat::operator*(const SquareMat& other) const
	{
		if (this->size != other.size)
		{
			throw "not the same size";
		}
		SquareMat ans = SquareMat(this->size);
		for (int i = 0; i < this->size; i++)
		{
			for (int j = 0; j < this->size; j++)
			{
				double sum = 0;
				for (int k =0 ; k < this->size; k++)
				{
					sum += this->mat[i][k] * other.mat[k][j];
				}
				ans.mat[i][j] = sum;
			}
		}
		return ans;
	}

	SquareMat& SquareMat::operator=(const SquareMat& other) 
	{
		if (this->mat != nullptr)
		{
			for (int i = 0; i < this->size; i++)
			{
				if (this->mat[i] != nullptr)
				{
					delete[] this->mat[i];
				}
			}
			delete[] this->mat;
		}
		int size = other.size;
		this->mat = new double* [size];
		for (int i = 0; i < size; i++)
		{
			this->mat[i] = new double[size];
			for (int j = 0; j < size; j++)
			{
				this->mat[i][j] = other[i][j];
			}
		}
		return *this;
	}
	SquareMat SquareMat::operator*(const double scalar) const
	{
		
		SquareMat ans = SquareMat(this->size,this->mat);
		for (int i = 0; i < this->size; i++)
		{
			for (int j = 0; j < this->size; j++)
			{
				ans.mat[i][j] *=scalar;
			}
		}
		return ans;
	}
	
	SquareMat operator*(const double scalar, const SquareMat& mat)
	{
		return mat * scalar;
	}

	ostream& operator<<(ostream& os, const SquareMat& mat)
	{

		for (int i = 0; i < mat.size; i++)
		{
			os << "|";
			for (int j = 0; j < mat.size - 1; j++)
			{
				os << mat[i][j] << " ,";
			}
			os << mat[i][mat.size - 1] << "|" << endl;
		}
		os << endl<<endl;
		return os;
	}

	SquareMat SquareMat::operator%(const SquareMat& other) const
	{
		if (this->size != other.size)
		{
			throw "not the same size";
		}
		SquareMat ans = SquareMat(this->size,this->mat);
		for (int i = 0; i < this->size; i++)
		{
			for (int j = 0; j < this->size; j++)
			{
				ans.mat[i][j] *= other.mat[i][j];
			}
		}
		return ans;
	}

	SquareMat SquareMat::operator%(const int scalar) const
	{

		SquareMat ans = SquareMat(this->size, this->mat);
		for (int i = 0; i < this->size; i++)
		{
			for (int j = 0; j < this->size; j++)
			{
				int num = this->mat[i][j];
				ans.mat[i][j] = num%scalar;
			}
		}
		return ans;
	}

	SquareMat SquareMat::operator/(const double scalar) const
	{

		SquareMat ans = SquareMat(this->size, this->mat);
		for (int i = 0; i < this->size; i++)
		{
			for (int j = 0; j < this->size; j++)
			{
				ans.mat[i][j] /= scalar;
			}
		}
		return ans;
	}
	SquareMat SquareMat::operator^(const int scalar) const
	{
		if (scalar < 0)
		{
			throw "power is less than 0";
		}
		SquareMat ans = SquareMat(this->size, this->mat);
		for (int i = 1; i < scalar; i++)
		{
			ans = ans* (*this);
		}
		return ans;
	}

	double* SquareMat::operator[](int index) const
	{
		if (index < 0 || index >= this->size)
		{
			
			throw "index out of bounds";
		}
		return this->mat[index];
	}

	SquareMat& SquareMat::operator++()
	{
		for (int i = 0; i < this->size; i++)
		{
			for (int j = 0; j < this->size; j++)
			{
				this->mat[i][j] +=1;
			}
		}
		return *this;
	}

	SquareMat SquareMat::operator++(int)
	{
		SquareMat old = SquareMat(this->size, this->mat);
		++(*this);
		return old;
	}

	void SquareMat::operator~()
	{
		for (int i = 0; i < this->size; i++)
		{
			for (int j = 0; j < i; j++)
			{
				double temp = this->mat[i][j];
				this->mat[i][j] = this->mat[j][i];
				this->mat[j][i] = temp;
			}
		}
	}

	bool SquareMat::operator==(const SquareMat& other)const
	{
		return this->getSum() == other.getSum();
	}
	bool SquareMat::operator!=(const SquareMat& other)const
	{
		return this->getSum() != other.getSum();
	}
	bool SquareMat::operator<(const SquareMat & other)const
	{
		return this->getSum() < other.getSum();
	}
	bool SquareMat::operator>(const SquareMat& other)const
	{
		return this->getSum() > other.getSum();
	}
	bool SquareMat::operator>=(const SquareMat& other)const
	{
		return this->getSum() >= other.getSum();
	}
	bool SquareMat::operator<=(const SquareMat& other)const
	{
		return this->getSum() <= other.getSum();
	}

	double SquareMat::operator!()
	{
		return this->determinanta();
	}

	SquareMat& SquareMat::operator+=(const SquareMat& other)
	{
		SquareMat ans = *this + other;
		*this = ans;
		return ans;
	}
	SquareMat& SquareMat::operator-=(const SquareMat& other)
	{
		SquareMat ans = *this - other;
		*this = ans;
		return ans;
	}
	SquareMat& SquareMat::operator*=(const SquareMat& other)
	{
		SquareMat ans = *this * other;
		*this = ans;
		return ans;
	}
	SquareMat& SquareMat::operator%=(const SquareMat& other)
	{
		SquareMat ans = *this % other;
		*this = ans;
		return ans;
	}
	SquareMat& SquareMat::operator/=(const double scalar)
	{
		SquareMat ans = *this / scalar;
		*this = ans;
		return ans;
	}
	SquareMat& SquareMat::operator%=(const int scalar)
	{
		SquareMat ans = *this % scalar;
		*this = ans;
		return ans;
	}
	SquareMat& SquareMat::operator*=(const double scalar)
	{
		SquareMat ans = *this * scalar;
		*this = ans;
		return ans;
	}


}
