/*
* DETAILS
* -------
* c-source-scanner is written for these purposes:
* 1) To understand how to scan a program's source code file.
* 2) To understand how to use a scanner generator to 'generate' a
* source code generator.
* 3) To understand how to use finite automata concept via defining regular
* expressions to match the lexeme of the code and output the tokens.
*
* c-source-scanner is NOT written for these purposes (at-least-for-now):
* 1) To provide a 'full' scanner program for C language.
* 2) To construct a symbol table for future enhancements of building a
* real compiler.
*
* NOTES
* -----
* 1) scanner.l follows up the c naming conventions:
* http://www.cprogramming.com/tutorial/style_naming_conventions.html
* 2) Constant ID of the ASCII characters are same with their ASCII codes.
* 3) Regex for comments based on:
* http://ostermiller.org/findcomment.html
* 4) O'Reilly's Flex&Bison book is a very good resource, if you want to
* know more about flex and bison.
============================================================================
*/

/* we do not need flex library */
%option noyywrap

/* ----- DEFINITIONS PART ----- */
/* ============================ */

/* DEFINITIONS FOR TOKEN CODES */
/* --------------------------- */

/* ' The literal block %{ ... %} ' in this part is copied to verbatim to the generated
C source file near the beginning, before the beginning of yylex() */
%{
#define PLUS "+"
#define MINUS "-"
#define MULT "*"
#define DIV "/"
#define PERCENT "%"
#define LAND "&&"
#define LOR "||"
#define LNOT "!"
#define LESSTHAN "<"
#define GREATERTHAN ">"
#define LTEQUAL ">="
#define GTEQUAL "<="
#define EQUAL "=="
#define NOTEQUAL "!="
#define BITAND "&"
#define BITOR "|" 
#define BITXOR "^"
#define LPARA "("
#define RPARA ")"
#define LBRACKET "["
#define RBRACKET "]"
#define LCURLY "{"
#define RCURLY "}"
#define COMMA ","
#define SEMICOLON ";"
#define ASSIGN "="
#define CHARSYM "char"
#define INTSYM "int"
#define VOIDSYM "void"
#define IFSYM "if"
#define ELSESYM "else"
#define WHILESYM "while"
#define FORSYM "for"
#define CONTINUESYM "continue"
#define BREAKSYM "break"
#define RETURNSYM "return"
#define IDENTIFIER 258
#define INTEGER 259
#define STRING 260
#define DELIMITER 261
#define COMMENT 262

/* Function : dec_to_hex
* Description : Decimal to Hexadecimal Converter
* The function takes a char pointer (which is flex's yytext) and using
* format place holder tecnique to do the convertion. Additionally it
* manipulates the string to construct the 32-bit representation of the
* hexadecimal number (e.g. 0x7fffffff).
*/
const char* dec_to_hex(const char* number) {
char *temp;
char *buffer;
int len, i;

temp = malloc(sizeof(char) * 11);
buffer = malloc(sizeof(char) * 8);
sprintf(buffer, "%x", atoi(number));
sprintf(temp, "0x");
len = strlen(buffer);

for (i=2; i<10-len; i++)
temp[i] = '0';

strncat(temp, buffer, len);
return temp;
free(buffer);
free(temp);
}

/* Function : clean_str
* Description : Remove leading/tailing double quotes of string
* The function takes a char pointer (which is flex's yytext) and using
* strncpy function to copy it to the temp array starting from the 1st
* index of 'str' and ignoring the tailing double quote with exchanging
* it a null-character.
*/
const char* clean_str(const char* str) {
char *temp;
int len;
len = strlen(str);
temp = malloc(sizeof(char) * (len-1));
strncpy(temp, (++str), len-1);
temp[len-2] = '\0';
return temp;
free(temp);
}

%}

/* DEFINITIONS FOR FINITE AUTOMATA */
/* ------------------------------- */

/* Universal Character Name: the naming conventions for UCS defined by International Standard ISO/IEC 10646 */
UCN (\\u[0-9a-fA-F]{4}|\\U[0-9a-fA-F]{8})

