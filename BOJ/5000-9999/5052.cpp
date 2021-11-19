#include <iostream>

struct Trie
{
	bool is_terminal;
	Trie *next[10];

	Trie() : is_terminal(false)
	{
		for (int i = 0; i < 10; i++)
			this->next[i] = NULL;
	};

	~Trie()
	{
		for (int i = 0; i < 10; i++)
			if (this->next[i])
				delete (this->next[i]);
	}

	// return true when there is no terminal
	bool insert(const char *key)
	{
		if (!key[0])
		{
			for (int i = 0; i < 10; i++)
				if (this->next[i])
					return false;
			is_terminal = true;
			return true;
		}

		if (this->is_terminal)
			return false;

		int idx = key[0] - '0';

		if (!this->next[idx])
		{
			this->next[idx] = new Trie;
		}

		return (this->next[idx]->insert(key + 1));
	}
};

void solve_case()
{
	bool is_duplicated = false;
	int m;
	char s[11];
	Trie *trie = new Trie;

	std::cin >> m;
	for (int i = 0; i < m; i++)
	{
		std::cin >> s;
		if (!is_duplicated && !trie->insert(s))
			is_duplicated = true;
	}
	std::cout << (is_duplicated ? "NO" : "YES") << std::endl;
	delete trie;
}

int main()
{
	int n;
	std::cin >> n;
	while (n--)
		solve_case();
	return 0;
}
