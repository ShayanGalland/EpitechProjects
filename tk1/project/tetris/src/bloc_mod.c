/*
** EPITECH PROJECT, 2021
** tools
** File description:
** help
*/

#include "my.h"

int count_bs(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
	    if (str[i] == '\n')
            count++;
    }
    return count;
}

void rotate(game_t *game)
{
    int height = game->cur_block->piece.dim.y;
    int width = game->cur_block->piece.dim.x;
    int new_height = width;
    int new_width = height;
    char **newPiece = malloc(sizeof(char*) * new_height);

    for (int i = 0; i < width; i++) {
        newPiece[i] = malloc(sizeof(char) * new_width);
        for (int j = 0; j < new_width; j++)
            newPiece[i][j] = 0;
    }
    for (int y = 0; y < new_height; y++) {
        for( int x = 0; x < new_width; x++)
            newPiece[y][x] = game->cur_block->piece.tab[x][y];
    }
    game->cur_block->piece.dim.x = new_width;
    game->cur_block->piece.dim.y = new_height;
    game->cur_block->piece.tab = newPiece;
}

void array_comb(game_t *game, int mx, int my)
{
    int y = 1+my;
    int x = 14/2 - game->cur_block->piece.dim.x/2 + mx;

    for (int j = 0; j < 39; j++) {
        for (int i = 0; i < 15; i++)
            game->map2.tab[j][i] = ' ';
    }
    for (int j = 0; j < game->cur_block->piece.dim.y; j++) {
        for (int i = 0; i < game->cur_block->piece.dim.x; i++) {
            if (game->cur_block->piece.tab[j][i] == '*')
                game->map2.tab[y][x] = game->cur_block->piece.tab[j][i];
            x++;
        }
        x = 14/2 - game->cur_block->piece.dim.x/2 + mx;
        y++;
    }
}

int is_lose(game_t *game, int mx, int my)
{
    int y = 1+my;
    int x = 14/2 - game->cur_block->piece.dim.x/2 + mx;

    for (int j = 0; j < 39; j++) {
        for (int i = 0; i < 15; i++)
            game->map2.tab[j][i] = ' ';
    }
    for (int j = 0; j < game->cur_block->piece.dim.y; j++) {
        for (int i = 0; i < game->cur_block->piece.dim.x; i++) {
            if (game->cur_block->piece.tab[j][i] == '*' && game->map.tab[y][x] == '*')
                return 1;
            x++;
        }
        x = 14/2 - game->cur_block->piece.dim.x/2 + mx;
        y++;
    }
    return 0;
}

unsigned int generate_random_number(int min, int max)
{
    int result  = rand() % ((max + 1) - min) + min;
    return result;
}

piece_t *generate_new_piece(game_t *game)
{
    piece_t *piece = malloc(sizeof(piece_t));
    int r = generate_random_number(0, game->nb_block-1);

    piece->piece.dim.x = game->block[r].piece.dim.x;
    piece->piece.dim.y = game->block[r].piece.dim.y;
    piece->piece.tab = malloc(sizeof(char*)*piece->piece.dim.y);
    for (int j = 0; j < piece->piece.dim.y; j++) {
        piece->piece.tab[j] = malloc(sizeof(char) * piece->piece.dim.x);
        for (int i = 0; i < piece->piece.dim.x;i++)
            piece->piece.tab[j][i] = game->block[r].piece.tab[j][i];
    }
    game->speed = 1;
    game->mv = 0;
    return piece;
}