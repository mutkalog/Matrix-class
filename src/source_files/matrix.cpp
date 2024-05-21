#include "../header_files/matrix.h"
#include <ostream>
#include <istream>

Matrix::Matrix(int rows, int columns)
    : _rows(rows), _columns(columns), matrix(new int[_rows * _columns]) {}

Matrix::Matrix(const Matrix &obj)
    : _rows(obj._rows), _columns(obj._columns),
      matrix(new int[_rows * _columns]) {
  for (size_t i = 0; i != (_columns * _rows); ++i) {
    matrix[i] = obj.matrix[i];
  }
}

Matrix::Matrix(Matrix &&obj)
    : _rows(obj._rows), _columns(obj._columns), matrix(obj.matrix) {
  obj.matrix = nullptr;
  obj._rows = 0;
  obj._columns = 0;
}

Matrix &Matrix::operator=(const Matrix &m2) {
  delete[] matrix;
  _rows = m2._rows;
  _columns = m2._columns;
  matrix = new int[_rows * _columns];
  for (size_t i = 0; i != (_columns * _rows); ++i) {
    matrix[i] = m2.matrix[i];
  }
  return *this;
}

Matrix &Matrix::operator=(Matrix &&m2) {
  delete[] matrix;
  matrix = m2.matrix;
  m2.matrix = nullptr;
  _columns = m2._columns;
  _rows = m2._rows;

  return *this;
}

Matrix::~Matrix() { delete[] matrix; }

void Matrix::makeRandomElements(int border) {
  for (size_t i = 0; i != (_rows * _columns); ++i) {
    matrix[i] = std::rand() % border;
  }
}

int &Matrix::operator()(size_t i, size_t j) {
  if (i >= _rows || j >= _columns) {
    throw std::out_of_range("Error: incorrect matrix index value(s)");
  }
  return matrix[(i * j) + j];
}

Matrix Matrix::operator*(const Matrix &m2) const {
  if (this->_columns != m2._rows) {
    throw std::length_error(
        "Illegal operation: matrix multiplication when columns of the left "
        "matrix do not equal to rows of the right matrix");
  }

  Matrix result(this->_rows, m2._columns);
  for (size_t i = 0; i != this->_rows; ++i) {
    for (size_t k = 0; k != m2._columns; ++k) {
      int tmp = 0;
      for (size_t j = 0; j != this->_columns; ++j) {
        tmp += this->matrix[(i * this->_columns) + j] *
               m2.matrix[(j * m2._columns) + k];
      }
      result.matrix[(i * result._columns) + k] = tmp;
    }
  }
  return result;
}

Matrix Matrix::operator+(const Matrix &m2) const {
  if (this->_columns != m2._columns || this->_rows != m2._rows) {
    throw std::length_error(
        "Illegal operation: matrix addition when sizes not equal");
  }

  Matrix result(this->_rows, this->_columns);
  for (size_t i = 0; i != _rows; ++i) {
    for (size_t j = 0; j != _columns; ++j) {
      size_t id = i * _columns + j;
      result.matrix[id] = this->matrix[id] + m2.matrix[id];
    }
  }
  return result;
}

Matrix Matrix::operator-(const Matrix &m2) const {
  if (this->_columns != m2._columns || this->_rows != m2._rows) {
    throw std::length_error(
        "Illegal operation: matrix substraction when sizes not equal");
  }

  Matrix result(this->_rows, this->_columns);
  for (size_t i = 0; i != _rows; ++i) {
    for (size_t j = 0; j != _columns; ++j) {
      size_t id = i * _columns + j;
      result.matrix[id] = this->matrix[id] - m2.matrix[id];
    }
  }
  return result;
}

void Matrix::transpose() {
  Matrix result(_columns, _rows);
  for (size_t i = 0; i != _rows; ++i) {
    for (size_t j = 0; j != _columns; ++j) {
      size_t id = i * _columns + j;
      result.matrix[(j * _rows) + i] = this->matrix[id];
    }
  }
  *this = result;
}

std::ostream &operator<<(std::ostream &stream, const Matrix &m) {
  for (size_t i = 0; i != m._rows; ++i) {
    for (size_t j = 0; j != m._columns; ++j) {
      stream << m.matrix[(i * m._columns) + j] << " ";
    }
    stream << "\n";
  }
  return stream;
}

std::istream &operator>>(std::istream &stream, Matrix &m) {
  for (size_t i = 0; i != m._rows; ++i) {
    for (size_t j = 0; j != m._columns; ++j) {
      stream >> m.matrix[(i * m._columns) + j];
    }
  }
  return stream;
}
