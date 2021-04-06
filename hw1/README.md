
## Problem Statement 

### Part 1 
The position of a robotic arm is determined by an angle that can only take values between `-60` degreesand `+120` degrees (included). In this homework, you will create a C++ class Angle that represents the angle of the robotic arm. The implementation should enforce the limits on the range of allowed values. The angle can only take integer values. Any attempt to change the angle beyond `120` degrees should result in the angle value being `120`. Any attempt to change the angle to a value smaller than `-60` should result in the angle value being `-60`.


### Part 2

Create a simple fraction calculator that can add and subtract anynumber of fractions and writes the answer as a reduced fraction. Your program will read input from stdinand write output on `stdout`. A fraction is represented as the sequence:

```
a/b
```

where `a` and `b` are integers and any amount of white space characters ` ` (including none) can separate `a` from `/` and `/` from `b`.

Input consists of an expression made of fractions separated by the operators '+' or '-'. The number of fractions in the expression is arbitrary. Each of the following 6 lines is an example of valid input expression:

```
1/2 + 3/4
1/2-5/7+3/5
355/113
3      /9-21 /   -7
4/7-5/-8
-2/-3--7 /5
```

Note that the numerator and/or denominator of a fraction given as input may be negative. The input will consist of a single expression on a single line terminated by a `\n` character. The output should consist of a single, irreducible fraction written asc/dwhere cis a signed integer and dis a positive integer (i.e. the denominator cannot be negative in the output). The numbers `c` and `d` should not have any common factors (apart from 1). 