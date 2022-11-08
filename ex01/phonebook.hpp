class Phonebook
{
		std::string	first_name[9];
		std::string	last_name[9];
		std::string	nickname[9];
		std::string	phone[9];
		std::string	secret[9];

		public:
		void add_contact(int index);
		void search();
};

std::string formatter(std::string str);

