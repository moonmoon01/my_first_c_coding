#include <stdio.h>
#include <math.h>

#define NUM_OF_ROW    3
#define NUM_OF_COL    3

#define PLAYER_A      0
#define PLAYER_B      1

char gameBoard[NUM_OF_ROW][NUM_OF_COL]={ {'_', '_', '_'},
                                         {'_', '_', '_'},
                                         {'_', '_', '_'} };

int player=PLAYER_A;
int game_over = 0;

void checkGameOver(void);




void display_gameBoard(void)
{
  printf("===Display Game Board=== \n");

  for(int i=0; i<NUM_OF_ROW; i++){
       for(int j=0; j<NUM_OF_COL; j++){
          printf("%c", gameBoard[i][j]);
       }
       printf("\n");
  }

}

void diplay_opening(void)
{
  printf("Hi, I can code in C language!\n");
  printf("My favorite animals are sheep\n");
  printf("o-###- \n"
         "  | |\n");
}

int main()
{
  int born;
  int age;

  int row;
  int col;

  diplay_opening();
  /*
  printf("몇년도에 태어나셨나요?");
  scanf("%d", &born);

  age=2030-born;
  printf("당신은 2030년에는 %d살이 됩니다.\n",age);
  */
  
  display_gameBoard();

  int i =0;

  while( (i<9)  && (game_over == 0 )) {
      printf("몇번 행을 선택하시겠습니까?");
      scanf("%d",&row);

      printf("몇번 열을 선택하시겠습니까?");
      scanf("%d",&col);

      if(player==PLAYER_A){
        gameBoard[row][col] = 'O';
        player = PLAYER_B;
      }
      else{
        gameBoard[row][col] = 'X';
        player = PLAYER_A;
      }


      display_gameBoard();
      checkGameOver();

 }
    return 0;
}


void checkGameOver(void)
{
   for (int l=0; l<3; l++){
        if((gameBoard[l][0] != '_'))
        {
          if( (gameBoard[l][0] == gameBoard[l][1] ) && 
                (gameBoard[l][1] == gameBoard[l][2]) )
            {
                game_over = 1;
                printf("game over");
            }
        }
   }
    for (int i=0; i<3; i++){
        if((gameBoard[0][i] != '_'))
        {
          if( (gameBoard[0][i] == gameBoard[1][i] ) && 
                (gameBoard[1][i] == gameBoard[2][i]) )
            {
                game_over = 1;
                printf("game over");
            }
        }
    }
    if((gameBoard[1][1] !='_'))
    {
      if((gameBoard[0][0] == gameBoard[1][1])&&
          (gameBoard[1][1]==gameBoard[2][2]))
          {game_over =1;
          printf("game over");}
      if((gameBoard[0][2] == gameBoard[1][1])&&
          (gameBoard[1][1] == gameBoard[2][0]))
          {game_over =1;
          printf("game over");}
    }


}
