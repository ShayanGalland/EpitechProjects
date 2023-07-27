/*
** EPITECH PROJECT, 2021
** tools
** File description:
** main
*/

#include "my.h"

void setup(game_t *game)
{
    game->level = 1;
    game->speed = 1;
    game->mv = 0;
    game->score = 0;
    game->cur_block = generate_new_piece(game);
}

void key_control(game_t *game, int key)
{
    switch (key) {
        case 65:
            rotate(game);
            flushinp();
            break;
        case 66:
            game->speed = 5;
            flushinp();
            break;
        case 68:
            if (!bord_col(game))
                game->mv--;
            flushinp();
            break;
        case 67:
            if (!bord_col(game))
                game->mv++;
            flushinp();
            break;
        }
        game->del = 200;
}

void ctr_all(game_t *game, int key)
{

    level(game);
}

void gameplay(game_t *game)
{
    int key = 0;
    int down = 0;
    int d = 0;
    WINDOW *recup = initscr();

    cbreak();
    noecho();
    setup(game);
    while (key != 'q') {
        d = 100/game->speed;
        clear();
        prt_map(game);
        timeout(d);
        key = getch();
        key_control(game, key);
        if (key != ERR)
            delay(d);
        if (collision(game)) {
            merge_map(game);
            free(game->cur_block);
            game->cur_block = generate_new_piece(game);
            down = 0;

            if(is_lose(game, game->mv, down))
                break;
            chk_lines(game);
        }
        down++;
        ctr_all(game, key);
        array_comb(game, game->mv, down);
    }
}

void tetris()
{
    game_t game;

    srand(42);
    count_block("tetriminos", &game);
    fil_tab(&game);
    fil_tab2(&game);
    gameplay(&game);
    endwin();
    free(game.map2.tab);
    free(game.map.tab);
    for (int i = 0; i < game.nb_block; i++)
        free(game.block[i].piece.tab);
}

int main(int ac, char **av)
{
    if (help(ac, av) == 1)
        return 0;
    tetris(ac, av);
    return 0;
}