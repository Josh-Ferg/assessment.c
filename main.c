 #include<stdio.h>
 
int main()
{

	unsigned char message[1000]; //The text the user will input, this will either be encoded or decoded depending upon which section of the program is run.
	int i, rotarte, number, a; // i is used to count for loops, rotarte is the key/rotational value of the cesar cyphers, number is used by the menu to decide which section to run, a is used in for loops to count sections of the alphabet.
	char letter, quay[26],  alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //letter takes the current letter of the message, quay is the key the user inputs for substitution cyphers, alphabet is the standard english alphabet.
	
	
	printf("To encrypt a message using a ceasar cypher and a known key please press: 1\nTo decrypt a ceasar cypher with a known key please press: 2\nTo encrypt a message with a substitution cypher and a known key please press: 3\nTo decrypt a message that has been encripted with a substitution cypher and you know the key please press: 4\n");
	scanf("%d", &number);
	//Above is the menu to select what the user wishes to do.
	if(number == 1) { //If the user chooses to encrypt a message with a ceasar cypher this section runs.
	    
	printf("Enter a message to encrypt:\n");
	scanf(" %[^\n]s", message); //Takes the message the user inputs.
	printf("Enter the rotational value as an integer:\n");
	scanf(" %d", &rotarte); //Takes the key the user inputs
	
	for(i=0; message[i] != '\0'; ++i) { //Starts the for loop at the first carachter of the message, continues the loop for the duration of the message.
		letter = message[i]; //The current carachter of the message is assigned to 'letter'
		if(letter >= 'A' && letter <= 'Z') { //Continue if 'letter' is a capital letter
			letter = letter + rotarte; //encrypts the current letter with the value of the rotation
			if(letter > 'Z') { 
				letter = letter - 26; //If the encrypted letter rolls off the alphabet this resets it back at the start of the alphabet
			}
			if(letter < 'A') { 
				letter = letter + 26; //If the encrypted letter is less than 'A' it is pushed to the back of the alphabet
			}
			message[i] = letter; //The original letter of the message is substituted for the newly encrypted letter
		}
	} //process repeats again until the end of the string
	
	printf("The encrypted message is:\n%s\n", message); //The entire newly encrypted message is printed to the screen
	
	}
	else if(number == 2) { //If the user selects to decrypt a rotation cypher with a known key, this section runs
	    
	printf("Enter a message to decrypt:\n");
	scanf(" %[^\n]s", message); //Gets the encrypted message
	printf("Enter the rotational value as an integer:\n");
	scanf(" %d", &rotarte); //Gets the key
	
	for(i=0; message[i] != '\0'; ++i){ //Starts the for loop at the first carachter of the message, continues the loop for the duration of the message.
		letter = message[i]; //The current carachter of the message is assigned to 'letter'
		if(letter >= 'A' && letter <= 'Z'){ //Continue if 'letter' is a capital letter
			letter = letter - rotarte; //decrypts the current letter with the value of the rotation
			if(letter < 'A') {
				letter = letter + 26; //If the decrypted letter is less than 'A' it is pushed to the back of the alphabet
			}
			if(letter > 'Z') {
			    letter = letter - 26; //If the decrypted letter rolls off the alphabet this resets it back at the start of the alphabet
			}
			
			message[i] = letter; //The original letter of the message is substituted for the newly decrypted letter
		}
	} //process repeats again until the end of the string
	
	printf("The decrypted message is:\n%s\n", message); //The entire newly decrypted message is printed to the screen
	
	}
	else if(number == 3) { //If the user chooses to encrypt a message with a substitution cypher this section runs.
	    
	printf("Enter a message to encrypt:\n");
	scanf(" %[^\n]s", message); //Takes the message the user inputs.
	printf("Enter the substitution alphabet in capital letters, e.g:\nABCDEFGHIJKLMNOPQRSTUVWXYZ\nAZERTYUIOPQSDFGHJKLMWXCVBN <-- like this bottom row:\n");
	scanf(" %s", quay); //Gives am example of how the key should be entered and reads the entered key
	
	for(i=0; message[i] != '\0'; ++i) { //Starts the for loop at the first carachter of the message, continues the loop for the duration of the message.
		
		if(message[i] <= 'A' || message[i] >= 'Z') { 
		    message[i] = message[i]; //Only continue if the current carachter of the message is a capital letter
		}
		else {
		letter = message[i]; //The current carachter of the message is assigned to 'letter'
		message[i] = 0; //Sets the current carachter value of message to 0
		if(letter >= 'A' && letter <= 'Z') {
		    for(a=0; alphabet[a] != '\0'; a++) { //counts through the real alphabet 
			    if(alphabet[a] == letter){ //Stops when the value of the real alphabet is equal to 'letter', records the number of places it moved up the alphabet
			      message[i] = quay[a]; //Assigns the actual charachter in the message with the number of places in moved up the alphabet combined with the key 
			    }
		    }   
		}
        }
    }
	
	printf("The encrypted message is:\n%s\n", message); //Prints the encrypted message
	    
	}
	else if(number == 4) { //If the user chooses to decrypt a message with a substitution cypher this section runs.
	    
	printf("Enter a message to decrypt:\n");
	scanf(" %[^\n]s", message); //Takes the message the user inputs.
	printf("Enter the substitution alphabet in capital letters, e.g:\nABCDEFGHIJKLMNOPQRSTUVWXYZ\nAZERTYUIOPQSDFGHJKLMWXCVBN <-- like this bottom row:\n");
	scanf(" %s", quay); //Gives am example of how the key should be entered and reads the entered key
	
	for(i=0; message[i] != '\0'; ++i){ //Starts the for loop at the first carachter of the message, continues the loop for the duration of the message.
		
		if(message[i] <= 'A' || message[i] >= 'Z'){
		    message[i] = message[i]; //Only continue if the current carachter of the message is a capital letter
		}
		else {
		letter = message[i]; //The current carachter of the message is assigned to 'letter'
		message[i] = 0; //Sets the current carachter value of message to 0
		if(letter >= 'A' && letter <= 'Z'){
		    for(a=0; quay[a] != '\0'; a++){ //counts through the real key provided by the user 
			    if(quay[a] == letter){ //Stops when the value of the key is equal to 'letter', records the number of places it moved up the key
			      message[i] = alphabet[a];  //Assigns the actual charachter in the message with the number of places in moved up the key combined with the alphabet
			    }
		    }    
		}	
        }
    }
	
	printf("The decrypted message is:\n%s\n", message); //Prints the decrypted message
	
	}
	else {
	    printf("Please enter one of the valid numbers from the menu.\n"); //In the menu if the user selects an option that isn't available this message prints
	}

	
	return 0;
}
