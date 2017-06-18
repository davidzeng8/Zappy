/*
** parse_parameter.c for parse_parameter in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Sun Jun 18 20:18:05 2017 David Zeng
** Last update Sun Jun 18 20:18:05 2017 David Zeng
*/

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "param.h"

int	param_port(t_param *param, int argc, char **argv)
{
  char	*str;

  (void)argc;
  (void)argv;
  str = NULL;
  param->port = strtol(optarg, &str, 0);
  errno = 0;
  if (errno == ERANGE || (str != NULL && strcmp(str, "") != 0))
    {
      fprintf(stderr, "Error: failed to parse port \"%s\"\n", optarg);
      return (1);
    }
  if (param->port < 0)
    {
      fprintf(stderr, "-p option only accepts valid ports\n");
      return (1);
    }
  return (0);
}

int	param_width(t_param *param, int argc, char **argv)
{
  char	*str;

  (void)argc;
  (void)argv;
  str = NULL;
  param->dimension.x = strtol(optarg, &str, 0);
  errno = 0;
  if (errno == ERANGE || (str != NULL && strcmp(str, "") != 0))
    {
      fprintf(stderr, "Error: failed to parse width \"%s\"\n", optarg);
      return (1);
    }
  if (param->dimension.x < 10 || param->dimension.x > 30)
    {
      fprintf(stderr, "-x option only accepts integer"
	      " values between 10 and 30\n");
      return (1);
    }
  return (0);
}

int	param_height(t_param *param, int argc, char **argv)
{
  char	*str;

  (void)argc;
  (void)argv;
  str = NULL;
  param->dimension.y = strtol(optarg, &str, 0);
  errno = 0;
  if (errno == ERANGE || (str != NULL && strcmp(str, "") != 0))
    {
      fprintf(stderr, "Error: failed to parse height \"%s\"\n", optarg);
      return (1);
    }
  if (param->dimension.y < 10 || param->dimension.y > 30)
    {
      fprintf(stderr, "-y option only accepts integer"
	      " values between 10 and 30\n");
      return (1);
    }
  return (0);
}

int	param_name(t_param *param, int argc, char **argv)
{
  int	i;
  int	size;

  i = --optind;
  size = 0;
  while (i + size < argc && *argv[i + size] != '-')
    ++size;
  param->names = malloc(sizeof(char*) * (size + 1));
  if (!param->names)
    exit(84);
  while (optind < argc && *argv[optind] != '-')
    {
      param->names[optind - i] = strdup(argv[optind]);
      if (!param->names[optind - i])
	exit(84);
      ++optind;
    }
  param->names[optind - i] = NULL;
  return (0);
}

int	param_client(t_param *param, int argc, char **argv)
{
  char	*str;

  (void)argc;
  (void)argv;
  str = NULL;
  param->nb_client = strtol(optarg, &str, 0);
  errno = 0;
  if (errno == ERANGE || (str != NULL && strcmp(str, "") != 0))
    {
      fprintf(stderr, "Error: failed to parse client nb \"%s\"\n", optarg);
      return (1);
    }
  if (param->nb_client < 0)
    {
      fprintf(stderr, "-c option only accepts integer"
	      " values greater or equal to 1\n");
      return (1);
    }
  return (0);
}
