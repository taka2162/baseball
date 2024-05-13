#include "baseball.h"

parameter	*pitcher;
batter_list	*batters;
int	ball = 0;
int	strike = 0;
int	out = 0;
int	runner[3] = {0, 0, 0};
int	front = -1;
int	rear = -1;
char	*first = "◇";
char	*second = "◇";
char	*third = "◇";

void	error(void)
{
	printf("\x1b[41m大雨だーー！中止！！！\x1b[m\n");
	exit(EXIT_FAILURE);
}

void	initialize_zone(int **zone, int num)
{
	int	i;
	int	j;

	i = 0;
	while (i < num)
	{
		j = 0;
		while (j < num)
		{
			zone[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	print_count(void)
{
	int	b;

	printf("\n\x1b[32mB\x1b[m: ");
	b = 0;
	while (b < ball)
	{
		printf("●");
		b++;
	}
	printf("\t\t\t\x1b[34mランナー\x1b[m ↓\n");
	printf("\x1b[33mS\x1b[m: ");
	b = 0;
	while (b < strike)
	{
		printf("●");
		b++;
	}
	printf("\t\t\t    %s\n", second);
	printf("\x1b[31mO\x1b[m: ");
	b = 0;
	while (b < out)
	{
		printf("●");
		b++;
	}
	printf("\t\t\t %s     %s\n", third, first);
}

void	print_pitching(void)
{
	if (batters->dominant == -1)
	{
		printf(	"  c\n"         	 						
				"   c \n"   		
				" cccc\n"		
				" ccc cc   1   2  3  4   5\n"		
				"cccccc    x \x1b[35m+--+--+--+\x1b[0m  x\n"
				"cccc      6 \x1b[35m  7  8  9 \x1b[0m 10\n"
				"cccc      x \x1b[35m+--+--+--+\x1b[0m  x\n"
				"cccc     11 \x1b[35m 12 13 14 \x1b[0m 15\n"
				"ccccc     x \x1b[35m+--+--+--+\x1b[0m  x\n"
		  	 	" ccccc   16 \x1b[35m 17 18 19 \x1b[0m 20\n"
		  	 	"  ccc     x \x1b[35m+--+--+--+\x1b[0m  x\n"
				" ccc     21  22 23 24  25\n"
				"ccc\n"
				"cccc\n"
    			"＿＿＿／ ／＿＿＿＿＿＿＿＼ ＼＿＿＿\n");
	}
	else
	{
		printf(	"                                 c   \n"         	 						
				"                                c    \n"   		
				"                               cccc\n"		
				"           1   2  3  4   5   cc ccc \n"		
				"           x \x1b[35m+--+--+--+\x1b[0m  x    cccccc \n"
				"           6 \x1b[35m  7  8  9 \x1b[0m 10      cccc \n"
				"           x \x1b[35m+--+--+--+\x1b[0m  x      cccc \n"
				"          11 \x1b[35m 12 13 14 \x1b[0m 15      cccc \n"
				"           x \x1b[35m+--+--+--+\x1b[0m  x     ccccc \n"
		  	 	"          16 \x1b[35m 17 18 19 \x1b[0m 20    ccccc  \n"
		  	 	"           x \x1b[35m+--+--+--+\x1b[0m  x     ccc   \n"
				"          21  22 23 24  25      ccc  \n"
				"                                 ccc \n"
				"                                cccc \n"
    			"＿＿＿／ ／＿＿＿＿＿＿＿＼ ＼＿＿＿\n");
	}
}

void	print_batting(void)
{
	printf("\n\n\n"
		"       o      cc\n"
		"        cc ccccc\n"
		"           cc c\n"
		"         ccc\n"
		"      cc      cc\n"
		"  cc          cc\n"
		"\x1b[33m--------------------------------------------------\x1b[m\n");
	usleep(250000);
	system("clear");
	printf("\n\n\n"
		"                     o\n"
		"                ccc\n"
		"              ccc\n"
		"            cc c\n"
		"          cccc\n"
		"       cc      cc\n"
		"  cc           cc\n"
		"\x1b[33m--------------------------------------------------\x1b[m\n");
	usleep(250000);
	system("clear");
	printf("\n\n\n"
		"                                              o\n"
		"                 cc\n"
		"              cccc\n"
		"           ccc c   c\n"
		"         ccccc       c\n"
		"       cc     cc\n"
		"  cc           cc\n"
		"\x1b[33m--------------------------------------------------\x1b[m\n");
	usleep(250000);
	system("clear");
	printf("\n\n\n"
		"\n"
		"            c    cc\n"
		"            c ccc\n"
		"           ccc cc\n"
		"  c      cccc\n"
		"   c c cc    cc\n"
		"              cc\n"
		"\x1b[33m--------------------------------------------------\x1b[m\n");
	usleep(1000000);
	system("clear");
	printf("\n\n\n"
		"\n"
		"                                           cc   c\n"
		"                                         ccc cc\n"
		"                                         ccccc\n"
		"                            o            ccc\n"
		"                                       cc  cc\n"
		"                                      cc      cc\n"
		"\x1b[33m--------------------------------------------------\x1b[m\n");
	usleep(250000);
	system("clear");
	printf("\n\n\n"
		"\n"
		"                                           cc\n"
		"                                       c cccc\n"
		"                            o        c cccccc\n"
		"                                 cc      ccc\n"
		"                                        cc cc\n"
		"                                      cc       cc\n"
		"\x1b[33m--------------------------------------------------\x1b[m\n");
	usleep(250000);
	system("clear");
	printf("\n\n\n"
		"\n"
		"                                    cc     cc\n"
		"                                        ccccc\n"
		"                                          ccc\n"
		"                                         ccc\n"
		"                                        cc cc\n"
		"                                      cc       cc\n"
		"\x1b[33m--------------------------------------------------\x1b[m\n");
	usleep(250000);
	system("clear");
	printf("\n\n\n"
		"                                              cc\n"
		"                                           ccc\n"
		"                                          cccc\n"
		"                                          cc\n"
		"                                         ccc\n"
		"                                       cc  cc\n"
		"                                       cc      cc\n"
		"\x1b[33m--------------------------------------------------\x1b[m\n");
}

void	print_result(int result)
{
	printf("\x1b[41m  ");
	if (result == SWING_OUT)
		printf("空振り！");
	else if (result == STRIKE)
		printf("ストライク！！");
	else if (result == BALL)
		printf("ボール");
	else if (result == FOUL)
		printf("ファウル！");
	else if (result == P_GROUNDER)
		printf("ピッチャーゴロ");
	else if (result == C_GROUNDER)
		printf("キャッチャーゴロ");
	else if (result == F_GROUNDER)
		printf("ファーストゴロ");
	else if (result == S_GROUNDER)
		printf("セカンドゴロ");
	else if (result == SS_GROUNDER)
		printf("ショートゴロ");
	else if (result == T_GROUNDER)
		printf("サードゴロ");
	else if (result == DOUBLE_PLAY)
		printf("ダブルプレー！");
	else if (result == P_LINER)
		printf("ピッチャーライナー");
	else if (result == F_LINER)
		printf("ファーストライナー");
	else if (result == S_LINER)
		printf("セカンドライナー");
	else if (result == SS_LINER)
		printf("ショートライナー");
	else if (result == T_LINER)
		printf("サードライナー");
	else if (result == RF_LINER)
		printf("ライトライナー");
	else if (result == CF_LINER)
		printf("センターライナー");
	else if (result == LF_LINER)
		printf("レフトライナー");
	else if (result == C_FLY)
		printf("キャッチャーフライ");
	else if (result == P_FLY)
		printf("ピッチャーフライ");
	else if (result == F_FLY)
		printf("ファーストフライ");
	else if (result == S_FLY)
		printf("セカンドフライ");
	else if (result == SS_FLY)
		printf("ショートフライ");
	else if (result == T_FLY)
		printf("サードフライ");
	else if (result == RF_FLY)
		printf("ライトフライ");
	else if (result == CF_FLY)
		printf("センターフライ");
	else if (result == LF_FLY)
		printf("レフトフライ");
	else if (result == RF_LINE_TWO_G || result == RF_LINE_TWO_L || result == RF_LINE_TWO_F)
		printf("ライト線へのツーベース！");
	else if (result == RF_HIT_G || result == RF_HIT_L)
		printf("ライト前ヒット！");
	else if (result == CF_HIT_G || result == CF_HIT_L)
		printf("センター前ヒット！");
	else if (result == LF_HIT_G || result == LF_HIT_L)
		printf("レフト前ヒット！");
	else if (result == R_C_TWO_L || result == R_C_TWO_F)
		printf("右中間へのツーベース！");
	else if (result == L_C_TWO_L || result == L_C_TWO_F)
		printf("左中間へのツーベース！");
	else if (result == RF_TWO_F)
		printf("ライトオーバーのツーベース！");
	else if (result == CF_TWO_F)
		printf("センターオーバーのツーベース！");
	else if (result == LF_TWO_F)
		printf("レフトオーバーのツーベース！");
	else if (result == RF_HOMERUN)
		printf("ライトスタンドへのホームラン！");
	else if (result == CF_HOMERUN)
		printf("センタースタンドへのホームラン！");
	else if (result == LF_HOMERUN)
		printf("レフトスタンドへのホームラン！");
	else if (result == BOUTOU)
		printf("暴投！！！！！");
	printf("\x1b[m\n");	
}

int	enqueue(int data)
{
	int	result;
	int	i;

	result = runner[2];
	i = 1;
	while (0 <= i)
	{
		runner[i] = runner[i + 1];
		i--;
	}
	return (result);
}

void	moveRunner(int result)
{
	if (result == BALL)
		runner
}

void	master(void)
{
	ball_bandle	*bandle;
	int			batting_ball;

	registration_param();
	batters = registration_batters(1);
	//while (batters != NULL)
	//{
	//	printf("%s\n", batters->name);
	//	batters = batters->next;
	//}
	while (out < 3)
	{
		print_count();
		print_pitching();
		bandle = pitching();
		system("clear");
		batting_ball = batting(bandle);
		print_batting();
		print_result(batting_ball);
		printf("\n\x1b[32mbatting_ball = %d\x1b[m\n", batting_ball);
		sleep(4);
		if (batting_ball == SWING_OUT || batting_ball == STRIKE)
		{	
			strike++;
			if (strike == 3)
			{
				out++;
				strike = 0;
			}
		}
		else if (batting_ball == FOUL && strike < 2)
			strike++;
		else if (batting_ball == BALL)
		{
			ball++;
			if (ball == 4)
			{
				
				ball = 0;
			}
		}
		else if (batting_ball < 0)
		{
			ball = 0;
			strike = 0;
			out++;
		}
		system("clear");
	}
}


int	main(void)
{
	unsigned int	seed;

	pitcher = (parameter *)malloc(sizeof(parameter));
	if (pitcher == NULL)
		error();
	seed = (unsigned int)time(NULL);
	srand(seed);
	master();
	free(pitcher);
	return (0);
}

    