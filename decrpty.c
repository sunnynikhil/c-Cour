#include<stdio.h>
#include<string.h>
char * decrypt(char *str,char *key)
{

    int len=strlen(str);
    char *res=(char*)malloc(512000*sizeof(char));
    int index=0;
    for(index = 0 ; str[index]!='\0' ; index++)
    {

        res[index]=str[index]-(key[index]-'0');
        if((res[index]<'a'&&res[index]>'A'&&str[index]>='a'&&str[index]<='z')||(res[index]<'A'&&str[index]>='A'&&str[index]<='Z'))
            res[index]=res[index]+26;
    }
    res[index]='\0';
    return res;
}
void testString(char * expected,char * actual,int testcase)
{
    if(strcmp(expected,actual)==0)
    {
        printf("Test case %d passed\n",testcase);
    }
    else
    {
        printf("Test case %d failed expected : %s actual %s\n",testcase,expected,actual);
    }
}
void test()
{
    testString("abc",decrypt("bcd","111"),1);
    testString("abcde",decrypt("bdfhj","12345"),2);
    testString("brg",decrypt("ksj","913"),3);
    testString("ZraB",decrypt("CvfD","3452"),4);
    testString("abcd",decrypt("abcd","0000"),5);
}
int main()
{
    test();
    return 0;
}
