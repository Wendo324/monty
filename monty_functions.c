#include "monty.h"
/**
 * pall - Print All stack
 * @stack: Addres of first element in stack
 * @line_number: Number of actual line
 */
void pall(stack_t **stack, unsigned int line_number)
{
  stack_t *tmp = NULL;

  (void)line_number;
  if (!stack || !(*stack))
    return;
  tmp = *stack;
  while (tmp)
    {
      printf("%d\n", tmp->n);
      tmp = tmp->next;
    }
}
/**
 * pint - Print only element of stack
 * @stack: Addres of first element in strack
 * @line_number: Number of actual line
 */
void pint(stack_t **stack, unsigned int line_number)
{

  if ((!stack) || (!(*stack)))
    {
      fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
      exit(EXIT_FAILURE);
    }
  printf("%d\n", (*stack)->n);
}
/**
 * pop - Delete a stack element
 * @stack: Addres of first element in stack
 * @line_number: Number of actual line
 */
void pop(stack_t **stack, unsigned int line_number)
{
  stack_t *tmp;

  if (!(*stack) || (!stack))
    {
      fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
      exit(EXIT_FAILURE);
    }
  tmp = *stack;
  *stack = (*stack)->next;
  free(tmp);
}
/**
 * swap - swap the first two elements in the list
 * @stack: Addres of first element in stack
 * @line_number: Number of actual line
 */
void swap(stack_t **stack, unsigned int line_number)
{
  int aux;
  stack_t *tmp;

  if (!stack || !(*stack) || !(*stack)->next)
    {
      fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
      exit(EXIT_FAILURE);
    }
  tmp = (*stack)->next;
  aux = (*stack)->n;
  (*stack)->n = tmp->n;
  tmp->n = aux;
}
/**
 * add - Sum of the first two elements
 * @stack: Addres of first element in stack
 * @line_number: Number of actual line
 */
void add(stack_t **stack, unsigned int line_number)
{
  int sum;
  stack_t *tmp;

  if (!stack || !(*stack) || !(*stack)->next)
    {
      fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
      exit(EXIT_FAILURE);
    }
  tmp = (*stack)->next;
  sum = (*stack)->n + tmp->n;
  free(*stack);
  (*stack) = tmp;
  (*stack)->n = sum;
}
/**
 * sub - substract the top by the second top.
 * @stack: Head of the double linked list.
 * @line_number: Line of execution of command.
 * Return: Nothing, couse the struct specifications.
 */
void sub(stack_t **stack, unsigned int line_number)
{
  int res, i;
  stack_t *tmp = *stack;

  for (i = 0; tmp != NULL; i++)
    tmp = tmp->next;
  if (i < 2 || *stack == NULL)
    {
      fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
      exit(EXIT_FAILURE);
    }

  tmp = (*stack)->next;
  res = tmp->n - (*stack)->n;
  free(*stack);
  *stack = tmp;
  (*stack)->n = res;
}

/**
 * _div - divide the top by the second top.
 * @stack: Head of the double linked list.
 * @line_number: Line of execution of command.
 * Return: Nothing, couse the struct specifications.
 */
void _div(stack_t **stack, unsigned int line_number)
{
  int res;
  stack_t *tmp = *stack;

  if (!stack || !*stack || !(*stack)->next)
    {
      fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
      exit(EXIT_FAILURE);
    }
  if ((*stack)->n == 0)
    {
      fprintf(stderr, "L%u: division by zero\n", line_number);
      exit(EXIT_FAILURE);
    }

  tmp = (*stack)->next;
  res = tmp->n / (*stack)->n;
  free(*stack);
  *stack = tmp;
  (*stack)->n = res;
}

/**
 * _mul - multiplicate the top by the second top.
 * @stack: Head of the double linked list.
 * @line_number: Line of execution of command.
 * Return: Nothing, couse the struct specifications.
 */
void _mul(stack_t **stack, unsigned int line_number)
{
  int res;
  stack_t *tmp = *stack;

  if (!stack || !*stack || !(*stack)->next)
    {
      fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
      exit(EXIT_FAILURE);
    }
  tmp = (*stack)->next;
  res = (*stack)->n * tmp->n;
  free(*stack);
  *stack = tmp;
  (*stack)->n = res;
}
/**
 * _mod - get the module of the top by the second top.
 * @stack: Head of the double linked list.
 * @line_number: Line of execution of command.
 * Return: Nothing, couse the struct specifications.
 */
