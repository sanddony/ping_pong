#include <stdio.h>
#define HEIGHT 25
#define WIDTH 78
#define RIGHTROCKET_X 3
#define LEFTROCKET_X 74

void PrintField();
void PrintScoreTable(int player_left_score, int player_right_score);
int ChangeBallX(int ball_x, int ball_y, int vector_x, int rightRocket,
                int leftRocket);
int ChangeBallY(int ball_y, int vector_y);
int MoveRightRocket(int rightRocket);
int MoveLeftRocket(int leftRocket);
int CheckScorePL(int ball_x, int player_left_score);
int CheckScorePR(int ball_x, int player_right_score);
void DecideWinner(int player_left_score, int player_right_score);
void PlayerLeft1Win(int player_right_score);
void PlayerRight2Win(int player_left_score);

int main() {
  int player_left_score = 0;
  int player_right_score = 0;
  int vector_x = -1;
  int vector_y = 1;
  while (player_left_score < 21 && player_right_score < 21) {
    int rightRocket = 12;
    int leftRocket = 12;
    int ball_x = 40;
    int ball_y = 12;
    while (ball_x > 1 && ball_x < 77) {
      PrintField(rightRocket, leftRocket, ball_x, ball_y, player_left_score,
                 player_right_score);
      switch (getchar()) {
        case 'a':
          ((rightRocket - 2) != 0) ? (rightRocket -= 1) : rightRocket;
          break;
        case 'z':
          ((rightRocket + 2) != 24) ? (rightRocket += 1) : rightRocket;
          break;
        case 'k':
          ((leftRocket - 2) != 0) ? (leftRocket -= 1) : leftRocket;
          break;
        case 'm':
          ((leftRocket + 2) != 24) ? (leftRocket += 1) : leftRocket;
          break;
      }
      int flag_space = 1;
      while (flag_space)
        if (getchar() == ' ') flag_space = 0;
      vector_y = ChangeBallY(ball_y, vector_y);
      vector_x = ChangeBallX(ball_x, ball_y, vector_x, rightRocket, leftRocket);
      ball_x += vector_x;
      ball_y += vector_y;
      player_left_score = CheckScorePL(ball_x, player_left_score);
      player_right_score = CheckScorePR(ball_x, player_right_score);
    }
    DecideWinner(player_left_score, player_right_score);
  }
}

void PrintField(int rightRocket, int leftRocket, int ball_x, int ball_y,
                int player_left_score, int player_right_score) {
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      if ((x == RIGHTROCKET_X && (y == rightRocket - 1 || y == rightRocket ||
                                  y == rightRocket + 1)) ||
          (x == LEFTROCKET_X &&
           (y == leftRocket - 1 || y == leftRocket || y == leftRocket + 1))) {
        printf("|");
      } else if (y == ball_y && x == ball_x) {
        printf("o");
      } else {
        if (x == 0) printf("|");
        if (y == 0 && x == 5)
          printf(" Player 1: %d ", player_left_score);
        else if (y == 0 && x == 70)
          printf(" Player 2: %d ", player_right_score);
        else if (y == 0 && (x > 45 && x < 71))
          continue;
        else if (y == 0 && x == 5 && player_left_score > 9)
          printf(" Player 1: %d", player_left_score);

        else if (y == 0 && x == 70 && player_right_score)
          printf(" Player 2: %d", player_right_score);

        else if ((y == 0 && (x > 43 && x < 71)) &&
                 (player_left_score > 9 && player_right_score > 9))
          continue;
        else if ((y == 0 && (x > 44 && x < 71)) &&
                 (player_left_score > 9 || player_right_score > 9))
          continue;
        else if (y == 0 || y == 24)
          printf("=");
        else
          printf(" ");
        if (x == 77) printf("|");
      }
    }
    printf("\n");
  }
}

int ChangeBallX(int ball_x, int ball_y, int vector_x, int rightRocket,
                int leftRocket) {
  if ((ball_x == 6) && (ball_y == rightRocket || ball_y == rightRocket + 1 ||
                        ball_y == rightRocket - 1)) {
    vector_x = -(vector_x);
  }
  if (ball_x == 73 && (ball_y == leftRocket || ball_y == leftRocket + 1 ||
                       ball_y == leftRocket - 1)) {
    vector_x = -(vector_x);
  }
  return (vector_x);
}

