#include <stdio.h>

int main( int argc, char *argv[] ) {
    int proceed = 1;
    int map[100][20] = { 0 }; 
    const char *directions[4] = {"North", "East", "South", "West"};
    int directionX[4]         = {      0,      1,       0,     -1}; 
    int directionY[4]         = {     -1,      0,       1,      0}; 
    int currentPosition[] = {2, 2};
    int currentDirection = 0;
    int player = 2;
    int path = 1;
    int argsCheck = 0;
    int argsIndex = 0;
    map[2][2] = player;
    if(argc > 0){
        argsCheck = 1;
    }
    while(proceed == 1){
        char input[1];
        for(int y = 0; y<20; y++){
            for(int x = 0; x<100; x++){
                if(map[x][y] == 0){
                    printf("░");
                }else if (map[x][y] == 2){
                    printf("P");
                }
                else{
                    printf("#");
                }
            }
            printf("\n");
        }
        printf("Please traverse the world and explore using these commands: \n  W - Walk Forward\n  A - Turn Left\n  D - Turn Right\n  E - Check Direction\n  Q - Quit the Game\n");
        if(argsCheck == 0){ 
            scanf("%s", input);
        }else{
            if(argc == argsIndex){
                argsCheck = 0;
                *input = *"e";
            }else{
                *input = *argv[argsIndex];
                argsIndex++;
            }
        }
        switch(input[0]){
            case 'w' :
                map[currentPosition[1]][currentPosition[0]] = path;
                
                if(!((currentPosition[0] + directionX[currentDirection] < 0) || 
(currentPosition[0] + directionX[currentDirection] > 100))){
                    currentPosition[0] = currentPosition[0] + 
directionX[currentDirection];
                }
                if(!((currentPosition[1] + directionY[currentDirection] < 0) || 
(currentPosition[1] + directionY[currentDirection] > 20))){
                    currentPosition[1] = currentPosition[1] + 
directionY[currentDirection];
                }
                map[currentPosition[1]][currentPosition[0]] = player;
                break;
            case 'a' :
                currentDirection--;
                if(currentDirection < 0){
                    currentDirection = 3;
                }
                break;
            case 'd' :
                currentDirection++;
                if(currentDirection > 3){
                    currentDirection = 0;
                }
                break;
            case 'e' :
                printf("Your current direction is %s! \n", 
directions[currentDirection]);
                break;
            case 'q' :
                proceed = 0;
                break;
            default: 
                printf("You must enter one of the commands!");
        }
    }
    return 0;
}