#include<stdio.h>
#include<string.h>
char * encrypt(char *str,char *key)
{

    int len=strlen(str);
    char *res=(char*)malloc(51200*sizeof(char));
    int index=0;
    for(index = 0 ; str[index]!='\0' ; index++)
    {

        res[index]=str[index]+(key[index]-'0');
        if(res[index]>'Z'&&res[index]<'a')
            res[index]=res[index]-'Z'+'A'-1;
        if(res[index]>'z')
            res[index]=res[index]-'z'+'a'-1;

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
    testString("bcd",encrypt("abc","111"),1);
    testString("bdfhj",encrypt("abcde","12345"),2);
    testString("ksj",encrypt("brg","913"),3);
    testString("CvfD",encrypt("ZraB","3452"),4);
    testString("abcd",encrypt("abcd","0000"),5);

}
int main()
{
    test();
    return 0;
}
