/*
** stones.h for stones in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Wed Jun 14 03:25:42 2017 David Zeng
** Last update Wed Jun 14 03:25:42 2017 David Zeng
*/

#ifndef STONES_H_
# define STONES_H_

/**
 * Constant for stones
 */
typedef enum	e_stones
  {
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME,
    STONES_SIZE,
  }		t_stones;

/**
 * return an malloc'ed string corresponding to the stone
 */
char		*stone_to_str(t_stones stone);
/**
 * return the stone enum corresponding to the string
 * return STONES_SIZE in case of failure
 */
t_stones	str_to_stone(char *str);

#endif /* !STONES_H_ */
