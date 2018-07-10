#include <bits/stdc++.h>
#include <curl/curl.h>

std::string data;

/* ---------------------------------------------------------------------------
 * DECLARATIONS
 * ---------------------------------------------------------------------------
*/
void find_meaning ( std::string word );
std::string to_lower ( std::string temp );
size_t writeCallback ( char* buf, size_t size, size_t nmemb, void* up );

/*
 * ---------------------------------------------------------------------------
 * DEFINITION - writeCallback
 * Tells curl how many bytes to handle.
*/

size_t writeCallback ( char* buf, size_t size, size_t nmemb, void* up )
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
std::string to_lower ( std::string temp )
{
	for ( int iter = 0; iter < temp.length () ; iter++ )
		if ( temp [ iter ] >= 'A' && temp [ iter ] <= 'Z' )
			temp [ iter ] += 'a' - 'A';
	return temp;
}


/*
 * ---------------------------------------------------------------------------
 * DEFINITION - find_meaning
 * Searches the word on https://dictionary.cambridge.org/dictionary/english/<word>. 
*/
void find_meaning ( std::string word )
{

	data = "";
	char URLp [ 200 ] = "https://dictionary.cambridge.org/dictionary/english/";
	char word2 [ 20 ];
	word = to_lower ( word );
	strcpy ( word2, word.c_str ( ));
	strcat ( URLp, word2 );

	CURL* curl;

	curl_global_init ( CURL_GLOBAL_ALL );
	curl = curl_easy_init ();

	curl_easy_setopt ( curl, CURLOPT_URL, URLp );
	curl_easy_setopt ( curl, CURLOPT_WRITEFUNCTION, &writeCallback );
	//curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L); //tell curl to output its progress

	curl_easy_perform ( curl );


	curl_easy_cleanup ( curl );
	curl_global_cleanup ();


	std::string search_text = "<meta itemprop=\"headline\" content=";

	std::ofstream os ( "check.txt" ); 
	std::ifstream is;
	os << data;
	os.close();
	is.open ( "check.txt" );
	std::string check1;
	do {
		getline (is, check1);
	}
	while ( is.eof () || check1.find ( search_text ) == std::string::npos );
	
	check1.erase ( check1.begin(), check1.begin() + 43 );
	check1.erase ( check1.end () - 13, check1.end ( ));
	for ( int iter = 0 ; iter < check1.length () ; iter++ )	{
		if ( check1 [ iter ] == '&' || ( check1 [ iter ] == '.' && check1 [ iter + 1 ] == ' ' && check1 [ iter + 2 ] == 'L'))
		{
			std::cout << "\n";
			break;
		}
		check1 [ iter ] == ':' ? std::cout << std::endl : std::cout << check1 [ iter ];
	}
}
