#include <stdio.h>

void draw_pole(int mx, int my, int r1y, int r2y, int sc1, int sc2);
int rocket1_move(char keychar1, int r1y);
int rocket2_move(char keychar2, int r2y);
int ball_move_x(int mx, int vx);
int ball_move_y(int my, int vy);
int coll_wall(int my, int dy);
int coll_rocket(int mx, int my, int r1y, int r2y, int dx);
int win(int mx);

int main() {
  int mx = 38;
  int my = 12;
  int r1y = 12;
  int r2y = 12;
  int sc1 = 0;
  int sc2 = 0;
  char keyp1;
  char keyp2;
  int dx = 1;
  int dy = 1;
  do {
    if (win(mx) == 0) {
      sc2 += 1;
      mx = 38;
      my = 12;
      r1y = 12;
      r2y = 12;
      dx = 1;
      dy = 1;
    } else if (win(mx) == 1) {
      sc1 += 1;
      mx = 38;
      my = 12;
      r1y = 12;
      r2y = 12;
      dx = -1;
      dy = -1;
    }
    draw_pole(mx, my, r1y, r2y, sc1, sc2);
    scanf("%1c%1c", &keyp1, &keyp2);
    r1y = rocket1_move(keyp1, r1y);
    r2y = rocket2_move(keyp2, r2y);
    mx = ball_move_x(mx, dx);
    dy = coll_wall(my, dy);
    my = ball_move_y(my, dy);
    dx = coll_rocket(mx, my, r1y, r2y, dx);
  } while (sc1 != 21 || sc2 != 21);
  if (sc1 == 21) {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                  "
           " Player #1 "
           "WIN!!!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
  }
  if (sc2 == 21) {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                  "
           " Player #2 "
           "WIN!!!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
  }
  return 0;
}

void draw_pole(int mx, int my, int r1y, int r2y, int sc1, int sc2) {
  int i, j;
  for (i = 0; i < 25; i++) {
    for (j = 0; j < 80; j++) {
      if (j == 1 && ((i >= r1y - 1) && (i <= r1y + 1))) {
        printf("X");
      } else if (j == 78 && ((i >= r2y - 1) && (i <= r2y + 1))) {
        printf("X");
      } else if (i == my && j == mx) {
        printf("O");
      } else {
        if ((i == 0 || i == 24) && (j == 0 || j == 79)) {
          printf("*");
        } else if ((i == 0 || i == 24) && (j != 0 && j != 79)) {
          printf("-");
        } else if ((j == 0 || j == 79) && (i > 0 && i < 24)) {
          printf("|");
        } else if ((i > 0 && i < 24) && j == 38) {
          printf(".");
        } else {
          printf(" ");
        }
      }
    }
    printf("\n");
  }
  printf("                         %d                      %d\n", sc1, sc2);
}

int rocket1_move(char keychar1, int r1y) {
  if (r1y != 22) {
    if (keychar1 == 'z') {
      r1y += 1;
    }
  }
  if (r1y != 2) {
    if (keychar1 == 'a') {
      r1y -= 1;
    }
  }
  return r1y;
}

int rocket2_move(char keychar2, int r2y) {
  if (r2y != 22) {
    if (keychar2 == 'm') {
      r2y += 1;
    }
  }
  if (r2y != 2) {
    if (keychar2 == 'k') {
      r2y -= 1;
    }
  }
  return r2y;
}

int ball_move_x(int mx, int vx) { return mx + vx; }

int ball_move_y(int my, int vy) { return my + vy; }

int coll_wall(int my, int dy) {
  if (my == 1 || my == 23) {
    dy = -dy;
  }
  return dy;
}

int coll_rocket(int mx, int my, int r1y, int r2y, int dx) {
  if ((mx == 2 && my >= r1y - 1 && my <= r1y + 1) ||
      (mx == 77 && my >= r2y - 1 && my <= r2y + 1)) {
    dx = -dx;
  }
  return dx;
}

int win(int mx) {
  int who_win = -1;
  if (mx == 1) {
    who_win = 0;
  }
  if (mx == 78) {
    who_win = 1;
  }
  return who_win;
}
