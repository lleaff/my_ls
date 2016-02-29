/*
** my_str_to_wordtab.c for libmy_02 in /home/hains-_l/Libmy/libmy_02/src/
** 
** Made by HAINS-FERLAND Lothaire
** Login   <hains-_l@etna-alternance.net>
** 
** Started on  Sat Oct  3 14:35:18 2015 HAINS-FERLAND Lothaire
** Last update Thu Oct 15 10:45:27 2015 Lothaire HAINS-FERLAND
*/

#include <stdlib.h>

char        *my_strdup(char *str);

static int  is_whitespace(char c)
{
  return (c == ' ' || c == '\n' || c == '\t');
}

static int  count_words(char *str)
{
  int i;
  int wordsc;

  i = 0;
  wordsc = 0;
  while (str[i])
    {
      while (is_whitespace(str[i]))
        i++;
      while (str[i] && !is_whitespace(str[i]))
        i++;
      wordsc++;
    }
  return (wordsc);
}

static int *get_word_sizes(char *str, int wordc)
{
  int i;
  int k;
  int *wordsizes;

  if ((wordsizes = malloc(wordc * sizeof (int))) == NULL || !wordc)
    return (NULL);
  i = 0;
  k = 0;
  while (str[i])
    {
      while (is_whitespace(str[i]))
        i++;
      wordsizes[k] = 0;
      while (str[i] && !is_whitespace(str[i]))
        {
          i++;
          wordsizes[k]++;
        }
      k++;
    }
  return (wordsizes);
}

char        **my_str_to_wordtab(char *str)
{
  int i;
  int wordc;
  int *wordsizes;
  char **words;
  int j;
  int k;

  wordc = count_words(str);
  wordsizes = get_word_sizes(str, wordc);
  words = malloc((wordc + 1) * sizeof (char*));
  i = 0;
  k = 0;
  while (str[i])
    {
      while (is_whitespace(str[i]))
        i++;
      j = 0;
      words[k] = malloc((wordsizes[k] + 1) * sizeof (char));
      while (str[i] && !is_whitespace(str[i]))
        words[k][j++] = str[i++];
      words[k][j] = '\0';
      k++;
    }
  words[wordc] = NULL;
  return (words);
}
