#include<stdio.h>
 
int main()
{
	unsigned char message[500], letter;
	int i, rotarte;
	
	printf("Enter a message to encode:\n");
	scanf("%[^\n]s", message);
	printf("Enter the rotational value as an integer:\n");
	scanf("%d", &rotarte);
	
	for(i=0; message[i] != '\0'; ++i){
		letter = message[i];
		if(letter >='a'&& letter <='z'){
			letter=letter + rotarte;
			if(letter>'z'){
				letter= letter -26;
			}
			
			message[i] = letter;
		}
		else if(letter >= 'A' && letter <= 'Z'){
			letter = letter + rotarte;
			if(letter > 'Z'){
				letter = letter - 26;
			}
			
			message[i] = letter;
		}
	}
	
	printf("%s\n", message);
	
	return 0;
}