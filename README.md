## maths

In this directory, I implement the mathematical concepts that I learn in code. 

To build the project, execute make: 
```
make
```

To execute the program:
```
./bin/maths
```

Documentation can be found in the GitHub wiki. 

The project was developed in a VSCode Docker development container. 

Unit testing was performed using the googletest framework. 
You can execute the unit tests using: 
```
./tests/tests
```

### Dependencies 

- Make 4.2.1
- Cmake 2.8.12
- C++
- (for testing) [googletest](https://github.com/google/googletest)
- (for dev container) Docker, VSCode

### Linear Algebra

Completed tasks:
- Implement class Matrix 
- Multiplication by scalars and vectors (currently in-place by a method)
- Transpose matrices
- Addition and subtraction (as overloaded operators)

In progress:
- Multiplication by matrices 

To-do:
- Dot product
- Hadamard product
- Identity matrix construction
- Symmetry 
- Inverse
- Reassign specific elements of matrix
