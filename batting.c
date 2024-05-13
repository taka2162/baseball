#include "baseball.h"

extern parameter	*pitcher;
extern batter_list	*batters;
extern int	out;
extern char	*first;
extern char	*second;
extern char	*third;

int	serch_slowest_ball(void)
{
	balltype_list	*head;
	int				slow;

	head = pitcher->balltype;
	slow = head->speed_rate;
	while (head->next != NULL)
	{
		if (head->speed_rate < slow)
			slow = head->speed_rate;
		head = head->next;
	}
	return ((pitcher->speed * slow) / 100 - 8);
}

void	free_breaking(int **before_breaking)
{
	int	i;

	i = 0;
	while (i < pitcher->style + 2)
	{
		free(before_breaking[i]);
		i++;
	}
	free(before_breaking);
}

int	breakingable(int focus[], int course[])
{
	int				**before_breaking;
	balltype_list	*head;
	int				i;

	before_breaking = (int **)malloc((pitcher->style + 2) * sizeof(int *));
	if (before_breaking == NULL)
		error();
	i = 0;
	while (i < pitcher->style + 2)
	{
		before_breaking[i] = (int *)malloc(2 * sizeof(int));
		if (before_breaking[i] == NULL)
			error();
		i++;
	}
	head = pitcher->balltype;
	i = 0;
	while (head != NULL)
	{
		before_breaking[i][0] = (focus[0] - head->turn[0]);
		before_breaking[i][1] = focus[1] - head->turn[1];
		//printf("focus = [%d, %d] before_breaking = [%d, %d] 球種: %s\n", focus[0], focus[1], before_breaking[i][0], before_breaking[i][1], head->name);
		//printf("focus = %d  breaking_points[%d] = %d   球種: %s\n", focus, i, breaking_points[i], head->name);
		head = head->next;
		i++;
	}
	i = 0;
	while (i < pitcher->style + 2)
	{
		if (before_breaking[i][0] == course[0] && before_breaking[i][1] == course[1])
		{
			free(before_breaking);
			return (1);
		}
		i++;
	}
	free_breaking(before_breaking);
	return (0);
}

int	timing_dif(ball_bandle *bandle, int timing)
{
	int	dif;

	dif = bandle->speed - timing;
	return (dif);
}

//int	percent(void)
//{
//	int	percent;

//	percent = rand() % 100 + 1;
//	return (percent);
//}

int	calculate_angle_x(int angle_y, int dif, int sign, int energy)
{
	int	percent;
	int	dominant;
	int	angle_x;

	if (batters->dominant == 1)
		dif *= -1;
	if (angle_y == 0)
	{
		if (sign == 1)
		{
			if (-4 < dif && dif <= 4)
				return (CF_HIT_G);
			else if (-12 < dif && dif < -4)
				return (RF_HIT_G);
			else if (dif < -12)
			{
				if (5 < rand() % 10 + 1)
					return (FOUL);
				return (RF_LINE_TWO_G);
			}
			else if (4 < dif && dif <= 12)
				return (LF_HIT_G);
			else if (12 < dif)
			{
				if (5 < rand() % 10 + 1)
					return (FOUL);
				return (LF_LINE_TWO_G);
			}
		}
		else
		{
			if (first == "◆" && out < 2)
			{
				if (rand() % 10 + 1 > 5)
					return (DOUBLE_PLAY);
			}
			if (energy < 70)
				return (P_GROUNDER - rand() % 2);
			else if (-4 < dif && dif <= 4)
				return (SS_GROUNDER - rand() % 2);
			else if (-12 < dif && dif < -4)
				return (S_GROUNDER);
			else if (dif < -12)
				return (F_GROUNDER);
			else if (4 < dif && dif <= 12)
				return (SS_GROUNDER);
			else if (12 < dif)
				return (T_GROUNDER);
		}
	}
	else if (angle_y == 1)
	{
		if (sign == 1)
		{
			if (-4 < dif && dif <= 4)
				return (CF_HIT_L);
			else if (-12 < dif && dif < -4)
				return (R_C_TWO_L - rand() % 2);
			else if (dif < -12)
			{
				if (5 < rand() % 10 + 1)
					return (FOUL);
				return (RF_LINE_TWO_L);
			}
			else if (4 < dif && dif <= 12)
				return (LF_HIT_L - rand() % 2);
			else if (12 < dif)
			{
				if (5 < rand() % 10 + 1)
					return (FOUL);
				return (LF_LINE_TWO_L);
			}
		}
		else
		{
			if (energy < 70)
				return (P_LINER);
			else if (-4 < dif && dif <= 4)
				return (CF_LINER);
			else if (-12 < dif && dif < -4)
				return (RF_LINER);
			else if (dif < -12)
				return (S_LINER - rand() % 2);
			else if (4 < dif && dif <= 12)
				return (LF_LINER);
			else if (12 < dif)
				return (T_LINER - rand() % 2);
		}
	}
	else if (angle_y == 2)
	{
		if (sign == 1)
		{
			if (-4 < dif && dif <= 4)
			{
				if (90 <= energy)
					return (CF_HOMERUN);
				return (CF_TWO_F);
			}
			else if (-12 < dif && dif < -4)
			{
				if (90 <= energy)
					return (RF_HOMERUN);
				return (R_C_TWO_F - rand() % 2);
			}
			else if (dif < -12)
			{
				if (5 < rand() % 10 + 1)
					return (FOUL);
				return (RF_LINE_TWO_F);
			}
			else if (4 < dif && dif <= 12)
			{
				if (energy <= 90)
					return (LF_HOMERUN);
				return (LF_HIT_G - rand() % 2);
			}
			else if (12 < dif)
			{
				if (5 < rand() % 10 + 1)
					return (FOUL);
				return (LF_LINE_TWO_F);
			}
		}
		else
		{
			if (energy < 70)
				return (P_FLY - rand() % 2);
			else if (-4 < dif && dif <= 4)
				return (CF_FLY);
			else if (-12 < dif && dif < -4)
				return (RF_FLY);
			else if (dif < -12)
				return (S_FLY - rand() % 2);
			else if (4 < dif && dif <= 12)
				return (LF_FLY);
			else if (12 < dif)
				return (T_FLY - rand() % 2);
		}
	}
}