int ChangeBallY(int ball_y, int vector_y) {
  if (ball_y == 1 || ball_y == 23) {
    vector_y = -(vector_y);
  }
  return (vector_y);
}

int CheckScorePL(int ball_x, int player_left_score) {
  if (ball_x >= 77) {
    player_left_score++;
  }
  return player_left_score++;
}

int CheckScorePR(int ball_x, int player_right_score) {
  if (ball_x <= 1) {
    player_right_score++;
  }
  return player_right_score++;
}

void PlayerLeft1Win(int player_right_score) {
  char nosimbol = '\0';
  if (player_right_score < 9) nosimbol = ' ';
  printf("|===== Player 1: 21 ==================");
  printf("==================== Player 2: %d%c =========|\n", player_right_score,
         nosimbol);
  printf(
      "|                                                                       "
      "         |\n");
  printf(
      "|                                                                       "
      "         |\n");
  printf(
      "|      ########  ##          ###    ##    ## ######## ########        "
      "##         |\n");
  printf(
      "|      ##     ## ##         ## ##    ##  ##  ##       ##     ##     "
      "####         |\n");
  printf(
      "|      ##     ## ##        ##   ##    ####   ##       ##     ##       "
      "##         |\n");
  printf(
      "|      ########  ##       ##     ##    ##    ######   ########        "
      "##         |\n");
  printf(
      "|      ##        ##       #########    ##    ##       ##   ##         "
      "##         |\n");
  printf(
      "|      ##        ##       ##     ##    ##    ##       ##    ##        "
      "##         |\n");
  printf(
      "|      ##        ######## ##     ##    ##    ######## ##     ##     "
      "######       |\n");
  printf(
      "|                                                                       "
      "         |\n");
  printf(
      "|                                                                       "
      "         |\n");
}

void PlayerRight2Win(int player_left_score) {
  char nosimbol = '\0';
  if (player_left_score < 9) nosimbol = ' ';
  printf("|===== Player 1: %d%c ================", player_left_score, nosimbol);
  printf("====================== Player 2: 21 =========|\n");
  printf(
      "|                                                                       "
      "         |\n");
  printf(
      "|                                                                       "
      "         |\n");
  printf(
      "|      ########  ##          ###    ##    ## ######## ########      "
      "#######      |\n");
  printf(
      "|      ##     ## ##         ## ##    ##  ##  ##       ##     ##    ##   "
      "  ##     |\n");
  printf(
      "|      ##     ## ##        ##   ##    ####   ##       ##     ##         "
      "  ##     |\n");
  printf(
      "|      ########  ##       ##     ##    ##    ######   ########      "
      "#######      |\n");
  printf(
      "|      ##        ##       #########    ##    ##       ##   ##      ##   "
      "         |\n");
  printf(
      "|      ##        ##       ##     ##    ##    ##       ##    ##     ##   "
      "         |\n");
  printf(
      "|      ##        ######## ##     ##    ##    ######## ##     ##    "
      "#########     |\n");
  printf(
      "|                                                                       "
      "         |\n");
  printf(
      "|                                                                       "
      "         |\n");
}

void DecideWinner(int player_left_score, int player_right_score) {
  if (player_left_score == 21) PlayerLeft1Win(player_right_score);
  if (player_right_score == 21) PlayerRight2Win(player_left_score);
  printf(
      "|               ##      ## #### ##    ##  ######  ####                  "
      "         |\n");
  printf(
      "|               ##  ##  ##  ##  ###   ## ##    ## ####                  "
      "         |\n");
  printf(
      "|               ##  ##  ##  ##  ####  ## ##       ####                  "
      "         |\n");
  printf(
      "|               ##  ##  ##  ##  ## ## ##  ######   ##                   "
      "         |\n");
  printf(
      "|               ##  ##  ##  ##  ##  ####       ##                       "
      "         |\n");
  printf(
      "|               ##  ##  ##  ##  ##   ### ##    ## ####                  "
      "         |\n");
  printf(
      "|                ###  ###  #### ##    ##  ######  ####                  "
      "         |\n");
  printf(
      "|                                                                       "
      "         |\n");
  printf(
      "|                                                                       "
      "         |\n");
  printf(
      "|                                                                       "
      "         |\n");
  printf(
      "|                                                                       "
      "         |\n");
  printf(
      "|======================================================================="
      "=========|\n");
}
