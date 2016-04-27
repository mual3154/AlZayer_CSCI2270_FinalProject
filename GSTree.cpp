#include "GSTree.h"
#include<string>
#include<iostream>
using namespace std;


void GSTree::addGameNode(int ranking, string title , double IGNrating, double price, int quantity, string console){
	GameNode *tmp = new GameNode;
	tmp = root;
	GameNode *parent = new GameNode;
	parent = NULL;
	
	GameNode *node = new GameNode(ranking, title, IGNrating , price, quantity, console);
	node->leftChild = NULL;
	node->rightChild = NULL;
	node->parent = NULL;
	
	while(tmp!=NULL){
		parent = tmp;
		if(node->title.compare(tmp->title) < 0){
			tmp = tmp->leftChild;
		}
		else if(node->title.compare(tmp->title) > 0){
			tmp = tmp->rightChild;
		}

	}
	if(parent == NULL){
		root = node;
	}
	else if(node->title.compare(parent->title) < 0){
		parent->leftChild = node;
		node->parent = parent;
	}
	else{
		parent->rightChild = node;
		node->parent = parent;
	}

}


void GSTree::findGame(string title){
	GameNode *node = search(title);
	if(node !=NULL){
		cout << "Game Info:" << endl;
		cout << "===========" << endl;
		cout << "Ranking: " << node->ranking << endl;
		cout << "Title: " << node->title << endl;
		cout << "IGN rating: " << node->IGNrating << endl;
		cout << "Price: " << node->price << endl;
		cout << "Quantity: " << node->quantity << endl;
		cout << "Console: " << node->console << endl;
	}
	else{
		cout << "Game is not in stock.\n Restock or search for in another branch." << endl;
	}

}

void GSTree::sellGame(string title){
	GameNode *node = search(title);
	if(node!=NULL){
		cout << "Game has been sold." << endl;
		node->quantity = node->quantity-1;
		cout << "Game Info:" << endl;
		cout << "===========" << endl;
		cout << "Ranking: " << node->ranking << endl;
		cout << "Title: " << node->title << endl;
		cout << "IGN rating: " << node->IGNrating << endl;
		cout << "Price: " << node->price << endl;
		cout << "Quantity: " << node->quantity << endl;
		cout << "Console: " << node->console << endl;
		if(node->quantity == 0){
			deleteGameNode(node->title);
		}
	}
	else{
		cout <<"Game out of stock.\n Locate in a different branch." << endl;
	}
}

void GSTree::printGameInventory(GameNode *node){
	if(node->leftChild !=NULL){
		printGameInventory(node->leftChild);
	}
	cout << node->title << ":\n" << node->console << " " << node->quantity << " - " << node->price << "$ - " << node->IGNrating <<endl;
	if(node->rightChild != NULL){
		printGameInventory(node->rightChild);
	}
}

GSTree::GSTree(){

}

void GSTree::printGameInventory(){
	printGameInventory(root);
}

int GSTree::countGameNodes(){
	int *m = 0;
	GameNode *tmp = new GameNode;
	tmp = root;
	countGameNodes(tmp , m);
	return *m;
}


void GSTree::countGameNodes(GameNode *node , int* c){
	if(node->leftChild != NULL){
		countGameNodes(node->leftChild , c);
	}
	*c = *c + 1;
	if(node->rightChild !=NULL){
		countGameNodes(node->rightChild, c);
	}
}

GameNode* GSTree::treeMinimum(GameNode *node){
	while(node->leftChild !=NULL){
		node = node->leftChild;
		return node;
	}
}

void GSTree::deleteGameNode(std::string title){
	GameNode *tmp = new GameNode;
	GameNode *min = new GameNode;
	GameNode *parent = new GameNode;
	tmp = search(title);
	parent = tmp->parent;
	if(tmp != NULL){
		if(tmp->leftChild == NULL && tmp->rightChild == NULL){
			delete tmp;
			tmp = NULL;
		}
		else if(tmp->leftChild == NULL){
			if(tmp->title.compare(parent->title) < 0 ){
				tmp->rightChild->parent = tmp->parent;
				parent->leftChild = tmp->rightChild;
				delete tmp;
			}
			else{
				tmp->rightChild->parent = tmp->parent;
				parent->rightChild = tmp->rightChild;
				delete tmp;
			}
	
		}
		else if(tmp->rightChild == NULL){
			if(tmp->title.compare(parent->title) < 0 ){
				tmp->leftChild->parent = tmp->parent;
				parent->leftChild = tmp->leftChild;
				delete tmp;
			}
			else{
				tmp->leftChild->parent = tmp->parent;
				parent->rightChild = tmp->leftChild;
				delete tmp;
			}
		}
		else{
			min = treeMinimum(tmp->rightChild);
			parent = min->parent;
			if(min->rightChild !=NULL){
				min->rightChild->parent = min->parent;
				parent->leftChild = min->rightChild;
				min->rightChild = NULL;
			}
			min->leftChild = tmp->leftChild;
			if(tmp->leftChild !=NULL){
				tmp->leftChild->parent = min;
			}
			min->rightChild = tmp->rightChild;
			if(tmp->rightChild !=NULL){
				tmp->rightChild->parent = min;
			}
			parent = tmp->parent;
			min->parent = parent;
			if(min->title.compare(parent->title) <0){
				parent->leftChild = min; 
			}
			else{
				parent->rightChild = min;
			}
			delete tmp;

		}



	}
	else{
		cout << "Game not found." << endl;
	}

}

void GSTree::DeleteAll(){
	GameNode *tmp = root;
	DeleteAll(tmp);
	cout << "Goodbye!" << endl;
}

void GSTree::DeleteAll(GameNode *node){
	if(node !=NULL){
		if(node->leftChild !=NULL){
			DeleteAll(node->leftChild);
		}
		if(node->rightChild !=NULL){
			DeleteAll(node->rightChild);
		}
	cout << "Deleting: " << node->title << endl;
	delete node;
	}
}

bool GSTree::foundInStore(string title , int *amount){
	bool found = false;
        GameNode *node = root;
        while(node !=NULL){
                if(title.compare(node->title) < 0){
                        node = node->leftChild;
                }
                else if(title.compare(node->title) > 0){
                        node = node->rightChild;
                }
                else{
			found == true;
			*amount = node->quantity /2;
			return true;
                }

        }
        if(found == false){
		return false;
        }


}


void GSTree::restockItem(string title, int amount){
	GameNode *node = search(title);
	if(node !=NULL){
		node->quantity = node->quantity + amount;
	}else{
		double price, IGNrating;
		int ranking;
		string console;
		cout << "This game is out of stock" << endl;
		cout << "Please enter the following information" << endl;
		cout << "the ranking based on best selling: ";
		cin >> ranking;
		cout << "for which device: ";
		cin >> console;
		cout << "the price of the game: ";
		cin >> price;
		cout << "the IGN rating: ";
		cin >> IGNrating;
		addGameNode(ranking, title, IGNrating, price, amount, console);
		
        }
}

GameNode* GSTree::search(std::string title){
	bool found = false;
        GameNode *node = root;
        while(node !=NULL){
                if(title.compare(node->title) < 0){
                        node = node->leftChild;
                }
                else if(title.compare(node->title) > 0){
                        node = node->rightChild;
                }
                else{
                       return node; 
                }

        }
        if(found == false){
		return NULL;
        }


}

void GSTree::reprice(string title, double price){
	GameNode *tmp = search(title);
	if(tmp!=NULL){
		tmp->price = price;
	}
	else{
		cout << "Game not found" << endl;
	}
}

void GSTree::moveToStore(){
	
	
}
