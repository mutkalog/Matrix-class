#ifndef MATRIX_H
#define MATRIX_H

#include <stdexcept>

class Matrix {
public:
  Matrix();

  Matrix(int rows, int columns);

  Matrix(const Matrix &obj);

  Matrix(Matrix &&obj) noexcept;

  Matrix &operator=(const Matrix &m2) noexcept;

  Matrix &operator=(Matrix &&m2) noexcept;
  
  ~Matrix();

  void setSize(int rows, int columns);

  void swap(Matrix &obj);

  void makeRandomElements(int border = 10);

  int &operator()(size_t i, size_t j);

  Matrix operator*(const Matrix &m2) const;
  
  Matrix operator+(const Matrix &m2) const;

  Matrix operator-(const Matrix &m2) const;

  void transpose();

  friend std::ostream &operator<<(std::ostream &stream, const Matrix &m);

  friend std::istream &operator>>(std::istream &stream, Matrix &m);

private:
  int _rows, _columns;
  int *matrix;
};

#endif // !MATRIX_H
