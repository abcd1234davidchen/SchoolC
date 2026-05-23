# Compiler Homework 2: Parser
by: B123245006陳展皝

## System info:
Lex version: flex 2.6.4
Yacc version: bison (GNU Bison) 2.3
Operating Platform: macOS 26.5

## Executing Method:
Install:
- macOS: brew install flex
- Linux: sudo apt-get install flex bison
Compile:
- macOS: make mac
- Linux: make
Run:
- ./scanner < TEST_FILE.java

## Handle Issues in this specification:
1. New .l file was modified from the previous homework to work with the new .y file.
2. The scope and symbol table management was implemented to handle variable declarations and references, including nested scopes and unused variable warnings. This involved creating a stack of Scope structs to represent the current scope and its parent scopes, and a linked list of Symbol structs to represent the identifiers declared in each scope. The parser was modified to call the appropriate functions for managing the symbol table when entering and leaving scopes, declaring identifiers, and marking identifiers as used when they are referenced in the code.
3. Classes are implemented with fields and methods. The parser can handle class declarations, including the syntax for declaring fields and methods, and manage the symbol table for class members. The fields are treated as variables declared in the class scope. The parser also handles the syntax for method declarations, including the parameter list and method body, and manages the symbol table for method parameters and local variables.
4. Field declarations include variable declarations with optional initializers. The parser can handle the syntax for field declarations, including the optional initializer, and manage the symbol table for class fields. When a field is declared, it is added to the symbol table for the class scope, and if it has an initializer, the parser processes the initializer expression to mark any identifiers used in it as referenced.
5. Method declarations include parameters and a method body. The body can contain variable declarations and statements. The parser can handle the syntax for method declarations, including the parameter list and method body, and manage the symbol table for method parameters and local variables. The parser also handles the syntax for statements within the method body, such as variable declarations, assignments, and control flow statements.
6. Statements include variable declarations, assignments, and control flow statements. The parser can handle the syntax for these statements and manage the symbol table accordingly. Variable declarations are processed to add identifiers to the symbol table, while assignments and control flow statements are processed to mark identifiers as used when they are referenced in the code.
7. Expressions include literals, identifiers, and method invocations. The parser can handle the syntax for these expressions and manage the symbol table accordingly. Literals are processed as constant values, while identifiers are processed to mark them as used when they are referenced in expressions. Method invocations are parsed through the name and argument list rules, and any identifiers used inside them are marked as referenced.
8. Errors are reported for redeclarations of identifiers in the same scope, unused variable warnings, and general syntax errors. The parser checks for these errors when processing declarations and references, and prints appropriate error messages when they are detected. Redeclarations are reported when an identifier is declared more than once in the same scope, while unused variable warnings are reported for variables that are declared but never referenced in the code.
9. AI and internet is used to help understanding the specification and providing suggestions for implementation

## Problems encountered while writing this assignment:
1. Handling error was tricky, especially for syntax errors and redeclarations. I had to carefully check the conditions ensure proper error reporting.
2. yyerror and yyerrok were used to handle syntax errors in if and for statements. I had to make sure to call yyerrok after reporting the error to prevent cascading errors.
3. yacc shows shift/reduce conflicts for multiple statements. I had to use precedence rules to resolve these conflicts and ensure the correct parsing of statements.

## Results of executing all of test files:
![screenshot](/compiler/HW2/screenshot.png)
