#ifndef GSTREE_H
#define GSTREE_H

#include<iostream>
#include<string>
struct GameNode{
    int ranking;
    double IGNrating;
    std::string title;
    std::string console;
    double price;
    int quantity;
    GameNode *parent;
    GameNode *leftChild;
    GameNode *rightChild;

    GameNode(){};

    GameNode(int in_ranking, std::string in_title, double in_IGNrating , double in_price, int in_quantity, std::string in_console)
    {
        ranking = in_ranking;
        title = in_title;
        price = in_price;
        quantity = in_quantity;
	console = in_console;
	IGNrating = in_IGNrating;
    }

};

class GSTree
{
    public:
        GSTree();
        ~GSTree();
	int countGameNodes();
	void DeleteAll();
	void deleteGameNode(std::string title);
	void printGameInventory();
        void addGameNode(int ranking, std::string title, double IGNrating, double price, int quantity, std::string console);
        void findGame(std::string title);
        void sellGame(std::string title);
	void removeFromStore();
	void moveToStore();
	bool foundInStore(std::string title, int *amount);
	void restockItem(std::string title, int amount);
	void reprice(std::string title , double price );
    protected:
    private:
	
        void printGameInventory(GameNode *node);
        GameNode* search(std::string title);
        GameNode *root;
	GameNode* treeMinimum(GameNode *node);
	void DeleteAll(GameNode *node);
	void countGameNodes(GameNode *node, int* c);

};

#endif // GSTREE_H
