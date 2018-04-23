#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../chapter04/getch.c"

#define MAXWORD 100

/**
 *  Author:Zheng Jun
 *  Date:2018/4/20 17:43
 *  E-mail:zhengjun1987@outlook.com
 *  Desc:
 */

 struct tnode 
 {
 	char *word;
 	int count;
 	struct tnode *left;
 	struct tnode *right;
 };

 struct tnode *talloc(void){
 	return (struct tnode *) malloc(sizeof(struct tnode));
 }

 void strcopy(char *s, char *t){
 	while((*s++ = *t++) != '\0')
 		;
 }

 char *strdup1(char *s){
 	char *p;
 	p = (char *) malloc(strlen(s) + 1);
 	if (p != NULL)
 	{
 		strcopy(p, s);
 	}
 	return p;
 }

struct tnode *addtree(struct tnode *root, char *word){
	int cond;
	if (root == NULL) {
		root = talloc();
		root->word = strdup1(word);
		root->count = 1;
		root->left = NULL;
		root->right = NULL;
	} else if ((cond = strcmp(word, root->word)) == 0) {
		root->count++;
	} else if (cond < 0) {
		root->left = addtree(root->left, word);
	} else {
		root->right = addtree(root->right, word);
	}
	return root;
}

void treeprint(struct tnode *t){
	if (t != NULL)
	{
		treeprint(t->left);
		printf("%4d %s\n", t->count, t->word);
		treeprint(t->right);
	}
}

int getword(char *word, int lim){
	int c;
	char *w = word;
	while(isspace(c = getch())){

	}
	if (c != EOF)
	{
		*w++ = c;
	}
	if (!isalpha(c))
	{
		*w = '\0';
		return c;
	}
	for( ; --lim > 0; w++){
		if (!isalnum(*w = getch()))
		{
			ungetch(*w);
			break;
		}
	}
	*w = '\0';
	return word[0];
}

int main(int argc, char const *argv[])
{
	struct tnode *root;
	char word[MAXWORD];
	root = NULL;
	while(getword(word, MAXWORD) != EOF){
		if (isalpha(word[0]))
		{
			root = addtree(root, word);
		}
	}
	treeprint(root);
	return 0;
}


	  //  1 Author
	  //  1 Date
	  //  1 Desc
	  //  1 E
	  //  2 EOF
	  //  1 Jun
	  //  3 MAXWORD
	  //  6 NULL
	  //  1 Zheng
	  //  4 addtree
	  //  1 argc
	  //  1 argv
	  //  1 break
	  //  7 c
	  //  1 chapter04
	  // 12 char
	  //  1 com
	  //  3 cond
	  //  1 const
	  //  4 count
	  //  1 ctype
	  //  1 d
	  //  1 define
	  //  3 else
	  //  1 for
	  //  3 getch
	  //  2 getword
	  //  4 h
	  //  9 if
	  //  5 include
	  //  7 int
	  //  1 isalnum
	  //  2 isalpha
	  //  1 isspace
	  //  5 left
	  //  2 lim
	  //  1 mail
	  //  1 main
	  //  2 malloc
	  //  1 n
	  //  1 outlook
	  //  5 p
	  //  1 printf
	  //  6 return
	  //  5 right
	  // 19 root
	  //  6 s
	  //  1 sizeof
	  //  1 stdio
	  //  1 stdlib
	  //  1 strcmp
	  //  2 strcopy
	  //  2 strdup1
	  //  1 string
	  //  1 strlen
	  // 10 struct
	  //  8 t
	  //  2 talloc
	  // 10 tnode
	  //  4 treeprint
	  //  1 ungetch
	  //  3 void
	  //  7 w
	  //  3 while
	  // 16 word
	  //  1 zhengjun1987