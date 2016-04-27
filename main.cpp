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
	cin >> store;
	return store;
}
void showmainmenu(){
	//A function to print the main menu
	cout << "\n=============Main Menu=============" << endl;
	cout << "1. Find a game" << endl;
	cout << "2. Sell a game" << endl;
	cout << "3. Print the inventory" << endl;
	cout << "4. Restock the shelf" << endl;
	cout << "5. Locate in other branches"  << endl;
	cout << "6. Change the price" << endl;
	cout << "7. Request moving from other store" << endl;
	cout << "8. Quit this branches database" << endl;
	cout << "===================================\n" << endl;

}


int main(int argc , char* argv[]){
	
	ifstream in_stream; // start of building of BST
	ifstream two_stream;
	ifstream three_stream;
	in_stream.open(argv[1]);
	two_stream.open(argv[2]);
	three_stream.open(argv[3]);
	string line;
	GSTree *boulder = new GSTree;
	GSTree *laf = new GSTree;
	GSTree *lake = new GSTree;
	int counter = 0;
	string thearray[90];
	string secline;
	int counter2=0;
	int counter3=0;
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
			thearray[counter] = line;
			counter++;
		}
	}

	for(int x = 0; x<90 ; x=x+6){
		boulder->addGameNode(atoi(thearray[x].c_str()) , thearray[x+1] , atof(thearray[x+2].c_str()) , atof(thearray[x+3].c_str() ) , atoi(thearray[x+4].c_str()) , thearray[x+5]);
	}//end of building of BST

	string twoarray[90];	
	while(!two_stream.eof()){
                getline(two_stream, line, ',');
                int m = line.find('\n');
                if(m!=-1){
                        secline = line.substr(m+1, line.length());
                        line = line.substr(0,m);
                        twoarray[counter2] = line;
                        twoarray[counter2+1] = secline;
                        counter2 = counter2+2;
                }
                else{
                        twoarray[counter2] = line;
                        counter2++;
                }
        }
	 for(int x = 0; x<90 ; x=x+6){
                laf->addGameNode(atoi(twoarray[x].c_str()) , twoarray[x+1] , atof(twoarray[x+2].c_str()) , atof(twoarray[x+3].c_str() ) , atoi(twoarray[x+4].c_str()) , twoarray[x+5]);
        }
	
	string threearray[90];
        while(!three_stream.eof()){
                getline(three_stream, line, ',');
                int m = line.find('\n');
                if(m!=-1){
                        secline = line.substr(m+1, line.length());
                        line = line.substr(0,m);
                        threearray[counter3] = line;
                        threearray[counter3+1] = secline;
                        counter3 = counter3+2;
                }
                else{
                        threearray[counter3] = line;
                        counter3++;
                }
        }
         for(int x = 0; x<90 ; x=x+6){
                lake->addGameNode(atoi(threearray[x].c_str()) , threearray[x+1] , atof(threearray[x+2].c_str()) , atof(threearray[x+3].c_str() ) , atoi(threearray[x+4].c_str()) , threearray[x+5]);
        }

	
	string k, store;
	cout << "\n\nWelcome to the Colorado GameStop Database!\n\n" << endl;
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
					boulder->findGame(l);
				}
				else if(k=="2"){
					//sell a game
					cout << "Enter title:" << endl;
					string l;
					getline(cin, l, '\n');
					getline(cin, l, '\n');
					boulder->sellGame(l);
				}
				else if(k=="3"){
					//printing game inventory
					boulder->printGameInventory();
				}

				else if(k=="4"){
                                        //restocking, if not found in the tree, creates the node.       
                                        string fnd, amount;
                                        cout << "Enter the title of the game:" <<endl;
                                        getline(cin, fnd , '\n');
                                        getline(cin, fnd , '\n');
                                        cout << "Enter the amount you are restocking:" << endl;
                                        getline(cin, amount , '\n');
                                        boulder->restockItem( fnd , atoi(amount.c_str()));
                                }
				else if(k=="5"){
					//locate in other stores	
					string fnd;
					cout << "Enter the title of the game to find:" << endl; 
					getline(cin, fnd , '\n');
					getline(cin, fnd , '\n');
					bool laff = laf->foundInStore(fnd);
					bool wood = lake->foundInStore(fnd);
					cout << "In Lafayette: " << laff << endl;
					if(laff == true){
						laf->findGame(fnd);
					}
					cout << "In Lakewood: " << wood<<endl;
					if(wood == true){
						lake->findGame(fnd);
					}
				}
				else if(k=="6"){
				//change in price
					string fnd , newprice;
					cout << "Enter the title of the game:" << endl;
					getline(cin, fnd , '\n');
					getline(cin, fnd , '\n');
					cout << "Enter the new price in the form (xx.xx):" << endl;
					getline(cin, newprice , '\n');
					boulder->reprice(fnd , atof(newprice.c_str()));
					
				}
				else if(k=="7"){
				//move from other store
					string fnd,title;
					cout << "Enter the title of the game:" <<endl;
					getline(cin, title , '\n');
					getline(cin, title , '\n');
					bool bldr = boulder->foundInStore(title);
					bool laff = laf->foundInStore(title);
					bool wood = lake->foundInStore(title);
					cout << "In Lafayette: " << laff << endl;
					cout << "In Lakewood: " << wood<<endl;
					cout << "=====Move from=======" << endl;
					cout << "1. Lafayette" << endl;
					cout << "2. Lakewood" << endl;
					getline(cin, fnd , '\n');
					if(bldr == true){
						if(fnd == "1" && laff == true){
							int x = laf->removeFromStore(title);
							boulder->moveToStore(fnd , x);
						}
						else if(fnd =="2" && wood ==true){
							int x = lake->removeFromStore(title);
							boulder->moveToStore(title,x);
						}
						else{
							cout << "This game is not available in the requested store. Try in another store or another item" << endl;
						}
					}
					else{
						cout << "Please add at least one copy onto the shelf to request more from other branches. Provide the price, ranking in terms of best selling, and the current IGN ranking from the branch manager." << endl;
					}
	
				}
			}
		}
		else if(store == "2"){
		while(k!="8"){
				showmainmenu();
				cin >> k;
				if(k == "1"){
					//find a game
					cout << "Enter title:" << endl;
					string l;
					getline(cin, l , '\n');
					getline(cin, l , '\n');
					laf->findGame(l);
				}
				else if(k=="2"){
					//sell a game
					cout << "Enter title:" << endl;
					string l;
					getline(cin, l, '\n');
					getline(cin, l, '\n');
					laf->sellGame(l);
				}
				else if(k=="3"){
					//printing game inventory
					laf->printGameInventory();
				}
				else if(k=="4"){
                                        //restocking, if not found in the tree, creates the node.       
                                        string fnd, amount;
                                        cout << "Enter the title of the game:" <<endl;
                                        getline(cin, fnd , '\n');
                                        getline(cin, fnd , '\n');

                                        cout << "Enter the amount you are restocking:" << endl;
                                        getline(cin, amount , '\n');
                                        laf->restockItem( fnd , atoi(amount.c_str()));

				}
				else if(k=="5"){
					
					string fnd;
					cout << "Enter the title of the game to find:" << endl; 
					getline(cin, fnd , '\n');
					getline(cin, fnd , '\n');
					//remove one of three:
					bool bldr = boulder->foundInStore(fnd);
					bool wood = lake->foundInStore(fnd);
					cout << "In Boulder: " << bldr << endl;
					if(bldr == true){
						boulder->findGame(fnd);
					}
					cout << "In Lakewood: " << wood<<endl;
					if(wood == true){
						lake->findGame(fnd);
					}
				}
				else if(k=="6"){
				//change in price
					string fnd, newprice;
					cout << "Enter the title of the game:" << endl;
					getline(cin, fnd , '\n');
					getline(cin, fnd , '\n');
					cout << "Enter the new price in the form (xx.xx):" << endl;
					getline(cin, newprice , '\n');
					laf->reprice(fnd , atof(newprice.c_str()));
				}
				else if(k=="7"){
				//move from other store
					string title,fnd;
					cout << "Enter the title of the game:" <<endl;
					getline(cin,title, '\n');
					getline(cin, title , '\n');
					bool bldr = boulder->foundInStore(title);
					bool laff = laf->foundInStore(title);
					bool wood = lake->foundInStore(title);
					cout << "In Boulder: " << bldr << endl;
					cout << "In Lakewood: " << wood<<endl;
					cout << "=====Move from=======" << endl;
					cout << "1. Boulder" << endl;
					cout << "2. Lakewood" << endl;
					getline(cin, fnd , '\n');
					if(laff == true){
						if(fnd == "1" && bldr == true){
							int x = boulder->removeFromStore(title);
							//moveToStore = the one you add to
							laf->moveToStore(title , x);
							//removefromstore = the one you remove from
						}
						else if(fnd =="2" && wood ==true){
							int x = lake->removeFromStore(title);
							laf->moveToStore(title, x);
						}
						else{
						cout << "Please add at least one copy onto the shelf to request more from other branches. Provide the price, ranking in terms of best selling, and the current IGN ranking from the branch manager." << endl;
						}

					}
					else{
						cout << "Please add at least one copy onto the shelf to request more from other branches. Provide the price, ranking in terms of best selling, and the current IGN ranking from the branch manager." << endl;
					}
	
				}
			}	
		}
		else if(store == "3"){
			while(k!="8"){
				showmainmenu();
				cin >> k;
				if(k == "1"){
					//find a game
					cout << "Enter title:" << endl;
					string l;
					getline(cin, l , '\n');
					getline(cin, l , '\n');
					lake->findGame(l);
				}
				else if(k=="2"){
					//sell a game
					cout << "Enter title:" << endl;
					string l;
					getline(cin, l, '\n');
					getline(cin, l, '\n');
					lake->sellGame(l);
				}
				else if(k=="3"){
					//printing game inventory
					lake->printGameInventory();
				}
				else if(k=="4"){
					//restocking, if not found in the tree, creates the node.	
					string fnd, amount;
					cout << "Enter the title of the game:" <<endl;
					getline(cin, fnd , '\n');
					getline(cin, fnd , '\n');
					
					cout << "Enter the amount you are restocking:" << endl;
					getline(cin, amount , '\n');
					lake->restockItem( fnd , atoi(amount.c_str()));
				}
				else if(k=="5"){
					
					string fnd;
					cout << "Enter the title of the game to find:" << endl; 
					getline(cin, fnd , '\n');
					getline(cin, fnd , '\n');
					//remove one of three:
					bool bldr = boulder->foundInStore(fnd);
					bool laff = laf->foundInStore(fnd);
					cout << "In Boulder: " << bldr << endl;
					if(bldr == true){
						boulder->findGame(fnd);
					}
					cout << "In Lafayette: " << laff << endl;
					if(laff == true){
						laf->findGame(fnd);
					}
					
				}
				else if(k=="6"){
				//change in price
					string fnd, newprice;
					cout << "Enter the title of the game:" << endl;
					getline(cin, fnd , '\n');
					getline(cin, fnd , '\n');
					cout << "Enter the new price in the form (xx.xx):" << endl;
					getline(cin, newprice , '\n');
					lake->reprice(fnd , atof(newprice.c_str()));
				}
				else if(k=="7"){
				//move from other store
					string fnd, title;
					cout << "Enter the title of the game:" <<endl;
					getline(cin, title , '\n');
					getline(cin, title , '\n');
					bool bldr = boulder->foundInStore(title);
					bool laff = laf->foundInStore(title);
					bool wood = lake->foundInStore(title);
					cout << "In Boulder: " << bldr<<endl;
					cout << "In Lafayette: " << laff << endl;
					cout << "=====Move from=======" << endl;
					cout << "1. Boulder" << endl;
					cout << "2. Lafayette" << endl;
					getline(cin, fnd , '\n');
					if(wood == true){
						if(fnd == "1" && bldr == true){
							int x = boulder->removeFromStore(title);
							lake->moveToStore(title , x);
						}
						else if(fnd =="2" && laff ==true){
							int x = laf->removeFromStore(title);
							lake->moveToStore( title , x);
						}
						else{
							cout << "Please add at least one copy onto the shelf to request more from other branches. Provide the price, ranking in terms of best selling, and the current IGN ranking from the branch manager." << endl;
						}
					}
					else{
						cout << "Please add at least one copy onto the shelf to request more from other branches. Provide the price, ranking in terms of best selling, and the current IGN ranking from the branch manager." << endl;
					}
	
				}
			}
		}
	k = "0";
	}	
	//deconstruct for all BST's
	boulder->DeleteAll();	
	laf->DeleteAll();
	lake->DeleteAll();
}
