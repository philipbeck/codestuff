#include <iostream>
#include "code.h"
#include <string>;
using namespace std;

int main()
{
	bool notdone = true;
	string fname,cmd;
	char ch1,ch2;
	int n;
	cout << "Type the name of the file you want decoding: ";
	cin >> fname;
	cout << "\nLooking at the frequency of letters...";
	code file(fname);
	file.count();
	cout << "Type in help to see all commands\n\n";
	while (notdone)
	{
		cout << "What would you like to do now?\n";
		cin >> cmd;
		if(cmd == "swap")
		{
			cout << "Type a letter you want to swap: ";
			cin >> ch1;
			cout << "Type the one you want to swap it with: ";
			cin >> ch2;
			cout << "\n\n";
			file.swap(ch1,ch2);
			file.show();
		}
		else if(cmd == "getshift")
		{
			cout << "what letter?\n";
			cin >> ch1;
			cout << "shift "<< ch1 << " = " << file.getshift(ch1) << "\n";
		}
		else if(cmd == "getallshift")
		{
			for(int i = 0; i<26;i++)
			{
				cout << (char) (i+97) << " = "<< file.getshift(i+97) << "\n";
			}
		}
		else if(cmd == "shift")
		{
			cout << "How much would you like to shift by?\n";
			cin >> n;
			cout << "shifting...\n";
			file.shift(n);
			file.show();
			cout << "\n\n";
		}
		else if(cmd == "write")
		{
			cout << "What is the name of the file you want to write to?\n";
			cin >> fname;
			cout << "writing...\n";
			file.write(fname);
			cout << "finished!\n";
		}
		else if(cmd == "quit")
		{
			notdone = false;
		}
		else if(cmd == "punctuation")
		{
			cout << "Toggling punctuation\n\n";
			file.togglepunct();
			file.show();
			cout << "\n\n";
		}
		else if(cmd == "help")
		{
			cout << "\nCommands:\n\n"
				<<"\47swap\47 - Swaps two letters\n"
				<<"\47getshift\47 - Gets the shift from the original of one letter\n"
				<<"\47getallshift\47 - Gets the shifts for the whole alphabet\n"
				<<"\47shift\47 - Shifts the alphabet along by a number of spaces\n"
				<<"\47write\47 - Writes the \47finished\47 code to a new file\n"
				<<"\47quit\47 - Ends the program (anything you haven't written to a file will be lost)\n"
				<<"\47punctuation\47 - Toggles whether to ignore things that aren't letters\n"
	//			<<"\47help\47 - Lists all the commands, hopefully you have realised this\n\n"
				<<"Also remember to put \42.txt\42 at the end of your filenames.\n\n"
				<<"If you have any other ideas about what this could do or have found some \nproblems tell me on facebook or something\n\n";
		}
	}
	return(0);
}
