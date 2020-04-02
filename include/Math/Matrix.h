/**
 * @file C:\Users\leona\source\repos\Shared\include\Math\Matrix.h.
 *
 * Declares the matrix class
 **/

#pragma once
#include "Vector.h"

/** . */
namespace ELCT350
{
/** . */
  namespace Math
  {
    /**
     * A matrix. This class cannot be inherited..
     *
     * @author Rod Leonard
     * @date 4/2/2020
     **/
    class Matrix final
    {
    public:
      #pragma region Constructors and Destructors
      /**
       * Constructor
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @param  rowSize    (Optional) Size of the row.
       * @param  columnSize (Optional) Size of the column.
       **/
      Matrix(size_t rowSize = 0, size_t columnSize = 0);
      /**
       * Constructor
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @param  original The original.
       **/
      Matrix(const Matrix& original);
      /**
       * Constructor
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @param [in,out] old The old.
       **/
      Matrix(Matrix&& old) noexcept;
      /**
       * Destructor
       *
       * @author Rod Leonard
       * @date 4/2/2020
       **/
      ~Matrix();
      #pragma endregion

      #pragma region Modifiers
      /**
       * Clears this  to its blank/initial state
       *
       * @author Rod Leonard
       * @date 4/2/2020
       **/
      void clear();
      /**
       * Sets a column
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @param  index  Zero-based index of the.
       * @param  column The column.
       **/
      void setColumn(size_t index, const Vector& column);
      #pragma endregion

      #pragma region Observers
      /**
       * Gets row size
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @returns The row size.
       **/
      size_t getRowSize() const;
      /**
       * Gets column size
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @returns The column size.
       **/
      size_t getColumnSize() const;
      /**
       * Gets a column
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @param  index Zero-based index of the.
       *
       * @returns The column.
       **/
      Vector getColumn(size_t index) const;
      /**
       * Gets the inverse
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @returns The inverse.
       **/
      Matrix getInverse() const;
      #pragma endregion

      #pragma region Operators
      #pragma region Modifiers
      /**
       * Array indexer operator
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @param  index Zero-based index of the.
       *
       * @returns The indexed value.
       **/
      Vector& operator[](size_t index);
      /**
       * Assignment operator
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @param  rhs The right hand side.
       *
       * @returns A shallow copy of this.
       **/
      Matrix& operator=(const Matrix& rhs);
      #pragma endregion

      #pragma region Observers
      /**
       * Array indexer operator
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @param  index Zero-based index of the.
       *
       * @returns The indexed value.
       **/
      const Vector operator[](size_t index) const;
      /**
       * Addition operator
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @param  rhs The right hand side.
       *
       * @returns The result of the operation.
       **/
      Matrix operator+(const Matrix& rhs) const;
      /**
       * Multiplication operator
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @param  rhs The right hand side.
       *
       * @returns The result of the operation.
       **/
      Vector operator*(const Vector& rhs) const;
      /**
       * Multiplication operator
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @param  rhs The right hand side.
       *
       * @returns The result of the operation.
       **/
      Matrix operator*(const Matrix& rhs) const;
      #pragma endregion
      #pragma endregion

    private:
      #pragma region Variables
      /** Size of the row */
      size_t _rowSize;
      /** Size of the column */
      size_t _columnSize;
      /** The rows */
      Vector* _rows;
      #pragma endregion

      #pragma region Observers
      /**
       * Decompose lu
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @param [in,out] L A Matrix to process.
       * @param [in,out] U A Matrix to process.
       **/
      void decomposeLU(Matrix& L, Matrix& U) const;
      #pragma endregion
    };
  }
}