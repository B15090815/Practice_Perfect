#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;


bool IsDigit(char c)
{
	return '0'<=c && c<='9';
}

bool IsLetter(char c)
{
	return 'A'<=c && c <='z';
}

void preprocess(ifstream &s)
{
	char c;
	ofstream outfile("process.txt",ios::out);
	if(outfile.is_open()){
		while(!s.eof())
		{
			c = s.get();
			switch(c)
			{
				case '/':
					c = s.get();
					if(c == '/'){
						while(c != '\n'){
							c = s.get();
						}
					}else{
						while(c != '/'){
							c = s.get();
						}
					}
					break;
				case '\t':
				case '\r':
				case '\n':
					break;
				default:
					outfile.put(c);
			}
		}
		
	}
	outfile.close();
}


void parse(ifstream &s)
{
	char buff[128];
	char ch;
	char token[20];
	int i = 0;
	bool backoff = false;
	//fstream::pos_type current;
	while(!s.eof())
	{
		
		if(!backoff){
			ch = s.get();
		}
		backoff = false;
		if(IsLetter(ch)){
			token[i++] = ch;
			while(1){
				ch = s.get();
				
				if(IsLetter(ch) || IsDigit(ch)){
					token[i++] = ch;
				}else{
					token[i] = '\0';
					cout<<token<<endl;
					i = 0;
					backoff = true;
					break;
				}
			}
		}else if(IsDigit(ch)){
			while(1){
				ch = s.get();
				if(IsDigit(ch)){
					token[i++] = ch;
				}else{
					token[i] = '\0';
					cout<<token;
					i = 0;
					backoff = true;
					break;
				}
			}
		}else{
			switch(ch)
			{
				
				case ' ':
					break;
				case '+':
				case '-':
				case '*':
				case '/':
				case '%':
				case '=':
				case '!':
	 			case '>':
				case '<':
					token[i++] = ch;

					ch = s.get();
					if(ch == '='){
						token[i++] = ch;
					}else{
						backoff = true;
					}
					token[i] = '\0';
					cout<<token<<endl;
					i=0;
					break;
				case ';':
				case '(':
				case ')':
				case '{':
				case '}':
				case ',':
					token[i++] = ch;
					token[i] = '\0';
					cout<<token<<endl;
					i=0;
					break;			
			}
			
			
			
			
			
		}
	}
}


int main()
{
	ifstream source("source.txt",ios::in);
	if(!source.is_open())
	{
		cout<<"open source file fail\n";
		return 0;
	}
	preprocess(source);
	source.close();
	
	char buff[128];
	memset(buff,0,100);
	ifstream s("process.txt",ios::in);
	s.read(buff,5);
	cout<<buff;
/*
	while(!s.eof())
	{
		cout<<(char)s.get();
	}*/
	
	
	//parse(s);

	//s.close();
	return 0;
}

