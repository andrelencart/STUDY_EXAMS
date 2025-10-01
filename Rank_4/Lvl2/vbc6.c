//This file is given at the exam

#include <stdio.h>
#include <malloc.h>
#include <ctype.h>

typedef struct node {
    enum {
        ADD,
        MULTI,
        VAL
    }   type;
    int val;
    struct node *l;
    struct node *r;
}   node;

node *parse_expr_r(char **s);
node *parse_term(char **s);
node *parse_factor(char **s);

node    *new_node(node n)
{
    node *ret = calloc(1, sizeof(n));
    if (!ret)
        return (NULL);
    *ret = n;
    return (ret);
}

void    destroy_tree(node *n)
{
    if (!n)
        return ;
    if (n->type != VAL)
    {
        destroy_tree(n->l);
        destroy_tree(n->r);
    }
    free(n);
}

void    unexpected(char c)
{
    if (c)
        printf("Unexpected token '%c'\n", c);
    else
        printf("Unexpected end of file\n");
}

int accept(char **s, char c)
{
    if (**s == c)
    {
        (*s)++;
        return (1);
    }
    return (0);
}

int expect(char **s, char c)
{
    if (accept(s, c))
        return (1);
    unexpected(**s);
    return (0);
}


node	*parse_factor(char **s)
{
	if (isdigit((unsigned char)**s)){
		node n = {.type = VAL, .val = **s - '0', .l = NULL, .r = NULL};
		(*s)++;
		return (new_node(n));
	}
	if (accept(s, '(')){
		node *e = parse_expr_r(s);
		if (!e)
			return (NULL);
		if (!expect(s, ')')){
			destroy_tree(e);
			return NULL;
		}
		return (e);
	}
	unexpected(**s);
	return NULL;
}

node *parse_term(char **s)
{
	node *left = parse_factor(s);
	if (!left)
		return NULL;
	while (accept(s, '*')){
		node *right = parse_factor(s);
		if (!right){
			destroy_tree(left);
			return NULL;
		}
		node n = {.type = MULTI, .l = left, .r = right};
		left = new_node(n);
		if (!left)
			return NULL;
	}
	return (left);
}

node *parse_expr_r(char **s)
{
	node *left = parse_term(s);
	if (!left)
		return NULL;
	while (accept(s, '+')){
		node *right = parse_term(s);
		if (!right){
			destroy_tree(left);
			return NULL;
		}
		node n = {.type = ADD, .l = left, .r = right};
		left = new_node(n);
		if (!left)
			return NULL;
	}
	return (left);
}

node    *parse_expr(char *s)
{
    char *p = s;
	node *ret = parse_expr_r(&p);

	if (!ret)
		return (NULL);
    if (*p)
    {
		unexpected(*p);
        destroy_tree(ret);
        return (NULL);
    }
    return (ret);
}

int eval_tree(node *tree)
{
    switch (tree->type)
    {
        case ADD:
            return (eval_tree(tree->l) + eval_tree(tree->r));
        case MULTI:
            return (eval_tree(tree->l) * eval_tree(tree->r));
        case VAL:
            return (tree->val);
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);
    node *tree = parse_expr(argv[1]);
    if (!tree)
        return (1);
    printf("%d\n", eval_tree(tree));
    destroy_tree(tree);
}