#include <ncurses.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {
  int mx = 38;
  int my = 12;
  int r1y = 12;
  int r2y = 12;
  int sc1 = 0;
  int sc2 = 0;
  int ch = ' ';
  int dx = 1;
  int dy = 1;
  initscr();
  noecho();
  curs_set(0);
  nodelay(stdscr, 1);
  do {
    clear();
    if (ch == 'a' && r1y != 1) {
      r1y -= 1;
    }
    if (ch == 'z' && r1y != 24) {
      r1y += 1;
    }
    if (ch == 'k' && r2y != 1) {
      r2y -= 1;
    }
    if (ch == 'm' && r2y != 24) {
      r2y += 1;
    }
    printw("                            %d                                %d",
           sc1, sc2);
    if (sc1 == 21) {
      printw("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                  "
             " Player #1 "
             "WIN!!!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
      nodelay(stdscr, 0);
    }
    if (sc2 == 21) {
      printw("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                  "
             " Player #2 "
             "WIN!!!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
      nodelay(stdscr, 0);
    }
    mvaddch(r1y - 1, 0, 'X');
    mvaddch(r1y, 0, 'X');
    mvaddch(r1y + 1, 0, 'X');

    mvaddch(r2y - 1, 80, 'X');
    mvaddch(r2y, 80, 'X');
    mvaddch(r2y + 1, 80, 'X');

    usleep(90000);
    mx += dx;
    my += dy;
    if (mx == 80) {
      sc1 += 1;
      mx = 38;
      my = 12;
      r1y = 12;
      r2y = 12;
      dx = -1;
      dy = -1;
    }
    if (mx == 0) {
      sc2 += 1;
      mx = 38;
      my = 12;
      r1y = 12;
      r2y = 12;
      dx = 1;
      dy = 1;
    }
    if (my == 0 || my == 25) {
      dy = -dy;
    }
    if ((mx == 1 && my >= r1y - 1 && my <= r1y + 1) ||
        (mx == 79 && my >= r2y - 1 && my <= r2y + 1)) {
      dx = -dx;
    }
    mvaddch(my, mx, 'O');
  } while (((ch = getch()) != 27) || sc1 != 21 || sc2 != 21);
  getch();
  endwin();
  return 0;
}
