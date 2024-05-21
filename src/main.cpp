#include "header_files/matrix.h"
#include <fstream>
#include <iostream>
#include <stdexcept>

int main() {
  try {
    std::ifstream in("../data/items.txt");
    if (!in)
      return 1;
    
    Matrix m1(3, 2);
    Matrix m2(3, 3);
    Matrix m3(2, 3);
    Matrix m4(3, 2);

    // filling the matrix 1 with random numbers from 0 to 9
    m1.makeRandomElements(10);
    // filling the matrix 2 with numbers from a file
    in >> m2;
    // filling the matrix 3 with random numbers from 0 to 5
    m3.makeRandomElements(5);

    m1(1, 1) = 29; // accessing an element in 1st row and 1st column
    std::cout << "matrix №1:\n";
    std::cout << m1 << "\n"; 
    std::cout << "matrix №2:\n";
    std::cout << m2 << "\n";
    std::cout << "matrix №3:\n";
    std::cout << m3 << "\n";

    // a copy constructor demonstration
    Matrix m5 = m2 ;
    // a move assignment operator demonstration
    m4 = m1 * m3;
    std::cout << "matrix №4 that equal to matrix №1 * matrix №3:\n";
    std::cout << m4 << "\n";
    m3 = m5 - m4;
    std::cout << "matrix №3 that equal to matrix №5 - matrix №4:\n";
    std::cout << m3 << "\n";

    // matrix transposing 
    m4.transpose();
    std::cout << "matrix №4 that equal to transposed matrix №4:\n";
    std::cout << m4 << "\n";

    //std::cout << m5(21,3); // Error: incorrect matrix index value

  } catch (const std::length_error &ex) {
    std::cout << ex.what() << "\n";
  } catch (const std::out_of_range &ex) {
    std::cout << ex.what() << "\n";
  }
}
