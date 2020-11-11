#include <stdio.h>
#include <stdlib.h>

typedef struct		s_list
{
	char			c;
	struct s_list	*front;
	struct s_list	*next;
}					t_list;

t_list	*lst_new(char c)
{
	t_list	*node;

	if (!(node = (t_list *)malloc(sizeof(t_list))))
		return (0);
	node->c = c;
	node->front = NULL;
	node->next = NULL;
	return (node);
}

int	free_all(t_list *head)
{
	t_list	*next;

	next = head->next;
	while (head->next)
	{
		free(head);
		head = next;
		next = head->next;
	}
	free(head);
	return (0);
}

t_list *remove_front_node(t_list *cur, t_list **head)
{
	t_list *tmp;

	tmp = cur->front;
	if (cur->front->front == NULL)
		cur->front = NULL;
	else
	{
		cur->front->front->next = cur;
		cur->front = cur->front->front;
	}
	free(tmp);
	if (cur->front == NULL)
		*head = cur;
	return (cur);
}

t_list *add_front_node(t_list *cur, t_list **head)
{
	char c;

	getchar();
	scanf("%c", &c);
	if (cur->front == NULL)
	{
		if (!(cur->front = lst_new(c)))
			return (0);
		cur->front->next = cur;
		*head = cur->front;
	}
	else
	{
		if (!(cur->front->next = lst_new(c)))
			return (0);
		cur->front->next->front = cur->front;
		cur->front->next->next = cur;
		cur->front = cur->front->next;
	}
	return (cur);
}

int main(void)
{
	int		N;
	char	c;
	t_list	*head;
	t_list	*cur;
	t_list	*tmp;

	scanf("%c", &c);
	if (!(head = lst_new(c)))
		return (1);
	cur = head;
	while (1)
	{
		scanf("%c", &c);
		if (c == '\n')
			break ;
		if (!(cur->next = lst_new(c)))
			return (1);
		cur->next->front = cur;
		cur = cur->next;
	}
	if (!(cur->next = lst_new('\0')))
		return (1);
	cur->next->front = cur;
	cur = cur->next;
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++)
	{
		scanf("%c", &c);
		if (c == 'L' && cur->front != NULL)
			cur = cur->front;
		else if (c == 'D' && cur->next != NULL)
			cur = cur->next;
		else if (c == 'B' && cur->front != NULL)
			cur = remove_front_node(cur, &head);
		else if (c == 'P')
			if (!(cur = add_front_node(cur, &head)))
				return (1);
		getchar();
	}
	cur = head;
	while (cur->c)
	{
		printf("%c", cur->c);
		cur = cur->next;
	}
	printf("\n");
	free_all(head);
	return (0);
}