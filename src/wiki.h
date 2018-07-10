#include <bits/stdc++.h>


/* ---------------------------------------------------------------------------
 * DECLARATIONS
 * ---------------------------------------------------------------------------
*/
void find_information ( std::string query );
size_t writeCallback ( char* buf, size_t size, size_t nmemb, void* up );


/*
 * ---------------------------------------------------------------------------
 * DEFINITION - writeCallback
 * Tells curl how many bytes to handle.
*/

size_t writeCallbackWik ( char* buf, size_t size, size_t nmemb, void* up )
{
    for ( int c = 0 ; c < size*nmemb ; c++)
    {
        data.push_back ( buf [ c ]);
    }
    return size*nmemb;
}

 
/*
 * ---------------------------------------------------------------------------
 * DEFINITION - to_lower ( string )
 * Converts entire string to lower case.
*/
std::string to_fUpLower ( std::string temp )
{
	char prevChar = '~';
	for ( int iter = 1; iter < temp.length () ; iter++ )	{
	
		if ( prevChar == '_' )	{
			prevChar = temp [ iter ];
			continue;	
		}

		if ( temp [ iter ] >= 'A' && temp [ iter ] <= 'Z' )	
			temp [ iter ] += 'a' - 'A';
		prevChar = temp [ iter ];
	}
	return temp;
}


/*
 * ---------------------------------------------------------------------------
 * DEFINITION - find_information
 * Searches the word on https://wikipedia.org/wiki/<word>. 
*/
void find_information ( std::string word )
{

	data = "";
	char URLp [ 200 ] = "https://en.wikipedia.org/wiki/";
	char word2 [ 50 ];
	word = to_fUpLower ( word );
	strcpy ( word2, word.c_str ( ));
	strcat ( URLp, word2 );


	CURL* curl;

	curl_global_init ( CURL_GLOBAL_ALL );
	curl = curl_easy_init ();

	curl_easy_setopt ( curl, CURLOPT_URL, URLp );
	curl_easy_setopt ( curl, CURLOPT_WRITEFUNCTION, &writeCallbackWik );
	//curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L); //tell curl to output its progress

	curl_easy_perform ( curl );


	curl_easy_cleanup ( curl );
	curl_global_cleanup ();


	std::string search_text = "<p>";

	std::ofstream os ( "wiki.txt" ); 
	std::ifstream is;
	os << data;
	os.close();

	is.open ( "wiki.txt" );
	std::string paragraph;
	do {
		getline (is, paragraph);
	}
	while ( is.eof () || paragraph.find ( search_text ) == std::string::npos );

	paragraph.erase ( paragraph.begin(), paragraph.begin ()+6);
	for ( int iter = 0; iter < paragraph.length () || iter < 400 ; iter ++ )
	{
		if ( paragraph [ iter ] == '<' )	{
			do
			{
				iter ++;
			} while ( paragraph [ iter ] != '>' );
		}
		else
			std::cout << paragraph [ iter ];
	}
	std::cout << "...\nRead more on " << URLp << std::endl;

}
