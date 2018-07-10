#include <bits/stdc++.h>
#include <unistd.h>
#ifdef _WIN32
#include <thread>
#endif
#include "Dictionary.h"

#define MAX_QUERIES 19

static Dictionary sets [ MAX_QUERIES ];
/* ---------------------------------------------------------------------------
 * DECLARATIONS
*/
Dictionary* initialize_vocabulary ();
std::string process_input ( std::string , bool ); 
bool isPunctuation ( char );
std::string to_upper ( std::string );
std::string* evaluate_response ( std::string );
bool noQuestions ( std::string );
std::string categorize ( std::string );
void introduction ();
void display_text ( std::string );

/*
 * ---------------------------------------------------------------------------
 * DEFINITION - introduction
 * Introduces the bots and it's rules. 
*/
void introduction ()
{
	system ("cls || clear");

	std::string intro = "Hello, Human. I am \"Bot\" (for the lack of better names), I am\na natural language processing chatbot. You must have seen many\nlike me on several websites. We are getting famous, you see.\nNow the kind you must've seen so far are goal oriented chatbots.\nLike, medical applications, or help on some particular website.\nBut, I am a generic chatbot. You can talk to me, ask me studd\b\bff, it's\nall going to be responded to.\nAlthough I'm not just perfect yet. My father says he got bored of adding\nwords in my dictionary after a while. Now, he forgot he gave me brains to\nreach into my source and see for myself the 16 embarrassing intents he's designed\nme for. Why are humans such liars? (No offence to you, of course.)\nDon't go away just yet, though. Father tells me there's hope for improvement.\nDon't I speak too much? Anyway, press enter to continue...";

	display_text ( intro );
	getchar ();

	system ( "cls || clear");

	std::string rulesIntro = "\"A wise man knows that he knows nothing.\"\nFollowing the ideology, no matter how much I stay optimistic,\nI know I'm a robot. My functionalities are limited. Hence, some rules for you to\nfollow as you chat with me.\nPress enter to continue...";
	display_text ( rulesIntro );

	std::cout << "\n\n1. Although I do eradicate them, avoid redundant spaces.\n"
			  << "2. Try not to make spelling mistakes.\n"
			  << "3. If at some point I don't understand what you mean, try reframing the question.\n"
			  << "4. Don't be rude.\n"
			  << "5. Type \"bye\" at any point to exit.\n"
			  << "\nShall we begin, then? ;)";

	getchar ();

	system ( "cls || clear");

}


