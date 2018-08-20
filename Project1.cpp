/*
 * // SpellCheck <Project1.cpp>
// EE w312 Project 1 submission by
// Anika Agarwal
/

#include <stdio.h> // provides declarations for printf and putchar
#include <stdint.h> // provides declarations for int32_t uint32_t and the other (new) standard C types

/* All of your code must be in this file. Please no #includes other than standard system headers (ie.., stdio.h, stdint.h)
 *
 * Many students find it helpful to declare global variables (often arrays). You are welcome to use
 * globals if you find them helpful. Global variables are by no means necessary for this project.
 */

/* You must write this function (spellCheck). Do not change the way the function is declared (i.e., it has
 * exactly two parameters, each parameter is a standard (mundane) C string (see SpellCheck.pdf).
 * You are expected to use reasonable programming style. I *insist* that you indent
 * reasonably and consistently in your code. I strongly encourage you to avoid big functions
 * So, plan on implementing spellCheck by writing two or three other "support functions" that
 * help make the actual spell checking easier for you.
 * There are no explicit restrictions on using functions from the C standard library. However,
 * for this project you should avoid using functionality from the C++ standard libary. You will
 * almost certainly find it easiest to just write everything you need from scratch!
 */
int checkLetter(char letter);
void MakeLow(char *article);
int matchWord(int first, int last, char article[], char dictionary[] );

/*
 * checkLetter;
 * Input: character to be checked
 * Output: Returns 1 if letter, 0 if not letter
 */
int checkLetter(char letter){
    if (letter >= 'a' && letter <= 'z') { //is character in bounds?
        return 1 ;
    }
    else{
        return 0;
    }
}

/*
 * MakeLow;
 * If character is uppercase, converts it to lowercase
 */
void MakeLow(char *article) {
    while (*article) {
        if (*article >= 'A' && *article <= 'Z') {
            *article = *article + ('a' - 'A');  //make lowercase (diff = 0x20)
        }
        article++ ;
    }
}


/*
 * matchWord;
 * Input: start of word (first), end of word (last), article, dictionary
 * Return: 0 (no word exists), 1 (word exists)
 */
int matchWord(int first, int last, char article[], char dictionary[]) {
    int index = 0 ;            // dictionary index
    int firststart = first ;  //article index
    int wLength = (last - first);
    while (dictionary[index] != 0) {
        while (dictionary[index] != '\n' || first != last) { //while not at \n or the end of the word
                if (article[first] == dictionary[index]) {
                    index++;
                    first++;
                    wLength--;                              //make sure all letters have been matched
                }
                else {
                    while (dictionary[index] != '\n') {
                        index++;
                        if(dictionary[index] == 0){  //if run through whole dictionary and no sol'n then 0
                            return 0;
                        }
                    }
                    index++;                        //keep moving through dictionary
                    first = firststart;             //reset place in article
                    wLength = last - first;         //reset article word length
                }
        }
        if (first == last && dictionary[index] != 0) {  //if at end of word
            index++;
            if (wLength == 0) {
                return 1; // word exists ONLY if full length ==0 (fix for europeANS)
            }
        }
        index++ ;       //keep moving though dictionary
    }
    return 0 ;      //no match --> print
}


void spellCheck(char article[], char dictionary[]){
    int start=0;  //start of word in article
    int end =0;   // end of word in article
    int length =0;  //length of word in article

    MakeLow(dictionary); //puts dictionary and article in lowercase
    MakeLow(article);

    while(article[start] != 0){                         //while article not at end
        while(checkLetter(article[start]) == 0) {
            start++ ;                                   //count until first letter of word
            if(article[start] == 0) {
                break ;
            }
        }
        if(article[start] == 0) {
            break ;
        }
        end = start ;
        while(checkLetter(article[end]) == 1) {        //find end of word
            end++ ;
        }
        length = end-start;
        if(length >= 2) {                               //only consider word if at least 2 characters long
            if (!matchWord(start, end, article, dictionary)) {
                for (int i = start; i < start + length; i++) {  //print character
                    printf("%c", article[i]);
                }
                printf("\n");
            }
        }
        start = start + length;             //new start point of word
    }
}
