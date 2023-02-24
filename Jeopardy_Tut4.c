/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_LEN 256
#define NUM_CATEGORIES 3
#define NUM_QUESTIONS 12
#define NUM_PLAYERS 4

//Question Struct
typedef struct
{
  char category[MAX_LEN];
  char question[MAX_LEN];
  char answer[MAX_LEN];
  int value;
  bool answered;
} question;

//Player Strcut 
typedef struct {
    char name[MAX_LEN];
    int score;
} player;

player players[NUM_PLAYERS];

static char categories[NUM_CATEGORIES][256] = {
  "Programming",
  "Algorithms",
  "Databases"
};

question questions[NUM_QUESTIONS];

void initialize_game ()
{
    
    //Assiging values to variables
    //4 questions per category 
  strcpy(questions[0].category, "Programming");
  strcpy(questions[0].question, "What is an API");
  strcpy(questions[0].answer, "Interface");
  questions[0].value = 200;
  questions[0].answered = false;

  strcpy(questions[1].category, "Programming");
  strcpy(questions[1].question, "Finish the word: A simple language to learn is P____?");
  strcpy(questions[1].answer, "Python");
  questions[1].value = 400;
  questions[1].answered = false;

  strcpy(questions[2].category, "Programming");
  strcpy(questions[2].question, "Which programming language is used to develop apps in Andrioid?");
  strcpy(questions[2].answer, "Java");
  questions[2].value = 600;
  questions[2].answered = false;
  
  
  strcpy(questions[3].category, "Programming");
  strcpy(questions[3].question, "Who developed C language ?");
  strcpy(questions[3].answer, "Dennis");
  questions[3].value = 800;
  questions[3].answered = false;
  
  
  strcpy(questions[4].category, "Algorithms");
  strcpy(questions[4].question, "Worst case of quicksort in Big O ?");
  strcpy(questions[4].answer, "n2");
  questions[4].value = 200;
  questions[4].answered = false;

  strcpy(questions[5].category, "Algorithms");
  strcpy(questions[5].question, "What algorithm should be used to find a number in a sorted array?");
  strcpy(questions[5].answer, "BinarySearch");
  questions[5].value = 400;
  questions[5].answered = false;

  strcpy(questions[6].category, "Algorithms");
  strcpy(questions[6].question, "What is the meaning of algorithm?");
  strcpy(questions[6].answer, "Instructions");
  questions[6].value = 600;
  questions[6].answered = false;
  
  strcpy(questions[7].category, "Algorithms");
  strcpy(questions[7].question, "Can a binary tree have infinite nodes?");
  strcpy(questions[7].answer, "No");
  questions[7].value = 800;
  questions[7].answered = false;
  
  strcpy(questions[8].category, "Databases");
  strcpy(questions[8].question, "What key in a database table is used as an identifier?");
  strcpy(questions[8].answer, "Primary");
  questions[8].value = 200;
  questions[8].answered = false;
  
  strcpy(questions[9].category, "Databases");
  strcpy(questions[9].question, "Which command should be used to create a table ?");
  strcpy(questions[9].answer, "CREATE");
  questions[9].value = 400;
  questions[9].answered = false;
  
  strcpy(questions[10].category, "Databases");
  strcpy(questions[10].question, "Which command should be used to delete a table ?");
  strcpy(questions[10].answer, "DELETE");
  questions[10].value = 600;
  questions[10].answered = false;
  
  strcpy(questions[11].category, "Databases");
  strcpy(questions[11].question, "What is a database replication");
  strcpy(questions[11].answer, "Duplication");
  questions[11].value = 800;
  questions[11].answered = false;
}

//Checks if the player exists 
bool player_exists(int num_players, char *name)
{   
  int found = 0;
  
  for(int i=0;i<num_players;i++){
    
    if(strcmp(name,players[i].name) == 0){
        found = 1;
        break;
    }
  }
  
  if(found == 1){
    return true;
  }
  else{
    return false;
  }
}


