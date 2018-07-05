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
				string category = categorize ( process_input ( userQuery, true ));
				results =  evaluate_response ( category );

				do	{
					currResponse = rand () % 3;
				} while ( prevResponse == currResponse );
				
				prevResponse = currResponse;
				if ( category == "BYE")	execute = false;

				std::cout << results [ currResponse ];
				
			}
		}
};
int main ()		{
	
	Bot bot;
	std::cout << "\033[2J\033[1;1H";
	bot.inititate ();
}
