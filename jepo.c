#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_LEN 256
#define NUM_CATEGORIES 3
#define NUM_QUESTIONS 12
#define NUM_PLAYERS 4

#define RESET   "\033[0m"       /*End color for print*/
#define RED     "\033[31m"      /* Red for print */
#define GREEN   "\033[32m"      /* Green for print*/


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
    
    if(strcasecmp(name,players[i].name) == 0){
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
        if (strcasecmp(name, players[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

//checks the correct points and returns the question index
int return_question(int sub, int amt) {

    int k = -1; //stores index of the question
    
    if (amt == 200)
        k = sub;
    else if (amt == 400)
        k = sub + 1;
    else if (amt == 600)
        k = sub + 2;
    else if (amt == 800)
        k = sub +3;
    else
        printf("Invalid Input. Try again");
    
    return k;
}

void valid_answer(char *answer, int k, char *name, int amt) {
    
    //Checks  if the answer is correct or incorrect 
    
    int index = player_num(name);
    
    if (strcasecmp(answer, questions[k].answer) == 0) {
        printf("\x1b[32mAnswer is correct\x1b[0m\n"); 
        questions[k].answered = true;
        players[index].score += amt;
        printf("\x1b[33mScore of %s is : %d\x1b[0m\n", name, players[index].score);
    }
    
    else {
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
//shows the available questions in green and answered in red
int display_quesAvail(char* category){
    
    int sub=-1; //stores the cat index (subject)
    int points = 200;
    
    if (strcasecmp(category, "Programming") == 0 || strcasecmp(category, "P") == 0 ) {
        sub = 0;
        printf("\nYou chose Programming.\n");
        for(int i = 0; i < 4; i++){
            if(questions[i].answered)
                printf(RED "%d\t" RESET, points);
            else printf(GREEN "%d\t" RESET, points);
            points += 200;
        }
        
    } else if (strcasecmp(category, "Algorithms\n") == 0 || strcasecmp(category, "A") == 0 ) {
        sub = 4;
        printf("\nYou chose Algorithms.\n");
        for(int i = 4; i < 8; i++){
            if(questions[i].answered)
                printf(RED "%d\t" RESET, points);
            else printf(GREEN "%d\t" RESET, points);
            points += 200;
        }
        
    } else if (strcasecmp(category, "Databases") == 0 || strcasecmp(category, "D") == 0) {
        sub = 8;
        printf("\nYou chose Databases.\n");
        for(int i = 8; i < 12; i++){
            if(questions[i].answered)
                printf(RED "%d\t" RESET, points);
            else printf(GREEN "%d\t" RESET, points);
            points += 200;
        }
    
    } else
        printf("Invalid Input..Try again");
    
    return sub;
}

//Main Function
int main() {
    //Declaring variabes
    char cat[MAX_LEN];
    char response[MAX_LEN];
    bool x = false;
    
    initialize_game();

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
            Start0:
            printf("Please select a category: (\x1b[33mP\x1b[0m)Programming\t(\x1b[33mA\x1b[0m) Algorithms\t(\x1b[33mD\x1b[0m) Databases\n");
            scanf("%s", cat);
            
            Start1:
            
            int sub;
            sub = display_quesAvail(cat);
            
            if(sub == -1)
                goto Start0; //bad practice.....ik ik
                
            printf("\nEnter amount: ");
            int amt;
            scanf("%d", &amt);
            
            int k = return_question(sub, amt);
            
            if(k == -1)
                goto Start1; //yes ik
            
            if(questions[k].answered) {
                printf("This question has already been answered.....\nPick another one.");
                goto Start1; //idc
            }
            
            printf("\n%s", questions[k].question);

            printf("\nEnter your answer:\n");
            char ans[MAX_LEN];
            scanf("%s", ans);

            valid_answer(ans, k, name, amt);

            printf("Are you a quitter? (\x1b[33mY\x1b[0m/\x1b[33mN\x1b[0m)\n");
            scanf("%s", response);

            if (strcasecmp(response, "Y") == 0) {
                x = true;
                display_points();
                break;
            }
        } else {
            printf("\x1b[35;1mPLAYER DOES NOT EXIST!\x1b[0m\n");
            break;
        }
    }

    return 0;
}