/* DIGIT: any number from 0 to 9 */
DIGIT [0-9]

/* LETTER: any uppercase or lowercase letter */
LETTER [A-Za-z]

/* DELIMITER: any occurence of 'space', 'tab' or 'newline' */
DELIMITER [ \t\n]

/* IDENTIFIER: starting with a letter; following by any occurence of letter, digit or underscore */
IDENTIFIER ([_a-zA-Z]|{UCN})([_a-zA-Z0-9]|{UCN})*

/* INTEGER: 0 or more occurence of consecutive digits */
INTEGER 0|([1-9][0-9]*)

/* STRING: anything between double quote; just considers \" and \\ characters */
STRING L?\"([^"\\]|\\['"?\\abfnrtv]|\\[0-7]{1,3}|\\[Xx][0-9a-fA-F]+|{UCN})*\"

/* COMMENT: any c style comment */
COMMENT ("/*"([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*"*"+"/")|("//".*)


%%
 /* ----- RULES PART ----- */
 /* ====================== */

 /* RULES FOR OPERATORS AND PUNCTUATIONS */
 /* ------------------------------------ */
"+" { printf("%s\n", PLUS); }
"-" { printf("%s\n", MINUS); }
"*" { printf("%s\n", MULT); }
"/" { printf("%s\n", DIV); }
"%" { printf("%s\n", PERCENT); }
"&&" { printf("%s\n", LAND); }
"||" { printf("%s\n", LOR); }
"!" { printf("%s\n", LNOT); }
"<" { printf("%s\n", LESSTHAN); }
">" { printf("%s\n", GREATERTHAN); }
"<=" { printf("%s\n", LTEQUAL); }
">=" { printf("%s\n", GTEQUAL); }
"==" { printf("%s\n", EQUAL); }
"!=" { printf("%s\n", NOTEQUAL); }
"&" { printf("%s\n", BITAND); }
"|" { printf("%s\n", BITOR); }
"^" { printf("%s\n", BITXOR); }
"(" { printf("%s\n", LPARA); }
")" { printf("%s\n", RPARA); }
"[" { printf("%s\n", LBRACKET); }
"]" { printf("%s\n", RBRACKET); }
"{" { printf("%s\n", LCURLY); }
"}" { printf("%s\n", RCURLY); }
"," { printf("%s\n", COMMA); }
";" { printf("%s\n", SEMICOLON); }
"=" { printf("%s\n", ASSIGN); }

 /* RULES FOR KEYWORDS */
 /* ------------------ */
"char" { printf("%s\n", CHARSYM); }
"int" { printf("%s\n", INTSYM); }
"void" { printf("%s\n", VOIDSYM); }
"if" { printf("%s\n", IFSYM); }
"else" { printf("%s\n", ELSESYM); }
"while" { printf("%s\n", WHILESYM); }
"for" { printf("%s\n", FORSYM); }
"continue" { printf("%s\n", CONTINUESYM); }
"break" { printf("%s\n", BREAKSYM); }
"return" { printf("%s\n", RETURNSYM); }

 /* RULES FOR IDENTIFIIERS */
 /* ---------------------- */
{IDENTIFIER} { printf("%s\n", yytext); }

 /* RULES FOR LITERALS */
 /* ------------------ */
{INTEGER} { printf("%s\n",yytext); }
{STRING} { printf("%s\n",yytext); }

{DELIMITER} { printf("%c\n", DELIMITER); }

 /* ignore any kind of comments; i.e. no 'action'! */
 /* {COMMENT} { printf("%s\n", COMMENT) ; } */

%%
/* ----- USER CODE PART ----- */
/* ========================== */
main(argc, argv)
int argc;
char **argv;
{
YY_BUFFER_STATE bp;
extern FILE* yyin;

if (argc>1) {
yyin = fopen(argv[1],"r");
} else {
yyin = stdin;
bp = yy_create_buffer(yyin, YY_BUF_SIZE); // YY_BUF_SIZE defined by flex, typically 16K=16384
yy_switch_to_buffer(bp); // tell it to use the buffer we just made
}
yylex();
}