/**********************************************************
 * This file is generated by 20-sim ANSI-C Code Generator
 *
 *  file:  xxmatrix.h
 *  model: 8RT-FLEX68-D_transient
 *  expmt: 8RT-FLEX68-D_transient
 *  date:  August 19, 2014
 *  time:  1:35:00 pm
 *  user:  Norwegian University of Science and Technology 
 *  from:  20-sim 4.4 Student License
 *  build: 4.4.1.4356
 **********************************************************/

/* This file describes the declaration of the matrix structure
   and functions used in generated 20-sim ANSI-C code.
   All the generated code uses these typedefs to enhance
   flexibility (in case the compiler is not Visual C++ 6 or the destination
   platform is not Windows 2000 on a Pentium III).
*/

#ifndef XX_MATRIX_H
#define XX_MATRIX_H

/* 20-sim include files */
#include "xxtypes.h"

/* The matrix declaration */
typedef struct
{
	XXDouble *mat;
	XXInteger rows;
	XXInteger columns;
} XXMatrix;

/* fill in a matrix struct with a given array, rows and columns */
void XXCreateMatrixStruct (XXMatrix *mat_dest, XXInteger rows, XXInteger columns, XXDouble *values);

/* allocate a matrix struct with rows and columns
void XXAllocateMatrixStruct (XXMatrix *mat_dest, XXInteger rows, XXInteger columns);

   free a matrix struct with rows and columns
void XXFreeMatrixStruct (XXMatrix *mat_dest);
*/

/* and the function declarations */
/* copy a matrix source to a matrix destination */
void XXMatrixMov (XXMatrix *mat_dest, XXMatrix *mat_source);

/* copy a scalar to every element in a matrix destination */
void XXMatrixScalarMov (XXMatrix *mat_dest, XXDouble s);

/* get the row(zero_based) designated by the integer
   from the source to the destination. destination is vector */
void XXMatrixGetRow (XXMatrix *mat_dest, XXMatrix *mat_source, XXInteger row);

/* set the row(zero_based) designated by the integer
   to the destination from the source. source is vector*/
void XXMatrixSetRow (XXMatrix *mat_dest, XXMatrix *mat_source, XXInteger row);

/* get the column(zero_based) designated by the integer
   from the source to the destination. destination is vector */
void XXMatrixGetColumn (XXMatrix *mat_dest, XXMatrix *mat_source, XXInteger column);

/* set the column(zero_based) designated by the integer
   to the destination from the source. source is vector */
void XXMatrixSetColumn (XXMatrix *mat_dest, XXMatrix *mat_source, XXInteger column);

/* use the source vector as elements of the diagonal in the
   destination matrix */
void XXMatrixDiag (XXMatrix *mat_dest, XXMatrix *mat_source);

/* add a matrix source1 to a matrix source2 to a matrix destination */
void XXMatrixAdd (XXMatrix *mat_dest, XXMatrix *mat_source1, XXMatrix *mat_source2);

/* add a matrix source1 to a scalar source2 to a matrix destination */
void XXMatrixScalarAdd (XXMatrix *mat_dest, XXMatrix *mat_source1, XXDouble s2);

/* add a scalar source1 to a matrix source2 to a matrix destination */
void XXScalarMatrixAdd (XXMatrix *mat_dest, XXDouble s1, XXMatrix *mat_source2);

/* add a scalar source1 to a scalar source2 to a matrix destination */
void XXScalarScalarAdd (XXMatrix *mat_dest, XXDouble s1, XXDouble s2);

/* subtract a Matrix source2 from a matrix source1 to a matrix destination */
void XXMatrixSub (XXMatrix *mat_dest, XXMatrix *mat_source1, XXMatrix *mat_source2);

/* subtract a scalar source2 from a matrix source1 to a matrix destination */
void XXMatrixScalarSub (XXMatrix *mat_dest, XXMatrix *mat_source1, XXDouble s2);

/* subtract a matrix source2 from a scalar source1 to a matrix destination */
void XXScalarMatrixSub (XXMatrix *mat_dest, XXDouble s1, XXMatrix *mat_source2);

/* subtract a scalar source2 from a scalar source1 to a matrix destination */
void XXScalarScalarSub (XXMatrix *mat_dest, XXDouble s1, XXDouble s2);

