#include "baseball.h"

batter_list	*registration_batters(int num)
{
	batter_list	*list;

	list = (batter_list *)malloc(4 * sizeof(batter_list));
	if (list == NULL)
		error();
	if (num == 1)
		list->name = "近本";
	else if (num == 2)
		list->name = "中野";
	else if (num == 3)
		list->name = "森下";
	else
		list->name = "大山";
	if (num == 1)
		list->meet = 79;
	else if (num == 2)
		list->meet = 76;
	else if (num == 3)
		list->meet = 60;
	else
		list->meet = 76;
	if (num == 1)
		list->power = 69;
	else if (num == 2)
		list->power = 67;
	else if (num == 3)
		list->power = 69;
	else
		list->power = 78;
	if (num == 1)
		list->run = 85;
	else if (num == 2)
		list->run = 80;
	else if (num == 3)
		list->run = 69;
	else
		list->run = 67;
	if (num == 1 || num == 2)
		list->dominant = -1;
	else
		list->dominant = 1;
	if (num < 4)
		list->next = registration_batters(num + 1);
	else
		list->next = NULL;
	return (list);
}
