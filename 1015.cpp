#include<iostream>
#include<cstdio>
using namespace std;
int ParseInt(char c)
{
    return c-'0';
}

int main()
{
    char formula[100];
    gets(formula);
    int bit;
    int sign[2];
    int first = -1;
    int tail = -1;
    int num = 0;
    bool Isop = false;
    bool Isx = false;
    int right = 0;
    char c;
    float a = 0.0;
    float b = 0.0;
    char d;
    for(int i=0;formula[i]!='\0';i++)
    {
        c = formula[i];
        if(c>='0' && c<='9')
        {
            bit = ParseInt(c);
            num = (num*10 + bit);
            if(i==0)
                sign[tail = (tail+1)%2] = 1;
        }
        else if(c=='-')
        {
            sign[tail = (tail+1)%2] = -1;
            if(i>0)
                Isop = true;
        }
        else if(c=='+')
        {
            sign[tail = (tail+1)%2] = 1;
            if(i>0)
                Isop = true;
        }else if(c=='=')
        {
            Isop = true;
            sign[tail = (tail+1)%2] = 1;
            right++;
        }else if(c>='a' && c<='z')
        {
            Isx = true;
            d = c;
            if(num<1)
                num = 1;
        }

        if(Isop)
        {
            num = num*sign[first = (first+1)%2];
            Isop = false;
            if(num!=0)
            {
                if(right==1)
                {
                    if(Isx)
                    {
                        b = b + float(num);
                        Isx = false;
                    }else{
                        a = a + float(num);
                    }
                    right++;
                }else if(right>1)
                {
                    if(Isx)
                    {
                        b = b - float(num);
                        Isx = false;
                    }else{
                        a = a - float(num);
                    }
                }else
                {
                    if(Isx)
                    {
                        b = b + float(num);
                        Isx = false;
                    }else{
                        a = a + float(num);
                    }
                }
                num = 0;
            }

        }
    }

    if(right)
    {
        if(Isx)
            b = b - num*sign[tail];
        else
            a = a - num*sign[tail];
    }else
    {
        if(Isx)
            b = b + num*sign[tail];
        else
            a = a + num*sign[tail];
    }
    printf("%c=%.3f\n",d,-a/b);
    return 0;
}
