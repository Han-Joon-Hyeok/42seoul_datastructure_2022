/*

	- 스택이 비어있다면, 바로 추가
	- 스택이 비어있지 않다면 다음과 같이 수행
		- 스택의 가장 위에 있는 요소(TopElement)가 현재 들어온 괄호와 짝이 맞는지 확인
		- 만약 같으면, pop(TopElement) 수행
		- 같지 않으면 오류 발생

*/

#include "../linkedstack/linkedstack.h"

int	isOpenBracket(LinkedStack *stack, StackNode node)
{
	char	c;

	c = node.data;
	if (c == '(' || c == '{' || c == '[')
		return (TRUE);
	return (FALSE);
}

int	isCloseBracket(LinkedStack *stack, StackNode node)
{
	char	c;

	c = node.data;
	if (c == ')' || c == '}' || c == ']')
		return (TRUE);
	return(FALSE);
}

int	checkBracketPairs(LinkedStack *stack, StackNode node)
{
	StackNode	*peek;

	if (isLinkedStackEmpty(stack))
		return (FALSE);
	peek = peekLS(stack);
	if (peek->data == '(' && node.data == ')')
	{
		popLS(stack);
		return (TRUE);

	}
	else if (peek->data == '{' && node.data == '}')
	{
		popLS(stack);
		return (TRUE);

	}
	else if (peek->data == '[' && node.data == ']')
	{
		popLS(stack);
		return (TRUE);
	}
	else
		return (FALSE);
	return (FALSE);
}

int checkBracketMatching(char *expr)
{
	int				i;
	int				result;
	StackNode		node;
	LinkedStack		*stack;

	i = 0;
	result = TRUE;
	stack = createLinkedStack();
	while (*(expr + i) != '\0' && result != FALSE)
	{
		node.data = *(expr + i);
		if (isOpenBracket(stack, node))
		{
			pushLS(stack, node);
		}
		else if (isCloseBracket(stack, node))
		{
			result = checkBracketPairs(stack, node);
		}
		i += 1;
	}
	if (!isLinkedStackEmpty(stack))
		return (FALSE);
	return (result);
}

#include <stdio.h>
int	main(int argc, char *argv[])
{
	if (argc >= 2)
	{
		printf("string: %s\n, result: %d", argv[1], checkBracketMatching(argv[1]));
	}
	return (0);
}