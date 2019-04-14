#include<stdio.h>
 
int main()
{
	char message[500], letter;
	int i, rotation;
	
	printf("Enter a message to encode:\n");
	scanf("%[^\n]s", message);
	printf("Enter the rotational value as an integer:\n");
	scanf("%d", &rotation);
	
	for(i=0; message[i] != '\0'; ++i){
		letter = message[i];
		
		if(letter >='a'&& letter <='z'){
			letter=letter + rotation;
			
			if(letter>'z'){
				letter= letter -'z'+'a'- 1;
			}
			
			message[i] = letter;
		}
		else if(letter >= 'A' && letter <= 'Z'){
			letter = letter + rotation;
			
			if(letter > 'Z'){
				letter = letter - 'Z' + 'A' - 1;
			}
			
			message[i] = letter;
		}
	}
	
	printf("%s\n", message);
	
	return 0;
}