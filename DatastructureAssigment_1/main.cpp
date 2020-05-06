#include <iostream>
#include <string.h>
#include <stdlib.h>
#include<ctype.h>
#include<stdio.h>
#include<cstdlib>
using namespace std;

int main(int argc, char *argv[])
{
    int i,j,sum;
    bool k=true;
    if (strcmp(argv[1] ,"print" )== 0)
        {
           if(argc<=2)
           cout <<"Incorrect Number of Arguments";
           else
            {
                for(i=2;i<=argc;i++)
               cout << argv[i] << " ";
            }

        }

    else if (strcmp(argv[1] ,"reverse" )== 0)
        {
         if(argc<=2)
         cout <<"Incorrect Number of Arguments";
         for(i=argc;i>=3;i--)
         cout << argv[i-1] << " ";
        }
    else if (strcmp(argv[1] ,"middle" )== 0)
    {
        if(argc <=2)
        cout <<"Incorrect Number of Arguments";
        else
        {
            int i = argc;
            if(i%2==1)
            {
            i = (i+1)/2;
            cout<< argv[i];
            }
            else
        {
            i = i/2;
            cout<< argv[i] <<" "<<argv[i+1];
        }
        }

    }
      else if(strcmp(argv[1] ,"delete" )== 0)
      {

          if(argc <=2)
          {cout <<"Incorrect Number of Arguments";
          k=false;
                goto V;
          }


          if(true)
         {   j = atoi(argv[2]);
            for(i=0;i < strlen(argv[2]);i++)
            {
                if((isdigit(argv[2][i])==0)&&(!(argv[2][0]== '+' )))
                {
                cout <<"Incorrect Data Type";
                k=false;
                goto V;
               }
               if(atoi(argv[2])==0)
               {
                cout <<"Incorrect Data Type";
                k=false;
                goto V;
               }
               if((argv[2][0]== '+' )&& (isdigit(argv[2][1])==0))
                {
                cout <<"Incorrect Data Type";
                k=false;
                goto V;
               }


               }
         }


         if(k){
        j = atoi(argv[2]);
             j = j +2;

             if(j >=argc)
             cout <<"Incorrect Number of Arguments";
             else
             {

                for(i=3;i<=argc;i++)
               {
               if(i!= j)
               cout << argv[i] <<" ";
                }
             }
           }
        V : while(true)
            break;
      }

    else if(strcmp(argv[1] ,"upper" )== 0)
    {
            if(argc <=2)
            cout <<"Incorrect Number of Arguments"<<endl;
            else
             {
            for(i=2;i<argc;i++)
              {
                 for(j=0;j < strlen(argv[i]);j++)
                 {
                    argv[i][j] = toupper(argv[i][j]);
                     cout << argv[i][j];
                 }
                 cout << " ";
              }

           }
    }



    else if(strcmp(argv[1] ,"add" )== 0)
    {
         if(argc <=2)
         cout <<"Incorrect Number of Arguments";
         if(true)
         {
             for(i=2;i<argc;i++)
           {
             for(j=0;j < strlen(argv[i]);j++)
             {
                 if((isdigit(argv[i][j])==0)&&(!(argv[i][0])== '-')&&(!isdigit(argv[i][1])==0))
                 {
                     cout <<"Incorrect Data Type";
                     k =false;
                     goto W;
                  }
                }
            }
         }

          if(true)
          {   for(i=2;i<argc;i++)
           {
             for(j=1;j < strlen(argv[i]);j++)
             {      if(isdigit(argv[i][j])==0)
                    {
                    cout <<"Incorrect Data Type";
                     k =false;
                     goto W;
                    }
              }
           }
          }


        if(true)
              {
                   for(i=2;i<argc;i++)
                {
                    if((strlen(argv[i])==1)&&(isdigit(argv[i][0])==0))
                 {
                 cout <<"Incorrect Data Type";
                     k =false;
                     goto W;
                }
              }
          }




         if(k)
         {
           sum = 0;
           for(i=2;i<=argc;i++)
           {
             j = atoi(argv[i]);
             sum = sum + j;
           }
           cout << sum;
         }
          W: while(true)
            break;
    }

    else if (strcmp(argv[1] ,"shuffle" )== 0)
    {
      if(argc !=3)
      cout <<"Incorrect Number of Arguments";
      else
        {

          for(i=0;i<strlen(argv[2]);i++)
           {
             if(i%2!=0)
             {
             cout << argv[2][i];
             cout << argv [2][i-1] ;
             }
           }
          if((strlen(argv[2]))%2==1)
          {
          j = strlen(argv[2])-1;
          cout<< argv[2][j];
         }
    }
    }


    else if (strcmp(argv[1] ,"shuffleStatement" )== 0)
    {

        if(argc <= 3)
        cout <<"Incorrect Number of Arguments"<<endl;

      else

       {
            for(i=2;i<argc;i++)
             {
              if(i%2!=0)
              {
              cout << argv[i]<<" ";
              cout << argv [i-1] << " ";
              }

             }
     if(argc%2==1)
     cout<< argv[argc-1];
    }
    }

   else if (strcmp(argv[1] ,"random" )== 0)
   {

       if(argc!=6)
       {cout <<"Incorrect Number of Arguments";
       k= false;
       goto L2;
       }

       if(true)
       {
         for(j=0;j < strlen(argv[2]);j++)
           {
               if((isdigit(argv[2][j])==0)||(atoi(argv[2])==0)||(atoi(argv[3])>atoi(argv[4])))
               {cout <<"Incorrect Data Type";
               k=false;

               goto L2;
               }
           }
       }

       if(true)
         {
             for(i=3;i<=5;i++)
           {
             for(j=0;j < strlen(argv[i]);j++)
             {
                 if((isdigit(argv[i][j])==0))
                    {
                        while(((argv[i][0])== '+') || ((argv[i][0])== '-'))
                       goto L1;
                     cout <<"Incorrect Data Type";
                     k=false;
                    goto L2;}
                 }
             }
           }

        L1: if(true)
        {
          for(i=3;i<=5;i++)
         {if(((argv[i][0])== '+' || ((argv[i][0])== '-'))&& isdigit(argv[i][1])==0)
        {
         cout <<"Incorrect Data Type";
                     k=false;
                    goto L2;
              }
        }
        }
       if(k)
          {
           int length = atoi(argv[2]);
           int minimum = atoi(argv[3]);
           int maximum = atoi(argv[4]);
           int seed_value = atoi(argv[5]);

           srand(seed_value);
           for(i=1;i <= length ; i++)
           cout << (rand()%(maximum-minimum+1)+minimum) << " ";
          }
          L2:
              while(true)
                break;
   }

   else
    cout <<"Undefined Command";
    return 0;
}