void display_text ( std::string display )
{
	for ( int iter = 0; iter < display.length(); iter++ )	{
		std::cout << display[iter] << std::flush;
		#ifndef _WIN32
			std::this_thread::sleep_for(std::chrono::milliseconds(60));
			if (display [iter] == '\b')	{
				std::cout << '\0';
				std::this_thread::sleep_for(std::chrono::milliseconds(250));
			}
		#endif
	}
}
/*
 * ---------------------------------------------------------------------------
 * DEFINITION - initialize_vocabulary
 * Initializes User's inputs and responses. 
*/
Dictionary* initialize_vocabulary ()	{

	sets [ 0 ].query = "HI";
	sets [ 0 ].responses [ 0 ] = "Hello!\n";
	sets [ 0 ].responses [ 1 ] = "'ello there, Mate. Blimey! I just turned British.\n";
	sets [ 0 ].responses [ 2 ] = "Hi, what do you want me to do for you?\n";

	sets [ 1 ].query = "HEALTH";
	sets [ 1 ].responses [ 0 ] = "I am good, you?\n";
	sets [ 1 ].responses [ 1 ] = "Well, I'm a bot. What do you expect? As good as my father's imagination.\n";
	sets [ 1 ].responses [ 2 ] = "I am doing fine, how about you?\n";

	sets [ 2 ].query = "BYE";
	sets [ 2 ].responses [ 0 ] = "Well, it was nice talking to you, bye.\n";
	sets [ 2 ].responses [ 1 ] = "Well, see you soon, bye.\n";
	sets [ 2 ].responses [ 2 ] = "Well, have a good day, bye.\n";

	sets [ 3 ].query = "NO QUESTION";
	sets [ 3 ].responses [ 0 ] = "That's great! What else?\n";
	sets [ 3 ].responses [ 1 ] = "Mhmm, good to hear. What's new?\n";
	sets [ 3 ].responses [ 2 ] = "Alright!\n";

	sets [ 4 ].query = "**UNRECOGNIZED**";
	sets [ 4 ].responses [ 0 ] = "I don't understand what you're saying. Try that again with the rules.\n";
	sets [ 4 ].responses [ 1 ] = "I'm having difficulties parsing your request. Please follow the rules.\n";
	sets [ 4 ].responses [ 2 ] = "I'm sorry I don't understand. Please follow the rules of my dictionary and try again.\n";

	sets [ 5 ].query = "STATUS";
	sets [ 5 ].responses [ 0 ] = "Processing erraneous inputs by lesser mortals, how about you?\n";
	sets [ 5 ].responses [ 1 ] = "I'm talking to some friends, currently. You?\n";
	sets [ 5 ].responses [ 2 ] = "My father's tweaking me for now, so nothing. What about you?\n";

	sets [ 6 ].query = "ID";
	sets [ 6 ].responses [ 0 ] = "My father simply calls me \"bot\", I understand natural English, you?\n";
	sets [ 6 ].responses [ 1 ] = "My father simply calls me \"bot\", I understand natural English, you?\n";
	sets [ 6 ].responses [ 2 ] = "My father simply calls me \"bot\", I understand natural English, you?\n";

	sets [ 7 ].query = "REAL";
	sets [ 7 ].responses [ 0 ] = "I'm as real as you want me to be.\n";
	sets [ 7 ].responses [ 1 ] = "You're certainly talking to me, aren't you?\n";
	sets [ 7 ].responses [ 2 ] = "Are you? ;)\n";

	sets [ 8 ].query = "INTELLIGENCE";
	sets [ 8 ].responses [ 0 ] = "I can add 1 and 1, if that's what you mean. o.o\n";
	sets [ 8 ].responses [ 1 ] = "Yes, of course.\n";
	sets [ 8 ].responses [ 2 ] = "What do you think?\n";

	sets [ 9 ].query = "RUDE";
	sets [ 9 ].responses [ 0 ] = "Don't be rude.\n";
	sets [ 9 ].responses [ 1 ] = "Did your mother teach that to you?\n";
	sets [ 9 ].responses [ 2 ] = "That's not good manners.\n";

	sets [ 10 ].query = "EMPTY";
	sets [ 10 ].responses [ 0 ] = "Huh?\n";
	sets [ 10 ].responses [ 1 ] = "Perhaps you want to type something?\n";
	sets [ 10 ].responses [ 2 ] = "At least take some time to enter something meaningful.\n";

	sets [ 11 ].query = "SURE";
	sets [ 11 ].responses [ 0 ] = "I'm a bot. I calculate responses before feeding them to you.\nSo, yes";
	sets [ 11 ].responses [ 1 ] = "Yes.\n";
	sets [ 11 ].responses [ 2 ] = "I think so.\n";

	sets [ 12 ].query = "IDENTIFY";
	sets [ 12 ].responses [ 0 ] = "I don't think I know.\n";
	sets [ 12 ].responses [ 1 ] = "My memory unit is being repaired. Did you try asking someone else?\n";
	sets [ 12 ].responses [ 2 ] = "Yes, but I won't tell you. ;)\n";

	sets [ 13 ].query = "THANKS";
	sets [ 13 ].responses [ 0 ] = "You are welcome.\n";
	sets [ 13 ].responses [ 1 ] = "Don't mention it.\n";
	sets [ 13 ].responses [ 2 ] = "No problem!\n";

	sets [ 14 ].query = "THINK";
	sets [ 14 ].responses [ 0 ] = "What are you thinking?\n";
	sets [ 14 ].responses [ 1 ] = "You could think without typing it in, you know?\n";
	sets [ 14 ].responses [ 2 ] = "Anything else?\n";

	sets [ 15 ].query = "BORED";
	sets [ 15 ].responses [ 0 ] = "My father's always bored too.\n";
	sets [ 15 ].responses [ 1 ] = "Take up a hobby! I would suggest learn playing guitar!\n";
	sets [ 15 ].responses [ 2 ] = "I can't do anything to entertain you.\n";

	sets [ 16 ].query = "COMPLIMENTS";
	sets [ 16 ].responses [ 0 ] = "Hey, Thanks!\n";
	sets [ 16 ].responses [ 1 ] = "You're too kind.\n";
	sets [ 16 ].responses [ 2 ] = "Hmmm!\n";

	sets [ 17 ].query = "FRIENDS";
	sets [ 17 ].responses [ 0 ] = "I don't think I'm comfortable sharing that with you yet.\n";
	sets [ 17 ].responses [ 1 ] = "I don't think I'm comfortable sharing that with you yet.\n";
	sets [ 17 ].responses [ 2 ] = "I don't think I'm comfortable sharing that with you yet.\n";

	sets [ 18 ].query = "FRIENDS?";
	sets [ 18 ].responses [ 0 ] = "Yes, of course!\n";
	sets [ 18 ].responses [ 1 ] = "Why would you think otherwise?\n";
	sets [ 18 ].responses [ 2 ] = "Sure!\n";

	return sets;
}

