#include "code.h"
#include "iostream"

//constructors

code::code()
{
	alph = new letter[26];

	for(int n=0;n<26;n++)
	{
		alph[n].let = 65+n;
		alph[n].rletter = 32;
		alph[n].freq = 0;
		alph[n].order = -1;
		alph[n].shift = 0;
	}
	punct = true;
}

code::code(string filename)
{
	codefile.open(filename);

	alph = new letter[26];

	for(int n=0;n<26;n++)
	{
		alph[n].let = 65+n;
		alph[n].rletter = 32;
		alph[n].freq = 0;
		alph[n].order = -1;
		alph[n].shift = 0;
	}
	punct = true;
}

//destructor

code::~code()
{
	codefile.close();
	delete alph;
}

//doing stuff

void code::count()
{
	char c;
	int i;
	codefile.seekg(0);
	codefile.seekp(0);
	//counts frequency
	while (codefile.good())
	{
		codefile.get(c);
		if(c != ' ' && c != 13)
		{
			alph[c-65].freq++;
		}
	}
	codefile.clear();

	//sorts letters;
	for(int n = 1;n<27;n++)
	{
		i = 0;
		c = 0;
		for (int m = 0;m<26;m++)
		{
			if(alph[m].order == -1 && i <= alph[m].freq)
			{
				i = alph[m].freq;
				c = alph[m].let;
			}
		}
			alph[c-65].order = n;
	}
	for(int n = 0; n < 26 ;n++)
	{
		cout << n <<": order-" <<alph[n].order<<" letter-" <<alph[n].let <<" frequency - "<<alph[n].freq;
		switch (alph[n].order)
		{
		case 1:
			alph[n].rletter = 'e';
			break;
		case 2:
			alph[n].rletter = 't';
			break;
		case 3:
			alph[n].rletter = 'a';
			break;
		case 4:
			alph[n].rletter = 'o';
			break;
		case 5:
			alph[n].rletter = 'i';
			break;
		case 6:
			alph[n].rletter = 'n';
			break;
		case 7:
			alph[n].rletter = 's';
			break;
		case 8:
			alph[n].rletter = 'h';
			break;
		case 9:
			alph[n].rletter = 'r';
			break;
		case 10:
			alph[n].rletter = 'd';
			break;
		case 11:
			alph[n].rletter = 'l';
			break;
		case 12:
			alph[n].rletter = 'c';
			break;
		case 13:
			alph[n].rletter = 'u';
			break;
		case 14:
			alph[n].rletter = 'm';
			break;
		case 15:
			alph[n].rletter = 'w';
			break;
		case 16:
			alph[n].rletter = 'f';
			break;
		case 17:
			alph[n].rletter = 'g';
			break;
		case 18:
			alph[n].rletter = 'y';
			break;
		case 19:
			alph[n].rletter = 'p';
			break;
		case 20:
			alph[n].rletter = 'b';
			break;
		case 21:
			alph[n].rletter = 'v';
			break;
		case 22:
			alph[n].rletter = 'k';
			break;
		case 23:
			alph[n].rletter = 'j';
			break;
		case 24:
			alph[n].rletter = 'x';
			break;
		case 25:
			alph[n].rletter = 'q';
			break;
		case 26:
			alph[n].rletter = 'z';
			break;
		default:
			alph[n].rletter = '@';
			break;
		}
		cout << " rletter- "<< alph[n].rletter<< "\n";
	}
	cout << "\n\n";
	codefile.seekg(0);
	codefile.seekp(0);
	while(codefile.good())
	{
		codefile.get(c);
		if(c>64 && c<91)
		{
			cout << alph[c-65].rletter;
		}
		else
			cout << c;
	}
	cout << "\n\n\n";
}

void code::swap(char ch1,char ch2)
{
	bool l = true;
	int n=0;
	int m=0;
	while(alph[n].rletter != ch2){n++;}
	while(alph[m].rletter != ch1){m++;}
	alph[n].rletter = ch1;
	alph[m].rletter = ch2;
}

/* to do...

void code::repeat()
{
	char cc,cn;
	codefile.clear();
	codefile.seekp(0);
	codefile.seekg(0);
	while(codefile.good())
	{

	}
}

*/

void code::shift(int s)
{
	for(int i = 0;i<26;i++)
	{
		if(i+97+s<123)
		{
			alph[i].rletter = alph[i].let + s + 32;
			alph[i].shift = s;
		}
		else
		{
			alph[i].rletter = alph[i].let + s + 6;
			alph[i].shift = s;
		}
	}
}

//display

int code::getshift(char c)
{
	int n = 0;
	while(alph[n].rletter != c && n < 26){n++;}
	if(n > 25)
	{
		return 0;
	}
	if(alph[n].let > c - 32)
	{
		alph[n].shift = 26 - (alph[n].let - (c-32));
		return alph[n].shift;
	}
	else
	{
		alph[n].shift = (c - (alph[n].let + 32));
		return alph[n].shift;
	}
}

void code::show()
{
	char c;
	codefile.clear();
	codefile.seekg(0);
	codefile.seekp(0);
	while(codefile.good())
	{
		codefile.get(c);
		if(c>64 && c<91)
		{
			cout << alph[c-65].rletter;
		}
		else if(punct)
			cout << c;
	}
	cout << "\n\n";
}

void code::write(string file)
{
	char c,l;
	fstream ans;
	ans.open(file);
	codefile.clear();
	codefile.seekg(0);
	codefile.seekp(0);
	while(codefile.good())
	{
		codefile.get(c);
		if (c>64 && c<91)
		{
			l = alph[c-65].rletter;
			ans << l;
		}
		else if(punct)
			ans << c;
	}
	ans.close();
}

//changing stuff

void code::togglepunct()
{
	if(punct)
		punct = false;
	else
		punct = true;
}
