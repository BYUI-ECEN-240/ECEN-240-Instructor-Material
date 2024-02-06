### Using Laws and Theorems to Simplify an Equation

# Lab 3 Helps

Lab 3 requires the use of at least two of the theorems on the "Laws and
Theorems of Boolean Algebra" sheet to simplify one of the signals. Here
is a quick example of how so solve a similar problem:

Example: Simplify F = AB'C + A'B'C + A'BC

The first task is to identify any two of the product terms that only
have one variable different. For example, AB'C is only one variable
different that A'B'C (the A, A' is different).

Alternatively, we can identify that A'B'C is only one variable different
than A'BC (the B',B). Which one of these should we pick to simplify? Why
not use both of these?

F = AB'C + <span style="color:#00C61A">A'B'C</span> + A'BC

= AB'C + <span style="color:#00C61A">A'B'C</span> + <span style="color:#00C61A">A'B'C</span> + A'BC <span style="color:#00C61A">Theorem 3</span>

= (AB'C + A'B'C) + (A'B'C + A'BC) Theorem 7

= B'C(A + A') + A'C(B' + B) Theorem 8

= B'C(1) + A'C(1) Theorem 5

= B'C + A'C Theorem 1D

Theorem 10 is the "shortcut' combination of theorems 7, 8, 5, and 1D. We
could simply apply theorems 3 and 10 to simplify this expression.
