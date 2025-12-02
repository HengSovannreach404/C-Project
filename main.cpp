#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Node{
public:
    string title;
    Node *next;
    Node *prev;
    Node (string s){
        title = s;
        next = nullptr;
        prev = nullptr;
    }
};
class playlist {
private:
    Node *head;
    Node *current;
public:
    playlist(){
        head = nullptr;
        current = nullptr;
    }
    void addSong (string name){
        Node *NewSong = new Node(name);
        if( head == nullptr){
            head = NewSong;
            current = NewSong;
        } else {
            Node* temp = head;
            while (temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = NewSong;
            NewSong->prev = temp;
        }
        cout << "Added :" << name <<endl;
    }
    void display (){
        if( head == nullptr){
            cout << "Playlist is empty." <<endl;
        } else {
            cout << "---- Playlist ----" << endl;
            Node *temp = head;
            while (temp != nullptr){
                if ( temp == current){
                    cout<< "> ";
                } else {
                    cout << "  " <<endl;
                }
                cout << temp->title << endl;
                temp = temp->next;
            }
        }
    }
    void play() {
        if (current == nullptr) {
            cout << "No songs to play.\n";
            return;
        }
        cout << "Playing: " << current->title << endl;
    }
    void playnext (){
        if(current == nullptr){
            cout << "NO songs in playlist."<<endl;
            return;
        } else  if (current->next == nullptr){
            cout<< "This is the last song."<<endl;
            return;
        }
        current = current->next;
        play();
    }
    void PlayPrevoius(){
        if(current == nullptr){
            cout << "NO songs in playlist."<<endl;
            return;
        } 
        current = current->prev;
        play();

    }

};
int main () {
    playlist p;
    int option;
    string name ;
    do{
        cout<< "\n--- Music Player Menu ---" << endl;
        cout<< "1. Add Song"<< endl;
        cout<< "2. Show Playlist"<< endl;
        cout<< "3. Play Music"<< endl;
        cout<< "4. Next Music"<< endl;
        cout<< "5. Prevoius"<< endl;
        cout<< "0. exit program"<< endl;
        cout<< "Choose Option : ";
        cin >> option ;
        switch (option){
            case 1 : 
                cout << "Enter A Song : " ;
                cin.ignore();
                getline(cin, name);
                p.addSong(name);
                break;
            case 2 : 
                p.display();
                break;
            case 3 :
                p.play();
                break;
            case 4 :
                p.playnext();
                break; 
            case 5 : 
                p.PlayPrevoius();
                break;
            case 0: 
                cout<<"Exit program"<<endl;
            
            
        }

    }while(option!=0);

    return 0 ;

}