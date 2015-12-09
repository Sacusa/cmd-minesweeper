#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <process.h>
#include "numinput.cpp"

int i,j,diff,nobomb=0,ex,ey,bx,by,x,y,win,action,flag=0,inerr=0;
char grid1[7][7],grid2[9][9],grid3[12][12],grid4[16][16],chkbomb;
char grid01[7][7],grid02[9][9],grid03[12][12],grid04[16][16],restart;

void main()
{
 startgame:
 flag=0;
 clrscr();
 void generator(void);
 void check(void);
 void open(void);
 void chkblank(void);
 void dispbomb(void);
 cout<<"\t\t\t\tCMD Minesweeper";
 cout<<"\n\nDifficulty:";
 cout<<"\n1.Beginner (7x7, 5 bombs)";
 cout<<"\n2.Easy (9x9, 10 bombs)";
 cout<<"\n3.Intermediate (12x12, 24 bombs)";
 cout<<"\n4.Advanced (16x16, 60 bombs)";
 cout<<"\n\nEnter difficulty: ";
 inerr=intnum(diff);
 if(inerr==1 || inerr==2 || diff>4 || diff<1)
 	goto startgame;
 switch(diff)
 {
  case 1:
     starterr1:
	 clrscr();
	 cout<<"\t\t\t\tCMD Minesweeper\n";
	 cout<<"\n\t  ";
	 for(i=0;i<7;i++)
	 cout<<i+1<<' ';
	 for(i=0;i<7;i++)
	 {
	  cout<<"\n\t"<<i+1<<' ';
	  for(j=0;j<7;j++)
	  cout<<"0 ";
	 }
	 cout<<"\n\nEnter the\n";
	 cout<<"-Row: ";
	 inerr=intnum(x);
	 if(inerr==1 || inerr==2 || x>7 || x<1)
	 	goto starterr1;
	 cout<<"-Column: ";
	 inerr=intnum(y);
	 if(inerr==1 || inerr==2 || y>7 || y<1)
	 	goto starterr1;
	 ex=x;
	 ey=y;
	 generator();
	 grid01[x-1][y-1]=grid1[x-1][y-1];
	 for(i=0;i<7;i++)
	 chkblank();
	 while(flag==0)
	 {
	  start1:
	  clrscr();
	  cout<<"\t\t\t\tCMD Minesweeper\n";
	  cout<<"\n\t  ";
	  for(i=0;i<7;i++)
	  cout<<i+1<<' ';
	  for(i=0;i<7;i++)
	  {
	   cout<<"\n\t"<<i+1<<' ';
	   for(j=0;j<7;j++)
	   cout<<grid01[i][j]<<' ';
	  }
	  cout<<"\n\n";
	  cout<<"Actions";
	  cout<<"\n1.Open";
	  cout<<"\n2.Flag";
	  cout<<"\n3.Exit";
	  cout<<"\n\nAction: ";
	  inerr=intnum(action);
	  if(inerr==1 || inerr==2 || action>3 || action<1)
	  	goto start1;
	  if(action==1)
	  {
	   actionerr11:
	   cout<<"\nEnter\n";
	   cout<<"-Row: ";
	   inerr=intnum(x);
	   if(inerr==1 || inerr==2 || x>7 || x<1)
	   	goto actionerr11;
	   cout<<"-Column: ";
	   inerr=intnum(y);
	   if(inerr==1 || inerr==2 || y>7 || y<1)
	   	goto actionerr11;
	   open();
	  }
	  else
	  if(action==2)
	  {
	   actionerr12:
	   cout<<"\nEnter\n";
	   cout<<"-Row: ";
	   inerr=intnum(x);
	   if(inerr==1 || inerr==2 || x>7 || x<1)
	   	goto actionerr12;
	   cout<<"-Column: ";
	   inerr=intnum(y);
	   if(inerr==1 || inerr==2 || y>7 || y<1)
	   	goto actionerr12;
	   grid01[x-1][y-1]='F';
	  }
	  else
	  if(action==3)
	  {
	   clrscr();
	   cout<<"Thank you for playing my game.";
	   cout<<"\n\nMade By:  Sudhanshu Gupta";
	   cout<<"\n\nPress any key to continue...";
	   getch();
	   return;
	  }
	  check();
	  if(flag==1)
	  {
	   dispbomb();
	   clrscr();
	   cout<<"\t\t\t\tCMD Minesweeper\n";
	   cout<<"\n\t  ";
	   for(i=0;i<7;i++)
	   cout<<i+1<<' ';
	   for(i=0;i<7;i++)
	   {
	    cout<<"\n\t"<<i+1<<' ';
	    for(j=0;j<7;j++)
	    cout<<grid01[i][j]<<' ';
	   }
	   cout<<"\n\nOh snap! You lost the game. Better luck next time";
	   cout<<"\n\nPress any key to continue.";
	   getch();
	   restarterr11:
	   clrscr();
	   cout<<"Would you like to play again (Y/N): ";
	   cin>>restart;
	   if(restart=='Y' || restart=='y')
	   goto startgame;
	   else
	   if(restart=='N' || restart=='n')
	   {
	    clrscr();
	    cout<<"Thank you for playing my game.";
	    cout<<"\n\nMade By: Sudhanshu Gupta";
	    cout<<"\n\nPress any key to continue...";
	    getch();
	    return;
	   }
	   else
	   goto restarterr11;
	  }
	  if(flag==2)
	  {
	   clrscr();
	   cout<<"\t\t\t\tCMD Minesweeper\n";
	   cout<<"\n\t  ";
	   for(i=0;i<7;i++)
	   cout<<i+1<<' ';
	   for(i=0;i<7;i++)
	   {
	    cout<<"\n\t"<<i+1<<' ';
	    for(j=0;j<7;j++)
	    cout<<grid01[i][j]<<' ';
	   }
	   cout<<"\n\nCongratulations! You won the game.";
	   cout<<"\n\nPress any key to continue.";
	   getch();
	   restarterr12:
	   clrscr();
	   cout<<"\n\nWould you like to play again (Y/N): ";
	   cin>>restart;
	   if(restart=='Y' || restart=='y')
	   goto startgame;
	   else
	   if(restart=='N' || restart=='n')
	   {
	    clrscr();
	    cout<<"Thank you for playing my game.";
	    cout<<"\n\nMade By: Sudhanshu Gupta";
	    cout<<"\n\nPress any key to continue...";
	    getch();
	    return;
	   }
	   else
	   goto restarterr12;
	  }
	  else
	  goto start1;
	 }
  case 2:
     starterr2:
	 clrscr();
	 cout<<"\t\t\t\tCMD Minesweeper\n";
	 cout<<"\n\t  ";
	 for(i=0;i<9;i++)
	 cout<<i+1<<' ';
	 for(i=0;i<9;i++)
	 {
	  cout<<"\n\t"<<i+1<<' ';
	  for(j=0;j<9;j++)
	  cout<<"0 ";
	 }
	 cout<<"\n\nEnter the\n";
	 cout<<"-Row: ";
	 inerr=intnum(x);
	 if(inerr==1 || inerr==2 || x>9 || x<1)
	     goto starterr2;
	 cout<<"-Column: ";
	 inerr=intnum(y);
	 if(inerr==1 || inerr==2 || y>9 || y<1)
	     goto starterr2;
	 ex=x;
	 ey=y;
	 generator();
	 grid02[x-1][y-1]=grid2[x-1][y-1];
	 for(i=0;i<9;i++)
	 chkblank();
	 while(flag==0)
	 {
	  start2:
	  clrscr();
	  cout<<"\t\t\t\tCMD Minesweeper\n";
	  cout<<"\n\t  ";
	  for(i=0;i<9;i++)
	  cout<<i+1<<' ';
	  for(i=0;i<9;i++)
	  {
	   cout<<"\n\t"<<i+1<<' ';
	   for(j=0;j<9;j++)
	   cout<<grid02[i][j]<<' ';
	  }
	  cout<<"\n\n";
	  cout<<"Actions";
	  cout<<"\n1.Open";
	  cout<<"\n2.Flag";
	  cout<<"\n3.Exit";
	  cout<<"\n\nAction: ";
	  inerr=intnum(action);
	  if(action>3 || action <1 || inerr==1 || inerr==2)
	  	goto start2;
	  if(action==1)
	  {
	   actionerr21:
	   cout<<"\nEnter\n";
	   cout<<"-Row: ";
	   inerr=intnum(x);
	   if(inerr==1 || inerr==2 || x>9 || x<1)
	   	goto actionerr21;
	   cout<<"-Column: ";
	   inerr=intnum(y);
	   if(inerr==1 || inerr==2 || y>9 || y<1)
	   	goto actionerr21;
	   open();
	  }
	  else
	  if(action==2)
	  {
	   actionerr22:
	   cout<<"\nEnter\n";
	   cout<<"-Row: ";
	   inerr=intnum(x);
	   if(inerr==1 || inerr==2 || x>9 || x<1)
	   	goto actionerr22;
	   cout<<"-Column: ";
	   inerr=intnum(y);
	   if(inerr==1 || inerr==2 || y>9 || y<1)
	   	goto actionerr22;
	   grid02[x-1][y-1]='F';
	  }
	  else
	  if(action==3)
	  {
	   clrscr();
	   cout<<"Thank you for playing my game.";
	   cout<<"\n\nMade By: Sudhanshu Gupta";
	   cout<<"\n\nPress any key to continue...";
	   getch();
	   return;
	  }
	  check();
	  if(flag==1)
	  {
	   dispbomb();
	   clrscr();
	   cout<<"\t\t\t\tCMD Minesweeper\n";
	   cout<<"\n\t  ";
	   for(i=0;i<9;i++)
	   cout<<i+1<<' ';
	   for(i=0;i<9;i++)
	   {
	    cout<<"\n\t"<<i+1<<' ';
	    for(j=0;j<9;j++)
	    cout<<grid02[i][j]<<' ';
	   }
	   cout<<"\n\nOh snap! You lost the game. Better luck next time";
	   cout<<"\n\nPress any key to continue.";
	   getch();
	   restarterr21:
	   clrscr();
	   cout<<"Would you like to play again (Y/N): ";
	   cin>>restart;
	   if(restart=='Y' || restart=='y')
	   goto startgame;
	   else
	   if(restart=='N' || restart=='n')
	   {
	    clrscr();
	    cout<<"Thank you for playing my game.";
	    cout<<"\n\nMade By: Sudhanshu Gupta";
	    cout<<"\n\nPress any key to continue...";
	    getch();
	    return;
	   }
	   else
	   goto restarterr21;
	  }
	  if(flag==2)
	  {
	   clrscr();
	   cout<<"\t\t\t\tCMD Minesweeper\n";
	   cout<<"\n\t  ";
	   for(i=0;i<9;i++)
	   cout<<i+1<<' ';
	   for(i=0;i<9;i++)
	   {
	    cout<<"\n\t"<<i+1<<' ';
	    for(j=0;j<9;j++)
	    cout<<grid02[i][j]<<' ';
	   }
	   cout<<"\n\nCongratulations! You won the game.";
	   cout<<"\n\nPress any key to continue.";
	   getch();
	   restarterr22:
	   clrscr();
	   cout<<"\n\nWould you like to play again (Y/N): ";
	   cin>>restart;
	   if(restart=='Y' || restart=='y')
	   goto startgame;
	   else
	   if(restart=='N' || restart=='n')
	   {
	    clrscr();
	    cout<<"Thank you for playing my game.";
	    cout<<"\n\nMade By: Sudhanshu Gupta";
	    cout<<"\n\nPress any key to continue...";
	    getch();
	    return;
	   }
	   else
	   goto restarterr22;
	  }
	  else
	  goto start2;
	 }
  case 3:
     starterr3:
	 clrscr();
	 cout<<"\t\t\t\tCMD Minesweeper\n";
	 cout<<"\n\t  ";
	 for(i=0;i<12;i++)
	 cout<<i+1<<' ';
	 for(i=0;i<12;i++)
	 {
	  if(i<9)
	  {
	   cout<<"\n\t"<<i+1<<"  ";
	   for(j=0;j<12;j++)
	   cout<<"0 ";
	  }
	  else
	  {
	   cout<<"\n\t"<<i+1<<' ';
	   for(j=0;j<12;j++)
	   cout<<"0 ";
	  }
	 }
	 cout<<"\n\nEnter the\n";
	 cout<<"-Row: ";
	 inerr=intnum(x);
	 if(inerr==1 || inerr==2 || x>12 || x<1)
	  goto starterr3;
	 cout<<"-Column: ";
	 inerr=intnum(y);
	 if(inerr==1 || inerr==2 || y>12 || y<1)
	  goto starterr3;
	 ex=x;
	 ey=y;
	 generator();
	 grid03[x-1][y-1]=grid3[x-1][y-1];
	 for(i=0;i<12;i++)
	 chkblank();
	 while(flag==0)
	 {
	  start3:
	  clrscr();
	  cout<<"\t\t\t\tCMD Minesweeper\n";
	  cout<<"\n\t  ";
	  for(i=0;i<12;i++)
	  cout<<i+1<<' ';
	  for(i=0;i<12;i++)
	  {
	   if(i<9)
	   {
	    cout<<"\n\t"<<i+1<<"  ";
	    for(j=0;j<12;j++)
	    cout<<grid03[i][j]<<' ';
	   }
	   else
	   {
	    cout<<"\n\t"<<i+1<<' ';
	    for(j=0;j<12;j++)
	    cout<<grid03[i][j]<<' ';
	   }
	  }
	  cout<<"\n\n";
	  cout<<"Actions";
	  cout<<"\n1.Open";
	  cout<<"\n2.Flag";
	  cout<<"\n3.Exit";
	  cout<<"\n\nAction: ";
	  inerr=intnum(action);
	  if(action>3 || action<1 || inerr==1 || inerr==2)
	  	goto start3;
	  if(action==1)
	  {
	   actionerr31:
	   cout<<"\nEnter\n";
	   cout<<"-Row: ";
	   inerr=intnum(x);
	   if(inerr==1 || inerr==2 || x>12 || x<1)
	   	goto actionerr31;
	   cout<<"-Column: ";
	   inerr=intnum(y);
	   if(inerr==1 || inerr==2 || y>12 || y<1)
	   	goto actionerr31;
	   open();
	  }
	  else
	  if(action==2)
	  {
	   actionerr32:
	   cout<<"\nEnter\n";
	   cout<<"-Row: ";
	   inerr=intnum(x);
	   if(inerr==1 || inerr==2 || x>12 || x<1)
	   	goto actionerr32;
	   cout<<"-Column: ";
	   inerr=intnum(y);
	   if(inerr==1 || inerr==2 || y>12 || y<1)
	   	goto actionerr32;
	   grid03[x-1][y-1]='F';
	  }
	  else
	  if(action==3)
	  {
	   clrscr();
	   cout<<"Thank you for playing my game.";
	   cout<<"\n\nMade By: Sudhanshu Gupta";
	   cout<<"\n\nPress any key to continue...";
	   getch();
	   return;
	  }
	  check();
	  if(flag==1)
	  {
	   dispbomb();
	   clrscr();
	   cout<<"\t\t\t\tCMD Minesweeper\n";
	   cout<<"\n\t  ";
	   for(i=0;i<12;i++)
	   cout<<i+1<<' ';
	   for(i=0;i<12;i++)
	   {
	    if(i<9)
	    {
	     cout<<"\n\t"<<i+1<<"  ";
	     for(j=0;j<12;j++)
	     cout<<grid03[i][j]<<' ';
	    }
	    else
	    {
	     cout<<"\n\t"<<i+1<<' ';
	     for(j=0;j<12;j++)
	     cout<<grid03[i][j]<<' ';
	    }
	   }
	   cout<<"\n\nOh snap! You lost the game. Better luck next time";
	   cout<<"\n\nPress any key to continue.";
	   getch();
	   restarterr31:
	   clrscr();
	   cout<<"Would you like to play again (Y/N): ";
	   cin>>restart;
	   if(restart=='Y' || restart=='y')
	   goto startgame;
	   else
	   if(restart=='N' || restart=='n')
	   {
	    clrscr();
	    cout<<"Thank you for playing my game.";
	    cout<<"\n\nMade By: Sudhanshu Gupta";
	    cout<<"\n\nPress any key to continue...";
	    getch();
	    return;
	   }
	   else
	   goto restarterr31;
	  }
	  if(flag==2)
	  {
	   clrscr();
	   cout<<"\t\t\t\tCMD Minesweeper\n";
	   cout<<"\n\t  ";
	   for(i=0;i<12;i++)
	   cout<<i+1<<' ';
	   for(i=0;i<12;i++)
	   {
	    if(i<9)
	    {
	     cout<<"\n\t"<<i+1<<"  ";
	     for(j=0;j<12;j++)
	     cout<<grid03[i][j]<<' ';
	    }
	    else
	    {
	     cout<<"\n\t"<<i+1<<' ';
	     for(j=0;j<12;j++)
	     cout<<grid03[i][j]<<' ';
	    }
	   }
	   cout<<"\n\nCongratulations! You won the game.";
	   cout<<"\n\nPress any key to continue.";
	   getch();
	   restarterr32:
	   clrscr();
	   cout<<"\n\nWould you like to play again (Y/N): ";
	   cin>>restart;
	   if(restart=='Y' || restart=='y')
	   goto startgame;
	   else
	   if(restart=='N' || restart=='n')
	   {
	    clrscr();
	    cout<<"Thank you for playing my game.";
	    cout<<"\n\nMade By: Sudhanshu Gupta";
	    cout<<"\n\nPress any key to continue...";
	    getch();
	    return;
	   }
	   else
	   goto restarterr32;
	  }
	  else
	  goto start3;
	 }
  case 4:
     starterr4:
	 clrscr();
	 cout<<"\t\t\t\tCMD Minesweeper\n";
	 cout<<"\n\t  ";
	 for(i=0;i<16;i++)
	 cout<<i+1<<' ';
	 for(i=0;i<16;i++)
	 {
	  if(i<9)
	   {
	    cout<<"\n\t"<<i+1<<"  ";
	    for(j=0;j<16;j++)
	    cout<<"0 ";
	   }
	   else
	   {
	    cout<<"\n\t"<<i+1<<' ';
	    for(j=0;j<16;j++)
	    cout<<"0 ";
	   }
	 }
	 cout<<"\n\nEnter the\n";
	 cout<<"-Row: ";
	 inerr=intnum(x);
	 if(inerr==1 || inerr==2 || x>16 || x<1)
	  goto starterr4;
	 cout<<"-Column: ";
	 inerr=intnum(y);
	 if(inerr==1 || inerr==2 || y>16 || y<1)
	  goto starterr4;
	 ex=x;
	 ey=y;
	 generator();
	 grid04[x-1][y-1]=grid4[x-1][y-1];
	 for(i=0;i<16;i++)
	 chkblank();
	 while(flag==0)
	 {
	  start4:
	  clrscr();
	  cout<<"\t\t\t\tCMD Minesweeper\n";
	  cout<<"\n\t  ";
	  for(i=0;i<16;i++)
	  cout<<i+1<<' ';
	  for(i=0;i<16;i++)
	  {
	   if(i<9)
	   {
	    cout<<"\n\t"<<i+1<<"  ";
	    for(j=0;j<16;j++)
	    cout<<grid04[i][j]<<' ';
	   }
	   else
	   {
	    cout<<"\n\t"<<i+1<<' ';
	    for(j=0;j<16;j++)
	    cout<<grid04[i][j]<<' ';
	   }
	  }
	  cout<<"\n\n";
	  cout<<"Actions";
	  cout<<"\n1.Open";
	  cout<<"\n2.Flag";
	  cout<<"\n3.Exit";
	  cout<<"\n\nAction: ";
	  inerr=intnum(action);
	  if(action>3 || action<1 || inerr==1 || inerr==2)
	  	goto start4;
	  if(action==1)
	  {
	   actionerr41:
	   cout<<"\nEnter\n";
	   cout<<"-Row: ";
	   inerr=intnum(x);
	   if(inerr==1 || inerr==2 || x>16 || x<1)
	   	goto actionerr41;
	   cout<<"-Column: ";
	   inerr=intnum(y);
	   if(inerr==1 || inerr==2 || y>16 || y<1)
	   	goto actionerr41;
	   open();
	  }
	  else
	  if(action==2)
	  {
	   actionerr42:
	   cout<<"\nEnter\n";
	   cout<<"-Row: ";
	   inerr=intnum(x);
	   if(inerr==1 || inerr==2 || x>16 || x<1)
	   	goto actionerr42;
	   cout<<"-Column: ";
	   inerr=intnum(y);
	   if(inerr==1 || inerr==2 || y>16 || y<1)
	   	goto actionerr42;
	   grid04[x-1][y-1]='F';
	  }
	  else
	  if(action==3)
	  {
	   clrscr();
	   cout<<"Thank you for playing my game.";
	   cout<<"\n\nMade By: Sudhanshu Gupta";
	   cout<<"\n\nPress any key to continue...";
	   getch();
	   return;
	  }
	  check();
	  if(flag==1)
	  {
	   dispbomb();
	   clrscr();
	   cout<<"\t\t\t\tCMD Minesweeper\n";
	   cout<<"\n\t  ";
	   for(i=0;i<16;i++)
	   cout<<i+1<<' ';
	   for(i=0;i<16;i++)
	   {
	    if(i<9)
	    {
	     cout<<"\n\t"<<i+1<<"  ";
	     for(j=0;j<16;j++)
	     cout<<grid04[i][j]<<' ';
	    }
	    else
	    {
	     cout<<"\n\t"<<i+1<<' ';
	     for(j=0;j<16;j++)
	     cout<<grid04[i][j]<<' ';
	    }
	   }
	   cout<<"\n\nOh snap! You lost the game. Better luck next time";
	   cout<<"\n\nPress any key to continue.";
	   getch();
	   restarterr41:
	   clrscr();
	   cout<<"Would you like to play again (Y/N): ";
	   cin>>restart;
	   if(restart=='Y' || restart=='y')
	   goto startgame;
	   else
	   if(restart=='N' || restart=='n')
	   {
	    clrscr();
	    cout<<"Thank you for playing my game.";
	    cout<<"\n\nMade By: Sudhanshu Gupta";
	    cout<<"\n\nPress any key to continue...";
	    getch();
	    return;
	   }
	   else
	   goto restarterr41;
	  }
	  if(flag==2)
	  {
	   clrscr();
	   cout<<"\t\t\t\tCMD Minesweeper\n";
	   cout<<"\n\t  ";
	   for(i=0;i<16;i++)
	   cout<<i+1<<' ';
	   for(i=0;i<16;i++)
	   {
	    if(i<9)
	    {
	     cout<<"\n\t"<<i+1<<"  ";
	     for(j=0;j<12;j++)
	     cout<<grid04[i][j]<<' ';
	    }
	    else
	    {
	     cout<<"\n\t"<<i+1<<' ';
	     for(j=0;j<12;j++)
	     cout<<grid04[i][j]<<' ';
	    }
	   }
	   cout<<"\n\nCongratulations! You won the game.";
	   cout<<"\n\nPress any key to continue.";
	   getch();
	   restarterr42:
	   clrscr();
	   cout<<"\n\nWould you like to play again (Y/N): ";
	   cin>>restart;
	   if(restart=='Y' || restart=='y')
	   goto startgame;
	   else
	   if(restart=='N' || restart=='n')
	   {
	    clrscr();
	    cout<<"Thank you for playing my game.";
	    cout<<"\n\nMade By: Sudhanshu Gupta";
	    cout<<"\n\nPress any key to continue...";
	    getch();
	    return;
	   }
	   else
	   goto restarterr42;
	  }
	  else
	  goto start4;
	 }
 }
}
void dispbomb()
{
 switch(diff)
 {
  case 1:for(i=0;i<7;i++)
	 {
	  for(j=0;j<7;j++)
	  {
	   if(grid1[i][j]=='*')
	   grid01[i][j]=grid1[i][j];
	  }
	 }
	 return;
  case 2:for(i=0;i<9;i++)
	 {
	  for(j=0;j<9;j++)
	  {
	   if(grid2[i][j]=='*')
	   grid02[i][j]=grid2[i][j];
	  }
	 }
	 return;
  case 3:for(i=0;i<12;i++)
	 {
	  for(j=0;j<12;j++)
	  {
	   if(grid3[i][j]=='*')
	   grid03[i][j]=grid3[i][j];
	  }
	 }
	 return;
  case 4:for(i=0;i<16;i++)
	 {
	  for(j=0;j<16;j++)
	  {
	   if(grid4[i][j]=='*')
	   grid04[i][j]=grid4[i][j];
	  }
	 }
	 return;
 }
}
void open()
{
 void chkblank(void);
 switch(diff)
 {
  case 1:grid01[x-1][y-1]=grid1[x-1][y-1];
	 if(grid01[x-1][y-1]=='*')
	 return;
	 else
	 {
	  for(i=0;i<7;i++)
	  chkblank();
	  return;
	 }
  case 2:grid02[x-1][y-1]=grid2[x-1][y-1];
	 if(grid02[x-1][y-1]=='*')
	 return;
	 else
	 {
	  for(i=0;i<9;i++)
	  chkblank();
	  return;
	 }
  case 3:grid03[x-1][y-1]=grid3[x-1][y-1];
	 if(grid03[x-1][y-1]=='*')
	 return;
	 else
	 {
	  for(i=0;i<12;i++)
	  chkblank();
	  return;
	 }
  case 4:grid04[x-1][y-1]=grid4[x-1][y-1];
	 if(grid04[x-1][y-1]=='*')
	 return;
	 else
	 {
	  for(i=0;i<16;i++)
	  chkblank();
	  return;
	 }
 }
}
void check()
{
 switch(diff)
 {
  case 1:win=0;
	 for(i=0;i<7;i++)
	 {
	  for(j=0;j<7;j++)
	  {
	   if(grid01[i][j]=='*')
	   {
	    flag=1;
	    return;
	   }
	  }
	 }
	 for(i=0;i<7;i++)
	 {
	  for(j=0;j<7;j++)
	  {
	   if(grid1[i][j]!='*')
	   {
	    if(grid01[i][j]==grid1[i][j])
	    win++;
	   }
	  }
	 }
	 if(win==44)
	 flag=2;
	 return;
  case 2:win=0;
	 for(i=0;i<9;i++)
	 {
	  for(j=0;j<9;j++)
	  {
	   if(grid02[i][j]=='*')
	   {
	    flag=1;
	    return;
	   }
	  }
	 }
	 for(i=0;i<9;i++)
	 {
	  for(j=0;j<9;j++)
	  {
	   if(grid2[i][j]!='*')
	   {
	    if(grid02[i][j]==grid2[i][j])
	    win++;
	   }
	  }
	 }
	 if(win==71)
	 flag=2;
	 return;
  case 3:win=0;
	 for(i=0;i<12;i++)
	 {
	  for(j=0;j<12;j++)
	  {
	   if(grid03[i][j]=='*')
	   {
	    flag=1;
	    return;
	   }
	  }
	 }
	 for(i=0;i<12;i++)
	 {
	  for(j=0;j<12;j++)
	  {
	   if(grid3[i][j]!='*')
	   {
	    if(grid03[i][j]==grid3[i][j])
	    win++;
	   }
	  }
	 }
	 if(win==120)
	 flag=2;
	 return;
  case 4:win=0;
	 for(i=0;i<16;i++)
	 {
	  for(j=0;j<16;j++)
	  {
	   if(grid04[i][j]=='*')
	   {
	    flag=1;
	    return;
	   }
	  }
	 }
	 for(i=0;i<16;i++)
	 {
	  for(j=0;j<16;j++)
	  {
	   if(grid4[i][j]!='*')
	   {
	    if(grid04[i][j]==grid4[i][j])
	    win++;
	   }
	  }
	 }
	 if(win==196)
	 flag=2;
	 return;
 }
}
void chkblank()
{
 switch(diff)
 {
  case 1:for(x=0;x<7;x++)
	 {
	  for(y=0;y<7;y++)
	  {
	   if(grid01[x][y]==' ')
	   {
	    if((x!=0 && y!=0) || (x!=6 && y!=6))
	    {
	     if(grid1[x-1][y-1]!='*')
	     grid01[x-1][y-1]=grid1[x-1][y-1];
	     if(grid1[x-1][y]!='*')
	     grid01[x-1][y]=grid1[x-1][y];
	     if(grid1[x-1][y+1]!='*')
	     grid01[x-1][y+1]=grid1[x-1][y+1];
	     if(grid1[x][y-1]!='*')
	     grid01[x][y-1]=grid1[x][y-1];
	     if(grid1[x][y+1]!='*')
	     grid01[x][y+1]=grid1[x][y+1];
	     if(grid1[x+1][y-1]!='*')
	     grid01[x+1][y-1]=grid1[x+1][y-1];
	     if(grid1[x+1][y]!='*')
	     grid01[x+1][y]=grid1[x+1][y];
	     if(grid1[x+1][y+1]!='*')
	     grid01[x+1][y+1]=grid1[x+1][y+1];
	    }
	    else
	    if(x==0 && y>0 && y<6)
	    {
	     if(grid1[x][y-1]!='*')
	     grid01[x][y-1]=grid1[x][y-1];
	     if(grid1[x+1][y-1]!='*')
	     grid01[x+1][y-1]=grid1[x+1][y-1];
	     if(grid1[x+1][y]!='*')
	     grid01[x+1][y]=grid1[x+1][y];
	     if(grid1[x+1][y+1]!='*')
	     grid01[x+1][y+1]=grid1[x+1][y+1];
	     if(grid1[x][y+1]!='*')
	     grid01[x][y+1]=grid1[x][y+1];
	    }
	    else
	    if(x==6 && y>0 && y<6)
	    {
	     if(grid1[x][y-1]!='*')
	     grid01[x][y-1]=grid1[x][y-1];
	     if(grid1[x-1][y-1]!='*')
	     grid01[x-1][y-1]=grid1[x-1][y-1];
	     if(grid1[x-1][y]!='*')
	     grid01[x-1][y]=grid1[x-1][y];
	     if(grid1[x-1][y+1]!='*')
	     grid01[x-1][y+1]=grid1[x-1][y+1];
	     if(grid1[x][y+1]!='*')
	     grid01[x][y+1]=grid1[x][y+1];
	    }
	    else
	    if(y==0 && x>0 && x<6)
	    {
	     if(grid1[x-1][y]!='*')
	     grid01[x-1][y]=grid1[x-1][y];
	     if(grid1[x-1][y+1]!='*')
	     grid01[x-1][y+1]=grid1[x-1][y+1];
	     if(grid1[x][y+1]!='*')
	     grid01[x][y+1]=grid1[x][y+1];
	     if(grid1[x+1][y+1]!='*')
	     grid01[x+1][y+1]=grid1[x+1][y+1];
	     if(grid1[x+1][y]!='*')
	     grid01[x+1][y]=grid1[x+1][y];
	    }
	    else
	    if(y==6 && x>0 && x<6)
	    {
	     if(grid1[x-1][y]!='*')
	     grid01[x-1][y]=grid1[x-1][y];
	     if(grid1[x-1][y-1]!='*')
	     grid01[x-1][y-1]=grid1[x-1][y-1];
	     if(grid1[x][y-1]!='*')
	     grid01[x][y-1]=grid1[x][y-1];
	     if(grid1[x+1][y-1]!='*')
	     grid01[x+1][y-1]=grid1[x+1][y-1];
	     if(grid1[x+1][y]!='*')
	     grid01[x+1][y]=grid1[x+1][y];
	    }
	    else
	    if(x==0 && y==0)
	    {
	     if(grid1[x][y+1]!='*')
	     grid01[x][y+1]=grid1[x][y+1];
	     if(grid1[x+1][y+1]!='*')
	     grid01[x+1][y+1]=grid1[x+1][y+1];
	     if(grid1[x+1][y]!='*')
	     grid01[x+1][y]=grid1[x+1][y];
	    }
	    else
	    if(x==0 && y==6)
	    {
	     if(grid1[x][y-1]!='*')
	     grid01[x][y-1]=grid1[x][y-1];
	     if(grid1[x+1][y-1]!='*')
	     grid01[x+1][y-1]=grid1[x+1][y-1];
	     if(grid1[x+1][y]!='*')
	     grid01[x+1][y]=grid1[x+1][y];
	    }
	    else
	    if(x==6 && y==0)
	    {
	     if(grid1[x-1][y]!='*')
	     grid01[x-1][y]=grid1[x-1][y];
	     if(grid1[x-1][y+1]!='*')
	     grid01[x-1][y+1]=grid1[x-1][y+1];
	     if(grid1[x][y+1]!='*')
	     grid01[x][y+1]=grid1[x][y+1];
	    }
	    else
	    if(x==6 && y==6)
	    {
	     if(grid1[x-1][y]!='*')
	     grid01[x-1][y]=grid1[x-1][y];
	     if(grid1[x-1][y-1]!='*')
	     grid01[x-1][y-1]=grid1[x-1][y-1];
	     if(grid1[x][y-1]!='*')
	     grid01[x][y-1]=grid1[x][y-1];
	    }
	   }
	  }
	 }
	 return;
  case 2:for(x=0;x<9;x++)
	 {
	  for(y=0;y<9;y++)
	  {
	   if(grid02[x][y]==' ')
	   {
	    if((x!=0 && y!=0) || (x!=8 && y!=8))
	    {
	     if(grid2[x-1][y-1]!='*')
	     grid02[x-1][y-1]=grid2[x-1][y-1];
	     if(grid2[x-1][y]!='*')
	     grid02[x-1][y]=grid2[x-1][y];
	     if(grid2[x-1][y+1]!='*')
	     grid02[x-1][y+1]=grid2[x-1][y+1];
	     if(grid2[x][y-1]!='*')
	     grid02[x][y-1]=grid2[x][y-1];
	     if(grid2[x][y+1]!='*')
	     grid02[x][y+1]=grid2[x][y+1];
	     if(grid2[x+1][y-1]!='*')
	     grid02[x+1][y-1]=grid2[x+1][y-1];
	     if(grid2[x+1][y]!='*')
	     grid02[x+1][y]=grid2[x+1][y];
	     if(grid2[x+1][y+1]!='*')
	     grid02[x+1][y+1]=grid2[x+1][y+1];
	    }
	    else
	    if(x==0 && y>0 && y<8)
	    {
	     if(grid2[x][y-1]!='*')
	     grid02[x][y-1]=grid2[x][y-1];
	     if(grid2[x+1][y-1]!='*')
	     grid02[x+1][y-1]=grid2[x+1][y-1];
	     if(grid2[x+1][y]!='*')
	     grid02[x+1][y]=grid2[x+1][y];
	     if(grid2[x+1][y+1]!='*')
	     grid02[x+1][y+1]=grid2[x+1][y+1];
	     if(grid2[x][y+1]!='*')
	     grid02[x][y+1]=grid2[x][y+1];
	    }
	    else
	    if(x==8 && y>0 && y<8)
	    {
	     if(grid2[x][y-1]!='*')
	     grid02[x][y-1]=grid2[x][y-1];
	     if(grid2[x-1][y-1]!='*')
	     grid02[x-1][y-1]=grid2[x-1][y-1];
	     if(grid2[x-1][y]!='*')
	     grid02[x-1][y]=grid2[x-1][y];
	     if(grid2[x-1][y+1]!='*')
	     grid02[x-1][y+1]=grid2[x-1][y+1];
	     if(grid2[x][y+1]!='*')
	     grid02[x][y+1]=grid2[x][y+1];
	    }
	    else
	    if(y==0 && x>0 && x<8)
	    {
	     if(grid2[x-1][y]!='*')
	     grid02[x-1][y]=grid2[x-1][y];
	     if(grid2[x-1][y+1]!='*')
	     grid02[x-1][y+1]=grid2[x-1][y+1];
	     if(grid2[x][y+1]!='*')
	     grid02[x][y+1]=grid2[x][y+1];
	     if(grid2[x+1][y+1]!='*')
	     grid02[x+1][y+1]=grid2[x+1][y+1];
	     if(grid2[x+1][y]!='*')
	     grid02[x+1][y]=grid2[x+1][y];
	    }
	    else
	    if(y==8 && x>0 && x<8)
	    {
	     if(grid2[x-1][y]!='*')
	     grid02[x-1][y]=grid2[x-1][y];
	     if(grid2[x-1][y-1]!='*')
	     grid02[x-1][y-1]=grid2[x-1][y-1];
	     if(grid2[x][y-1]!='*')
	     grid02[x][y-1]=grid2[x][y-1];
	     if(grid2[x+1][y-1]!='*')
	     grid02[x+1][y-1]=grid2[x+1][y-1];
	     if(grid2[x+1][y]!='*')
	     grid02[x+1][y]=grid2[x+1][y];
	    }
	    else
	    if(x==0 && y==0)
	    {
	     if(grid2[x][y+1]!='*')
	     grid02[x][y+1]=grid2[x][y+1];
	     if(grid2[x+1][y+1]!='*')
	     grid02[x+1][y+1]=grid2[x+1][y+1];
	     if(grid2[x+1][y]!='*')
	     grid02[x+1][y]=grid2[x+1][y];
	    }
	    else
	    if(x==0 && y==8)
	    {
	     if(grid2[x][y-1]!='*')
	     grid02[x][y-1]=grid2[x][y-1];
	     if(grid2[x+1][y-1]!='*')
	     grid02[x+1][y-1]=grid2[x+1][y-1];
	     if(grid2[x+1][y]!='*')
	     grid02[x+1][y]=grid2[x+1][y];
	    }
	    else
	    if(x==8 && y==0)
	    {
	     if(grid2[x-1][y]!='*')
	     grid02[x-1][y]=grid2[x-1][y];
	     if(grid2[x-1][y+1]!='*')
	     grid02[x-1][y+1]=grid2[x-1][y+1];
	     if(grid2[x][y+1]!='*')
	     grid02[x][y+1]=grid2[x][y+1];
	    }
	    else
	    if(x==8 && y==8)
	    {
	     if(grid2[x-1][y]!='*')
	     grid02[x-1][y]=grid2[x-1][y];
	     if(grid2[x-1][y-1]!='*')
	     grid02[x-1][y-1]=grid2[x-1][y-1];
	     if(grid2[x][y-1]!='*')
	     grid02[x][y-1]=grid2[x][y-1];
	    }
	   }
	  }
	 }
	 return;
  case 3:for(x=0;x<12;x++)
	 {
	  for(y=0;y<12;y++)
	  {
	   if(grid03[x][y]==' ')
	   {
	    if((x!=0 && y!=0) || (x!=11 && y!=11))
	    {
	     if(grid3[x-1][y-1]!='*')
	     grid03[x-1][y-1]=grid3[x-1][y-1];
	     if(grid3[x-1][y]!='*')
	     grid03[x-1][y]=grid3[x-1][y];
	     if(grid3[x-1][y+1]!='*')
	     grid03[x-1][y+1]=grid3[x-1][y+1];
	     if(grid3[x][y-1]!='*')
	     grid03[x][y-1]=grid3[x][y-1];
	     if(grid3[x][y+1]!='*')
	     grid03[x][y+1]=grid3[x][y+1];
	     if(grid3[x+1][y-1]!='*')
	     grid03[x+1][y-1]=grid3[x+1][y-1];
	     if(grid3[x+1][y]!='*')
	     grid03[x+1][y]=grid3[x+1][y];
	     if(grid3[x+1][y+1]!='*')
	     grid03[x+1][y+1]=grid3[x+1][y+1];
	    }
	    else
	    if(x==0 && y>0 && y<11)
	    {
	     if(grid3[x][y-1]!='*')
	     grid03[x][y-1]=grid3[x][y-1];
	     if(grid3[x+1][y-1]!='*')
	     grid03[x+1][y-1]=grid3[x+1][y-1];
	     if(grid3[x+1][y]!='*')
	     grid03[x+1][y]=grid3[x+1][y];
	     if(grid3[x+1][y+1]!='*')
	     grid03[x+1][y+1]=grid3[x+1][y+1];
	     if(grid3[x][y+1]!='*')
	     grid03[x][y+1]=grid3[x][y+1];
	    }
	    else
	    if(x==11 && y>0 && y<11)
	    {
	     if(grid3[x][y-1]!='*')
	     grid03[x][y-1]=grid3[x][y-1];
	     if(grid3[x-1][y-1]!='*')
	     grid03[x-1][y-1]=grid3[x-1][y-1];
	     if(grid3[x-1][y]!='*')
	     grid03[x-1][y]=grid3[x-1][y];
	     if(grid3[x-1][y+1]!='*')
	     grid03[x-1][y+1]=grid3[x-1][y+1];
	     if(grid3[x][y+1]!='*')
	     grid03[x][y+1]=grid3[x][y+1];
	    }
	    else
	    if(y==0 && x>0 && x<11)
	    {
	     if(grid3[x-1][y]!='*')
	     grid03[x-1][y]=grid3[x-1][y];
	     if(grid3[x-1][y+1]!='*')
	     grid03[x-1][y+1]=grid3[x-1][y+1];
	     if(grid3[x][y+1]!='*')
	     grid03[x][y+1]=grid3[x][y+1];
	     if(grid3[x+1][y+1]!='*')
	     grid03[x+1][y+1]=grid3[x+1][y+1];
	     if(grid3[x+1][y]!='*')
	     grid03[x+1][y]=grid3[x+1][y];
	    }
	    else
	    if(y==11 && x>0 && x<11)
	    {
	     if(grid3[x-1][y]!='*')
	     grid03[x-1][y]=grid3[x-1][y];
	     if(grid3[x-1][y-1]!='*')
	     grid03[x-1][y-1]=grid3[x-1][y-1];
	     if(grid3[x][y-1]!='*')
	     grid03[x][y-1]=grid3[x][y-1];
	     if(grid3[x+1][y-1]!='*')
	     grid03[x+1][y-1]=grid3[x+1][y-1];
	     if(grid3[x+1][y]!='*')
	     grid03[x+1][y]=grid3[x+1][y];
	    }
	    else
	    if(x==0 && y==0)
	    {
	     if(grid3[x][y+1]!='*')
	     grid03[x][y+1]=grid3[x][y+1];
	     if(grid3[x+1][y+1]!='*')
	     grid03[x+1][y+1]=grid3[x+1][y+1];
	     if(grid3[x+1][y]!='*')
	     grid03[x+1][y]=grid3[x+1][y];
	    }
	    else
	    if(x==0 && y==11)
	    {
	     if(grid3[x][y-1]!='*')
	     grid03[x][y-1]=grid3[x][y-1];
	     if(grid3[x+1][y-1]!='*')
	     grid03[x+1][y-1]=grid3[x+1][y-1];
	     if(grid3[x+1][y]!='*')
	     grid03[x+1][y]=grid3[x+1][y];
	    }
	    else
	    if(x==11 && y==0)
	    {
	     if(grid3[x-1][y]!='*')
	     grid03[x-1][y]=grid3[x-1][y];
	     if(grid3[x-1][y+1]!='*')
	     grid03[x-1][y+1]=grid3[x-1][y+1];
	     if(grid3[x][y+1]!='*')
	     grid03[x][y+1]=grid3[x][y+1];
	    }
	    else
	    if(x==11 && y==11)
	    {
	     if(grid3[x-1][y]!='*')
	     grid03[x-1][y]=grid3[x-1][y];
	     if(grid3[x-1][y-1]!='*')
	     grid03[x-1][y-1]=grid3[x-1][y-1];
	     if(grid3[x][y-1]!='*')
	     grid03[x][y-1]=grid3[x][y-1];
	    }
	   }
	  }
	 }
	 return;
  case 4:for(x=0;x<16;x++)
	 {
	  for(y=0;y<16;y++)
	  {
	   if(grid04[x][y]==' ')
	   {
	    if((x!=0 && y!=0) || (x!=15 && y!=15))
	    {
	     if(grid4[x-1][y-1]!='*')
	     grid04[x-1][y-1]=grid4[x-1][y-1];
	     if(grid4[x-1][y]!='*')
	     grid04[x-1][y]=grid4[x-1][y];
	     if(grid4[x-1][y+1]!='*')
	     grid04[x-1][y+1]=grid4[x-1][y+1];
	     if(grid4[x][y-1]!='*')
	     grid04[x][y-1]=grid4[x][y-1];
	     if(grid4[x][y+1]!='*')
	     grid04[x][y+1]=grid4[x][y+1];
	     if(grid4[x+1][y-1]!='*')
	     grid04[x+1][y-1]=grid4[x+1][y-1];
	     if(grid4[x+1][y]!='*')
	     grid04[x+1][y]=grid4[x+1][y];
	     if(grid4[x+1][y+1]!='*')
	     grid04[x+1][y+1]=grid4[x+1][y+1];
	    }
	    else
	    if(x==0 && y>0 && y<15)
	    {
	     if(grid4[x][y-1]!='*')
	     grid04[x][y-1]=grid4[x][y-1];
	     if(grid4[x+1][y-1]!='*')
	     grid04[x+1][y-1]=grid4[x+1][y-1];
	     if(grid4[x+1][y]!='*')
	     grid04[x+1][y]=grid4[x+1][y];
	     if(grid4[x+1][y+1]!='*')
	     grid04[x+1][y+1]=grid4[x+1][y+1];
	     if(grid4[x][y+1]!='*')
	     grid04[x][y+1]=grid4[x][y+1];
	    }
	    else
	    if(x==15 && y>0 && y<15)
	    {
	     if(grid4[x][y-1]!='*')
	     grid04[x][y-1]=grid4[x][y-1];
	     if(grid4[x-1][y-1]!='*')
	     grid04[x-1][y-1]=grid4[x-1][y-1];
	     if(grid4[x-1][y]!='*')
	     grid04[x-1][y]=grid4[x-1][y];
	     if(grid4[x-1][y+1]!='*')
	     grid04[x-1][y+1]=grid4[x-1][y+1];
	     if(grid4[x][y+1]!='*')
	     grid04[x][y+1]=grid4[x][y+1];
	    }
	    else
	    if(y==0 && x>0 && x<15)
	    {
	     if(grid4[x-1][y]!='*')
	     grid04[x-1][y]=grid4[x-1][y];
	     if(grid4[x-1][y+1]!='*')
	     grid04[x-1][y+1]=grid4[x-1][y+1];
	     if(grid4[x][y+1]!='*')
	     grid04[x][y+1]=grid4[x][y+1];
	     if(grid4[x+1][y+1]!='*')
	     grid04[x+1][y+1]=grid4[x+1][y+1];
	     if(grid4[x+1][y]!='*')
	     grid04[x+1][y]=grid4[x+1][y];
	    }
	    else
	    if(y==15 && x>0 && x<15)
	    {
	     if(grid4[x-1][y]!='*')
	     grid04[x-1][y]=grid4[x-1][y];
	     if(grid4[x-1][y-1]!='*')
	     grid04[x-1][y-1]=grid4[x-1][y-1];
	     if(grid4[x][y-1]!='*')
	     grid04[x][y-1]=grid4[x][y-1];
	     if(grid4[x+1][y-1]!='*')
	     grid04[x+1][y-1]=grid4[x+1][y-1];
	     if(grid4[x+1][y]!='*')
	     grid04[x+1][y]=grid4[x+1][y];
	    }
	    else
	    if(x==0 && y==0)
	    {
	     if(grid4[x][y+1]!='*')
	     grid04[x][y+1]=grid4[x][y+1];
	     if(grid4[x+1][y+1]!='*')
	     grid04[x+1][y+1]=grid4[x+1][y+1];
	     if(grid4[x+1][y]!='*')
	     grid04[x+1][y]=grid4[x+1][y];
	    }
	    else
	    if(x==0 && y==15)
	    {
	     if(grid4[x][y-1]!='*')
	     grid04[x][y-1]=grid4[x][y-1];
	     if(grid4[x+1][y-1]!='*')
	     grid04[x+1][y-1]=grid4[x+1][y-1];
	     if(grid4[x+1][y]!='*')
	     grid04[x+1][y]=grid4[x+1][y];
	    }
	    else
	    if(x==15 && y==0)
	    {
	     if(grid4[x-1][y]!='*')
	     grid04[x-1][y]=grid4[x-1][y];
	     if(grid4[x-1][y+1]!='*')
	     grid04[x-1][y+1]=grid4[x-1][y+1];
	     if(grid4[x][y+1]!='*')
	     grid04[x][y+1]=grid4[x][y+1];
	    }
	    else
	    if(x==15 && y==15)
	    {
	     if(grid4[x-1][y]!='*')
	     grid04[x-1][y]=grid4[x-1][y];
	     if(grid4[x-1][y-1]!='*')
	     grid04[x-1][y-1]=grid4[x-1][y-1];
	     if(grid4[x][y-1]!='*')
	     grid04[x][y-1]=grid4[x][y-1];
	    }
	   }
	  }
	 }
	 return;
 }
}
void generator()
{
 switch(diff)
 {
  case 1:for(i=0;i<7;i++)
	 {
	  for(j=0;j<7;j++)
	  grid01[i][j]='0';
	 }
	 for(i=0;i<7;i++)
	 {
	  for(j=0;j<7;j++)
	  grid1[i][j]='0';
	 }
	 nobomb=0;
	 randomize();
	 while(nobomb<5)
	 {
	  bx=random(6-0+1)+0;
	  by=random(6-0+1)+0;
	  if((bx!=(ex-1) && by!=(ey-1)) && grid1[bx][by]!='*')
	  {
	   grid1[bx][by]='*';
	   nobomb++;
	  }
	  else
	  continue;
	 }
	 for(i=0;i<7;i++)
	 {
	  for(j=0;j<7;j++)
	  {
	   if(grid1[i][j]=='*')
	   continue;
	   else
	   {
	    if((i!=0 && j!=0) || (i!=6 && j!=6))
	    {
	     chkbomb='0';
	     if(grid1[i-1][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid1[i-1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(grid1[i-1][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid1[i][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid1[i][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid1[i+1][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid1[i+1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(grid1[i+1][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(chkbomb=='0')
	     grid1[i][j]=' ';
	     else
	     grid1[i][j]=chkbomb;
	    }
	    else
	    if(i==0 && j>0 && j<6)
	    {
	     chkbomb='0';
	     if(grid1[i][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid1[i+1][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid1[i+1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(grid1[i+1][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid1[i][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(chkbomb=='0')
	     grid1[i][j]=' ';
	     else
	     grid1[i][j]=chkbomb;
	    }
	    else
	    if(i==6 && j>0 && j<6)
	    {
	     chkbomb='0';
	     if(grid1[i][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid1[i-1][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid1[i-1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(grid1[i-1][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid1[i][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(chkbomb=='0')
	     grid1[i][j]=' ';
	     else
	     grid1[i][j]=chkbomb;
	    }
	    if(j==0 && i>0 && i<6)
	    {
	     chkbomb='0';
	     if(grid1[i-1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(grid1[i-1][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid1[i][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid1[i+1][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid1[i+1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(chkbomb=='0')
	     grid1[i][j]=' ';
	     else
	     grid1[i][j]=chkbomb;
	    }
	    else
	    if(j==6 && i>0 && i<6)
	    {
	     chkbomb='0';
	     if(grid1[i-1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(grid1[i-1][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid1[i][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid1[i+1][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid1[i+1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(chkbomb=='0')
	     grid1[i][j]=' ';
	     else
	     grid1[i][j]=chkbomb;
	    }
	    if(i==0 && j==0)
	    {
	     chkbomb='0';
	     if(grid1[i][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid1[i+1][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid1[i+1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(chkbomb=='0')
	     grid1[i][j]=' ';
	     else
	     grid1[i][j]=chkbomb;
	    }
	    if(i==0 && j==6)
	    {
	     chkbomb='0';
	     if(grid1[i][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid1[i+1][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid1[i+1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(chkbomb=='0')
	     grid1[i][j]=' ';
	     else
	     grid1[i][j]=chkbomb;
	    }
	    if(i==6 && j==0)
	    {
	     chkbomb='0';
	     if(grid1[i-1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(grid1[i-1][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid1[i][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(chkbomb=='0')
	     grid1[i][j]=' ';
	     else
	     grid1[i][j]=chkbomb;
	    }
	    if(i==6 && j==6)
	    {
	     chkbomb='0';
	     if(grid1[i-1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(grid1[i-1][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid1[i][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(chkbomb=='0')
	     grid1[i][j]=' ';
	     else
	     grid1[i][j]=chkbomb;
	    }
	   }
	  }
	 }
  case 2:for(i=0;i<9;i++)
	 {
	  for(j=0;j<9;j++)
	  grid02[i][j]='0';
	 }
	 for(i=0;i<9;i++)
	 {
	  for(j=0;j<9;j++)
	  grid2[i][j]='0';
	 }
	 nobomb=0;
	 randomize();
	 while(nobomb<10)
	 {
	  bx=random(8-0+1)+0;
	  by=random(8-0+1)+0;
	  if((bx!=(ex-1) && by!=(ey-1)) && grid2[bx][by]!='*')
	  {
	   grid2[bx][by]='*';
	   nobomb++;
	  }
	  else
	  continue;
	 }
	 for(i=0;i<9;i++)
	 {
	  for(j=0;j<9;j++)
	  {
	   if(grid2[i][j]=='*')
	   continue;
	   else
	   {
	    if((i!=0 && j!=0) || (i!=8 && j!=8))
	    {
	     chkbomb='0';
	     if(grid2[i-1][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid2[i-1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(grid2[i-1][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid2[i][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid2[i][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid2[i+1][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid2[i+1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(grid2[i+1][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(chkbomb=='0')
	     grid2[i][j]=' ';
	     else
	     grid2[i][j]=chkbomb;
	    }
	    else
	    if(i==0 && j>0 && j<8)
	    {
	     chkbomb='0';
	     if(grid2[i][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid2[i+1][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid2[i+1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(grid2[i+1][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid2[i][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(chkbomb=='0')
	     grid2[i][j]=' ';
	     else
	     grid2[i][j]=chkbomb;
	    }
	    else
	    if(i==8 && j>0 && j<8)
	    {
	     chkbomb='0';
	     if(grid2[i][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid2[i-1][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid2[i-1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(grid2[i-1][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid2[i][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(chkbomb=='0')
	     grid2[i][j]=' ';
	     else
	     grid2[i][j]=chkbomb;
	    }
	    if(j==0 && i>0 && i<8)
	    {
	     chkbomb='0';
	     if(grid2[i-1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(grid2[i-1][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid2[i][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid2[i+1][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid2[i+1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(chkbomb=='0')
	     grid2[i][j]=' ';
	     else
	     grid2[i][j]=chkbomb;
	    }
	    else
	    if(j==8 && i>0 && i<8)
	    {
	     chkbomb='0';
	     if(grid2[i-1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(grid2[i-1][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid2[i][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid2[i+1][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid2[i+1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(chkbomb=='0')
	     grid2[i][j]=' ';
	     else
	     grid2[i][j]=chkbomb;
	    }
	    if(i==0 && j==0)
	    {
	     chkbomb='0';
	     if(grid2[i][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid2[i+1][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid2[i+1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(chkbomb=='0')
	     grid2[i][j]=' ';
	     else
	     grid2[i][j]=chkbomb;
	    }
	    if(i==0 && j==8)
	    {
	     chkbomb='0';
	     if(grid2[i][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid2[i+1][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid2[i+1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(chkbomb=='0')
	     grid2[i][j]=' ';
	     else
	     grid2[i][j]=chkbomb;
	    }
	    if(i==8 && j==0)
	    {
	     chkbomb='0';
	     if(grid2[i-1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(grid2[i-1][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid2[i][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(chkbomb=='0')
	     grid2[i][j]=' ';
	     else
	     grid2[i][j]=chkbomb;
	    }
	    if(i==8 && j==8)
	    {
	     chkbomb='0';
	     if(grid2[i-1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(grid2[i-1][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid2[i][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(chkbomb=='0')
	     grid2[i][j]=' ';
	     else
	     grid2[i][j]=chkbomb;
	    }
	   }
	  }
	 }
  case 3:for(i=0;i<12;i++)
	 {
	  for(j=0;j<12;j++)
	  grid03[i][j]='0';
	 }
	 for(i=0;i<12;i++)
	 {
	  for(j=0;j<12;j++)
	  grid3[i][j]='0';
	 }
	 nobomb=0;
	 randomize();
	 while(nobomb<24)
	 {
	  bx=random(11-0+1)+0;
	  by=random(11-0+1)+0;
	  if((bx!=(ex-1) && by!=(ey-1)) && grid3[bx][by]!='*')
	  {
	   grid3[bx][by]='*';
	   nobomb++;
	  }
	  else
	  continue;
	 }
	 for(i=0;i<12;i++)
	 {
	  for(j=0;j<12;j++)
	  {
	   if(grid3[i][j]=='*')
	   continue;
	   else
	   {
	    if((i!=0 && j!=0) || (i!=11 && j!=11))
	    {
	     chkbomb='0';
	     if(grid3[i-1][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid3[i-1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(grid3[i-1][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid3[i][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid3[i][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid3[i+1][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid3[i+1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(grid3[i+1][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(chkbomb=='0')
	     grid3[i][j]=' ';
	     else
	     grid3[i][j]=chkbomb;
	    }
	    else
	    if(i==0 && j>0 && j<11)
	    {
	     chkbomb='0';
	     if(grid3[i][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid3[i+1][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid3[i+1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(grid3[i+1][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid3[i][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(chkbomb=='0')
	     grid3[i][j]=' ';
	     else
	     grid3[i][j]=chkbomb;
	    }
	    else
	    if(i==11 && j>0 && j<11)
	    {
	     chkbomb='0';
	     if(grid3[i][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid3[i-1][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid3[i-1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(grid3[i-1][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid3[i][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(chkbomb=='0')
	     grid3[i][j]=' ';
	     else
	     grid3[i][j]=chkbomb;
	    }
	    if(j==0 && i>0 && i<11)
	    {
	     chkbomb='0';
	     if(grid3[i-1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(grid3[i-1][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid3[i][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid3[i+1][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid3[i+1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(chkbomb=='0')
	     grid3[i][j]=' ';
	     else
	     grid3[i][j]=chkbomb;
	    }
	    else
	    if(j==11 && i>0 && i<11)
	    {
	     chkbomb='0';
	     if(grid3[i-1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(grid3[i-1][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid3[i][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid3[i+1][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid3[i+1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(chkbomb=='0')
	     grid3[i][j]=' ';
	     else
	     grid3[i][j]=chkbomb;
	    }
	    if(i==0 && j==0)
	    {
	     chkbomb='0';
	     if(grid3[i][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid3[i+1][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid3[i+1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(chkbomb=='0')
	     grid3[i][j]=' ';
	     else
	     grid3[i][j]=chkbomb;
	    }
	    if(i==0 && j==11)
	    {
	     chkbomb='0';
	     if(grid3[i][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid3[i+1][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid3[i+1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(chkbomb=='0')
	     grid3[i][j]=' ';
	     else
	     grid3[i][j]=chkbomb;
	    }
	    if(i==11 && j==0)
	    {
	     chkbomb='0';
	     if(grid3[i-1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(grid3[i-1][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid3[i][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(chkbomb=='0')
	     grid3[i][j]=' ';
	     else
	     grid3[i][j]=chkbomb;
	    }
	    if(i==11 && j==11)
	    {
	     chkbomb='0';
	     if(grid3[i-1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(grid3[i-1][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid3[i][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(chkbomb=='0')
	     grid3[i][j]=' ';
	     else
	     grid3[i][j]=chkbomb;
	    }
	   }
	  }
	 }
  case 4:for(i=0;i<16;i++)
	 {
	  for(j=0;j<16;j++)
	  grid04[i][j]='0';
	 }
	 for(i=0;i<16;i++)
	 {
	  for(j=0;j<16;j++)
	  grid4[i][j]='0';
	 }
	 randomize();
	 while(nobomb<60)
	 {
	  bx=random(15-0+1)+0;
	  by=random(15-0+1)+0;
	  if((bx!=(ex-1) && by!=(ey-1)) && grid4[bx][by]!='*')
	  {
	   grid4[bx][by]='*';
	   nobomb++;
	  }
	  else
	  continue;
	 }
	 for(i=0;i<16;i++)
	 {
	  for(j=0;j<16;j++)
	  {
	   if(grid4[i][j]=='*')
	   continue;
	   else
	   {
	    if((i!=0 && j!=0) || (i!=15 && j!=15))
	    {
	     chkbomb='0';
	     if(grid4[i-1][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid4[i-1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(grid4[i-1][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid4[i][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid4[i][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid4[i+1][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid4[i+1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(grid4[i+1][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(chkbomb=='0')
	     grid4[i][j]=' ';
	     else
	     grid4[i][j]=chkbomb;
	    }
	    else
	    if(i==0 && j>0 && j<15)
	    {
	     chkbomb='0';
	     if(grid4[i][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid4[i+1][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid4[i+1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(grid4[i+1][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid4[i][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(chkbomb=='0')
	     grid4[i][j]=' ';
	     else
	     grid4[i][j]=chkbomb;
	    }
	    else
	    if(i==15 && j>0 && j<15)
	    {
	     chkbomb='0';
	     if(grid4[i][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid4[i-1][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid4[i-1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(grid4[i-1][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid4[i][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(chkbomb=='0')
	     grid4[i][j]=' ';
	     else
	     grid4[i][j]=chkbomb;
	    }
	    if(j==0 && i>0 && i<15)
	    {
	     chkbomb='0';
	     if(grid4[i-1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(grid4[i-1][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid4[i][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid4[i+1][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid4[i+1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(chkbomb=='0')
	     grid4[i][j]=' ';
	     else
	     grid4[i][j]=chkbomb;
	    }
	    else
	    if(j==15 && i>0 && i<15)
	    {
	     chkbomb='0';
	     if(grid4[i-1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(grid4[i-1][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid4[i][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid4[i+1][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid4[i+1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(chkbomb=='0')
	     grid4[i][j]=' ';
	     else
	     grid4[i][j]=chkbomb;
	    }
	    if(i==0 && j==0)
	    {
	     chkbomb='0';
	     if(grid4[i][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid4[i+1][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid4[i+1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(chkbomb=='0')
	     grid4[i][j]=' ';
	     else
	     grid4[i][j]=chkbomb;
	    }
	    if(i==0 && j==15)
	    {
	     chkbomb='0';
	     if(grid4[i][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid4[i+1][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid4[i+1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(chkbomb=='0')
	     grid4[i][j]=' ';
	     else
	     grid4[i][j]=chkbomb;
	    }
	    if(i==15 && j==0)
	    {
	     chkbomb='0';
	     if(grid4[i-1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(grid4[i-1][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid4[i][j+1]=='*')
	     chkbomb=chkbomb+1;
	     if(chkbomb=='0')
	     grid4[i][j]=' ';
	     else
	     grid4[i][j]=chkbomb;
	    }
	    if(i==15 && j==15)
	    {
	     chkbomb='0';
	     if(grid4[i-1][j]=='*')
	     chkbomb=chkbomb+1;
	     if(grid4[i-1][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(grid4[i][j-1]=='*')
	     chkbomb=chkbomb+1;
	     if(chkbomb=='0')
	     grid4[i][j]=' ';
	     else
	     grid4[i][j]=chkbomb;
	    }
	   }
	  }
	 }
 }
}
