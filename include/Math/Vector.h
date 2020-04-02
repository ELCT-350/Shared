/**
 * @file C:\Users\leona\source\repos\Shared\include\Math\Vector.h.
 *
 * Declares the vector class
 **/

#pragma once

/** . */
namespace ELCT350
{
/** . */
  namespace Math
  {
    /**
     * A vector. This class cannot be inherited..
     *
     * @author Rod Leonard
     * @date 4/2/2020
     **/
    class Vector final
    {
    public:
      #pragma region Constructors and Destructors
      /**
       * Constructor
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @param  vectorSize (Optional) Size of the vector.
       **/
      Vector(size_t vectorSize = 0);
      /**
       * Constructor
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @param  original The original.
       **/
      Vector(const Vector& original);
      /**
       * Constructor
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @param [in,out] old The old.
       **/
      Vector(Vector&& old) noexcept;
      /**
       * Destructor
       *
       * @author Rod Leonard
       * @date 4/2/2020
       **/
      ~Vector();
      #pragma endregion

      #pragma region Modifiers
      /**
       * Clears this  to its blank/initial state
       *
       * @author Rod Leonard
       * @date 4/2/2020
       **/
      void clear();
      #pragma endregion

      #pragma region Observers
      /**
       * Gets the size
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @returns The size.
       **/
      size_t getSize() const;
      #pragma endregion

      #pragma region Operators
      #pragma region Modifers
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
      double& operator[](size_t index);
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
      Vector& operator=(const Vector& rhs);
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
      double operator[](size_t index) const;
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
      Vector operator+(const Vector& rhs) const;
      /**
       * Subtraction operator
       *
       * @author Rod Leonard
       * @date 4/2/2020
       *
       * @param  rhs The right hand side.
       *
       * @returns The result of the operation.
       **/
      Vector operator-(const Vector& rhs) const;
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
      double operator*(const Vector& rhs) const;
      #pragma endregion
      #pragma endregion
    private:
      #pragma region Variables
      /** The size */
      size_t _size;
      /** The values */
      double* _values;
      #pragma endregion
    };
  }
}