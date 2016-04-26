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
void showmainmenu(){
	//A function to print the main menu
	cout << "======Main Menu======" << endl;
	cout << "1. Find a game" << endl;
	cout << "2. Rent a game" << endl;
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
	string thearray[200];
	string secline;
	
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
			thearray[counter] = line;
			counter++;
		}
	}
	for(int x = 0; x<200 ; x=x+4){
		bintree->addGameNode(atoi(thearray[x].c_str()) , thearray[x+1] , atoi(thearray[x+2].c_str()) , atoi(thearray[x+3].c_str()));
	}//end of building of BST
		another->addGameNode(atoi(thearray[x].c_str()) , thearray[x+1] , atoi(thearray[x+2].c_str()) , atoi(thearray[x+3].c_str()));
	string k;
	cout << "Choose your store:" << endl;
	cout << "1. Boulder - Canyon Blvd" << endl;
	cout << "2. Lafayette - Waneka Mall" << endl;
	cout << "3. LakeWook - Colfax Ave" <<endl;
	cout << "enter 0 to close this program" << endl;
	string store = NULL;
	cin >> store;
	while(store != "0"){
		if(store == "1"){
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
					bintree->locateInStores(bintree , another , another , "Inception");
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
                                        bintree->locateInStores(bintree , another , another , "Inception");
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
                                        bintree->locateInStores(bintree , another , another , "Inception");
                                }
                        }

		}

	}	
	//deconstruct for all BST's
	bintree->DeleteAll();	
	
}