//Returns the index of a player 
int player_num(char *name) {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        if (strcmp(name, players[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

//Display categories and questions
char* display_question(char* category, int amt) {
    
    initialize_game();
    char* question = NULL;
    
    if (strcmp(category, "Programming") == 0 || strcmp(category, "P") == 0 || strcmp(category, "programming") == 0) {
        printf("\x1b[32;1m CATEGORY: %s\x1b[0m\n", questions[0].category);
        
        for (int k = 0; k < 4; k++) {
            if (amt == questions[k].value) {
                question = questions[k].question;
                break;
            }
        }
    } else if (strcmp(category, "Algorithms") == 0 || strcmp(category, "A") == 0 || strcmp(category, "algorithms") == 0) {
        printf("\x1b[32;1m CATEGORY: %s\x1b[0m\n", questions[4].category);
        
        for (int k = 4; k < 8; k++) {
            if (amt == questions[k].value) {
                question = questions[k].question;
                break;
            }
        }
    } else {
        printf("\x1b[32;1m CATEGORY: %s\x1b[0m\n", questions[8].category);
        
        for (int k = 8; k < NUM_QUESTIONS; k++) {
            if (amt == questions[k].value) {
                question = questions[k].question;
                break;
            }
        }
    }
    
    return question;
}

void valid_answer(char *answer, char *opt, char *name, int amt) {
    
    //Checks  if the answer is correct or incorrect 
    initialize_game();
    int correct = 0;
    int index = player_num(name);
    
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(opt, questions[i].question) == 0 && strcmp(answer, questions[i].answer) == 0) {
            if (questions[i].answered) {
                printf("\x1b[31mThe question has already been answered!\x1b[0m\n"); 
                break;
            }
            printf("\x1b[32mAnswer is correct\x1b[0m\n"); 
            questions[i].answered = true;
            correct = 1;
            players[index].score += amt;
            printf("\x1b[33mScore of %s is : %d\x1b[0m\n", name, players[index].score); 
        }
    }
    
    if (!correct) {
        printf("\x1b[31mAnswer is incorrect\x1b[0m\n"); 
    }
}


//Displays final score, player name, and score
void display_points() {
    printf("\x1b[34;1mFinal Scores:\x1b[0m\n");
    printf("%-20s \x1b[33;1m%5s\x1b[0m\n", "Player Name", "Score");
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("%-20s \x1b[32;1m%5d\x1b[0m\n", players[i].name, players[i].score);
    }
}



    

//Main Function
int main() {
    //Declaring variabes
    char cat[MAX_LEN];
    char response[MAX_LEN];
    bool x = false;

    // Prompt for players names
    printf("\x1b[34;1mWELCOME TO JEOPARDY!\x1b[0m\n");
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Hello, please enter your name: ");
        scanf("%s", players[i].name);
        players[i].score = 0;
    }
    
    
    //Game Loop
    while (x == false) {
        printf("Please enter the name of the selected player:\n");
        char name[MAX_LEN];
        scanf("%s", name);

        if (player_exists(NUM_PLAYERS, name) == 1) {
            printf("Welcome,\x1b[35;1m%s\x1b[0m.\n", name);
            printf("Please select a category: (\x1b[33mP\x1b[0m)Programming\t(\x1b[33mA\x1b[0m) Algorithms\t(\x1b[33mD\x1b[0m) Databases\n");
            scanf("%s", cat);

            printf("Please enter the amount: \x1b[33;1m200\t400\t600\t800\x1b[0m\n");
            int amt;
            scanf("%d", &amt);

            char *opt = display_question(cat, amt);
            printf("%s\n", opt);

            printf("Enter your answer:\n");
            char ans[MAX_LEN];
            scanf("%s", ans);

            valid_answer(ans, opt, name, amt);

            printf("Do you want to quit? (\x1b[33mY\x1b[0m/\x1b[33mN\x1b[0m)\n");
            scanf("%s", response);

            if (strcmp(response, "Y") == 0) {
                x = true;
                break;
            }
        } else {
            printf("\x1b[35;1mPLAYER DOES NOT EXIST!\x1b[0m\n");
        }
    }
    
    display_points();



    return 0;
}


