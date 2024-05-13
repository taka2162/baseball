#include "baseball.h"

extern parameter	*pitcher;

balltype_list	*serch_balltype(balltype_list *balltype, int num)
{
	balltype_list	*head;
	int				i;

	head = balltype;
	i = 1;
	while (i < num)
	{
		head = head->next;
		i++;
	}
	return (head);
}

int	scan_balltype(void)
{
	balltype_list	*head;
	int				balltype;
	int				num;

	head = pitcher->balltype;
	num = 1;
	printf("\n++球種を選んで！++\n\n");
	while (head != NULL)
	{
		printf("%d. %s\t--%s\n", num, head->name, head->explanation);
		head = head->next;
		num++;
	}
	while (1)
	{
		scanf("%d", &balltype);
    	if (balltype < 1 || num - 1 < balltype)
   		{
        	printf("\e[%dF\e[J", num + 2);
			printf("サインミス！！\n");
			sleep(1);
			printf("\e[K\e[A\e[K");
   		}
		else
		{
			printf("\e[%dF\e[J", num + 2);
			printf("--選んだ球種: %s\n", serch_balltype(pitcher->balltype, balltype)->name);
			break;
		}
	}
	return (balltype);
}

void	*scan_course(ball_bandle *bandle)
{
	int	course;
	int	result[2];
	int	row;
	int	col;

	while (1)
	{
		printf("\n++コースを選んで！ピンクの部分がストライクゾーンだ！++\n※ 選んだコースから変化します。\n");
		scanf("%d", &course);
		if (course < 1 || 25 < course)
		{
			printf("\e[3A\e[J");
			printf("サインミス！！\n");
			sleep(1);
			printf("\e[K\e[A\e[K");
		}
		else
		{
			printf("\e[3A\e[J");
			printf("--選んだコース: %d\n", course);
			break;
		}
	}
	row = course / 5;
	col = course % 5 - 1;
	//printf("row = %d\ncol = %d\n", row, col);
	bandle->course[0] = row;
	bandle->course[1] = col;
}

ball_bandle	*pitching(void)
{
	balltype_list	*selected_ball;
	ball_bandle		*bandle;

	bandle = (ball_bandle *)malloc(sizeof(ball_bandle));
	if (bandle == NULL)
		error();
	selected_ball = serch_balltype(pitcher->balltype, scan_balltype());
	//printf("pitcher->speed = %d\nspeed->rate = %d\n", pitcher->speed, selected_ball->speed_rate);
	bandle->speed = (pitcher->speed * selected_ball->speed_rate) / 100 - (rand() % 8);
	//printf("bandle->speed = %d\n", bandle->speed);
	scan_course(bandle);
	bandle->breaking[0] = bandle->course[0] + selected_ball->turn[0];
	bandle->breaking[1] = bandle->course[1] + selected_ball->turn[1] * pitcher->dominant_hand;
	//printf("breaking[0] = %d\nbreaking[1] = %d\n", bandle->breaking[0], bandle->breaking[1]);
	//bandle->breaking = (bandle->course + selected_ball->turn[0] * 5 * pitcher->dominant_hand) + selected_ball->turn[1] * pitcher->dominant_hand;
	//printf("bandle->breaking[0] = %d\n", bandle->breaking);
	return (bandle);
}
