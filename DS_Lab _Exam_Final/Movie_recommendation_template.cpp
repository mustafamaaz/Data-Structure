// #include <iostream>
// #include <string>

// using namespace std;

// class Node {
// 		int movieID;
// 		string title;
// 		string genre;
// 		int ratings;
// 		Movie* left;
// 		Movie* right;

// 		// define the constructor
// };

// class MovieRecommendationSystem {
// 	private:
// 		Node* root;

// 	public:
// 		// define the constructor

// 		// Insert a movie into the BST
// 		void insertMovie(Node* root, int movieID, string title, string genre, int ratings) {
// 			if (node == nullptr) {
// 				node = new Movie(movieID, title, genre, ratings);
// 			} else if (movieID < node->movieID) {
// 				insertMovie(node->left, movieID, title, genre, ratings);
// 			} else {
// 				insertMovie(node->right, movieID, title, genre, ratings);
// 			}
// 		}

// 		// Recommend movies of a given genre
// 		void recommendMoviesByGenre(string genre) {

// 		}

// 		// Delete a movie by ID
// 		Movie* deleteMovieByID(Node *root, int movieID) {

// 		}

// };

// int main() {
// 	MovieRecommendationSystem engine;
// 	int choice;
// 	while (true) {
// 		cout << "Menu:\n";
// 		cout << "1. Add a Movie\n";
// 		cout << "2. Delete a Movie by ID\n";
// 		cout << "3. Recommend Movies by Genre\n";
// 		cout << "4. Display Movies Sorted by Ratings\n";
// 		cout << "5. Exit\n";
// 		cout << "Enter your choice: ";
// 		cin >> choice;

// 		switch (choice) {
// 			case 1: {
// 				int movieID;
// 				string title, genre;
// 				double ratings;
// 				cout << "Enter Movie ID: ";
// 				cin >> movieID;
// 				cin.ignore(); // Clear newline character from the buffer
// 				cout << "Enter Movie Title: ";
// 				getline(cin, title);
// 				cout << "Enter Movie Genre: ";
// 				getline(cin, genre);
// 				cout << "Enter Ratings: ";
// 				cin >> ratings;

// 				engine.insertMovie(root, movieID, title, genre, ratings);
// 				cout << "Movie added successfully!" << endl;
// 				break;
// 			}
// 			case 2: {
// 				int deleteID;
// 				cout << "Enter Movie ID to delete: ";
// 				cin >> deleteID;
// 				root = deleteMovieByID(root, deleteID);
// 				cout << "Movie with ID " << deleteID << " deleted successfully!" << endl;
// 				break;
// 			}
// 			case 3: {
// 				string genre;
// 				cout << "Enter your favorite genre: ";
// 				cin.ignore(); // Clear newline character from the buffer
// 				getline(cin, genre);
// 				recommendMoviesByGenre(genre);
// 				break;
// 			}
// 			case 4:
// 				displayMovies();
// 				break;
// 			case 5:
// 				cout << "Exiting the program." << endl;
// 				return;
// 			default:
// 				cout << "Invalid choice. Please try again." << endl;
// 				break;
// 		}
// 	}
// 	return 0;
// }

























#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct node
{

    int movieId , genere, rating;
	string title;

    node *left, *right;
};

class binary_search_tree
{

private:
    node *temp, *temp1;

public:
    node *root;
    int id,gen,rat;
	string tit;

    binary_search_tree()
    {
        root = temp = temp1 = NULL;
    }

