#include <stdio.h>

int main(){
	char ch;
	bool twoQuote = 0;	// twoQuote = 0 means next to be scaned is
				// the open double quote
	while(scanf("%c", &ch) != EOF){
		if(ch == '\"'){
			if(!twoQuote){
				printf("``");
				twoQuote = 1;
			} else {
				printf("''");
				twoQuote = 0;
			}
		} else {
			printf("%c", ch);
		}
	}
	return 0;
}
		
