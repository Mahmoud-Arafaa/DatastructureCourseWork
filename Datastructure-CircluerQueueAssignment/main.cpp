#include <iostream>
#include<bits/stdc++.h>
#include <typeinfo>
#include "queue.h"
#include <iostream>
using namespace std;
int main(int argc,char* argv[])
{

    StaticQueue<int> W ;
    StaticQueue<int> R ;
    StaticQueue<int> D;

    int a,b,d;
    int tst=0;
    a=atoi(argv[1]);
	int limit=(pow(2,a))-1;
	b=atoi(argv[2]);
	d=atoi(argv[3]);

	if (argc<5){
            cout<<"Invalid number of arguments ";
            tst++;
	}
	if(a<=0 || !isdigit(argv[1][0])){
            cout<<"Invalid seqNumBits ";
            tst ++;
          }
    if(isdigit(argv[1][0])) {
        if(b>limit|| b<=0 ||!isdigit(argv[2][0])){
            cout <<"Invalid winSize ";
            tst ++;
            }
        if(d>limit||d<0 || !isdigit(argv[3][0])){
            cout<<"Invalid initSeq ";
            tst ++;
          }

    }
    if (!isdigit(argv[1][0])) {
        if( b<=0 ||!isdigit(argv[2][0])){
            cout <<"Invalid winSize ";
            tst ++;}
        if(d<0 || !isdigit(argv[3][0])){
            cout<<"Invalid initSeq ";
            tst ++;
          }
    }
    int t,minusVal=0,charVal=0,limtVal=0;
	for(int i=4 ; i<argc ; i++){
        string str(argv[i]);
        stringstream ss(str);
        ss >> t;
        if(t>limit && a>0)
            limtVal++;
        if(t<0)
            minusVal++;
        if(int(str[0])>=65&&int(str[0])<=90)
            charVal++;
        if(int(str[0])>=97&&int(str[0])<=122)
            charVal++;

        }
    if(minusVal>0||charVal>0||limtVal>0){
            cout<<"Invalid packet ID";
            tst++;
    }

    if(tst>0){
        return 0;
    }

    int j=argc-4;
    int i=4;
    int temp;
    int E=d;
    int itr=1;
    while(j--)
    {

        string str(argv[i++]);
        stringstream ss(str);
        ss >> temp;
        if(E>limit){
            E=0;
            itr++;
        }
        if(temp>E+b-1)
        {
            D.enqueue(temp);
            continue;

        }
        if(temp==E)
        {
            W.enqueue(temp);
            E++;
            if(W.found(E))
            {
                E++;
                }
        continue;

        }
        if((temp<E) && (temp >= E+b-limit-1))
        {
            D.enqueue(temp);
            continue;
        }

        if(temp==limit)
        {
            W.enqueue(temp);
            itr++;


            continue;
        }
        if(W.found(temp)&&itr==1)
        {
            D.enqueue(temp);
        }else{
               W.enqueue(temp);
        }
    }




    W.normalize(limit);
    W.order();
    W.nonNormalize(limit);

    int E2= d;
    for(int i=0;i<argc-4;i++)
    {

        if(E2==W.fronty())
        {
            R.enqueue(E2);
            E2++;
            W.dequeue();
        }

        else
            break;
        if(E2==limit+1){E2=0;}
    }

    if(E2>limit){E2=0;}

    cout<<"R ";R.print();
    cout <<" E "<<E2;
    cout<<" W ";W.print();
    cout<<" D ";D.print();


}
