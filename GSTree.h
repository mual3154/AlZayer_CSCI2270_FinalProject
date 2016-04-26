#ifndef GSTREE_H
#define GSTREE_H

#include<iostream>
#include<string>
struct GameNode{
    int IGNranking;
    std::string title;
    int relyear;
    int quantity;
    GameNode *parent;
    GameNode *leftChild;
    GameNode *rightChild;

    GameNode(){};

    GameNode(int in_ranking, std::string in_title, int in_year, int in_quantity)
    {
        IGNranking = in_ranking;
        title = in_title;
        relyear = in_year;
        quantity = in_quantity;
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
        void addGameNode(int ranking, std::string title, int releaseYear, int quantity);
        void findGame(std::string title);
        void sellGame(std::string title);
	void removeFromStore();
	void moveToStore();
	bool foundInStore(std::string gameTitle);
    protected:
    private:
	
        void printGameInventory(GameNode *node);
        GameNode* search(std::string title);
        GameNode *root;
	GameNode* treeMinimum(GameNode *node);
	void DeleteAll(GameNode *node);
	void countGameNodes(GameNode *node, int *c);

};

#endif // GSTREE_H
