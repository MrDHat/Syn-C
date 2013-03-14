/* 
============================================================================
* Program Name 	: scanner.l
* Author		: #B96902133, Hakki Caner Kirmizi
* Description		: A C source code scanner written with flex.
* Environment		: Windows-7 Entreprise
* Editor		: vim 7.2 for WIN 
* Integration Tests	: linux2.csie.ntu.edu.tw
* Flex			: 2.5.35
* Compiler		: gcc (Debian 4.4.3-3) 4.4.3
* Version Control	: TortoiseSVN 1.6.7, Build 18415 - 32 Bit
* Project Hosting	: http://code.google.com/p/c-source-scanner/
* 
* INSTRUCTIONS
* ------------
* Build		: flex scanner.l
* Compile		: gcc lex.yy.c
* Run			: There are two options...
*  1) a.out [input-filename] // recommended for long source codes
*  2) a.out // hit enter and use stdin; BE AWARE OF BUFFER SIZE!!!
* 
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
/* Included for queue operations */
#include "queue_ops.h"
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
#define AUTOSYM "auto"
#define EXTERNSYM "extern"	
#define FLOATSYM "float"
#define DOUBLESYM "double"
#define SWITCHSYM "switch"
#define CASESYM "case"
#define CONSTSYM "const"
#define DEFAULTSYM "default"
#define LONGSYM "long"			
#define REGISTERSYM "register"
#define SHORTSYM "short"		
#define SIGNEDSYM "signed"
#define STATICSYM "static"
#define UNSIGNEDSYM "unsigned"
#define IFSYM "if"
#define ELSESYM "else"
#define WHILESYM "while"
#define DOSYM "do"
#define FORSYM "for"
#define CONTINUESYM "continue"
#define BREAKSYM "break"
#define RETURNSYM "return"
#define ENUMSYM "enum"		
#define STRUCTSYM "struct"
#define UNIONSYM "union"	
#define GOTOSYM "goto"
#define SIZEOFSYM "sizeof"
#define TYPEDEFSYM "typedef"
#define IDENTIFIER 258
#define INTEGER 259
#define STRING 260
#define DELIMITER 261
#define COMMENT 262

queue_ops queue_obj;
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
"+" { printf("%s\n", PLUS); queue_obj.push_into_queue(PLUS, 1, 1); }
"-" { printf("%s\n", MINUS); queue_obj.push_into_queue(MINUS, 1, 1); }
"*" { printf("%s\n", MULT); queue_obj.push_into_queue(MULT, 1, 1); }
"/" { printf("%s\n", DIV); queue_obj.push_into_queue(DIV, 1, 1); }
"%" { printf("%s\n", PERCENT); queue_obj.push_into_queue(PERCENT, 1, 1); }
"&&" { printf("%s\n", LAND); queue_obj.push_into_queue(LAND, 1, 1); }
"||" { printf("%s\n", LOR); queue_obj.push_into_queue(LOR, 1, 1); }
"!" { printf("%s\n", LNOT); queue_obj.push_into_queue(LNOT, 1, 1); }
"<" { printf("%s\n", LESSTHAN); queue_obj.push_into_queue(LESSTHAN, 1, 1); }
">" { printf("%s\n", GREATERTHAN); queue_obj.push_into_queue(GREATERTHAN, 1, 1); }
"<=" { printf("%s\n", LTEQUAL); queue_obj.push_into_queue(LTEQUAL, 1, 1); }
">=" { printf("%s\n", GTEQUAL); queue_obj.push_into_queue(GTEQUAL, 1, 1); }
"==" { printf("%s\n", EQUAL); queue_obj.push_into_queue(EQUAL, 1, 1); }
"!=" { printf("%s\n", NOTEQUAL); queue_obj.push_into_queue(NOTEQUAL, 1, 1); }
"&" { printf("%s\n", BITAND); queue_obj.push_into_queue(BITAND, 1, 1); }
"|" { printf("%s\n", BITOR); queue_obj.push_into_queue(BITOR, 1, 1); }
"^" { printf("%s\n", BITXOR); queue_obj.push_into_queue(BITXOR, 1, 1); }
"(" { printf("%s\n", LPARA); queue_obj.push_into_queue(LPARA, 1, 1); }
")" { printf("%s\n", RPARA); queue_obj.push_into_queue(RPARA, 1, 1); }
"[" { printf("%s\n", LBRACKET); queue_obj.push_into_queue(LBRACKET, 1, 1); }
"]" { printf("%s\n", RBRACKET); queue_obj.push_into_queue(RBRACKET, 1, 1); }
"{" { printf("%s\n", LCURLY); queue_obj.push_into_queue(LCURLY, 1, 1); }
"}" { printf("%s\n", RCURLY); queue_obj.push_into_queue(RCURLY, 1, 1); }
"," { printf("%s\n", COMMA); queue_obj.push_into_queue(COMMA, 1, 1); }
";" { printf("%s\n", SEMICOLON); queue_obj.push_into_queue(SEMICOLON, 1, 1); }
"=" { printf("%s\n", ASSIGN); queue_obj.push_into_queue(ASSIGN, 1, 1); }

 /* RULES FOR KEYWORDS */
 /* ------------------ */