void _mod(stack_t **stack, unsigned int line_number)
{
  int res;
  stack_t *tmp = *stack;

  if (!stack || !*stack || !(*stack)->next)
    {
      fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
      exit(EXIT_FAILURE);
    }
  if ((*stack)->n == 0)
    {
      fprintf(stderr, "L%u: division by zero\n", line_number);
      exit(EXIT_FAILURE);
    }

  tmp = (*stack)->next;
  res = tmp->n % (*stack)->n;
  free(*stack);
  *stack = tmp;
  (*stack)->n = res;
}

/**
 * pchar - Print ascii character.
 * @stack: Head of the double linked list.
 * @line_number: Line of execution of command.
 * Return: Nothing, couse the struct specifications.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
  if (!stack || !(*stack))
    {
      fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
      exit(EXIT_FAILURE);
    }
  if ((*stack)->n < 32 || (*stack)->n > 126)
    {
      fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
      exit(EXIT_FAILURE);
    }
  printf("%c\n", (*stack)->n);
}
/**
 * push - Inizialice a node in the begin of the list.
 * @stack: Head of the double linked list.
 * @line_number: Line of execution of command.
 * Return: Nothing, couse the struct specifications.
 */
void push(stack_t **stack, unsigned int line_number)
{
  stack_t *new_node;
  char *value;
  int operator;

  new_node = malloc(sizeof(stack_t));
  if (new_node == NULL)
    {
      free(new_node);
      fprintf(stderr, "USAGE: monty file\n");
      exit(EXIT_FAILURE);
    }
  value = strtok(NULL, " \n\t\r");
  operator = manage_error(value, line_number);
  new_node->n = operator;
  new_node->prev = NULL;

  if (*stack == NULL)
    {
      *stack = new_node, new_node->next = NULL;
      return;
    }
  (*stack)->prev = new_node;
  new_node->next = *stack;
  *stack = new_node;
}

/**
 * nop - Do nothing.
 * @stack: Head of the double linked list.
 * @line_number: Line of execution of command.
 * Return: Nothing, couse the struct specifications.
 */

void nop(stack_t **stack, unsigned int line_number)
{
  (void)stack;
  (void)line_number;
}

/**
 * _rotl - Pass the top to the bottom of the linked list.
 * @stack: Head of the double linked list.
 * @line_number: Line of execution of command.
 * Return: Nothing, couse the struct specifications.
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
  stack_t *tmp1;
  stack_t *tmp2;

  if (!stack || !(*stack) || !(*stack)->next)
    return;

  (void)line_number;
  tmp1 = *stack;
  tmp2 = *stack;

  while (tmp1->next != NULL)
    tmp1 = tmp1->next;

  *stack = tmp2->next;
  (*stack)->prev = tmp2->prev;

  tmp2->next = tmp1->next;
  tmp1->next = tmp2;
  tmp2->prev = tmp1;
}

/**
 * _rotr - Pass the top to the bottom of the linked list.
 * @stack: Head of the double linked list.
 * @line_number: Line of execution of command.
 * Return: Nothing, couse the struct specifications.
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
  stack_t *tmp, *final, *b_final;

  if (!stack || !(*stack) || !(*stack)->next)
    return;

  (void)line_number;
  tmp = *stack;
  final = *stack;

  while (final->next != NULL)
    final = final->next;

  b_final = final->prev;
  b_final->next = final->next;

  final->next = tmp;
  final->prev = tmp->prev;
  tmp->prev = final;

  *stack = final;
}
/**
 * pstr - print string
 * @stack: Addres of first element of stack
 * @line_number: Num of line
 */
void pstr(stack_t **stack, unsigned int line_number)
{
  stack_t *tmp = (*stack);

  (void)line_number;
  if (!stack || !(*stack))
    goto exi;

  while (tmp)
    {
      if (tmp->n == 0)
	goto exi;
      if (tmp->n < 32 || tmp->n > 126)
	goto exi;
      printf("%c", tmp->n);
      tmp = tmp->next;
    }
 exi: printf("\n");
}