/* multiply matrix source1 and matrix source2 to destination matrix */
void XXMatrixMul (XXMatrix *mat_dest, XXMatrix *mat_source1, XXMatrix *mat_source2);

/* multiply matrix source1 with scalar source2 to matrix destination */
void XXMatrixScalarMul (XXMatrix *mat_dest, XXMatrix *mat_source1, XXDouble s2);

/* multiply scalar source1 with matrix source2 to matrix destination */
void XXScalarMatrixMul (XXMatrix *mat_dest, XXDouble s1, XXMatrix *mat_source2);

/* multiply scalar source1 with scalar source2 to matrix destination */
void XXScalarScalarMul(XXMatrix *mat_dest, XXDouble s1, XXDouble s2);

/* multiply matrix source1 with matrix source2 to scalar destination
   the sizes are not checked but it should be that rows of source1 == 1 and columns source2 == 1*/
void XXScalarMatrixMatrixMul (XXDouble *dest, XXMatrix *mat_source1, XXMatrix *mat_source2);

/* multiply all elements element-wise to the destination */
void XXMatrixMulElement (XXMatrix *mat_dest, XXMatrix *mat_source1, XXMatrix *mat_source2);

/* divide all elements element-wise to the destination */
void XXMatrixDivElement (XXMatrix *mat_dest, XXMatrix *mat_source1, XXMatrix *mat_source2);

/* pow all elements element-wise to the destination */
void XXMatrixAddElement (XXMatrix *mat_dest, XXMatrix *mat_source1, XXMatrix *mat_source2);

/* take the inverse of a matrix source to a matrix destination
   workarray size at least (3 * n * n + 2 * n)
   with n is rows is columns from source (=equal to destination) */
void XXMatrixInverse (XXMatrix *mat_dest, XXMatrix *mat_source, XXDouble *workarray);

/* divide matrix source1 with matrix source2 to matrix destination
   workarray size at least (4 * n * n + 2 * n)
   with n is rows is columns from source2 */
void XXMatrixDiv (XXMatrix *mat_dest, XXMatrix *mat_source1, XXMatrix *mat_source2, XXDouble *workarray);

/* divide matrix source1 with scalar source2 to matrix destination */
void XXMatrixScalarDiv (XXMatrix *mat_dest, XXMatrix *mat_source1, XXDouble s2);

/* divide scalar source1 with matrix source2 to matrix destination
   workarray size at least (3 * n * n + 2 * n)
   with n is rows is columns from source2 (=equal to destination) */
void XXScalarMatrixDiv (XXMatrix *mat_dest, XXDouble s1, XXMatrix *mat_source2, XXDouble *workarray);

/* divide scalar source1 with scalar source2 to matrix destination */
void XXScalarScalarDiv (XXMatrix *mat_dest, XXDouble s1, XXDouble s2);

/* take the negative value of the matrix source to the the matrix destination */
void XXMatrixInv (XXMatrix *mat_dest, XXMatrix *mat_source);

/* take the transpose of the matrix source to the the matrix destination */
void XXMatrixTranspose (XXMatrix *mat_dest, XXMatrix *mat_source);

/* take the determinant of the matrix source and put it in the scalar destination */
XXDouble XXMatrixDeterminant (XXMatrix *mat_source, XXDouble *workarray);

/* use the source1 as an integer index for the destination
   and copy the scalar value of source2 at this point */
void XXMatrixMovRelAbs (XXMatrix *mat_dest, XXDouble s1, XXDouble s2);

/* use the source2 as an integer index for the source1
   and copy this value of source1 to the scalar destination */
void XXMatrixMovAbsRel (XXDouble *dest, XXMatrix *mat_source1, XXDouble s2);

/* find the minimum value in a matrix source and place this in
   the destination */
void XXMatrixMinimum (XXDouble *dest, XXMatrix *mat_source);

/* find the maximum value in a matrix source and place this in
   the destination */
void XXMatrixMaximum (XXDouble *dest, XXMatrix *mat_source);

/* summize all the elements of the matrix and put the result in the dest */
void XXMatrixSum (XXDouble *dest, XXMatrix *mat_source);

/* set the destination to the eye matrix */
void XXMatrixEye (XXMatrix *mat_dest);

/* multiply the source1 n times with itself, with n in source2
   an integer number. The result is put in the destination,
   workarray must have at least the size of the destination matrix
   plus the workarray size of an inverse matrix operation
   this makes 4 * n * n + 2 * n with n = rows/columns of source/dest.
   source and destination should be square */
