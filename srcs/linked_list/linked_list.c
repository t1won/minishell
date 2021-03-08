/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 08:47:55 by tseo              #+#    #+#             */
/*   Updated: 2021/03/07 09:19:37 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

/*
** 1. 노드 생성
** 2. 노드 삽입
** 3. 리스트 삭제
*/


t_cmd	*create_node(t_cmd new_data)
{
	t_cmd* new_node = (t_cmd *)malloc(sizeof(t_cmd));

	// 세부 데이터 집어 넣어주기
	*new_node = new_data; // 바로 대입 가능?
	new_node->prev = NULL;
	new_node->next = NULL;

	return (new_node);
}

void	append_node(t_cmd **head, t_cmd *new_node)
{
	// head가 NULL이면 새로운 노드가 HEAD
	if ((*head) == NULL)
		*head = new_node;
	else
	{
		// 테일을 찾아 new_node 연결
		t_cmd *tail = (*head);
		while (tail->next != NULL)
			tail = tail->next;
		tail->next = new_node;
		new_node->prev = tail; // 기존 테일을 새로운 테일의 prev가 가리키게
	}
}
