#include "my.h"

void get_player(int *x_player, int *y_player, map_t *map)
{
    for (int x = 0; x < map->rows; x++) {
        for (int y = 0; map->map_entities[x][y] != '\n'; y++) {
            if (map->map_entities[x][y] == 'P') {
                *x_player = x;
                *y_player = y;
                return;
            }
        }
    }
}
void print_map(map_t *map)
{
    for (int x = 0; x < map->rows; x++) {
        for (int y = 0; map->map_static[x][y] != '\0'; y++) {
            if (map->map_entities[x][y] != ' ')
                printw("%c", map->map_entities[x][y]);
            else
                printw("%c", map->map_static[x][y]);
        }
    }
}
int check_collision(map_t *map, int new_x_player, int new_yplayer)
{
    if (map->map_static[new_x_player][new_yplayer] == '#')
        return 1;
    if (map->map_entities[new_x_player][new_yplayer] == 'X')
        return 2;
    return 0;
}


void do_up(map_t *map) 
{
    int ret_collision = check_collision(map, map->x_player - 1, map->y_player);

    if (!ret_collision) {
        map->map_entities[map->x_player][map->y_player] = ' ';
        map->x_player = map->x_player - 1;
        map->map_entities[map->x_player][map->y_player] = 'P';
    }
    else if (ret_collision == 2) {
        int ret_collision = check_collision(map, map->x_player - 2, map->y_player);
        if (!ret_collision) {
            map->map_entities[map->x_player - 2][map->y_player] = 'X';
            map->map_entities[map->x_player - 1][map->y_player] = ' ';
            map->map_entities[map->x_player][map->y_player] = ' ';
            map->x_player = map->x_player - 1;
            map->map_entities[map->x_player][map->y_player] = 'P';
        }
    }
}
void do_down(map_t* map)
{
    int ret_collision = check_collision(map, map->x_player + 1, map->y_player);

    if (!ret_collision) {
        map->map_entities[map->x_player][map->y_player] = ' ';
        map->x_player = map->x_player + 1;
        map->map_entities[map->x_player][map->y_player] = 'P';
    }
    else if (ret_collision == 2) {
        ret_collision = check_collision(map, map->x_player + 2, map->y_player);
        if (!ret_collision) {
            map->map_entities[map->x_player + 2][map->y_player] = 'X';
            map->map_entities[map->x_player + 1][map->y_player] = ' ';
            map->map_entities[map->x_player][map->y_player] = ' ';
            map->x_player = map->x_player + 1;
            map->map_entities[map->x_player][map->y_player] = 'P';
        }
    }
}
void do_left(map_t* map)
{
    int ret_collision = check_collision(map, map->x_player, map->y_player - 1);

    if (!ret_collision) {
        map->map_entities[map->x_player][map->y_player] = ' ';
        map->y_player = map->y_player - 1;
        map->map_entities[map->x_player][map->y_player] = 'P';
    }
    else if (ret_collision == 2) {
        ret_collision = check_collision(map, map->x_player, map->y_player - 2);
        if (!ret_collision) {
            map->map_entities[map->x_player][map->y_player - 2] = 'X';
            map->map_entities[map->x_player][map->y_player - 1] = ' ';
            map->map_entities[map->x_player][map->y_player] = ' ';
            map->y_player = map->y_player - 1;
            map->map_entities[map->x_player][map->y_player] = 'P';
        }
    }
}
void do_right(map_t* map)
{
    int ret_collision = check_collision(map, map->x_player, map->y_player + 1);

    if (!ret_collision) {
        map->map_entities[map->x_player][map->y_player] = ' ';
        map->y_player = map->y_player + 1;
        map->map_entities[map->x_player][map->y_player] = 'P';
    }
    else if (ret_collision == 2) {
        ret_collision = check_collision(map, map->x_player, map->y_player + 2);
        if (!ret_collision) {
            map->map_entities[map->x_player][map->y_player + 2] = 'X';
            map->map_entities[map->x_player][map->y_player + 1] = ' ';
            map->map_entities[map->x_player][map->y_player] = ' ';
            map->y_player = map->y_player + 1;
            map->map_entities[map->x_player][map->y_player] = 'P';
        }
    }
}
void handle_move(int key, map_t* map)
{
    switch (key)
    {
    case 'z':
        do_up(map);
        break;

    case 's':
        do_down(map);
        break;

    case 'q':
        do_left(map);
        break;

    case 'd':
        do_right(map);
        break;
    }
}

int game_frame(int key, map_t *map, int *game_result)
{
    int ret_collision = 0;
    
    get_player(&map->x_player, &map->y_player, map);
    handle_move(key, map);
    if (is_game_win(map)) {
        *game_result = 0;
        return 0;
    }
    else if (is_game_lost(map)) {
        *game_result = 1;
        return 0;
    }
    else {
        return 1;
    }
}

void is_boxe_good(int x, int y, map_t *map, int *win)
{
    if (map->map_static[x][y] == 'O' && map->map_entities[x][y] != 'X') {
        *win = 0;
    }
}
int is_game_win(map_t *map)
{
    int win = 1;
    for (int x = 0; x < map->rows; x++) {
        for (int y = 0; map->map_static[x][y] != '\0'; y++) {
            is_boxe_good(x, y, map, &win);
        }
    }
    return win;
}
void check_boxe_not_pushable(int x, int y, map_t *map, int *lose)
{
    if (map->map_entities[x][y] == 'X') {
        if (check_collision(map, x - 1, y) == 0 && map->map_static[x + 1][y] == ' ')
            *lose = 0;

        if (check_collision(map, x + 1, y) == 0 && map->map_static[x - 1][y] == ' ')
            *lose = 0;

        if (check_collision(map, x, y - 1) == 0 && map->map_static[x][y + 1] == ' ')
            *lose = 0;

        if (check_collision(map, x, y + 1) == 0 && map->map_static[x][y - 1] == ' ')
            *lose = 0;
    }
}
int is_game_lost(map_t *map)
{
    int lose = 1;
    for (int x = 0; x < map->rows; x++) {
        for (int y = 0; map->map_static[x][y] != '\0'; y++) {
            check_boxe_not_pushable(x, y, map, &lose);
        }
    }
    return lose;
}

int main(int argc, char **argv)
{
    map_t *map = NULL;
    int key = 0;
    int game_result = 0;

    if(argc != 2)
        return 84;

    map = read_map(argv[1]);
    if(!map)
        return 84;

    initscr();
    noecho();
    while (key != '\n') {
        clear();
        print_map(map);
        key = getch();
        if (key == ' ') {
            free(map);
            map = read_map(argv[1]);
            continue;
        }
        if (!game_frame(key, map, &game_result))
            break;
    }
    endwin();
    return game_result;
}