int	calculate_batting(int angle_y, int dif, int energy)
{
	int	percent;
	int	result;
	int	sign;

	percent = rand() % 100 + 1;
	if (angle_y == 0)
	{
		if (percent < 40 + dif * 2 + (100 - energy) / 3)
			sign = -1;
		else
			sign = 1;
		result = calculate_angle_x(angle_y, dif, sign, energy);
	}
	else if (angle_y == 1)
	{
		if (percent < 20 + dif * 2 + (100 - energy) / 3)
			sign = -1;
		else
			sign = 1;
		result = calculate_angle_x(angle_y, dif, sign, energy);
	}
	else if (angle_y == 2)
	{
		if (percent < 30 + dif * 2 + (100 - energy) / 3)
			sign = -1;
		else
			sign = 1;
		result = calculate_angle_x(angle_y, dif, sign, energy);
	}
	return (result);
}

int	abs(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

int	swing(ball_bandle *bandle, int focus[], int timing)
{
	int	result;
	int	percent;
	int	angle_y;
	int	dif;
	int	energy;

	dif = timing_dif(bandle, timing);
	percent = rand() % 100 + 1;
	printf("percent = %d\n", percent);
	if (focus[0] == bandle->breaking[0] && focus[1] == bandle->breaking[1])
	{
		if (0 < percent && percent <= 10 || 20 < abs(dif))
			return (SWING_OUT);
		else if (10 < percent && percent <= 30)
		{
			angle_y = 0;
			energy = 100;
		}
		else if (30 < percent && percent <= 65)
		{
			angle_y = 1;
			energy = 100;
		}
		else
		{
			angle_y = 2;
			energy = 100;
		}
		result = calculate_batting(angle_y, dif, energy);
	}
	else if (focus[0] == bandle->breaking[0] && (focus[1] == bandle->breaking[1] + 1 || focus[1] == bandle->breaking[1] - 1))
	{
		if (0 < percent && percent <= 20 || 20 < abs(dif))
			return (SWING_OUT);
		else if (20 < percent && percent <= 50)
		{
			angle_y = 0;
			energy = 70;
		}
		else if (50 < percent && percent <= 80)
		{
			angle_y = 1;
			energy = 80;
		}
		else
		{
			angle_y = 2;
			energy = 70;
		}
		result = calculate_batting(angle_y, dif, energy);
	}
	else if (focus[0] == bandle->breaking[0] + 1 && focus[1] == bandle->breaking[1])
	{
		if (0 < percent && percent <= 40 || 20 < abs(dif))
			return (SWING_OUT);
		else if (40 < percent && percent <= 80)
		{
			angle_y = 0;
			energy = 70;
		}
		else if (80 < percent && percent <= 95)
		{
			angle_y = 1;
			energy = 80;
		}
		else
		{
			angle_y = 2;
			energy = 50;
		}
		result = calculate_batting(angle_y, dif, energy);
	}
	else if (focus[0] == bandle->breaking[0] + 1 && (focus[1] == bandle->breaking[1] + 1 || focus[1] == bandle->breaking[1] - 1))
	{
		if (0 < percent && percent <= 35 || 20 < abs(dif))
			return (SWING_OUT);
		else if (35 < percent && percent <= 80)
		{
			angle_y = 0;
			energy = 60;
		}
		else if (80 < percent && percent <= 95)
		{
			angle_y = 0;
			energy = 70;
		}
		else
		{
			angle_y = 0;
			energy = 30;
		}
		result = calculate_batting(angle_y, dif, energy);
	}
	else
		if (0 < percent && percent <= 50 || 20 < abs(dif))
			return (SWING_OUT);
		else if (50 < percent && percent <= 70)
		{
			angle_y = 0;
			energy = 60;
		}
		else if (70 < percent && percent <= 85)
		{
			angle_y = 0;
			energy = 70;
		}
		else
		{
			angle_y = 0;
			energy = 30;
		}
		result = calculate_batting(angle_y, dif, energy);
	return (result);
}

int	batting(ball_bandle	*bandle)
{
	int	result;
	int	focus[2];
	int	timing;
	int	percent;

	if (1 <= bandle->breaking[0] && bandle->breaking[0] <= 3 && 1 <= bandle->breaking[1] && bandle->breaking[1] <= 3)
		result = STRIKE;
	else
		result = BALL;
	focus[0] = rand() % 3 + 1;
	//printf("focus[0] = %d\n", focus[0]);
	focus[1] = rand() % 3 + 1;
	//printf("focus[1] = %d\n", focus[1]);
	timing = pitcher->speed - (rand() % (pitcher->speed - serch_slowest_ball()));
	//printf("timing = :%d\n", timing);
	percent = rand() % 100 + 1;
	if (focus[0] == bandle->course[0] && focus[1] == bandle->course[1])
		result = swing(bandle, focus, timing);
	else if (breakingable(focus, bandle->course) == 1)
	{
		//if (percent < 100 / (pitcher->style + 1))
		result = swing(bandle, focus, timing);
	}
	//else if (focus[0] == bandle->course[0] + 1 || focus[1] == bandle->course[1] + 1 || focus[1] == bandle->course[1] - 1)
	//	result = swing(bandle, focus, timing);
	return (result);
}
