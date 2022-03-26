#include <stdio.h>
#include <math.h>
#include <string.h>

int mealsPoints[5] = {0,0,0,0,0};
char meals[5][14] = {"Sushi" , "Kebab" , "Fish", "Burger","Pizza"};

int main() {
    int numOfGuests = 0;
    int tempValue = 0;
    int numOfMealsExceedThreshold = 0;
    int secondRoundIndex = 0;
    printf("Welcome to the perfect game of What2Eat \nHow many people you are? ");
    scanf("%d", &numOfGuests);
    int threshold = 10 * numOfGuests;
    if (numOfGuests == 0) {
        printf("Maybe you are fasting. Wait for a few hours.");
    } else if (numOfGuests == 1) {
        printf("Go and get some friend my buddy :(");
    } else {
        printf("Tonight we have 5 options they are\n");
        for (int i = 0; i < 5; ++i) {
            printf("%2d: %s\n", i + 1, meals[i]);
        }
        printf("Tonight we have 5 options they are\n");
        for (int i = 0; i < numOfGuests; ++i) {
            printf("Order your priority for these options with numbers defined at the head of line person %2d \n",
                   i + 1);
            for (int j = 0; j < 5; ++j) {
                scanf("%2d", &tempValue);
                mealsPoints[tempValue - 1] = mealsPoints[tempValue - 1] + pow(2, 4 - j);
            }
        }


        for (int i = 0; i < 5; ++i) if (mealsPoints[i] >= threshold) ++numOfMealsExceedThreshold;


        char stageTwoMeals[numOfMealsExceedThreshold][14];


        for (int i = 0; i < 5; ++i) {
            if (mealsPoints[i] >= threshold) {
                strcpy(stageTwoMeals[secondRoundIndex], meals[i]);
                secondRoundIndex++;
            }
        }
        if (numOfMealsExceedThreshold == 0) printf("You are staying at home");

        else if (numOfMealsExceedThreshold == 1) printf("You are going to eat %s", stageTwoMeals[0]);

        else {
            printf("In the second round remaining foods are ");
            for (int i = 0; i < numOfMealsExceedThreshold; ++i) {
                printf("%2d: %s\n", i + 1, stageTwoMeals[i]);
            }
            int secondRoundMealsPoints[numOfMealsExceedThreshold];
            memset(secondRoundMealsPoints, 0 , numOfMealsExceedThreshold*sizeof(secondRoundMealsPoints[0]));
            for (int i = 0; i < numOfGuests; ++i) {
                printf("Order your priority for these options with numbers defined at the head of line person %2d \n",
                       i + 1);
                for (int j = 0; j < numOfMealsExceedThreshold; ++j) {
                    scanf("%2d", &tempValue);
                    secondRoundMealsPoints[tempValue - 1] = secondRoundMealsPoints[tempValue - 1] + j;
                }
            }

            int indexOfPreferredMeal = 0;
            for (int i = 0; i < numOfMealsExceedThreshold; ++i) {
                if(secondRoundMealsPoints[i]<secondRoundMealsPoints[indexOfPreferredMeal]){
                    indexOfPreferredMeal = i;
                }
            }
            printf(" You are going to eat %s tonight", stageTwoMeals[indexOfPreferredMeal]);
        }



        return 0;
    }
}