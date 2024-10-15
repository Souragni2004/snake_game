#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int rows=30,columns=30,i,j,coord1=0,coord2=0,movex=1,movey=1,score=0,gamestop=0;
void draw();
void food();
void move();
void main()
{
    food();
    while(gamestop!=1)
    {
        printf("Score:%d",score);  
        move();
        draw();
    }
}
void draw()
{
    system("cls");
    for(i=0;i<rows;i++)
    {
        for(j=0;j<columns;j++)
        {
            if(i==0||i==rows-1||j==0||j==columns-1)
            printf("*");
            else if(i==coord1&&j==coord2)
            printf("0");
            else if(i==movex&&j==movey)
            printf(">");
            else
            printf(" ");
        }
        printf("\n");
    }
    if(gamestop==1)
    printf("Game Over!Score:%d",score);
}
void food()
{
  srand(time(NULL));
  coord1=rand()%(rows-1);
  coord2=rand()%(rows-1);
  if(coord1==0)
  coord1++;
  else if(coord2==0)
  coord2++;
}
void move()
{
    if(kbhit())
    {
        switch(getch())
        {
            case 'f':movey++;
                     break;
            case 'u':movex--;
                     break;
            case 'd':movex++;
                     break;
            case 'b':movey--;
                     break;   
             default:break;                                        
        }

    }
    if(movex==0||movex==rows-1||movey==0||movey==columns-1)
    {  
    gamestop=1;
    }
    if(movex==coord1&&movey==coord2)
    {
      srand(time(NULL));
      coord1=rand()%(rows-1);
      coord2=rand()%(rows-1);
      if(coord1==0)
      coord1++;
      else if(coord2==0)
      coord2++;
      score++;
    }
}