    void insert_binary_tree(node *temp)
    {

        if (root == NULL)
        {

            temp = new node;
            temp->movieId = id;
			temp->genere = gen;
			temp->rating= rat;
			temp->title = tit;
            temp->left = NULL;
            temp->right = NULL;
            root = temp;
            return;
        }

        if (temp->movieId == id)
        {

            cout << " \n Given id is already present in tree.\n";
            return;
        }

        if (temp->movieId > id)
        {

            if (temp->left != NULL)
            {
                insert_binary_tree(temp->left);
                return;
            }

            else
            {

                temp->left = new node;
                temp->left->movieId = id;
				temp->left->genere = gen;
				temp->left->rating = rat;
				temp->left->title = tit;
                temp->left->left = NULL;
                temp->left->right = NULL;
                return;
            }
        }

        if (temp->movieId < id)
        {

            if (temp->right != NULL)
            {

                insert_binary_tree(temp->right);
                return;
            }

            else
            {

                temp->right = new node;
                temp->right->movieId = id;
				temp->right->genere = gen;
				temp->right->rating = rat;
				temp->right->title = tit;
                temp->right->left = NULL;
                temp->right->right = NULL;
                return;
            }
        }
    }

  

    void deleting_binary_tree(node *temp)
    {
        if (root == NULL)
        {
            cout << "\nThere is no child to delete\n";
            return;
        }

        if (root->movieId == id)
        {

            //   case 1 having not child
            if (temp->left == NULL && temp->right == NULL)
            {
                delete root;
                root = NULL;
        
                return;
            }

            // case 2 having 1 child on left or right
            if (temp->left == NULL)
            {
                // seting pointer to right
                temp1 = root;
                root = root->right;
                delete temp1;
                temp1 = NULL;
                temp = root;
         
                return;
            }
            if (temp->right == NULL)
            {
                // setting pointer to left
                temp1 = root;
                root = root->left;
                delete temp1;
                temp1 = NULL;
                temp = root;
              
                return;
            }

            //   case 3 having 2 child
            if (temp->left != NULL && temp->right != NULL)
            {

                temp1 = temp->right;

                if (temp1->left != NULL)
                {

                    while (temp1->left->left != NULL)
                    {
                        temp1 = temp1->left;
                    }

                    root->movieId = temp1->left->movieId;
					root->genere= temp1->left->genere;
					root->rating = temp1->left->rating;
					root->title = temp1->left->title;

                    temp = temp1->left;
                    temp1->left = temp1->left->right;
                    delete temp;
                    temp == NULL;
               
                    return;
                }
                else
                {
                    root->movieId = temp1->movieId;
					root->genere = temp1->genere;
					root->rating = temp1->rating;
					root->title = temp1->title;

                    temp->right = temp->right->right;
                    delete temp1;
                    temp1 = NULL;

                    return;
                }
            }
        }
        else
        {
            if (id > temp->movieId)
            {
                if (temp->right->movieId == id)
                {

                    //   case 1 having not child
                    if (temp->right->left == NULL && temp->right->right == NULL)
                    {
                        delete temp->right;
                        temp->right = NULL;
                    
                        return;
                    }

                    // case 2 having 1 child on left or right
                    if (temp->right->left == NULL)
                    {
                        // seting pointer to right
                        temp1 = temp->right;
                        temp->right = temp->right->right; // or temp->right = temp1->right;
                        delete temp1;
                        temp1 = NULL;
                 
                        return;
                    }
                    if (temp->right->right == NULL)
                    {
                        // setting pointer to left
                        temp1 = temp->right;
                        temp->right = temp->right->left; // or temp->right = temp1->right;
                        delete temp1;
                        temp1 = NULL;
                    
                        return;
                    }

                    //   case 3 having 2 child
                    if (temp->left != NULL && temp->right != NULL)
                    {
                        temp = temp->right;
 
                        temp1 = temp->right;
                        if (temp1->left != NULL)
                        {

                            while (temp1->left->left != NULL)
                            {
                                temp1 = temp1->left;
                            }

                            temp->movieId = temp1->left->movieId;
							temp->genere = temp1->left->genere;
							temp->rating = temp1->left->rating;
							temp->title = temp1->left->title;

                            temp = temp1->left;
                            temp1->left = temp1->left->right;
                            delete temp;
                            temp == NULL;
                        
                            return;
                        }
                        else
                        {
                            temp->movieId = temp1->movieId;
							temp->genere = temp1->genere;
							temp->rating = temp1->rating;
							temp->title = temp1->title;

                            temp->right = temp->right->right;
                            delete temp1;
                            temp1 = NULL;
                        
                            return;
                        }
                    }
                }
                else
                {
                    deleting_binary_tree(temp->right);
                    return;
                }
            }

            // left
            if (id < temp->movieId)
            {
                if (temp->left->movieId == id)
                {

                    //   case 1 having not child
                    if (temp->left->left == NULL && temp->left->right == NULL)
                    {
                        delete temp->left;
                        temp->left = NULL;
                        cout << "\ngeneral case 1 done \n";
                        return;
                    }

                    // case 2 having 1 child on left or right
                    if (temp->left->left == NULL)
                    {
                        // seting pointer to right
                        temp1 = temp->left;
                        temp->left = temp->left->right; 
                        delete temp1;
                        temp1 = NULL;
                
                        return;
                    }
                    if (temp->left->right == NULL)
                    {
                        // setting pointer to left
                        temp1 = temp->left;
                        temp->left = temp->left->left; 
                        delete temp1;
                        temp1 = NULL;
                 
                        return;
                    }

                    //   case 3 having 2 child
                    if (temp->left->left  != NULL && temp->left->right != NULL)
                    {

                        temp = temp->left;
                        temp1 = temp->right;
                        if (temp1->left != NULL)
                        {

                            while (temp1->left->left != NULL)
                            {
                                temp1 = temp1->left;
                            }

                            temp->movieId = temp1->left->movieId;
							temp->rating = temp1->left->rating;
							temp->genere = temp1->left->genere;
							temp->title = temp1->left->title;


                            temp = temp1->left;
                            temp1->left = temp1->left->right;
                            delete temp;
                            temp == NULL;
                           
                            return;
                        }
                        else
                        {
                            temp->movieId = temp1->movieId;
							temp->genere = temp1->genere;
							temp->rating = temp1->rating;
							temp->title = temp1->title;


                            temp->right = temp->right->right;
                            delete temp1;
                            temp1 = NULL;
                         
                            return;
                        }
                    }
                }
                else
                {
                    deleting_binary_tree(temp->left);
                    return;
                }
            }
        }
    }

