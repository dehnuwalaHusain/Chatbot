#include "backend.h"

typedef std::string string;

class Bot	{

	string userQuery;
	int prevResponse, currResponse;

	private:
		Dictionary *sets;
	public:
		Bot ()	{

			sets = initialize_vocabulary ();
		}

		void inititate ()	{

			introduction ();

			bool execute = true;
			srand ( time ( NULL ));
			prevResponse = -1;
			while ( execute ) {

				string *results;

				std::cout << "User > ";
				std::getline ( std::cin, userQuery );
			
				std::cout << "Bot > ";

				std::string processedQuery = process_input ( userQuery, true );
				string category = categorize ( processedQuery );
				if ( category == "FUNCTION" )	{
					identify_function ( processedQuery );
				}
				else {
					results =  evaluate_response ( category );
					do	{
						currResponse = rand () % 3;
					} while ( prevResponse == currResponse );
					
					prevResponse = currResponse;
					if ( category == "BYE")	execute = false;

					std::cout << results [ currResponse ];
					
				}
			}
		}
};
int main ()		{
	
	Bot bot;
	system ( "cls || clear ");
	bot.inititate ();
}
