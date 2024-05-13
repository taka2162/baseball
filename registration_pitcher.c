#include "baseball.h"

extern parameter	*pitcher;

balltype_list	*add_balltype_list(int balltype, balltype_list *list)
{
	balltype_list	*ball;
    balltype_list    *head;
	char			*name;
	char			speed;

	ball = (balltype_list *)malloc(sizeof(balltype_list));
	if (ball == NULL)
		error();
    head = list;    
    while (list->next != NULL)
        list = list->next;
	if (balltype == 1)
	{
		ball->name = "スライダー";
		ball->explanation = "利き腕と反対側に曲がる球。利き腕の同じバッターに効果的。";
		ball->speed_rate = 87;
		ball->turn[0] = 0;
		ball->turn[1] = -1;
		ball->next = NULL;
	}
	// {"スライダー", 87, [0, -1], *list};
	else if (balltype == 2)
	{
		ball->name = "カーブ";
		ball->explanation = "利き腕と反対側に曲がりながら落ちる球。タイミングを外すことができる。";
		ball->speed_rate = 78;
		ball->turn[0] = 1;
		ball->turn[1] = -1;
		ball->next = NULL;
	}
		//balltype_list	ball = {"カーブ", 78, [-1, -1], *list};
	else if (balltype == 3)
	{
		ball->name = "フォーク";
		ball->explanation = "打者の手元で沈み込む球。空振りを誘いやすい。";
		ball->speed_rate = 90;
		ball->turn[0] = 1;
		ball->turn[1] = 0;
		ball->next = NULL;
	}
		//balltype_list	ball = {"フォーク", 90, [1, 0], *list}:
	else if (balltype == 4)
	{
		ball->name = "シンカー";
		ball->explanation = "利き腕側に曲がりながら落ちる球。球速は遅いがよく曲がる。";
		ball->speed_rate = 83;
		ball->turn[0] = 1;
		ball->turn[1] = 1;
		ball->next = NULL;
	}
		//balltype_list	ball = {"シンカー", 83, [1, 1], *list};
	else if (balltype == 5)
	{
		ball->name = "シュート";
		ball->explanation = "利き腕側に曲がる球。バットの芯を外して詰まらせることができる。";
		ball->speed_rate = 96;
		ball->turn[0] = 0;
		ball->turn[1] = 1;
		ball->next = NULL;
	}
		//balltype_list	ball = {"シュート", 96, [0, 1], *list};
	list->next = ball;
    return (head);
}

int    *sort_balltype(int style)
{
    int    *sortList;
    int    balltypeCode;
    int    i;
    int    start;
    int    tmp;
    
    sortList = (int *)calloc((style + 1) * sizeof(int), 0);
    if (sortList == NULL)
        error();
    i = 0;    
    while(i <= style)
    {
        balltypeCode = rand() % 5 + 1;
        i = 0;
        //printf("balltypeCode = %d\n", balltypeCode);
        while (i <= style)
        {
            if (sortList[i] == balltypeCode)
                break;
            if (sortList[i] == 0)
            {
                //printf("sortList [i] = balltypeCode;\n");
                sortList[i] = balltypeCode;
                break;
            }
            i++;
        }
    }
    start = 0;
    while (start <= style)
    {
        i = start;
        while (i < style)
        {
            if (sortList[i + 1] < sortList[i])
            {
                tmp = sortList[i + 1];
                sortList[i + 1] = sortList[i];
                sortList[i] = tmp;
            }
            i++;
        }
        start++;
    }
    return (sortList);
}

balltype_list	*create_balltype(int style)
{
	balltype_list	*list;
    int				*sortList;
	int		      	i;

	list = (balltype_list *)malloc(sizeof(balltype_list));
	if (list == NULL)
		error();
    sortList = sort_balltype(style);    
    list->name = "ストレート";
	list->explanation = "まっすぐ突き刺さるような球。一番球速が出るが、変化はしない。";
	list->speed_rate = 100;
	list->turn[0] = 0;
	list->turn[1] = 0;
	list->next = NULL;
    i = 0;
    while (i <= style)
    {
        //printf("sorrList[i] = %d\ni = %d\n", sortList[i], i);
        list = add_balltype_list(sortList[i], list);
        i++;
    }
	free(sortList);
	return (list);
}

void	registration_param(void)
{
	char			name[24];
	int				dominant;

	while (1)
	{
		printf("名前は何？\n");
		scanf("%s", name);
		if (strlen(name) > 24)
		{
			printf("\e[2A\e[K");
			printf("名前が長すぎる！\n");
			sleep(1);
			printf("\e[K\e[A\e[K");
		}
		else
		{
			printf("\e[2A\e[K");
			printf("名前: %s\n", name);
			break ;
		}
	}
	pitcher->name = name;
	dominant = 0;
	while (1)
	{
		printf("右利き？左利き？\n1: 右\n2: 左\n");
		scanf(" %d", &dominant);
		if (dominant != 1 && dominant != 2)
		{
			printf("\e[4A\e[K");
			printf("さては腕が3本あるな！\n");
			sleep(1);
			printf("\e[K\e[A\e[K");
		}
		else
		{
			printf("\e[4A\e[K");
			if (dominant == 1)
				printf("利き腕: 右\n");
			else
				printf("利き腕: 左\n");
			break ;
		}
	}
	if (dominant == 1)
		pitcher->dominant_hand = dominant;
	else
		pitcher->dominant_hand = -1;
	while (1)
	{
		printf("ピッチングスタイルは？\n1: 圧倒的な球威\n2: 正確なコントロール\n3: 多彩な変化球\n");
		scanf("%d", &pitcher->style);
		if (pitcher->style < 1 || 3 < pitcher->style)
		{
			printf("\e[5A\e[J");
			printf("そのスタイルじゃ戦えない！\n");
			sleep(1);
			printf("\e[K\e[A\e[K");
		}
		else
		{
			printf("\e[5A\e[J");
			if (pitcher->style == 1)
				printf("ピッチングスタイル: 剛腕\n");
			else if (pitcher->style == 2)
				printf("ピッチングスタイル: 精密機械\n");
			else
				printf("ピッチングスタイル: 変幻自在\n");
			break ;
		}
	}
	if (pitcher->style == 1)
		pitcher->speed = rand() % 7 + 155;
	else if (pitcher->style == 2)
		pitcher->speed = rand() % 7 + 147;
	else if (pitcher->style == 3)
		pitcher->speed = rand() % 7 + 139;
	pitcher->balltype = create_balltype(pitcher->style);
}