"char" { printf("%s\n", CHARSYM); queue_obj.push_into_queue(CHARSYM, 1, 1); }
"int" { printf("%s\n", INTSYM); queue_obj.push_into_queue(INTSYM, 1, 1); }
"void" { printf("%s\n", VOIDSYM); queue_obj.push_into_queue(VOIDSYM, 1, 1); }
"if" { printf("%s\n", IFSYM); queue_obj.push_into_queue(IFSYM, 1, 1); }
"else" { printf("%s\n", ELSESYM); queue_obj.push_into_queue(ELSESYM, 1, 1); }
"while" { printf("%s\n", WHILESYM); queue_obj.push_into_queue(WHILESYM, 1, 1); }
"for" { printf("%s\n", FORSYM); queue_obj.push_into_queue(FORSYM, 1, 1); }
"continue" { printf("%s\n", CONTINUESYM); queue_obj.push_into_queue(CONTINUESYM, 1, 1); }
"break" { printf("%s\n", BREAKSYM); queue_obj.push_into_queue(BREAKSYM, 1, 1); }
"return" { printf("%s\n", RETURNSYM); queue_obj.push_into_queue(RETURNSYM, 1, 1); }
"auto" { printf("%s\n", AUTOSYM); queue_obj.push_into_queue(AUTOSYM, 1, 1); }
"extern" { printf("%s\n", EXTERNSYM); queue_obj.push_into_queue(EXTERNSYM, 1, 1); }	
"float" { printf("%s\n", FLOATSYM); queue_obj.push_into_queue(FLOATSYM, 1, 1); }
"double" { printf("%s\n", DOUBLESYM); queue_obj.push_into_queue(DOUBLESYM, 1, 1); }
"switch" { printf("%s\n", SWITCHSYM); queue_obj.push_into_queue(SWITCHSYM, 1, 1); }
"case" { printf("%s\n", CASESYM); queue_obj.push_into_queue(CASESYM, 1, 1); }
"const" { printf("%s\n", CONSTSYM); queue_obj.push_into_queue(CONSTSYM, 1, 1); }
"default" { printf("%s\n", DEFAULTSYM); queue_obj.push_into_queue(DEFAULTSYM, 1, 1); }
"long" { printf("%s\n", LONGSYM); queue_obj.push_into_queue(LONGSYM, 1, 1); }
"register" { printf("%s\n", REGISTERSYM); queue_obj.push_into_queue(REGISTERSYM, 1, 1); }
"short" { printf("%s\n", SHORTSYM); queue_obj.push_into_queue(SHORTSYM, 1, 1); }
"signed" { printf("%s\n", SIGNEDSYM); queue_obj.push_into_queue(SIGNEDSYM, 1, 1); }
"static" { printf("%s\n", STATICSYM); queue_obj.push_into_queue(STATICSYM, 1, 1); }
"unsigned" { printf("%s\n", UNSIGNEDSYM); queue_obj.push_into_queue(UNSIGNEDSYM, 1, 1); }
"do" { printf("%s\n", DOSYM); queue_obj.push_into_queue(DOSYM, 1, 1); }
"enum" { printf("%s\n", ENUMSYM); queue_obj.push_into_queue(ENUMSYM, 1, 1); }
"struct" { printf("%s\n", STRUCTSYM); queue_obj.push_into_queue(STRUCTSYM, 1, 1); }
"union"	{ printf("%s\n", UNIONSYM); queue_obj.push_into_queue(UNIONSYM, 1, 1); }
"goto" { printf("%s\n", GOTOSYM); queue_obj.push_into_queue(GOTOSYM, 1, 1); }
"sizeof" { printf("%s\n", SIZEOFSYM); queue_obj.push_into_queue(SIZEOFSYM, 1, 1); }
"typedef" { printf("%s\n", TYPEDEFSYM); queue_obj.push_into_queue(TYPEDEFSYM, 1, 1); }

 /* RULES FOR IDENTIFIIERS */
 /* ---------------------- */
{IDENTIFIER} { printf("%s\n", yytext); queue_obj.push_into_queue(yytext, 1, 2); }

 /* RULES FOR LITERALS */
 /* ------------------ */
{INTEGER} { printf("%s\n",yytext); queue_obj.push_into_queue(yytext, 1, 1); }
{STRING} { printf("%s\n",yytext); queue_obj.push_into_queue(yytext, 1, 1); }

{DELIMITER} { printf("%c\n", DELIMITER); queue_obj.push_into_queue(DELIMITER, 1, 1); }

 /* ignore any kind of comments; i.e. no 'action'! */
 /* {COMMENT} { printf("%s\n", COMMENT) ; queue_obj.push_into_queue(COMMENT, 1, 1); } */

%%
/* ----- USER CODE PART ----- */
/* ========================== */

main(int argc, char **argv)
//int argc;
//char **argv;
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
