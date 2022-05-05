#include "minishell.h"

t_tag	*tag_init(void *data, int type)
{
	t_tag	*tag;

	tag = (t_tag *)malloc(sizeof(tag));
	if (tag == NULL)
		return (NULL);
	tag->data = data;
	tag->type = type;
	tag->next = NULL;
	return (tag);
}

t_tag	*tag_last(t_tag *head)
{
	while (head->next != NULL)
		head = head->next;
	return (head);
}

t_tag	*tag_add_back(t_tag **head, t_tag *new)
{
	if (*head == NULL)
		*head = new;
	else
		tag_last(*head)->next = new;
}
