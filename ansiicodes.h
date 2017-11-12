/* 
 * File:   ansiicodes.h
 * Author: Brian Fraser
 *
 * Contains the ANSII codes which change the font colour and style.
 * Usage:
 * 
 *   1: Copy this file into the same folder as your project. 
 * 
 *   2: Include this file into your C++ file:
 *      #include "ansiicodes.h"
 * 
 *   3: Use the ANSII_... constants defined below in cout statements, such as:
 *      cout << "Hello " << ANSII_RED << "world" << ANSII_NORMAL << "!\n";
 *      cout << ANSII_BOLD << ANSII_GREEN << "test" << ANSII_NORMAL << endl;
 */

#ifndef ANSIICODES_H
#define	ANSIICODES_H

using namespace std;
#include <string>


// ANSII screen colour codes
// Source: http://en.wikipedia.org/wiki/ANSI_escape_code
const string ANSII_NORMAL  = "\033[0m";

const string ANSII_BLACK   = "\033[30m";
const string ANSII_RED     = "\033[31m";
const string ANSII_GREEN   = "\033[32m";
const string ANSII_YELLOW  = "\033[33m";
const string ANSII_BLUE    = "\033[34m";
const string ANSII_MAGENTA = "\033[35m";
const string ANSII_CYAN    = "\033[36m";
const string ANSII_WHITE   = "\033[37m";

const string ANSII_BACKGROUND_BLACK   = "\033[40m";
const string ANSII_BACKGROUND_RED     = "\033[41m";
const string ANSII_BACKGROUND_GREEN   = "\033[42m";
const string ANSII_BACKGROUND_YELLOW  = "\033[43m";
const string ANSII_BACKGROUND_BLUE    = "\033[44m";
const string ANSII_BACKGROUND_MAGENTA = "\033[45m";
const string ANSII_BACKGROUND_CYAN    = "\033[46m";
const string ANSII_BACKGROUND_WHITE   = "\033[47m";

const string ANSII_UNDERLINE     = "\033[4m";
const string ANSII_BOLD          = "\033[1m";
const string ANSII_ITALIC        = "\033[3m";
const string ANSII_INVERSE       = "\033[7m"; // Swap foreground & background colours
const string ANSII_STRIKETHROUGH = "\033[9m";


// DEMO CODE
// Copy and paste the following code into your program to have it show you all
// the colours and styles. Note that __LINE__ is the current line number 
// of the file (which helps you figure out which colour/style you applied).
/*
 	cout << "\nNORMAL COLOURS\n";
	cout << ANSII_BLACK << "Testing @ line " << __LINE__ << ANSII_NORMAL << endl;
	cout << ANSII_RED << "Testing @ line " << __LINE__ << ANSII_NORMAL << endl;
	cout << ANSII_GREEN << "Testing @ line " << __LINE__ << ANSII_NORMAL << endl;
	cout << ANSII_YELLOW << "Testing @ line " << __LINE__ << ANSII_NORMAL << endl;
	cout << ANSII_BLUE << "Testing @ line " << __LINE__ << ANSII_NORMAL << endl;
	cout << ANSII_MAGENTA << "Testing @ line " << __LINE__ << ANSII_NORMAL << endl;
	cout << ANSII_CYAN << "Testing @ line " << __LINE__ << ANSII_NORMAL << endl;
	cout << ANSII_WHITE << "Testing @ line " << __LINE__ << ANSII_NORMAL << endl;

	cout << "\nBOLD STYLE\n";
	cout << ANSII_BOLD << ANSII_BLACK << "Testing @ line " << __LINE__ << ANSII_NORMAL << endl;
	cout << ANSII_BOLD << ANSII_RED << "Testing @ line " << __LINE__ << ANSII_NORMAL << endl;
	cout << ANSII_BOLD << ANSII_GREEN << "Testing @ line " << __LINE__ << ANSII_NORMAL << endl;
	cout << ANSII_BOLD << ANSII_YELLOW << "Testing @ line " << __LINE__ << ANSII_NORMAL << endl;
	cout << ANSII_BOLD << ANSII_BLUE << "Testing @ line " << __LINE__ << ANSII_NORMAL << endl;
	cout << ANSII_BOLD << ANSII_MAGENTA << "Testing @ line " << __LINE__ << ANSII_NORMAL << endl;
	cout << ANSII_BOLD << ANSII_CYAN << "Testing @ line " << __LINE__ << ANSII_NORMAL << endl;
	cout << ANSII_BOLD << ANSII_WHITE << "Testing @ line " << __LINE__ << ANSII_NORMAL << endl;

	cout << "\nBACKGROUND COLOURS\n";
	cout << ANSII_BACKGROUND_BLACK << "Testing @ line " << __LINE__ << ANSII_NORMAL << endl;
	cout << ANSII_BACKGROUND_RED << "Testing @ line " << __LINE__ << ANSII_NORMAL << endl;
	cout << ANSII_BACKGROUND_GREEN << "Testing @ line " << __LINE__ << ANSII_NORMAL << endl;
	cout << ANSII_BACKGROUND_YELLOW << "Testing @ line " << __LINE__ << ANSII_NORMAL << endl;
	cout << ANSII_BACKGROUND_BLUE << "Testing @ line " << __LINE__ << ANSII_NORMAL << endl;
	cout << ANSII_BACKGROUND_MAGENTA << "Testing @ line " << __LINE__ << ANSII_NORMAL << endl;
	cout << ANSII_BACKGROUND_CYAN << "Testing @ line " << __LINE__ << ANSII_NORMAL << endl;
	cout << ANSII_BACKGROUND_WHITE << "Testing @ line " << __LINE__ << ANSII_NORMAL << endl;
	
	cout << "\nSTYLES\n";
	cout << ANSII_BOLD << "Testing @ line " << __LINE__ << ANSII_NORMAL << endl;
	cout << ANSII_ITALIC << "Testing @ line " << __LINE__ << ANSII_NORMAL << endl;
	cout << ANSII_UNDERLINE << "Testing @ line " << __LINE__ << ANSII_NORMAL << endl;
	cout << ANSII_INVERSE << "Testing @ line " << __LINE__ << ANSII_NORMAL << endl;
	cout << ANSII_STRIKETHROUGH << "Testing @ line " << __LINE__ << ANSII_NORMAL << endl;
 */

#endif	/* ANSIICODES_H */

