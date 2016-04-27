//Muntadher AlZayer 104348447
//CSCI2270
//Hoenigman - Guohui
//Final Project

#include<iostream>
#include<algorithm>
#include<fstream>
#include "GSTree.h"
#include<string>
using namespace std;
string storemenu(){
	string store;
	cout << "=====Choose your store=====" << endl;
	cout << "1. Boulder - Canyon Blvd" << endl;
	cout << "2. Lafayette - Waneka Mall" << endl;
	cout << "3. Lakewood - Colfax Ave" <<endl;
	cout << "enter 0 to close this program" << endl;
	cout << "=============================" << endl;
	cin >> store;
	return store;
}
void showmainmenu(){
	//A function to print the main menu
	cout << "======Main Menu======" << endl;
	cout << "1. Find a game" << endl;
	cout << "2. Sell a game" << endl;
	cout << "3. Print the inventory" << endl;
	cout << "4. Delete a NODE" << endl;
	cout << "5. Count the inventory" << endl;
	cout << "6. Quit" << endl;
}


int main(int argc , char* argv[]){
	
	ifstream in_stream; // start of building of BST
	in_stream.open(argv[1]);
	string line;
	GSTree *bintree = new GSTree;
	GSTree *another = new GSTree;
	int counter = 0;
	string thearray[300];
	string secline;
	int c2 = 0;
	
	while(!in_stream.eof()){
		getline(in_stream, line, ',');
		int m = line.find('\n');
		if(m!=-1){
			secline = line.substr(m+1, line.length());
			line = line.substr(0,m);
			thearray[counter] = line;
			thearray[counter+1] = secline;
			counter = counter+2;
		}
		else{
			c2++;
			cout << c2<< endl;
			thearray[counter] = line;
			counter++;
		}
	}
	cout << "we out here" << endl;
	for(int x = 0; x<300 ; x=x+6){
		bintree->addGameNode(atoi(thearray[x].c_str()) , thearray[x+1] , atof(thearray[x+2].c_str()) , atof(thearray[x+3].c_str() ) , atoi(thearray[x+4].c_str()) , thearray[x+5]);
		cout << "we hungry " << c2++ << " " << thearray[x] << endl;
	}//end of building of BST
		//another->addGameNode(atoi(thearray[x].c_str()) , thearray[x+1] , atoi(thearray[x+2].c_str()) , atoi(thearray[x+3].c_str()));
	string k, store;
	//showstoremenu();
	//cin >> store;
	while(store != "0"){	
		string store = storemenu();
		if(store == "0"){
		break;
		}
		if(store == "1"){
			while(k!="8"){
				showmainmenu();
				cin >> k;
				if(k == "1"){
					//find a game
					cout << "Enter title:" << endl;
					string l;
					getline(cin, l , '\n');
					getline(cin, l , '\n');
					bintree->findGame(l);
				}
				else if(k=="2"){
					//sell a game
					cout << "Enter title:" << endl;
					string l;
					getline(cin, l, '\n');
					getline(cin, l, '\n');
					bintree->sellGame(l);
				}
				else if(k=="3"){
					//printing game inventory
					bintree->printGameInventory();
				}
				else if(k=="4"){
					//restocking, if not found in the tree, creates the node.	
					int amount;
					cout << "Enter the amount you are restocking:" << endl;
					getline(cin, str , '\n');
					getline(cin, str , '\n');
					bintree->restockItem(amount);
				}
				else if(k=="5"){
					
					string fnd;
					cout << "Enter the title of the game to find:" << endl; 
					getline(cin, fnd , '\n');
					getline(cin, fnd , '\n');
					//remove one of three:
					bool bldr = boulder->foundInStore(title);
					bool laff = laf->foundInStore(title);
					bool wood = lake->foundInStore(title);
					cout << "In Boulder: " << bldr << endl;
					if(bldr == true){
						boulder->findGame(fnd);
					}
					cout << "In Lafayette: " << laff << endl;
					if(laff == true){
						laff->findGame(fnd);
					}
					cout << "In Lakewood: " << wood<<endl;
					if(wood == true){
						lake->findGame(fnd);
					}
				}
				else if(k=="6"){
				//change in price
					string fnd;
					double newprice;
					cout << "Enter the title of the game:" << endl;
					getline(cin, fnd , '\n');
					getline(cin, fnd , '\n');
					cout << "Enter the new price in the form (xx.xx):" << endl;
					getline(cin, newprice , '\n');
					getline(cin, newprice , '\n');
					boulder->reprice(fnd , newprice);
				}
				else if(k=="7"){
				//move from other store
					
				}
			}
		}
		else if(store == "2"){
			while(k!="7"){
                                showmainmenu();
                                cin >> k;
                                if(k == "1"){
                                        cout << "Enter title:" << endl;
                                        string l;
                                        getline(cin, l , '\n');
                                        getline(cin, l , '\n');
                                        bintree->findGame(l);
                                }
                                else if(k=="2"){
                                        cout << "Enter title:" << endl;
                                        string l;
                                        getline(cin, l, '\n');
                                        getline(cin, l, '\n');
                                        bintree->sellGame(l);
                                }
                                else if(k=="3"){
                                        bintree->printGameInventory();
                                }
                                else if(k=="4"){
                                        string str;
                                        cout << "Enter a title:" << endl;
                                        getline(cin, str , '\n');
                                        getline(cin, str , '\n');
                                        bintree->deleteGameNode(str);
                                }
                                else if(k=="5"){
                                        //counting the movies
                                        cout  << "Tree contains: " << bintree->countGameNodes() << " movies." << endl;
                                }
                                else if(k=="6"){

                                        cout << "Finding Inception in the other stores" << endl;
                                        //bintree->locateInStores(bintree , another , another , "Inception");
                                }
                        }
		}
		else if(store == "3"){
			while(k!="7"){
                                showmainmenu();
                                cin >> k;
                                if(k == "1"){
                                        cout << "Enter title:" << endl;
                                        string l;
                                        getline(cin, l , '\n');
                                        getline(cin, l , '\n');
                                        bintree->findGame(l);
                                }
                                else if(k=="2"){
                                        cout << "Enter title:" << endl;
                                        string l;
                                        getline(cin, l, '\n');
                                        getline(cin, l, '\n');
                                        bintree->sellGame(l);
                                }
                                else if(k=="3"){
                                        bintree->printGameInventory();
                                }
                                else if(k=="4"){
                                        string str;
                                        cout << "Enter a title:" << endl;
                                        getline(cin, str , '\n');
                                        getline(cin, str , '\n');
                                        bintree->deleteGameNode(str);
                                }
                                else if(k=="5"){
                                        //counting the movies
                                        cout  << "Tree contains: " << bintree->countGameNodes() << " movies." << endl;
                                }
                                else if(k=="6"){

                                        cout << "Finding Inception in the other stores" << endl;
                                        //bintree->locateInStores(bintree , another , another , "Inception");
                                }
                        }

		}
	cout << store << endl;
	k = "0";
	}	
	//deconstruct for all BST's
	bintree->DeleteAll();	
	
}
