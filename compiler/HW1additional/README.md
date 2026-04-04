# Compiler Homework 1: Scanner
by: B123245006陳展皝

## System info:
Lex version: flex 2.6.4
Operating Platform: macOS 26.4

## Executing Method:
Install flex:
- macOS: brew install flex
- Linux: sudo apt-get install flex
Compile:
- macOS: make mac
- Linux: make
Run:
- ./scanner < TEST_FILE.java

## Handle Issues in this specification:
1. Handling comments: Comment handling is first priority, as comments can contain characters that may be mistaken for tokens. Comments are handled by detecting "//" for single-line comments, which are ignored until the end of the line, and "/\*" for multi-line comments, enters a separate comment state until reach "\*/". This ensures that any text within comments is not processed as code.
2. Handling whitespace and newlines: Whitespace characters (spaces, tabs) and newlines are ignored, but they are used to track the line number and character position for accurate reporting of token locations.
3. Handling symbols/operators: Pattern matching are used for symbols and operators.
4. Handling reserved words: Reserved words are handled by maintaining a list of reserved words. Notable that reserved words are also identifiers, so higher priority is given to prevent misclassification.
5. Handling identifiers: Identifiers are defined by a regular expression that allows for letters, digits, underscores, and dollar signs, but must start with a letter, underscore, or dollar sign.
6. Handling integer/float/string constants: Integer constants are defined as a sequence of digits, optionally preceded by a plus or minus sign. Float constants are defined as a sequence of digits with a decimal point, optionally preceded by a plus or minus sign, and may include an exponent part. String constants are defined as text enclosed in double quotes, allowing for escaped characters.
7. Handling invalid tokens: Any sequence of characters that does not match the patterns for valid tokens is classified as an invalid token and reported accordingly.
8. AI and internet is used to help understanding the specification and providing suggestions for implementation

## Problems encountered while writing this assignment:
 1. "\r" was not considered in the original code, which caused issues when handling comments on Windows or files with different newline conventions. This was resolved by updating the regular expression for single-line comments to account for both "\n" and "\r\n".

## Results of executing all of test files:
![screenshot](/compiler/HW1/screenshot.png)
