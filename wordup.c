//Author: Gia Mangili
//Date: 2/22/2025
//Purpose: Project 10

#include <stdio.h>
#include <stdbool.h>

#define WORD_LENGTH 5
#define MAX_GUESS 6

void loadWord(char word[]);
void lowerCase(char *str);
void upCase(char *str);
bool validGuess(char *guess);
int length(char *str);
bool letter(char c);
bool compareWords(char *guess, char *word);
void feedback(char *guess, char *word);
void printpreGuess(char guesses[][WORD_LENGTH + 1], int count, char *word, bool finalGuess);

int main(){
	
	char word[WORD_LENGTH +1];
	char guess[WORD_LENGTH + 2];
	char preGuess[MAX_GUESS][WORD_LENGTH + 1];
	int guessCount = 0;
	
	loadWord(word);
	
	while(guessCount < MAX_GUESS){
		printf("GUESS %d! Enter your guess: ", guessCount + 1);
		fgets(guess, sizeof(guess), stdin);
		
		int len = length(guess);
			if(guess[len - 1] == '\n'){
				guess[len - 1 ] = '\0';
			}
			
		lowerCase(guess);
			if (!validGuess(guess)){
				continue;
			}
		for(int i = 0; i < WORD_LENGTH + 1; i++){
			preGuess[guessCount][i] = guess[i];
		}
		
		bool isFinal = (guessCount == MAX_GUESS - 1);
		printpreGuess(preGuess, guessCount + 1, word, isFinal);
		
		if(compareWords(guess, word)){
			printf("You won in %d guess%s! \n", guessCount + 1, guessCount == 0 ? "" : "es");
			return 0;
		
		}
		
		guessCount++;
	}
	printf("You lost, better luck next time! \n");
	return 0;
}

void loadWord(char word[]){
	FILE *file = fopen("mystery.txt", "r");
	if(file == NULL){
		printf("Can't open file");
		word[0] = '\0';
		
			return;
	}
	fscanf(file, "%5s", word);
	fclose(file);
}

void lowerCase(char *str){
	for(int i = 0; i < WORD_LENGTH; i++){
		if(str[i] >= 'A' && str[i] <= 'Z'){
			str[i] +=('a' - 'A');
		}
	}
}

void upCase(char *str){
	for(int i = 0; i < WORD_LENGTH; i++){
		if(str[i] >= 'a' && str[i] <= 'z'){
			str[i] -= ('a' - 'A');
		}
	}
}

int length(char *str){
	int i = 0;
	while(str[i] != '\0') i++;
		return i;
}

bool letter(char c){
	return(c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool validGuess(char *guess){
	if(length(guess) != WORD_LENGTH){
		printf("Your guess must be 5 letters long.\nPlease try again: \n");
			return false;
		}
	for(int i = 0; i < WORD_LENGTH; i++){
		if(!letter(guess[i])){
			printf("Your guess must contain only letter.\nPlease try again: \n");
			return false;
		}
	}
	return true;
}

bool compareWords(char *guess, char *word){
	for(int i = 0; i < WORD_LENGTH; i++){
		if(guess[i] != word[i]) return false;
	}
		return true;
}

void printpreGuess(char guesses[][WORD_LENGTH + 1], int count, char *word, bool finalGuess){
	for(int g = 0; g < count; g++){
		if(finalGuess && g == count - 1){
			printf("FINAL GUESS: ");
		}
	for(int i = 0; i < WORD_LENGTH; i++){
   		 if(guesses[g][i] == word[i]){
      
       			 printf("%c", guesses[g][i] - ('a' - 'A'));
   	 } else {
  
       			 printf("%c", guesses[g][i]);
    		}
	}
		printf("\n");
	for(int i = 0; i < WORD_LENGTH; i++){
		bool matchWrongPlace = false;
			if(guesses[g][i] == word[i]){
				printf(" ");
					continue;
			}
	for(int k = 0; k < WORD_LENGTH; k++){
		if(guesses[g][i] == word[k]){
			bool alreadyUsed = false;
		for(int j = 0; j < WORD_LENGTH; j++){
			if(guesses[g][j] == word[j] && guesses[g][j] == guesses[g][i] && j != i){
				alreadyUsed = true;
			}
		}
			if(!alreadyUsed){
				matchWrongPlace = true;
			}
		}
	}
	
			printf("%c", matchWrongPlace ? '^' : ' ');
		}
			printf("\n");
		}
		printf("================================\n");
	}
