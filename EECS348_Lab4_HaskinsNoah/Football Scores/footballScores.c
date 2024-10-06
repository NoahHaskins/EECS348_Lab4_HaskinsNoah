#include <stdio.h>

void findCombinations(int score) {
    int td6, fg3, safety2, td8, td7;
    
    printf("Possible combinations of scoring plays if a team\'s score is %d:\n", score);
    
    for (td8 = 0; td8 * 8 <= score; td8++) {
        for (td7 = 0; td7 * 7 + td8 * 8 <= score; td7++) {
            for (td6 = 0; td6 * 6 + td7 * 7 + td8 * 8 <= score; td6++) {
                for (fg3 = 0; fg3 * 3 + td6 * 6 + td7 * 7 + td8 * 8 <= score; fg3++) {
                    for (safety2 = 0; safety2 * 2 + fg3 * 3 + td6 * 6 + td7 * 7 + td8 * 8 <= score; safety2++) {
                        if (td6 * 6 + fg3 * 3 + safety2 * 2 + td8 * 8 + td7 * 7 == score) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", 
                                    td8, td7, td6, fg3, safety2);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int score;
    
    while (1) {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        
        if (score <= 1) {
            break;
        }
        
        findCombinations(score);
    }
    
    return 0;
}
