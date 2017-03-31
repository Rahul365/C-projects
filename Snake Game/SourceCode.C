#include<stdio.h>
#include<math.h>
#include<process.h>
#include<time.h>
#include<ctype.h>
#include<windows.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77


void Up();
void Down();
void Left();
void Right();
void Move();
void Border();
int Score();
void Delay(long double);
void Food();
int ScoreOnly();
void Bend();
void record();
void Print();
void Exitgame();
void Load();
void gotoxy(int x,int y);
void GotoXY(int x,int y);

int len;
char key;
int length;
int bend_no;
int life;

typedef struct coordinates{
int x;
int y;
int direction;
}coord;
coord body[30],head,food,bend[500];

int main(){
        char key;
        Print();
        system("cls");
        Load();
        length=5;
        head.x=25;
        head.y=20;
        head.direction=RIGHT;
        Border();
        Food();
        life=3;
        bend[0]=head;
        Move();
        return 0;
}

void gotoxy(int x,int y)
{
  COORD coord;
  coord.X=x;
  coord.Y=y;
  SetConsoleCursorPosition(GetCursorHandle(STD_OUTPUT_HANDLE),coord);
}
void GotoXY(int x,int y)
{
  COORD a;
  HANDLE b;
        fflush(stdout);
  b=GetCursorHandle(STD_OUTPUT_HANDLE);
  a.X=x;
  a.Y=y;
  SetConsoleCursorPosition(b,a);
}
void Print(){
  printf("\t\tMini Snake Game\n");
  getch();
  system("cls");
  printf("\tIntroduction to the game\n);
  printf("1-> Use arrow keys to move the snake within the block to fetch the food\n");
  printf("2-> Do not the hit the border\n");
  printf("\t\tEnjoy the game\n");
  if(getch()==27)
         exit(0);
}
void Load(){
  int r,q;
  gotoxy(36,14);
  printf("Loading.....\n");
  gotoxy(34,15);
  for(r=1;r<=10;r++){
  for(q=0;q<=100000000;q++);
  printf("%c",177);
  }
  getch();
}
void Border(){
        system("cls");
        GotoXY(food.x,food.y);
        printf("F");
        int i;
        
        for(i=10;i<71;i++)
        {
                GotoXY(i,10);
                printf("!");
                GotoXY(i,30);
                printf("!");
        }
        for(i=10;i<31;i++)//left and right walls
        {
               GotoXY(10,i);
                printf("!");
               GotoXY(70,i);
                printf("!");
        }
}
void Food(){
if(head.x==food.x && head.y==food.y){
        length++;
        time_t a;
        a=time(0);
        srand(a);
        food.x=rand()%70;
        if(food.x <=10 )
                food.x+=11;
        food.y=rand()%30;
        if(food.y <=10)
                food.y+=11;
}
else if(food.x==0)//initially all global variables are zero
{
        food.x=rand()%70;
        if(food.x<=10)
                food.x+=11;
        food.y=rand()%30;
        if(food.y<=10)
                food.y+=11;
}
}
int Score(){
        int score;
        score = length-5;
        GotoXY(20,8);
        printf("Score : %d",score);
        GotoXY(50,8);
        printf("Life  : %d",life);
        return score;
}
int Scoreonly(){
        int score=Score();
        system("cls");
        return score;
}
void Delay(long double k){
        Score();
        long double i;
        for(i=0;i<=10000000;i++);
}
