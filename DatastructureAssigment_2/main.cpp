#include "InordList.h"
#include<bits/stdc++.h>
using namespace std;

InordList::InordList()
{
    head=last=current=NULL;
}

int InordList::wordCount()
{
    int cnt=1;
    if(head==NULL)
    {
        cout<<"There's No Words!";
        return 0;
    }
    Node *temp=head;
    for(temp;temp->next!=NULL;temp=temp->next)
        {cnt++;};
    return cnt;
}

int InordList::distWord(int &n)
{
    if(head==NULL)
    {
        cout<<"There's No Dist.. Words";
        return 0;
    }
    Node *temp=head;
    int cnt=0;
    for(temp;temp->next!=NULL;temp=temp->next)
    {
        if(temp->data==temp->next->data)
            cnt++;
    }
    int result=n-cnt;
    return result;

}

int InordList::countWord(string &s)
{
    if(head==NULL)
    {
        cout<<"There's No Words!";
        return 0;
    }
    Node *temp=head;
    int cnt=0;
    for(temp;temp->next!=NULL;temp=temp->next)
    {
        if(temp->data==s)
            cnt++;
    }
    return cnt;
}

void InordList::frequentWord()
{
    if(head==NULL)
    {
        cout<<"There's No Words!";
        return ;
    }
    Node *temp=head;
    string test;
    string arr[1000];int j=0;
    for(temp;temp->next!=NULL;temp=temp->next)
    {
        test=temp->data;
        arr[j++]=test;
    }
    int maxm=0,minm=-15;
    string store="";
    bool visited=0;
    sort(arr,arr+j);
    for(int i=0;i<j;i++)
    {

        maxm=countWord(arr[i]);
        if(maxm>minm)
        {
            minm=maxm;
            store=arr[i];
        }
    }
    cout<<store;

}
void InordList::starting(string &s)
{
    if(head==NULL)
    {
        cout<<"There's No Words!";
        return ;
    }
    Node *temp=head;
    string test="";
    bool done=true;
    string arr[100];int j=0;
    int len=s.length();
    for(temp;temp->next!=NULL;temp=temp->next)
    {
       test=temp->data;
       if(test.substr(0,len).compare(s)==0)
            arr[j++]=test;
    }

    sort(arr,arr+j);
    string hello="";
    int cnt=0;
    for(int i=0;i<j;){
            hello=arr[i];
            for(int k=0;k<j;k++)
            {
                if(hello==arr[k])
                    cnt++;
            }
            cout<<hello<<": "<<cnt<<" ";
            i=(i+cnt);
            cnt=0;
}
}
void InordList::search(string &s)
{
    if(head==NULL)
    {
        cout<<"There's No Words!";
        return ;
    }
    Node *temp=head;
    Node *iter=head;
    string test;
    string arr[100];int j=0;
    int sor[100];
    int x=0;
    string visted[100];int vi=0;
    int len=s.length();
    bool lol=0;
    for(temp;temp->next!=NULL;temp=temp->next)
    {
       test=temp->data;
       if(test.substr(0,len).compare(s)==0)
       {
           for(int k=0;k<vi;k++)
           {
               if(test==visted[k])
                    lol=1;
           }


           if(!lol){
           cout<<test<<" :";
           for(iter;iter->next!=NULL;iter=iter->next)
           {
               if(test==iter->data)
               {
                   sor[x++]=iter->lnum;
               }
           }
           sort(sor,sor+x);
           cout<<" Lines ";
           for(int i=0;i<x;i++)
                cout<<sor[i]<<" ";
           iter=head;
           cout<<endl;
           visted[vi++]=test;
           lol=1;
           x=0;
       }
       lol=0;
     }
       }
    }
void InordList::print()
{
    Node *temp=head;
    if(head==NULL)
        return ;
    for(temp;temp->next!=NULL;temp=temp->next)
    {
        cout<<temp->data<<" ";
        cout<<temp->lnum<<"\n";
    }
}

bool InordList::insert_(const string &s,int &n)
{

    Node *newNode=new Node;
    Node *temp;
    if(newNode == NULL)
        return false;
    newNode->data=s;
    newNode->lnum=n;
    if(head==NULL || (s.compare(head->data))<=0 )
    {
        newNode->next=head;
        head=newNode;
    }
    else
    {
        temp=head;
        while(temp ->next !=NULL &&(s.compare(temp->next->data))>=0)
                temp=temp->next;
        newNode->next = temp->next;
        temp->next=newNode;

    }
return true;
}
int main(int argc,char *argv[])
{

  InordList lis;
  ifstream file;
  file.open(argv[1]);

  if(file.is_open()!=1)
  {
      cout<<"There's No file";
      return 0;
  }

  if(argc!=3)
  {
      cout<<"There's No Commands File";
      return 0;
  }

  string s;
  int cnt=0;
  while(getline(file,s))
  {
      for(int i=0;i<s.length();i++)
      {
          if(s[i]==','||s[i]=='.'||s[i]=='\n'||s[i]=='\t')
                s[i]=' ';
      }
      cnt++;
      string temp="";
      stringstream obj(s);
      while(obj>>temp)
      {
          for(int i=0;i<temp.length();i++)
          {
              if(temp[i]>=65&&temp[i]<97)
                    temp[i]+=32;
          }
          lis.insert_(temp,cnt);
      }


}
  file.close();
  ifstream commandsFile;
  commandsFile.open(argv[2]);
  if(!commandsFile.is_open())
  {
      cout<<"There's No Command File";
      return 0;
  }
  string total,command,test;
  int result;
  while(getline(commandsFile,total))
  {
    stringstream obj(total);
    obj>>command;
    if(command=="wordCount")
    {
        cout<<lis.wordCount()<<" words\n";
    }

    if(command=="distWords")
    {
        result=lis.wordCount();
        cout<<lis.distWord(result)<<" distinct words\n";
    }
    if(command=="charCount")
    {
        file.open(argv[1]);
        int cnt=0;
        string line;
        while(getline(file,line)){
            cnt+=line.length();
            cnt++;
        }
        cout<<cnt<<" characters\n";
    }
    if(command=="frequentWord")
    {
        cout<<"Most frequent word is: ";
        lis.frequentWord();
        cout<<"\n";
    }
    if(command=="countWord")
    {

        obj>>test;
        result=lis.countWord(test);
        if ( (total.length()>(9+test.length()+2) || (total.length())<11 ))
        {
            cout << "Wrong Command!";
            return 0;
        }
        cout << test <<" is repeated "<<result<<" times" << endl ;
    }
    if(command=="starting")
    {
        obj>>test;
        if ( (total.length()>(9+test.length()+1) || (total.length())<10 ))
        {
            cout << "Wrong Command!";
            return 0;
        }
        for(int i=0;i<test.length();i++)
          {
              if(test[i]>=65&&test[i]<97)
                    test[i]+=32;
          }
          lis.starting(test);
          cout<<endl;
    }
    if(command=="search")
    {
       obj>>test;
       for(int i=0;i<test.length();i++)
          {
              if(test[i]>=65&&test[i]<97)
                    test[i]+=32;
          }

       if (test.length()<2)
        {
            cout << "Wrong Command!";
            return 0;
        }
        lis.search(test);


    }
    if(command.length()<1)
    {
        cout<<"Undefined command\n";
        return 0;
    }

  }
  commandsFile.close();
}



