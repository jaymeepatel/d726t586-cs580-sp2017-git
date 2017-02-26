#include<iostream>
using namespace std;

#include "Matrix.h"

Matrix::Matrix()
{
	
}

void Matrix::allocateSpace()
{
	mArray = new double*[numRows];
	
	for(int i = 0; i < numRows; i++)
	{
			mArray[i] = new double[numCols];
	}
}

void Matrix::deleteSpace()
{
	for(int i = 0; i < numRows; i++)
	{
			delete[](mArray[i]);
    }

	delete []mArray;
	
	numRows = 0;
	numCols = 0;
}

Matrix::Matrix(const Matrix &m)
{
	numRows = m.numRows;
	numCols = m.numCols;
	allocateSpace();
	
	for(int i = 0; i < numRows; i++)
	{
		for(int j = 0; j < numCols; j++)
		{
			mArray[i][j] = m.mArray[i][j];
		}
	}
	
	cout << "Matrix copy ctor: Allocated the matrix" << endl;
}

Matrix::~Matrix()
{
	deleteSpace();
	cout << "Matrix dtor: Released the matrix\n" << endl;
}

Matrix& Matrix::operator=(const Matrix& m2)
{
	if(this != &m2)
	{
		deleteSpace();
		
		numRows = m2.numRows;
		numCols = m2.numCols;
		allocateSpace();
		
		for(int i = 0; i < numRows; i++)
		{
			for(int j = 0; j < numCols; j++)
			{
				mArray[i][j] = m2.mArray[i][j];
			}
		}			
		
		cout << "Matrix operator=: Assigned the matrix" << endl;
		return *this;
	}
	
}

Matrix operator+(const Matrix& m1, const Matrix& m2)
{
	Matrix m3(m1);
	
	for(int i = 0; i < m3.numRows; i++)
	{
		for(int j = 0; j < m3.numCols; j++)
		{
			m3.mArray[i][j] = m3.mArray[i][j] + m2.mArray[i][j];
		}
	}
	
	return m3;
}

istream& operator>>(istream& ISObj, Matrix& m)
{
	int rows, cols;
	ISObj >> rows >> cols;
	
	if(rows != m.numRows || cols != m.numCols)
	{
		m.deleteSpace();
	}
	
	m.numRows = rows;
	m.numCols = cols;
	
	m.allocateSpace();
	
	for(int i = 0; i < m.numRows; i++)
	{
		for(int j = 0; j < m.numCols; j++)
		{
			ISObj >> m.mArray[i][j];
		}
	}
	
	return ISObj;
}

ostream& operator<<(ostream& OSObj, const Matrix& m)
{
	OSObj << "This is a " << m.numRows << " by " << m.numCols << " Matrix" << endl;
	
	for(int i = 0; i < m.numRows; i++)
	{
		for(int j = 0; j < m.numCols; j++)
		{
			OSObj << m.mArray[i][j] << " ";
		}
		
		OSObj << endl;
	}
	
	return OSObj;
}

void Matrix::printDiagonal() const
{
	cout << "Matrix::printDiagonal(): Sorry, no diagonal\n" << endl;
}