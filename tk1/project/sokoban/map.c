#include "my.h"

//// TEMP /////
ssize_t getline(char **lineptr, size_t *n, FILE *stream)
{
    size_t pos;
    int c;

    if (lineptr == NULL || stream == NULL || n == NULL)
    {
        errno = EINVAL;
        return -1;
    }

    c = getc(stream);
    if (c == EOF)
    {
        return -1;
    }

    if (*lineptr == NULL)
    {
        *lineptr = malloc(128);
        if (*lineptr == NULL)
        {
            return -1;
        }
        *n = 128;
    }

    pos = 0;
    while (c != EOF)
    {
        if (pos + 1 >= *n)
        {
            size_t new_size = *n + (*n >> 2);
            if (new_size < 128)
            {
                new_size = 128;
            }
            char *new_ptr = realloc(*lineptr, new_size);
            if (new_ptr == NULL)
            {
                return -1;
            }
            *n = new_size;
            *lineptr = new_ptr;
        }

        ((unsigned char *)(*lineptr))[pos++] = c;
        if (c == '\n')
        {
            break;
        }
        c = getc(stream);
    }

    (*lineptr)[pos] = '\0';
    return pos;
}
//// TEMP /////

int check_line(char *line)
{
    int i = 0;

    while (line[i] != '\0')
    {
        if (line[i] != '#' && line[i] != 'P' && line[i] != 'O' && line[i] != 'X' && line[i] != '\n' && line[i] != ' ')
            return 0;
        i++;
    }
    return 1;
}
int check_map(const char *map_filepath, int *rows, int *cols)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int i = 0;

    fp = fopen(map_filepath, "r");
    while ((read = getline(&line, &len, fp)) != -1)
    {
        if (!check_line(line))
            return -1;
        (*rows)++;
        if ((*cols) == 0)
            *cols = read;
    }
    if (line)
        free(line);
    return 0;
}
map_t *read_map(const char *map_filepath)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    map_t *map = malloc(sizeof(map_t));
    map->rows = 0;
    map->cols = 0;
    int i = 0;

    if (check_map(map_filepath, &map->rows, &map->cols) != 0)
        return NULL;

    map->map_static = malloc(sizeof(char *) * map->rows);
    map->map_entities = malloc(sizeof(char *) * map->rows);
    fp = fopen(map_filepath, "r");
    while ((read = getline(&line, &len, fp)) != -1)
    {
        map->map_static[i] = line;
        map->map_entities[i] = malloc(sizeof(char) * read);
        memcpy(map->map_entities[i], map->map_static[i], sizeof(char) * read);
        line = NULL;
        i++;
    }
    clean_map(map->map_static, map->rows, 0);
    clean_map(map->map_entities, map->rows, 1);
    return map;
}
char clean_tile(char tile, int entities)
{
    if (entities == 0)
    {
        if (tile != '#' && tile != 'O' && tile != '\n')
            tile = ' ';
    }
    else
    {
        if (tile != 'P' && tile != 'X' && tile != '\n')
            tile = ' ';
    }

    return tile;
}
void clean_map(char **map, int rows, int entities)
{
    for (int x = 0; x < rows; x++)
    {
        for (int y = 0; map[x][y] != '\0'; y++)
        {
            map[x][y] = clean_tile(map[x][y], entities);
        }
    }
}