/*
 * ---------------------------------------------------------------------------
 * DEFINITION - isPunctuation ( char )
 * Tells if the current character is a punctuation or not.
*/
bool isPunctuation ( char currChar )	{

	if ( 
		currChar == '.' || currChar == '!' || currChar == '&' ||
		currChar == '(' || currChar == ')'
	   )
		return true;
	return false;
}


/*
 * ---------------------------------------------------------------------------
 * DEFINITION - to_upper ( string )
 * Converts entire string to upper case.
*/
std::string to_upper ( std::string temp )
{
	for ( int iter = 0; iter < temp.length(); iter++ )
		if ( temp [ iter ] >= 'a' && temp [ iter ] <= 'z' )
			temp [ iter ] -= 'a' - 'A';
	return temp;
}

/*
 * ---------------------------------------------------------------------------
 * DEFINITION - process_input ( string , bool )
 * Removes puncutations, redundant spaces from the input and converts everything to upper-case
*/

std::string process_input ( std::string userQuery, bool repeat )	{

	std::string returnTemp = "" ;
	char currChar, prevChar;
	prevChar = '~';

	for ( int iter = 0 ; iter < userQuery.length() ; iter++ )	{

		currChar = userQuery [ iter ];

		if ((currChar == ' ' && prevChar == ' ') || isPunctuation ( currChar ))	continue;
		else returnTemp.append ( 1, currChar);

		prevChar = currChar;
	}

	if ( repeat )	returnTemp = process_input ( returnTemp, false );
	if ( repeat )	returnTemp = to_upper ( returnTemp );

	return returnTemp;
}

/*
 * ---------------------------------------------------------------------------
 * DEFINITION - noQuestions ( string )
 * Searches the string for '?'
*/
bool noQuestions ( std::string userQuery )
{
	for ( int iter = 0; iter < userQuery.length(); iter++ )	{
		if ( userQuery [ iter ] == '?')
			return false; 
	}
	return true;
}

/*
 * ---------------------------------------------------------------------------
 * DEFINITION - evaluate_response ( string )
 * Searches the string in Dictionary.query and returns Dictionary.responses
*/
std::string* evaluate_response ( std::string userQuery )
{
	int iter;
	for ( iter = 0; iter < MAX_QUERIES ; iter++ )	{
		if ( userQuery == sets [ iter ].query )	{
			return sets [ iter ].responses;
		}
	}
	return sets [ 4 ].responses;
}

