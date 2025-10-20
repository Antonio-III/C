/* The program takes in a large input (text), then break it up 
into a sequence of unique words, and output the unique words.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define MAXCHARS 1000 // Max chars per word
#define INITIAL 100 // Initial size of unique word array

typedef char word_t[MAXCHARS+1];
int getword(word_t W, int limit);
void exit_if_null(void *ptr, char *msg);

int
main(int argc, char *argv[])
{
	word_t one_word;
	// 1
	char **all_words;
	// 2
	size_t current_size = INITIAL;
	
	// totwords is just for better UX
	int numdistinct = 0, totwords = 0, i, found;
	
	// 3
	all_words = (char **)malloc(INITIAL*sizeof(*all_words));
	exit_if_null(all_words, "initial allocation");
	
	while (getword(one_word, MAXCHARS) != EOF)
	{
		totwords = totwords + 1;
		found = 0;
		for (i = 0; i < numdistinct && !found; i++)
		{
			found = (strcmp(one_word, all_words[i]) == 0);
		}
		if (!found)
		{
			// 4
			if (numdistinct == current_size)
			{
				current_size *= 2;
				all_words = realloc(all_words, 
				current_size*sizeof(*all_words));
				
				exit_if_null(all_words, "reallocation");
			}
			// 5
			all_words[numdistinct] = (char *)malloc(1+strlen(one_word));
			
			exit_if_null(all_words[numdistinct], "string malloc");
			// 6
			strcpy(all_words[numdistinct], one_word);
			numdistinct += 1;
		}
	}
	printf("%d words read\n", totwords);
	for (i = 0; i < numdistinct; i++)
	{
		printf("word #%d is \"%s\"\n", i, all_words[i]);
		// 7
		free(all_words[i]);
		all_words[i] = NULL;
	}
	// 8
	free(all_words);
	all_words = NULL;
	return 0;
}

void
exit_if_null(void *ptr, char *msg)
{
	if (!ptr)
	{
		printf("unexpected null pointer: %s\n", msg);
		exit(EXIT_FAILURE);
	}
}

#include "getword.c"