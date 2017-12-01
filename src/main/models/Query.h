#include "expertsystem.hpp"

class Query{
	private: string query;

	public : Query(string query){
				 this->query = query;
			 }
	public: string getQuery()
			{
				return (query);
			}
};