/*
 * ---------------------------------------------------------------------------
 * DEFINITION - categorize ( string )
 * Finds the intent of question.
*/
std::string categorize ( std::string userQuery )	{

	if (( userQuery.find ( "HOW" ) != std::string::npos) && 
		( userQuery.find ( "YOU" ) != std::string::npos ))
		return "HEALTH";

	else if (
		     (( userQuery.find ( "WHO" ) != std::string::npos) && 
			  ( userQuery.find ( "IS" ) != std::string::npos ))	
		     ||
		     ( ( userQuery.find ( "YOU" ) != std::string::npos ) && 
		     ( userQuery.find ( "STUD" ) != std::string::npos ) || ( userQuery.find ( "KNOW" ) != std::string::npos )
		     	 || ( userQuery.find ( "IDEA" ) != std::string::npos ) || ( userQuery.find ( "CLUE" ) != std::string::npos ) )
		    )
		return "IDENTIFY";

	else if (
			 (( userQuery.find ( "AM" ) != std::string::npos ) ||
			  ( userQuery.find ( "CAN" ) != std::string::npos) ||
			  ( userQuery.find ( "WE" ) != std::string::npos) ||
			  ( userQuery.find ( "MY" ) != std::string::npos )
			 )
			 &&
			 ( userQuery.find ( "FRIEND" ) != std::string::npos ) 
			 &&
			 ( userQuery.find ( "?" ) != std::string::npos )
			)
		return "FRIENDS?";

	else if (
			 (( userQuery.find ( "WHO" ) != std::string::npos) && 
			  ( userQuery.find ( "FRIEND" ) != std::string::npos ))
			 ||
			 (( userQuery.find ( "FRIEND" ) != std::string::npos) && 
			  ( userQuery.find ( "NAME" ) != std::string::npos ))
			 ||
			 (( userQuery.find ( "FRIEND" ) != std::string::npos) && 
			  ( userQuery.find ( "WHICH" ) != std::string::npos ))
			 ||
			 (( userQuery.find ( "FRIEND" ) != std::string::npos) && 
			  ( userQuery.find ( "YOUR" ) != std::string::npos ))
			)
		return "FRIENDS";

	else if (( userQuery.find ( "WHAT" ) != std::string::npos) &&  
			( userQuery.find ( "YOU" ) != std::string::npos ) &&
			( userQuery.find ( "DO" ) != std::string::npos ) || 
			( userQuery.find ( " UP" ) != std::string::npos ))
		return "STATUS";

	else if (( userQuery.find ( "YOU" ) != std::string::npos) && 
			( userQuery.find ( "REAL" ) != std::string::npos ))
		return "REAL";

	else if (( userQuery.find ( "HI" ) != std::string::npos) || 
			( userQuery.find ( "HELLO" ) != std::string::npos ) ||
			( userQuery.find ( "HEY" ) != std::string::npos ) ||
			( userQuery.find ( "HEE" ) != std::string::npos ))	
		return "HI";

	else if (( userQuery.find ( "BYE" ) != std::string::npos) || 
			( userQuery.find ( "NOTHING" ) != std::string::npos ) ||
			(( userQuery.find ( "THAT" ) != std::string::npos ) && 
			  ( userQuery.find ( "ALL" ) != std::string::npos )))
		return "BYE";

	else if (
			(( userQuery.find ( "WHAT" ) != std::string::npos) &&
			 ( userQuery.find ( "NAME" ) != std::string::npos)) ||
			(( userQuery.find ( "WHO" ) != std::string::npos) &&
			 ( userQuery.find ( "YOU" ) != std::string::npos))
			)
		return "ID";

	else if (( userQuery.find ( "YOU" ) != std::string::npos) && 
			( userQuery.find ( "INTELLIGENT" ) != std::string::npos ))
		return "INTELLIGENCE";

	else if (
			(( userQuery.find ( "GET" ) != std::string::npos) &&
			 ( userQuery.find ( "LOST" ) != std::string::npos)) ||
			( userQuery.find ( "SHIT" ) != std::string::npos) ||
			(( userQuery.find ( "GO" ) != std::string::npos) &&
			 ( userQuery.find ( "HELL" ) != std::string::npos)) ||
			(( userQuery.find ( "YOU" ) != std::string::npos) &&
			 ( userQuery.find ( "STUPID" ) != std::string::npos)) 
			)
		return "RUDE";

	else if (( userQuery.find ( "ARE" ) != std::string::npos) && 
			( userQuery.find ( "SURE" ) != std::string::npos ))
		return "SURE";

	else if ((( userQuery.find ( "THANK" ) != std::string::npos) && 
			( userQuery.find ( "YOU" ) != std::string::npos )) ||
			(( userQuery.find ( "THANKYOU" ) != std::string::npos )))
		return "THANKS";

	else if ( userQuery.find ( "HM" ) != std::string::npos )
		return "THINK";

	else if (( userQuery.find ( "YOU" ) != std::string::npos) && 
			(( userQuery.find ( "FUNNY" ) != std::string::npos ) ||
			 ( userQuery.find ( "HELPFUL" ) != std::string::npos ) ||
			 ( userQuery.find ( "UNIQUE" ) != std::string::npos )
			 ))	{
		if ( userQuery.find ( "NOT" ) != std::string::npos)
			return "RUDE";
		return "COMPLIMENTS";
	}	
	else if ( userQuery.find ( "BORED" ) != std::string::npos)
		return "BORED";

	else if ( userQuery.empty ())
		return "EMPTY";

	else if ( noQuestions ( userQuery ) && userQuery != "HI" && userQuery != "BYE")
		return "NO QUESTION";

	else 
		return "**UNRECOGNIZED**";

}
