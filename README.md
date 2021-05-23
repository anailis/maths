## maths

In this directory, I implement the mathematical concepts that I learn in code. These are divided into small, distinct tasks. 

To build the project: 
```
make
```

To execute the program:
```
./mathsml
```

### Linear Algebra

#### Task 1: Vectors and Matrices

**Aim:** to implement a class `Matrix` which stores vectors and matrices. 
**Status:**
**Outcome:**

#### Task 2: Addition, Subtraction, and Products

**Aim:** to implement matrix and vector addition; subtraction; multiplication by scalars, vectors, matrices; Hadamard product member functions for class `Matrix`
**Tests:**
- Correct output of addiction, subtraction, and products
- Appropriate error messages for incorrect dimensions
**Status:**
**Outcome:**

#### Task 3: Identity Matrix

**Aim:** create a new constructor for the `Matrix` class that returns an identity matrix
**Tests:**
- Correct use of the constructor returns an identity matrix
- Use of other constructors does not default to the identity matrix 
- All task 2 methods for the `Matrix` class work with the identity matrix and give the correct outcomes

#### Task 4: Inverse and Transpose

**Aim:** to implement tranpose and matrix inverse member functions for class `Matrix`
**Tests:**
- Correct inverse and transpose outputs
- Error when asking for inverse of any vector or a non-invertible matrix 
