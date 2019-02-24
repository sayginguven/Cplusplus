#include <iostream>

class Player
{

private:
	std::string name;
	int health;
	double xp;

public:
	Player();
	Player(std::string name, int health, double xp);
	Player(const Player &source);
	~Player();

public:
	std::string getName() const;
	int getHealth() const;
	double getXP() const;
	
	
	bool operator>(const Player &obj) const;
	friend std::ostream& operator <<(std::ostream& stream, const Player &obj);
};