void XXMatrixPow (XXMatrix *mat_dest, XXMatrix *mat_source1,
				XXDouble s2, XXDouble *workarray);
/* and the scalar scalar variant */
void XXScalarScalarPow (XXMatrix *mat_dest, XXDouble s1, XXDouble s2);

/* take the cross product of matrix source1 and matrix source2
   to a destination matrix. all matrices must be 3x1 */
void XXMatrixCrossProduct (XXMatrix *mat_dest, XXMatrix *mat_source1, XXMatrix *mat_source2);

/* take the inner product of matrix source1 and matrix source2
   to a scalar destination. the source matrices must be nx1 */
void XXMatrixInnerProduct (XXDouble *dest, XXMatrix *mat_source1, XXMatrix *mat_source2);

/* take the 2-norm of matrix source to a scalar destination */
void XXMatrixNorm (XXDouble *dest, XXMatrix *mat_source);

/* take the inf norm of matrix source to a scalar destination */
void XXMatrixNormInf (XXDouble *dest, XXMatrix *mat_source);

/* take the Trace of the matrix source to the scalar destination.
   The trace is defined as the sum of the diagonal values */
XXDouble XXMatrixTrace (XXMatrix *mat_source);

/* take the symetric value of the source matrix.
   the result is placed in the destination matrix.
   the work array must have the same size as the source */
void XXMatrixSym (XXMatrix *mat_dest, XXMatrix *mat_source, XXDouble *workarray);

/* take the anti symetric value of the source matrix.
   the result is placed in the destination matrix.
   the work array must have the same size as the source */
void XXMatrixAsym (XXMatrix *mat_dest, XXMatrix *mat_source, XXDouble *workarray);

/* take the skew of the source matrix to a matrix destination
   source = 3x1, destination is 3x3 */
void XXMatrixSkew (XXMatrix *mat_dest, XXMatrix *mat_source);

/* take the skew of the source1 matrix and source2 matrix
   to a matrix destination.
   source1 is 3x3 and source2 = 3x1, destination is 4x4 */
void XXMatrixHomogeneous (XXMatrix *mat_dest, XXMatrix *mat_source1, XXMatrix *mat_source2);

/* take the inverse of a sourceH matrix to a destination matrix
   the source is 4x4 and the destination matrix is 4x4 */
void XXMatrixInverseH (XXMatrix *mat_dest, XXMatrix *mat_source);

/* Create an Adjoint matrix.
   source matrix is 4x4, destination matrix is 6x6 */
void XXMatrixAdjoint (XXMatrix *mat_dest, XXMatrix *mat_source);

/* Create an Adjoint matrix from two source matrices
   source1 matrix is 3x3 (orientation),
   source2 matrix is 3x1 (position),
   destination matrix is 6x6 */
void XXMatrixAdjoint1 (XXMatrix *mat_dest, XXMatrix *mat_source1, XXMatrix *mat_source2);

/* Create an Adjoint matrix from a source matrix
   source1 matrix is 6x1
   destination matrix is 6x6 */
void XXMatrixadjoint (XXMatrix *mat_dest, XXMatrix *mat_source);

/* Create an adjoint matrix from two source matrices
   source1 matrix is 3x1
   source2 matrix is 3x1
   destination matrix is 6x6 */
void XXMatrixadjoint1 (XXMatrix *mat_dest, XXMatrix *mat_source1, XXMatrix *mat_source2);

/* calcalate the tilde matrix from a source matrix
   source1 matrix is 6x1
   destination matrix is 4x4 */
void XXMatrixTilde (XXMatrix *mat_dest, XXMatrix *mat_source);

/* calcalate the tilde matrix from two source matrices
   source1 matrix is 3x1
   source2 matrix is 3x1
   destination matrix is 4x4 */
void XXMatrixTilde1 (XXMatrix *mat_dest, XXMatrix *mat_source1, XXMatrix *mat_source2);

/* calculate the solution of Ax=b towards x 
   inside 20-sim this is done with an advanced linear solver
   code generation uses the x=inverse(A)*b approach instead */
void XXLinearSolve (XXMatrix *mat_dest, XXMatrix *mat_source1, XXMatrix *mat_source2, XXString method, XXInteger id, XXDouble *workarray);

#endif /* XX_MATRIX_H */


