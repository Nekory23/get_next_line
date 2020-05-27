/*
** EPITECH PROJECT, 2020
** get_next_line
** File description:
** read a file line by line
*/

#include "get_next_line.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

char *fill_line(char *buffer, char *line, char *stock, int i)
{
    int j = 0;
    int len = my_strlen(stock);

    line = malloc(sizeof(char) * (READ_SIZE * i + 1));
    if (len != 0) {
        while (j != len) {
            line[j] = stock[j];
            j++;
        }
    }
    for (int temp = 0; temp <= i; temp++)
        line[j + temp] = buffer[temp];
    return (line);
}

char *get_next_line(int fd)
{
    static char stock[READ_SIZE];
    char buffer[READ_SIZE + 1];
    int rd = read(fd, buffer, READ_SIZE);
    char *line = 0;

    if (fd == -1 || rd <= 0)
        return (NULL);
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i + 1] == '\n') {
            line = fill_line(buffer, line, stock, i);
            for (int j = 0; buffer[i] != '\0'; j++, i++)
                stock[j] = buffer[i + 2];
            break;
        }
        if (buffer[i + 1] == '\0')
            for (int j = 0; buffer[j] != '\0'; j++)
                stock[j] = buffer[j];
    }
    return (line);
}
