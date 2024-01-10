#include <stdio.h>

int main()
{
	float highscore[5];

    for (int i = 0; i < 5; ++i) {
        printf("High score #%d ",i+1);
        scanf("%f",&highscore[i]);
    }
	puts("Here are the high scores:");
    for (int i = 0; i < 5; ++i) {
        printf("#%d %.2f\n",i+1,highscore[i]);
    }

	return(0);
}

