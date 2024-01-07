![image](https://github.com/Najeebullah3124/Truth-Table-Generator-/assets/147226547/a0393adb-3a89-4847-80d7-9a8e781e5a07)
Purpose:
The program evaluates logical expressions in infix notation and generates their truth tables.

Libraries Used:
iostream: Input/output streams.
string: String handling.
math.h: Mathematical functions.
conio.h: Console input/output functions.
iomanip: Input/output manipulation.
Structures and Classes:
variable: Structure holding a string and an integer array.
Node: Class defining a node for a stack.
Stack: Class implementing a stack for characters.
StringNode: Structure for a node in a string stack.
StringStack: Class implementing a stack for strings.
Functions:
AND_operation, OR_operation, NOT_operation, Implies_operation, XOR_operation, BIconditional_operation: Functions performing logical operations on variables.
getPrecedence: Determines the precedence of operators.
isbalanced: Checks if the brackets in the expression are balanced.
infixToPostfix: Converts an infix expression to postfix notation.
count_variable, count_operations: Counts the number of variables and operations in the expression.
initializeVariables: Initializes variables based on the input expression.
calculate: Evaluates the postfix expression.
main: Main function handling user input, expression evaluation, and truth table generation.
Usage Instructions:
Explain how to enter logical expressions using specific symbols for different operations.
Describe the console output format showing the truth table.
Additional Notes:
Consider explaining edge cases and limitations of the program.
Add comments within the code to clarify complex logic or functions.
