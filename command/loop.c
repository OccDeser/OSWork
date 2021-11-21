#include "stdio.h"

int sleep(int times){
    int t = 0;
    for(int i = 0; i < times; i++){
        for(int j = 0; j < 100; j++){
            for (int k = 0; k < 10000; k++){
                if(k){
                    t = (t + i * j) / k;
                }
            }
        }
    }
    return t;
}

int main(int argc, char * argv[])
{
	int cnt = 0;
    while (1)
    {
        printf("%d ", cnt);
        sleep(1);
        cnt++;
    }
	return 0;
}
