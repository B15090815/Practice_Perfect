//#include<iostream>
//#include<stdlib.h>
//#include<time.h>
//using namespace std;
//int main()
//{
//	srand((unsigned)time(NULL));
//	int a = 0;
//	int b = 26;
//	int c;
//	for(int i=0;i<72;i++){
//		c = (rand() % (b-a+1))+ a;
//		cout<<(char) ('a'+c);
//	}
////	cout<<(char) ('a'+27);
//	cout<<"\n";
//	return 0;
//} 

#include <stdio.h>
#include<string.h>
int main()
{
    char buf[80]={'\0'};
    char s[5];
//    scanf("%s",s);
    for(int i=0;i<10;i++){
    	sprintf(s,"%X",i+20);
    	printf("%s",s);
    	strcat(buf,s);
		} 
		printf("\n");
//    sprintf(buf, "insert into temp (t,k) values(%s)\n", s);
//    printf("%s\n",buf);
//    scanf("%s",s);
//    sprintf(buf, "insert into temp (t,k) values(%s)\n", s);
    printf("%s\n", buf);
    return 0;
}
 
