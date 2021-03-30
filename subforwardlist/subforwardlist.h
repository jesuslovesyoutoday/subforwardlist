#include <iostream>

template<typename type>

class subforwardlist
{
	private:
		type data;
		subforwardlist<type>* next;
		subforwardlist<type>* first;
	
	public:
		subforwardlist<type>()
		{
			first = NULL;
		}

		~subforwardlist<type>()
		{
			while (first->next != NULL)
			{
				auto* temp = first->next;
				delete first->next;
				first = temp;
			}
			delete first;
		}

		void clear(subforwardlist<type> *s)
		{
			if (s != NULL)
			{
				clear(s->next);
				delete s;
			}
		}

		void push_back(type element)
		{
			auto* temp = first;
			if(first != NULL)
			{
				while(temp->next != NULL)
				{
					temp = temp->next;
				}
				temp->next = new subforwardlist<type>;
				temp->next->data = element;
				temp->next->next = NULL;
			}

			else 
			{
				first = new subforwardlist<type>;
				first->data = element;
				first->next = NULL;
			}
		}

		type pop_back()
		{
			return erase_where(size()-1);
		}

		void push_forward(type element)
		{
			push_where(0, element);
		}

		type pop_forward()
		{
			return erase_where(0);
		}

		void push_where(int where, type element)
		{
			if(first == NULL)
			{
				first = new subforwardlist<type>;
				first->data = element;
				first->next = NULL;
			}

			else if (where != 0)
			{
				auto* temp = first;
				for (int i = 0; i < where-1; ++i)
				{
					temp = temp->next;	
				}
				auto* next_for_where = temp->next;
				
				auto* p = new subforwardlist<type>;
				p->data = element;
				p->next = next_for_where;
				temp->next = p;
			}

			else
			{
				auto* p = new subforwardlist<type>;
				p->data = element;
				p->next = first;
				first = p;
			}
		}
		
		type erase_where(int where)
		{
			if (first == NULL)
			{
				return 0;
			}
			else if (where != 0)
			{
				auto* temp = first;
				for (int i = 0; i < where - 1; i++)
				{
					temp = temp->next;
				}
				auto* p = temp->next->next;
				type a = temp->next->data;
				delete temp->next;
				temp->next = p;
				return a;
			}
			else
			{
				type a = first->data;
				first->data = 0;
				auto* temp = first->next;
				delete first;
				first = temp;
				return a;
			}
		}

		unsigned int size() const
		{
			unsigned int i = 0;
			auto temp = first;

			while(temp != NULL)
			{
				temp = temp->next;
				i++;
			}

			return i;
		}

		void print() const
		{
			auto* temp = first;
			for (int i = 0; i < size(); i++)
			{
				std::cout << temp->data << std::endl;
				temp = temp->next;
			}
		}
};
