#ifndef BASEBALL_H

#define BASEBALL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <string.h>

#define STRIKE 100
#define BALL 101
#define	SWING_OUT 0
#define FOUL -10
#define P_GROUNDER -1
#define C_GROUNDER -2
#define	F_GROUNDER -3
#define S_GROUNDER -4
#define SS_GROUNDER -5
#define T_GROUNDER -6
#define DOUBLE_PLAY -7
#define P_LINER -11
#define F_LINER -12
#define S_LINER -13
#define SS_LINER -14
#define T_LINER -15
#define RF_LINER -16
#define CF_LINER -17
#define LF_LINER -18
#define C_FLY -21
#define P_FLY -22
#define F_FLY -23
#define S_FLY -24
#define SS_FLY -24
#define T_FLY -26
#define RF_FLY -27
#define	CF_FLY -28
#define LF_FLY -29

#define RF_LINE_TWO_G 1
#define RF_HIT_G 2
#define CF_HIT_G 3
#define LF_HIT_G 4
#define LF_LINE_TWO_G 5
#define RF_LINE_TWO_L 11
#define RF_HIT_L 12
#define R_C_TWO_L 13
#define CF_HIT_L 14
#define L_C_TWO_L 15
#define LF_HIT_L 16
#define LF_LINE_TWO_L 17
#define RF_LINE_TWO_F 21
#define RF_TWO_F 22
#define R_C_TWO_F 23
#define CF_TWO_F 24
#define L_C_TWO_F 25
#define LF_TWO_F 26
#define LF_LINE_TWO_F 27
#define RF_HOMERUN 31
#define CF_HOMERUN 32
#define LF_HOMERUN 33
#define BOUTOU 1000

typedef struct balltype
{
	char				*name;
	char				*explanation;
	int					speed_rate;
	int					turn[2];
	struct balltype		*next;
}	balltype_list;

typedef struct ball_bandle
{
	int				speed;
	int				course[2];
	int				breaking[2];
}	ball_bandle;


typedef struct p
{
	char			*name;
	int				speed;
	balltype_list	*balltype;
	int				style;
	int				dominant_hand;
}	parameter;

typedef struct	b
{
	char		*name;
	int			meet;
	int			power;
	int			run;
	int			dominant;
	struct b	*next;
}	batter_list;

void		error(void);
void		print_pitching(void);
ball_bandle	*pitching(void);
void		print_count(void);
void		registration_param(void);
batter_list	*registration_batters(int num);
int			batting(ball_bandle	*bandle);
void		print_batting(void);

#endif