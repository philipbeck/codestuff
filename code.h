#ifndef CODE_H
#define CODE_H

#include "string"
#include <fstream>
using namespace std;

struct letter{
char let;
char rletter;
int freq;
short order;
short shift;
};

class code
{
public:
	//constructors
	code();
	code(string);
	//destructors
	~code();
	//swapping things etc
	void count();
	void swap(char,char);
	void repeat();
	void shift(int);
	//display
	int getshift(char);
	void show();
	void write(string);
	//changing stuff
	void togglepunct();
private:
	fstream codefile;
	letter* alph;
	bool punct;
};

#endif
