#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int testCase=0,numOfCrossings=0,numOfStreets=0,numOfQueries=0;
    while(true)
    {
        cin >> numOfCrossings >> numOfStreets >> numOfQueries;

        if(numOfCrossings==0 && numOfStreets==0 && numOfQueries==0)
            break;

        int weight[numOfCrossings+1][numOfCrossings+1] ;
        int c1,c2;

        for(int i=1; i<=numOfCrossings; i++)
            for(int j=1; j<=numOfCrossings; j++)
                weight[i][j] = 99999;

        for(int i=1; i<=numOfStreets; i++)
        {
            cin >> c1 >> c2;
            cin >> weight[c1][c2] ;
            weight[c2][c1]= weight[c1][c2] ;
        }

        for(int k=1; k<=numOfCrossings; k++)
            for(int i=1; i<=numOfCrossings; i++)
                for(int j=1; j<=numOfCrossings; j++)
                    weight[i][j] = weight[j][i]  = min(weight[i][j],max(weight[i][k], weight[k][j]));
        testCase++;
        cout <<"Case "<<testCase<<endl;

        for(int i=1; i<=numOfQueries; i++)
        {
            cin >> c1 >> c2;

            if(weight[c1][c2] == 99999)
                cout <<"no path"<<endl;
            else
                cout << weight[c1][c2]<<endl;

        }
    }
    return 0;
}