    void in_order(node *temp)
    {
        if (root == NULL)
        {
            cout << " Tree is empty.\n";
            return;
        }

        if (temp->left != NULL)
            in_order(temp->left);
        cout<<"\n\n=============================\n\n";
        cout <<"Movie ID  "<< temp->movieId << " \n";
		 cout <<"Movie Title  "<< temp->title << " \n";
		  cout <<"Movie Generation  "<< temp->genere << " \n";
		   cout <<"Movie Rating  "<< temp->rating << " \n";
		   cout<<"\n=============================\n";

        if (temp->right != NULL)
            in_order(temp->right);

        return;
    }

	void recommanded_movie(node *temp){

		

	}



};

int main()
{

    binary_search_tree obj;
    int choise;
     int r_height; 

    while (true)
    {
        cout << "\n1)Add Movie\n2) display movies\n3)delete movies\n4)Recomanded movie\n5)exit\n ";
        cin >> choise;

        if (choise == 1)
        {
            cout << "Enter the id of movie \n";
            cin >> obj.id;
			 cout << "Enter the title of movie tree\n";
            cin >> obj.tit;
			 cout << "Enter the generation of movie tree\n";
            cin >> obj.gen;
			 cout << "Enter the rating of movie tree\n";
            cin >> obj.rat;
            obj.insert_binary_tree(obj.root);
        }
        else if (choise == 2)
        {
			cout<<"\n\n**********************Display panel******************************\n";
            obj.in_order(obj.root);
			cout<<"\n*****************************************************************\n";
        }
        else if (choise == 3)
        {
            cout << "Enter the id of movie you want to delete\n";
            cin >> obj.id;
            obj.deleting_binary_tree(obj.root);
        }
		else if (choise == 4)
        {
            cout << "Enter the id of recomannded movie\n";
            cin >> obj.id;
            obj.deleting_binary_tree(obj.root);
        }

           else if (choise == 5)
        {
            break;
        }
    }

    return 0;
}

