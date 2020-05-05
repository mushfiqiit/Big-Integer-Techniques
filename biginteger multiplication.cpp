#include <bits/stdc++.h>

using namespace std;

string ans;

void bigIntegerAdd(int bigIntA[], int bigIntB[])
{
    int carry=0;
    int bigIntSum[100]={0};
    for(int i =0;i<100;i++)
    {
        bigIntSum[i]=(bigIntA[i]+bigIntB[i]+carry)%10;
        carry=(bigIntA[i]+bigIntB[i]+carry)/10;
    }

    for(int i=0;i<100;i++)
    {
        bigIntB[i]=bigIntSum[i];
    }
}

void bigIntegerMultiplication(string s1, string s2)
{
    int bigIntA[100]={0},  bigIntB[100];

    for(int i=s1.length()-1, j=0;i>=0;i--, j++)
    {
        bigIntA[j]=s1[i]-'0';
    }

    for(int i=s2.length()-1, j=0; i>=0;i--, j++)
    {
        bigIntB[j]=s2[i]-'0';
    }

    int byproduct[s2.length()][100]={0};
    for(int j=0;j<s2.length();j++)
    {
        int carry=0;
        int byproditr=0;
        while(byproditr<j)
        {
            byproduct[j][byproditr++]=0;
        }
        for(int i=0;i<100;i++)
        {
            byproduct[j][byproditr++]=(bigIntA[i]*bigIntB[j]+carry)%10;
            carry=(bigIntA[i]*bigIntB[j]+carry)/10;
            //cout << byproduct[j][byproditr-1];
        }
        //cout << "\n";
    }

    for(int j=0;j<s2.length()-1;j++)
    {
        bigIntegerAdd(byproduct[j], byproduct[j+1]);
    }

    /*for(int i=0;i<100;i++)
    {
        cout << byproduct[s2.length()-1][i];
    }
    cout << "\n";*/
    string result;
    int flag=0;
    for(int i=99;i>=0;i--)
    {
        if(flag!=0 || byproduct[s2.length()-1][i]!=0)
        {
        char ch=(byproduct[s2.length()-1][i]+'0');
        result=result+ch;
        flag=1;
        }
    }
    //cout << result << endl;
    ans=result;
    char ch='\0';
    ans=ans+ch;
    //cout << ans << endl;
    //result=result+'\0';*/
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    bigIntegerMultiplication(s1, s2);

    int flag=0;
    //cout << ans << endl;
    for(int i=0;i<100;i++)
    {
        if(flag!=0 || ans[i]!='0')
        {
            cout << ans[i];
            flag=1;
        }
    }
    //cout << ans;
}
